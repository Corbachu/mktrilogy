/******************************************************************************
 File: mkcombo.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Combo Functions
******************************************************************************/

#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkinit.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkjoy.h"
#include "mkpal.h"
#include "mkscore.h"
#include "mkstat.h"
#include "moves.h"
#include "mkcombo.h"
#include "mkguys.h"
#include "mkreact.h"
#include "mkcanned.h"
#include "mkfatal.h"
#include "vcache.h"

/******************************************************************************/
/* External Local References */
/******************************************************************************/

/* located in mkcombo.s */
extern WORD scom_axe_up[];
extern COMBO ct_sa_elbow2[];
extern COMBO ct_jc_elbow2[];
extern COMBO ct_jc_knee2[];
extern COMBO ct_rd_elbow2[];
extern COMBO ct_rd_knee2[];
extern COMBO ct_rain_elbow2[];
extern COMBO ct_rain_knee2[];
extern COMBO ct_noob_elbow2[];
extern COMBO ct_noob_knee2[];
/******************************************************************************/
COMBO *ochar_elbow_combos[]=
{
	ct_kano_elbow2,
	ct_sonya_elbow2,
	ct_jax_elbow2,
	ct_ind_elbow2,
	ct_jc_elbow2,

	ct_swat_elbow2,
	ct_lia_elbow2,
	ct_sektor_elbow2,
	ct_cyrax_elbow2,
	ct_lao_elbow2,

	ct_tusk_elbow2,
	ct_sg_elbow2,
	ct_st_elbow2,
	ct_lk_elbow2,
	ct_smoke_elbow2,

	ct_kitana_elbow2,
	ct_jade_elbow2,
	ct_mileena_elbow2,

	ct_scorp_elbow2,
	ct_rep_elbow2,
	ct_ermac_elbow2,
	ct_osz_elbow2,
	ct_scorp_elbow2,
	ct_noob_elbow2,		//-noob 
	ct_rd_elbow2,		// rayden 
	ct_sa_elbow2,		// baraka 
	ct_rain_elbow2,		//-rain 
	NULL,					// baraka 
	NULL,					// baraka 
	NULL,					// baraka 
};


extern COMBO ct_sa_knee2[];

COMBO *ochar_knee_combos[]=
{
	ct_kano_knee2,	// 0
	ct_sonya_knee2,	// 1
	ct_jax_knee2,	// 3
	ct_ind_knee2,	// 2
	ct_jc_knee2,	// 4

	ct_swat_knee2,	// 5
	ct_lia_knee,	// 6
	ct_sektor_knee2,	// 7
	ct_cyrax_knee2,	// 8
	ct_lao_knee2,	// 9

	ct_tusk_knee2,	// 10
	ct_sg_knee2,	// 11
	ct_st_knee2,	// 12
	ct_lk_knee2,	// 13
	ct_smoke_knee2,	// 14

	ct_kitana_knee2,	  // 15
	ct_jade_knee2,	  // 16
	ct_mileena_knee2,  // 17

	ct_scorp_knee2,	     // 18
	ct_rep_knee2, 	     // 19
	ct_ermac_knee2,   	// 20
	ct_osz_knee2,    	// 21
	ct_kano_knee2,   	// 22
	ct_noob_knee2,   	// 23  
	ct_rd_knee2,		// rayden -u64-
	ct_sa_knee2,		// baraka -u64- 
	ct_rain_knee2,   	// 23  
	NULL,					// kamel
	
	NULL,					// baraka -u64- 
	NULL,					// baraka -u64- 
};

extern BRUTAL brutal_kano[];
extern BRUTAL brutal_sonya[];
extern BRUTAL brutal_jax[];
extern BRUTAL brutal_indian[];
extern BRUTAL brutal_cage[];
extern BRUTAL brutal_swat[];
extern BRUTAL brutal_lia[];
extern BRUTAL brutal_robo1[];
extern BRUTAL brutal_robo2[];
extern BRUTAL brutal_lao[];
extern BRUTAL brutal_tusk[];
extern BRUTAL brutal_sg[];
extern BRUTAL brutal_st[];
extern BRUTAL brutal_lk[];
extern BRUTAL brutal_robo3[];
extern BRUTAL brutal_kit[];
extern BRUTAL brutal_jade[];
extern BRUTAL brutal_mil[];
extern BRUTAL brutal_scorp[];
extern BRUTAL brutal_rep[];
extern BRUTAL brutal_ermac[];
extern BRUTAL brutal_osz[];
extern BRUTAL brutal_osm[];
extern BRUTAL brutal_noob[];
extern BRUTAL brutal_rayden[];
extern BRUTAL brutal_baraka[];
extern BRUTAL brutal_rain[];
extern BRUTAL brutal_kamel[];

