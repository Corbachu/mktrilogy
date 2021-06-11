/******************************************************************************
 File: bkgdpit.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Pit Routines
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
#include "mkjoy.h"
#include "moves.h"
#include "mkguys.h"
#include "vcache.h"
#include "mkblood.h"
#include "mksound.h"
#include "mkfatal.h"
#include "mkr1.h"

long long kung5_buffer[80*1024/sizeof(long long)];

extern void *a_pittorch[];
extern BYTE mk1pit_dict[];
extern ADDRESS preload_pittorch[];

/*****************
*****************/

DTBL_INITA mk1pit_table [] =
{
	{5,0x5c+3,0x2b,a_pittorch,&baklst7},
	{5,0x341-1,0x2b,a_pittorch,&baklst7},
	{0}
};

extern void *a_silo[];

char txt_sinvade[]="WINNER INVADES SPACE!\n";
void moon_flyer(void) 
{
	OBJECT *obj;
	
	process_sleep(0x20);
	
	current_proc->pa9=a_silo;
	((ADDRESS *)current_proc->pa9)+=randu(4)-1;
	
	(ADDRESS)current_proc->a5=GET_LONG(current_proc->pa9);
	gso_dmawnz(obj,(ADDRESS)current_proc->a5,0,0,0);
	alloc_cache((void *)current_proc->a5,0,obj);
	insert_object(obj,&baklst7);
	
	obj->oxpos.u.intpos=-60+worldtlx.u.intpos;
	obj->oypos.u.intpos=0x50;	
	obj->oxvel.pos=SCX(0x20000);
	
	current_proc->a10=2;
	do
	{
		while (obj->oxpos.u.intpos<SCRRGT+worldtlx.u.intpos)
		{
			if (((swcurr.u.p1pad & MASK_SELECT) || (swcurr.u.p2pad & MASK_SELECT)) & f_silotte==0) 
			{
				if ((obj->oxpos.u.intpos-worldtlx.u.intpos)>20 && (obj->oxpos.u.intpos-worldtlx.u.intpos)<240)
				{
					f_silotte=1;
					tsound(0x8e);
					msg1(txt_sinvade);
				}
			}
			process_sleep(1);
		}
		
		obj->oxpos.u.intpos=-70;
		obj->oxvel.pos=0;
		process_sleep(0x120);
		obj->oxvel.pos=SCX(0x20000);
	}
	while(--current_proc->a10>0);

	delpal(obj);
	del_loop(obj,&baklst7);
	
	process_suicide();
}

void calla_mk1pitstar(void) 
{
	int i;
	OBJECT *obj;
	BYTE *dmem;

	dmem=vmem_predecomp_perm((ADDRESS*)preload_pittorch,mk1pit_dict,(BYTE *)&kung5_buffer[0],80*1024);
	
	create_dumb_animators(mk1pit_table,mk1pit_dict,0);
	
	if (randper(100)==SYSTEM_CARRY_SET && count_active_players()==2 && round_num<=1)
	{
		CREATE(PID_BANI,moon_flyer);
		f_silotte=0;
	}
	
	return;	
}



