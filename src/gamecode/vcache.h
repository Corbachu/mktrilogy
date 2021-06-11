/******************************************************************************
 File: vcache.h

 By: David Schwartz

 Date: Jan  1995

 (C) Williams Entertainment

 Mortal Kombat III vcache header
******************************************************************************/

#ifndef __mk_vcache_h__
#define __mk_vcache_h__

/*
 * 	DEFINITIONS
 */
 
/* VCACHE STUFF */

/* compress flags */
#define VCACHE_UNCOMPRESS	0					// image is not compressed
#define VCACHE_COMPRESS	1						// image is compressed

/* VRAM memory allocation structure */
typedef struct v_vrammem {
	void *v_imgptr;							// ptr to start addr of image
	void *v_dcmpptr;						// ptr to decompessed version of image
	WORD v_cnt;								// # objects using entry (-1 = permanent)
	WORD v_decomp;							// decomp flag for object (see flags above)
	BYTE *v_dict;							// dictionary pointer
} VRAMMEM;

#define MAX_VRAMMEM 200						// # of entries in manager cache
#define VRAM_PERM 0xffff					// vram cache entry is permanent
#define VCACHE_FAILED 0xffff				// indictate no cache

/*
 *	RAM
 */
__EXTERN__ VRAMMEM vram_cache[MAX_VRAMMEM];	/* cache of entries in vram memory manager */

/*
 *	PROTOTYPES
 */
/* vram cache prototypes */
void init_vram_cache(void);
void vram_cache_decomp_clear(void);
WORD alloc_vram_mem(BYTE *dict,void *,WORD,WORD);
void alloc_vram_mem_update(WORD ventry);
void dealloc_vram_mem(WORD);
void flush_vram_mem(void);

BYTE *vmem_predecomp_perm(ADDRESS *bglist,BYTE *dict,BYTE *dbuffer,LONG dsize);
WORD vmem_perm_img(void *permimg,BYTE *dict);

/*
 *	MACROS
 */
#define alloc_cache(_img,_heap,_obj) \
		(_obj)->header.t_width=((OIMGTBL *)(_img))->size.u.xpos; \
		(_obj)->header.t_height=((OIMGTBL *)(_img))->size.u.ypos; \
		(_obj)->ovcache=alloc_vram_mem((_obj)->odict,(void *)COMPUTE_ADDR((_heap),(LONG)(((OIMGTBL *)(_img))->isagptr)),(_obj)->ovcache,VCACHE_COMPRESS)

#endif /* __mk_valloc_h__ */