BRUTAL *brutal_table[]=
{
	brutal_kano,
	brutal_sonya,
	brutal_jax,
	brutal_indian,
	brutal_cage,

	brutal_swat,
	brutal_lia,
	brutal_robo1,
	brutal_robo2,
	brutal_lao,

	brutal_tusk,
	brutal_sg,
	brutal_st,
	brutal_lk,
	brutal_robo3,

	brutal_kit,
	brutal_jade,
	brutal_mil,
	brutal_scorp,
	brutal_rep,

	brutal_ermac,
	brutal_osz,
	brutal_osm,
	brutal_noob,
	brutal_rayden,
	
	brutal_baraka,
	brutal_rain,
	brutal_kamel,
	NULL,
	NULL,
	
	NULL,
	NULL,
	NULL,
};

/*****************************************************************************
 Function: void do_knee(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: 	None

 Returns: None

 Description:	perform a knee kick
******************************************************************************/
void do_knee(void)
{
	WORD result;
	WORD pcombo;

	OBJECT *obj=current_proc->pa8;

	init_special(obj);
	
	pcombo=(obj==p1_obj)?f_opt_combo1:f_opt_combo2;

	result=striker(SI_STRIKER_NORMAL,1,ACT_KNEE,ANIM_KNEE,1,0xe);

	if (ochar_knee_combos[obj->ochar] != NULL && (!f_no_combos) && (pcombo!=0))
	{
		me_in_front();
		process_combo_table(ochar_knee_combos[obj->ochar]);
	}

	/* knee4 */
	current_proc->pdata.p_action=ACT_KNEE_SD;

	if (result==SYSTEM_CARRY_SET)
		process_sleep(15);

	retract_strike(6);

	return;
}

void knee_elbow_blocked(WORD pa0)
{
	process_sleep(0x10);
	retract_strike(pa0);
	return;
}

/******************************************************************************
 Function: void do_elbow(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	perform an elbow attack
******************************************************************************/
BYTE ochar_elbow_animations[]=
{
	0x10,
	0x10,
	0x10,
	0x10,
	0x10,

	0x10,
	0x10,
	0x10,
	0x10,
	0x10,

	0x10,
	0x10,
	0x10,
	0x10,
	0x10,

	0x10,
	0x10,
	0x80|0x13,	// mileena

	0x10,	// scorpion
	0x80|0x00,	// reptile
	0x80|0x03,	// ermac
	0x80|0x03,	// old subzero
	0x10,	//osm
	0x80|0x03,	// noob
	0x10,		//rray
	0x10,		//bara
	0x80|0x03,	// rain
	0x10,		// kamel
	0x10,		// c2
	0x10,		// c3
};

void do_elbow(void)
{
	WORD pcombo;
	OBJECT *obj=current_proc->pa8;

	init_special(obj);
	
	pcombo=(obj==p1_obj)?f_opt_combo1:f_opt_combo2;

	if (ochar_elbow_animations[obj->ochar] & 0x80) 
		current_proc->pa9=get_char_ani(ANIM_TABLE2,ochar_elbow_animations[obj->ochar] & 0x7f);
	else current_proc->pa9=get_char_ani(ANIM_TABLE1,ochar_elbow_animations[obj->ochar] & 0x7f);

	if (striker(SI_STRIKER_NORMAL,1,ACT_ELBOW,0xffff,5,0xf)==SYSTEM_CARRY_SET)
	{
		me_in_front();
		
		if (winner_status==3 && am_i_joy()==SYSTEM_CARRY_SET)
		{
			if (brutal_table[obj->ochar]!=NULL)
				process_brutal_table(brutal_table[obj->ochar]);
			goto RETRACT;	
		}
			
		if (ochar_elbow_combos[obj->ochar]!=NULL && (!f_no_combos) && (pcombo!=0))
		{
			process_combo_table(ochar_elbow_combos[obj->ochar]);
		}
		else
		{
			/* elbow4 */
			current_proc->pdata.p_action=ACT_ELBOW_SD;
			process_sleep(10);
		}
	}

	/* elbow5 */
RETRACT:	
	retract_strike_act(ACT_ELBOW_SD,3);

	return;
}

void do_brutality(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	if (brutal_table[obj->ochar]!=NULL)
		process_brutal_table(brutal_table[obj->ochar]);
	wait_forever();	
}

