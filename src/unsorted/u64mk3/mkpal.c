/******************************************************************************
 File: mkpal.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Palette Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkpal.h"
#include "mkgame.h"

/******************************************************************************
 Function: void init_paltrans_queue(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	initialize the queue for palette transfers
******************************************************************************/
void init_paltrans_queue(void)
{
	paltrans_start=paltrans_end=paltrans_queue;				/* set empty queue (start=end=qstart) */

	return;
}

/******************************************************************************
 Function: WORD findpal(WORD *pal_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: pal_id - pal id to find

 Returns: color pal # the pal_id is using
		  0xffff - pal not found

 Description:	find the color map # to which the given palette is assigned
******************************************************************************/
WORD findpal(WORD *pal_id)
{
	WORD l;

	for (l=0;l<NUM_PALS;l++)
		if (palram[l].palid==pal_id)
			return(l);

	return(UNKNOWN_PAL);
}

/******************************************************************************
 Function: void clear_pal(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	clear out palette allocation ram
******************************************************************************/
void clear_pal(void)
{
	init_paltrans_queue();

	clear_fore_pal();

	clear_back_pal();


#if DEBUG
	usefpcnt=usebpcnt=0;
#endif

	return;
}

/******************************************************************************
 Function: void clear_fore_pal(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	clear out foreground palette map ram
******************************************************************************/
void clear_fore_pal(void)
{
	int l;

	for (l=0;l<NUM_F_PALS;l++)
		sys_memset(fpalram+l,0,sizeof(PALINFO));

	return;
}

/******************************************************************************
 Function: void clear_back_pal(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	clear out background palette map ram
******************************************************************************/
void clear_back_pal(void)
{
	int l;

	for (l=0;l<NUM_B_PALS;l++)
		sys_memset(bpalram+l,0,sizeof(PALINFO));

	return;
}

/******************************************************************************
 Function: WORD get_fore_pal(WORD *pal_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: pal_id - ptr to CLUT data

 Returns: the clut # that this entry uses

 Description:	allocate a palette for the incoming CLUT (FOREGROUNDS)
******************************************************************************/
#if 0
void pal_dbug(void) 
{
	PALINFO *palptr;
	short l=0;

	palptr=fpalram;
	while (l<NUM_PALS)
	{
		if (palptr->palcnt!=0)
		{
			printf(("PALETTE %x %d %d\n",palptr->palid,palptr->palcnt,palptr->paltime));
		}
		palptr++;
		l++;
	}
			 
}
#endif

WORD get_fore_pal(WORD *pal_id)
{
	PALINFO *palptr;
	short l=0;
	//-SONY_IGNORE- WORD cx,cy;

	palptr=fpalram;

	/* search, if id already exists in palette maps */
	while (l<NUM_PALS)
	{
		if (palptr->palid==pal_id)
		{
			palptr->palcnt++;				/* inc # of objects using this palette */

			return((WORD)l);				// return index into pal_buffer
		}
		palptr++;
		l++;
	}

	/* find a spare palette */
	l=0;
	palptr=fpalram;

	while (l<NUM_PALS)
	{
		if (palptr->palcnt==0 && (palptr->paltime==0 || palptr->paltime!=tick))
		{
			//setup palette transfer
			palset_xfer(l,pal_id);		// transfer from source to dest
			palptr->palcnt++;				/* inc # of objects using this palette */
			palptr->palid=pal_id;		/* set id */

#if DEBUG
			usefpcnt++;
#endif
			return((WORD)l);				// return index into pal buffer
		}

		l++;
		palptr++;

	}

//******** HACK TO DEAL WITH RUNNING OUT OF PALETTES ON PLAYER SELECT SCREEN *************
//	if (gstate==GS_PSEL || gstate==GS_POST_PSEL || gstate==GS_BUYIN || gstate==GS_INITIALS)
//		return(get_back_pal(pal_id));
//******** HACK TO DEAL WITH RUNNING OUT OF PALETTES ON PLAYER SELECT SCREEN *************

printf(("NO PALETTES\n"));
	while (1);

	return(0xffff);									/* no available palettes, shuld never get here */
}

