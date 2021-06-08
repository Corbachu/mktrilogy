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
#include "mkutil.h"
#include "mkani.h"
#include "mkguys.h"
#include "moves.h"
#include "mkjoy.h"
#include "mkzap.h"
#include "mkreact.h"
#include "mkfx.h"
#include "mkslam.h"
#include "mkstat.h"
#include "mkdrone.h"
#include "mkbug.h"
#include "mkr1.h"
#include "mkprop.h"
#include "mkpal.h"
#include "mksound.h"


JUMPTBL propell_table [] =
{
	prop_kano_cannon_ball,	// 0 - kano cannonball roll
	prop_sonya_bike_kick,	// 1 - sonya bike kick
	prop_ind_charge,			// 2 - indian charge
	prop_jax_dash_punch,		// 3 - jax dash punch
	prop_do_sz_decoy,		// 4 - subzero decoy
	prop_do_lia_fly,			// 5
	prop_do_lao_tele,		// 6
	prop_do_lao_angle,		// 7
	prop_do_robo_tele,		// 8
	prop_do_robo_air_grab,	// 9
	prop_do_tele_explode,	// a
	prop_do_lia_stay_afloat,	// b
	prop_do_sonya_square_wave,	// c
	prop_do_lk_bike,			// d
	prop_do_super_kang,		// e
	prop_do_sg_pounce,		// f
	prop_do_slide,			// 10
	prop_do_swat_zoom,			// 11
	prop_do_stick_sweep,		// 12
	prop_do_tusk_blur,		// 13
	prop_do_sg_quake,		// 14
	prop_do_ninja_slide,		// 15
	prop_do_scorp_tele,		// 16
	prop_do_reptile_dash,		// 17
	prop_do_jade_prop,		// 18
	prop_do_mileena_tele,		// 19
	prop_do_mileena_prop,		// 1a
	prop_do_ermac_tele,		// 1b
	prop_do_kano_upball,		// 1c
	prop_do_raiden_melt,		// 1d		//-u64-
	prop_do_raiden_dive,		// 1e		//-u64-
	prop_do_noob_slam,			// 1f
	prop_ind_charge_fast,		//20
	prop_do_scorp_tele_forward,		// 21
	prop_do_kano_psycho,
	prop_do_lk_sbike,
	prop_do_lao_dbl_tele,		// 6
	prop_do_jc_shoruken,
	prop_do_shadow_kick,
	prop_do_shadow_kickr,
};

/******************************************************************************
 Function: void do_body_propell(WORD pindex)

 By: David Schwartz

 Date: Nov 1994

 Parameters: pindex - body propell table index

 Returns: None

 Description:	initiate a body propell move
******************************************************************************/
void do_body_propell(WORD pindex)
{
	if (pindex>= (sizeof(propell_table)/sizeof(propell_table[0])))
	{
		reaction_exit(current_proc->pa8);
	}
	else
	{
	 	stack_jump(propell_table[pindex]);
	}

	return;
}

//*******************************************************************
//*******************************************************************
//-u64-
void prop_do_raiden_dive(void) 
{
	OBJECT *obj=current_proc->pa8;
	long *pvel;

	air_init_special(obj);
	set_noflip(obj);

	current_proc->pdata.p_action=ACT_DIVE;

	ochar_sound(0xa+randu(3)-1);

	towards_x_vel(current_proc,obj,SCX(0xa0000));

	if (obj==p1_obj) 
	{
		pvel=&p1_xvel.pos;
		current_proc->a10=p1_xvel.pos;
	}
	else
	{
		pvel=&p2_xvel.pos;
		current_proc->a10=p2_xvel.pos;
	}

	stop_me(obj);

	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_DIVE);
	mframew(3);
	*pvel=(long)current_proc->a10;
	mframew(3);

	/* dive3 */
	current_proc->a11=0x1a;
	do
	{
		process_sleep(1);
		current_proc->pdata.p_stk=0x14;
		if (strike_check_a0(obj,0x14)==SYSTEM_CARRY_SET)
			dive_hit();

	}
	while(--current_proc->a11>0);

	stop_me(obj);

	if (am_i_airborn(obj)==SYSTEM_CARRY_SET)
	{
		/* fall to ground */
		face_opponent(obj);
		get_char_ani(ANIM_TABLE1,ANIM_JUMPUP);
		((ADDRESS*)current_proc->pa9)++;
		do_next_a9_frame(obj);
		flight(obj,0,SCY(0x10000),SCY(0x8000),NEVER_ANI,0xffff);
	}

	reaction_exit(obj);
}

WORD ochar_dived_poses[]=	//-u64-
{
	0,	
	0,
	0,	
	0,	
	0,
		
	0,	
	0,	
	0,	
	0,
	0,

	0,
	0,
	0,
	0,
	0,
	
	0,	
	0,
	0,	
	0,	
	0,
		
	0,	
	0,	
	0,	
	0,
	0,

	0,
	0,
	0,
	0,
	0,
	
	0,
	0,
	0,
	0,
	0,
	
};

short ochar_dived_adjust[][2]=		//-u64-
{
	{-SCX(0x40),SCY(0x00)},	
	{-SCX(0x4a),SCY(0x08)},	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x48),SCY(0x00)},	
	
	{-SCX(0x48),SCY(0x00)},	
	{-SCX(0x50),SCY(0x00)}, 
	{-SCX(0x60),SCY(0x00)}, 
	{-SCX(0x48),SCY(0x0)},      	
	{-SCX(0x48),SCY(0x00)},	//
	
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),SCY(0x00)},	//
	
	{-SCX(0x48),SCY(0x00)},	//
	{-SCX(0x48),-SCY(0x14)},	//
};	


void dive_hit(void) 
{
	long stk_a10=(long)current_proc->a10;

	clear_inviso(current_proc->pdata.p_otherguy);
	stop_him(current_proc->pdata.p_otherguy);

	if (f_block) 
	{
		stack_jump(dive_blocked);
	}

	ochar_sound(8);
	
	current_proc->pa9=(void *)get_his_char_ani(ANIM_TABLE1,ANIM_KDOWN);	//-DHS- pick correctly for boss
	((ADDRESS*)current_proc->pa9)+=ochar_dived_poses[(current_proc->pdata.p_otherguy)->ochar];
	do_his_next_a9_frame(current_proc->pdata.p_otherguy);

	match_him_with_me_f();
	adjust_him_xy(ochar_dived_adjust[(current_proc->pdata.p_otherguy)->ochar][0],ochar_dived_adjust[(current_proc->pdata.p_otherguy)->ochar][1]);

	current_proc->a10=(ADDRESS)current_proc->pdata.p_otherguy;
	if (current_proc->pa8==p1_obj) 
	{
		(long *)current_proc->a0=&p1_xvel.pos;
		(long *)current_proc->a1=&p2_xvel.pos;
	}
	else
	{
		(long *)current_proc->a1=&p1_xvel.pos;
		(long *)current_proc->a0=&p2_xvel.pos;
	}

	/* dhit4 */
	*((long *)current_proc->a0)=stk_a10;
	*((long *)current_proc->a1)=stk_a10;
	(current_proc->pdata.p_otherguy)->oxvel.pos=stk_a10;
	(current_proc->pa8)->oxvel.pos=stk_a10;

	current_proc->a11=0x20;

	/* dhit6 */
	do
	{
		f_norepell=2;
		current_proc->p_comp_flag=PC_RAIDEN_DRAG;
		process_sleep(1);
		current_proc->p_comp_flag=PC_CLEAR;

		if (p1_xvel.pos==0 || p2_xvel.pos==0 || (current_proc->pa8)->oxvel.pos==0 || (current_proc->pdata.p_otherguy)->oxvel.pos==0)
			break;
	}
	while(--current_proc->a11>0);

	/* dhit7 */
	shake_a11(6,6);

	ochar_sound(0xd);
	
	if (((current_proc->pdata.p_otherproc)->pdata.p_flags & PM_CORPSE)==0)
		xfer_otherguy(r_post_dived);

	stack_jump(dive_blocked);
} 

void dive_blocked(void) 
{
	current_proc->pdata.p_action=ACT_DIVE_SD;

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS*)current_proc->pa9)++;

	flight(current_proc->pa8,SCX(0x40000),-SCY(0x80000),SCY(0x6000),3,-1);
	reaction_exit(current_proc->pa8);
}

void prop_do_raiden_melt(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *obj_decoy;
	PROCESS *ptemp;

	init_special_act(ACT_MELT,obj);
	update_tsl(l_warp,obj);
	
	ochar_sound(6);
	
	(OBJECT *)current_proc->a11=obj;

	/* create decoy to melt */
	get_char_ani(ANIM_TABLE1,ANIM_GETUP);

	ptemp=gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);									// a8 = decoy object
	obj_decoy=current_proc->pa8;
	obj_decoy->ochar=FT_RAYDEN;
	pose2_a9(0,ANIM_RAIDEN_MELT);
	insert_object(obj_decoy,&objlst);
	CREATE(PID_MELT,melt_decoy)->a11=(ADDRESS)ptemp;

	current_proc->pa8=obj;
	match_ani_points(obj,obj_decoy);

	/* put me next to other guy */
	rd_teleport_next_to();
	ground_player(obj);
	face_opponent(obj);
	raiden_getup_pal();
	get_char_ani(ANIM_TABLE1,ANIM_SWEEPUP);
	mframew(2);
	player_normpal();

	get_char_ani(ANIM_TABLE1,ANIM_STANCE);
	do_next_a9_frame(obj);

	back_to_normal();
	process_sleep(8);

	reaction_exit(obj);
}

void rd_teleport_next_to(void) 
{
	short ta9;
	short ta1,ta3;

	ta9=SCX(0x54);
	ta3=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;

	ta1=abs(right_edge+SCRRGT-ta3);
	if (ta1>SCX(0x80)) 
	{
		ta1=abs(left_edge-ta3);
		if (ta1>SCX(0x80))
			ta9=-ta9;
	}

	match_me_with_him();
	multi_adjust_xy(current_proc->pa8,ta9,0);

	return;
}

void melt_decoy(void) 
{
	animate2_a9(2,ANIM_RAIDEN_MELT);
	delobjp(current_proc->pa8);

	process_suicide();
}

#if 0
void r_noob_slam_wait(void) 
{
	reaction_start(REACT_START,NULL,if_shao_then_pass(1),NULL);

	current_proc->pdata.p_action=ACT_POUNCE;

	group_sound(2);

	get_char_ani(ANIM_TABLE1,ANIM_KDOWN);
	mframew(2);

	/* pounce4, if mod check rpounce2 */
	if (get_his_action(current_proc)==ACT_NOOB_TELESLAM)
		suspend_wait_action_jsrp();
	getup_reaction_exit;
}

void r_noob_slammed(void)
{
	OBJECT *obj=current_proc->pa8;
	WORD damage;

	current_proc->pdata.p_action=ACT_LEGGED;

	ground_player(obj);

	find_ani_part2(ANIM_KDOWN);					// knock down on back

	do_next_a9_frame(obj);

	group_sound(2);				// group speed: wasted

	damage=0x18;
	if (obj==p1_obj)
		bar_reducer(PLAYER1_TYPE,&damage);
	else bar_reducer(PLAYER2_TYPE,&damage);
	current_proc->pdata.p_damage+=damage;
	

	flight(obj,SCX(0x30000),-SCY(0x60000),SCY(0x8000),4,-1);

	land_on_my_back();
}

void prop_do_noob_slam(void)
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *other=current_proc->pdata.p_otherguy;
	short startx;
	WORD duck;

	init_special_act(ACT_NOOB_TELESLAM,obj);			// i cant block

	local_ochar_sound(0xc);						// teleport sound

	get_char_ani(ANIM_TABLE2,ANIM_NOOB_TELESLAM);
	do_next_a9_frame(obj);
	init_anirate(2);

	me_in_front();
	
	obj->oyvel.pos=-SCY(0x80000);
	obj->ograv.pos=-SCY(0x10000);

	/* nbsl4 */
	do
	{
		process_sleep(1);
	}
	while(distance_off_ground(current_proc,obj)<SCY(0xf8));		// zip off the top of screen

	clear_shadow_bit(obj);

	startx=obj->oxpos.u.intpos;			// save for later
	match_me_with_him();
	
	face_opponent(obj);

	obj->oypos.u.intpos=ground_y-SCY(0x60);
	
	/* move on up until latch on */
	obj->ograv.pos=SCY(0xa800);
	obj->oyvel.pos=-SCY(0xc8000);

	do
	{
		process_sleep(1);
		next_anirate();
		
		if (get_y_dist<SCY(0x20) && get_x_dist<SCX(0x30)) 
		{
			/* we latched on go in for the kill, unless blocking */
			if (is_he_blocking(&duck,0)==SYSTEM_CARRY_SET || q_is_he_a_boss()==SYSTEM_CARRY_SET)
				break;
			goto TELESLAM_HIT;
		}
		
	}
	while(obj->oyvel.pos<0);
	
	/* went up and caught nothing so lets land */
	scorpion_tele_blocked(obj);
	
