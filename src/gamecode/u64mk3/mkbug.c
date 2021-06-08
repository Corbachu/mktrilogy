/******************************************************************************
 File: mkvs.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III vs Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkinit.h"
#include "mkutil.h"
#include "mkani.h"
#include "mktext.h"
#include "mkjoy.h"

/******************************************************************************
 Function: void debug_grid(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	display debug grid on screen
******************************************************************************/
void debug_grid(void) 
{
#if DEBUG_GRID
	int test;

	/* green horiz lines */
	for (test=0;test<11;test++)
	{
		SetLineF2(&cdb->lines[test]);
		setRGB0(&cdb->lines[test],0,128,0);
		setXY2(&cdb->lines[test],0,test*43/2+16,320,test*43/2+16);
		cdb->primcnt++;
		AddPrim(cdb->ot_ptr,&cdb->lines[test]); 
	}

	/* blue vert lines */
	for (test=11;test<21;test++)
	{
		SetLineF2(&cdb->lines[test]);
		setRGB0(&cdb->lines[test],0,0,128);
		setXY2(&cdb->lines[test],(test-11)*32,0,(test-11)*32,240);
		cdb->primcnt++;
		AddPrim(cdb->ot_ptr,&cdb->lines[test]); 
	}
#endif /* DEBUG_GRID */

	return;
}

/******************************************************************************
 Function: void profiler(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	display profile of program
******************************************************************************/
void profiler(void) 
{
#if PROFILE
		if (f_profile==1) 
		{
			setRGB0(cdb->box_ptr,0,128,0);			// base line (1 vblank)
			setXYWH(cdb->box_ptr,12,32,12+240/2,6);
			AddPrim(cdb->ot_ptr,cdb->box_ptr); 
			cdb->box_ptr++;

			setRGB0(cdb->box_ptr,128,128,0);			// base line (2 vblank)
			setXYWH(cdb->box_ptr,12+240/2,32,12+240/2,6);
			AddPrim(cdb->ot_ptr,cdb->box_ptr); 
			cdb->box_ptr++;

			setRGB0(cdb->box_ptr,0,0,128);			// current line CPU
			setXYWH(cdb->box_ptr,12,24,12+(prof_end-prof_start)/2,8);
			AddPrim(cdb->ot_ptr,cdb->box_ptr); 
			cdb->box_ptr++;

			setRGB0(cdb->box_ptr,80,45,14);			// current line drawing
			setXYWH(cdb->box_ptr,12+(prof_end-prof_start)/2,24,12+(prof_draw_end-prof_draw_start)/2,8);
			AddPrim(cdb->ot_ptr,cdb->box_ptr); 
			cdb->box_ptr++;


			if ((prof_draw_end-prof_start)>prof_max)
				prof_max=prof_draw_end-prof_start;

			setRGB0(cdb->box_ptr,128,0,0);			// max line
			setXYWH(cdb->box_ptr,12,38,12+prof_max/2,8);
			AddPrim(cdb->ot_ptr,cdb->box_ptr); 
			cdb->box_ptr++;

		}
#endif
	return;
}

/******************************************************************************
 Function: void draw_collision_box(XYTYPE *tl,XYTYPE *lr,WORD index)

 By: David Schwartz

 Date: Dec 1994

 Parameters: tl - top left of box
			 lr - lower right of box
			 index - 0=attacker 1=victim

 Returns: None

 Description:	draw a collision box
******************************************************************************/
void draw_collision_box(XYTYPE *tl,XYTYPE *lr,WORD index) 
{
#if COLLISION_BOX
	OBJECT *obj;

	if (f_colbox && gstate==GS_FIGHTING) 
	{
		if (index==0)
			kilobj2(OID_CBOX,0xffff);

		obj=get_object();
		obj->oid=OID_CBOX;
		obj->oypos.u.intpos=tl->u.ypos;
		obj->osize.u.ypos=abs(tl->u.ypos-lr->u.ypos);

		obj->oxpos.u.intpos=tl->u.xpos;
		obj->osize.u.xpos=abs(tl->u.xpos-lr->u.xpos);

		obj->oflags|=M_BOX_POLY|M_XLU_ON;		// turn on xluency
		obj->oflags|=0x8000;					// 1/2 xluency

		obj->oconst=(index==0) ? 0x003c:0xf800;

		insert_object(obj,&objlst2);				// put on list #2, in front of fighters
	}
#endif
	return;	
}


#if SYS_DEBUG
void slam_debug_init(void) 
{
	OBJECT *pa8=current_proc->pa8;
	OBJECT *obj;
	
	MURDER;
	stop_scrolling();
	scrolly.pos=0;
	
	gstate=GS_DEBUG;
	
	return;
}

void print_slam_data(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *other=current_proc->pdata.p_otherguy;
	short delta;
	
	kilobj2(OID_TEXT,0xffff);
	
	delta=obj->oxpos.u.intpos-other->oxpos.u.intpos;
	if (delta>=0)
		printf(("DELTA X = %d\n",(delta*100)/80));
	else printf(("DELTA X = -%d\n",-(delta*100)/80));

	delta=obj->oypos.u.intpos-other->oypos.u.intpos;
	if (delta>=0)
		printf(("DELTA Y = -%d\n",(delta*100)/85));
	else printf(("DELTA Y = %d\n",-(delta*100)/85));
	
	printf(("\n"));
	return;
}

void gover_amode_entry(void);
void throw_debug(WORD pa0) 
{
	OBJECT *obj,*other;
	long ta1,ta2;
	
	obj=current_proc->pa8;
	other=current_proc->pdata.p_otherguy;
	
	slam_debug_init();
	
	if (pa0==1) 
	{
		/* grab */
		mframew(10);
	}
	
	/* bs0 */
	process_sleep(8);
	
	do_next_a9_frame(obj);
	advance_him();
	
	/* bs_loop */
	do
	{
		process_sleep(1);
		
		ta1=ta2=0;
		
		if (swcurr.u.p1pad & MASK_JUP)
			ta2--;
		if (swcurr.u.p1pad & MASK_JDOWN)
			ta2++;
		if (swcurr.u.p1pad & MASK_JLEFT)
			ta1--;
		if (swcurr.u.p1pad & MASK_JRIGHT)
			ta1++;

		if (swcurr.u.p1pad & MASK_JHIP) 
		{
			advance_him();
			process_sleep(0x20);
		}

		if (swcurr.u.p1pad & MASK_JBLOCK) 
		{
			do_next_a9_frame(obj);
			process_sleep(0x20);
		}
		
		if (swcurr.u.p1pad & MASK_START) 
		{
			print_slam_data();
			process_sleep(0x20);
		}

		if (swcurr.u.p2pad & MASK_START) 
		{
			/* ABORT GAME & RESET TO TITLE PAGE */
			printf(("ABORT\n"));
			gstate=GS_GAMEOVER;

			reset_map_variables();
			diff=0;

			p1_state=p2_state=0;				// take players out of game

			clr_scrn();
			murder_myoinit_score();
			stack_jump(gover_amode_entry);
		}
		
		other->oxpos.u.intpos+=ta1;
		other->oypos.u.intpos+=ta2;
	}
	while(1);
}


#endif