//******************************************************************************/
//******************************************************************************/
/******************************************************************************
 Function: void pit_scroll_proc(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:  falling down the pit scroll proc
******************************************************************************/
void mk1pit_scroll_proc(void)
{
	PROCESS *pa0;
	OBJECT *oa11=(OBJECT*)current_proc->a11;
	OBJECT *obj,*oa9;
	short ta0,ta1;

	stop_scrolling();
	scrolly.pos=0;

	white_flash();

	pa0=process_exist(PID_BACKG,0xffff);
	pa0->a10=1;							// background updateer = every tick
	current_proc->pdata.p_store1=0;			// init: clear this long

	current_proc->a10=0x8;				// time before switching camera view

	/* pits1, follow him down the pit */
	do
	{
		do
		{
			process_sleep(1);

			ta0=oa11->oxpos.u.intpos;
			ta1=worldtlx.u.intpos+SCRRGT/2;
			if (abs(ta0-ta1)<6)
			{
				/* pits3 (stop_scrolling) */
				stop_scrolling();						// just about centered --> stop scroll
			}
			else
			{
				if (ta0>ta1)
				{
					/* pit_scroll_right */
					if (worldtlx.u.intpos>=right_edge)
						stop_scrolling();
					else ss_20000(0);
				}
				else
				{
					/* pit_scroll_left */
					if (worldtlx.u.intpos<=left_edge)
						stop_scrolling();
					else ss_20000(1);
				}
			}

			/* pits3 */
			if ( current_proc->a10==0 )
				goto PITS5;
		}
		while(--current_proc->a10>0);

		current_proc->a10=0;

PITS5:
		/* pits5 */
		scrolly.pos=oa11->oyvel.pos;//+((oa11->oyvel.pos)>>3)+((oa11->oyvel.pos)>>4);		// scroll faster then dude falling

		oa9=(OBJECT *)current_proc->pdata.p_store1;
		oa9=NULL;
		if ( oa9!=NULL )
		{
 			current_proc->a0=oa9->oypos.u.intpos;
 			(current_proc->a0)-=(short)(SCRBOT-SCY(0x60));
		}
	} while (oa11->oypos.u.intpos<ground_y+378);

	scrolly.pos=0;
	stop_scrolling();

	/* pits6 */
	do
	{
		current_proc->p_comp_flag=PC_PIT_STOP;
		process_sleep(10);
	} while ( 1);

}


void mk1pit_fall_scan(void)
{
	long ta0;

	current_proc->a11=(current_proc->pa8)->oxvel.pos;
	ta0=(current_proc->pa8)->oyvel.pos;
	if (ta0>=SCY(0x80000))
	{
		(current_proc->pa8)->ograv.pos=0;
		(current_proc->pa8)->oyvel.pos=SCY(0x120000);
	}
	return;
}


/******************************************************************************
 Function: void fall_down_pit(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	die by pit
******************************************************************************/
void fall_down_mk1pit(void)
{
	PROCESS *ptemp;
	long ta0;

//	f_death=FAT_PIT;
	init_death_blow(FAT_PIT);
	disable_his_buttons;
	
	group_sound(9);			// death scream

	ptemp=process_exist(PID_SCROLL,0xffff);
	fastxfer(ptemp,mk1pit_scroll_proc);
	ptemp->a11=(ADDRESS)current_proc->pa8;

	current_proc->pdata.p_ganiy+=550;			// floor way down there

	if ( (current_proc->pa8)->oxpos.u.intpos<SCX(0x1c3) || (current_proc->pa8)->oxpos.u.intpos>SCX(0x2f0)  )
		ta0=SCX(0x8000);
	else ta0=SCX(0x20000);

	/* normfall */
	(FUNC)current_proc->a6=mk1pit_fall_scan;
	flight_call(current_proc->pa8,ta0,-(SCY(0x160000)),SCY(0x7000),5,ANIM_KDOWN);

	/* continue falling ! */
	(current_proc->pa8)->oyvel.pos=(0x120000);
	(current_proc->pa8)->oxvel.pos=(long)current_proc->a11;

	/* fdp4 */
	do
	{
		process_sleep(1);
		ptemp=process_exist(PID_SCROLL,0xffff);
	} while (ptemp->p_comp_flag!=PC_PIT_STOP);

	rsnd_stab();
	death_scream;
	find_ani_part2(ANIM_KDOWN);
	do_next_a9_frame(current_proc->pa8);

	do
	{
		process_sleep(1);
	}
	while((current_proc->pa8)->oypos.u.intpos<current_proc->pdata.p_ganiy+50);
	
	(current_proc->pa8)->oyvel.pos=0;
	(current_proc->pa8)->oxvel.pos=0;

	stop_a8(current_proc->pa8);
	
	create_blood_proc(BLOOD_PIT);

	ground_y=(current_proc->pa8)->oypos.u.intpos+SCY(0xa0);

	/* make dude flat */
	find_ani_part2(ANIM_KDOWN);
	mframew(5);

	shake_a8_up(current_proc->pa8,5,0,3,3);

	process_sleep(0x30);
	death_blow_complete();
	wait_forever();
}