TELESLAM_HIT:
	/* dude is caught, disable him */
	xfer_him_to_flipped_pause(ACT_NOOB_TELESLAM);
	f_norepell=0x060;							// disable repells
		
	/* change to grab frame */
	find_ani2_part2(ANIM_NOOB_TELESLAM);
	do_next_a9_frame(obj);

	//stop_me(obj);		//-u64a-
	stop_a8(other);

	/* take dude down off screen, set no repell */
	match_him_with_me_f();				// line him up
	
	if ((current_proc->pdata.p_otherguy)->ochar==FT_SG)
		adjust_him_xy(-10,0);
	else adjust_him_xy(-40,0);

	pose_him_a0(ANIM_SCARED);
	f_norepell=0x060;							// disable repells

	/* move up until velocity is positive  -u64a- */
	other->oyvel.pos=obj->oyvel.pos;

	/* nsl4 */
	do
	{
		process_sleep(1);
		other->oyvel.pos=obj->oyvel.pos;
	}
	while(obj->oyvel.pos<0);

	/* move on down	-u64a- */
	obj->oyvel.pos=SCY(0x70000);
	other->oyvel.pos=obj->oyvel.pos;

	/* nsl5 */
	do
	{
		process_sleep(1);
		if (obj->oypos.u.intpos>worldtly.u.intpos+SCRBOT)
			break;
		obj->oyvel.pos+=SCY(0x9000);			// artif gravity
		other->oyvel.pos=obj->oyvel.pos;
	}
	while(1);

	stop_a8(obj);
	stop_a8(other);

	/* resume to starting X position */
	obj->oxpos.u.intpos=startx;
	obj->oypos.u.intpos=worldtly.u.intpos-40;
	match_him_with_me_f();				// line him up
	adjust_him_xy(-40,0);


	/* slam down to ground */
	current_proc->a6=(ADDRESS)noob_slam_match;
	flight_call(current_proc->pa8,SCX(0),SCY(0x60000),SCY(0xf000),NEVER_ANI,-1);

	set_shadow_bit(obj);

	shake_a11(12,5);
	takeover_him(r_noob_slam_wait);
	
	get_char_ani(ANIM_TABLE1,ANIM_DUCK);
	mframew(1);
	
	ground_player(other);
	
	process_sleep(3);
	
	/* send other dude to sonya leg slam type code */
	takeover_him(r_noob_slammed);

	/* noob bounces away */ 
	current_proc->pdata.p_action=ACT_ZOOM_SD;
	if (obj->oxpos.u.intpos>other->oxpos.u.intpos)
		duck=1;
	else duck=0;

	match_me_with_him();
	obj->oflags&=~M_FLIPH;
	multi_adjust_xy(obj,(duck==1)?SCX(0x10):-SCX(0x10),-SCY(10));
	face_opponent(obj);

#if 1
	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS *)current_proc->pa9)++;
	flight(obj,SCX(0x15000),-SCY(0x84000),SCY(0x6000),2,-1);
	stack_jump(jump_up_land_jump);
#else	
	ground_player(obj);
	reaction_exit(obj);
#endif	
}

void noob_slam_match(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *other=current_proc->pdata.p_otherguy;
	
	other->oypos.pos=obj->oypos.pos;		// make latched carry match me
	return;
}
#endif
//*******************************************************************
//*******************************************************************
void prop_do_kano_upball(void) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_KANO_UPBALL,obj);

	ochar_sound(4);
	set_noflip(obj);

	towards_x_vel(current_proc,obj,(is_he_airborn()==SYSTEM_CARRY_CLR)? SCX(0x70000):SCX(0x90000));
	obj->oyvel.pos=-SCY(0x30000);
	obj->ograv.pos=-SCY(0x10000);

	multi_adjust_xy(obj,0,SCY(0x18)-6);

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS *)current_proc->pa9)++;				// a9--> ball roll ani
	init_anirate(3);

	current_proc->a11=10;		// how long to spin
	/* upr5 */
	do
	{
		process_sleep(1);
		if (current_proc->a11<=0x1a-6) 
		{
			if (strike_check_a0(obj,0x13)==SYSTEM_CARRY_SET) 
			{
				/* upball_hit */
				current_proc->pdata.p_action=ACT_KROLL_SD;

				hit_or_blocked_sound(0x7,0x8);

				if (f_block) 
				{
					flight(obj,SCX(0x30000),-SCY(0x80000),SCY(0x6000),2,-1);
				}
				else
				{
					flight(obj,SCX(0x0000),-SCY(0x90000),SCY(0x6000),2,-1);
				}

				jump_up_land_jsrp();
				reaction_exit(obj);
			}
		}
		next_anirate();
	}
	while(--current_proc->a11>0);

	current_proc->pdata.p_action=ACT_UPBALL_SD;

	obj->ograv.pos=SCY(0x18000);			// head down again
	/* upr8 */
	do
	{
		process_sleep(1);
		upball_x_damping(obj);
		next_anirate();
	}
	while(obj->oyvel.pos<0);

	set_x_vel(obj,0);
	obj->ograv.pos=SCY(0x5000);			// head down again

	current_proc->a6=NULL;
	flight_call(obj,DONT_TOUCH,DONT_TOUCH,DONT_TOUCH,2,-1);

	jump_up_land_jump();
}

void upball_x_damping(OBJECT *obj) 
{
	set_x_vel(obj,obj->oxvel.pos-(obj->oxvel.pos>>3));
	return;
}

void prop_do_kano_psycho(void) 
{
	OBJECT *obj=current_proc->pa8;
	long xvel;

	init_special_act(ACT_KANO_ROLL,obj);

	ochar_sound(4);
	set_noflip(obj);

	multi_adjust_xy(obj,0,SCY(0x18)-6);

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS *)current_proc->pa9)++;				// a9--> ball roll ani
	init_anirate(3);

	/* move for a bit */
	redirect_scroller(scorp_tele_scroll);

	/* random pick a direction and a velocity */
	set_x_vel(obj,xvel=(randper(500)==SYSTEM_CARRY_SET)? SCX(0xd0000)+(randu(0xa)<<16):-SCX(0xd0000)-(randu(0xa)<<16));
	obj->oyvel.pos=(randper(400)==SYSTEM_CARRY_SET)?SCY(0xa0000)+(randu(0xa)<<16):-SCY(0xa0000)-(randu(0xa)<<16);
	obj->ograv.pos=0;
	current_proc->a11=randu_minimum(30,30);		// how long to spin
	/* upr5 */
	do
	{
		process_sleep(1);
		
		if ((obj->oxpos.u.intpos>(worldtlx.u.intpos+SCRRGT-0x40) && xvel>0) || (obj->oxpos.u.intpos<worldtlx.u.intpos+0x40 && xvel<0))
		{
			xvel=-xvel;
			set_x_vel(obj,xvel);
		}
		
		if (obj->oypos.u.intpos>current_proc->pdata.p_ganiy+48)
		{
			obj->oypos.u.intpos=current_proc->pdata.p_ganiy+48;
			obj->oyvel.pos=-obj->oyvel.pos;
		}
		
		if (obj->oypos.u.intpos<worldtly.u.intpos)
			obj->oyvel.pos=-obj->oyvel.pos;
		
		if (strike_check_a0(obj,0x13)==SYSTEM_CARRY_SET) 
		{
			/* upball_hit */
			current_proc->pdata.p_action=ACT_KROLL_SD;

			hit_or_blocked_sound(0x7,0x8);

			if (f_block==0)
				flight(obj,SCX(0x50000),-SCY(0x80000),SCY(0x6000),2,-1);
			else flight(obj,SCX(0x10000),-SCY(0x80000),SCY(0x6000),2,-1);
			
			jump_up_land_jsrp();
			reaction_exit(obj);
		}
		
		next_anirate();
	}
	while(--current_proc->a11>0);

	current_proc->pdata.p_action=ACT_UPBALL_SD;

	obj->ograv.pos=SCY(0x18000);			// head down again
	/* upr8 */
	do
	{
		process_sleep(1);
		upball_x_damping(obj);
		next_anirate();
	}
	while(obj->oyvel.pos<0);

	set_x_vel(obj,0);
	obj->ograv.pos=SCY(0x5000);			// head down again

	current_proc->a6=NULL;
	flight_call(obj,DONT_TOUCH,DONT_TOUCH,DONT_TOUCH,2,-1);

	jump_up_land_jump();
}

//*******************************************************************
//*******************************************************************
void prop_do_mileena_prop(void) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_MILEENA_ROLL,obj);

	ochar_sound(0xa);

	do_first_a9_frame(ANIM_DUCK);
	process_sleep(3);

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS *)current_proc->pa9)++;				// a9--> 

	multi_adjust_xy(obj,SCX(0),SCY(0x4a));

	init_anirate(2);
	towards_x_vel(current_proc,obj,SCX(0xa0000));
	current_proc->a10=0x18;
	current_proc->a11=5;

	/* kano3 */
	do
	{
		do
		{
			next_anirate();
			sans_repell_3();
			if (strike_check_a0(obj,0x16)==SYSTEM_CARRY_SET)
				mileena_prop_hit();
			process_sleep(1);
		}
		while(--current_proc->a11>0);
		current_proc->a11=1;
	}
	while(--current_proc->a10>0);

	post_mileena_prop();
}

void mileena_prop_hit(void) 
{
	if (f_block==1 || q_is_he_a_boss()==SYSTEM_CARRY_SET)
	{
		stack_jump(mileena_prop_blocked);
	}

	current_proc->a10=0xb;
	/* khit4 */
	do
	{
		next_anirate();
		process_sleep(1);
	}
	while(--current_proc->a10>0);

	stack_jump(post_mileena_prop);
}

void post_mileena_prop(void) 
{
	stop_me(current_proc->pa8);
	ground_player(current_proc->pa8);
	face_opponent(current_proc->pa8);
	update_tsl(l_mileena_roll,current_proc->pa8);
	do_backup();
	reaction_exit(current_proc->pa8);
}

void mileena_prop_blocked(void) 
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_ZOOM_SD;

	(long)current_proc->a11=obj->oypos.pos;
	match_me_with_him();
	multi_adjust_xy(obj,0x20,0);
	face_opponent(obj);
	obj->oypos.pos=(long)current_proc->a11;

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS*)current_proc->pa9)++;

	obj->oyvel.pos=-SCY(0xb0000);
	obj->ograv.pos=SCY(0x6000);
	init_anirate(2);
	away_x_vel(current_proc,obj,SCX(0xa000));

	/* kblk4 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(obj->oypos.u.intpos>current_proc->pdata.p_ganiy);

	flight(obj,DONT_TOUCH,DONT_TOUCH,DONT_TOUCH,2,-1);
	jump_up_land_jump();
}

//*******************************************************************
//*******************************************************************
void prop_do_mileena_tele(void) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_MILEENA_ROLL,obj);

	ochar_sound(0x7);

	get_char_ani(ANIM_TABLE1,ANIM_LOKICK);
	do_next_a9_frame(obj);

	obj->oyvel.pos=SCY(0x50000);

	/* fntele3 */
	do
	{
		process_sleep(1);
		if (obj->oypos.u.intpos>worldtly.u.intpos+SCRBOT-SCY(0x20))
			break;
		obj->oyvel.pos+=SCY(0x6000);			// artif gravity
	}
	while(1);

	/* fntele5 */
	match_me_with_him();
	flip_multi(obj);
	multi_adjust_xy(obj,-SCX(0x50),0);
	obj->oypos.u.intpos=worldtly.u.intpos-SCY(0x20);

	find_ani_last_frame(ANIM_FLIPKICK);
	do_next_a9_frame(obj);

	current_proc->a6=(ADDRESS)mileena_teleport_call;
	towards_x_vel(current_proc,obj,SCX(0x40000));
	flight_call(obj,DONT_TOUCH,DONT_TOUCH,SCY(0xa000),NEVER_ANI,-1);

	animate_a9(3,ANIM_DUCK);
	process_sleep(8);
	reaction_exit(obj);
}

void mileena_teleport_call(void) 
{
	OBJECT *obj=current_proc->pa8;

	if (strike_check_a0(obj,0x15)==SYSTEM_CARRY_SET) 
	{
		/* mileena_tele_hit */
		current_proc->pdata.p_action=ACT_MIL_TELE_SD;
		if (f_block) 
		{
			(long)current_proc->a1=-SCY(0x60000);
			(long)current_proc->a2=SCY(0x5000);
		}
		else
		{
			(long)current_proc->a1=-SCY(0x50000);
			(long)current_proc->a2=SCY(0xa000);
		}

		find_ani_part_a14(ANIM_FLIPKICK,3);
		flight(obj,SCX(0x10000),(long)current_proc->a1,(long)current_proc->a2,6,-1);
		jump_up_land_jump();
	}
	else
	{
		return;
	}
}

//*******************************************************************
//*******************************************************************
void prop_do_jade_prop(void) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_JADE_PROP,obj);

	player_swpal(current_proc,jade_bright_p,obj);
	ochar_sound(6);
	create_fx(FX_JADE_SMOKE);

	get_char_ani(ANIM_TABLE1,ANIM_LOKICK);
	init_anirate(1);

	towards_x_vel(current_proc,obj,SCX(0x80000));

	current_proc->a10=5;
	/* jprop2 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--current_proc->a10>0);

	process_sleep(1);
	next_anirate();
	if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)
		jade_prop_hit();

	current_proc->a10=7;
	/* jprop5 */
	do
	{
		process_sleep(1);
		jade_prop_damping(obj);
		if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)
			jade_prop_hit();
	}
	while(--current_proc->a10>0);

	current_proc->pdata.p_action=ACT_ICHARGE_SD;

	current_proc->a10=8;
	/* jprop7 */
	do
	{
		process_sleep(1);
		jade_prop_damping(obj);
	}
	while(--current_proc->a10>0);

	stop_me(obj);
	process_sleep(0x20);
	reaction_exit(obj);
}

void jade_prop_hit(void) 
{
	do_first_a9_frame(ANIM_LOKICK);
	find_last_frame();
	do_next_a9_frame(current_proc->pa8);
	stop_me(current_proc->pa8);

	process_sleep((f_block)?0x20:0x10);
	reaction_exit(current_proc->pa8);
}

void jade_prop_damping(OBJECT *obj) 
{
	set_x_vel(obj,obj->oxvel.pos-(obj->oxvel.pos>>3));
	return;
}

//*******************************************************************
//*******************************************************************
void prop_do_reptile_dash(void) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_REPTILE_DASH,obj);

	get_char_ani(ANIM_TABLE1,ANIM_RUN);
	towards_x_vel(current_proc,obj,SCX(0xd0000));

	current_proc->a10=0x10;
	/* repd3 */
	do
	{
		process_sleep(1);
		do_next_a9_frame(obj);
		sans_repell_3();
		if (is_he_airborn()==SYSTEM_CARRY_CLR) 
		{
			if (strike_check_a0(obj,0x15)==SYSTEM_CARRY_SET) 
			{
				if (f_block)
				{
					reptile_dash_blocked(obj);
				}
				else
				{
					reptile_dash_hit();
				}
				
			}
		}
	}
	while(--current_proc->a10>0);

	reaction_exit(obj);
}