#if 0
/******************************************************************************
 Function: WORD get_back_pal(WORD *pal_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: clut - ptr to CLUT data

 Returns: the clut # that this entry uses

 Description:	allocate a palette for the incoming CLUT (BACKGROUNDS)
******************************************************************************/
WORD get_back_pal(WORD *pal_id)
{
	PALINFO *palptr;
	WORD l=0;			
	//-SONY_IGNORE- WORD cx,cy;

	palptr=palram;

	/* search, if id already exists in palette maps */
	while (l<NUM_PALS)
	{
		if (palptr->palid==pal_id)
		{
			palptr->palcnt++;				/* inc # of objects using this palette */
			//-SONY_IGNORE- return(getClut((FORE_CLUT_START_X+((l%CLUT_FACTOR)<<CLUT_SHIFT_SIZE)),(FORE_CLUT_START_Y+(l/CLUT_FACTOR))));
			return((WORD)l);		// get index for buffer
		}
		palptr++;
		l++;
	}

	/* find a spare palette */
	l=NUM_F_PALS;				// start in background palette area
	palptr=bpalram;

	while (l<NUM_PALS)
	{
		if (palptr->palcnt==0 && (palptr->paltime==0 ||palptr->paltime!=tick))
		{
			//setup palette transfer
			palset_xfer(l,pal_id);		// transfer from source to dest
			palptr->palcnt++;				/* inc # of objects using this palette */
			palptr->palid=pal_id;		/* set id */
#if DEBUG
			usebpcnt++;
#endif
			//-SONY_IGNORE_ return(getClut(cx,cy));
			return((WORD)l);			// index into palette buffer
		}
		l++;
		palptr++;

	}


printf(("NO PALETTES\n"));
	while (1);
	
	return(0xffff);									/* no available palettes */
}
#endif

void copy_pal(OBJECT *obj,WORD palid) 
{
	PALINFO *palptr;
	
	free_pal(obj->opal);
	
	obj->opal=palid;
	
	palptr=palram+palid;
	palptr->palcnt++;
	
	return;
}


/******************************************************************************
 Function: void free_pal(WORD clut_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: clut_id - clut id to free

 Returns: None

 Description:	free a palette
******************************************************************************/
void free_pal(WORD clut_id)
{
	short l;
	PALINFO *palptr;

	if (clut_id==0xffff)
		return;
		
	/* convert clut id into palram index */
	l=clut_id;					// clut id is a one to one match 
	
	if (l>=NUM_PALS) LOCKUP;

	palptr=palram+l;

	switch (palptr->palcnt)
	{
		case 0:
			LOCKUP;
			break;
		case 1:
			palptr->paltime=tick;			/* remember ticked freed, since can't allocate same tick */
#if DEBUG
			if (l<NUM_F_PALS)
				usefpcnt--;
			else usebpcnt--;
#endif
		default:
			palptr->palcnt--;
	}

	return;
}

/*
**************************************************************************
*											     *
*  cycle_forward	 / cycle_backward								*
* 											     *
*  a10 = palette										     *
*  a11 = [a,b,c,d]	a = starting color				     	*
* 			b = # of colors to cycle				     *
* 			c = sleep time between each iteration		     *
* 			d = unused							     *
*											     *
**************************************************************************
*/
void color_cycle(WORD *pal,WORD dir)
{
	short startcolor;
	short numcolor;
	short sleeptime;
	int i;
	WORD *src;
	WORD colorid;
	WORD color;

	(ADDRESS)current_proc->pa9=current_proc->a11;

	colorid=findpal(pal);
	if (colorid==0xffff)
		LOCKUP;

	/* cyc1 */
	startcolor=((current_proc->a11)>>24) & 0xff;
	numcolor=((current_proc->a11)>>16) & 0xff;
	sleeptime=((current_proc->a11)>>8) & 0xff;

	src=(WORD *)(&(current_proc->p_context.c_stack));

	/* copy into stack area */
	i=*((LONG *)pal);
	memcpy(src,pal,(i+2)*2);

	while (1)
	{
		if (dir==0)
		{
			/* forward cycle */
			color=*(src+2+startcolor+numcolor-1);
			for (i=startcolor+numcolor+2-1;i>2+startcolor;i--)
				*(src+i)=*(src+i-1);

			*(src+startcolor+2)=color;
		}
		else
		{
			/* backward cycle */
			color=*(src+2+startcolor);
			for (i=2+startcolor;i<(startcolor+numcolor-1);i++)
				*(src+i)=*(src+i+1);
			*(src+startcolor+numcolor+2-1)=color;
		}

		/* transfer to memory */
		palset_xfer(colorid,src);				// transfer to local palette buffers

		process_sleep(sleeptime);
	}
}

