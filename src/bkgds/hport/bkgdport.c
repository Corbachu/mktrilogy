/******************************************************************************
 File: bkgdpotr.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Portal Routines
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
long long hport_buffer[100*1024/sizeof(long long)];

/************************************************************
 * 			P O R T A L  S T U F F 					*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_portal_zap[];
extern void *PORTAL01[];
extern BYTE hport_dict[];

/********************
 ********************/
void portal_zap(void);
void mk3_calla(void);

/******************************************************************************
 Function: void mk3_calla(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup the citys background
******************************************************************************/
void mk3_calla(void)
{
	BYTE *dmem;

	dmem=vmem_predecomp_perm((ADDRESS*)a_portal_zap,hport_dict,(BYTE *)&hport_buffer[0],100*1024);
	
	CREATE(PID_BANI,portal_zap);
	return;
}

void portal_zap(void)
{
	OBJECT *obj;

	gso_dmawnz(obj,(ADDRESS)PORTAL01,hport_dict,0,0);
	set_xy_coordinates(obj,SCX(0xb0)+0x6,SCY(0x5c)-4);
	alloc_cache(PORTAL01,0,obj);
	insert_object(obj,&baklst1);

	/* pzap3 */
	do
	{
		tsound(0xb9+randu(2)-1);
		current_proc->pa9=a_portal_zap;
		framew(3);
		(long)current_proc->a11=obj->oypos.pos;
		obj->oypos.u.intpos=SCY(0x4000);
		process_sleep(0x30);
		obj->oypos.pos=(long)current_proc->a11;
	}
	while(1);
}
