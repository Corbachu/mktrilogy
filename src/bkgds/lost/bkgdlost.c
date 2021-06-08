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
long long lost_buffer[90*1024/sizeof(long long)];

/************************************************************
 * 			G R A V E  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *lost_anims[];
extern void *a_darkman1[];
extern void *a_darkman2[];
extern BYTE lost_dict[];

DTBL_INITA little_man_table [] =
{
	{6,SCX(0x100),(0x0080)+10,a_darkman1,&baklst2},
	{0x0006,SCX(0x110)+12,(0x0080)+4,a_darkman2,&baklst2},
	{0}
};

/******************************************************************************
 Function: void calla_lost(void)

 By: David Schwartz

 Date: Nov 1995

 Parameters: None

 Returns: None

 Description:	setup the desert background
******************************************************************************/
void calla_lost(void)
{
	BYTE *dmem;
	

	if (randper(222)==SYSTEM_CARRY_SET)
	{
		dmem=vmem_predecomp_perm((ADDRESS *)a_darkman1,lost_dict,(BYTE*)&lost_buffer[0],90*1024);
		dmem=vmem_predecomp_perm((ADDRESS *)a_darkman2,lost_dict,dmem,90*1024-(dmem-(BYTE *)&lost_buffer[0]));
		
		create_dumb_animators(little_man_table,lost_dict,0);
	}
	
   	return;
}