//**************************************************************
//**************************************************************
// PALETTE TRANSFER QUE ROUTINES FOR MOVING MEMORY TO VRAM 
// NOT NEEDED FOR U64
//**************************************************************
//**************************************************************
/******************************************************************************
 Function: void palset_xfer(WORD,WORD,WORD *)

 By: David Schwartz

 Date: Sept 1994

 Parameters: id - index into pal buffer memory
 			 clut - ptr to CLUT data

 Returns: the clut # that this entry uses

 Description:	add a palette transfer to queue
******************************************************************************/
void palset_xfer(WORD id,WORD *clut)
{
	paltrans_end->index=id;
	paltrans_end->count=GET_LONG(clut)++;
	paltrans_end->csrc=(ADDRESS *)clut;

	paltrans_end=((paltrans_end+1)==paltrans_queue+PALQ_MAX_ENTRY) ? paltrans_queue:paltrans_end+1;

	return;
}

/******************************************************************************
 Function: void transfer_palettes(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	transfers all palettes in queue
******************************************************************************/
void transfer_palettes(void)
{
	while (paltrans_start != paltrans_end)
	{
		memcpy(&pal_buffer[(paltrans_start->index*256*2)/sizeof(u64)],paltrans_start->csrc,paltrans_start->count*2);

		if ((++paltrans_start)==(paltrans_queue+PALQ_MAX_ENTRY))		/* wrap ptr if needed */
			paltrans_start=paltrans_queue;
	}

	return;
}

#if 0 //-SONY_IGNORE-
/******************************************************************************
 Function: void unget_pal(WORD clut_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: clut_id - clut id to free

 Returns: None

 Description:	clears out a palettes allocation count
******************************************************************************/
void unget_pal(WORD clut_id)
{
	short l;
	PALINFO *palptr;

	/* convert clut id into palram index */
	//-SONY_IGNORE- l=(clut_id-getClut(FORE_CLUT_START_X,FORE_CLUT_START_Y))>>CLUT_ID_SHIFT;

	if (l>=NUM_PALS) LOCKUP;

	palptr=palram+l;

	if (palptr->palcnt>0)
		palptr->paltime=tick;			/* remember ticked freed, since can't allocate same tick */

	palptr->palcnt=0;

#if DEBUG
	if (l<NUM_F_PALS)
		usefpcnt--;
	else usebpcnt--;
#endif

	return;
}

/******************************************************************************
 Function: void blow_pal(WORD *pal_id)

 By: David Schwartz

 Date: Sept 1994

 Parameters: clut_id - clut id to free

 Returns: None

 Description:	zero out the address and color count of a palette map entry
******************************************************************************/
void blow_pal(WORD *pal_id)
{
	short l=0;
	PALINFO *palptr=palram;

	/* find entry to blow up */
	while (l<NUM_PALS)
	{
		if (palptr->palid==pal_id)
		{
			palptr->palcnt=0;				/* kill count */
			palptr->palid=0;				/* kill id */
#if DEBUG
	if (l<NUM_F_PALS)
		usefpcnt--;
	else usebpcnt--;
#endif
			return;
		}
		palptr++;
		l++;
	}
	return;
}

#endif
