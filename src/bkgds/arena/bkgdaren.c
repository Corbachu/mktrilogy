/******************************************************************************
 File: bkgdaren.c

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
static LONG	dummy;			// used to create a bss section

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_boss[];
extern void *bosssit1[];
extern void *crowd1[];
extern void *crowd2[];
extern void *crowd3[];
extern void *RCHAIN1[];
extern void *BCHAIN1[];
extern void *a_raidch[];
extern void *a_barakach[];
extern BYTE arena_dict[];

void sitting_kahn(void) 
{
	OBJECT *obj;

	if (p1_char==FT_SK || p2_char==FT_SK)
		process_suicide();

	gso_dmawnz(obj,(ADDRESS)bosssit1,arena_dict,0,0);
	obj->oxpos.u.intpos=worldtlx.u.intpos+SCX(0x94);
	obj->oypos.u.intpos=worldtly.u.intpos+SCY(0x2b)+16;
	alloc_cache((OIMGTBL *)bosssit1,0,obj);
	insert_object(obj,&baklst1);

	while (winner_status!=3) 
	{
		if (p1_char==FT_SK || p2_char==FT_SK) 			// kahn fights he dont sit
		{
			delpal(obj);					// get rid of palette
			delobj_lista4(obj,&baklst1);	// remove object
			process_suicide();
		}
			
		process_sleep(1);
	}

	current_proc->pa9=a_boss;
	framew(7);
	process_suicide();
}

#if 0
void rayden_proc(void) 
{
	OBJECT *obj;

	process_suicide();

	if (p1_char==FT_RAYDEN || p2_char==FT_RAYDEN)
		process_suicide();

	gso_dmawnz(obj,(ADDRESS)RCHAIN1,arena_dict,0,0);
	obj->oxpos.u.intpos=worldtlx.u.intpos-114;
	obj->oypos.u.intpos=worldtly.u.intpos+SCY(0x49)+27;
	alloc_cache((OIMGTBL *)RCHAIN1,0,obj);
	insert_object(obj,&baklst1);

	do
	{
		current_proc->pa9=a_raidch;
		framew(8);
		process_sleep(0x30+randu(35));
	}
	while(1);
	process_suicide();
}

void baraka_proc(void) 
{
	OBJECT *obj;

	process_suicide();

	if (p1_char==FT_BARAKA || p2_char==FT_BARAKA)
		process_suicide();

	gso_dmawnz(obj,(ADDRESS)BCHAIN1,arena_dict,0,0);
	obj->oxpos.u.intpos=worldtlx.u.intpos+SCX(0x1e7)-54;
	obj->oypos.u.intpos=worldtly.u.intpos+SCY(0x49)+27;
	alloc_cache((OIMGTBL *)BCHAIN1,0,obj);
	insert_object(obj,&baklst1);

	do
	{
		current_proc->pa9=a_barakach;
		framew(8);
		process_sleep(0x30+randu(30));
	}
	while(1);
	process_suicide();
}
#endif

#define CROWD_START	(SCX(127)+0x2c+SCX(0x79))

short crowd_coordinates[]=
{
	CROWD_START-SCX(0x79),
	CROWD_START,
	CROWD_START+SCX(0x79),
	CROWD_START+(SCX(0x79)*2),
	CROWD_START+(SCX(0x79)*3),
	CROWD_START+(SCX(0x79)*4),
	0
};

void crowd_ani_jsrp(void) 
{
	OBJECT *obj;
	void *ta9=current_proc->pa9;

	obj=(OBJECT *)&baklst5;
	while(obj->olink!=NULL)
	{
		obj=obj->olink;
		current_proc->pa9=ta9;
		current_proc->pa8=obj;
		animate(SINGLE_ANI,current_proc->pa9,obj->oflags);
	}

	process_sleep(8);
	return;
}

void crowd_ani(void) 
{
	OBJECT *obj;

	short *ta7=crowd_coordinates;

	do
	{
		gso_dmawnz(obj,(ADDRESS)crowd1,arena_dict,0,0);
		set_xy_coordinates(obj,*ta7,SCY(0x7c)+0xf);
		alloc_cache(crowd1,0,obj);
		insert_object(obj,&baklst5);
		ta7++;
	}
	while(*ta7!=0);

	do
	{
		current_proc->pa9=crowd1;
		crowd_ani_jsrp();
		current_proc->pa9=crowd2;
		crowd_ani_jsrp();
		current_proc->pa9=crowd3;
		crowd_ani_jsrp();
	}
	while(1);
}

void calla_arena(void) 
{
	CREATE(PID_BANI,sitting_kahn);
//	CREATE(PID_BANI,rayden_proc);
//	CREATE(PID_BANI,baraka_proc);
	CREATE(PID_BANI,crowd_ani);
	return;
}
