/******************************************************************************
 File: mkcanned.c

 Date: Nov 1994

 (C) Williams Entertainment

 Mortal Kombat III canned Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkguys.h"
#include "mkutil.h"
#include "mkmain.h"
#include "mkani.h"
#include "mkcanned.h"
#include "mkreact.h"
#include "mkjoy.h"
#include "mkdrone.h"
#include "mkinit.h"
#include "mkfx.h"
#include "mkpal.h"
#include "mksound.h"
#include "mkdma.h"
#include "mksel.h"
#include "moves.h"
#include "mkscore.h"

//******************************************************************************
//******************************************************************************
WORD tot_replace=0;
void tot_replacement_proc(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *other;
	PROCESS *ploser;
	PROCESS *pother;
	OBJECT *oloser;

	/* no fighter data loaded yet */
	f_fighter_load=0;			
	
	/* save loser info */
	ploser=(PROCESS *)current_proc->pdata.p_store1=(PROCESS*)current_proc->a10;		// loser proc
	oloser=(OBJECT*)current_proc->a11;		// loser obj
	
	/* delete ghost if there is one */
	pother=process_exist((oloser==p1_obj)?PID_NOOB_ZAP_FLASH1:PID_NOOB_ZAP_FLASH2,-1);
	if (pother!=NULL) 
	{
		pother->pdata.p_store8=1;
	}
	
	/* cancel any agressors stuff */
	cancel_agressor(oloser);
	
	/* set correct palette */
	if ((other=current_proc->pdata.p_otherguy)!=NULL) 
	{
		if (other->ochar!=obj->ochar)
			player_normpal();
		else
		{
			if (other->oflags2 & M_UGLY_PAL)
				player_normpal();
			else player_ugly_pal();
		}
	}

	set_nocol(oloser);		// might need to move to earlier
	
	/* wait until it is safe to load new art */
	current_proc->pa8=oloser;
	do
	{
		if (q_switch_ok()==SYSTEM_CARRY_SET)
			break;
		process_sleep(1);	
	}
	while(1);
	current_proc->pa8=obj;
	
	/* announce the new guy */
	character_texture_load(obj->ochar,CHAR_NORMAL,obj->odict,SYNC_LOAD);
	insert_object(obj,&objlst);				// finalyy add guy to display list now that we have valid data
	dealloc_vram_mem(obj->ovcache);			// invalidate any object this guy might be using
	f_fighter_load=1;			
	
	tsound2(0x00+obj->ochar);
	tsound2(0x00+obj->ochar);
//	tsound2(0x00+obj->ochar);
	
	/* make appear on correct side away from other dude */
	if (other->oxpos.u.intpos-worldtlx.u.intpos<SCRRGT/2) 
	{
		obj->oxpos.u.intpos=worldtlx.u.intpos+SCRRGT;
		obj->oxvel.pos=-SCX(0x28000);
	}
	else
	{
		obj->oxpos.u.intpos=worldtlx.u.intpos;
		obj->oxvel.pos=SCX(0x28000);
	}
		
	/* make new guys appear on screen */
	current_proc->pdata.p_ganiy=obj->oypos.u.intpos;
	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	do_next_a9_frame(obj);
	current_proc->a6=0;
	gravity_ani(3,-SCY(0xa0000),ANGLE_GRAV);

	/* wait to jump into the limelight */
	current_proc->a10=0x40*3;
	stance_setup();
	do
	{
		process_sleep(1);
		next_anirate();
		
		if (--current_proc->a10==0)
			break;
		
		/* wait until loser hits the ground or time expires */
		if (ploser->pdata.p_ganiy!=oloser->oypos.u.intpos)
			continue;
		if (oloser->oyvel.pos==0)	
			break;
	}
	while(1);
	
	/* setup loser structures with new data */
	if (obj->oid==OID_P1) 
	{
		p1_xvel.pos=0;
		p1_obj->oxvel.pos=0;			// stop old guy
		
		oloser=p1_obj;
		ploser=p1_proc;
		
		p1_obj=obj;						// setup the family jewels, 
		p1_proc=current_proc;

		p1_char=p1_heap_char=p1_name_char=obj->ochar;
		
		if (df_nopower==1)
			p1_bar=p1_bar_view=1;
		else p1_bar=p1_bar_view=FULL_STRENGTH;
	}
	else
	{
		p2_xvel.pos=0;
		p2_obj->oxvel.pos=0;			// stop old guy
		
		oloser=p2_obj;
		ploser=p2_proc;
		
		p2_obj=obj;						// setup the family jewels, 
		p2_proc=current_proc;

		p2_char=p2_heap_char=p2_name_char=obj->ochar;
		
		if (df_nopower==1)
			p2_bar=p2_bar_view=1;
		else p2_bar=p2_bar_view=FULL_STRENGTH;
		
	}

	ochar_begin_calls();
	
	/* finish up bookkeeping */
	current_proc->procid=ploser->procid;
	pother=current_proc->pdata.p_otherproc;
	pother->pdata.p_otherproc=current_proc;
	pother->pdata.p_otherguy=obj;
	
	refresh_score();

	reaction_exit(obj);
}

