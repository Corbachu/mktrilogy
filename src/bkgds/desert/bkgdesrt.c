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
long long desert_buffer[75*1024/sizeof(long long)];

void make_cyrax_sand(void);

/************************************************************
 * 			G R A V E  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *CYRXSAND1[];
extern void *a_cyrax[];
extern BYTE desert_dict[];

DTBL_INIT cyrax_table [] =
{
	{7,CYRXSAND1,-SCX(0xb0)+24,SCY(0x008a)+24,a_cyrax,&baklst5},
	{0}
};

/******************************************************************************
 Function: void make_cyrax_sand(void)

 By: David Schwartz

 Date: Nov 1995

 Parameters: None

 Returns: None

 Description:	setup the desert background
******************************************************************************/
void make_cyrax_sand(void)
{
	BYTE *dmem;

	dmem=vmem_predecomp_perm((ADDRESS *)a_cyrax,desert_dict,(BYTE *)&desert_buffer[0],75*1024);

	create_dumb_animators_w(cyrax_table,desert_dict,0);

	return;
}

