/******************************************************************************
 File: valloc.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III VRAM ALLOCATION
******************************************************************************/

#define VDEBUG 1

/*** C Include files ***/
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "vcache.h"
#include "mkdma.h"
#include "mkgame.h"
/*********************************************************************
						 VRAM MEMORY CACHE MANAGER
 *********************************************************************/

#if VDEBUG
WORD vcache_used;
WORD vcache_comp;
#endif
/******************************************************************************
 Function: void init_vram_cache(WORD *vmem_list)

 By: David Schwartz

 Date: Dec 1994

 Parameters: vmem_list ptr to vram data

 Returns: None

 Description: 	resets vram cache manager & inits memory manager
******************************************************************************/
void init_vram_cache(void)
{
	int i;

	/* init cache */
	for (i=0;i<MAX_VRAMMEM;i++)
		sys_memset(vram_cache+i,0,sizeof(VRAMMEM));

#if VDEBUG
	vcache_used=0;
#endif

	return;
}

/*
 Clear all decomp ptrs so that they are always redone every frame.  This is a waste
 but we should have a lot of CPU to burn.  If not then implement a dynamic memory system.
 */
void vram_cache_decomp_clear(void) 
{
	int i;

	for (i=0;i<MAX_VRAMMEM;i++)
	{
		if ((vram_cache+i)->v_decomp==VCACHE_COMPRESS)
			(vram_cache+i)->v_dcmpptr=NULL;				// clear ptr so we can uncompress again
	}

	return;
}

/******************************************************************************
 Function: void vcache_uncompress(void)

 By: David Schwartz

 Date: Feb 1996

 Parameters: None

 Return: None

 Description:	This routine will run through the entire vcache list and uncompress
				any image that is marked compressed.  The dcmpptr will be updated to where
				the data has been uncompressed. The data is uncompressed to the current idcomp_ptr
				position and will always be 4 byte aligned.
******************************************************************************/
extern WORD f_white;
LONG max_dsize=0;
LONG last_dsize=0;
void vcache_uncompress(void) 
{
	int i;		  
	VRAMMEM *vptr;
									 
	for (i=0;i<MAX_VRAMMEM;i++)
	{
		vptr=(vram_cache+i);
		
		/* uncompress images that have no dcmpptr */
		if (vptr->v_dcmpptr==NULL && vptr->v_decomp==VCACHE_COMPRESS)
		{
#if SYS_DEBUG
			if ((ADDRESS)vptr->v_imgptr<0x80000000) 
			{
				printf(("ILLEGAL FRAME\n"));
				printf(("DCOMP PTR=%x BASE=%x FRAME=%x\n",idcomp_ptr,dpipe[vid_dpipe_writing].idcmp_base,vptr->v_imgptr));
			}
#endif		
			vptr->v_dcmpptr=uncompress_image(vptr->v_imgptr,vptr->v_dict);
#if SYS_DEBUG
			/* check if we blew our decompression buffer */
			if ((ADDRESS)idcomp_ptr>=(ADDRESS)(((BYTE *)dpipe[vid_dpipe_writing].idcmp_base)+DECOMP_BUFFER_SIZE))
				printf(("VCACHE UNCOMPRESS ERROR:	EXCEED DECOMP BUFFER %x\n",(ADDRESS)idcomp_ptr-(ADDRESS)dpipe[vid_dpipe_writing].idcmp_base));
#endif			
		}
	}  
	
#if SYS_DEBUG
		if (max_dsize<(LONG)((BYTE *)idcomp_ptr-(BYTE *)dpipe[vid_dpipe_writing].idcmp_base))
			max_dsize=(LONG)((BYTE *)idcomp_ptr-(BYTE *)dpipe[vid_dpipe_writing].idcmp_base);

		last_dsize=(LONG)((BYTE *)idcomp_ptr-(BYTE *)dpipe[vid_dpipe_writing].idcmp_base);
#endif	

	return;
}

