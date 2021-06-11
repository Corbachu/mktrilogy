/******************************************************************************
 File: bkgdsoul.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Soul Routines
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

void calla_soul(void);
void soul_na_do(void);

/************************************************************
 * 			S O U L  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern BYTE soul_dict[];
/******************************************************************************
 Function: void calla_soul(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the souls background
******************************************************************************/
extern void *SONADO_P[];
extern void *a_soul_na_do[];
extern void *SONADO1[];

void calla_soul(void)
{
	OBJECT *obj;
	PROCESS *ptemp;

	/* set soul tornado */
	gso_dmawnz(obj,(ADDRESS)SONADO1,soul_dict,0,0);
	set_xy_coordinates(obj,0x24b,0x4e);
	alloc_cache(SONADO1,0,obj);
	insert_object(obj,&baklst3);

	ptemp=CREATE(PID_BANI,soul_na_do);
	ptemp->pa8=obj;

	return;
}

/******************************************************************************
 Function: void soul_na_do(void)

 By: David Schwartz

 Date:  Jan 1995

 Parameters: None

 Returns: None

 Description:	animate the tornado
******************************************************************************/
void soul_na_do(void)
{
	while (TRUE)
	{
		current_proc->pa9=a_soul_na_do;
		framew(4);
	}
}

/* Prototypes */
void calla_tower(void);

/************************************************************
 * 			B A L C O N Y & T O W E R  S T U F F 			*
 ************************************************************/

/*****************
 Externals
*****************/
extern void *a_torch[];
/*****************
*****************/

DTBL_INITA tower_table [] =
{
	{5,0xc9,0x51,a_torch,&baklst8},
	{5,0x299,0x53,a_torch,&baklst8},
	{0}
};
/******************************************************************************
 Function: void calla_tower(void)

 By: David Schwartz

 Date:  Jan 1995

 Parameters: None

 Returns: None

 Description:	init balcony/tower stuff
******************************************************************************/
void calla_tower(void)
{
	create_dumb_animators(tower_table,soul_dict,0);

	return;
}