void reptile_dash_hit(void) 
{
	current_proc->a10=14;
	/* rdh3 */
	do
	{
		process_sleep(1);
		do_next_a9_frame(current_proc->pa8);
		sans_repell_3();
	}
	while(--current_proc->a10>0);

	stop_me(current_proc->pa8);

	process_sleep(6);

	face_opponent(current_proc->pa8);
	get_char_ani(ANIM_TABLE2,ANIM_REP_DASH);
	mframew(2);

	towards_x_vel(current_proc,current_proc->pa8,SCX(0xd0000));
	current_proc->a10=20;
	/* rdh5 */
	do
	{
		process_sleep(1);
		if (strike_check_a0(current_proc->pa8,0x16)==SYSTEM_CARRY_SET)
			break;
	}
	while(--current_proc->a10>0);

	/* rdh6 */
	stop_me(current_proc->pa8);
	process_sleep(0x14);

	mframew(3);
	reaction_exit(current_proc->pa8);
}

//*******************************************************************
//*******************************************************************
void prop_do_ermac_tele(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	if (am_i_airborn(obj)==SYSTEM_CARRY_CLR)	
	{
		ochar_sound(0x9);
		create_fx(FX_INVISO_POOF);
	}

	/* ertele3 */
	set_inviso(obj);

	stack_jump(prop_do_scorp_tele);
}

void prop_do_scorp_tele_forward(void) 
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_SCORP_TELE;
	air_init_special(obj);

	update_tsl(l_decoy,obj);

	ochar_sound(0xc);

	face_opponent(obj);

	current_proc->pdata.p_store5=6;
	current_proc->a6=(ADDRESS)sctele_scalla_2;
	flight_call(obj,-SCX(0xa0000),-SCY(0x30000),SCY(0x5000),3,(0x0001<<16)|ANIM_SCORP_TELE);
	clear_inviso(obj);
	reaction_exit(obj);
}

void prop_do_scorp_tele(void) 
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_SCORP_TELE;
	air_init_special(obj);

	update_tsl(l_decoy,obj);

	ochar_sound(0xc);

	redirect_scroller(scorp_tele_scroll);
	face_opponent(obj);
	flip_multi(obj);
	set_noedge(obj);

	current_proc->a6=(ADDRESS)sctele_scalla_1;
	flight_call(obj,SCX(0xa0000),-SCY(0x30000),SCY(0x5000),3,(0x0001<<16)|ANIM_SCORP_TELE);
	clear_inviso(obj);
	reaction_exit(obj);
}

#define SCORP_EDGE_ADJUST 0

void sctele_scalla_1(void) 
{
	OBJECT *obj=current_proc->pa8;

	sans_repell_3();

	if (obj->oxvel.pos==0)
		return;


	if (obj->oxvel.pos<0) 
	{
		current_proc->a0=(long)(obj->oxpos.u.intpos);
		current_proc->a1=(long)(worldtlx.u.intpos+SCORP_EDGE_ADJUST);
		current_proc->a3=(long)(worldtlx.u.intpos+SCRRGT);
	}
	else
	{
		current_proc->a1=(long)(obj->oxpos.u.intpos);
		current_proc->a0=(long)(worldtlx.u.intpos+SCORP_EDGE_ADJUST+SCRRGT-2*SCORP_EDGE_ADJUST);
		current_proc->a3=(long)(worldtlx.u.intpos+SCRRGT-SCRRGT);
	}

	/* stc5 */
	if ((long)current_proc->a1<(long)current_proc->a0)
		return;

	/* teleport part */
	obj->oxpos.u.intpos=current_proc->a3;
	current_proc->pdata.p_store4=(ADDRESS)sctele_scalla_2;
	current_proc->pdata.p_store5=0;
	clear_inviso(obj);
	clear_noedge(obj);
	return;
}

void sctele_scalla_2(void) 
{
	OBJECT *obj=current_proc->pa8;

	if (current_proc->pdata.p_store5!=0) 
	{
		current_proc->pdata.p_store5--;
		return;
	}
	
	sans_repell_3();
	if (strike_check_a0(obj,0x17)==SYSTEM_CARRY_CLR)
		return;

	find_last_frame();		// place in attack frame
	do_next_a9_frame(obj);
	
	if (f_block)
		scorpion_tele_blocked(obj);

	stop_me(obj);
	
	if (is_he_airborn()==SYSTEM_CARRY_CLR) 
	{
		current_proc->a10=6;
		current_proc->a11=(long)SCY(0x8000);
	}
	else
	{
		current_proc->a10=4;
		current_proc->a11=(long)SCY(0xc000);
	}

	/* sctele3 */
	process_sleep(current_proc->a10);

	flight(obj,0,SCY(0x10000),(long)current_proc->a11,30,-1);

	reaction_exit(obj);
}

void redirect_scroller(FUNC p_ar7) 
{
	PROCESS *ptemp;

	ptemp=exprc_er(PID_SCROLL);

	(OBJECT *)ptemp->pdata.p_store1=current_proc->pdata.p_otherguy;
	(PROCESS *)ptemp->pdata.p_store2=current_proc;
	fastxfer(ptemp,p_ar7);
	return;
}

/******************************************************************************
 Function: void prop_do_tusk_blur(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	tusk blur attack
******************************************************************************/
void prop_do_tusk_blur(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_TUSK_BLUR,obj);

	get_char_ani(ANIM_TABLE2,ANIM_TUSK_BLUR);

	towards_x_vel(current_proc,obj,SCX(0xd0000));
	init_anirate(1);

	ochar_sound(2);				// zoom sound!!!
	current_proc->pdata.p_store1=0;

	current_proc->a10=0x1a;
	/* blur3 */
	do
	{
		process_sleep(1);

		if (current_proc->pdata.p_store1==0)
		{
			if (strike_check_a0(obj,0x12)==SYSTEM_CARRY_SET)
			{
				if (f_block!=0)
					tusk_blur_block(obj);
				current_proc->pdata.p_store1=1;
			}
		}

		/* blur5 */
		sans_repell_3();
		next_anirate();
	}
	while(--current_proc->a10>0);

	find_ani2_part2(ANIM_TUSK_BLUR);

	stop_me(obj);
	mframew(2);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void tusk_blur_block(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	tusk raider blur block after hit
******************************************************************************/
void tusk_blur_block(OBJECT *pa8)
{
	blur_blocked_setup();

	if (GET_LONG(current_proc->pa9)!=0)
		mframew(1);

	/* blb7 */
	find_ani2_part2(ANIM_TUSK_BLUR);
	mframew(1);

	shake_a8_up(pa8,4,0,3,4);
	reaction_exit(pa8);
}

void reptile_dash_blocked(OBJECT *pa8) 
{
	blur_blocked_setup();
	pose_a9(3,ANIM_RUN);

	shake_a8_up(pa8,4,0,3,4);
	reaction_exit(pa8);
}

void blur_blocked_setup(void) 
{
	current_proc->pdata.p_action=ACT_TUSK_BLUR_SD;

	set_no_block(current_proc->pa8);
	stop_me(current_proc->pa8);
}

/******************************************************************************
 Function: void prop_do_stick_sweep(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat stick sweep attack
******************************************************************************/
void prop_do_stick_sweep(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_STICK_SWEEP,obj);

	ochar_sound(3);			// stick sweep sound

	towards_x_vel(current_proc,obj,SCX(0x60000));

	get_char_ani(ANIM_TABLE2,ANIM_SWAT_STICK);
	mframew(4);
	stop_me(obj);

	if (strike_check_a0(obj,0x17)==SYSTEM_CARRY_SET && f_block==0)
	{
		process_sleep(6);

		do_next_a9_frame(obj);
		process_sleep(4);
		reaction_exit(obj);
	}

	/* stsw_miss */
	current_proc->pdata.p_action=ACT_STSW_SD;
	do_next_a9_frame(obj);
	process_sleep(0x20);				// sitting duck time
	mframew(4);
	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_do_swat_zoom(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat zoom
******************************************************************************/
void prop_do_swat_zoom(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_ZOOM,obj);

	get_char_ani(ANIM_TABLE2,ANIM_SWAT_ZOOM);
	do_next_a9_frame(obj);

	local_ochar_sound(2);
	towards_x_vel(current_proc,obj,SCX(0xc0000));
	obj->oyvel.pos=-SCY(0x20000);
	obj->ograv.pos=SCY(0x2400);
	sans_repell_3();

	/* zoom scan loop */
	current_proc->pdata.p_store1=0;			// flag: no hit yet
	/* zoom3 */
	do
	{
		process_sleep(1);
		sans_repell_3();
		zoom_damping(obj);

		if (q_is_he_a_boss()==SYSTEM_CARRY_CLR)		// make sure strong enough to throw boss
		{
			if (strike_check_a0(obj,0x15)==SYSTEM_CARRY_SET)
			{
				if (f_block==1)
					zoom_blocked(obj);
				else zoom_hit(obj);
			}
		}

		/* zoom4 */
	}
	while(current_proc->pdata.p_ganiy>=obj->oypos.u.intpos);

	stop_me(obj);
	ground_player(obj);
	reaction_exit(obj);
}
#if 0
short ochar_zoom_lineups[][2]=
{
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},

	{SCX(0x40),SCY(0x00)},		// 5 - swat
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},

	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},

	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)},
	{SCX(0x40),SCY(0x00)}
};
#endif

/******************************************************************************
 Function: void zoom_hit(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat zoom hit
******************************************************************************/
void zoom_hit(OBJECT *pa8)
{
//-SONY_HACK- 	LONG *idptr;

	if (d_front_me_a5()<SCX(0xe0))
		set_his_noedge;			// avoid corner bs

	local_ochar_sound(4);

	stop_him(current_proc->pdata.p_otherguy);

	/* zoom2 */
	do
	{
		process_sleep(1);
		sans_repell_3();
		zoom_ground_scan(pa8);
		if (closest_edge_a5()<=SCX(0x60))
			goto ZOOMH5;
	}
	while(get_x_dist<=SCX(0x30));

	/* line him up with me */
ZOOMH5:
//-SONY_HACK- 	idptr=idcomp_ptr;       // bug fix for running out of decomp space

	match_him_with_me_f();
	pose_him_a9(1,ANIM_KDOWN);
	//adjust_him_xy(ochar_zoom_lineups[(current_proc->pdata.p_otherguy)->ochar][0],ochar_zoom_lineups[(current_proc->pdata.p_otherguy)->ochar][1]);
	adjust_him_xy(SCX(0x40),SCY(0x00));

	stop_me(pa8);
	ground_player(pa8);

//-SONY_HACK- 	idcomp_ptr=idptr;				// bug fix for running out of decomp space

	/* flip this zero */
	stop_him(current_proc->pdata.p_otherguy);
	current_proc->a11=get_his_char_ani(ANIM_TABLE1,ANIM_ZOOM);
	current_proc->a10=(ADDRESS)(current_proc->pdata.p_otherguy);
	get_char_ani(ANIM_TABLE2,ANIM_SWAT_ZOOM);
	find_part2();

	group_sound(4);
	rsnd_big_whoosh();

	//add_combo_damage(ZOOM_DAMAGE);

	double_mframew(3);
	xfer_otherguy(r_zoom_flipped);
	(current_proc->pdata.p_otherproc)->pa9=(void *)current_proc->a11;		// pass ani
	do_next_a9_frame(pa8);
	process_sleep(0xa);
	mframew(6);
	reaction_exit(pa8);
}

/******************************************************************************
 Function: void zoom_blocked(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat zoom blocked
******************************************************************************/
void zoom_blocked(OBJECT *pa8)
{
	current_proc->pdata.p_action=ACT_ZOOM_SD;

	match_me_with_him();
	pa8->oflags&=~M_FLIPH;
	multi_adjust_xy(pa8,(pa8->oxvel.pos<0)?SCX(0x10):-SCX(0x10),SCY(0));
	face_opponent(pa8);

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS *)current_proc->pa9)++;
	flight(pa8,SCX(0x10000),-SCY(0x80000),SCY(0x6000),2,-1);
	stack_jump(jump_up_land_jump);
}

/******************************************************************************
 Function: void zoom_damping(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat zoom damping function
******************************************************************************/
void zoom_damping(OBJECT *pa8)
{
	set_x_vel(pa8,pa8->oxvel.pos-((pa8->oxvel.pos)>>6));
	return;
}

/******************************************************************************
 Function: void zoom_ground_scan(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat zoom ground scan
******************************************************************************/
void zoom_ground_scan(OBJECT *pa8)
{
	if (pa8->oypos.u.intpos<current_proc->pdata.p_ganiy)
		return;

	pa8->oypos.u.intpos=current_proc->pdata.p_ganiy;		// ground me
	pa8->ograv.pos=0;
	(current_proc->pdata.p_otherguy)->oyvel.pos=0;

	return;
}

/******************************************************************************
 Function: void prop_do_lao_angle(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lao angle kick
******************************************************************************/
void prop_do_lao_angle(void)
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_LAO_ANGLE;
	air_init_special(current_proc->pa8);

	group_sound(0);					// attack voice
	local_ochar_sound(0);			// angle kick sound

	(FUNC)current_proc->a6=lao_angle_scan;
	flight_call(obj,-SCX(0x80000),SCY(0x30000),SCY(0x4000),2,ANIM_FLIPKICK);

	jump_up_land_jsrp();
	reaction_exit(obj);
}

