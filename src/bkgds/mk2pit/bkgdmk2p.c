/******************************************************************************
 File: bkgdesrt.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Desert Routines
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

/************************************************************
 * 			G R A V E  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_mk2darkman1[];
extern void *a_mk2darkman2[];
extern BYTE mk2pit_dict[];
DTBL_INITA mklittle_man_table [] =
{
	{6,SCX(0x100)+240,(0x0080)+10-6,a_mk2darkman1,&baklst4},
	{0x0006,SCX(0x110)+12+240,(0x0080)+4-6,a_mk2darkman2,&baklst4},
	{0}
};

long long mk2pit_buffer[100*1024/sizeof(long long)];

/******************************************************************************
 Function: void calla_lost(void)

 By: David Schwartz

 Date: Nov 1995

 Parameters: None

 Returns: None

 Description:	setup the desert background
******************************************************************************/
void calla_mk2pit(void)
{
	BYTE *dmem;
	
	dmem=vmem_predecomp_perm((ADDRESS *)a_mk2darkman1,mk2pit_dict,(BYTE*)&mk2pit_buffer[0],100*1024);
	dmem=vmem_predecomp_perm((ADDRESS *)a_mk2darkman2,mk2pit_dict,dmem,100*1024-(dmem-(BYTE *)&mk2pit_buffer[0]));

	create_dumb_animators(mklittle_man_table,mk2pit_dict,0);
	
   	return;
}

void calla_mk2star(void) 
{
	int i;
	OBJECT *obj;
	
#if 0
	for (i=0;i<15;i++)
	{
		obj=make_solid_object(0xffff,2,2);	
//		set_noscroll(obj);
		obj->ozval=0;
		obj->oxpos.u.intpos=randu(320)-1+worldtlx7.u.intpos-160;
		obj->oypos.u.intpos=worldtly.u.intpos+randu(160)+20;
		insert_object(obj,&baklst7);
	}

	for (i=0;i<15;i++)
	{
		obj=make_solid_object(0x7bef,2,2);	
//		set_noscroll(obj);
		obj->ozval=0;
		obj->oxpos.u.intpos=randu(320)-1+worldtlx8.u.intpos-160;
		obj->oypos.u.intpos=worldtly.u.intpos+randu(160)+20;
		insert_object(obj,&baklst8);
	}
#endif	
	return;	
}