/******************************************************************************
 Function: void finish_him(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	finish him move time (winner status=3)
******************************************************************************/
void finish_him(void)
{
	if (current_proc->pdata.p_flags & PM_FINISH)
		return;

	if (current_proc->procid==PID_P1)
	{
		current_proc->a0=p1_matchw;
		current_proc->a1=p2_matchw;
	}
	else
	{
		current_proc->a0=p2_matchw;
		current_proc->a1=p1_matchw;
	}

	if (((WORD)current_proc->a0) < ((WORD)current_proc->a1))
	{
		dizzy_dude();					// more wins for me ?, no --> dizzy
	}
	else
	{
		current_proc->pdata.p_flags|=PM_FINISH;			// flag: i am finishing him

		/* fhim5 */
		if (am_i_joy()==SYSTEM_CARRY_CLR)
		{
			stack_jump(d_finish_him);
		}
		else
		{
			stack_jump_joy(joy_proc,JI_JOY_ENTRY);
		}
	}
}

/******************************************************************************
 Function: void dizzy_dude(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	guy who's got his shit kicked
******************************************************************************/
void dizzy_dude(void)
{
	OBJECT *obj=current_proc->pa8;

	disable_all_buttons;
	face_opponent(obj);
	zero_my_p_hit(current_proc);

	if (winner_status==3)
	{
		obj->oflags2 &=(~M_NOFLIP);			// i can be flipped
		current_proc->pdata.p_flags|=PM_SITDUCK;	// match over ---> i'm a sitting duk
		set_no_block(obj);							// i cant block
	}

	/* dd4 */
	if (am_i_short()==SYSTEM_CARRY_SET) 
	{
		raiden_getup_pal();
		animate_a9(0x0004,ANIM_GETUP);
		player_normpal();
	}

	/* dd5 */
	current_proc->pdata.p_action=ACT_STUNNED;		// define action

  init_anirate(6);

	get_char_ani(ANIM_TABLE1,ANIM_DIZZY);
	if (obj->ochar==FT_ROBO1 || obj->ochar==FT_ROBO2)
		robo_dizzy_call();

	/* dd7 */
	do
	{
		/* dizzy wake */
		current_proc->p_comp_flag=PC_DIZZY;			// signal other routine that at dizzy_wake
		process_sleep(1);
		current_proc->p_comp_flag=PC_CLEAR;

		/* dizzy */
		next_anirate();
	}
	while(winner_status==3 || f_death!=0);					// death blow started ??

	collapse_on_ground();
}

/******************************************************************************
 Function: void robo_dizzy_call(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	perform robo dizzy
******************************************************************************/
void robo_dizzy_call(void)
{
	PROCESS *ptemp;

	ptemp=create_fx(FX_ROBO_DIZZY);

	(PROCESS *)(ptemp->pdata.p_store1)=current_proc;

	return;
}

/******************************************************************************
 Function: void endurance_trans(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	winner status = 4, edurance transition
******************************************************************************/
void endurance_trans(void)
{
	if ((p1_obj==current_proc->pa8 && p1_bar==0) || (p2_obj==current_proc->pa8 && p2_bar==0))
		collapse_on_ground();
	else
	{
		stack_jump(endurance_wake);
	}
}

