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
static int dummy;

void make_water_proc(void);
void water_proc(void);
void water_ani(OIMGTBL *frame,OBJECT *obj);

/************************************************************
 * 			WATER S T U F F 							*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_water1[];
extern BYTE water_dict[];

/******************************************************************************
 Function: void make_water_proc(void)

 By: David Schwartz

 Date: Nov 1995

 Parameters: None

 Returns: None

 Description:	setup the water background
******************************************************************************/
void make_water_proc(void)
{
	CREATE(PID_BANI,water_proc);
}

void water_proc(void)
{
	OBJECT *ta8;
	OBJECT *ta9;
	ADDRESS *ta11;

	do
	{
		ta11=(ADDRESS *)a_water1;

		/* water2 */
		do
		{
			ta8=(OBJECT *)&baklst3;
			ta9=(OBJECT *)&baklst4;

			/* water3 */
			do
			{
				ta8=ta8->olink;
				if (ta8==NULL)
					break;

				ta8->oheap=NULL;
				ta8->odict=water_dict;

				if (ta8->ozval==2)
					water_ani((OIMGTBL *)*(ta11+1),ta8);
				else
				{
					if (ta8->ozval==1)
						water_ani((OIMGTBL *)*(ta11+0),ta8);
				}
			}
			while(1);

			/* water6 */
			do
			{
				ta9=ta9->olink;
				if (ta9==NULL)
					break;

				ta9->oheap=NULL;
				ta9->odict=water_dict;

				if (ta9->ozval==0)
					water_ani((OIMGTBL *)*(ta11+3),ta9);
				else
				{
					if (ta9->ozval==1)
						water_ani((OIMGTBL *)*(ta11+2),ta9);
				}
			}
			while(1);

			/* water8 */
			process_sleep(8);
			ta11+=4;
			if (*ta11==NULL)
				break;
		}
		while(1);
	}
	while(1);
}

void water_ani(OIMGTBL *frame,OBJECT *obj) 
{
	short x,y;

	x=obj->oxpos.u.intpos;
	y=obj->oypos.u.intpos;
	current_proc->pa8=obj;
	animate(SINGLE_ANI,frame,obj->oflags);
	obj->oxpos.u.intpos=x;
	obj->oypos.u.intpos=y;
	return;
}