/******************************************************************************
 Function: void lao_angle_scan(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lao angle scan routine
******************************************************************************/
void lao_angle_scan(void)
{
	if (GET_LONG(current_proc->pa9)==0) 		// test if leg is extended
	{
		if (strike_check_a0(current_proc->pa8,0x12)==SYSTEM_CARRY_SET)
		{
			/* lao_angle_hit */
			stop_me(current_proc->pa8);
			if (f_block==0)
			{
				/* lao_angled_hit */
				process_sleep(6);
				land_on_yer_feet();
			}
			else
			{
				/* lao_angle_block */
				current_proc->pdata.p_action=ACT_LAO_SD;
				get_char_ani(ANIM_TABLE1,ANIM_BFLIP);
				((ADDRESS *)current_proc->pa9)++;
				flight(current_proc->pa8,SCX(0x4000),-SCY(0x70000),SCY(0x6000),3,-1);

				jump_up_land_jump();
			}
		}
	}

	return;
}

/******************************************************************************
 Function: void prop_do_lao_tele(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lao teleport blur
******************************************************************************/
void prop_do_lao_tele(void) 
{
	lao_tele(0);
}

void prop_do_lao_dbl_tele(void) 
{
	lao_tele(1);
}

void lao_tele(WORD telecnt)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_LAO_TELE,obj);			// i cant block

	local_ochar_sound(4);						// teleport sound

	get_char_ani(ANIM_TABLE2,ANIM_LAO_TELE_BLUR);
	do_next_a9_frame(obj);
	init_anirate(2);

	obj->oyvel.pos=-SCY(0x80000);
	obj->ograv.pos=-SCY(0x10000);

	/* hht4 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(distance_off_ground(current_proc,obj)<SCY(0xe8));		// zip off the top of screen
	
	/* check for a second teleprot */
	if (telecnt==1) 
	{
		obj->oypos.u.intpos=ground_y-SCY(0x60);
		obj->oyvel.pos=-SCY(0x80000);
		obj->ograv.pos=-SCY(0x10000);

		/* hht4 */
		do
		{
			process_sleep(1);
			next_anirate();
		}
		while(distance_off_ground(current_proc,obj)<SCY(0xe8));		// zip off the top of screen
	}

	teleport_next_to();
	face_opponent(obj);

	obj->oypos.u.intpos=ground_y-SCY(0x60);

	obj->ograv.pos=SCY(0x8000);
	obj->oyvel.pos=-SCY(0xa0000);

	/* hht6 */
	do
	{
		process_sleep(1);
	}
	while((obj->oypos.u.intpos-SCY(0x10))>current_proc->pdata.p_ganiy);

	if (am_i_joy()==SYSTEM_CARRY_SET)
		stuff_buttons(obj,bt_jump);				// joy = let him punch/kick
	else
	{
		/* hht8 */
		if (rand_num<0)
			do_jumpup_punch;
		else do_jumpup_kick;
	}

	find_ani2_part2(ANIM_LAO_TELE_BLUR);
	flight(obj,0,obj->oyvel.pos,obj->ograv.pos,5,-1);

	reaction_exit(obj);
}



/******************************************************************************
 Function: void prop_do_tele_explode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	teleport explode
******************************************************************************/
extern WORD IMPLODE_P[];
void prop_do_tele_explode(void)
{
	OBJECT *obj=current_proc->pa8;
	long a5,a6;

	a5=(long)current_proc->a5=obj->oxvel.pos;
	a6=(long)current_proc->a6=obj->oyvel.pos;

	current_proc->pdata.p_action=ACT_TELE_EXPLODE;
	air_init_special(current_proc->pa8);

	(long)current_proc->a5=a5;
	(long)current_proc->a6=a6;

	obj->oxvel.pos=(long)current_proc->a5;
	obj->oyvel.pos=(long)current_proc->a6;

	animate2_a9(0x0003,ANIM_ROBO_TELE_EXP);

	(OBJECT *)current_proc->a10=current_proc->pa8;
	current_proc->a11=2;

	/* dtex3 */
	do
	{
		get_char_ani(ANIM_TABLE2,ANIM_ROBO_TELE_EXP);
		find_part_a14(current_proc->a11);

		gso_dmawnz_np(obj,GET_LONG(current_proc->pa9),obj->odict,obj->oheap,0);
		obj->ochar=((OBJECT*)current_proc->a10)->ochar;
		get_player_palette(character_palettes_1);
		swpal((void *)IMPLODE_P,obj);
		obj->oid=OID_ROBO_LIMB;
		a8_front_plus_1(obj);

		lineup_1pwm(obj,(OBJECT *)current_proc->a10);
		insert_object(obj,&objlst);
		CREATE(PID_ROBO_LIMB,robo_limb_out);
		obj=current_proc->pa8=(OBJECT *)current_proc->a10;
		current_proc->a11++;
	}
	while(current_proc->a11!=9);

	create_fx(FX_ROBO_TELE_EXPLODE);
	process_sleep(1);

	stop_me(obj);
	set_nocol(obj);
	set_inviso(obj);
	clear_shadow_bit(obj);
	teleport_next_to();
	face_opponent(obj);
	ground_player(obj);
	process_sleep(0x0a);
	cyrax_implode();
	reaction_exit(obj);
}

void cyrax_implode(void)
{
	OBJECT *obj=current_proc->pa8;
	
	/* implode */
	(OBJECT *)current_proc->a10=current_proc->pa8;
	current_proc->a11=2;

	/* dtex5 */
	do
	{
		get_char_ani(ANIM_TABLE2,ANIM_ROBO_TELE_EXP);
		find_part_a14(current_proc->a11);

		gso_dmawnz_np(obj,GET_LONG(current_proc->pa9),obj->odict,obj->oheap,0);
		obj->ochar=((OBJECT*)current_proc->a10)->ochar;
		get_player_palette(character_palettes_1);
		swpal((void *)IMPLODE_P,obj);
		obj->oid=OID_ROBO_LIMB;
		a8_front_plus_1(obj);

		lineup_1pwm(obj,(OBJECT *)current_proc->a10);
		insert_object(obj,&objlst);
		(PROCESS *)current_proc->a0=CREATE(PID_ROBO_LIMB,robo_limb_in);
		obj=current_proc->pa8=(OBJECT *)current_proc->a10;
		current_proc->a11++;
	}
	while(current_proc->a11!=9);

	current_proc->a11=current_proc->a0;

	create_fx(FX_ROBO_TELE_IMPLODE);

	/* dtex6 */
	do
	{
		process_sleep(1);
	}
	while(((PROCESS *)current_proc->a11)->p_comp_flag==PC_CLEAR);

	clear_nocol(obj);
	clear_inviso(obj);
	set_shadow_bit(obj);

	backwards_ani2(3,ANIM_ROBO_TELE_EXP);

	return;
}

long limb_speeds[]=
{
	-SCX(LSPEED),-SCY(LSPEED),		// LEFT ARM
 	0,-SCY(LSPEED),					// HEAD
 	SCX(LSPEED),-SCY(LSPEED),		// RIGHT ARM
 	0,-SCY(LSPEED-0x18000),			// CHEST
 	0,SCY(LSPEED),					// WAIST
 	SCX(LSPEED),SCY(LSPEED),		// RIGHT LEG
 	-SCX(LSPEED),SCY(LSPEED)		// LEFT LEG
};

/******************************************************************************
 Function: void robo_limb_in(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	limbs come in
******************************************************************************/
void robo_limb_in(void)
{
	long *lptr;
	long xpos,ypos;
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_store1=(ADDRESS)current_proc->pa9;		// save frame 1

	current_proc->a11-=2;

	lptr=limb_speeds+(current_proc->a11*2);

	xpos=*lptr;
	xpos=(xpos<<3);				// quick multiply
	xpos=(xpos+(xpos<<1));		// 1/2 distance

	ypos=*(lptr+1);
	ypos=(ypos<<3);				// quick multiply
	ypos=(ypos+(ypos<<1));		// 1/2 distance

	multi_adjust_xy(obj,(short)(xpos>>16),(short)(ypos>>16));

	xpos=*lptr;					// implode 50% faster
	xpos=-((xpos>>1)+xpos);

	ypos=*(lptr+1);
	ypos=-((ypos>>1)+ypos);


	obj->oyvel.pos=ypos;

	set_proj_vel(obj,xpos,2);

	/* limb5 */
	xpos=0x10;
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--xpos>0);

	stop_a8(obj);

	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	frame_a9(obj);

	current_proc->p_comp_flag=PC_ROBO_LIMB_WAKE;
	process_sleep(3);

	/* limb8 */
	delobjp(obj);
	process_suicide();
}

/******************************************************************************
 Function: void robo_limb_out(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	limbs go out
******************************************************************************/
void robo_limb_out(void)
{
	long *lptr;
	long temp;
	OBJECT *obj=current_proc->pa8;

	current_proc->a11-=2;
	lptr=limb_speeds+(current_proc->a11*2);

	temp=*lptr;
	lptr++;
	obj->oyvel.pos=*lptr;
	set_proj_vel(obj,temp,2);

	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(scrtst(obj)==SYSTEM_ZERO_SET);

	delobjp(obj);
	process_suicide();
}