/******************************************************************************
 Function: void plwins(WORD pid)

 By: David Schwartz

 Date: Dec 1994

 Parameters: pid - proc id of winner

 Returns: None

 Description:	perform victory
******************************************************************************/
void plwins(WORD pid)
{
	if (current_proc->procid!=pid) 			// am i the winner
	{
		/* i lost */
		disable_all_buttons;
		collapse_on_ground();
	}
	else victory_animation();					// yes --> celebrate
}

/******************************************************************************
 Function: void psel_victory_animation(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	player select celebrate victory (victory_jumps)
******************************************************************************/
void psel_victory_animation(void)
{
	short zval;
	current_proc->pdata.p_flags&=(~PM_ALT_PAL);

	(ADDRESS)current_proc->pa9=(ADDRESS)(current_proc->pa8)->oslink;
	
	zval=(current_proc->pa8)->ozval;
//	init_special(current_proc->pa8);
//	(current_proc->pa8)->ozval=zval;
	
	stop_a8(current_proc->pa8);
	ground_player(current_proc->pa8);
	current_proc->pdata.p_flags|=PM_SPECIAL;
	
	
	(ADDRESS)(current_proc->pa8)->oslink=(ADDRESS)current_proc->pa9;
	f_victory_start=2;

	(current_proc->pa8)->ozval=zval;
	stack_jump(victory_animation);
}

void ending_victory_animation(void)
{
	stop_a8(current_proc->pa8);
	ground_player(current_proc->pa8);
	current_proc->pdata.p_flags|=PM_SPECIAL;
	f_victory_start=2;

	stack_jump(victory_animation);
}

/******************************************************************************
 Function: void victory_animation(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	celebrate victory (victory_jumps)
******************************************************************************/
void victory_animation(void)
{
	OBJECT *obj=current_proc->pa8;
	WORD ta1;


	ta1=obj->ochar;

	if ( (obj->ochar!=FT_LIA || f_final_act!=FAT_ANIMALITY) && f_victory_start!=2)
	{
		clear_inviso(obj);
		set_shadow_bit(obj);
		init_special(obj);
		if (am_i_shang()==SYSTEM_CARRY_SET) 
			obj->ochar=FT_ST;
	}

	f_victory_start=1;

	if (gstate==GS_PITFALLSPEC)
		wait_forever();

	switch (obj->ochar)
	{
		case FT_KAMEL:
			obj->ochar=randu(3)+FT_KITANA-1;
			if (obj->ochar==FT_JADE)
				animate_a9(5,ANIM_VICTORY);
			else
			{
				get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
				mframew(5);
			}	
			obj->ochar=FT_KAMEL;
			break;
		case FT_KANO:	// 0
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(4);
			break;

		case FT_SONYA:  // 1
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(5);
			process_sleep(12);
			mframew(4);
			break;

		case FT_JAX:	// 2
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(6);
			//mframew_2x(6,12);
			break;

		case FT_BARAKA:				//-u64-
			animate_a9(6,ANIM_VICTORY);
			mframew(6);
			break;

		case FT_INDIAN:	// 3
			animate_a9(0x0007,ANIM_VICTORY);
			process_sleep(8);
			ochar_sound(2);
			do_next_a9_frame(obj);
			process_sleep(9);
			mframew(6);
			break;

		case FT_SWAT:	// 5
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(6);				// animate

			current_proc->a11=3;
			do
			{
				process_sleep(6);
				find_ani_part2(ANIM_VICTORY);
				mframew(2);				// BANG!
			}
			while(--current_proc->a11>0);
			delete_slave();
			mframew(6);
			break;

		case FT_LIA:	// 6
			if (gstate==GS_PSEL)
			{
				/* lia_psel_victory */
				find_ani_part2(ANIM_VICTORY);
				mframew(4);				// aniamte
				break;
			}
			else
			{
				/* lia_victory */
				set_ignore_y(obj);
				get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
				if ( f_final_act!=FAT_ANIMALITY )
					stop_me(obj);
			}

			/* liav4 */
			mframew(4);				// aniamte

			if ( gstate==GS_GAMEOVER )
				break;						// dont float on gameover cast screen

			obj->ograv.pos=-SCY(0x4000);			// accel up
			process_sleep(0x0c);

			/* power down */
			/* LIAV6 */
			while(1)
			{
				obj->ograv.pos=(long)current_proc->a10=SCY(0x2000);			// head down

				/* LIAV3 */
				do
				{
					process_sleep(1);
				}
				while(obj->oyvel.pos<0);

				process_sleep(0x0d);

				/* power up */
				(long)current_proc->a10=-(long)current_proc->a10;
				obj->ograv.pos=(long)current_proc->a10;			// head down

				/* LIAV7 */
				do
				{
					process_sleep(1);
				}
				while(obj->oyvel.pos>0);

				process_sleep(0x0d);
			}
			break;

		case FT_RAYDEN:			//-u64-
			animate_a9(6,ANIM_VICTORY);
			
			if (gstate==GS_GAMEOVER || gstate==GS_PSEL || gstate==GS_POST_PSEL)
				break;
				
			CREATE(PID_LIGHTNING,victory_lighting);
			
			/* flash myself some */
			process_sleep(2);
			
			if (f_fade==0)
				CREATE(PID_FADE,rvic_fade);
				
			ochar_sound(0xe);
			
			current_proc->a11=6;
			do
			{
				player_froze_pal();
				process_sleep(4);
				player_normpal();
				process_sleep(4);
			}
			while(--current_proc->a11>0);
			
			break;

		case FT_MOTARO:
			ochar_sound(1);
			center_around_me();

		case FT_SK:
		case FT_TUSK:
		case FT_SG:
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(7);
			break;

		case FT_JADE:
			animate_a9(5,ANIM_VICTORY);
			break;

		case FT_ST:
			obj->ochar=ta1;
			if (obj->ochar!=FT_ST)
			{
				cancel_agressor(current_proc->pa8);
				back_to_shang_form(CHAR_SHANG);
			}

		default:		// 4 5 7 8 9 ...
			get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
			mframew(5);
			break;
	}

	wait_forever();
}


