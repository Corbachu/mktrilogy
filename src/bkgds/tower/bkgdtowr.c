/******************************************************************************
 File: bkgddead.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Bank Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkfx.h"
#include "mkani.h"
#include "mkinit.h"
#include "mkpal.h"
#include "mksound.h"
#include "vcache.h"

/* Prototypes */
long long tower_buffer[93*1024/sizeof(long long)];

void monk_proc(void);
void cloud_proc(void);

OBJECT *monk_piece(LONG pa4);

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern BYTE tower_dict[];
extern BYTE monk_dict[];

void calla_sktower(void) 
{
	PROCESS *ptemp;
	
	CREATE(PID_BANI,cloud_proc);
	ptemp=CREATE(PID_BANI,monk_proc);
	ptemp->pdata.p_store1=0x004501ca;
	ptemp->pdata.p_store2=0x004801c8;
	ptemp->pdata.p_store3=(ADDRESS)&baklst5;
	return;
}


#define WINDOW_LEFT	SCX(0x1ca)
#define WINDOW_RIGHT (SCX(0x290)+32)
extern void *cloud1a[];
extern void *cloud1b[];
extern void *cloud1c[];
extern void *cloud1d[];

short cloud_wrap[]=
{
	-69,SCY(0x00),	// 0
	-78,SCY(0x2c),	// 1
	-78,SCY(0x00),	// 2
	-69,-SCY(0x2c),	// 3
};

typedef struct
{
	void *cloud_img;
	short cloud_x;
	short cloud_y;
} CLOUDS;

CLOUDS cloud_row[]=
{
	{cloud1a,0x8000+69,SCY(0x2d)},
	{cloud1b,0x8000+78,-SCY(0x2d)},
	{cloud1b,78,SCY(0x00)},
	{cloud1a,0,0},
};

void left_edge_clip(OBJECT *pa5,OBJECT *pa14) 
{
	short ta0,ta1,ta2;
	
	ta2=pa14->oypos.u.intpos & 0x0fff;			// assume back to our normal position
	ta0=pa5->oxpos.u.intpos;
	ta1=pa14->osize.u.xpos;				
	ta0-=ta1;					// a0 - my unclipped x
	ta1+=ta0;					// a1 - right edge

	ta1-=WINDOW_LEFT-8;			// a1 = # of pixels on screen
	if (ta1>=4) 
	{
		/* onscreen --> check for clipping */
		pa14->oypos.u.intpos=ta2;				// on screen = normal y position
//		if (ta0>=WINDOW_LEFT-8) 
		{
			/* cld8 */
			pa14->ofset=0;
			pa14->oxpos.u.intpos=ta0;			// fully on screen = set true x position
			return;
		}
#if 0
		ta2=pa14->osize.u.xpos;
		ta2-=ta1;				// a2 = amount to clip off left
		
		pa14->ofset=ta2;		// set "left clip"
		
		ta0+=ta2;
		pa14->oxpos.u.intpos=ta0;
		//pa14->oxpos.u.intpos=WINDOW_LEFT-8;		// adjust coordinates for clip change
		pa14->ofset=0;
		pa14->oxpos.u.intpos=ta0;			// fully on screen = set true x position
#endif		
	}
	else
	{
		/* cld7 */
		pa14->oypos.u.intpos=ta2+0x4000;
		
	}

	return;
}

void clip_a_row(OBJECT **pa8,OBJECT **pa9,OBJECT **pa10,OBJECT **pa11) 
{
	OBJECT *ta14;
	short ta0,ta1,ta2;

	/* beyond right edge */
	if ((*pa11)->oxpos.u.intpos>WINDOW_RIGHT) 
	{
		(*pa11)->ofset=0;			// no clipping
		
		(*pa11)->oxpos.u.intpos=(*pa8)->oxpos.u.intpos+cloud_wrap[((LONG)(*pa11)->oslink-1)*2];
		(*pa11)->oypos.u.intpos=(*pa8)->oypos.u.intpos+cloud_wrap[((LONG)(*pa11)->oslink-1)*2+1];

		ta14=*pa8;				// cloud shuffle
		*pa8=*pa11;				// clouds are: a8 --> a9 --> a10 --> a11
		*pa11=*pa10;
		*pa10=*pa9;
		*pa9=ta14;
	}

	/* cld5 */
	left_edge_clip(*pa9,*pa8);		// clip 2 leftmost clouds
	left_edge_clip(*pa10,*pa9);
	(*pa10)->ofset=0;					// make sure no clip on a10 cloud
	(*pa11)->ofset=0;					// make sure no clip on a11 cloud

#if 0
	/* clip rightmost cloud (a11) */
	ta1=ta2=(*pa11)->osize.u.xpos;
	ta1+=(*pa11)->oxpos.u.intpos-WINDOW_RIGHT;
	if (ta1>0) 
	{
		ta2-=ta1;				// # of pixels on screen
		if (ta2<=3) 			// more than 3
			ta1-=3;				// no, make sure at least 3

		(*pa11)->ofset=((WORD)ta1)<<8;	// set right clipping
	}
#endif
	return;
}