/******************************************************************************
 Function: void prop_do_robo_air_grab(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	robo air grab
******************************************************************************/
void prop_do_robo_air_grab(void)
{
	short loop;
	long xval,yval,hypo;
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_ROBO_AIRGRAB;
	air_init_special(current_proc->pa8);

	ochar_sound(0x23);	

	find_ani2_part2(ANIM_ROBO_AIR_SLAM);		// part 2 = lunge
	do_next_a9_frame(obj);						// driving forward pose

	process_sleep(3);

	init_anirate(4);

	current_proc->a10=(ADDRESS)(current_proc->pdata.p_otherguy);

	loop=6;						// # of "close" ticks allowed

	/* air3 */
	do
	{
		current_proc->p_comp_flag=PC_ROBO_AIR;			// mod, signal robo_lp_close that at air_grab_sleep
		process_sleep(1);

		/* air_grab_sleep */
		current_proc->p_comp_flag=PC_CLEAR;			// pass air_grab_sleep

		next_anirate();

		xval=(((OBJECT *)(current_proc->a10))->oxpos.u.intpos-obj->oxpos.u.intpos)<<16;			// here is our dir vector
		yval=(((OBJECT *)(current_proc->a10))->oypos.u.intpos-obj->oypos.u.intpos)<<16;

		hypo=get_rough_hypotenuse(xval,yval);		// distance (roughly)
		hypo>>=16;

		xval=(xval/hypo)*12;					// normalize vector
		yval=(yval/hypo)*12;					// normalize vector

		obj->oxvel.pos=xval;
		obj->oyvel.pos=yval;

		set_x_vel(obj,xval);					// redirect my self

		if (is_he_airborn()==SYSTEM_CARRY_CLR)
			break;								// he is on ground ---> cancel


		if (get_x_dist>SCX(0x45))
			loop++;								// not super close, dont chalk up 1 "close tick"
	}
	while(--loop>0);

	/* air_grab_cancel */

	pose_a9(0x0000,ANIM_FLIPKICK);
	flight(obj,DONT_TOUCH,DONT_TOUCH,SCY(0x8000),NEVER_ANI,-1);

	jump_up_land_jsrp();
	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_do_robo_tele(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	robo teleport
******************************************************************************/
void prop_do_robo_tele(void)
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_action=ACT_ROBO_TELE;
	air_init_special(current_proc->pa8);

	local_ochar_sound(7);

	get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
	find_last_frame();

	do_next_a9_frame(obj);				// pose: teleport down

	obj->oyvel.pos=SCY(0x70000);			// start headin' downward

	obj->ograv.pos=SCY(0xb000);

	/* rtele3 */
	do
	{
		process_sleep(1);
	}
	while(distance_from_ground(obj)>0);

	match_me_with_him();

	/* compensate ofr his movement */
	(long)current_proc->a1=(current_proc->pdata.p_otherguy)->oxvel.pos;
	(long)current_proc->a1<<=4;
	(long)current_proc->a1>>=16;
	multi_adjust_xy(obj,(long)current_proc->a1-SCX(0x10),0);
	face_opponent(obj);

	obj->oypos.u.intpos=ground_y;			// under otherguy

	obj->oyvel.pos=-SCY(0x90000);
	obj->ograv.pos=-SCY(0x6000);

	get_char_ani(ANIM_TABLE2,ANIM_ROBO_TELEPUNCH);		// teleport punch anim
	init_anirate(5);

	current_proc->pdata.p_store1=0;			// flag: no collision
	current_proc->pdata.p_store2=0;

	/* rtele8 */
	do
	{
		process_sleep(1);
		next_anirate();

		if ((obj->oypos.u.intpos-current_proc->pdata.p_ganiy)<=SCY(0x30))
			tele_scan();					// high enough to scan for collision
	}
	while(obj->oypos.u.intpos>current_proc->pdata.p_ganiy);		// wait for me to reach ground level

	/* rtele9 */

	if (current_proc->pdata.p_store2==0)
		obj->ograv.pos=(0xf000);
	else obj->ograv.pos=(0xb000);			// blocked hang more (vulnerable)

	(FUNC)current_proc->a6=tele_scan2;
	flight_call(obj,0,DONT_TOUCH,DONT_TOUCH,current_proc->pdata.p_anirate,-1);

	jump_up_land_jsrp();
	reaction_exit(obj);
}

/******************************************************************************
 Function: void tele_scan2(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	teleport scan collision check #2
******************************************************************************/
void tele_scan2(void)
{
	if ((current_proc->pa8)->oyvel.pos>=0)
		return;					// dont check while heading up

	tele_scan();

	return;
}

/******************************************************************************
 Function: void tele_scan(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	teleport scan collision check
******************************************************************************/
void tele_scan(void)
{
	if (current_proc->pdata.p_store1==0)
	{
		current_proc->pdata.p_action=ACT_ROBO_TELE_SD;

		if (strike_check_a0(current_proc->pa8,0x13)==SYSTEM_CARRY_SET)
		{
			current_proc->pdata.p_store2=f_block;
			current_proc->pdata.p_store1=1;
		}
	}

	return;
}



/******************************************************************************
 Function: void prop_kano_cannon_ball(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	kano special move cannon ball roll
******************************************************************************/
void prop_kano_cannon_ball(void)
{
	int loop;

	OBJECT *obj=current_proc->pa8;

	init_special(obj);

	local_ochar_sound(4);

	set_noflip(obj);

	current_proc->pdata.p_action=ACT_KANO_ROLL;

	towards_x_vel(current_proc,obj,SCX(0xa0000));

	multi_adjust_xy(obj,SCX(0),SCY(0x10));				// lower me a bit

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	((ADDRESS*)current_proc->pa9)++;							// ball roll ani

	init_anirate(3);

	loop=0x1a;					// spin count
	/* kroll5 */
	do
	{
		process_sleep(1);
		if (loop<=(0x1a-6)) 		// dont scan on first 6 tixs
		{
			if (strike_check_a0(obj,0x13)==SYSTEM_CARRY_SET)
				kroll_hit(obj);
		}

		/* kroll4 */
		next_anirate();
	}
	while(--loop>0);

	stop_me(obj);
	ground_player(obj);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void kroll_hit(OBJECT *obj)

 By: David Schwartz

 Date: Nov 1994

 Parameters: obj - kano dude

 Returns: None

 Description:	kano special move cannon ball roll hit other routine
******************************************************************************/
void kroll_hit(OBJECT *obj)
{
	current_proc->pdata.p_action=ACT_KROLL_SD;		// sitting duck mode

	hit_or_blocked_sound(6,7);

	//get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	//GET_LONG(current_proc->pa9)++;

	if (f_block==0)
		flight(obj,SCX(0x50000),-SCY(0x80000),SCY(0x6000),2,-1);
	else flight(obj,SCX(0x10000),-SCY(0x80000),SCY(0x6000),2,-1);

	jump_up_land_jsrp();
	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_ind_charge(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	indian special charge move
******************************************************************************/
void prop_ind_charge(void) 
{
	ind_charge(0);
}

void prop_ind_charge_fast(void) 
{
	ind_charge(1);
}

void ind_charge(int speed)
{
	OBJECT *obj=current_proc->pa8;
	int loop;

	init_special_act(ACT_IND_CHARGE,obj);

	get_char_ani(ANIM_TABLE2,ANIM_IND_CHARGE);

	local_ochar_sound(8);

	create_fx(FX_TRAIL)->a11=speed;
	clear_shadow_bit(obj);			// no shadow during charge

	towards_x_vel(current_proc,obj,1);			// just so we are not exactly "0"

	do_next_a9_frame(obj);
	process_sleep(2);

	do_next_a9_frame(obj);
	process_sleep(2);

	towards_x_vel(current_proc,obj,(speed==0)?SCX(0x90000):SCX(0xb4000));
	do_next_a9_frame(obj);

	loop=(speed==0)?20:24;
	do
	{
		process_sleep(1);
		if (strike_check_a0(obj,(speed==0)?0x11:0x16)==SYSTEM_CARRY_SET)
			icharge_hit(obj);
	}
	while(--loop>0);

	reaction_exit(obj);

}

/******************************************************************************
 Function: void icharge_hit(OBJECT *obj)

 By: David Schwartz

 Date: Dec 1994

 Parameters: obj - dude who has hit

 Returns: None

 Description:	indian charge hit
******************************************************************************/
void icharge_hit(OBJECT *obj)
{
	stop_me(obj);
	current_proc->pdata.p_action=ACT_ICHARGE_SD;

	process_sleep(0x10);

	find_ani2_part2(ANIM_IND_CHARGE);

	mframew(3);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_jax_dash_punch(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	jax special move dash punch
******************************************************************************/
void prop_jax_dash_punch(void)
{
	OBJECT *obj=current_proc->pa8;
	int loop;

	init_special_act(ACT_JAX_DASH,obj);
	local_ochar_sound(3);

	get_char_ani(ANIM_TABLE2,ANIM_JAX_DASHP);
	current_proc->a10=(ADDRESS)current_proc->pa9;

	animate_a0_frames(0x0003,0x0002);

	towards_x_vel(current_proc,obj,SCX(0xa0000));

	do_next_a9_frame(obj);

	loop=8;
	/* dash2 */
	do
	{
		process_sleep(1);
		if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)
			dash_hit(obj);
	}
	while(--loop>0);

	current_proc->pdata.p_store1=(LONG)obj->oxvel.pos;			// save vel

	/* slow down */

	loop=0x10;
	/* dash3 */
	do
	{
		process_sleep(1);

		(long)current_proc->a0=(obj->oxvel.pos);
		(long)current_proc->a6=(obj->oxvel.pos)>>31;
		(long)current_proc->a5=((long)current_proc->pdata.p_store1)>>31;

		if (current_proc->a5!=current_proc->a6)
			current_proc->a0=0;

		set_x_vel(obj,((long)current_proc->a0)-(((long)current_proc->a0)>>5));

		if (loop<5) 
		{
			/* dash4 */
			current_proc->pdata.p_action=ACT_JAXDASH_SD;
		}
		else
		{
			if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)
				dash_hit(obj);
		}
	}
	while(--loop>0);

	dash_unblur(obj);

}

/******************************************************************************
 Function: void dash_hit(OBJECT *obj)

 By: David Schwartz

 Date: Nov 1994

 Parameters: obj - dude who has hit

 Returns: None

 Description:	slow down a dude
******************************************************************************/
void dash_hit(OBJECT *obj)
{
	if (f_block==0)
	{
		if (abs(obj->oxvel.pos)>SCX(0x40000))
			towards_x_vel(current_proc,obj,SCX(0x40000));		// max speed after hit

		/* dash6 */
		f_norepell=0x20;				// allow us to overlap
		process_sleep(4);
	}
	else
	{
		/* dash_blocked */
		current_proc->pdata.p_action=ACT_ICHARGE_SD;
		stop_me(obj);
		process_sleep(4);
	}

	dash_unblur(obj);
}

/******************************************************************************
 Function: void dash_unblur(OBJECT *obj)

 By: David Schwartz

 Date: Jan 1995

 Parameters: obj - jax

 Returns: None

 Description:	unblur the dashing jax
******************************************************************************/
void dash_unblur(OBJECT *obj)
{
	current_proc->pdata.p_action=ACT_ICHARGE_SD;
	find_ani2_part2(ANIM_JAX_DASHP);
	mframew(5);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_sonya_bike_kick(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	Sonya special bike kick move
******************************************************************************/
void prop_sonya_bike_kick(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SBIKE,obj);

	local_ochar_sound(3);			// bike fx
	local_ochar_sound(5);			// bike speech

	animate2_a9(0x0002,ANIM_SONYA_BIKE);		// intro part

	init_anirate(4);

	towards_x_vel(current_proc,obj,SCX(0x40000));

	obj->oyvel.pos=-SCY(0x20000);

	obj->ograv.pos=-SCY(0xc000);				// negative gravity

	set_nocol(obj);				// now this is power

	/* bike 3 */
	do
	{
		process_sleep(1);

		sans_repell_3();

		if (get_his_action(current_proc)!=ACT_DUCK && get_his_action(current_proc)!=ACT_BLOCKLO)		// he is ducked = no collision check
		{
			if (strike_check_a0(obj,0x14)==SYSTEM_CARRY_SET)
				bike_hit(obj);
		};

		/* bike4 */
		next_anirate();
	}
	while(distance_from_ground(obj)<SCY(0xc0));

	/* miss */
	current_proc->pdata.p_action=ACT_SBIKE_SD;
	clear_nocol(obj);

	(ADDRESS *)current_proc->a6=(ADDRESS *)(bike_scan_call);
	flight_call(obj,DONT_TOUCH,DONT_TOUCH,SCY(0xa000),4,-1);			// leave animation only, so no offset

	reaction_exit(obj);
}

/******************************************************************************
 Function: void bike_hit(OBJECT *obj)

 By: David Schwartz

 Date: Nov 1994

 Parameters: obj - sonya hit object

 Returns: None

 Description:	Sonya bike hit
******************************************************************************/
void bike_hit(OBJECT *obj)
{
	ADDRESS animtemp;
	int loop;

	current_proc->pdata.p_action=ACT_SBIKE_SD;

	/* calla_for_him */
	clear_inviso(current_proc->pdata.p_otherguy);


	if (f_block!=0)
	{
		/* bike blocked */
		flight(obj,SCX(0),-SCY(0x60000),SCY(0x8000),4,-1);
		jump_up_land_jsrp();
		reaction_exit(obj);
	}
	else
	{
		shake_a11(0x0003,0x0030);			// start a long shake

		animtemp=(ADDRESS)current_proc->pa9;

		get_his_a11_ani(ANIM_STUMBLE);			// current_proc->a10=otherguy

		(ADDRESS)current_proc->pa9=current_proc->a11;
		find_part2();							// his ani = repeating stumble

		current_proc->a11=(ADDRESS)current_proc->pa9;
		(ADDRESS)current_proc->pa9=animtemp;
			
		double_next_a9();
		
	   	//xfer_him_to_flipped_pause(ACT_BIKE);
		xfer_him_to_flipped_pause(0);
		inc_his_p_hit();

		stop_me(obj);
		stop_him(current_proc->pdata.p_otherguy);

		init_anirate(4);

		current_proc->pdata.p_store2=1;

		towards_x_vel(current_proc,obj,SCX(0x30000));

		obj->oyvel.pos=-SCY(0x30000);
		((OBJECT *)current_proc->a10)->oyvel.pos=-SCY(0x30000);

		/* bike6 */
		loop=0x20;
		do
		{
			process_sleep(1);

			if ((current_proc->pdata.p_otherproc)->pdata.p_flags & PM_CORPSE)		
				goto BIKE_ABORT;
			
			bike_hit_call(obj);
			if (distance_from_ground(obj)>SCY(0xe0))
				break;
		}
		while(--loop>0);

		/* bike8 */
		towards_x_vel(current_proc,obj,SCX(0x10000));
		obj->oyvel.pos=SCY(0x8000);
		((OBJECT *)current_proc->a10)->oyvel.pos=SCY(0x8000);

		/* bike7 */
		loop=0x10;
		do
		{
			process_sleep(1);
			bike_hit_call(obj);
		}
		while(--loop>0);

		/* release the other guy */
		dallprc(PID_SHAKER);

		xfer_him_to_a10_r(R_A10_BIKE);

		set_his_p_action(current_proc,ACT_SBIKE_KICKED);

BIKE_ABORT:
		get_char_ani(ANIM_TABLE2,ANIM_SONYA_BIKE);

		find_part_a14(3);

		mframew(4);					// get out of bike kick

		/* and land */
		pose_a9(0x0001,ANIM_JUMPUP);
		face_opponent(obj);
		flight(obj,SCX(0),SCY(0x20000),SCY(0x8000),NEVER_ANI,-1);

		jump_up_land_jsrp();
		reaction_exit(obj);
	}

	reaction_exit(obj);
}

/******************************************************************************
 Function: void bike_scan_call(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	call when sonya doing bike kick
******************************************************************************/
void bike_scan_call(void)
{
	f_norepell=3;
	return;
}

/******************************************************************************
 Function: void bike_hit_call(OBJECT *obj)

 By: David Schwartz

 Date: Nov 1994

 Parameters: obj - dudes object

 Returns: None

 Description:	check for hit with sonyas bike kick
******************************************************************************/
void bike_hit_call(OBJECT *obj)
{
	ADDRESS animtemp;

	f_norepell=3;

	if (--current_proc->pdata.p_store2==0)
	{
		rsnd_smack();
		current_proc->pdata.p_store2=7;
	}

	/* bike9 */
	match_him_with_me_f();

	adjust_him_a0(0xffe0ffd0);

	((OBJECT *)current_proc->a10)->ograv.pos=obj->ograv.pos;
	((OBJECT *)current_proc->a10)->oxvel.pos=obj->oxvel.pos;
	((OBJECT *)current_proc->a10)->oyvel.pos=obj->oyvel.pos;

	animtemp=(ADDRESS)current_proc->pa9;
	next_anirate();

	if (animtemp!=(ADDRESS)current_proc->pa9)
		advance_him();

	return;
}

/******************************************************************************
 Function: void prop_do_sz_decoy(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	subzero decoy
******************************************************************************/
void prop_do_sz_decoy(void)
{
	OBJECT *obj=current_proc->pa8;
	PROCESS *ptemp;

	air_init_special(obj);

	current_proc->pdata.p_action=ACT_SZ_DECOY;

	update_tsl(l_sz_decoy,obj);

	ptemp=CREATE(p1p2_pick(current_proc->pa8,PID_DECOY1,PID_DECOY2),decoy_proc);
	ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	ptemp->pdata.p_otherproc=current_proc->pdata.p_otherproc;

	(long)ptemp->a11=get_x_dist;

	local_ochar_sound(4+0x13);

	get_char_ani(ANIM_TABLE1,ANIM_BFLIP);
	((ADDRESS*)current_proc->pa9)++;			// backward flip ani

	flight(obj,SCX(0x60000),-SCY(0x60000),ANGLE_GRAV,3,-1);

	/* replace with generic land routine */
	current_proc->pdata.p_action=ACT_LAND;		// action: landing

	face_opponent(obj);

	get_char_ani(ANIM_TABLE1,ANIM_FFLIP);
	do_next_a9_frame(obj);
	process_sleep(3);					// allow moves during this sleep (ejbpatch)

	reaction_exit(obj);
}

/******************************************************************************
 Function: void decoy_proc(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	subzero decoy process
******************************************************************************/
void decoy_proc(void)
{
	short loop;

	OBJECT *obj=current_proc->pa8;
	OBJECT *obj_decoy;
	PROCESS *ptemp;

	if ((long)current_proc->a11<SCX(0x50)) 
	{
		/* decoy_dude */
		create_fx(FX_FREEZE_BLAST);
		process_suicide();
	}

	current_proc->pdata.p_store1=obj->oid;

	current_proc->a10=(ADDRESS)current_proc->pa9;		// save where I was
	get_char_ani(ANIM_TABLE1,ANIM_STANCE);				// get stance ani to make new obj
	(OBJECT *)current_proc->a11=current_proc->pa8;		// a11 = orig subzero
	ptemp=gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);									// a8 = decoy object
	obj_decoy=current_proc->pa8;
	(PROCESS *)(current_proc->pdata.p_store3)=ptemp;

	match_ani_points(obj,obj_decoy);			// lineup with sz

	obj_decoy->oflags=obj->oflags & (~M_FIGHTER);
	obj_decoy->ochar=obj->ochar;
	animate2(obj_decoy,obj->oshape);

	player_froze_pal();
	insert_object(obj_decoy,&objlst);
	ptemp=create_fx(FX_FREEZE_BLAST);

	current_proc->a10=10;
	/* decoy2 */
	do
	{
		multi_adjust_xy(obj_decoy,-SCX(0x4),SCY(0));
		process_sleep(1);
	}
	while(--current_proc->a10>0);

	/* decoy collision check */
	if (q_is_he_a_boss()==SYSTEM_CARRY_SET)
		stack_jump(decoy9);

	loop=(is_he_joy()==SYSTEM_CARRY_SET)?0x2a:0x20;		// vs joy==longer, vs drone == shorter
	/* decoy3 */
	do
	{
		process_sleep(1);
		if (decoy_collision_check()==SYSTEM_CARRY_SET)
			stack_jump(decoy9);
	}
	while(--loop>0);

	shake_collision_check(6);

	stack_jump(decoy9);
}

/******************************************************************************
 Function: void decoy9(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	subzero decoy process terminate routine
******************************************************************************/
void decoy9(void)
{
	local_ochar_sound(4+0x13);

	create_fx(FX_FREEZE_BLAST);
	process_sleep(3);

	process_kill((PROCESS *)(current_proc->pdata.p_store3));
	delobjp(current_proc->pa8);

	process_suicide();
}

/******************************************************************************
 Function: void shake_collision_check(short loop)

 By: David Schwartz

 Date: Jan 1995

 Parameters: loop - # of times to execute

 Returns: None

 Description:	shake decoy and perform collision
******************************************************************************/
void shake_collision_check(short loop)
{
	short loop1;
	OBJECT *obj=current_proc->pa8;

	do
	{
		obj->oxpos.u.intpos+=3;

		loop1=3;
		/* sac4 */
		do
		{
			process_sleep(1);
			if (decoy_collision_check()==SYSTEM_CARRY_SET)
				decoy9();
		}
		while(--loop1>0);

		obj->oxpos.u.intpos-=3;

		loop1=3;
		/* sac5 */
		do
		{
			process_sleep(1);
			if (decoy_collision_check()==SYSTEM_CARRY_SET)
				decoy9();
		}
		while(--loop1>0);
	}
	while(--loop>0);

	return;
}

/******************************************************************************
 Function: WORD decoy_collision_check(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: SYSTEM_CARRY_SET - collision occured
		  SYSTEM_CARRY_CLR - no collision occured

 Description:	collision routine for decoy, determines if collision and sets other guy reaction if hit
******************************************************************************/
WORD decoy_collision_check(void)
{
	XYTYPE tl_attack,lr_attack;					// attackers box pos
	XYTYPE tl_defend,lr_defend;					// defenders box pos
	short temp;

	f_block=0;									// set block flag

	if (is_he_blocking((WORD *)(&temp),0)==SYSTEM_CARRY_SET || is_jade_protected()==SYSTEM_CARRY_SET)
		return(SYSTEM_CARRY_CLR);

	/* setup attack collision box */
	tl_attack.u.ypos=highest_mpart(current_proc->pa8);
	lr_attack.u.ypos=lowest_mpart(current_proc->pa8);
	tl_attack.u.xpos=leftmost_mpart(current_proc->pa8);
	lr_attack.u.xpos=rightmost_mpart(current_proc->pa8);

	/* squeeze left and right */
	temp=abs(tl_attack.u.xpos-lr_attack.u.xpos);
	temp=(temp>>3)+(temp>>2);
	tl_attack.u.xpos+=temp;				// dudes left collision x
	lr_attack.u.xpos-=temp;				// dudes right collision x

	/* squeeze top and bottom */
	temp=abs(tl_attack.u.ypos-lr_attack.u.ypos);
	temp=(temp>>3)+(temp>>2);
	tl_attack.u.ypos+=temp;				// dudes top collision y
	lr_attack.u.ypos-=temp;				// dudes top collision y


#if COLLISION_BOX
	attack_box(&tl_attack,&lr_attack);
#endif

	/* setup defend collision box */
	tl_defend.u.ypos=highest_mpart(current_proc->pdata.p_otherguy);
	lr_defend.u.ypos=lowest_mpart(current_proc->pdata.p_otherguy);
	tl_defend.u.xpos=leftmost_mpart(current_proc->pdata.p_otherguy);
	lr_defend.u.xpos=rightmost_mpart(current_proc->pdata.p_otherguy);


#if COLLISION_BOX
	victim_box(&tl_defend,&lr_defend);
#endif

	/* perform collision detection */
	if (tl_attack.u.xpos>lr_defend.u.xpos ||
		tl_attack.u.ypos>lr_defend.u.ypos ||
		lr_attack.u.xpos<tl_defend.u.xpos ||
		lr_attack.u.ypos<tl_defend.u.ypos)
		return(SYSTEM_CARRY_CLR);						// no collision
	else
	{
		disable_his_buttons;
		xfer_otherguy(r_decoy_freeze);
		return(SYSTEM_CARRY_SET);
	}
}

/******************************************************************************
 Function: void teleport_next_to(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	teleport next to the otherdude
******************************************************************************/
void teleport_next_to(void)
{
	short xpos=SCX(0x54);			// pos = in front
	short oxpos;

	oxpos=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;

	if (abs(right_edge+SCRRGT-oxpos)>SCX(0x80))
	{
		if (abs(left_edge-oxpos)>SCX(0x080))
			xpos=-xpos;
	}

	/* tnt4 */
	match_me_with_him();

	multi_adjust_xy(current_proc->pa8,xpos,0);

	return;
}


/******************************************************************************
 Function: void prop_do_lia_fly(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lia hover fly
******************************************************************************/
void prop_do_lia_fly(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_HOVER,obj);

	get_char_ani(ANIM_TABLE2,ANIM_LIA_FLY_UP);

	set_ignore_y(obj);			// don't scroll up and follow me

	set_float_ani(0);

	/* initial up */
	local_ochar_sound(5);

	obj->ograv.pos=-SCY(0x6000);			// init upwards accel
	(long)current_proc->a10=SCY(0x60000);	// max speed (a10)
	current_proc->a11=SCX(0xd0);

	/* hover0 */
	do
	{
		hover_sleep_1(obj);
	}
	while(distance_from_ground(obj)<SCY(0xc0));

	back_to_normal();
	current_proc->pdata.p_action=ACT_HOVER;

	set_float_ani(0);
	find_part2();

	obj->ograv.pos=SCY(0x5000);			// down
	settle_down(obj);

	main_hover_loop();
}

/******************************************************************************
 Function: void prop_do_lia_stay_afloat(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lia hover stay afloat
******************************************************************************/
void prop_do_lia_stay_afloat(void)
{
	OBJECT *obj=current_proc->pa8;

	air_init_special(obj);

	get_char_ani(ANIM_TABLE2,ANIM_LIA_FLY_UP);
	find_part2();
	((ADDRESS *)(current_proc->pa9))+=6;

	back_to_normal();

	current_proc->pdata.p_action=ACT_HOVER;

	main_hover_loop();
}

/******************************************************************************
 Function: void main_hover_loop(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lia hover main loop
******************************************************************************/
void main_hover_loop(void)
{
	OBJECT *obj=current_proc->pa8;

	/* MAIN_HOVER_LOOP */
	while (TRUE)
	{
		current_proc->a5=(long)distance_from_ground(obj);

		/* left / right movement */
		if (is_stick_right(current_proc)==SYSTEM_CARRY_SET)
		{
			accelerate_x(obj,((long)current_proc->a11=SCX(0x8000)));			// stick left ---> accelerate left
			flight_move_ani(obj);
			goto XDAMP9;
		}

		/* hover2 */
		if (is_stick_left(current_proc)==SYSTEM_CARRY_SET)
		{
			accelerate_x(obj,((long)current_proc->a11=-SCX(0x8000)));			// stick right ---> accelerate right
			flight_move_ani(obj);
			goto XDAMP9;
		}

		/* xdamp1 */
		if (obj->oxvel.pos!=0)
		{
			(long)current_proc->a1=obj->oxvel.pos>>4;

			if ((long)current_proc->a1==0 || (long)current_proc->a1==-1)
				set_x_vel(obj,0);			// case damp to small, so stop
			else set_x_vel(obj,(obj->oxvel.pos-(long)current_proc->a1));
		}

		/* xdamp7 */
		switch (current_proc->pdata.p_store3)
		{
			case 1:
				set_float_ani(3);			// charge forward ---> uncharge
				break;
			case 2:
				set_float_ani(4);			// backoff --> unbackoff
				break;
			default:	// 0,3
				break;
		}

XDAMP9:
		(long)current_proc->a6=SCY(0x4000);		// stick not up gravity
		if (is_stick_up(current_proc)==SYSTEM_CARRY_CLR)
		{
			/* hover3, heading down -->pull up */
			if ((long)current_proc->a5>SCY(0xd5))
			{
				/* hover5 */
				if ((long)current_proc->a5<SCY(0xd8))
					goto HOVERS;
				else
				{
					(long)current_proc->a6=SCY(0x2000);
				}
			}
			else
			{
				(long)current_proc->a6=-SCY(0x3000);

			}
		}
		else
		{
			/* stick = up */
			(long)current_proc->a6=((long)current_proc->a5<=SCY(0xe0)) ? -SCY(0xc000):SCY(0x2000);
		}

		/* hoverd */
		obj->ograv.pos=(long)current_proc->a6;

		if (obj->oyvel.pos>SCY(0x30000))
			obj->oyvel.pos=SCY(0x30000);

		if (obj->oyvel.pos<-SCY(0x30000))
			obj->oyvel.pos=-SCY(0x30000);

HOVERS:
		hover_sleep_1(obj);
	}
}

/******************************************************************************
 Function: void settle_down(OBJECT *obj)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	wait until move down into position
******************************************************************************/
void settle_down(OBJECT *obj)
{
	do
	{
		do
		{
			hover_sleep_1(obj);
		}
		while(obj->oyvel.pos<0);
	}
	while(distance_from_ground(obj)>SCY(0xe0));

	obj->ograv.pos=-SCY(0x6000);
	/* settle3 */
	do
	{
		hover_sleep_1(obj);
	}
	while(abs(obj->oyvel.pos)>SCY(0x10000));

	return;
}

/******************************************************************************
 Function: void flight_move_ani(OBJECT *obj)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	flight movement
******************************************************************************/
void flight_move_ani(OBJECT *obj)
{
	if (abs(obj->oxvel.pos)<=SCX(0x60000)) 	// slow ---> dont change ani
		return;

	if (current_proc->pdata.p_store3==1 || current_proc->pdata.p_store3==2)
		return;								// already using ani ---> skip

	current_proc->a0=1;				// 1 - charge forward

	if ((long)current_proc->a11<0)
	{
		if (is_he_left(current_proc)==SYSTEM_CARRY_CLR)
			current_proc->a0=2;		// 2 - backoff
	}
	else
	{
		if (is_he_right(current_proc)==SYSTEM_CARRY_CLR)
			current_proc->a0=2;		// 2 - backoff
	}

	face_opponent(obj);

	set_float_ani(current_proc->a0);

	return;
}

/******************************************************************************
 Function: void accelerate_x(OBJECT *obj,long accel)

 By: David Schwartz

 Date: Jan 1995

 Parameters: obj - dude to accel
			 accel - amount to accel

 Returns: None

 Description:	accel x
******************************************************************************/
void accelerate_x(OBJECT *obj,long accel)
{
	long vel;

	vel=obj->oxvel.pos+accel;

	if (vel<-SCX(0x80000))
	{
		vel=-SCX(0x80000);
	}
	else
	{
		if (vel>SCX(0x80000))
			vel=SCX(0x80000);
	}

	set_x_vel(obj,vel);

	return;
}

/******************************************************************************
 Function: void hover_sleep_1(OBJECT *obj)

 By: David Schwartz

 Date: Jan 1995

 Parameters: obj - dude to sleep

 Returns: None

 Description:	hover in air and sleep on it
******************************************************************************/
void hover_sleep_1(OBJECT *obj)
{
	f_norepell=2;			// dont repell us during this

	process_sleep(1);
	next_anirate();

	if (check_block_bit()==SYSTEM_CARRY_SET)
		hover_land(obj);

	return;
}

WORD float_ani_speeds[] =
{
	6,			// 0 - up
	3,			// 1 - forward
	3,			// 2 - back
	3,			// 3 - unforward
	3			// 4 - unbackoff
};

/******************************************************************************
 Function: void set_float_ani(WORD offset)

 By: David Schwartz

 Date: Jan 1995

 Parameters: offset - offset of which ani to execute

 Returns: None

 Description:	set animation info
******************************************************************************/
void set_float_ani(WORD offset)
{

	current_proc->pdata.p_store3=offset;

	get_char_ani(ANIM_TABLE2,offset+2);

	init_anirate(float_ani_speeds[offset]);

	return;
}

/******************************************************************************
 Function: void hover_land(OBJECT *obj)

 By: David Schwartz

 Date: Jan 1995

 Parameters: obj - dude to lamd

 Returns: None

 Description:	land on ground from hover
******************************************************************************/
void hover_land(OBJECT *obj)
{
	set_float_ani(0);
	face_opponent(obj);

	flight(obj,DONT_TOUCH,DONT_TOUCH,SCY(0xa000),4,-1);

	clear_ignore_y(obj);			// allow scroll up and follow me

	stack_jump(jump_up_land_jump);
}

/******************************************************************************
 Function: void new_float_ani(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	set a new float animation (called from animation)
******************************************************************************/
void new_float_ani(void)
{
	current_proc->pdata.p_store3=0;
	current_proc->pdata.p_anirate=6;
	return;
}

/******************************************************************************
 Function: void prop_do_sonya_square_wave(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	do sonya's square wave
******************************************************************************/
void prop_do_sonya_square_wave(void)
{
	int loop;

	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SQUARE,obj);

	local_ochar_sound(4);				// sonya fly sound

	find_ani_last_frame(ANIM_JUMPUP);
	do_next_a9_frame(obj);
	obj->oyvel.pos=-SCY(0xc0000);				// head straight up!!

	/* lfly5 */
	do
	{
		process_sleep(1);
	}
	while(distance_off_ground(current_proc,obj)<SCY(0x60));

	/* horizontal punch */

	group_sound(0);

	obj->oyvel.pos=0;
	get_char_ani(ANIM_TABLE2,ANIM_SONYA_SWAVE);
	init_anirate(3);

	towards_x_vel(current_proc,obj,SCX(0xa0000));		// head towards opponent
	face_opponent(obj);

	/* lfly4 */
	loop=0x1a;
	do
	{
		process_sleep(1);
		next_anirate();

		if (strike_check_a0(obj,0x11)==SYSTEM_CARRY_SET)
		{
			/* liz_fly_hit */
			stop_me(obj);
			pose_a9(0x0002,ANIM_FLIPPUNCH);
			process_sleep(0x0a);

			away_x_vel(current_proc,obj,SCX(0x20000));
			loop=1;							// exit from loop
		}
	}
	while(--loop>0);

	/* square3 */
	pose_a9(0x0001,ANIM_JUMPUP);
	face_opponent(obj);

	flight(obj,SCX(0),SCY(0x20000),SCY(0x8000),NEVER_ANI,-1);

	jump_up_land_jsrp();
	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_do_slide(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	subzero slide
******************************************************************************/
void prop_do_slide(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SLIDE,obj);

	towards_x_vel(current_proc,obj,(obj->ochar==FT_OLDSZ)?SCX(0xb0000):SCX(0x80000));		// head towards opponent

	get_char_ani(ANIM_TABLE2,ANIM_REP_SLIDE);
	init_anirate(4);

	local_ochar_sound(6);			// slide sound

	/* first part of slide, no collision check */
	current_proc->a10=0x1c;
	do
	{
		process_sleep(1);
		next_anirate();

		if (current_proc->a10<=0x14)
		{
			if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)
			{
				/* slide_hit */
				if (f_block)
					break;

				pose2_a9(2,ANIM_REP_SLIDE);
				set_x_vel(obj,obj->oxvel.pos>>1);
				process_sleep(3);
				stop_me(obj);
				wait_for_landing();
				slide_is_over(obj);
			}
		}
	}
	while(--current_proc->a10>0);

	/* slide_blocked */
	stop_me(obj);
	clear_noflip(obj);
	set_no_block(obj);
	current_proc->pdata.p_action=ACT_SLIDE_SD;
	process_sleep(0x16);

	slide_is_over(obj);
}

/******************************************************************************
 Function: void slide_is_over(OBJECT *obj)

 By: David Schwartz

 Date: Feb 1995

 Parameters: obj - object

 Returns: None

 Description:	subzero slide is over
******************************************************************************/
void slide_is_over(OBJECT *obj)
{
	pose2_a9(1,ANIM_REP_SLIDE);
	process_sleep(4);
	pose2_a9(0,ANIM_REP_SLIDE);
	process_sleep(4);

	update_tsl(l_slide,obj);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_do_sg_quake(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	she goro quake
******************************************************************************/
void prop_do_sg_quake(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SG_QUAKE,obj);

	get_char_ani(ANIM_TABLE2,ANIM_SG_POUNCE);
	flight(obj,SCX(0),-SCY(0xa0000),SCY(0xc000),2,-1);

	local_ochar_sound(1);
	shake_a11(0x0008,0x0008);

	current_proc->a11=0;

	if (is_he_airborn()==SYSTEM_CARRY_CLR && q_is_he_a_boss()==SYSTEM_CARRY_CLR) 	// on ground and not boss cause damage
	{
		damage_to_him(0x19,current_proc->pdata.p_otherguy);
		takeover_him(r_quake);
		current_proc->a11=1;			// flag: quake hit
	}

	/* quake3 */
	current_proc->pdata.p_action=ACT_SG_QUAKE;
	get_char_ani(ANIM_TABLE2,ANIM_SG_POUNCE);
	find_part2();
	mframew(3);

	if (current_proc->a11==1)
		process_sleep(0x10);		// hit = faster wake
	else process_sleep(0x1c);

	do_next_a9_frame(obj);
	process_sleep(4);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void prop_do_sg_pounce(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	she goro pounce
******************************************************************************/
void prop_do_sg_pounce(void)
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SG_POUNCE,obj);

	local_ochar_sound(0);				// teleport sound

	get_char_ani(ANIM_TABLE2,ANIM_SG_POUNCE);
	do_next_a9_frame(obj);

	(long)current_proc->a11=(current_proc->pdata.p_otherguy)->oxpos.pos;		// save his x

	obj->oyvel.pos=-SCY(0x80000);
	obj->ograv.pos=-SCY(0x10000);			// neg gravity

	/* sgt4 */
	do
	{
		process_sleep(1);
	}
	while(distance_off_ground(current_proc,obj)<SCY(0xe8));

	obj->oxpos.pos=(long)current_proc->a11;				// where he was when I took off

	get_char_ani(ANIM_TABLE2,ANIM_SG_POUNCE);
	((ADDRESS *)current_proc->pa9)+=2;

	current_proc->a6=(ADDRESS)pounce_scan;
	flight_call(obj,0,SCY(0x60000),SCY(0x8000),2,-1);

	/* POUNCE_FALL, code copied in pounce_hit!!! */
	blur_catchup(obj);

	if (get_his_action(current_proc)!=ACT_POUNCE)
	{
		/* pounce_miss, copied in pounce_hit */
		current_proc->pdata.p_action=ACT_SG_POUNCE;
		set_no_block(obj);
		process_sleep(0xc);
		do_next_a9_frame(obj);
		process_sleep(4);
		if (q_is_he_a_boss()==SYSTEM_CARRY_SET)
			process_sleep(8);
		reaction_exit(obj);
	}

	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);

	set_ignore_y(obj);
	pounce_ground_him(obj);

	pounce_jsrp(0,r_pounce2);
	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);

	pounce_jsrp(edge_pick_a0(SCX(0x60000)),NULL);
	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void pounce_jsrp(long pa0,FUNC pa11)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa0 - x vel
			 pa11 - react routine

 Returns: None

 Description:	pounce subroutine
******************************************************************************/
void pounce_jsrp(long pa0,FUNC pa11)
{
	OBJECT *obj=current_proc->pa8;

	shake_a11(0x0008,0x0008);
	do_next_a9_frame(obj);
	set_x_vel(obj,pa0);

	flight(obj,DONT_TOUCH,-SCY(0xa0000),SCY(0xc000),2,-1);

	if (pa11!=NULL)
		xfer_otherguy(pa11);

	blur_catchup(obj);
}

/******************************************************************************
 Function: void blur_catchup(OBJECT *obj)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa0 - x vel
			 pa11 - react routine

 Returns: None

 Description:	pounce subroutine
******************************************************************************/
void blur_catchup(OBJECT *obj)
{
	local_ochar_sound(1);				// ground shake
	shake_a11(0x0007,0x0004);

	f_norepell=0x12;
	get_char_ani(ANIM_TABLE2,ANIM_SG_POUNCE);
	find_part2();
	mframew(3);
//	do_next_a9_frame(obj);
//	process_sleep(4);
	return;
}

/******************************************************************************
 Function: void pounce_scan(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	pounce scan routine
******************************************************************************/
void pounce_scan(void)
{
	OBJECT *obj=current_proc->pa8;

	sans_repell_3();

	if (q_is_he_a_boss()==SYSTEM_CARRY_SET)
		current_proc->a0=0x13;				// boss=blockable
	else current_proc->a0=0x12;				// nonboss=not blockable

	if (strike_check_a0(current_proc->pa8,current_proc->a0)==SYSTEM_CARRY_CLR)
		return;

	/* pounce_hit, pounce_fall */
	current_proc->a6=(ADDRESS)pounce_adjust_him;
	flight_call(obj,0,DONT_TOUCH,DONT_TOUCH,DONT_TOUCH,-1);

	/* pounce_fall, also in sg_pounce */
	blur_catchup(obj);

	if (get_his_action(current_proc)!=ACT_POUNCE)
	{
		/* pounce_miss, copied in pounce_hit */
		current_proc->pdata.p_action=ACT_SG_POUNCE;
		set_no_block(obj);
		process_sleep(0xc);
		do_next_a9_frame(obj);
		process_sleep(4);
		if (q_is_he_a_boss()==SYSTEM_CARRY_SET)
			process_sleep(8);
		reaction_exit(obj);
	}

	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);

	set_ignore_y(obj);
	pounce_ground_him(obj);

	f_norepell=10;
	pounce_jsrp(0,r_pounce2);
	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);

	f_norepell=10;
	pounce_jsrp(edge_pick_a0(SCX(0x60000)),NULL);
	do_next_a9_frame(obj);			// backup frame 5
	process_sleep(4);
	f_norepell=0;

	reaction_exit(obj);
}