/******************************************************************************
 Function: void process_combo_table(COMBO *ctbl)

 By: David Schwartz

 Date: Feb 1995

 Parameters: 	None

 Returns: None

 Description:	process a combo table and perform if correct
******************************************************************************/
void process_combo_table(COMBO *ctbl)
{
	WORD results;
	short pcombo;
	

	pcombo=(current_proc->pa8==p1_obj)?f_opt_combo1:f_opt_combo2;
	
	current_proc->a10=0;			// previouis button offset
	current_proc->pdata.p_action=ACT_COMBO;			// define my action, combo mode

	clear_combo_butn();

COMB0:	/* comb0 */
	current_proc->a0=ctbl->c_time & 0xff;		// time to button/anim speed, mask off "last option" bits

	if (am_i_joy()==SYSTEM_CARRY_CLR)
	{
		process_sleep(4);

		if (diff<2)
			return;				// easy == no cpu combo's
	}
	else
	{
		if (f_auto_combos==0 && pcombo!=2) 
		{
			/* combj */
			current_proc->pdata.p_anicount=current_proc->a0;
			process_sleep(3);

			current_proc->pdata.p_anicount-=3;

			/* comb1 */
			do
			{
				process_sleep(1);

				if ((results=combo_scan_a11(&ctbl))==SYSTEM_CARRY_SET)
					goto COMB8;
			}
			while(--current_proc->pdata.p_anicount>0);

			if (results==SYSTEM_CARRY_SET)
				goto COMB8;					// !! SUCCESS

			goto COMBO_2_LATE;
		}
	}

	/* success -> do next animation */
COMB8:
	if (is_he_airborn()==SYSTEM_CARRY_CLR)
		stop_him(current_proc->pdata.p_otherguy);		// he is airborn dont stop him

	/* comb2 */
	clear_combo_butn();

	current_proc->a10=current_proc->a14;		// save last button pushed

	if (ctbl->c_attack==CB_JUMP_ADDRESS)		// do a special move instead of a canned animation
		(ctbl->c_next)();

	/* comba */
	a9_combo_ani(ctbl->c_attack);

	mframew((ctbl->c_speed)>>8);			// anim speed

	if (strike_check(combo_strike_table[(ctbl->c_stk)>>8],0)==SYSTEM_CARRY_SET)
	{
		zero_turbo_bar();		// avoid sprint abuse

		(COMBO *)current_proc->a7=ctbl;

		/* -NOTE- conv note code spcae is 0x8000000 or greater */
		if ((LONG)ctbl->c_next >= 0x80000000)
		{
			ctbl=(COMBO *)(ctbl->c_next);
			goto COMB0;					// neg = process it
		}

		process_sleep((LONG)(ctbl->c_next));
		//a9_combo_ani(ctbl->c_retr);
		goto COMB9;
	}
	else
	{
		/* combo_miss */
		process_sleep(0x10);
	}

COMBO_2_LATE:
	process_sleep(5);

COMBO_EXIT:
	a9_combo_ani(ctbl->c_retr);

COMB9:
	mframew(4);

	reaction_exit(current_proc->pa8);
}

FUNCW requirement_table[]=
{
	combo_is_stick_away,		// 1
	check_axe_up_combo,	// 2
	combo_is_stick_toward,	// 3
	combo_is_stick_down,		// 4
	set_his_half_damage,
	combo_is_stick_up,
	combo_q_no,
	set_his_quarter_damage,
};

/******************************************************************************
 Function: WORD combo_scan_a11(COMBO **ctbl)

 By: David Schwartz

 Date: Feb 1995

 Parameters: ctbl - (a11) ptr to a ptr combo table

 Returns: SYSTEM_CARRY_SET - combo match
		  SYSTEM_CARRY_CLR - no combo match

 Description:	scan a combo table and detrmine if valid combo started
******************************************************************************/
WORD combo_scan_a11(COMBO **ctbl)
{
	COMBO *ta11=*ctbl;
	WORD *cbutton;

	/* cscan1 */
	do
	{
		current_proc->a14=ta11->c_speed & 0x000f;		// this will be out "LAST" button

		cbutton=*(last_switch_ram+(current_proc->a14*2)+1);	// combo ram

		if (p2_obj==current_proc->pa8)
			cbutton++;

		/* comb5 */
		if (*cbutton!=0) 		// button presses since last sleep, combo time
		{
			/* make sure no other buttons pressed */
			current_proc->a2=0;
			current_proc->a1=(p1_obj==current_proc->pa8)?0:1;		// index into combo time ram

			/* loop unroll from arcade */
			if (c_hp[current_proc->a1] && current_proc->a10!=0)
				current_proc->a2++;
			if (c_lp[current_proc->a1] && current_proc->a10!=1)
				current_proc->a2++;
			if (c_block[current_proc->a1] && current_proc->a10!=2)
				current_proc->a2++;
			if (c_hk[current_proc->a1] && current_proc->a10!=3)
				current_proc->a2++;
			if (c_lk[current_proc->a1] && current_proc->a10!=4)
				current_proc->a2++;

			/* comb7, after loop */
			if (current_proc->a2>1)
				goto COMBOF;

			current_proc->a0=ta11->c_req & 0xff;

			if (current_proc->a0!=0)
			{
				current_proc->a0--;

				if (requirement_table[current_proc->a0]()==SYSTEM_CARRY_CLR)		// test requirement
					goto COMBOF;
			}

			/* cscan8 */
			*ctbl=ta11;
			return(SYSTEM_CARRY_SET);
		}

COMBOF:
		if ((ta11->c_time & M_LAST_OPTION))
			break;
		ta11++;
	}
	while(1);

	/* cscan9 */
	return(SYSTEM_CARRY_CLR);
}