void rvic_fade(void) 
{
	dallprc(PID_CYCLE);		// stop color cyclers
	raiden_dimmer();
	process_sleep(0x2d);
	raiden_undimmer();
	process_suicide();
}

void victory_lighting(void) 
{
	PROCESS *ptemp=current_proc->pdata.p_otherproc;
	
	current_proc->a11=(ADDRESS)current_proc->pa8;
	
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_VICTORY);
	gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);
	(OBJECT *)current_proc->a10=current_proc->pa8;
	current_proc->pa8=(OBJECT*)current_proc->a11;
	match_ani_points(current_proc->pa8,(OBJECT*)current_proc->a10);
	insert_object((OBJECT *)current_proc->a10,&objlst);
	
	gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);
	(OBJECT *)current_proc->a14=current_proc->pa8;
 	current_proc->pa8=(OBJECT*)current_proc->a11;
	match_ani_points(current_proc->pa8,(OBJECT*)current_proc->a14);
	
	current_proc->pa8=(OBJECT*)current_proc->a14;
	flip_multi(current_proc->pa8);
	multi_adjust_xy(current_proc->pa8,-SCX(0x8),0);
	insert_object((OBJECT *)current_proc->a14,&objlst);
	
	ochar_sound(0);
	
	current_proc->a11=(ADDRESS)current_proc->pa9;
	
	current_proc->pdata.p_otherproc=current_proc;
	double_mframew(4);
	current_proc->pdata.p_otherproc=ptemp;
	
	delobjp(current_proc->pa8);
	delobjp((OBJECT*)current_proc->a10);
	
	process_suicide();
} 

/******************************************************************************
 Function: void mframew_2x(WORD anispeed,WORD pause)

 By: David Schwartz

 Date: Dec 1994

 Parameters: anispeed - animation speed
			 pause - pause between animations

 Returns: None

 Description:	animate through a list of multipart frames twice
******************************************************************************/
void mframew_2x(WORD anispeed,WORD pause)
{
	mframew(anispeed);

	process_sleep(pause);

	mframew(anispeed);

	return;
}