/******************************************************************************
 Function: void pounce_adjust_him(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	pounce adjust dude after hit
******************************************************************************/
void pounce_adjust_him(void)
{
	if (is_he_airborn()==SYSTEM_CARRY_SET)
	{
		stop_him(current_proc->pdata.p_otherguy);
		match_him_with_me();
		adjust_him_xy(SCX(0),SCY(0x18));
	}
	else
	{
		pounce_ground_him(current_proc->pa8);
	}

	return;
}


/******************************************************************************
 Function: void pounce_ground_him(void);

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	pounce ground dude
******************************************************************************/
void pounce_ground_him(OBJECT *pa8)
{
	stop_him(current_proc->pdata.p_otherguy);
	(current_proc->pdata.p_otherguy)->oxpos.pos=(pa8)->oxpos.pos;
	/* ground_him */
	(current_proc->pdata.p_otherguy)->oypos.u.intpos=(current_proc->pdata.p_otherproc)->pdata.p_ganiy;
	return;
}

/******************************************************************************
 Function: void prop_do_super_kang(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	super liu kang
******************************************************************************/
void prop_do_super_kang(void)
{
	long ta3,ta1;

	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SUPERKANG,obj);
	local_ochar_sound(2);
	local_ochar_sound(5);			// scream

	towards_x_vel(current_proc,obj,SCX(0xa0000));

	ta3=get_x_dist-SCX(10);

	if (ta3<=0)
		ta3=1;				// no neg

	/* supfly3 */
	ta3<<=16;
	ta3/=SCX(10);				// a3=distaance/speed = time
	ta3>>=16;

	if (ta3<=0)
		ta3=1;				// no neg

	/* supfly1 */
	(long)current_proc->a11=ta3;
	ta1=SCY(0x200000)/ta3;			// dist we want to travel up

	if (ta1>SCY(0x40000))
		ta1=SCY(0x40000);				// dont spaz out

	/* supfly9 */
	obj->oyvel.pos=-ta1;

	get_char_ani(ANIM_TABLE2,ANIM_LK_SKANG);
	init_anirate(1);

	/* fly */

	current_proc->a10=8;

	/* supfly5 */
	do
	{
		process_sleep(1);

		if (--current_proc->a10==0)
		{
			current_proc->a10=1;				// do coll check for now on

			if (strike_check_a0(obj,0x13)==SYSTEM_CARRY_SET)
			{
				/* supfly7, collision=yes */
				current_proc->pdata.p_action=ACT_POSTATTACK;
				if (f_block)
				{
					/* superfly8, superkick blocked */
					current_proc->pdata.p_action=ACT_SUPERK_SD;
					super_kick_land(obj);
					get_char_ani(ANIM_TABLE1,ANIM_STANCE);
					do_next_a9_frame(obj);
					set_no_block(obj);
					process_sleep(10);
				}
				else
				{
					super_kick_land(obj);
				}

				reaction_exit(obj);
			}
		}

		/* supfly6 */
		next_anirate();
	}
	while(--current_proc->a11>0);

	/* collision = no */
	(ADDRESS *)current_proc->a6=NULL;
	flight_call(obj,DONT_TOUCH,DONT_TOUCH,SCY(0xa000),NEVER_ANI,-1);

	find_ani2_part2(ANIM_LK_SKANG);
	mframew(3);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void super_kick_land(OBJECT *obj)

 By: David Schwartz

 Date: Feb 1995

 Parameters: obj - lk

 Returns: None

 Description:	super liu kang land kick
