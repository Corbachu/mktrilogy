/******************************************************************************
 File: bkgdsbst.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Background Street & Subway Routines
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
#include "mkreact.h"
#include "mkguys.h"
#include "mkdma.h"
#include "vcache.h"

/* local prototypes */
static LONG	dummy;			// used to create a bss section

/* subway stuff */
#define TRAINX (-SCX(0x50))

typedef struct sub_lite {
	void *simg;
	void *spal;
	short sypos;
	short sxpos;
	LONG sflip;
} SLITE;

void calla_street(void);
void storm_proc(void);
void calla_subway(void);
void make_a_gleam(OBJECT **olist,short x,short y);
void light_proc(void);
void fast_sleep(ADDRESS olist,OBJECT *glist);
OBJECT *get_lit_list(SLITE *table);
void train_proc(void);
void start_garbage(void);	

/************************************************************
 * 			S U B W A Y  S T U F F 							*
 ************************************************************/

/********************
 Subway Externals
 ********************/
/* palettes */
extern void *STBREAK_P[];
extern void *P_DARK1[];
extern void *P_DARK11[];
extern void *P_DARK3[];
extern void *P_DARK6[];
extern void *P_DARK8[];
extern void *P_DLITE[];
extern void *P_LITE1[];
extern void *P_LITE11[];
extern void *P_LITE3[];
extern void *P_LITE6[];
extern void *P_LITE8[];
extern void *P_LLITE[];
extern void *P_PILR1a[];
extern void *P_RAILGLM[];

/* animation pieces */
extern void *BKRAIL[];
extern void *FRTRAIL[];
extern void *RAILGLEAM[];
extern void *TRAINA[];
extern void *TRAINB[];
extern void *TRAINC[];
extern void *LITE1[];
extern void *LITE2[];
extern void *LITE3[];
extern void *LITE4[];
extern void *LITE6[];
extern void *LITE7[];
extern void *LITE8[];
extern void *LITE9[];
extern void *LITE10[];
extern void *LITE11[];
extern void *DARK1[];
extern void *DARK2[];
extern void *DARK3[];
extern void *DARK4[];
extern void *DARK6[];
extern void *DARK7[];
extern void *DARK8[];
extern void *DARK9[];
extern void *DARK10[];
extern void *DARK11[];

SLITE unlit_object_table[]=
{
	{DARK1,P_DARK1,17+15+SCY(0x001d),1+14+SCX(0x0154),0},
	{DARK2,P_DARK1,17+15+SCY(0x001d),1+14+SCX(0x01c2),0},
	{DARK6,P_DARK6,17+15+SCY(0x0084),1+16+SCX(0x0155),0},
	{DARK7,P_DARK6,17+15+SCY(0x0084),1+12+SCX(0x01c2),0},
	{DARK4,P_DARK3,17+15+SCY(0x0022),1+12+SCX(0x0165),0},
	{DARK9,P_DLITE,17+13+SCY(0x0028),1+14+SCX(0x019f),0},		// left side

	{DARK1,P_DARK1,17+15+SCY(0x001d),14+SCX(0x053b),1},
	{DARK2,P_DARK1,17+15+SCY(0x001d),13+SCX(0x04cc),1},
	{DARK6,P_DARK6,17+15+SCY(0x0084),12+SCX(0x053d),1},
	{DARK7,P_DARK6,17+15+SCY(0x0084),13+SCX(0x04cc),1},
	{DARK3,P_DARK3,17+15+SCY(0x0022),14+SCX(0x0594),1},
	{DARK9,P_DLITE,17+13+SCY(0x0028),14+SCX(0x0513),1},		// right side

	{DARK8,P_DARK8,17+15+SCY(0x0084),640,0},
	{DARK8,P_DARK8,17+15+SCY(0x0084),729,1},
	{DARK1,P_DARK1,17+15+SCY(0x001d),730,1},
	{DARK1,P_DARK1,17+15+SCY(0x001d),642,0},
	{DARK3,P_DARK3,17+15+SCY(0x0022),800+1,1},
	{DARK4,P_DARK3,17+15+SCY(0x0022),653-1,0},
	{DARK10,P_DLITE,17+13+SCY(0x0029),701,0},
	{DARK11,P_DARK11,17+19+SCY(0x005f),705,0},
	{DARK11,P_DARK11,17+19+SCY(0x005f),728,1},	// middle
	{0,0,0,0,0}
};

