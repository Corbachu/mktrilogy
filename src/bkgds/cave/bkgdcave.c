/******************************************************************************
 File: bkgdcave.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III cave Routines
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
#include "mkjoy.h"
#include "vcache.h"

/* Prototypes */
static int dummy;

void make_hell_flames(void);

/************************************************************
 * 			S O U L  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern BYTE cave_dict[];
/*****************
 Externals
*****************/
/******************************************************************************
 Function: void make_hell_flames(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the caves background
******************************************************************************/
extern void *HELLFLAME01[];
extern void *a_hell_flames[];

DTBL_INIT hell_flame_table [] =
{
	{4,HELLFLAME01,SCX(0x84)+24+8+2,(0x005e)+7,a_hell_flames,&baklst3},
	{4,HELLFLAME01,SCX(0x27d)+24+8+2,(0x005e)+7,a_hell_flames,&baklst3},
	{0}
};

void make_hell_flames(void)
{
	create_dumb_animators_w(hell_flame_table,cave_dict,0);

	return;
}

/************************************************************
 * 			CAVE STUFF *
 ************************************************************/


/******************************************************************************
 Function: void calla_cave(void)

 By: David Schwartz

 Date:  Jan 1995

 Parameters: None

 Returns: None

 Description:	init cave
******************************************************************************/
extern void *a_cave_sky[];
extern void *a_cave_sky_f[];
DTBL_INITA cave_sky_table [] =
{
	{4,SCX(0x84)+0x18,(0x005e)-54-3,a_cave_sky,&baklst4},
	{0x8004,SCX(0x17d)+0xac,(0x005e)-54-2,a_cave_sky_f,&baklst4},
	{0}
};

extern WORD CAVFLR_P[];
extern WORD CAVEFLRw_PAL[];
extern WORD CAVEFLRx_PAL[];
extern WORD CAVEFLRy_PAL[];
extern WORD CAVEFLRz_PAL[];

WORD *cfg_tbl[]=
{
	CAVFLR_P,
	CAVEFLRw_PAL,
	CAVEFLRx_PAL,
	CAVEFLRy_PAL,
	CAVEFLRz_PAL,
	CAVEFLRy_PAL,
	CAVEFLRx_PAL,
	CAVEFLRw_PAL,
	CAVFLR_P,
	NULL
};

void cave_floor_glow(void) 
{
	WORD **ta10;

	while (1)
	{
		ta10=cfg_tbl;

		do
		{
			free_pal(skew_constpal);
			skew_constpal=get_fore_pal((void *)(*ta10));
			process_sleep(3+randu(9));
			
			ta10++;
		}
		while(*ta10!=NULL);
	}
}

void calla_cave(void)
{
	CREATE(PID_CYCLE,cave_floor_glow);

	create_dumb_animators(cave_sky_table,cave_dict,0);

	return;
}

/* Hell Pool Fatlity */
extern void *a_hell_hit[];
extern WORD HELLHIT1_P[];

void fall_in_lava(void) 
{
	OBJECT *obj=current_proc->pa8;
	short ta0;
	P_RAM *pram_ptr;

	f_shadows=0;

	current_proc->pdata.p_store6=(long)obj->oxpos.u.intpos;
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

	insert_object(obj,&baklst7);
	obj->oypos.u.intpos=0;

	set_noscroll(obj);

	ta0=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;
	ta0-=worldtlx.u.intpos;

	if (ta0<=SCRRGT/2)
		ta0+=SCX(0x80);
	else ta0-=SCX(0x80);

	if (ta0<SCX(0x80))
		ta0=SCX(0x80);

	obj->oxpos.u.intpos=ta0;

	group_sound(2);
	obj->oyvel.pos=SCY(0x20000);
	obj->ograv.pos=SCY(0x6000);

	/* lava8 */
	do
	{
		process_sleep(1);
	}
	while(obj->oypos.u.intpos<SCY(0xb2)-24);

	
	/* create new lava object and lineup */
	shake_a11(4,6);
	tsound(0x5f);				
	stop_me(obj);

	if (obj->oflags & M_FLIPH)
		flip_multi(obj);
		
	obj->oxpos.u.intpos-=((obj->header.t_width<<8)/obj->oscale.u.xpos)/2;
	obj->oypos.u.intpos=189;
	obj->oscale.yx=0x01000100;

	
	current_proc->pa9=a_hell_hit;
	obj->oheap=0;
	obj->odict=cave_dict;
	obj->oflags &=(~M_FIGHTER);		// not a fighter anymore, clear the flag
	obj->oflags2 &=~M_MULTIPART;
	swpal(HELLHIT1_P,obj);
	framew(5);
	obj->oypos.u.intpos=0xf00;			// offscreen please
	process_sleep(0x20);

	if ((swcurr.u.p1pad & P1B5) && (swcurr.u.p2pad & P2B5)) 
	{
		tsound(0x66);				// crispy if both runs
		process_sleep(0x40);
	}

	if ((swcurr.u.p1pad & P1B0) && (swcurr.u.p2pad & P2B0)) 
	{
		current_proc->a11=0x1d;				// speech crispy
		create_fx(FX_LAVA_DAN);
		process_sleep(0x48);
	}

	death_blow_complete();

	wait_forever();
}