******************************************************************************/
void super_kick_land(OBJECT *obj)
{
	current_proc->pdata.p_action=ACT_SUPERK_SD;
	stop_me(obj);
	process_sleep(20);		// i am in danger zone

	flight(obj,0,0,SCY(0xa000),NEVER_ANI,-1);

	find_ani2_part2(ANIM_LK_SKANG);
	mframew(3);

	return;
}

/******************************************************************************
 Function: void prop_do_lk_bike(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	liu kang bike kick
******************************************************************************/
void prop_do_lk_bike(void) 
{
	current_proc->a11=0;
	prop_do_lk_bike_code();
}

void prop_do_lk_sbike(void) 
{
	current_proc->a11=1;
	prop_do_lk_bike_code();
}

void prop_do_lk_bike_code(void)
{
	OBJECT *obj=current_proc->pa8;
	WORD ta11=current_proc->a11;
	long xvel;

	init_special_act(ACT_BIKE,obj);

	local_ochar_sound(4);
	if (ta11==1)
	{
		borrow_ochar_sound(0xf,FT_ERMAC);		// rumble sound
		create_fx(FX_TRAIL)->a11=0;
		away_x_vel(current_proc,obj,-SCX(0xb0000));
		xvel=-SCX(0xb0000);
	}
	else
	{
		away_x_vel(current_proc,obj,-SCX(0x90000));
		xvel=-SCX(0x90000);
	}

	current_proc->a10=ta11;
	current_proc->a6=(ADDRESS)bike_call;
	current_proc->a11=(ta11==0)?6:4;
	flight_call(obj,xvel,-SCY(0x38000),SCY(0x3000),4,0x00010002);

	reaction_exit(obj);
}