SLITE lit_object_table[] =
{
	{LITE1,P_LITE1,17+15+SCY(0x001d),1+14+SCX(0x0154),0},
	{LITE2,P_LITE1,17+15+SCY(0x001d),1+14+SCX(0x01c2),0},
	{LITE6,P_LITE6,17+15+SCY(0x0084),1+16+SCX(0x0155),0},
	{LITE7,P_LITE6,17+15+SCY(0x0084),1+12+SCX(0x01c2),0},
	{LITE4,P_LITE3,17+15+SCY(0x0022),1+12+SCX(0x0165),0},
	{LITE9,P_LLITE,17+13+SCY(0x0028),1+14+SCX(0x019f),0},		// left side

	{LITE1,P_LITE1,17+15+SCY(0x001d),14+SCX(0x053b),1},
	{LITE2,P_LITE1,17+15+SCY(0x001d),13+SCX(0x04cc),1},
	{LITE6,P_LITE6,17+15+SCY(0x0084),12+SCX(0x053d),1},
	{LITE7,P_LITE6,17+15+SCY(0x0084),13+SCX(0x04cc),1},
	{LITE3,P_LITE3,17+15+SCY(0x0022),14+SCX(0x0594),1},
	{LITE9,P_LLITE,17+13+SCY(0x0028),14+SCX(0x0513),1},		// right side

	{LITE8,P_LITE8,17+15+SCY(0x0084),640,0},
	{LITE8,P_LITE8,17+15+SCY(0x0084),729,1},
	{LITE1,P_LITE1,17+15+SCY(0x001d),730,1},
	{LITE1,P_LITE1,17+15+SCY(0x001d),642,0},
	{LITE3,P_LITE3,17+15+SCY(0x0022),800+1,1},
	{LITE4,P_LITE3,17+15+SCY(0x0022),653-1,0},
	{LITE10,P_LLITE,17+14+SCY(0x0029),701,0},
	{LITE11,P_LITE11,17+19+SCY(0x005f),705,0},
	{LITE11,P_LITE11,17+19+SCY(0x005f),728,1},		// middle
	{0,0,0,0,0}
};

WORD train_table[] =
{
	1,TRAINX,1,
	2,SCX(0x51)-1,1,
	3,SCX(0x64)-1,1,
	3,SCX(0x64)-1,0,
	2,SCX(0x51)-1,0,
	1,SCX(0x5c)-1,0,

	1,SCX(0x5c)-1,1,
	2,SCX(0x51)-1,1,
	3,SCX(0x64)-1,1,
	3,SCX(0x64)-1,0,
	2,SCX(0x51)-1,0,
	1,SCX(0x5c)-1,0,
	0
};

void *train_pieces[] = {TRAINA,TRAINB,TRAINC};
extern BYTE sbst_dict[];

/******************************************************************************
 Function: void calla_subway(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the subway background, animations, processes etc.
******************************************************************************/
void calla_subway(void)
{
	short loop;
	short x,y;
	OBJECT *obj;
	PROCESS *ptemp;
	OIMGTBL *frame;


	/* set backrail */
	obj=gbo_dmawnz((OIMGTBL *)BKRAIL,sbst_dict,0,0);
	set_xy_coordinates(obj,480,16+22-8+SCY(0x00ac));
	alloc_cache(BKRAIL,0,obj);
	insert_object(obj,&baklst3);

	obj=gbo_dmawnz((OIMGTBL *)BKRAIL,sbst_dict,0,0);
	set_xy_coordinates(obj,480+161,16+22-8+SCY(0x00ac));
	alloc_cache(BKRAIL,0,obj);
	insert_object(obj,&baklst3);

	/* set frontrail */
	obj=gbo_dmawnz((OIMGTBL *)FRTRAIL,sbst_dict,0,0);
	set_xy_coordinates(obj,480,16+23-8+SCY(0x00c1));
	alloc_cache(FRTRAIL,0,obj);
	insert_object(obj,&baklst3);

	obj=gbo_dmawnz((OIMGTBL *)FRTRAIL,sbst_dict,0,0);
	set_xy_coordinates(obj,480+161,16+23-8+SCY(0x00c1));
	alloc_cache(FRTRAIL,0,obj);
	insert_object(obj,&baklst3);

	/* gleams2 ,insert gleams */
	x=8+SCX(0x0180);
	y=16+21-7+SCY(0x00ac);
	loop=3;
	do
	{
		make_a_gleam(&baklst1,x,y);
		make_a_gleam(&baklst1,x,y+SCY(0x15)+2);	// down to the lower rai
		x+=(SCX(0xe0)*2);						// move under the next lamp
	}
	while(--loop>0);

	/* gleams3 ,insert gleams */
	x=8+SCX(0x0260);
	y=16+21-7+SCY(0x00ac);
	loop=2;
	do
	{
		make_a_gleam(&baklst2,x,y);
		make_a_gleam(&baklst2,x,y+SCY(0x15)+2);	// down to the lower rai
		x+=(SCX(0xe0)*2);						// move under the next lamp
	}
	while(--loop>0);

	/* lights on / lights off */
	obj=get_lit_list(lit_object_table);
	baklst4=(OBJECT *)current_proc->a10=obj;	// turn lights on, enable list

	obj=get_lit_list(unlit_object_table);
	(OBJECT *)current_proc->a11=obj;			// turn lights off,

	ptemp=CREATE(PID_BANI,light_proc);

	return;
}