/******************************************************************************
 Function: void a9_combo_ani(WORD pa9)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa9 - anim index & offset

 Returns: None

 Description:	combo anim setup
******************************************************************************/
void a9_combo_ani(WORD pa9)
{
	WORD t_a9;

	t_a9=pa9>>8;
	pa9&=0x00ff;

	if (t_a9 & 0x80)
		find_ani2_part_a14(t_a9 & 0x7f,pa9);
	else find_ani_part_a14(t_a9,pa9);

	return;
}

/******************************************************************************
 Function: void clear_combo_butn(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	combo ram clear
******************************************************************************/
void clear_combo_butn(void)
{
	current_proc->a0=(p1_obj==current_proc->pa8)?0:1;		// index into combo time ram

	/* loop unroll from arcade */
	c_hp[current_proc->a0]=0;
	c_lp[current_proc->a0]=0;
	c_block[current_proc->a0]=0;
	c_hk[current_proc->a0]=0;
	c_lk[current_proc->a0]=0;
	return;
}

/******************************************************************************
 Function: WORD check_axe_up_combo(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: SYSTEM_CARRY_SET - condition matched (axe up)
		  SYSTEM_CARRY_CLR - condition failed

 Description:	see if combo is performed
******************************************************************************/
WORD check_axe_up_combo(void)
{
	(PROCESS *)current_proc->pdata.p_store4=current_proc;		// this is assumed

	return(stick_look_lr(P1B0,P2B0,scom_axe_up));
}

/************************************************
 COMBO STUB FOR CORRECT ROUTINES
************************************************/
WORD combo_q_no(void) 
{
	return(SYSTEM_CARRY_CLR);
}

WORD combo_is_stick_away(void)
{
	return(is_stick_away(current_proc));
}

WORD combo_is_stick_up(void)
{
	return(is_stick_up(current_proc));
}

WORD combo_is_stick_down(void)
{
	return(is_stick_down(current_proc));
}

WORD combo_is_stick_toward(void)
{
	return(is_stick_toward(current_proc));
}

WORD set_his_half_damage(void)
{
	if ((current_proc->pdata.p_otherproc)->pdata.p_hit>=3)
		set_half_damage(current_proc->pdata.p_otherguy);

	return(SYSTEM_CARRY_SET);			// always return 'YES'
}

WORD set_his_quarter_damage(void) 
{
	/* calla_for_him */
	set_half_damage(current_proc->pdata.p_otherguy);
	return(SYSTEM_CARRY_SET);			// always return 'YES'
}

WORD retract_brutal(WORD pchar) 
{
	WORD retract;
	
	switch (pchar)
	{
		case FT_ERMAC:
		case FT_OLDSZ:
		case FT_REPTILE:
		case FT_RAIN:
		case FT_NOOB:
			retract=0x8002;
			break;
		case FT_MILEENA:
			retract=0x9302;
			break;
		default:
			retract=RETRACT_ELBOW;
	}
	
	return(retract);
}

