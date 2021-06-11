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
#include "mkmain.h"
#include "mkjoy.h"
#include "mkinit.h"
#include "mkfatal.h"
#include "mkguys.h"
#include "mkpal.h"
#include "mkblood.h"
#include "mksound.h"
#include "vcache.h"

/* Prototypes */
static LONG	dummy;			// used to create a bss section

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

extern void *dlists_ceiling[];

/********************
 Externals
 ********************/
extern void *armory_anims[];
extern void *a_lava[];
extern BYTE armory_dict[];
DTBL_INITA lava_table [] =
{
	{0x8006,0x61,0x56,a_lava,&baklst3},
	{0x0006,0xc8,0x56,a_lava,&baklst3},
	{0x8006,0x2c6,0x56,a_lava,&baklst3},
	{0}
};

extern WORD VAT[];
void armory_cycle(void) 
{
	process_sleep(24);
	current_proc->a11=0x2d0b0600;
	cycle_forward(VAT);
	wait_forever();
}

void calla_armory(void)
{
	CREATE(PID_CYCLE,armory_cycle);
	create_dumb_animators(lava_table,armory_dict,0);
	return;
}


/************************************************************
 * 			LAIR S T U F F 								*
 ************************************************************/
extern void *lair_anims[];
#define EYE_COUNT 8
short eye_table[EYE_COUNT][2]=
{
	{30,80},
	{90,110},
	{120,75},
	{157,144},
	{200,97},
	{257,154},
	{287,124},
	{333,99},
};

#define EYE_CYCLE_COUNT	8
WORD eye_cycle[]=
{
	0x0000,
	0xffff>>6,
	0xffff>>5,
	0xffff>>4,
	0xffff>>3,
	0xffff>>2,
	0xffff>>1,
	0xffff,
};

void goro_eyes(void) 
{
	OBJECT *obj,*obj2;
	LONG ta11=current_proc->a11;
	
	obj=make_solid_object(0xffff,2,2);	
	obj->ozval=999;
	obj->oxpos.u.intpos=eye_table[ta11][0]-4;
	obj->oypos.u.intpos=worldtly.u.intpos+eye_table[ta11][1];
	set_noscroll(obj);
	set_inviso(obj);
	insert_object(obj,&baklst8);

	obj2=make_solid_object(0xffff,2,2);	
	obj2->ozval=999;
	obj2->oxpos.u.intpos=eye_table[ta11][0]+4;
	obj2->oypos.u.intpos=worldtly.u.intpos+eye_table[ta11][1];
	set_noscroll(obj2);
	set_inviso(obj2);
	insert_object(obj2,&baklst8);
	
	while (1)
	{
		current_proc->a11=randu_minimum(0x30,0x40);
		process_sleep(current_proc->a11);
		current_proc->a11=EYE_CYCLE_COUNT;
		do
		{
			obj->oconst=eye_cycle[current_proc->a11];
			obj2->oconst=eye_cycle[current_proc->a11];
			process_sleep(2);
		}
		while(--current_proc->a11>0);
	}
	
	
}
void calla_lair(void) 
{
	int i;
	
//	for (i=0;i<EYE_COUNT;i++)
//		CREATE(PID_BANI,goro_eyes)->a11=i;
		
	return;
}


/************************************************************
 * 			TOMB   S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
/* BAT CODE */
extern void *tomb_anims[];
extern void *a_medbat[];
extern void *a_smallbat[];
extern void *MEDBAT1[];

void set_bat_coordinates(short pax,short pay) 
{
	set_xy_coordinates(current_proc->pa8,worldtlx4.u.intpos+pax,worldtly.u.intpos+pay);
	return;
}

void get_bat_obj(long pvel,short pax,short pay) 
{
	OBJECT *obj;

	gso_dmawnz(obj,(ADDRESS)MEDBAT1,armory_dict,0,0);
	alloc_cache(MEDBAT1,0,obj);

	obj->oxvel.pos=pvel;
	set_bat_coordinates(pax,pay);

	insert_object(obj,&baklst4);
	return;
}

void bat_pause(void) 
{
	long ta11=(current_proc->pa8)->oxvel.pos;
	stop_a8(current_proc->pa8);
	process_sleep(0x60);
	(current_proc->pa8)->oxvel.pos=ta11;
	return;
}
void bats_proc(void) 
{
	get_bat_obj(-SCX(0x20000),SCX(0x800),SCY(0x800));

	/* bat2 */
	while (1)
	{
		set_bat_coordinates(SCX(0x190),SCY(0x50));

		current_proc->pa9=a_medbat;
		init_anirate(1);

		/* bat3 */
		do
		{
			process_sleep(6);
			next_anirate();
		}
		while(worldtlx4.u.intpos-(current_proc->pa8)->oxpos.u.intpos<SCX(0x40)+0x20);

		bat_pause();
	}
}