/******************************************************************************
 Function: void make_a_gleam(OBJECT **olist,short x,short y)

 By: David Schwartz

 Date: Dec 1994

 Parameters: olist - obj list to add to
			 x - xpos
			 y - ypos

 Returns: None

 Description:	add a gleam to the background list specified
******************************************************************************/
void make_a_gleam(OBJECT **olist,short x,short y)
{
	OBJECT *obj;

	obj=gbo_dmawnz((OIMGTBL *)RAILGLEAM,sbst_dict,0,0);
	set_xy_coordinates(obj,x,y);

	alloc_cache(RAILGLEAM,0,obj);

	insert_object(obj,olist);

	return;
}

/******************************************************************************
 Function: void light_proc(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: current_proc->a10 - lit list
			 current_proc->a11 - unlit list

 Returns: None

 Description:  turns lights on and off
******************************************************************************/
void light_proc(void)
{
	OBJECT *gleam_list;
	short loop;

	process_sleep(0x40);				// let the fade happen

	gleam_list=baklst1;				// oa9 -> gleam object list

	/* lproc2 */
	while (TRUE)
	{
		loop=5;

		/* lproc3 */
		do
		{
			fast_sleep(current_proc->a10,gleam_list);

			fast_sleep(current_proc->a11,gleam_list);
		}
		while(--loop>0);

		/* lights on */
		baklst1=gleam_list;								// gleam list on
		baklst4=(OBJECT *)current_proc->a10;		// background list = on

		process_sleep(randu(0x20)+0x20);
	}
}

/******************************************************************************
 Function: void fast_sleep(ADDRESS olist,OBJECT *glist)

 By: David Schwartz

 Date: Dec 1994

 Parameters: olist - obj list to sleep on
			 glist - gleam list, needed when lights go on

 Returns: None

 Description:	routine to sleep for lights
******************************************************************************/
void fast_sleep(ADDRESS olist,OBJECT *glist)
{
	baklst1=(olist==current_proc->a10)? glist:NULL;		// assume gleams "off"
	baklst4=(OBJECT *)olist;							// set list

	process_sleep(randu(5)+2);

	return;
}

/******************************************************************************
 Function: OBJECT *get_lit_list(SLITE *table)

 By: David Schwartz

 Date: Dec 1994

 Parameters: table - list of light objects to add

 Returns: ptr to start of created list

 Description:	add a bunch of lights to a background list
******************************************************************************/
OBJECT *get_lit_list(SLITE *table)
{
	OBJECT *oa9,*obj;
	OIMGTBL *img;
	short x,y;

	(OBJECT *)current_proc->a0=obj_free;
	oa9=NULL;
	while (TRUE)
	{
		(ADDRESS)img=current_proc->a5=(ADDRESS)table->simg;		// get img
		if (current_proc->a5==0)
			break;

		current_proc->a6=(ADDRESS)table->spal;		// get pal
		x=table->sxpos;					// get x coord
		y=table->sypos;					// get y coord
		obj=gbo_dmawnz((OIMGTBL *)current_proc->a5,sbst_dict,0,(void *)current_proc->a6);
		set_xy_coordinates(obj,x,y);

		alloc_cache(img,0,obj);

		if (table->sflip==1)				// flip ?
		{
		 	flip_single(obj);
		}

		/* lit5 */
		if (oa9!=NULL)
			oa9->olink=obj;						// tack on the end

		oa9=obj;

		table++;							// next structure element
	}

	/* lit 4 */
	oa9->olink=NULL;							// terminate list

	return((OBJECT *)current_proc->a0);
}