void vcache_uncompress_lock(BYTE *dest,WORD ventry) 
{
	int i;
	VRAMMEM *vptr;
	BYTE *idcomp;

	vptr=(vram_cache+ventry);
		
	/* uncompress images that have no dcmpptr */
	if (vptr->v_dcmpptr==NULL && vptr->v_decomp==VCACHE_COMPRESS)
	{
		vptr->v_decomp=VCACHE_UNCOMPRESS;
		idcomp=(BYTE *)idcomp_ptr;
		(BYTE *)idcomp_ptr=dest;
		vptr->v_dcmpptr=uncompress_image(vptr->v_imgptr,vptr->v_dict);
		(BYTE *)idcomp_ptr=idcomp;
	}
	
	return;
}

/******************************************************************************
 Function: WORD alloc_vram_mem(BYTE *dict,void *img,WORD ventry,WORD decomp_flag)

 By: David Schwartz

 Date: Jan 1996

 Parameters: dict - dictionary ptr for image
 			 img - img to load
			 ventry - obj current vcache entry
			 decomp_flag - (0-image is uncompressed, 1-image is compressed)

 Returns: cache entry number (0-MAX_VRAMMEM-1)
		  VCACHE_FAILED  - unable to alloc in cache (TRAP)

 Description: 	searches the cache to see if img has been loaded
				if found
					inc cnt if not permanent
					returns back cache index
				not found
					allocates vram and load image
					inc cnt
					retruns back header info

NOTE: if there is not enough cache entries, function will TRAP!
******************************************************************************/
WORD alloc_vram_mem(BYTE *dict,void *img,WORD ventry,WORD decomp_flag)
{
	WORD i=0;
	VRAMMEM *vmem;
	WORD vfind=VCACHE_FAILED;			// find first available vmem, in case img not already loaded

	while (i<MAX_VRAMMEM)
	{
		vmem=vram_cache+i;

		if (vfind==VCACHE_FAILED && vmem->v_cnt==0)	// find avail entry
			vfind=i;

		if (vmem->v_imgptr==img && (vmem->v_cnt>0 || vmem->v_cnt==VRAM_PERM))
		{
			if (ventry==i)					// find entry current allocated to object, do nada
				return(i);
			else dealloc_vram_mem(ventry);	// release prev image

			/* found entry */
			if (vmem->v_cnt!=VRAM_PERM)		// if not perm, inc count
				vmem->v_cnt++;

			return(i);
		}
		else i++;
	}

	/* no entry found */
	if (vfind==VCACHE_FAILED) 
	{
#if VDEBUG	
		printf(("VACHE ALLOC FAILED %d\n",vcache_used));
		i=0;
		while (i<MAX_VRAMMEM)
		{
			if (vram_cache[i].v_cnt==0)
			printf(("CACHE CNT %d\t%d\n",i,vram_cache[i].v_cnt));
			i++;
		}
#else
		printf(("VACHE ALLOC FAILED \n"));
#endif
		LOCKUP;
		return(VCACHE_FAILED);
	}
	else
	{
		/* release prev image */
		dealloc_vram_mem(ventry);

#if VDEBUG
	vcache_used++;
#endif

		/* setup a new entry */
		vmem=vram_cache+vfind;

		vmem->v_cnt=1;						// entry has one obj using it

		/* memory allocation code */
		vmem->v_imgptr=img;					// save source ptr 

		vmem->v_dcmpptr=(decomp_flag==VCACHE_UNCOMPRESS)? img:NULL;				// if uncompressed then assign dmpptr to img
		vmem->v_decomp=decomp_flag;												// set decomp flag 
		vmem->v_dict=dict;						// set dictionary pointer
		

		return(vfind);
	}
}

void alloc_vram_mem_update(WORD ventry) 
{
	VRAMMEM *vmem;
	
	if (ventry==VCACHE_FAILED)
		return;
		
	vmem=vram_cache+ventry;
	
	if (vmem->v_cnt!=VRAM_PERM)
		vmem->v_cnt++;
	
	return;	
}

/******************************************************************************
 Function: void dealloc_vram_mem(WORD vcache_entry)

 By: David Schwartz

 Date: Dec 1994

 Parameters: vcache entry - index into cache of entry used

 Returns: None

 Description: 	removes one from cnt of entry supplied and
				if cnt goes to zero, unallocates block if not
				perm
******************************************************************************/
void dealloc_vram_mem(WORD vcache_entry)
{
	VRAMMEM *vmem;

	if (vcache_entry==VCACHE_FAILED)				// only dealloc inited stuff
		return;

	vmem=vram_cache+vcache_entry;

	if (vmem->v_cnt!=VRAM_PERM) 					// if perm ignore dealloc
	{
		if ((--vmem->v_cnt)==0)
		{
			vmem->v_imgptr=NULL;					// clear key
			vmem->v_dcmpptr=NULL;					// clear decomp ptr
			vmem->v_decomp=VCACHE_UNCOMPRESS;		// reset decomp flag
			
#if VDEBUG
			vcache_used--;
#endif
			
		}
	}

	return;
}