void make_a_cloud(long xvel,short pb2x,short pb2y,WORD pa11) 
{
	OBJECT *obj;
	gso_dmawnz(obj,(ADDRESS)cloud1a,tower_dict,0,0);
	obj->oflags|=M_CLIP;
	set_xy_coordinates(obj,pb2x,pb2y);
	alloc_cache(cloud1a,0,obj);
	(LONG)obj->oslink=pa11;
	obj->oxvel.pos=xvel;
	return;
}

void get_a8_to_a11(long xvel,short pb2x,short pb2y) 
{
	make_a_cloud(xvel,pb2x,pb2y,4);
	(OBJECT *)current_proc->a10=current_proc->pa8;

	current_proc->a11=3;
	/* cld2 */
	do
	{
		(OBJECT *)current_proc->pa9=current_proc->pa8;
		make_a_cloud(xvel,pb2x,pb2y,current_proc->a11);

		(current_proc->pa8)->oxpos.u.intpos=((OBJECT*)current_proc->pa9)->oxpos.u.intpos;
		(current_proc->pa8)->oypos.u.intpos=((OBJECT*)current_proc->pa9)->oypos.u.intpos;
		animate(SINGLE_ANI,(OIMGTBL *)cloud_row[current_proc->a11-1].cloud_img,(current_proc->pa8)->oflags);

		(current_proc->pa8)->oflags|=M_CLIP;

		if (cloud_row[current_proc->a11-1].cloud_x & 0x8000)
			flip_single(current_proc->pa8);

		(current_proc->pa8)->oxpos.u.intpos=((OBJECT*)current_proc->pa9)->oxpos.u.intpos+cloud_row[current_proc->a11-1].cloud_x & 0x7fff;
		(current_proc->pa8)->oypos.u.intpos=((OBJECT*)current_proc->pa9)->oypos.u.intpos+cloud_row[current_proc->a11-1].cloud_y;
		((OBJECT *)current_proc->pa9)->olink=current_proc->pa8;

	}
	while(--current_proc->a11>0);

	current_proc->pa8=(OBJECT *)current_proc->a10;
	(OBJECT*)current_proc->pa9=(current_proc->pa8)->olink;
	(OBJECT*)current_proc->a10=((OBJECT*)current_proc->pa9)->olink;
	(OBJECT*)current_proc->a11=((OBJECT*)current_proc->a10)->olink;
	((OBJECT*)current_proc->a11)->olink=NULL;

	return;
}

extern ADDRESS preload_clouds[];
extern ADDRESS preload_monk[];

void cloud_proc(void) 
{
	int i;
	OBJECT *l1_a8,*l1_a9,*l1_a10,*l1_a11;
	OBJECT *l2_a8,*l2_a9,*l2_a10,*l2_a11;
	BYTE *dmem;

	dmem=vmem_predecomp_perm(preload_clouds,tower_dict,(BYTE *)&tower_buffer[0],93*1024);
	dmem=vmem_predecomp_perm(preload_monk,monk_dict,dmem,93*1024-(dmem-(BYTE *)&tower_buffer[0]));

	get_a8_to_a11(SCX(0x30000),WINDOW_LEFT-SCX(0x30),SCY(0x2a)+24);
	baklst7=current_proc->pa8;
	l1_a8=current_proc->pa8;
	l1_a9=(OBJECT*)current_proc->pa9;
	l1_a10=(OBJECT*)current_proc->a10;
	l1_a11=(OBJECT*)current_proc->a11;

	get_a8_to_a11(SCX(0x18000),WINDOW_LEFT,24);
	baklst8=current_proc->pa8;
	l2_a8=current_proc->pa8;
	l2_a9=(OBJECT*)current_proc->pa9;
	l2_a10=(OBJECT*)current_proc->a10;
	l2_a11=(OBJECT*)current_proc->a11;

	for (i=0;i<200;i++)
	{
		l1_a8->oxpos.pos+=l1_a8->oxvel.pos;
		l1_a9->oxpos.pos+=l1_a9->oxvel.pos;
		l1_a10->oxpos.pos+=l1_a10->oxvel.pos;
		l1_a11->oxpos.pos+=l1_a11->oxvel.pos;
		l2_a8->oxpos.pos+=l2_a8->oxvel.pos;
		l2_a9->oxpos.pos+=l2_a9->oxvel.pos;
		l2_a10->oxpos.pos+=l2_a10->oxvel.pos;
		l2_a11->oxpos.pos+=l2_a11->oxvel.pos;
		clip_a_row(&l2_a8,&l2_a9,&l2_a10,&l2_a11);
		clip_a_row(&l1_a8,&l1_a9,&l1_a10,&l1_a11);
	}
	
	/* cloud move loop */
	do
	{
		clip_a_row(&l2_a8,&l2_a9,&l2_a10,&l2_a11);
		clip_a_row(&l1_a8,&l1_a9,&l1_a10,&l1_a11);
		process_sleep(2);
	}
	while(1);
}