/******************************************************************************
 Function: void train_proc(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	train routine
******************************************************************************/
void train_proc(void)
{
	WORD *tableptr;
	short x;
	OBJECT *prev_train,*obj,*oa0;
	OIMGTBL *train_frame;

TRAIN_PROC:
	prev_train=NULL;

	tableptr=train_table;
TRAIN3:
	current_proc->a5=GET_WORD(tableptr)++;		// grab image offset
	if (current_proc->a5==0)
	{
		tableptr=NULL;
		goto TRAIN5;
	}

TRAIN2:
	obj=gbo_dmawnz(train_frame=(OIMGTBL *)train_pieces[current_proc->a5-1],sbst_dict,0,0);
//	set_noscroll(obj);
	obj->oid=OID_FX;						// mark train as an effect so that we can kill it later
	obj->oflags2|=M_YLOCK;

	/* get vram info */
	alloc_cache(train_frame,0,obj);

	x=GET_WORD(tableptr)++;								// grab x coord
	
	if (prev_train==NULL) 
		x+=worldtlx6.u.intpos;		

	if ((GET_WORD(tableptr)++)==1)
		flip_single(obj);								// flip object

TRAIN4:
	if (prev_train!=NULL)
		x=prev_train->oxpos.u.intpos-x;		// yes, use as an offset

TRAIN6:
	obj->oxpos.u.intpos=x;

	obj->oypos.u.intpos=SCY(0x3a)+18;			// same y for all pieces

	obj->oxvel.pos=SCX(0x60000);						// train speed

	insert_object(obj,&baklst6);

	/* delete loop */
TRAIN5:
	process_sleep(1);

	if ((oa0=baklst6)==NULL)
		process_suicide();

TRAIN7:
	while (oa0->olink!=NULL)				// peek ahead, last piece exit
	{
		(OBJECT *)current_proc->a1=oa0;		// walk the list
		oa0=oa0->olink;
	}

TRAIN8:
	if ((oa0->oxpos.u.intpos-worldtlx6.u.intpos)>=SCRRGT && obj->oid==OID_FX)			// make sure only kill trains
	{
		delobj_lista4(oa0,&baklst6);

	}

TRAINA:
	if ((obj->oxpos.u.intpos-worldtlx6.u.intpos)<-16)			// time for a new piece
		goto TRAIN5;
		
	prev_train=obj;

	if (tableptr==NULL)
		goto TRAIN5;
	else goto TRAIN3;
}


/************************************************************
 * 			S T R E E T  S T U F F 							*
 ************************************************************/
/********************
 Street Externals
 ********************/
extern void *street_anims[];
extern void *a_storm[];
extern void *a_big_paper_strt[];
extern void *a_lil_paper_strt[];
extern void *a_leaf_strt[];
extern void *a_paper1_strt[];
extern void *STORM01[];
extern void *a_storm[];
extern void *PAPER1_STRT[];



/******************************************************************************
 Function: void calla_street(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the street background
******************************************************************************/
void calla_street(void)
{
	CREATE(PID_BANI,storm_proc);

	CREATE(PID_BANI,wind_sound);

	start_garbage();
	
	return;
}