short ochar_dead_adjusts[][2]=
{
	{26-82,-93-(-93)},		 // 0, kano
	{36-101+4,-96-(-97)+4},		 //   1, sonya
	{39-101,-106-(-110)-4},		 //   2, jax
	{33-95,-96-(-98)},		 //   3, indian
	{33-100,-95-(-103)-8},		 //   4, subzero
	{31-101,-97-(-94)},		 //   5, swat
	{45-83,-98-(-101)-4},		 //   6, lia
	{40-87,-93-(-97)},		 //   7, robo1
	{40-87,-93-(-97)},		 //   8, robo2
	{36-101,-91-(-91)},		 //   9, lao
	{33-85,-96-(-98)},		 //   a, tusk
	{54-113,-101-(-107)-8},		 //   b, sg
	{55-83,-89-(-86)+4},		 //   c, st
	{38-101,-93-(-99)-8+4},		 //   d, lk
	{40-87,-93-(-97)},		 //   e, smoke

	{40-87,-93-(-97)},		 //   f, kit
	{40-87,-93-(-97)},		 //   10, jade
	{40-87,-93-(-97)},		 //   11, mil

	{40-87,-93-(-97)},		 //   12,  scro
	{40-87,-93-(-97)},		 //   13, rep
	{40-87,-93-(-97)},		 //   14, ermac
	{40-87,-93-(-97)},		 //   15, osz
	{40-87,-93-(-97)},		 //   16, osmk
	{40-87,-93-(-97)},		 //   17, noob
	{40-87,-93-(-97)},		 //   18, rayden	
	{40-87,-93-(-97)},		 //   19 baraka

	{40-87,-93-(-97)},		 //   1a, rain
	{40-87,-93-(-97)},		 //   1b, kamel
	{SCX(0),0},		 //	1c
	{SCX(0),0},		 //	1d
	{SCX(0),0},		 //	1e motaro
	{SCX(0),0},		 //	1f 	SK
};

/******************************************************************************
 Function: void collapse_on_ground()

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	collapse to ground
******************************************************************************/
void collapse_on_ground(void)
{
	OBJECT *obj=current_proc->pa8;

	player_normpal();
	set_noedge(obj);
	stop_me(obj);

	boss_branch(0x12);
	animate_a9(0x0004,ANIM_THUD);
	find_ani_part2(ANIM_KDOWN);
	find_last_frame();
	do_next_a9_frame(obj);

	multi_adjust_xy(obj,ochar_dead_adjusts[obj->ochar][0],ochar_dead_adjusts[obj->ochar][1]);

	shake_n_sound();
	clear_shadow_bit(obj);

	obj->oflags2|=M_DEAD;

	wait_forever();
}

void wings1(void) 
{
	wng1(-SCX(0x50000),0);
}

void wings2(void) 
{
	wng1(SCX(0x50000),1);
}

void wng1(long pa11,WORD player) 
{
	current_proc->pdata.p_otherguy=(OBJECT *)current_proc->a0;		//-DHS- big error here?? check first a0 not assigned to anything
	stance_setup();

	current_proc->a10=0x40;
	/* wng3 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--current_proc->a10>0);
	(current_proc->pa8)->oxvel.pos=pa11;

	current_proc->pdata.p_ganiy=(current_proc->pa8)->oypos.u.intpos;

	get_char_ani(ANIM_TABLE1,ANIM_BFLIP);
	current_proc->a6=0;
	gravity_ani(3,-SCY(0xa0000),ANGLE_GRAV);

	delobjp(current_proc->pa8);
	
	if (player==0) 
	{
		f_wait_for_wings-=WINGS_P1_DEC;
		if ((f_wait_for_wings & WINGS_P1_MASK)==0) 
		{
			/* load main character again */
			character_texture_load(p1_char,CHAR_NORMAL,p1_heap,SYNC_LOAD);
		}
	}
	else
	{
		f_wait_for_wings-=WINGS_P2_DEC;
		if ((f_wait_for_wings & WINGS_P2_MASK)==0) 
		{
			/* load main character again */
			character_texture_load(p2_char,CHAR_NORMAL,p2_heap,SYNC_LOAD);
		}
	}

	dallobj(OID_TEXT);
	
	process_suicide();
}

