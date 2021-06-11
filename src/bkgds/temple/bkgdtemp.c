/******************************************************************************
 File: bkgdtemp.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Temple Routines
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


/* local prototypes */
static LONG	dummy;			// used to create a bss section

void temple_calla(void);
void candle_flame(void);

/************************************************************
 * 			T E M P L E  S T U F F 							*
 ************************************************************/
/*****************
 Externals
*****************/
extern void *a_tflame[];
extern void *a_candle_flame[];
extern void *wik1[];
extern void *KANDLE1[];
extern BYTE temple_dict[];
extern ADDRESS temple_preload[];
extern BYTE explode_dict[];
extern BYTE blood_dict[];
extern BYTE control_dict[];
extern ADDRESS a_puff[];
extern ADDRESS a_face_blood[];
extern ADDRESS a_decap_spray[];
extern ADDRESS a_rotate_12[];
extern ADDRESS control_panel_info1[];
/*****************
*****************/

DTBL_INITA tony_candle_table[] =
{
	{4,0xd5+2+21,0x2c-1,a_tflame,&baklst7},
	{4,0x14d+2+22,0x2c-1,a_tflame,&baklst7},
	{4|0x8000,0x26d+12,0x2c-1,a_tflame,&baklst7},
	{4|0x8000,0x2e4+13,0x2c-1,a_tflame,&baklst7},
	{0}
};

long long temple_buffer[74*1024/sizeof(long long)];

/******************************************************************************
 Function: void temple_calla(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	setup the bridge background
******************************************************************************/
void temple_calla(void)
{
	OBJECT *obj;
	BYTE *dmem;
	
	dmem=vmem_predecomp_perm(temple_preload,temple_dict,(BYTE *)&temple_buffer[0],74*1024);
	
	current_proc->a10=10;
	(long)current_proc->a11=-1;

	do
	{
		/* candd */
		gso_dmawnz(obj,(ADDRESS)KANDLE1,temple_dict,0,0);
		obj->oxpos.u.intpos=(short)current_proc->a11+8+2;
		obj->oypos.u.intpos=0xb2+6;	//+36;
		alloc_cache(KANDLE1,0,obj);
		insert_object(obj,&baklst6);


		/* flame */
		(OBJECT *)current_proc->pa9=obj;
		gso_dmawnz(obj,(ADDRESS)wik1,temple_dict,0,0);
		alloc_cache(wik1,0,current_proc->pa8);
		insert_object(current_proc->pa8,&baklst6);

		obj->oxpos.u.intpos=((OBJECT *)current_proc->pa9)->oxpos.u.intpos+SCX(7);
		obj->oypos.u.intpos=((OBJECT *)current_proc->pa9)->oypos.u.intpos-SCY(12);

		CREATE(PID_BANI,candle_flame);
		(long)current_proc->a11+=SCX(0x96);
	}
	while(--current_proc->a10>0);

	create_dumb_animators(tony_candle_table,temple_dict,0);

	return;
}

/******************************************************************************
 Function: void candle_flame(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	animate the candles on the temple bkgd
******************************************************************************/
void candle_flame(void)
{
	process_sleep(randu(10));

	current_proc->pa9=a_candle_flame;
	framew(3+randu(2));

	wait_forever();
}