void small_bat_proc(void) 
{
	get_bat_obj(SCX(0x10000),-SCX(0x40),SCY(0x60));
	flip_single(current_proc->pa8);

	/* bat0 */
	while (1)
	{
		set_bat_coordinates(-SCX(0x40),SCY(0x60));

		current_proc->pa9=a_smallbat;
		init_anirate(1);

		/* bat3 */
		do
		{
			process_sleep(6);
			next_anirate();
		}
		while((current_proc->pa8)->oxpos.u.intpos-(worldtlx4.u.intpos+SCRRGT)<SCX(0x40));

		bat_pause();
	}
}

/* Spike Fatality Code */
extern void *spikeroof2[];
extern void *spikes[];

void ceiling_scroll(void) 
{
	stop_scrolling();
	scrolly.pos=0;

	/* up we go */
	do
	{
		process_sleep(1);
		scrolly.pos=-SCY(0x30000);
	}
	while(abs(worldtly.u.intpos-ceiling_y)<SCY(0x30));

	scrolly.pos=0;

	wait_forever();
}

void one_roof_tile(short pa1,short pa14) 
{
	OBJECT *obj;

	gso_dmawnz(obj,(ADDRESS)spikeroof2,armory_dict,0,0);
	alloc_cache((OIMGTBL*)spikeroof2,0,obj);
	obj->oxpos.u.intpos=pa1;
	obj->oypos.u.intpos=ceiling_y-64;
	obj->ozval=0;
	insert_object(obj,&baklst1);

	gso_dmawnz(obj,(ADDRESS)spikes,armory_dict,0,0);
	alloc_cache((OIMGTBL*)spikes,0,obj);
	obj->oxpos.u.intpos=pa1-(worldtlx2.u.intpos-worldtlx.u.intpos);
	obj->oypos.u.intpos=ceiling_y-36;
	obj->ozval=FRONT_Z+50;
	insert_object(obj,&objlst);

	return;
}

extern void *dlist_ceiling;
void spike_the_ceiling(void) 
{
	OBJECT *ta8=current_proc->pa8;
	OBJECT *obj;
	short ta14,ta1,ta9;

	DONT_SHOW_SCORES;
	dlists=dlists_ceiling;

	ta14=worldtlx2.u.intpos-SCX(070);
	ta1=SCX(0x1eb-140);

	do
	{
		ta1+=SCX(070);
	}
	while(ta1<ta14);

	ta9=7;
	do
	{
		one_roof_tile(ta1,ta14);
		ta1+=SCX(70);
	}
	while(--ta9>0);

	current_proc->pa8=ta8;

	return;
}


void scan_for_ceiling(void)
{
	OBJECT *obj=current_proc->pa8;

	if (obj->oypos.u.intpos>=(ceiling_y-SCY(0x34)+5)) 
	{
		if (distance_off_ground(current_proc,obj)>SCY(0xa0)-5)
			f_shadows=0;

		return;
	}

	/* sfc9 */
	rsnd_stab();				
	death_scream;
	stop_me(obj);

	shake_a11(8,8);
	get_char_ani(ANIM_TABLE1,ANIM_KDOWN);
	find_part2();
	find_last_frame();
	do_next_a9_frame(obj);
	multi_adjust_xy(obj,0,-SCY(0x40));

	death_blow_complete();

	if (((swcurr.u.p1pad & MASK_JDOWN) && (swcurr.u.p2pad & MASK_JDOWN)) || (randper(150)==SYSTEM_CARRY_SET)) 
	{
		/* sfcc */
		process_sleep(0x80);
		obj->oyvel.pos=SCY(0x2000);
		process_sleep(0x70);
		group_sound(2);
		flight(obj,0,SCY(0x20000),SCY(0x8000),NEVER_ANI,-1);
		shake_n_sound();
	}
	else
	{
		/* sfca */
		create_blood_proc(BLOOD_SPIKE_DRIP);		
	}

	wait_forever();
}

void r_spike_rise(void) 
{
	PROCESS *ptemp;

	spike_the_ceiling();

	ptemp=process_exist(PID_SCROLL,0xffff);
	fastxfer(ptemp,ceiling_scroll);
	ptemp->a11=(ADDRESS)current_proc->pa8;

	current_proc->a6=(ADDRESS)scan_for_ceiling;
	flight_call(current_proc->pa8,SCX(0x10000),-SCY(0xe0000),SCY(0x2000),5,ANIM_KDOWN);
	wait_forever();
}


void calla_tomb(void) 
{
	CREATE(PID_BANI,bats_proc);
	CREATE(PID_BANI,small_bat_proc);

	return;
}