WORD brutal_scan_a11(BRUTAL *btbl)
{
	WORD *cbutton;

	/* cscan1 */
	current_proc->a14=btbl->b_speed & 0x000f;		// this will be out "LAST" button

	cbutton=*(last_switch_ram+(current_proc->a14*2)+1);	// combo ram

	if (p2_obj==current_proc->pa8)
		cbutton++;						  

	/* comb5 */
	if (*cbutton!=0) 		// button presses since last sleep, combo time
	{
	
		/* make sure no other buttons pressed */
		current_proc->a2=0;
		current_proc->a1=(p1_obj==current_proc->pa8)?0:1;		// index into combo time ram

		/* loop unroll from arcade */
		if (c_hp[current_proc->a1] && current_proc->a10!=0)
			current_proc->a2++;
		if (c_lp[current_proc->a1] && current_proc->a10!=1)
			current_proc->a2++;
		if (c_block[current_proc->a1] && current_proc->a10!=2)
			current_proc->a2++;
		if (c_hk[current_proc->a1] && current_proc->a10!=3)
			current_proc->a2++;
		if (c_lk[current_proc->a1] && current_proc->a10!=4)
			current_proc->a2++;
			
		/* comb7, after loop */
		if (current_proc->a2>1)
			return(SYSTEM_CARRY_CLR);
		else return(SYSTEM_CARRY_SET);
	}

	/* cscan9 */
	return(SYSTEM_CARRY_CLR);
}

void process_brutal_table(BRUTAL *btbl)
{
	WORD results;
	WORD auto_flag=0;
	BRUTAL *restoretbl=btbl;
	WORD sleep;
	short xtest;
	
	clear_combo_butn();
	
	/* brutality start */
 	pose_a9(0,0);
	f_death=FAT_BRUTAL;
	
	/* process tables */
	current_proc->a10=0;			// previouis button offset
	current_proc->pdata.p_action=ACT_BRUTAL;			// define my action, brutal mode


COMB0:	/* comb0 */
	current_proc->a0=12;
	
	if (am_i_joy()==SYSTEM_CARRY_CLR || auto_flag!=0)
	{
		process_sleep(4);
	}
	else
	{
		/* combj */
		current_proc->pdata.p_anicount=current_proc->a0;
		process_sleep(3);

		current_proc->pdata.p_anicount-=3;

		/* comb1 */
		do
		{
			process_sleep(1);

			if ((results=brutal_scan_a11(btbl))==SYSTEM_CARRY_SET)
				goto COMB8;
		}
		while(--current_proc->pdata.p_anicount>0);

		if (results==SYSTEM_CARRY_SET)
			goto COMB8;					// !! SUCCESS
			
		goto BRUTAL_2_LATE;
	}

	/* success -> do next animation */
COMB8:
	if (is_he_airborn()==SYSTEM_CARRY_CLR)
		stop_him(current_proc->pdata.p_otherguy);		// he is airborn dont stop him

	/* comb2 */
	clear_combo_butn();

	current_proc->a10=current_proc->a14;		// save last button pushed

	/* comba */
	a9_combo_ani(btbl->b_attack);

	if (auto_flag==1)
		sleep=(btbl->b_speed)>>9;			// anim speed (double time)
	else sleep=(btbl->b_speed)>>8;			// anim speed
	if (sleep==0)
		sleep=1;
	
	xtest=(current_proc->pa8)->oxpos.u.intpos;
		
	mframew(sleep);	
	
	(current_proc->pa8)->oxpos.u.intpos-=((current_proc->pa8)->oxpos.u.intpos-xtest)/2;
	
	if (strike_check(combo_strike_table[(btbl->b_stk)>>8],0)==SYSTEM_CARRY_SET)
	{
		zero_turbo_bar();		// avoid sprint abuse
		
		(BRUTAL *)current_proc->a7=btbl;
		btbl++;
		
		if ((current_proc->pa8)->oflags & M_FLIPH)
			(current_proc->pa8)->oxpos.u.intpos-=4;
		else (current_proc->pa8)->oxpos.u.intpos+=4;

		if (btbl->b_attack!=0xffff) 
		{
			goto COMB0;
		}
		
		/* high speed brutaltity time */
		if (auto_flag==0) 
		{
			init_death_blow(FAT_BRUTAL);
			auto_flag++;
			btbl=restoretbl;
			goto COMB0;
		}
		
		/* do an uppercut */
		a9_combo_ani(0x0b01);
		rsnd_big_smack();
		mframew(2);

		/* end it all */
		takeover_him(r_ex2on2);
		process_sleep(0x12+0x40);
		
		a9_combo_ani(retract_brutal((current_proc->pa8)->ochar));
		mframew(4);
		
		process_sleep(0x8);
		sound_music_stop();
		death_blow_complete();
		
		stack_jump(victory_animation);
	}
	else
	{
		/* combo_miss */
		process_sleep(0x10);
	}

BRUTAL_2_LATE:
	process_sleep(3);
	takeover_him(rd_cacell_victum);
	a9_combo_ani(retract_brutal((current_proc->pa8)->ochar));
	mframew(4);
	
	/* abort brutality, reset whatever stuff */
	sound_music_stop();
	f_death=-1;
	process_sleep(1);
	f_death=0;
	
	process_sleep(0x30);
	stack_jump(victory_animation);
}

