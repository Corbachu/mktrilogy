/******************************************************************************
 File: bkgdcity.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III City Routines
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
#include "mkdma.h"
#include "vcache.h"

/* Prototypes */
long long city_buffer[55*1024/sizeof(long long)];


void calla_city(void);
void storm_proc(void);

/************************************************************
 * 			C I T Y/R O O F  S T U F F 						*
 ************************************************************/
/********************
 Externals
 ********************/

/********************
 ********************/
extern void *a_burn[];
extern BYTE city_dict[];

DTBL_INITA burn_table [] =
{
	{5,SCX(0x0043)+32,SCY(0x0096)+29,a_burn,&baklst4},
	{0}
};

/******************************************************************************
 Function: void calla_city(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the citys background
******************************************************************************/
extern ADDRESS preload_burn[];
void calla_city(void)
{
	BYTE *dmem;

	dmem=vmem_predecomp_perm(preload_burn,city_dict,(BYTE *)&city_buffer[0],55*1024);

	/* display */
	CREATE(PID_BANI,storm_proc);
	create_dumb_animators(burn_table,city_dict,0);
 
	return;
}


