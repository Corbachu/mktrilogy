/******************************************************************************
 File: bkgdbrig.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Bridge Routines
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
long long bridge_buffer[75*1024/sizeof(long long)];

void bridge_calla(void);
void start_garbage(void);	

/************************************************************
 * 			B R I D G E S T U F F 							*
 ************************************************************/
/********************
 Externals
 ********************/
/******************************************************************************
 Function: void bridge_calla(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	setup the bridge background
******************************************************************************/
extern ADDRESS preload_trash[];
extern BYTE trash_dict[];

void bridge_calla(void)
{
	BYTE *dmem;

	dmem=vmem_predecomp_perm(preload_trash,trash_dict,(BYTE *)&bridge_buffer[0],75*1024);

	CREATE(PID_BANI,wind_sound);

	start_garbage();	

	return;
}