/******************************************************************************
 Function: void fall_on_trax(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	die by train
******************************************************************************/
extern void train_proc(void);
void fall_on_trax(void)
{
	OBJECT *obj=current_proc->pa8;
	void *ta5;

	current_proc->pdata.p_store6=obj->oxpos.u.intpos;
	group_sound(9);						// death scream

	dallprc(PID_SCROLL);
	dallprc(PID_REPELL);
	dallprc(PID_SMOKER);

	obj->oyvel.pos=-SCY(0x100000);			// zoom off screen
	get_char_ani(ANIM_TABLE1,ANIM_KDOWN);
	init_anirate(6);

	/* trax3 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(distance_off_ground(current_proc,obj)<SCY(0x100));

	stop_me(obj);
	clear_shadow_bit(obj);

	create_fx(FX_SUBWAY_ROX);
	process_sleep(0x50);

	current_proc->a10=(ADDRESS)current_proc->pa8;
#if 0
	ta5=ochar_mini_falls[obj->ochar];
	current_proc->pdata.p_store7=(ADDRESS)ta5;
	gso_dmawnz(obj,(ADDRESS)ta5,mini_anims,0);
	alloc_cache(ta5,&mini_anims,obj);
#endif
	pose_a9(2,ANIM_KDOWN);
	obj->oscale.yx=0x01c001c0;
	clear_shadow_bit(obj);
	obj->ochar=((OBJECT*)current_proc->a10)->ochar;
	obj->oid=((OBJECT*)current_proc->a10)->oid;

	if (current_proc->procid==PID_P1)
	{
		del_loop1(p1_obj,&objlst);				// pull off objlst
		obj_free=obj_free->olink;			// remove from free list so it can be active again
		p1_obj=obj;
	}
	else
	{
		del_loop1(p2_obj,&objlst);				// pull off objlst
		obj_free=obj_free->olink;			// remove from free list so it can be active again
		p2_obj=obj;					// stuff new obj
	}

	player_froze_pal();
	player_normpal();

	insert_object(obj,&baklst6);
	obj->oxpos.u.intpos=(short)current_proc->pdata.p_store6;
	obj->oypos.u.intpos=0;

	obj->oxpos.u.intpos=SCRRGT/2+worldtlx6.u.intpos;

	group_sound(2);

	obj->oyvel.pos=SCY(0x30000);			// fall down
	obj->ograv.pos=SCY(0x6000);

	CREATE(PID_BANI,train_sound_proc);

	/* trax8 */
	do
	{
		process_sleep(1);
	}
	while(obj->oypos.u.intpos<SCY(0x90));			// fall until hit ground

	shake_n_sound();
	stop_me(obj);
	process_sleep(0x18);

#if 0
	ta5=ochar_mini_stunned[obj->ochar];
	animate(SINGLE_ANI,ta5,obj->oflags);
#endif
	obj->oypos.u.intpos=SCY(0xe8)-obj->osize.u.ypos;
	pose_a9(0,ANIM_DIZZY);

	obj->oyvel.pos=-SCY(0x30000);
	do
	{
		process_sleep(1);
	} while ( obj->oypos.u.intpos>87);
	stop_a8(obj);

	get_char_ani(ANIM_TABLE1,ANIM_DIZZY);			// act a bit dizzy (arcade mod)
	init_anirate(5);
	current_proc->a10=0x15;
	do
	{
		next_anirate();
		process_sleep(1);
	} while (--current_proc->a10>0 );


	CREATE(PID_BANI,train_proc);

	current_proc->a10=0x1c;
	do
	{
		next_anirate();
		process_sleep(1);
	} while (--current_proc->a10>0 );

	group_sound(9);
	tsound(0x83);
#if 0
	(ADDRESS)ta5=current_proc->pdata.p_store7;
	animate(SINGLE_ANI,ta5,obj->oflags);
#endif
	pose_a9(2,ANIM_KDOWN);

	obj->oypos.u.intpos-=SCY(0x20);

#if 0
	if ( p1_obj==obj )
		p1_xvel.pos=obj->oxvel.pos=SCX(0x80000);
	else p2_xvel.pos=obj->oxvel.pos=SCX(0x80000);
#endif

	obj->oxvel.pos=SCX(0x80000);
	obj->oyvel.pos=-SCY(0x30000);
	obj->ograv.pos=SCY(0x6000);
	shake_a11(5,5);

	process_sleep(0x30);
	death_blow_complete();
	process_sleep(0x20);

	wait_forever();
}

void train_sound_proc(void)
{
	tsound(0x84);
	process_sleep(0x10);

	tsound(0x85);
	process_sleep(0x38);
	tsound(0x85);
	process_sleep(0x38);
	tsound(0x85);
	process_sleep(0x38);
	tsound(0x85);
	process_sleep(0x38);

	tsound(0x86);

	process_suicide();
}
