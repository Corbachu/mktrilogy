/******************************************************************************
 File: bkgdbattle.c

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
static int dummy;
/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern WORD WATER[];

void battle_cycle(void) 
{
	process_sleep(24);
	current_proc->a11=0x21080800;
	cycle_forward(WATER);
	wait_forever();
}

void calla_battle(void) 
{
	CREATE(PID_CYCLE,battle_cycle);
	return;
}