/******************************************************************************
 Function: void flush_vram_mem(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description: 	looks at all vram cache entries and flushes any non perm vram
******************************************************************************/
void flush_vram_mem(void)
{
	short i=0;
	VRAMMEM *vmem;

	while (i<MAX_VRAMMEM)
	{
		vmem=vram_cache+i;

		if (vmem->v_cnt!=VRAM_PERM && vmem->v_cnt!=0) 					// if perm ignore dealloc
		{
			/* flush and non perm non zero entry */
			vmem->v_imgptr=NULL;					// clear key
			vmem->v_dcmpptr=NULL;					// clear decomp ptr
			vmem->v_decomp=VCACHE_UNCOMPRESS;		// reset decomp flag
#if VDEBUG
			vcache_used--;
#endif
			
		}

		i++;						// next entry
	}
	return;
}

/******************************************************************************
 Function: void alloc_vram_perm_bg_list(ADDRESS *bglist,void *heap)

 By: David Schwartz

 Date: Feb 1995

 Parameters: bglist - list of images to alloc
			 heap -  ptr to start of data heap for images

 Returns: None

 Description: 	This routine reads through a 0 terminated lists and allocs a vcache entry
******************************************************************************/
BYTE *vmem_predecomp_perm(ADDRESS *bglist,BYTE *dict,BYTE *dbuffer,LONG dsize)
{
	BYTE *dtemp=(BYTE *)idcomp_ptr;
	void *animframe;
	OIMGTBL *dimg;
	BYTE *retvalue;
	
	if (gstate==GS_AMODE || gstate==GS_GAMEOVER)
		return(dbuffer);
		
	(BYTE *)idcomp_ptr=dbuffer;
	
	while (*bglist!=NULL)
	{
		dimg=*bglist;
		animframe=dimg->isagptr;
		vmem_perm_img(animframe,dict);
#if SYS_DEBUG
		if (((BYTE*)idcomp_ptr-dbuffer)>=dsize) 
		{
			printf(("VMEM PRE DECOMP ERROR:\n"));
			printf(("EXCEED HEAP SPACE BY %d BYTES\n",((BYTE*)idcomp_ptr-dbuffer)-dsize));
			ermac(15);
		}
#endif		
		bglist++;
	}
	
	printf(("REMAIN SPACE %d BYTES\n",((BYTE*)idcomp_ptr-dbuffer)-dsize));
	
	retvalue=(BYTE *)idcomp_ptr;
	(BYTE *)idcomp_ptr=dtemp;
	
	return(retvalue);
}

WORD vmem_perm_img(void *permimg,BYTE *dict)
{
	short i=0;
	VRAMMEM *vmem;
	WORD vfind=VCACHE_FAILED;			// find first available vmem, in case img not already loaded
	/* see if it exists */
	while (i<MAX_VRAMMEM)
	{
		vmem=vram_cache+i;

		if (vfind==VCACHE_FAILED && vmem->v_cnt==0)	// find avail entry
			vfind=i;

		if (vmem->v_imgptr==permimg && vmem->v_cnt==VRAM_PERM)
			return(i);
		else i++;
	}

	/* find avail error */
	if (vfind==VCACHE_FAILED) 
	{
		printf(("RAN OUT OF PERM ENTRIES\n"));
		ermac(15);
	}
	
	/* setup data */
	vmem=vram_cache+vfind;

	vmem->v_cnt=VRAM_PERM;					// set entry as permanent

	/* setup header info */
	vmem->v_imgptr=permimg;
	vmem->v_dict=dict;
	vmem->v_decomp=VCACHE_UNCOMPRESS;
 	vmem->v_dcmpptr=uncompress_image(vmem->v_imgptr,vmem->v_dict);
	return(vfind);
	
}
