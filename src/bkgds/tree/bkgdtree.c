/******************************************************************************
 File: bkgdtree.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III living forest Routines
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
long long tree_buffer[65*1024/sizeof(long long)];

/************************************************************
 * 			D E A D  S T U F F 								*
 ************************************************************/

/********************
 Externals
 ********************/
extern void *a_treeroar[];
extern void *TREEANI1[];
extern BYTE tree_dict[];

void triple_framew(WORD pa0) 
{
	OBJECT *obj=current_proc->pa8;

	do
	{
		if (frame_a9(current_proc->pa8)==SYSTEM_CARRY_SET)
			break;
		((ADDRESS*)current_proc->pa9)--;
		current_proc->pa8=(OBJECT*)current_proc->a11;
		frame_a9(current_proc->pa8);
		((ADDRESS*)current_proc->pa9)--;
		current_proc->pa8=(OBJECT*)current_proc->a10;
		frame_a9(current_proc->pa8);
		current_proc->pa8=obj;
		process_sleep(pa0);
	}
	while(1);

	return;
}

OBJECT *make_a_mad_tree(short pax,short pay) 
{
	OBJECT *obj;

	gso_dmawnz(obj,(ADDRESS)TREEANI1,tree_dict,0,0);
	set_xy_coordinates(obj,pax,pay);
	alloc_cache(TREEANI1,0,obj);
	insert_object(obj,&baklst1);

	return(obj);
}

void tree_animator(void) 
{
	(OBJECT *)current_proc->a11=make_a_mad_tree(295,85);
	(OBJECT *)current_proc->a10=make_a_mad_tree(0x214,85);
	make_a_mad_tree(0x2fb,85);

	do
	{
		process_sleep(0x80+randu(0xc0));
		tsound(0xb5);			
		current_proc->pa9=a_treeroar;
		triple_framew(5);
	}
	while(1);
}

void calla_forest(void) 
{
	BYTE *dmem;

	dmem=vmem_predecomp_perm((ADDRESS*)a_treeroar,tree_dict,(BYTE *)&tree_buffer[0],65*1024);
	
	CREATE(PID_BANI,tree_animator);
	return;
}