/******************************************************************************
 Function: void bike_call(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	liu kang bike kick
******************************************************************************/
void bike_call(void)
{
	OBJECT *obj=current_proc->pa8;
	void *ta9;

	if (current_proc->a11!=0)
	{
		current_proc->a11--;
		return;
	}

	/* bcall3 */
	if (strike_check_a0(obj,(current_proc->a10==0)?0x12:0x14)==SYSTEM_CARRY_CLR)
		return;

	stop_me(obj);

	lights_on_hit();

	if (f_block)
	{
		/* bike_sitting_duck */
		current_proc->pdata.p_action=ACT_LK_BIKE_SD;

		((ADDRESS *)current_proc->pa9)++;
		flight(obj,SCX(0x10000),-SCY(0x50000),SCY(0x4000),4,0x00010002);
		jump_up_land_jump();
	}

	/* liu kang bike: HIT */
	update_his_hit_queue(ACT_BIKE);

	clear_inviso(current_proc->pdata.p_otherguy);

	takeover_him(biked_suspend);

	if (is_he_facing_me()==SYSTEM_CARRY_CLR)
		flip_multi(current_proc->pdata.p_otherguy);

	/* lkbike0 */
	if (is_he_airborn()==SYSTEM_CARRY_SET)
	{
		/* hit in air */
		if (get_x_dist<=SCX(0x30))
		{
			current_proc->a10=(ADDRESS)current_proc->pdata.p_otherguy;
			current_proc->a7=((OBJECT *)current_proc->a10)->oypos.pos;
			match_him_with_me_f();
			((OBJECT *)current_proc->a10)->oypos.pos=current_proc->a7;

			/* lkbike2 */
			adjust_him_x(-SCX(0x20));
		}
	}
	else
	{
		/* lkbike1 */
		match_him_with_me_f();

		/* ground_him */
		(current_proc->pdata.p_otherguy)->oypos.u.intpos=(current_proc->pdata.p_otherproc)->pdata.p_ganiy;

		/* lkbike2 */
		adjust_him_x(-SCX(0x20));
	}

	/* lkbike3 */
	(ADDRESS)current_proc->pa9=get_his_char_ani(ANIM_TABLE1,ANIM_STUMBLE);
	find_part2();
	current_proc->a11=(ADDRESS)current_proc->pa9;

	away_x_vel(current_proc,obj,-SCX(0x50000));

	/* away_x_vel_him */
	away_x_vel(current_proc->pdata.p_otherproc,current_proc->pdata.p_otherguy,SCX(0x50000));

	process_sleep(1);

	/* punching bag animation loop */
	(OBJECT *)current_proc->a10=current_proc->pdata.p_otherguy;
	get_char_ani(ANIM_TABLE2,ANIM_LK_BIKE);
	init_anirate(3);

	current_proc->pdata.p_store2=8;

	current_proc->pdata.p_store1=48;
	/* lkbike4 */
	do
	{
		next_anirate();

		if (--current_proc->pdata.p_store2==0)
		{
			rsnd_med_smack();
			current_proc->pdata.p_store2=8;
		}

		if (current_proc->pdata.p_anicount==3)
		{
			shake_a11(0x0003,0x0003);

			ta9=current_proc->pa9;
			current_proc->pa9=(void *)current_proc->a11;
			do_his_next_a9_frame(current_proc->pdata.p_otherguy);
			current_proc->a11=(ADDRESS)current_proc->pa9;
			current_proc->pa9=ta9;

		}

		/* lkbike6 */
		if ((current_proc->pdata.p_otherguy)->oxvel.pos==0)
		{
			if (get_x_dist<=SCX(0x30))
				stop_me(obj);
		}

		/* lkbike5 */
		process_sleep(1);

		sans_repell_3();
		
		if ((current_proc->pdata.p_otherproc)->pdata.p_flags & PM_CORPSE)		
			goto BIKE_ABORT;
		

	}
	while(--current_proc->pdata.p_store1>0);

	/* done = fall to ground */
	takeover_him(r_bike_kicked_done);
	
BIKE_ABORT:
	flight(obj,0,0,SCY(0x4000),4,-1);

	zero_turbo_bar();

	reaction_exit(obj);
}

/******************************************************************************
 Function: void biked_suspend(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	suspend while being biked
******************************************************************************/
void biked_suspend(void)
{
	inc_p_hit();
	
	current_proc->pdata.p_hitby=ACT_BIKE;
	suspend_wait_action();
}

//******************************************************************
//******************************************************************
void prop_do_jc_shoruken(void) 
{
	OBJECT *obj=current_proc->pa8;
	long stk_a0,stk_a1,stk_a2;
	long ta10;
	
	init_special_act(ACT_SHORUKEN,obj);
	ochar_sound(4);

	animate2_a9(4,ANIM_JC_SHORUK);	
	
	obj->oyvel.pos=-SCY(0xc0000);
	obj->ograv.pos=SCY(0xb000);
	away_x_vel(current_proc,obj,-SCX(0xa0000));

	ta10=(obj->oxvel.pos<0)?-SCX(0x8000):SCX(0x8000);
	current_proc->pdata.p_store1=0;		// no contact
	
	create_fx(FX_TRAIL)->a11=0;		// green only
	
	/* shor4 accelerate up */
	do
	{
		process_sleep(1);
		
		f_norepell=3;
		
		if (current_proc->pdata.p_store1==0 && get_his_action(current_proc)!=ACT_DUCK) 
		{
			if (strike_check_a0(obj,0x11)==SYSTEM_CARRY_SET)	
			{
				current_proc->pdata.p_store1=1;
				
				if (f_block==0) 
				{
					stk_a0=obj->oxvel.pos;
					stk_a1=obj->oyvel.pos;
					stk_a2=obj->ograv.pos;
					
					stop_me(obj);
					away_x_vel(current_proc,obj,1);
					
					f_norepell=8;
					process_sleep(6);
					obj->oyvel.pos=stk_a1;
					obj->ograv.pos=stk_a2;
					away_x_vel(current_proc,obj,-abs(stk_a0));
				}
				else
				{
					stk_a0=obj->oxvel.pos;
					stop_me(obj);
					away_x_vel(current_proc,obj,stk_a0/8);
				}
			}
		}
		
		/* shor7 */
		obj->ograv.pos-=SCY(0x2000);
		
	}
//	while(obj->oypos.u.intpos-(0x40)>0);
	while (distance_off_ground(current_proc,current_proc->pa8)<80);
	
	/* slow down at peak */
	current_proc->pdata.p_action=ACT_SHORUKEN_SD;
	
	obj->ograv.pos=SCY(0x18000);
	/* shor5 */
	while (obj->oyvel.pos<=0)
	{
		away_x_vel(current_proc,obj,-(obj->oxvel.pos>>1));
		f_norepell=3;
		process_sleep(1);
			
	}
	
	/* shor6 */
	stop_me(obj);
	
	process_sleep(12);
	
	pose2_a9(3,ANIM_JC_SHORUK);
	drop_down_land_jump();
}

void prop_do_shadow_kick(void) 
{
	jc_shadow_kick(0);
}

void prop_do_shadow_kickr(void) 
{
	jc_shadow_kick(1);
}

void jc_shadow_kick(WORD ta11) 
{
	OBJECT *obj=current_proc->pa8;

	init_special_act(ACT_SHADK,obj);
	
	get_char_ani(ANIM_TABLE2,ANIM_JC_SKICK);

	away_x_vel(current_proc,obj,(ta11==0)?-SCX(0x60000):-SCX(0x78000));
	ochar_sound(0x1);			
	create_fx(FX_TRAIL)->a11=ta11;
	
	init_anirate(2);
	
	current_proc->a11=(ta11==0)?20:24;
	/* skick4 */
	do
	{
		next_anirate();
		
		if (current_proc->a11<=13) 
		{
			if (strike_check_a0(obj,0x10)==SYSTEM_CARRY_SET)		
				shadow_kick_hit();
		}
		
		process_sleep(1);
	}
	while(--current_proc->a11>0);
	
	current_proc->pdata.p_action=0;
	stop_me(obj);
	
	current_proc->pdata.p_action=ACT_SHADOW_SD;
	process_sleep(12);
	skick8();
}

void shadow_kick_hit(void) 
{
	get_char_ani(ANIM_TABLE2,ANIM_JC_SKICK);
	find_last_frame();
	stop_me(current_proc->pa8);
	
	current_proc->pdata.p_action=ACT_SHADOW_SD;
	do_next_a9_frame(current_proc->pa8);
	process_sleep(20);
	skick8();
}

void skick8(void) 
{
	get_char_ani(ANIM_TABLE2,ANIM_JC_SKICK);
	find_part2();
	mframew(3);
	reaction_exit(current_proc->pa8);
}

#define NOOB_DAMAGE	0xf

void noobed(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	ground_player(obj);
	find_ani_part2(ANIM_KDOWN);
	do_next_a9_frame(obj);
	group_sound(2);
	rsnd_ground();
	shake_a11(8,8);
	
	current_proc->pdata.p_action=ACT_NOOB_SLAM_BOUNCE;
	damage_to_me(NOOB_DAMAGE,obj);
	inc_p_hit();
	
	set_quarter_damage(obj);
	flight(obj,SCX(0x20000),-SCY(0xb0000),SCY(0x8000),4,-1);
	land_on_my_back();
}

void noob_hyperslam_fatality(OBJECT *oa10);

void noob_hit(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *oa10;
	PROCESS *pother=current_proc->pdata.p_otherproc;
	WORD stk_a0,stk_a1;
	WORD fatalflag=current_proc->pdata.p_store1;
	
	face_opponent(obj);
	pose_a9(0,ANIM_THROW);
	
	stk_a0=pother->pdata.p_hit;
	stk_a1=pother->pdata.p_damage;
	
	pother->pdata.p_damage=0;
	pother->pdata.p_hit=0;
	body_slam_init(obj);
	
	oa10=(OBJECT*)current_proc->a10;
	
	pother->pdata.p_hit=stk_a0;
	pother->pdata.p_damage=NOOB_DAMAGE+stk_a1;
	
	obj->oyvel.pos=-SCY(0x80000);
	oa10->oyvel.pos=-SCY(0x80000);
	
	get_char_ani(ANIM_TABLE1,ANIM_THROW);
	mframew(1);
	double_next_a9();
	process_sleep(2);
	double_next_a9();
	process_sleep(2);
	
	obj->ograv.pos=oa10->ograv.pos=SCY(0x14000);
	
	/* drop below ground */
	do
	{
		process_sleep(1);
		sans_repell_3();
		
		if (obj->oyvel.pos>=0) 
		{
			oa10->oxvel.pos=obj->oxvel.pos;
			oa10->oyvel.pos=obj->oyvel.pos;
		}
	}
	while(abs(obj->oypos.u.intpos-current_proc->pdata.p_ganiy)<SCY(0x50));
	
	obj->oypos.u.intpos-=SCRBOT+SCY(0x40);
	oa10->oypos.u.intpos-=SCRBOT+SCY(0x40);
	
	/* noobs3 */
	do
	{
		process_sleep(1);
		sans_repell_3();
		oa10->oxvel.pos=obj->oxvel.pos;
		oa10->oyvel.pos=obj->oyvel.pos;
	}
	while(current_proc->pdata.p_ganiy>obj->oypos.u.intpos);
	
	if (fatalflag==1)
		noob_hyperslam_fatality(oa10);
		
	stop_him(oa10);
	
	takeover_him(noobed);
	
	stop_me(obj);
	ground_player(obj);
	reaction_exit(obj);
}

void prop_do_noob_slam(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	init_special_act(ACT_NOOB_TELESLAM,obj);			// i cant block
	
	update_tsl(l_warp,obj);
	
	ochar_sound(4);
	
	create_fx(FX_TRAIL);
	
	get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
	do_next_a9_frame(obj); 
	init_anirate(2);
	
	obj->oyvel.pos=-SCY(0x80000);
	obj->ograv.pos=-SCY(0x10000);
	away_x_vel(current_proc,obj,1);		// fool out trail effect
	
	/* nt4 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(distance_off_ground(current_proc,obj)<SCY(0xe8));
	
	teleport_next_to();
	face_opponent(obj);
	
	obj->oypos.u.intpos=ground_y-SCY(0x60);
	
	obj->ograv.pos=SCY(0x8000);
	obj->oyvel.pos=-SCY(0xa0000);
	away_x_vel(current_proc,obj,0);		// fool out trail effect
	
	/* nt6 */
	do
	{
		process_sleep(1);
	}
	while((obj->oypos.u.intpos-SCY(0x10))>current_proc->pdata.p_ganiy);
	
	get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
	
	face_opponent(obj);
	pose_a9(0,ANIM_THROW);
	away_x_vel(current_proc,obj,-1);		// fool out trail effect
	
	/* noob drop */
NOOB_DROP:	
	do
	{
		process_sleep(1);
		if (obj->oyvel.pos<0 && (current_proc->pdata.p_otherguy)->ochar!=FT_SK && (current_proc->pdata.p_otherguy)->ochar!=FT_MOTARO)
		{
			if (strike_check_a0(obj,0x20)==SYSTEM_CARRY_SET) 
			{
				if (f_block==1)
					zoom_blocked(obj);
				else noob_hit();
			}
		}
	}
	while(obj->oyvel.pos<0);
	
	if (obj->oypos.u.intpos<current_proc->pdata.p_ganiy)
		goto NOOB_DROP;
	
	stop_me(obj);
	ground_player(obj);
	reaction_exit(obj);	
}
