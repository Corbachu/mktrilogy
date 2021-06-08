/******************************************************************************
 File: bkgdgrav.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Grave Yard Routines
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
long long grave_buffer[24*1024/sizeof(long long)];

void grave_calla(void);
void moon_proc(void);

/************************************************************
 * 			G R A V E  S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern BYTE grave_dict[];
extern void *BOON[];
extern void *BERAN[];
extern void *TOBIAS[];
extern void *MICHIC[];
extern void *GOSKIE[];
extern void *VOGEL[];
extern void *MAY[];
extern void *MILLER[];
extern void *SCHWARTZ[];
extern void *GUIDO[];

void *tomb_stones1[]=
{
	BOON,
	BERAN,
	TOBIAS,
	GOSKIE
};

void *tomb_stones2[]=
{
	GOSKIE,
	BOON,
	VOGEL,
	MICHIC
};

void *tomb_stones3[]=
{
	BERAN,
	MILLER,
	TOBIAS,
	MICHIC
};

void *tomb_stones4[]=
{
	GUIDO,
	MAY,
	SCHWARTZ,
	MILLER
};

void *tomb_stones5[]=
{
	GUIDO,
	BOON,
	SCHWARTZ,
	TOBIAS
};

void *tomb_stones6[]=
{
	MILLER,
	MAY,
	VOGEL,
	BERAN
};

ADDRESS *tomb_table[]=
{
	(ADDRESS *)tomb_stones1,(ADDRESS *)tomb_stones2,(ADDRESS *)tomb_stones3,(ADDRESS *)tomb_stones4,(ADDRESS *)tomb_stones5,(ADDRESS *)tomb_stones6
};

short tomb_spots[]=
{
	-SCX(0x100),
	SCX(0x00),
	SCX(0x100),
	SCX(0x200),
	SCX(0x300)
};

/******************************************************************************
 Function: void grave_calla(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	setup the graveyard background
******************************************************************************/
extern void *a_moon[];
extern void *MOONA28[];
extern ADDRESS preload_grave[];

void grave_calla(void)
{
	OBJECT *obj;
	PROCESS *ptemp;
	ADDRESS *tombtbl;
	BYTE *dmem;

	dmem=vmem_predecomp_perm(preload_grave,grave_dict,(BYTE *)&grave_buffer[0],24*1024);

	/* set moon process */
	gso_dmawnz_ns(obj,(ADDRESS)MOONA28,grave_dict,0,0);
	set_xy_coordinates(obj,0x60,0x20-6);
	alloc_cache(MOONA28,0,obj);

	ptemp=CREATE(PID_BANI,moon_proc);
	ptemp->pa8=obj;
	insert_object(obj,&baklst8);

	tombtbl=tomb_table[randu(6)-1]; 	// add our names

	current_proc->a11=4;
	/* tomb3 */
	do
	{
		gso_dmawnz(obj,(ADDRESS)(tombtbl[current_proc->a11-1]),grave_dict,0,0);
		obj->oxpos.u.intpos=worldtlx1.u.intpos+tomb_spots[current_proc->a11-1];
		obj->oypos.u.intpos=ground_y-SCY(0x58)-1;
		alloc_cache(tombtbl[current_proc->a11-1],0,obj);
		obj->oid=OID_CD;		// hack to remove objects

		insert_object(obj,&baklst9);
	}
	while(--current_proc->a11>0);

	return;
}

/******************************************************************************
 Function: void moon_proc(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	moon procedure
******************************************************************************/
void moon_proc(void)
{
	while (1)
	{
		process_sleep((WORD)randu_minimum(0x40,0x40));

		current_proc->pa9=a_moon;
		framew(8);
	}
}

