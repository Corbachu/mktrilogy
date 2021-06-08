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
#include "mkjoy.h"
#include "mkguys.h"
#include "vcache.h"

/* Prototypes */
static int dummy;

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *dead_anims;
extern void *a_green_splash[];
extern void *a_slime_skel[];
extern void *acidsplash1a[];
extern void *acidskel1[];

extern WORD NESS_P[];
extern BYTE dead_dict[];

void dedpool_cycle(void) 
{
	process_sleep(24);
	current_proc->a11=0x010f0600;
	cycle_forward(NESS_P);
	wait_forever();
}

void calla_dead(void) 
{
	CREATE(PID_CYCLE,dedpool_cycle);
	return;
}

void green_splash_proc(void) 
{
	tsound(0xb6);			
	current_proc->pa9=a_green_splash;
	framew(4);
	delobjp(current_proc->pa8);
	process_suicide();
}

void check_out(int loop) 
{
	OBJECT *obj=current_proc->pa8;
	
	while (--loop>0)
	{
		get_my_dfe();
		if (current_proc->a6<0x30 || current_proc->a5<0x30)
			(current_proc->pa8)->oxvel.pos=0;
	
		process_sleep(1);	
	}
	
	return;
}

void r_fall_in_slime(void) 
{
	OBJECT *ta8,*obj=current_proc->pa8;

	ta8=obj;

	/* fis3 */
	f_shadows=0;
	center_around_me();
	group_sound(9);						// death scream
	shake_a11(6,6);

	get_my_dfe();
	if ((obj->oflags & M_FLIPH)==0)
		current_proc->a6=current_proc->a5;

	if (current_proc->a6<SCX(0x130)) 
	{
		/* fis4 */
		current_proc->pdata.p_ganiy-=8;		//adjust floor to slime
		flight(obj,-SCX(0x40000),-SCY(0xc0000),SCY(0x6000),5,ANIM_ORB_BANGED);
	}
	else
	{
		/* fis5 */
		current_proc->pdata.p_ganiy-=0x20;		//adjust floor to slime
		flight(obj,-SCX(0x40000),-SCY(0xc0000),SCY(0x6000),5,ANIM_KDOWN);
	}

	/* fis6 */
	gso_dmawnz(obj,(ADDRESS)acidsplash1a,dead_dict,0,0);
	alloc_cache((OIMGTBL*)acidsplash1a,0,obj);
	lineup_1pwm(obj,ta8);

	obj->ozval=FRONT_Z+20;
	obj->oypos.u.intpos=(0xb8)+30;
	insert_object(obj,&objlst);
	CREATE(PID_BANI,green_splash_proc);
	current_proc->pa9=obj;
	current_proc->pa8=ta8;

	ta8->oypos.u.intpos+=10;
	process_sleep(4);

	set_inviso(ta8);

	process_sleep(0x50);

	current_proc->a10=(ADDRESS)ta8;

	gso_dmawnz(obj,(ADDRESS)acidskel1,dead_dict,0,0);
	alloc_cache((OIMGTBL*)acidskel1,0,obj);
	obj->oxpos.u.intpos=ta8->oxpos.u.intpos;
	obj->oypos.u.intpos=(0xb0)+32;
	insert_object(obj,&objlst);

	get_my_dfe();
	obj->oxvel.pos=(current_proc->a6>current_proc->a5)?-SCX(0x8000):SCX(0x8000);

	death_blow_complete();

	current_proc->pa9=a_slime_skel;
	framew(5);

	tsound(0xb7);		
	((ADDRESS*)current_proc->pa9)++;
	framew(5);
	
	check_out(0x20);

	if ((swcurr.u.p1pad & MASK_JDOWN) || (swcurr.u.p2pad & MASK_JDOWN) || (randper(200)==SYSTEM_CARRY_SET))
		tsound(0xb8);			

	check_out(0x200);
	wait_forever();
}

