/******************************************************************************
 File: bkgddead.c

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
long long monks_buffer[95*1024/sizeof(long long)];

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_warplite[];
extern void *timefloor1[];
extern void *warplite1[];


//extern void *a_bg_monk[];
//extern void *bgmonktorso[];
extern void *timemonk1[];
extern void *a_timemonk[];
extern BYTE monks_dict[];
extern BYTE monk_dict[];

void warplite_animator(void) 
{
	OBJECT *obj;
	
	gso_dmawnz(obj,(ADDRESS)warplite1,monks_dict,0,0);
	set_xy_coordinates(obj,worldtlx7.u.intpos+SCX(0xc2),SCY(0x82));
	alloc_cache(warplite1,0,obj);
	insert_object(obj,&baklst7);

	/* wla1 */
	while (1)
	{
		(long)current_proc->pdata.p_store1=obj->oxpos.pos;
		(long)current_proc->pdata.p_store2=obj->oypos.pos;
		obj->oxpos.u.intpos=0xfff;
		obj->oypos.u.intpos=0xfff;			// move offscreen
		process_sleep(0x70);

		tsound(0xb9+randu(2)-1);

		obj->oxpos.pos=(long)current_proc->pdata.p_store1;
		obj->oypos.pos=(long)current_proc->pdata.p_store2;

		current_proc->a11=2;
		do
		{
			current_proc->pa9=a_warplite;
			framew(3);
		}
		while(--current_proc->a11>0);
	}
}

void put_float(void *pa0,short pax,short pay,WORD pa3) 
{
	OBJECT *obj;
	
	gso_dmawnz(obj,(ADDRESS)pa0,monks_dict,0,0);
	set_xy_coordinates(obj,pax+worldtlx5.u.intpos,pay);
	alloc_cache((OIMGTBL *)pa0,0,obj);
	obj->ozval=pa3;
	insert_object(obj,&baklst4);

	return;
}

void lil_monk_animator(void) 
{
	while (1)
	{
		current_proc->pa9=a_timemonk;
		framew(6);
	}
}

void monk_proc(void);
extern ADDRESS preload_monk[];
void calla_monk(void) 
{
	PROCESS *ptemp;
	BYTE *dmem;

	dmem=vmem_predecomp_perm((ADDRESS*)a_warplite,monks_dict,(BYTE *)&monks_buffer[0],95*1024);
	dmem=vmem_predecomp_perm((ADDRESS*)a_timemonk,monks_dict,dmem,95*1024-(dmem-(BYTE *)&monks_buffer[0]));
	dmem=vmem_predecomp_perm(preload_monk,monk_dict,dmem,95*1024-(dmem-(BYTE *)&monks_buffer[0]));

	ptemp=CREATE(PID_BANI,monk_proc);
	ptemp->pdata.p_store1=0x0058018c;
	ptemp->pdata.p_store2=0x005b018a;
	ptemp->pdata.p_store3=(ADDRESS)&baklst4;

	ptemp=CREATE(PID_BANI,monk_proc);
	ptemp->pdata.p_store1=0x00580212;
	ptemp->pdata.p_store2=0x005b0210;
	ptemp->pdata.p_store3=(ADDRESS)&baklst4;

	put_float(timefloor1,SCX(0xa0),SCY(0x98),1);

	put_float(timemonk1,SCX(0xa0),SCY(0x83),2);
	CREATE(PID_BANI,lil_monk_animator);
	put_float(timemonk1,SCX(0xe0),SCY(0x83),2);
	CREATE(PID_BANI,lil_monk_animator);

	CREATE(PID_BANI,warplite_animator);

	return;
}

