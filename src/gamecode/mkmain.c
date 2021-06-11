/******************************************************************************
 File: mkmain.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Main Game Flow Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkinit.h"
#include "mkguys.h"
#include "mkr1.h"
#include "mkrepell.h"
#include "mkmain.h"
#include "mkutil.h"
#include "mkani.h"
#include "moves.h"
#include "mkmain.h"
#include "mksel.h"
#include "mkjoy.h"
#include "mkopt.h"
#include "mkdiag.h"
#include "mkend.h"
#include "mkamode.h"
#include "mkladder.h"
#include "mkscore.h"
#include "mktext.h"
#include "mkvs.h"
#include "mkfx.h"
#include "mkpal.h"
#include "mkfade.h"
#include "mkbonus.h"
#include "mkreact.h"
#include "mksound.h"
#include "mkmode.h"
#include "mkhstd.h"
#include "mkdma.h"
#include "mkbio.h"
#include "mkbuyin.h"
#include "vcache.h"
#include "mkcanned.h"
#include "wessapi.h"

/* local extern info */
extern FNTSETUP pf_15point_soff[];
extern FNTSETUP pf_15point[];
extern FNTSETUP pf_dave_smallc[];
extern FNTSETUP pf_entered[];
extern FNTSETUP pf_round_num[];
extern void *fl_entered[];
extern void *fl_finish[];
extern WORD LOADING_P[];
extern WORD YELLOW_p[];
extern WORD title_song;

extern WORD *endurance_tables[];
void end_of_tournament(void);
void play_finish_tune(void);
extern void two_on_two_tot1(void); 
extern void three_on_three_tot1(void);
void clue_giveaway(void);
void toasty_check(WORD pa0);
void invaders_game_load(WORD pa0,WORD type);

void force_it(void)
{
	if (gstate==GS_AMODE)
		return;

	
#if MK_EJBBUG
	if (df_fastrun==0)
		return;

	if (gstate==GS_AMODE)
		return;

	p1_char=FT_KANO;
	p2_char=FT_SONYA;
	curback=BKGD_WATER_MOD;
#endif

	return;
}

HSCORE factory_initials[]=
{
	{"MK4",10}, 			// 1
	{"OFF",9}, 			// 2
	{"ROD",9},  			// 3
	{"USA",7},  			// 4
	{"KER",6}, 			// 8
	{"BAB",6},  			// 5
	{"MK1",5},  			// 6
	{"TOB",5},  			// 7
	{"MK2",4}, 			// 9
	{"TIM",3}, 			// 10
	{"MK3",5}, 			// 11
	{"DHS",4}, 			// 12
	{"TTT",4}, 			// 13
	{"BOO",4}, 			// 14
	{"TOB",3} 			// 15
};

/******************************************************************************
 Function: void start_entry(WORD *pstate,WORD poffset)

 By: David Schwartz

 Date: Sept 1994

 Parameters: pstate - ptr to player state of whom start was pushed (a2)
			 poffset - (0=p1 1=p2) (a4)

 Returns: None

 Description:	Based on game start and/or player state react to the start button
				being pushed.
				1) start a new game
				2) barge into an existing game
				3) do nothing
				4) auto select player
******************************************************************************/
void start_entry(WORD *pstate,WORD poffset)
{
	f_start_pressed=1;					/* flag: start button pressed !! */

	/* BASED ON GAME STATE EXECUTE CORRECT ACTION */
	switch (gstate)
	{
		case 0x00:							// 0 - null
		case 0x08:							// 8 - diags
		case 0x09:							// 9 - chop sequence
		case 0x0a:							// a - enter initials
		case 0x0c:							// c - octopus ??
		case 0x0d:							// d - post player select fade
		case 0x0e:							// e -
		case 0x0f:							// f - intro effect
		case 0x11:							// 11 -
		case 0x12:							// 12 -
		case 0x13:							// 13 -
		case 0x14:							// 14 - mode select
		case 0x15:							// 15 - already in options death
			process_suicide();
			break;

		case 0x01: 	// start_during_amode	 1 - attract mode
		case 0x0b:	// start_during_gover	 b - game over start!!
			/* amode_game_start */
			/* Note: This is an addition to the arcade game.
				This is where we hooked in the option stuff
			*/
			wess_seq_stopall();
			title_song=0;
			f_fatal_demo=0;

			/* gover_game_start */
			murder_myoinit_score();
			DISPLAY_ON;

			game_init();

			/* MUST FALL INTO do_pstate_jump case */

		case 0x03: // start_during_buyin	 3 - buyin
		case 0x04: // start_during_psel		 4 - fighter select
			/* do_pstate_jump */
			switch (*pstate)
			{
				case 0x01:					// 1 - active
				case 0x04:					// 4 -
				case 0x05:					// 5 -
					process_suicide();
					break;

				case 0x03:	 // pstate_is_psel	3 - auto select check
					switch (mode_of_play)
					{
						case 0:		// random_sel_1on1
							if (&p1_state==pstate)
							{
								current_proc->a5=MASK_JUP;		// p1 up mask
								current_proc->a6=FT_NOOB;
								current_proc->a0=PID_P1SEL;
								current_proc->a11=0;			// no alt
								current_proc->a14=0;			// no 2nd alt
							}
							else
							{
								current_proc->a5=MASK_JUP<<16;		// p2 up mask
								current_proc->a6=FT_RAIN;
								current_proc->a0=PID_P2SEL;
								current_proc->a11=0;			// no alt
								current_proc->a14=0;			// no 2nd alt
							}
							break;		
						case 1:		// random_sel_2on2
							if (&p1_state==pstate)
							{
								current_proc->a5=MASK_JUP;		// p1 up mask
								current_proc->a6=FT_NOOB;
								current_proc->a0=PID_P1SEL;
								current_proc->a11=PID_P2SEL;			// no alt
								current_proc->a14=0;			// no alt
							}
							else
							{
								current_proc->a5=MASK_JUP<<16;		// p2 up mask
								current_proc->a6=FT_RAIN;
								current_proc->a0=PID_P3SEL;
								current_proc->a11=PID_P4SEL;			// no alt
								current_proc->a14=0;			// no alt
							}					
						break;		
						case 4:		// random_sel_3on3
							if (&p1_state==pstate)
							{
								current_proc->a5=MASK_JUP;		// p1 up mask
								current_proc->a6=FT_NOOB;
								current_proc->a0=PID_P1SEL;
								current_proc->a11=PID_P2SEL;			// no alt
								current_proc->a14=PID_P5SEL;			// no alt
							}
							else
							{
								current_proc->a5=MASK_JUP<<16;		// p2 up mask
								current_proc->a6=FT_RAIN;
								current_proc->a0=PID_P3SEL;
								current_proc->a11=PID_P4SEL;			// no alt
								current_proc->a14=PID_P6SEL;			// no alt
							}
							break;		// random_sel_3on3
						default:
							process_suicide();
							break;
					}

					/* asc3 */
					if ((((PROCESS *)(current_proc->a0))=process_exist(current_proc->a0,-1))!=NULL)		// do i have a cursor process
						goto ASC4;

					if (current_proc->a11==0)
						process_suicide();

					if ((((PROCESS *)(current_proc->a0))=process_exist(current_proc->a11,-1))!=NULL)		// do i have a cursor process
						goto ASC4;
						
					if (current_proc->a14==0)
						process_suicide();

					if ((((PROCESS *)(current_proc->a0))=process_exist(current_proc->a14,-1))==NULL)		// do i have a cursor process
						process_suicide();

ASC4:
					/* asc4 */
					if (((PROCESS *)current_proc->a0)->p_comp_flag!=PC_CURSOR_LOOP)							// verify its where it should be
						process_suicide();

					current_proc->a1=((PROCESS *)current_proc->a0)->pdata.p_store6;				// p_mychar

					if (*((WORD *)(current_proc->a1))!=current_proc->a6)						// is it at the original spot
						process_suicide();

					if (swcurr.padvalue & current_proc->a5)
						fastxfer((PROCESS *)current_proc->a0,auto_player_select);				// start auto player select

					process_suicide();
					break;	// case 3, pstate_in_psel

				case 0x00:	// pstate_is_zero 	0 - not in game
					if (gstate==GS_PSEL)
						join_in_during_psel(pstate);
					goto_mode_select(pstate,poffset);
					break;

				case 0x02:	// pstate_is_buyin	2 - buyin
					switch (mode_of_play)
					{
						case 0:		// buyin_1_on_1	Standard MK3
							if (count_active_players()==0 && credits<=0 && f_freeplay==0)
								process_suicide();					// one player game with no credits, its over with
						case 1:		// buyin_2_on_2	2 on 2
						case 4:		// buyin_3_on_3	3 on 3 
							*pstate=PS_PSEL;		//changed from BUYIN???
							goto_mode_select(pstate,poffset);
							break;
						case 2:		// tournament_play
							stack_jump(tournament_play);
							break;
					}
					break;
			}	/* pstate switch */
			break;			// start_during_buyin, start_during_psel		
							
		case 0x02:  // barge_game_start		2 - fighting
			if (*pstate==PS_ACTIVE) 	// player is active so he is allowed to pause game
			{
				/* pause game */
				if (f_pause || winner_status==3)
					process_suicide();		// dont allow pause to keep happening or during fatalities

				if ((clk_ones+clk_tens) == 0)
					process_suicide();		// no pause at end of round

				pause_setup(poffset);
				pause_hold(poffset);
				process_suicide();
			}

		case 0x05:							// 5 - bonus count
		case 0x06:							// 6 - pre-fight setup
		case 0x07:							// 7 - round intro
			/* barge_game_start */
			if (*pstate==PS_ACTIVE || f_death>0)
				process_suicide();
			else
			{
				load_bkgd=0xffff;
			
				clr_scrn();
				murder_myoinit();
				//-SONY- idcomp_base=(LONG *)image_dcomp_buffer;			// reset decomp buffer

				advance_curback();

				b0=p1_state;			// save pstates
				b1=p2_state;

				game_init();

				p2_state=b1;			// restore pstates
				p1_state=b0;
				irqskye=0;				// clear screen

				goto_mode_select(pstate,poffset);
			}
			break;

			case 0x10:		// start_during_debug		10 - debug
				process_suicide();
				break;
	} /* gstate switch */

/*
	SHOULD ONLY GET TO THIS CODE FROM ONE OF THE ABOVE CASES
	NOTHING SHOULD FALL THROUGH TO THIS POINT!!!
*/
	while (TRUE);
}

WORD f_special_endur;
void goto_mode_select(WORD *pstate,WORD poffset)
{
	WORD *pstate_tmp;

GMS1:
	//-SONY- idcomp_base=(LONG *)image_dcomp_buffer;			// reset decomp buffer
	call_every_tick=NULL;					// dont call anything
	current_proc->procid=PID_MASTER;				/* i am the master game flow proc */

	/* sag3 */
	if (poffset==0) 								/* clear win in a row & total rounds won */
	{
		p1_wiar=p1_rwon=0;
		pstate_tmp=&p1_state;
	}
	else
	{
		p2_wiar=p2_rwon=0;
		pstate_tmp=&p2_state;
	}

	update_pmsg();

//	opt_main();
//	mode_of_play=0;
	mode_select();

	if (mode_of_play==3) 
	{
		opt_main();
		mode_of_play=0;
		goto GMS1;
	}

	stack_jump(post_mode_select);
}

void post_mode_select(void)
{
	current_proc->procid=PID_MASTER;

	gstate=GS_PSEL;						/* game state = player select mode */

	eliminate_buyins();

	match_init();
	f_special_endur=0;
	f_silotte=0xffff;
	player_select();

	if (count_active_players()==1 && f_freeplay==0)
		credits--;							// only 1 players, that going cost
		
	if (credits<0)
		credits=0;

	stack_jump(game_loop);
}

void game_loop(void)
{

	if (count_active_players()==0)
	{
		stack_jump(game_over);
	}
	
	stack_jump(round_loop);
}

JUMPTBL rl_tbl[]=
{
	one_on_one,
	two_on_two,
	tournament_play,
	two_on_two,
	three_on_three,
};

void round_loop(void)
{
	stack_jump(rl_tbl[mode_of_play]);
}

void one_on_one(void)
{
	WORD pcount;

	round_1_vs();

	check_battle_milestone();

	if ((pcount=count_active_players())==0)
	{
		stack_jump(game_over);
	}

	if (pcount !=2)
	{
		clear_combo_ram();
		gstate=GS_ROUND_INTRO;						/* game state: intro (1 player) */
		if (set_drone_ochar()==SYSTEM_CARRY_SET)
		{
			stack_jump(game_over);
		}
	}

	/* PLAY1: */
	/* play 1 round */
	f_play3=1;
	f_special_match=0;
	round_results=play_1_round();

PLAY2:
	if (is_endurance_possible()==SYSTEM_CARRY_CLR) 
		goto PLAY3_PRE;
	
	current_proc->a0=a0_next_endurance_guy();
	if (current_proc->a0!=0xffff)
	{
		spawn_endurance_guy(current_proc->a0);
		goto PLAY2;
	}

PLAY3_PRE:
	if ( play3_pa14!=NULL )
	{
		stack_jump(play3_pa14);
	}
	else
	{
		stack_jump(play3);
	}
}

void play3(void)
{
	WORD pcount;

	results_of_round(round_results);
	f_play3=0;

	if (p1_matchw==2 || p2_matchw==2)			/* anyone won 2 yet? */
	{
		inc_winners_wiar();
		update_win_counters();

		if ((clk_ones+clk_tens) != 0)			/* if time left, then allow finishing moves */
		{
			finish_him_sequence();
			set_winner_status();
		}
	}

	/* PLAY7: */
	f_thatsall=1;								/* flag: enough fighting already */
	bonus_count();

	if (p1_matchw!=2 && p2_matchw!=2)
	{
		stack_jump(round_loop);
	}

	end_of_match_chores();

	pcount=count_active_players();				// # of active players before buyin

	loser_in_buyin();								/* loser = buyin state */

	if ( pcount==1 && credits==0 && p1_state!=PS_ACTIVE && p2_state!=PS_ACTIVE)
	{
		check_enter_initials1();					// outta money for one player restart
		stack_jump(game_over);
	}

	check_enter_initials1();
	do_buyin();

	if (pcount!=1)
		check_enter_initials2();							/* if loser didn't buyin, check hstd */

	/* skip_inits */
	if ((WORD)current_drone_a0()==SP_END)
	{
		stack_jump(game_over);
	}

	current_proc->a1=mode_of_play;
	mode_of_play=0;

	if (current_proc->a1==1 || current_proc->a1==4) 
	{
		stack_jump(buyin_to_1_on_1);
	}
		
	stack_jump(game_loop);
}

void buyin_to_1_on_1(void) 
{
	p1_wiar=p2_wiar=0;
	p1_rwon=p2_rwon=0;
	p1_state=p2_state=PS_PSEL;

	stack_jump(post_mode_select);

}

short stk_p1_char;
short stk_p2_char;
short stk_p3_char;
short stk_p4_char;
short stk_p5_char;
short stk_p6_char;

void two_on_two(void) 
{
	stk_p1_char=p1_char;
	stk_p2_char=p2_char;
	stk_p3_char=p3_char;
	stk_p4_char=p4_char;	// grav original chooses

	switch (round_num)
	{
		case 1:		// char_setup_2
			p1_char=stk_p2_char;	// round 2 = p2 vs p4
			p2_char=stk_p4_char;
			p3_char=stk_p1_char;	// round 2 = p1 vs p3
			p4_char=stk_p3_char;
			break;

		default:
			p2_char=stk_p3_char;		// round 1= 
			p3_char=stk_p2_char;
			break;
	}

	/* tot0 */
	round_1_vs();

	f_special_match=0;
	round_results=play_1_round();
	
	stack_jump(two_on_two_tot1);
}	

char txt_ready_player[]="PLAYER %d GET READY!\n";

void two_on_two_tot1(void)
{
	PROCESS *pa1,*pa10;
	WORD *pbar;
	short pchar;
	short pnum;

TOT1:
	switch (round_results)
	{
		case 2:			// tot_tie
			stack_jump(game_over);	
			LOCKUP;					// should never will go to TOT2
			break;
		case 0:			// tot_p1wins
			pa1=p2_proc;	// loser proc
			pchar=p4_char;			// replacement ochar
			pbar=&p2_bar;			// power bar we are waiting for
			pnum=4;
			break;
		case 1:			// tot_p2wins
			pa1=p1_proc;	// loser proc
			pchar=p3_char;			// replacement ochar
			pbar=&p1_bar;			// power bar we are waiting for
			pnum=3;
			break;
		case 3:			// tot_timeout
			f_thatsall=1;
			print_timeout_msg();
			
			round_results=round_is_over();
			goto TOT5;
			break;
	}

	/* TOT2: */
	if ((pa1->pdata.p_flags & PM_WINGMAN)==0)	// did we defeat a "wingman", 
	{
		/* print ready to fight message */
		lm_setup(pf_dave_smallc);
		fnt_state.fnt_posx=160;
		fnt_state.fnt_posy=120;
		printf_p1(txt_ready_player,pnum);
		
		/* load new dude */
		pa10=spawn_wingman(pa1,pchar);
		pa10->pdata.p_flags|=PM_JOY;		// joystick dude flag
		wait_for_wingman(pbar);
//-tot		clear_nocol(pa1->pa8);				// allow collisions
		
		/* remove text message */
		dallobj(OID_TEXT);
		
		/* continue fighting */
		round_results=continue_fighting();
		goto TOT1;
	}

TOT5:
	p1_char=stk_p1_char;			// restore original choicses
	p2_char=stk_p2_char;			// goto --> end of round (bonus count)
	p3_char=stk_p3_char;
	p4_char=stk_p4_char;
	stack_jump(play3);
}

void three_on_three(void) 
{
	stk_p1_char=p1_char;
	stk_p2_char=p2_char;
	stk_p3_char=p3_char;
	stk_p4_char=p4_char;	// grav original chooses
	stk_p5_char=p5_char;	// grav original chooses
	stk_p6_char=p6_char;	// grav original chooses

	switch (round_num)
	{
		case 1:		// char_setup_2
			p1_char=stk_p2_char;	// round 2 = p2 vs p4
			p2_char=stk_p4_char;
			p3_char=stk_p5_char;	// round 2 = p1 vs p3
			p4_char=stk_p6_char;
			p5_char=stk_p1_char;
			p6_char=stk_p3_char;
			break;

		case 2:
			p1_char=stk_p5_char;	// round 2 = p2 vs p4
			p2_char=stk_p6_char;
			p3_char=stk_p1_char;	// round 2 = p1 vs p3
			p4_char=stk_p3_char;
			p5_char=stk_p2_char;
			p6_char=stk_p4_char;
			break;
		
		default:
			p2_char=stk_p3_char;		// round 1= 
			p3_char=stk_p2_char;
			
			break;
	}

	/* tot0 */
	round_1_vs();

	f_special_match=0;
	round_results=play_1_round();
	stack_jump(three_on_three_tot1);
}

void three_on_three_tot1(void) 
{
	PROCESS *pa1,*pa10;
	WORD *pbar;
	short pchar;
	short pnum;

TOT1:
	switch (round_results)
	{
		case 2:			// tot_tie
			stack_jump(game_over);	
			LOCKUP;					// should never will go to TOT2
			break;
		case 0:			// tot_p1wins
			pa1=p2_proc;	// loser proc
			if (pa1->pdata.p_flags & PM_WINGMAN)
			{
				pchar=p6_char;			// replacement ochar
				pnum=6;
			}
			else 
			{
				pchar=p4_char;			// replacement ochar
				pnum=4;
			}
			
			pbar=&p2_bar;			// power bar we are waiting for
			break;
		case 1:			// tot_p2wins
			pa1=p1_proc;	// loser proc
			if (pa1->pdata.p_flags & PM_WINGMAN)
			{
				pchar=p5_char;			// replacement ochar
				pnum=5;
			}
			else 
			{
				pchar=p3_char;			// replacement ochar
				pnum=3;
			}
			
			pbar=&p1_bar;			// power bar we are waiting for
			break;
		case 3:			// tot_timeout
			f_thatsall=1;
			print_timeout_msg();
			
			round_results=round_is_over();
			goto TOT5;
			break;
	}

	/* TOT2: */
	if ((pa1->pdata.p_flags & PM_WINGMAN2)==0)	// did we defeat a "wingman", 
	{
		/* print ready to fight message */
		lm_setup(pf_dave_smallc);
		fnt_state.fnt_posx=160;
		fnt_state.fnt_posy=120;
		printf_p1(txt_ready_player,pnum);
		
		/* load new dude */
		pa10=spawn_wingman(pa1,pchar);
		pa10->pdata.p_flags|=PM_JOY;		// joystick dude flag
		wait_for_wingman(pbar);
//-tot		clear_nocol(pa1->pa8);				// allow collisions
		
		/* remove text message */
		dallobj(OID_TEXT);
		
		/* continue fighting */
		round_results=continue_fighting();
		goto TOT1;
	}

TOT5:
	p1_char=stk_p1_char;			// restore original choicses
	p2_char=stk_p2_char;			// goto --> end of round (bonus count)
	p3_char=stk_p3_char;
	p4_char=stk_p4_char;
	p5_char=stk_p5_char;
	p6_char=stk_p6_char;
	stack_jump(play3);
}

//********************************************************************8

WORD word1=1;
WORD word2=2;
WORD word3=3;
WORD word4=4;
WORD word5=5;
WORD word6=6;
WORD word7=7;
WORD word8=8;

WORD *tmatchups[]=
{
	&word1,
	&word2,		// 1st match = p1 vs. p2
	&word3,
	&word4,		// 2nd match = p3 vs. p4
	&word5,
	&word6,		// 3rd match = p5 vs. p6
	&word7,
	&word8,		// 4th match = p7 vs. p8
	&twinners[0],
	&twinners[1],	// 5th match = match 1 winner vs. match 2 winner
	&twinners[2],
	&twinners[3],	// 6th match = match 3 winner vs. match 4 winner
	&twinners[4],
	&twinners[5],	// 7th match = match 5 winner vs. match 6 winner
	&twinners[6],	// 7th match = match 5 winner vs. match 6 winner
};

void tournament_play(void) 
{
	WORD stk_a10;
	WORD **ta11;
	WORD *ta0,*ta1;

	current_proc->a10=stk_a10=0;
	twinners[0]=twinners[1]=twinners[2]=twinners[3]=0;
	twinners[4]=twinners[5]=twinners[6]=0;

	/* tp3 */
	do
	{
		tournament_tree(stk_a10);
		
		advance_curback();

		ta11=&tmatchups[stk_a10*2];		// a11 ---> next match up !!
		ta0=*ta11;								// a0 ---> player ochar
		ta11++;									
		ta1=*ta11;								// a1 ---> to player ochar
		ta11++;									

		p1_char=p1_tour[*ta0-1];			// setup player 1
		p2_char=p1_tour[*ta1-1];			// setup player 2

		vs_or_ladder();
		p1_matchw=p2_matchw=round_num=0;		// reset for tournament

		f_special_match=0;
		round_results=play_1_round();

		/* ror_tournament */
		results_of_round(round_results);
		f_thatsall=1;			// flag: enough fighting

		bonus_count();
		
		if (round_results==3)
			round_results=round_is_over();

		switch (round_results)
		{
			case 0:			// tp_p1wins
				ta11=&tmatchups[stk_a10*2];		// a11 ---> next match up !!
				ta0=*ta11;
				break;
			case 1:			// tp_p2wins
				ta11=&tmatchups[stk_a10*2+1];		// a11 ---> next match up !!
				ta0=*ta11;
				break;
			case 2:			// tp_tie
			case 3:			// tp_timeout
				stack_jump(game_over);
				LOCKUP;			// should never get here
				break;
		}

		/* tp7 */
		twinners[stk_a10]=*ta0;		// stuff winner's player

		stk_a10++;

		p1_heap_char=p2_heap_char=0xffff;
		
	}
	while(stk_a10!=7);			// more matches to play again

	/* tournament is over */
	tournament_tree(stk_a10);

	murder_myoinit_score();
	bogus_dlist;

	p1_char=p2_char=p1_tour[*ta0-1];
	p15_centered(get_winner_text(),SCX(0xc8),SCY(0x70)+8);
	process_sleep(0x40);

	murder_myoinit_score();

	stack_jump(end_of_tournament);
}

void round_1_vs(void) 
{
	if (round_num==0)
	{
		vs_or_ladder();
		p1_heap_char=p2_heap_char=0xffff;
		p1_boss_char=p2_boss_char=0xffff;
	}


	return;
}

/******************************************************************************
 Function: void set_winner_status(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	set the winner status
******************************************************************************/
void set_winner_status(void)
{
	winner_status=(p1_bar==0)? 2:1;		// declare the winner
	return;
}

void play_1_match(void) 
{
	WORD results;
	
POM1:
	f_play3=0;
	
	round_results=play_1_round();

POM2:	
	if (is_endurance_possible()==SYSTEM_CARRY_CLR) 
		goto POM3_PRE;
	current_proc->a0=a0_next_endurance_guy();
	
	if (current_proc->a0!=0xffff)
	{
		spawn_endurance_guy(current_proc->a0);
		goto POM2;
	}
POM3_PRE:
	set_drone_ochar();
	results_of_round(round_results);
	f_play3=0;
	if (p1_matchw==2 || p2_matchw==2)			/* anyone won 2 yet? */
	{
		inc_winners_wiar();
		update_win_counters();

		if ((clk_ones+clk_tens) != 0)			/* if time left, then allow finishing moves */
		{
			finish_him_sequence();
			set_winner_status();
		}
	}

	/* POM7: */
	f_thatsall=1;								/* flag: enough fighting already */
	bonus_count();

	if (p1_matchw!=2 && p2_matchw!=2)
		goto POM1;
	
	return;
}

void spawn_endurance_guy(WORD pa0) 
{
	if (round_results==1) 
	{
		spawn_wingman(p1_proc,pa0);
		wait_for_wingman(&p1_bar);
//-tot		clear_nocol(p1_proc->pa8);
	}
	else
	{
		spawn_wingman(p2_proc,pa0);
		wait_for_wingman(&p2_bar);
//-tot		clear_nocol(p2_proc->pa8);
	}

	round_results=continue_fighting();
	return;
}

WORD is_endurance_possible(void)
{
	WORD ta0;

	if (count_active_players()!=1)
		q_no;

	if (map_start==NULL)
		q_no;

	current_proc->a0=ta0=*(map_start+map_position);	// set a0 for other routines, sloppy time
	if (ta0 & 0x80) 
	{
		current_proc->a14=0;
		if (p1_state!=PS_ACTIVE)
			current_proc->a14=1;

		if (current_proc->a14==round_results)
			q_yes;
	}

	q_no;
}

WORD a0_next_endurance_guy(void) 
{
	WORD *ta0;

	current_proc->a0&=0x7f;

	ta0=endurance_tables[current_proc->a0];

	((ADDRESS)current_proc->pdata.p_slave)+=1;		// next endur offset

	return(*(ta0+(ADDRESS)current_proc->pdata.p_slave));
}

void fatal_demo_loop(void) 
{
	//-DHS- write code

	LOCKUP;
}

/******************************************************************************
 Function: void game_over(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	Game over routines
******************************************************************************/
char txt_gameover[]="GAME OVER";
void game_over(void)
{
	gstate=GS_GAMEOVER;

	DONT_SHOW_SCORES;
	reset_map_variables();
	diff=0;

	p1_state=p2_state=0;				// take players out of game

	immune_mpp();
	MURDER;

	fast_fadeout_jsrp(0x20);

	MURDER;

	/* ending_gover_entry */
	sound_music_start(MUSIC_SPECIAL);

	clr_scrn();
	murder_myoinit_score();
	unimmune_mpp();
	MURDER;						// kill lingering multiparts

	if (f_oldsm==0 || f_kamel==0)
	{
		/* game_over_exit */
		ukk_codes();
	}
	else
	{
		do_background(BKGD_BATTLE_MOD);
		p15_centered(txt_gameover,SCX(0xc8),SCY(0x58));
		process_sleep(0x40*5);
	}

	MURDER;
	stack_jump(gover_amode_entry);
}

/******************************************************************************
 Function: void clear_combo_ram(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	clear combo ram stuff (briefcase)
******************************************************************************/
void clear_combo_ram(void)
{
	combo_1=combo_2=combo_3=0;
	combo_4=combo_5=combo_6=0;

	return;
}

/******************************************************************************
 Function: void game_init(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Initialize variables for starting a game
******************************************************************************/
void game_init(void)
{
	c_curback=-1;
	advance_curback();

	battle_num=1;

	c_1p_tries=1;

	f_secret=0;
	f_shadows=0;
	f_nosound=0;
	f_doagress=0;
	round_num=0;						/* round one !!! */
	winner_status=0;					/* no winner */
	coinflag=0;							/* flag: coin page not up */

	p1_xvel.pos=0;
	p1_obj=NULL;
	p1_proc=NULL;
	p1_state=0;
	p1_map.pos=0;
	p1_wiar=0;
	p1_rwon=0;

	p2_xvel.pos=0;
	p2_obj=NULL;
	p2_proc=NULL;
	p2_state=0;
	p2_map.pos=0;
	p2_wiar=0;
	p2_rwon=0;

	init_player_variables();

	return;
}

/******************************************************************************
 Function: void init_player_variables(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Initialize variables for players 1 & 2
******************************************************************************/
void init_player_variables(void)
{

	p1_matchw=p2_matchw=0;
	p1_perfect=p2_perfect=0;

	p1_button=p2_button=bt_null;			/* disable buttons */

	return;
}

/******************************************************************************
 Function: WORD play_1_round(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: 0 --> player 1 won round
		  1 --> player 2 won round
		  2 --> tied *
		  3 --> timeout (clock hit zero)

 Description:	Master process routine to play 1 round

	Note: Due to the arcade assembly code making this code reentrant at multiple spots
		  we have split the code up into small chunks so that we can keep the correct flow
******************************************************************************/
extern ADDRESS get_sp(void);
WORD play_1_round(void)
{
	force_it();
	p1_name_char=p1_char;
	p2_name_char=p2_char;

	send_code_a3(0);						// shut up all sounds

	play3_pa14=NULL;					// reset return func, if used, will be set in try_briefcase

	SET_GAME_STATE(GS_PFSETUP);

	if (gstate!=GS_AMODE)
		murder_myoinit_score();					// amode = dont kill everyone

	/* play00 */
	object_initialize();
	setup_score_ram();

	/* arcade display flow */
	DISPLAY_OFF;						

	ochar_force_curback();			// force backgrounds

	round_init();
		
	update_knotches();
	update_pmsg();
	update_win_counters();
	SHOW_SCORES;
	try_kombat_kodes();
	do_background(curback);				
	process_sleep(1);
	
	CREATE(PID_REPELL,repell);
	CREATE(PID_SCROLL,scroller);

	setup_players();
	start_shadows();

	SET_GAME_STATE(GS_ROUND_INTRO);
	play_background_tune();


#if MK_EJBBUG
	if (df_fastrun!=0)
		goto SKIP_INTRO;
#endif

	/* PLAY1A: */
	f_sync=0;
	CREATE(PID_FX,round_intro_fx);
	fast_fadein_jsrp(0x020);

	while (f_sync==0)
		process_sleep(0x1);			// time for fx to run

SKIP_INTRO:
#if MK_EJBBUG
	DISPLAY_ON;
#endif

	/* POST_SEC_TRASH: */

	/* cheat code */
	if (df_nopower && gstate!=GS_AMODE)
		p1_bar=p2_bar=1;

	/* cheat code */
	if (f_one_win && gstate!=GS_AMODE)
		p1_matchw=p2_matchw=1;

	/* cant start until wingman are outta here */
	while (f_wait_for_wings!=0x0000)
		process_sleep(1);
		
	/* let the games begin */	
	return(master_mercy_entry());
}

WORD master_mercy_entry(void)
{
	f_start=1;								/* flag: start fighting !! */

	if (gstate==GS_AMODE)
		process_suicide();

	/* clock countdown */
	SET_GAME_STATE(GS_FIGHTING);

	clk_ones=clk_tens=CLOCK_INIT_DIGIT;					/* set clock */
	update_clock_ones(entry_8,clk_ones);
	update_clock_tens(entry_7,clk_tens);

	while (TRUE)
	{
		/* CLOCK3: */
		update_clock_ones(entry_8,clk_ones);

		if (clk_tens<2)
			tsound(0x17);							/* tick sound */

		/* CLOCK5: */
		if (clk_ones+clk_tens!=0)
		{
			(LONG)current_proc->pa8=(mode_of_play==1 || mode_of_play==4) ? CLOCK_SPEED*2:CLOCK_SPEED;					/* clock speed counter */
			do
			{
				/* CLOCK4: */
				process_sleep(3);							/* sleep */

				if (p1_bar==0 || p2_bar==0)
				{
					/* round_is_over */
					return(round_is_over());
				}
			} while (--((LONG)current_proc->pa8) !=0);

			if (!f_no_clock)
				clk_ones--;

			if (clk_ones<0)
			{
				clk_ones=CLOCK_INIT_DIGIT;
#if CLOCK_ON
				if (!f_no_clock)
					clk_tens--;
#endif
				update_clock_tens(entry_7,clk_tens);
			}
		}
		else
		{
			/* round_timeout */
			clk_ones=clk_tens=0;					// zero clock

			/* prend */
			killfx();
			weed_out_cheaters();
			return(ROUND_TIMEOUT);
		}
	}
}

/******************************************************************************
 Function: void results_of_round(WORD results)

 By: David Schwartz

 Date: Sept 1994

 Parameters: results - results of round of fight

 Returns: None

 Description:	Acts on the results of the round based on:
		results =
			0 - player 1 won
			1 - player 2 won
			2 - tied
			3 - timeout (clock hit zero)
******************************************************************************/
void results_of_round(WORD results)
{
	if (results==ROUND_TIMEOUT)
	{
		f_thatsall=1;							// flag: enough fighting already
		print_timeout_msg();

		/* round_is_over */
		results=round_is_over();
	}

	switch (results)
	{
		case ROUND_P1_P2_TIE:
			return;
		case ROUND_P1_WON:
			winner_status=1;						// winner status=player 1
			p1_matchw++;							// add to his match wins
			p1_rwon++;								// add to his total rounds won
			break;
		case ROUND_P2_WON:
			winner_status=2;						// winner status=player 2
			p2_matchw++;							// add to his match wins
			p2_rwon++;								// add to his total rounds won
 			break;
	}


	/* results_retp */
	update_knotches();

	if (winner_status==1)
	{
		if (p1_matchw!=2 || p1_state!=PS_ACTIVE || count_active_players()==2)
			return;
	}
	else
	{
		if (p2_matchw!=2 || p2_state!=PS_ACTIVE || count_active_players()==2)
			return;
	}

	if (map_start==NULL)
		return;

	if (*(map_start+map_position+1)!=SP_END)
		return;							// player hasn't beat game yet

	/* game_finished */
	reset_map_variables();

	gstate=GS_GAMEOVER;						/* game over */

	stack_jump(shao_kahn_death_fx);
}

WORD round_is_over(void) 
{
	killfx();
	weed_out_cheaters();

	if (p1_bar==p2_bar)						/* tie game */
		return(ROUND_P1_P2_TIE);
	else return((p1_bar>p2_bar) ? ROUND_P1_WON:ROUND_P2_WON);		/* p1 or p2 won */
}

/******************************************************************************
 Function: void master_proc_mercy(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	mercy process
******************************************************************************/
void master_proc_mercy(void)
{
	WORD rgb;

	f_start=f_thatsall=0;				// dont finish fight yet

	if (p1_bar!=0)
	{
		/* player 1 is the mericful one */
		current_proc->a10=p1_char;
		if (p1_wiar!=0)
			p1_wiar--;				// take "win in a row" from the winner
	}
	else
	{
		/* player 2 is the mericful one */
		current_proc->a10=p2_char;
		if (p2_wiar!=0)
			p2_wiar--;				// take "win in a row" from the winner
	}

	/* merc3 */
	restore_power(&p1_bar,&p2_matchw);
	restore_power(&p2_bar,&p1_matchw);			// more power to the loser

	if (clk_tens<4)
		clk_tens=4;				// make sure enough time to fight

	/* merc4 */
	update_knotches();
	update_pmsg();
	update_win_counters();
	SHOW_SCORES;

	/* fade down tune to prevent popping */
	(create_fx(FX_MERCY))->a10=current_proc->a10;			// pass merciful character

	gstate=GS_ROUND_INTRO;				// game state: intro;
	process_sleep(0x40);

	fastxfer(p1_proc,mercy_start);
	fastxfer(p2_proc,mercy_start);			// both players in stance animation

	process_sleep(0x40);

	winner_status=0;
	master_fade=0x10000;
	
	/* retrieve irqskye value */
	rgb=GET_WORD(table_o_mods[curback]);                             /* get background color*/
	if (rgb != NULL_IRQSKYE)
	{
		/* 		alpha  | 	red			   	 |   	green		  |	blue */
		irqskye=0x0001 | ((rgb & 0x7c00)>>9) | ((rgb & 0x03e0)<<1) | ((rgb & 0x001f)<<11);
	}

	round_results=current_proc->a10=master_mercy_entry();
	
	switch (mode_of_play)
	{
		case 1:
			stack_jump(two_on_two_tot1);
			break;
		case 4:
			stack_jump(three_on_three_tot1);
			break;
		default:
			stack_jump(play3);
			break;
	}	
}

void restore_power(WORD *pa5,WORD *pa6)
{
	if (*pa5==0)
	{
		*pa5=5;			// restore a little power
		*pa6=1;			// match wins = 1
	}

	return;
}

void mercy_start(void)
{
	back_to_normal();
	face_opponent(current_proc->pa8);
	disable_all_buttons;
	wait_for_start();
	reaction_exit(current_proc->pa8);
}

void wait_for_wingman(WORD *pbar) 
{
	current_proc->a10=0x40*3;
	do
	{
		process_sleep(1);
		if (f_fighter_load==0)
			current_proc->a10++;

		if (*pbar!=0)
			break;
	}
	while(--current_proc->a10>0);

	f_fighter_load=0;			// reset var
	return;
}

extern void r_ex2on2(void);

PROCESS *spawn_wingman(PROCESS *pa1,WORD pa5) 
{
	OBJECT *obj;
	OBJECT *owinner;
	PROCESS *ptemp;
	long ta11;
	short ta10;
	
	/* create replacement fighter */
	obj=make_tot_ochar_obj(pa5,0,(pa1->pa8)->odict);		// setup new character but dont load art
	ta11=SCX(0x28000);
	ta10=worldtlx.u.intpos;
	
	/* do explode stuff */
	current_proc->pdata.p_otherproc=pa1;
	current_proc->pdata.p_otherguy=pa1->pa8;
	pa1->pdata.p_flags|=PM_CORPSE;
	takeover_him(r_ex2on2);
	
	/* sans_explode */
	owinner=pa1->pdata.p_otherguy;
	if ((owinner->oxpos.u.intpos-worldtlx.u.intpos)<SCRRGT/2) 
	{
		ta10+=SCRRGT;
		flip_multi(obj);
		ta11=-ta11;
	}
	
	/* spwing3 */
	obj->oxpos.u.intpos=ta10;
	obj->oxvel.pos=ta11;
	
	dealloc_vram_mem(obj->ovcache);
	
	ptemp=CREATE(PID_TOTREP,tot_replacement_proc);
	sys_memset(&(ptemp->pdata),0,sizeof(PDATA));
	current_proc->a10=ptemp;			// new proc
	
	ptemp->pdata.p_slave=NULL;
	ptemp->pdata.p_flags|=PM_WINGMAN;
	if (pa1->pdata.p_flags & PM_WINGMAN)
		ptemp->pdata.p_flags|=PM_WINGMAN2;
	
	ptemp->pdata.p_otherguy=pa1->pdata.p_otherguy;
	ptemp->pdata.p_otherproc=pa1->pdata.p_otherproc;
	ptemp->pdata.p_joyport=pa1->pdata.p_joyport;
	
	pa1->pdata.p_flags|=PM_CORPSE;
	obj->oid=(pa1->pa8)->oid;
	ptemp->a10=(ADDRESS)pa1;			// pass losers proc
	ptemp->a11=(ADDRESS)pa1->pa8;	// pass loser obj

	return(ptemp);
}


/******************************************************************************
 Function: void check_enter_initials(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	check if its time to enter initials, if so
				setup variables and call the routine
******************************************************************************/
void check_enter_initials1(void)
{
	if (p1_state==0 || p2_state==0)
		return;

	check_enter_initials2();
}

void check_enter_initials2(void)
{
	if ( (p1_state+p2_state)==0 )
		return;								// nobody playing anymore = no initials

	if (p1_state!=PS_ACTIVE || (p1_state==PS_ACTIVE && p2_state!=PS_BUYIN))
	{
		if ( does_a0_cut_it(p1_wiar)==SYSTEM_CARRY_SET )
		{
	 		/* cei1, p1 enter initals */
	 		current_proc->pdata.p_flags=0;
	 		(ADDRESS)current_proc->pdata.p_anitab=p1_wiar;
	 		enter_initials();
	 		return;
		}
	}

	if ( p2_state!=PS_ACTIVE || (p2_state==PS_ACTIVE && p1_state!=PS_BUYIN))
	{
		if (does_a0_cut_it(p2_wiar)==SYSTEM_CARRY_SET)
		{
		 	/* cei2, p2 enter initals */
	 		current_proc->pdata.p_flags=1;
	 		(ADDRESS)current_proc->pdata.p_anitab=p2_wiar;
	 		enter_initials();
	 		return;
		}
	}

	return;
}

/******************************************************************************
 Function: void match_init(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	setup match
******************************************************************************/
void match_init(void)
{
	clear_combo_ram();
	f_gameflags=0;
}

/******************************************************************************
 Function: void round_init(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Initialize things at the start of a round
******************************************************************************/
void round_init(void)
{
	int loop;

	round_num++;						/* next round */

	if (++c_three >= 4)					/* keep track of 1-2-3 */
		c_three=1;

	/* initialize switch queue ram */
	p1_bcq[0]=(LONG)(1);					/* set ptr to first entry */
	p1_jcq[0]=(LONG)(1);					/* set ptr to first entry */
	p1_boq[0]=(LONG)(1);					/* set ptr to first entry */
	p1_joq[0]=(LONG)(1);					/* set ptr to first entry */

	p2_bcq[0]=(LONG)(1);					/* set ptr to first entry */
	p2_jcq[0]=(LONG)(1);					/* set ptr to first entry */
	p2_boq[0]=(LONG)(1);					/* set ptr to first entry */
	p2_joq[0]=(LONG)(1);					/* set ptr to first entry */

	for (loop=1;loop<=SQS;loop++)
	{
		p1_bcq[loop]=0;
		p1_jcq[loop]=0;
		p1_boq[loop]=0;
		p1_joq[loop]=0;

		p2_bcq[loop]=0;
		p2_jcq[loop]=0;
		p2_boq[loop]=0;
		p2_joq[loop]=0;
	}

	recharge_bars();					/* set strength for players */

	clk_ones=clk_tens=9;				/* set clock */

	zero_round_init_words();

	zero_round_init_longs();

	/* rinit5 */
	l_sz_decoy[0]=0;
	l_sz_decoy[1]=0;
	l_morph[0]=0;
	l_morph[1]=0;
	l_slide[0]=0;
	l_slide[1]=0;
	l_liazap[0]=0;
	l_liazap[1]=0;
	l_net[0]=0;
	l_net[1]=0;
	l_angle[0]=0;
	l_angle[1]=0;
	f_aabuse=0;
	f_upcut_rec=0;
	f_unlim_run=0;
	lem4[0]=0;
	lem4[1]=0;
	l_jaxzap2[1]=0;
	l_jaxzap2[0]=0;

	l_throw_fan[0]=l_throw_fan[1]=0;
	l_decoy[0]=l_decoy[1]=0;
	l_flash[0]=l_flash[1]=0;
	l_spear[0]=l_spear[1]=0;
	l_block_fk[0]=l_block_fk[1]=0;
	l_mileena_roll[0]=l_mileena_roll[1]=0;
	l_puddle[0]=l_puddle[1]=0;
	f_gameflags=0;
	l_swat_gun[0]=l_swat_gun[1]=0;
	l_ermac_slam[0]=l_ermac_slam[1]=0;
	l_orb_slow[0]=l_orb_slow[1]=0;
	l_orb_fast[0]=l_orb_fast[1]=0;
	l_zap[0]=l_zap[1]=0;
	l_roundh[0]=l_roundh[1]=0;
	room8[0]=room8[1]=0;

	/* agressor bars */
	p_agressor_active[0]=p_agressor_active[1]=AGRESS_NORMAL;
	p_agressor[0]=p_agressor[1]=0;
	p_agressor_view[0]=p_agressor_view[1]=0;
	p_agressor_x[0]=P1_AGRESSOR_X;
	p_agressor_x[1]=P2_AGRESSOR_X;
	p_agressor_y[0]=P1_AGRESSOR_Y;
	p_agressor_y[1]=P2_AGRESSOR_Y;
	
	f_victory_start=0;
	spec_fx=FX_NO_LOAD;

	CREATE(PID_FLASHER,flash_pmsg);
	
	f_doagress=1;				// enable agressor

	return;
}

/******************************************************************************
 Function: void round_intro_fx(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	Announce the start of a round and give clues away if needed
******************************************************************************/
void round_intro_fx(void)
{
	PROCESS *ptemp;
	
	ptemp=create_fx(FX_CHARGE_BARS);
	
	/* decide if we want to show a clue */
#if 0	
	clue_giveaway();
#else	
	if (round_num==1 && mode_of_play!=4 && gstate!=GS_AMODE) 		// no clues during 3x3
	{
		if (p1_char!=FT_MOTARO && p1_char!=FT_SK && p2_char!=FT_SK && p2_char!=FT_MOTARO && randper(40)==SYSTEM_CARRY_SET)
			clue_giveaway();
	}
#endif
	
	/* continue with round */
	print_round_num();
	ptemp=create_fx(FX_FIGHT_INTRO);

	process_sleep(0x10);
	tsound(0x10);			// say 'FIGHT'
	process_sleep(0x20);
	process_suicide();
}

/******************************************************************************
 Function: void print_round_num(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	prints the round number
******************************************************************************/
void print_round_num(void)
{
	OBJECT *ta0;
	
	if (round_num<=4)
		tsound(round_num+0x10);		// speech: ROUND # 

	lm_printf_p1(pf_round_num,round_num);
	
	ta0=(OBJECT *)&objlst2;

	/* msg3 */
	while((ta0=ta0->olink)!=NULL)
	{
		if (ta0->oid==OID_TEXT)
			ta0->oid=OID_OPT_ID0;				// change all text id --> oid_r1
	}
	
	process_sleep(0x30);
	dallobj(OID_OPT_ID0);						// erase round #
	dallobj(OID_TEXT);						// erase round #

	return;
}

/******************************************************************************
 Function: void check_battle_milestone(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	check for special event conditions as follows:
		1)	must be 2 player game
		2)	must be on battle 100
		3)  must be in round 1

******************************************************************************/
void check_battle_milestone(void)
{
	WORD ta0,ta1;

	/* time for lame space game */
	if (count_active_players()==2 && battle_num==100 && round_num==0)
	{
		ta0=p1_state;
		ta1=p2_state;
		hidden_game_load();				// take it away mark & kent
		murder_myoinit();
		p1_state=ta0;
		p2_state=ta1;
	}

	/* time for pong??? */
	if (count_active_players()==2 && battle_num==50 && round_num==0)
	{
		ta0=p1_state;
		ta1=p2_state;
		pong_game_load();				// take it away mark & kent
		murder_myoinit();
		p1_state=ta0;
		p2_state=ta1;
	}

	/* time for space invaders */
	if (count_active_players()==2 && f_silotte==1)
	{
		f_silotte=0;
		ta0=p1_state;
		ta1=p2_state;
		invaders_game_load((p1_matchw==1)?0:1,0);				// take it away mark & kent
		murder_myoinit();
		p1_state=ta0;
		p2_state=ta1;
	}

	return;
}

/******************************************************************************
 Function: void weed_out_cheaters(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	Jump to GAME OVER if:
			a.	Both players are at full strength
			b.	5th or later round
******************************************************************************/
void weed_out_cheaters(void)
{
	if (((p1_bar+p2_bar)==FULL_STRENGTH*2) || round_num>=5)
	{
 		/* weed6 */
		stack_jump(game_over);
	}

	return;
}

/******************************************************************************
 Function: void zero_round_init_words(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	initializes vars for a round to 0 (WORD type only)
******************************************************************************/
void zero_round_init_words(void)
{
	f_sans_throws=0;
	f_sans_block=0;
	f_shadows=0;
	f_fade=0;
	f_dark=0;
	f_norepell=0;
	tick=0;
	f_timeout=0;
	winner_status=0;
	f_start=0;
	f_novel=0;
	f_death=0;
	f_final_act=0;
	f_warnsound=0;
	f_thatsall=0;
	c_goro_dummy=0;
	c_kahn_dummy=0;
	f_pause=PAUSE_CLEAR;
	f_superjumps=0;
	f_no_combos=0;
	f_no_special_moves=0;
	f_p1_half_damage=f_p2_half_damage=0;
	f_bloody_kombat=0;
	f_auto_combos=0;
	return;
}

/******************************************************************************
 Function: void zero_round_init_longs(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	initializes vars for a round to 0 (LONG type only)
******************************************************************************/
void zero_round_init_longs(void)
{
	int i;

	for (i=0;i<HQS;i++)
		p1_hitq[i]=p2_hitq[i]=0;

	l_hp[0]=l_hp[1]=0;
	l_lp[0]=l_lp[1]=0;
	l_block[0]=l_block[1]=0;
	l_hk[0]=l_hk[1]=0;
	l_lk[0]=l_lk[1]=0;

	p1_xvel.pos=p2_xvel.pos=0;

	return;
}

/******************************************************************************
 Function: WORD count_active_players(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: # of active players

 Description:	Determines number of human players in game
******************************************************************************/
WORD count_active_players(void)
{
	WORD i=0;

	if (p1_state==PS_ACTIVE)
		i++;

	if (p2_state==PS_ACTIVE)
		i++;

	return(i);
}

/******************************************************************************
 Function: WORD set_drone_ochar(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: SYSTEM_CARRY_SET - end of game reached
		  SYSTEM_CARRY_CLR  - end of game not reached

 Description:	Determines who is the next drone opponent based on the player
				up's map position
******************************************************************************/
WORD set_drone_ochar(void)
{
	WORD *pchar;
	WORD ta0;

	pchar=drone_char_point_a6();
	ta0=current_drone_a0();

	if (ta0==SP_END)
		return(SYSTEM_CARRY_SET);

	if (map_start==NULL)
		return(SYSTEM_CARRY_CLR);	// no map = dont set ochar

	*pchar=ta0;
	return(SYSTEM_CARRY_CLR);
}


WORD *drone_char_point_a6(void)
{
	if (who_is_alone()==1)
	{
		return(&p2_char);
	}
	else
	{
		return(&p1_char);
	}
}

short current_drone_a0(void)
{
	short ta0;

	if (map_start==NULL)
		return(0);

	ta0=*(map_start+map_position);

	if (ta0 & 0x80) 
	{
		/* endurance stuff */
		(long)current_proc->pdata.p_slave=0;		// save offset here
		ta0&=0x7f;					// strip flag bit
		ta0=*endurance_tables[ta0];
	}

	return(ta0);		// next "enemy offset" to battle with
}

/******************************************************************************
 Function: WORD who_is_alone(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: 1 ----> player 1 is the only human
		  2 ----> player 2 is the only human

 Description:	Determines which player is human
******************************************************************************/
WORD who_is_alone(void)
{
	if (p1_state==PS_ACTIVE)
	{
		if (p2_state==PS_ACTIVE)					/* error if player 2 active */
			while (TRUE);
		return(1);
	}
	else if (p2_state==PS_ACTIVE)
			return(2);

	return(1);
}

/******************************************************************************
 Function: void inc_winners_wiar(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Increment winners (WIAR variable)
******************************************************************************/
void inc_winners_wiar(void)
{
	WORD *pstate,*pwiar;

	if ((winner_status-1)!=0)
	{
		pstate=&p2_state;					/* player 2 wins in a row  */
		pwiar=&p2_wiar;
	}
	else
	{
		pstate=&p1_state;					/* player 1 wins in a row  */
		pwiar=&p1_wiar;
	}

	if (*pstate!=PS_ACTIVE)					/* winner active (ie..human)??? */
		*pwiar=0;							/* nope... */
	else (*pwiar)++;						/* human get another win in a row */
}

/******************************************************************************
 Function: void is_finish_him_allowed(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: SYSTEM_CARRY_SET - allow finish him
 		  SYSTEM_CARRY_CLR - disallow finish him

 Description:	handle things for FINISH HIM
******************************************************************************/
WORD is_finish_him_allowed(void)
{
	switch (p1_char)
	{
		case FT_MOTARO:
//			return(SYSTEM_CARRY_CLR);
		case FT_SK:
			if (p1_bar!=0 && p2_char!=FT_SK && p2_char!=FT_MOTARO)
				return(SYSTEM_CARRY_SET);
			else return(SYSTEM_CARRY_CLR);
				
	}

	switch (p2_char)
	{
		case FT_MOTARO:
//			return(SYSTEM_CARRY_CLR);
		case FT_SK:
			if (p2_bar!=0 && p1_char!=FT_SK && p1_char!=FT_MOTARO)
				return(SYSTEM_CARRY_SET);
			else return(SYSTEM_CARRY_CLR);
	}

	if ((clk_ones+clk_tens)==0)
		return(SYSTEM_CARRY_CLR);	// no time left
	else return(SYSTEM_CARRY_SET);
}

/******************************************************************************
 Function: void finish_him_sequence(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	handle things for FINISH HIM
******************************************************************************/
void finish_him_sequence(void)
{
	WORD fatal_timer;

	if (is_finish_him_allowed()==SYSTEM_CARRY_CLR)
		return;

	winner_status=3;						// flag: finish him mode

	f_no_special_moves=0;					// allow fatalities to happen

	play_finish_tune();
	
	finish_him_or_her();

	fatality_wait(0x30);

	/* over? */
	if (f_thatsall==0)
	{
		fatal_timer=fatality_wait(0xb0);

		/* check if fatality started */
		if (fatal_timer!=0)
		{
			fatal_timer=0x40*9;
			do
			{
				process_sleep(1);		// wait until death blow complete or time up
			}
			while((f_death!=-1) && (--fatal_timer>0));
		}
	}

	return;
}

/******************************************************************************
 Function: WORD fatality_wait(WORD waittime)

 By: David Schwartz

 Date: Oct 1994

 Parameters: waittime - max time i will wait

 Returns: timed out = 0
		  fatality started > 0

 Description:	wait around for the FATALITY to start
******************************************************************************/

WORD fatality_wait(WORD waittime)
{
	do
	{
		current_proc->p_comp_flag=PC_FATAL_WAIT;
		process_sleep(1);
		current_proc->p_comp_flag=PC_CLEAR;

		/* fatality_waiting */
		if (f_death!=0)					// death blow happened
			return(waittime);

		if (f_thatsall!=0)				// ran outta game time
			return(0);

		if ((p1_bar==0 && p2_state!=0) || (p2_bar==0 && p1_state!=0))
		{
			if (f_unlim_fatal && f_victory_start==0)				// unlimited time, keep timer big
				waittime=20;
		}
	}
	while(--waittime != 0);

	return(0);
}

/******************************************************************************
 Function: void end_of_match_chores(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	do this when a match is over (2 out of 3)
******************************************************************************/
void end_of_match_chores(void)
{
	advance_curback();

	battle_num++;											// next battle please !!

	round_num=c_three=f_mercy=0;

	dallobj(OID_TEXT);										// erase msg

	p1_matchw=p2_matchw=p1_perfect=p2_perfect=0;			// reset match wins and perfect for both dudes

	adv_winner_map();										// winner: move on!!
	diff_adjust();											// end of round diff adjust

	return;

}

/******************************************************************************
 Function: void loser_in_buyin(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	stick loser in buyin state
******************************************************************************/
void loser_in_buyin(void)
{
	WORD *pstate;

	pstate=(winner_status==1)? &p2_state:&p1_state;

	if (*pstate==PS_ACTIVE)			// loser a human
		*pstate=PS_BUYIN;			// loser = human --> he is in buyin mode

	return;
}

/******************************************************************************
 Function: void print_timeout_msg(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	when a round times out we call this to interupt things & print "TIMES UP"
******************************************************************************/
char txt_times_up[]="TIME IS UP";
void print_timeout_msg(void)
{
	send_code_a3(0);				// stop music

	//send_code_a3(ST_SZ_ICE_UP);			// gong

	f_novel=f_timeout=1;

	scrolly.pos=0;
	stop_scrolling();

	MURDER;

	p15_centered(txt_times_up,SCX(0xc8),SCY(0x38)+16);

	/* rto6 */
	process_sleep(0x50);

	dallobj(OID_FX);

	return;
}

WORD tbl_ochar_curbacks[]=
{
	FT_MOTARO,BKGD_TOWER_MOD,		// motaro = curback = 4
	FT_SK,BKGD_PIT_MOD,
	FT_OLDSMOKE,BKGD_MONK_MOD,
	FT_KAMEL,BKGD_FOREST_MOD,
	0
};

void ochar_force_curback(void) 
{
	WORD *ta7;

	if (count_active_players()==2)
		return;

	ta7=tbl_ochar_curbacks;
	
	while (*ta7!=0)
	{
		if ((*ta7==p1_char && p1_state != PS_ACTIVE) || (*ta7==p2_char && p2_state != PS_ACTIVE)) 
		{
			curback=*(ta7+1);
			break;
		}
		ta7+=2;
	}

	return;
}

/******************************************************************************
 Function: void reset_map_variable(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	reset map variables
******************************************************************************/
void reset_map_variables(void)
{
	map_position=0;
	map_start=0;
	perform=0;
	credits=GAME_CREDITS;			// # of 1 player credits
	return;
}

/******************************************************************************
 Function: void adv_winner_map(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	advance winners map pointer to next position
******************************************************************************/
void adv_winner_map(void)
{
	WORD winner;

	if (count_active_players()!=2) 						// both human players -->skip
	{
		/* adv2 */
		winner=(p1_state==PS_ACTIVE)? 1:2;				// set which player won

		if (winner_status==winner) 						// check if winner is human
		{
			map_position++;
		}
		else
		{
			/* adv7 */
			c_1p_tries++;								// count # of 1p tries!!
		}
	}

	return;
}

WORD ladderorder_a1(void) 
{
	return((ladder<=3)?ladder:1);
}

/******************************************************************************
 Function: void diff_adjust(void)

 By: David Schwartz

 Date: Oct 1994

 Parameters: None

 Returns: None

 Description:	end of round adjustment of the variable @diff
******************************************************************************/
short ladder_diff_minimums[5][4]=
{
	{0,0,0,0},
	{0,0,1,1},
	{0,1,2,3},
	{1,2,3,3},
	{2,3,3,3},
};

short ladder_diff_slopes[5][4]=
{
	{0,0,1,1},
	{0,1,1,2},
	{1,1,2,2},
	{1,2,2,3},
	{2,2,3,3},
};

short cmos_diff_perform[]={4,3,3,2,2};
short cmos_diff_perform_max[]={3,5,7,8,9};

void diff_adjust(void)
{
	WORD *pstate;
	short adjtbl;
	WORD ta1;

	pstate=(winner_status==1) ? &p1_state:&p2_state;

	if (*pstate==PS_ACTIVE)
	{
		/* winner is a human ---> get harder */
		if (count_active_players()==2)
			return;						// don't adjust if a two player game

		perform++;

		if (perform>=cmos_diff_perform[cmos_diff]) 
		{
			stuff_a0_diff(cmos_diff_perform_max[cmos_diff]);		
			return;
		}

		/* dadj3 */
		ta1=ladderorder_a1();
		stuff_a0_diff(diff+ladder_diff_slopes[cmos_diff][ta1]);	

	}
	else
	{
		/* winner is a drone */
		--perform;

		if (perform>-cmos_diff_perform[4-cmos_diff]) 			
		{
			/* wid3 */
			stuff_a0_diff(diff-1);
		}
		else
		{
			stuff_a0_diff(0);
		}
	}

	/* dadj5 */
	adjtbl=ladder_diff_minimums[cmos_diff][ladderorder_a1()];

	if (diff<adjtbl)
		stuff_a0_diff(adjtbl);

	return;
}

void stuff_a0_diff(short ta0) 
{
	if (ta0<0)
		ta0=0;

	if (ta0>9)
		ta0=9;				// to big=just use 9

	diff=ta0;
	
	return;
}

/******************************************************************************
 Function: void amode_demo_game(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	attract mode game process
******************************************************************************/
extern WORD JSCORE_P[];
extern WORD MSCORE_P[];
extern WORD KSCORE_P[];
void amode_demo_game(void)
{
	WORD ta1;
	WORD cb;

	ta1=f_nosound;
	cb=curback;
	game_init();
	f_nosound=ta1;
	curback=cb;

	object_initialize();
	setup_score_ram();
	get_fore_pal(SCORE_P);
	get_fore_pal(JSCORE_P);
	get_fore_pal(MSCORE_P);
	get_fore_pal(KSCORE_P);
	get_fore_pal(LOADING_P);

//	curback=randu(11)-1;

	stuff_a0_diff(6);

	f_special_match=0;
	play_1_round();

	wait_forever();
}

/******************************************************************************
 Function: void flash_pmsg(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	process to flash player messages, wait until there is one to flash
******************************************************************************/
void flash_pmsg(void)
{
	while (entry_5->disp_flag!=0 || entry_6->disp_flag!=0)
	{
		process_sleep(3);					// wait for legitimate message
	}

	flash_pmsg2();
}

/******************************************************************************
 Function: void flash_pmsg2(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	process to flash the player messages
******************************************************************************/
void flash_pmsg2(void)
{
	BYTE da10,da11;

	/* pmsg_blink_loop */
	while (TRUE)
	{
		da10=entry_6->disp_flag;
		da11=entry_5->disp_flag;

		if (p1_state!=PS_ACTIVE)
			entry_6->disp_flag=0;

		/* fpmsg5 */
		if (p2_state!=PS_ACTIVE)
			entry_5->disp_flag=0;

		/* fpmsg6 */
		process_sleep(14);

		/* fpmsg7 */
		if (entry_6->disp_flag==0)				// p1 still zero
			entry_6->disp_flag=da10;			// yes, then restore to normal

		/* fpmsg8 */
		if (entry_5->disp_flag==0)				// p2 still zero
			entry_5->disp_flag=da11;			// yes, then restore to normal

		/* fpmsg9 */
		process_sleep(14);
	}
}

/******************************************************************************
 Function: void finish_him_or_her(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	tell player to finish off the other dude
******************************************************************************/
void finish_him_or_her(void)
{
	OBJECT *pobj;

	pobj=(p1_bar==0)? p1_obj : p2_obj;

	switch (pobj->ochar)
	{
		case FT_LIA:
		case FT_SONYA:
		case FT_SG:
		case FT_KITANA:
		case FT_JADE:
		case FT_MILEENA:
		case FT_KAMEL:
			create_fx(FX_FINISH_HER);
			break;
		default:
			create_fx(FX_FINISH_HIM);
			break;
	}

	return;
}

/******************************************************************************
 Function: void advance_curback(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	change current background
******************************************************************************/
WORD hidden_included[]=
{
	BKGD_BATTLE_MOD,	// wasteland
	BKGD_KUNGFU2_MOD,	// kungfu 2 
	BKGD_DEADPOOL_MOD,	// deadpool
	BKGD_CITY_MOD,		// rooftop city
	BKGD_LIAR_MOD,		// goro lair
	BKGD_ARMORY_MOD,	// armory
	BKGD_TOMB_MOD,		// spiked tomb
	BKGD_HADES_MOD,		// hell
	BKGD_CAVE_MOD,		// cave
	BKGD_FOREST_MOD,	// living forest
	BKGD_MONK_MOD,		// monk portal
	BKGD_SUBWAY_MOD,	// subway
	BKGD_STREET_MOD,	// street
	BKGD_KUNGFU5_MOD,	// kungfu 5 
	BKGD_BELL_MOD,		// bell tower
	BKGD_MK2PITSTAR_MOD,	// mk2pit module
	BKGD_SKTOWER_MOD,	// monk tower
	BKGD_WATER_MOD,		// water bridge
	BKGD_DESERT_MOD,	// desert
	BKGD_HIDDEN_MOD,	// mk3 hidden portal
	BKGD_GRAVE_MOD,		// grave
	BKGD_MK2PIT_MOD,	// mk2pit module
	BKGD_PIT_MOD,		// pit 3
	BKGD_SOUL_MOD,		// soul
	BKGD_TOWER_MOD,		// tower 
	BKGD_LOST_MOD,		// frozen "lost" background
	BKGD_BRIDGE_MOD,	// bridge
	BKGD_KUNGFU5BOT_MOD,	// mk1 pit bottom
	BKGD_TEMPLE_MOD,	// church
};

void advance_curback(void)
{
	WORD *ta1;

	c_curback++;
	
	ta1=hidden_included;
	if (c_curback>=MAX_BACKGROUNDS)
		c_curback=0;

	curback=*(ta1+c_curback);

	return;
}

/******************************************************************************
 Function: void pause_setup(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	setup to pause the game
			1)	set pause flag
			2)	set process ID to pause class
			3)	dim screen
			4)	print pause message
******************************************************************************/
char txt_paused[]="PAUSED";
char txt_quit[]="QUIT";
char txt_cont[]="CONTINUE";
char txt_yess[]="YES";
char txt_no[]="NO";
char txt_sure[]="ARE YOU SURE?";

extern LONG max_dsize;
void pause_setup(WORD poffset)
{
	PROCESS *proc_ptr;
	OBJECT *obj;

	f_pause=(poffset==PLAYER1_TYPE) ? PAUSE_P1_INIT:PAUSE_P2_INIT;	// game is now paused

	process_kill_class(PID_FADE,0xffff);

	current_proc->procid=PID_PAUSE;			// set id, so process can run during pause
	
	/* draw background box */
	obj=make_solid_object(0x0001,160,56);
	obj->opal=get_fore_pal(WHITE_p);
	obj->oxpos.u.intpos=80+worldtlx.u.intpos;
	obj->oypos.u.intpos=60+worldtly.u.intpos;
	obj->oflags|=M_XLU_ON;
	obj->oflags|=0xa000;			// set xlu value
	obj->oid=OID_CURSOR4;
	obj->ozval=0;		
	insert_object(obj,&objlst2);
	
	p15_centered(txt_paused,160,65);		// print pause message

	/* change all PID_FADE process to PID_PAUSE_FADE */
	//if (f_blast==0 && process_exist(PID_ROCK,0xffff)==NULL)
	//	pause_dimmer();						// fade screen, if not blasting through background, (pause bug)

	proc_ptr=(PROCESS *)&active_head;
	while (proc_ptr->plink != NULL)
	{
		proc_ptr=proc_ptr->plink;

		if (proc_ptr->procid==PID_FADE)
			proc_ptr->procid=PID_PAUSE_FADE;
	}

	return;
}

void pause_color(WORD pa0,WORD *color) 
{
	OBJECT *obj;

	obj=objlst2;

	while (obj!=NULL)
	{
		if (obj->oid==pa0)
			swpal(color,obj);

		obj=obj->olink;
	}

	return;
}

void pause_id_change(WORD pa0)
{
	OBJECT *obj;

	obj=objlst2;

	while (obj!=NULL)
	{
		if (obj->oid==OID_TEXT)
			obj->oid=pa0;

		obj=obj->olink;
	}

	return;
}

#define pause_hilite(_pa0) pause_color(_pa0,YELLOW_p)
#define pause_unhilite(_pa0) pause_color(_pa0,WHITE_p)
/******************************************************************************
 Function: void pause_hold(WORD poffset)

 By: David Schwartz

 Date: Mar 1995

 Parameters: poffset - offset of player that paused game

 Returns: None

 Description:	wait for pause to be released and then clear pause state
			1) kill pause message objects
			2) undim screen
			3) clear pause flag
******************************************************************************/
void pause_hold(WORD poffset)
{
	WORD *joypad;
	short pause_state;
	short pause_pos;
	short debounce=24;

	lights_on_hit();				// turn lights on to see pause message

	joypad=(poffset==PLAYER1_TYPE) ? (WORD*)&swcurr.u.p1pad:(WORD *)&swcurr.u.p2pad;

	/* pause music and kill effects */
	wess_seq_pauseall(YesMute,REMEMBER_MUSIC|REMEMBER_SNDFX);

	f_pause-=2;

	/* delete old text */
	pause_id_change(OID_CURSOR3);		// change pause message oid
	p15_centered(txt_cont,160,85);		// print pause message
	pause_id_change(OID_CURSOR1);		// change line 1 ids
	pause_hilite(OID_CURSOR1);

	p15_centered(txt_quit,160,100);		// print pause message
	pause_id_change(OID_CURSOR2);		// change line 2 ids
	pause_unhilite(OID_CURSOR2);

	/* set state */
	pause_state=0;					// on no menus
	pause_pos=0;


	/* wait for user to do something */
	while (1)
	{
		while (--debounce>0)
			process_sleep(1);

		debounce=0;
		process_sleep(1);

		if ((*joypad) & MASK_START)
			goto EXIT_PAUSE;

		if ((*joypad) & MASK_JUP && pause_pos==1)  
		{
			pause_hilite(OID_CURSOR1);
			pause_unhilite(OID_CURSOR2);
			pause_pos=0;
			debounce=1;
		}

		if ((*joypad) & MASK_JDOWN && pause_pos==0)  
		{
			pause_hilite(OID_CURSOR2);
			pause_unhilite(OID_CURSOR1);
			pause_pos=1;
			debounce=1;
		}

		switch (pause_state)
		{
			case 0:		// CONTINUE OR QUIT
				if ((*joypad) & MASK_SELECT) 
				{
					debounce=12;
				 	if (pause_pos==0) 
				 	{
						goto EXIT_PAUSE;
				 	}
					else
					{
						dallobj(OID_CURSOR1);								// kill all text
						dallobj(OID_CURSOR2);								// kill all text
						dallobj(OID_CURSOR3);								// kill all text

						p15_centered(txt_sure,160,65);		// print pause message
						pause_id_change(OID_CURSOR3);		// change line 1 ids

						p15_centered(txt_no,160,85);		// print pause message
						pause_id_change(OID_CURSOR1);		// change line 1 ids
						pause_hilite(OID_CURSOR1);

						p15_centered(txt_yess,160,100);		// print pause message
						pause_id_change(OID_CURSOR2);		// change line 2 ids
						pause_unhilite(OID_CURSOR2);

						/* set state */
						pause_state++;
						pause_pos=0;
					}
				}
		
				break;

			case 1:		// NO OR YES
				debounce=12;
				if ((*joypad) & MASK_SELECT) 
				{
				 	if (pause_pos==0) 
				 	{
						goto EXIT_PAUSE;
				 	}
					else
					{
						f_pause=0;

						/* ABORT GAME & RESET TO TITLE PAGE */
						gstate=GS_GAMEOVER;

						DONT_SHOW_SCORES;
						reset_map_variables();
						diff=0;

						p1_state=p2_state=0;				// take players out of game

						clr_scrn();
						murder_myoinit_score();
						stack_jump(gover_amode_entry);
					}
				}
				break;
		}
	}

EXIT_PAUSE:
	/* start been pushed time to fight again */
	dallobj(OID_CURSOR1);								// kill all text
	dallobj(OID_CURSOR2);								// kill all text
	dallobj(OID_CURSOR3);								// kill all text
	dallobj(OID_CURSOR4);

	//if ( f_blast==0 && process_exist(PID_ROCK,0xffff)==NULL)
	//	pause_undimmer();					// un fade screen

	f_pause-=2;							// move from pause to thaw state

	/* start music up */
	wess_seq_restartall(YesVoiceRestart);

	return;
}

/******************************************************************************
 Function: void play_background_tune(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	start a background tune playing
******************************************************************************/
WORD round_1_tunes[]=
{
	MUSIC_TRAINTUN,
	MUSIC_STREET,
	MUSIC_BANK,
	MUSIC_ROOF,
	MUSIC_PIT,
	MUSIC_BRIDGE,
	MUSIC_GREEN,
	MUSIC_ROOF,
	MUSIC_CHURCH,
	MUSIC_GRAVE,
	MUSIC_PIT,
	MUSIC_PIT,
	MUSIC_TRAINTUN,
	MUSIC_PIT,
	MUSIC_BANK,
	MUSIC_ROOF,
	MUSIC_SPECIAL,
	MUSIC_SPECIAL,
	MUSIC_BANK,
	MUSIC_BRIDGE,
	MUSIC_GRAVE,
	MUSIC_GREEN,
	MUSIC_PIT,
	MUSIC_ROOF,
	MUSIC_SPECIAL,
	MUSIC_STREET,
	MUSIC_TRAINTUN,
	MUSIC_PIT,
	MUSIC_ROOF,
	MUSIC_BANK,
	MUSIC_BRIDGE,
	MUSIC_GRAVE,
};

WORD winner_tunes[]=
{
	MUSIC_TRAINTUE,
	MUSIC_STREETEN,
	MUSIC_BANKEND,
	MUSIC_ROOFEND,
	MUSIC_PITEND,
	MUSIC_BRIDGEEN,
	MUSIC_GREENEND,
	MUSIC_ROOFEND,
	MUSIC_CHURCHEN,
	MUSIC_GRAVEEND,
	MUSIC_PITEND,
	MUSIC_PITEND,
	MUSIC_TRAINTUE,
	MUSIC_PITEND,
	MUSIC_BANKEND,
	MUSIC_ROOFEND,
	MUSIC_SPECIALE,
	MUSIC_SPECIALE,
	MUSIC_BANKEND,
	MUSIC_BRIDGEEN,
	MUSIC_GRAVEEND,
	MUSIC_GREENEND,
	MUSIC_PITEND,
	MUSIC_ROOFEND,
	MUSIC_SPECIALE,
	MUSIC_STREETEN,
	MUSIC_TRAINTUE,
	MUSIC_PITEND,
	MUSIC_ROOFEND,
	MUSIC_BANKEND,
	MUSIC_BRIDGEEN,
	MUSIC_GRAVEEND,
};

WORD finish_tunes[]=
{
	MUSIC_TRAINTUF,
	MUSIC_STREETFI,
	MUSIC_BANKFINI,
	MUSIC_ROOFFINI,
	MUSIC_PITFINIS,
	MUSIC_BRIDGEFI,
	MUSIC_GREENFIN,
	MUSIC_ROOFFINI,
	MUSIC_CHURCHFI,
	MUSIC_GRAVEFIN,
	MUSIC_PITFINIS,
	MUSIC_PITFINIS,
	MUSIC_TRAINTUF,
	MUSIC_PITFINIS,
	MUSIC_BANKFINI,
	MUSIC_ROOFFINI,
	MUSIC_SPECIALF,
	MUSIC_SPECIALF,
	MUSIC_BANKFINI,
	MUSIC_BRIDGEFI,
	MUSIC_GRAVEFIN,
	MUSIC_GREENFIN,
	MUSIC_PITFINIS,
	MUSIC_ROOFFINI,
	MUSIC_SPECIALF,
	MUSIC_STREETFI,
	MUSIC_TRAINTUF,
	MUSIC_PITFINIS,
	MUSIC_ROOFFINI,
	MUSIC_BANKFINI,
	MUSIC_BRIDGEFI,
	MUSIC_GRAVEFIN,
};

WORD get_background_tune(void)
{
	/* start da tune */
	if ( curback>MAX_BACKGROUNDS )
	{
		return(MUSIC_SPECIAL);
	}
	else
	{
		return(round_1_tunes[curback]);
	}
}

void play_background_tune(void)
{
	if (test_gameflag(M_GF_NOMUSIC))
		return;
		
	sound_music_start(get_background_tune());
	
	return;
}

void play_finish_tune(void)
{
	WORD song;

	if (test_gameflag(M_GF_NOMUSIC))
		return;
		
	/* start da tune */
	if ( curback>MAX_BACKGROUNDS )
		song=MUSIC_SPECIALF;
	else song=finish_tunes[curback];

	sound_music_start(song);
	
	return;
}

void play_ending_chord(void)
{
	WORD song;

	if (test_gameflag(M_GF_NOMUSIC))
		return;
		
	
	/* music on */
	if (f_death!=-1)			 // if death blow = let gloom linger
	{
		/* start da tune */
		if ( curback>MAX_BACKGROUNDS )
			song=MUSIC_SPECIALE;
		else song=winner_tunes[curback];
		
		sound_music_start(song);

	}

	return;
}

/*************************************************************************
	BRIEF CASE STUFF
*************************************************************************/
LONG brief_case_codes[]=
{
	0x100100,		//   0 - r_throwing_disabled
	0x020020,		//   1 - r_blocking_disabled
	0x033000,		//   2 - r_p1_handicap
	0x000033,		//   3 - r_p2_handicap
	0x688422,		//   4 - r_dark_fighting
	0x460460,		//   5 - r_switcheroo
	0x987666,		//   6 - r_jackbot_easy
	0x707000,		//   7 - r_p1_supercap
	0x000707,		//   8 - r_p2_supercap
	0x642468,		//   9 - r_space_game
	0x969141,		//   a - r_wf_motaro
	0x033564,		//   b - r_wf_shao
	0x769342,		//   c - r_wf_noob
	0x282282,		//   d - r_nofear_clue
	0x987123,		//   e - r_no_powerbars
	0x788322,		//   f - r_uppercut_recovery
	0x466466,		//  10 - r_unlim_run
	0x985125,		//  11 - r_psycho_kombat
	0x123926,		//  12 - r_intro_message
	0x205205,		//  13 - r_sf_smoke
/*
* ultimate
*/
	0x044440,		//  14 - r_nopower (*)
	0x300300,		//  15 - r_silent_kombat (*)
	0x444444,		//  16 - easy randper
	0x880088,		//  17 - r_curback_subway (*)
	0x079035,		//  18 - r_curback_street (*)
	0x343343,		//  19 - r_curback_kung5 (*)
	0x880220,		//  1a - r_curback_ktower (*)
	0x077022,		//  1b - r_curback_bridge (*)
	0x123901,		//  1c - r_curback_soul (*)
	0x091190,		//  1d - r_curback_bell (*)
	0x600040,		//  1e - r_curback_temple (*)
	0x666333,		//  1f - r_curback_grave (*)
	0x820028,		//  20 - r_curback_pit3 (*)
	0x002003,		//  21 - r_curback_river
	0x666444,		//  22 - r_curback_hell (*)
	0x004700,		//  23 - r_curback_kkave (*)
	0x330033,		//  24 - r_curback_desert (*)
	0x933933,		//  25 - r_curback_subzero (*)
	0x050050,		//  26 - r_curback_noob (*)
	0x999999,		//  27 - revision #
	0x010010,		//  28 - r_throwing_encouraged
	0x227227,		//  29 - r_explode_2on2 (*)
	0x022220,		//  2a - r_explode_2on2 / no throws (*)
	0x550550,		//  2b - r_see_da_tour
	0x717313,		//  2c - r_bs_klue1
	0x448844,		//  2d - r_vinikour_quote
	0x122221,		//  2e - r_ferrier_quote
	0x004400,		//  2f - r_boon_quote

/*
 * SONY CODES
*/
	0x722722,		// 30 - disable combos
	0x321789,		// 31 - allow super jumps
	0x555556,		// 32 - no special moves
	0x390000,		// 33 - p1 inflict 1/2 damage
	0x000390,		// 34 - p2 inflict 1/2 damage
	0x390390,		// 35 - p1 & p2 inflict 1/2 damage
	0x975310,		// 36 - regen powerbar
	0x024689,		// 37 - super endurance
	0x040404,		// 38 - real kombat
	0x246246,		// 39 - r_pong_game

/*
 * TRILOGY KODES
*/
	0x121121,		//  3a - r_curback_kung2 (*)
	0x222222,		//  3b - r_curback_deadpool (*)
	0x212212,		//  3c - r_curback_wasteland (*)
	0x919919,		//  3d - r_curback_city rooftop (*)
	0x191191,		//  3e - r_curback_armory (*)
	0x543345,		//  3f - r_curback_forest (*)
	0x101010,		//  40 - r_curback_tower (*)
	0x007007,		//  41 - r_curback_portal (*)
	0x000666,		//  42 - r_curback_lair (*)
	0x566566,		//  43 - r_curback_tomb (*)
	0x166661,		//  44 - r_curback_pit (*)
	0x606606,		//  45 - r_curback_bridgestar (*)
	0x109901,		//  46 - bloody kombat
	0x484484,		// 	47 - auto combos
	0x123321,		// 	48 - winner fight kameleon
	0x137246,		// 	49 - fight a bottom of pit 1
	0x202808,		//  50 - babalities are reverseable
	0x524425,		//  51 - mk clue
	0x345987,		//  52
	0x246975,		// 53 - bogus clue
	0x000000,		// terminate list
};

/******************************************************************************
 Function: void try_kombat_kodes(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	try brief case, search for secret codes
******************************************************************************/
void try_kombat_kodes(void)
{
	LONG ta5=0;						// a5-players attempt to open
	LONG *ta0;

	if (gstate==GS_AMODE)
		return;

	if (round_num!=1) 
	{
		do_round_jsrps();
		return;
	}

	ta5|=(combo_6<<(4*0));
	ta5|=(combo_5<<(4*1));
	ta5|=(combo_4<<(4*2));
	ta5|=(combo_3<<(4*3));
	ta5|=(combo_2<<(4*4));
	ta5|=(combo_1<<(4*5));
	
	/* walk down the table of codes */
	kode_offset=-1;		// assume failure 
	
	ta0=brief_case_codes;
	current_proc->a7=0;
	/* brief3 */
	while (*ta0!=0)
	{
		if (*ta0==ta5)
		{
			kode_offset=current_proc->a7;
			break;
		}
		current_proc->a7++;
		ta0++;
	}

	/* briefcase_failure */
	combo_1=combo_2=combo_3=0;
	combo_4=combo_5=combo_6=0;

	do_round_jsrps();

	return;
}

/******************************************************************************
******************************************************************************/
extern char txt_space_game_intro[];
void hidden_game(void);
void hidden_game_load(void)
{
	gstate=GS_SPACE_GAME;
	amode_init_no_score();

	clr_scrn();
	mk3_gradient(GREEN_GRAD);
	sound_music_start(MUSIC_YOUWINTU);
	
	pds_centered_soff(txt_space_game_intro,160,SCY(0x50)-8-10);

	DISPLAY_ON;
	fadein_jsrp(0x40*6);

	loadoverlay(SYS_MARK_OVL);
	hidden_game();

	return;
}

/******************************************************************************
******************************************************************************/
extern char txt_invade_game_intro[];
WORD space_invade(WORD pa0);
void invade_clue_system(WORD numclues,WORD maxclue);
void invaders_game_load(WORD pa0,WORD type)
{
	WORD status;
	
	gstate=GS_SPACE_GAME;
	amode_init_no_score();

	clr_scrn();
	mk3_gradient(RED_GRAD);
	sound_music_start(MUSIC_YOUWINTU);
	
	pds_centered_soff(txt_invade_game_intro,160,SCY(0x50)-8-10);

	DISPLAY_ON;
	fadein_jsrp(0x40*6);

	loadoverlay(SYS_MARK_OVL);
	status=space_invade(pa0);

	if (status==SYSTEM_CARRY_SET)
	{
		if (type==1)
			invade_clue_system(3,14) ;
		else invade_clue_system(2,9) ;
	}
	
	return;
}

/******************************************************************************
******************************************************************************/
extern char txt_pong_game_intro[];
extern FNTSETUP pf_dave_smallc[];
void play_pong(void);
void pong_game_load(void)
{
	gstate=GS_SPACE_GAME;
	amode_init_no_score();


	clr_scrn();
	mk3_gradient(BLUE_GRAD);
	sound_music_start(MUSIC_YOUWINTU);
	
	lm_setup(pf_dave_smallc);
	fnt_state.fnt_posx=160;
	fnt_state.fnt_posy=16+SCY(0x50);
	fnt_state.fnt_spacing=0xffff;
	mk_printf(txt_pong_game_intro);

	DISPLAY_ON;
	fadein_jsrp(0x40*6);

	loadoverlay(SYS_PONG_OVL);
	play_pong();

	return;
}

void baby_flash(void) 
{
	white_flash();
	process_suicide();
}

typedef struct 
{
	WORD c_char;		// clue character
	char **c_clues;		// ptr to clue table
} CLUES;

char txt_km1[]="I AM CALLED KAMELEON";					
char txt_km2[]="TREES AND SHRUBS ARE PLACES TO MEET";
char txt_km3[]="YOU CAN NOT DEFEAT ME";
char txt_km4[]="MORE THEN TWO WILL KEEP ME AWAY";
char txt_km5[]="ONE IS NOT ENOUGH";
char txt_km6[]="I WILL BE HARD TO SEE";
char txt_km7[]="START ON THE BRIDGE OF STARS";
char txt_km8[]="I AM THE MASTER OF DISGUISE";
char txt_km9[]="WAIT FOR TOASTY";
char txt_km10[]="ARE YOU A WORTHY CHALLENGER?";
char *kamel_clues[]= 
{
	txt_km1,
	txt_km2,
	txt_km3,
	txt_km4,
	txt_km5,
	txt_km6,
	txt_km7,
	txt_km8,
	txt_km9,
	txt_km10,
};

char txt_sm1[]="START WITH SMOKE";
char txt_sm2[]="PROVE YOURSELF";
char txt_sm3[]="THE KEYS TO FINDING ME";
char txt_sm4[]="RELEASE THE INNER SOUL";
char txt_sm5[]="I WAS ONCE HUMAN";
char txt_sm6[]="START BEFORE THE FIGHT ";
char txt_sm7[]="FROSTY";
char txt_sm8[]="AWAY WE GO";
char txt_sm9[]="RUN AND BLOCK";
char txt_sm10[]="HI PUNCH AND HI KICK";
char *smoke_clues[]= 
{
	txt_sm1,
	txt_sm2,
	txt_sm3,
	txt_sm4,
	txt_sm5,
	txt_sm6,
	txt_sm7,
	txt_sm8,
	txt_sm9,
	txt_sm10,
};

char txt_mt1[]="I AM AT YOUR CONTROL";
char txt_mt2[]="AWAY YOU WILL SEE";
char txt_mt3[]="SEARCH FOR ME IN THE WASTELAND";
char txt_mt4[]="BRING ON GORO";
char txt_mt5[]="BRING ON KINTARO";
char txt_mt6[]="I LIKE JADES DESERT";
char txt_mt7[]="BEFORE ONE FIGHTS IS THE TIME";
char txt_mt8[]="KICKS ARE THE KEY";
char txt_mt9[]="I WILL CRUSH ALL";
char txt_mt10[]="THE TOWER IS A FAVORITE";
char *motaro_clues[]= 
{
	txt_mt1,
	txt_mt2,
	txt_mt3,
	txt_mt4,
	txt_mt5,
	txt_mt6,
	txt_mt7,
	txt_mt8,
	txt_mt9,
	txt_mt10,
};


char txt_sk1[]="FIND ME ON THE ROOFTOP";
char txt_sk2[]="PUNCHES ?";
char txt_sk3[]="BEFORE FIGHT BUTTONS PUSHED";
char txt_sk4[]="ARE YOU WORTHY?";
char txt_sk5[]="MY KAVE IS A GOOD SPOT";
char txt_sk7[]="FROSTY";
char txt_sk8[]="DONT FORGET TO DUCK DOWN";
char txt_sk9[]="TRY THE PIT III";
char txt_sk10[]="I CANNOT BE DEFEATED";
char *sk_clues[]= 
{
	txt_sk1,
	txt_sk2,
	txt_sk3,
	txt_sk4,
	txt_sk5,
	txt_mt1,
	txt_sk7,
	txt_sk8,
	txt_sk9,
	txt_sk10,
};


#define MAX_CLUES	4
CLUES clue_table[]=
{
	{FT_KAMEL,kamel_clues},
	{FT_OLDSMOKE,smoke_clues},
	{FT_MOTARO,motaro_clues},
	{FT_SK,sk_clues},
};

void clue_giveaway(void) 
{
	CLUES *ctbl;
	OBJECT *obj;
	short pa0;
	
	nosounds();
	process_sleep(0x18);
	
	pa0=randu(MAX_CLUES)-1;
	ctbl=&clue_table[pa0];

	/* create character */
	f_wait_for_wings+=WINGS_P2_DEC;
	current_proc->pdata.p_flags&=~PM_KAMEL;
	obj=make_intro_ochar_obj(ctbl->c_char,SCRRGT/2,6);
	tsound(0x0);
	tsound(0x1);
	CREATE(PID_FX,baby_flash);
	create_fx(FX_INVISO_POOF);
	
	/* execute victory */
	if (ctbl->c_char==FT_KAMEL) 
	{
		CREATE(PID_KAMELEON,kamel_switch)->a11=1;
	}
			
	get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
	mframew(4);
		
	/* print clue */
	pds_centered(*(ctbl->c_clues+randu(10)-1),160,160);		
	
	/* wait */
	process_sleep(0x70);

	dallobj(OID_TEXT);	
	current_proc->pa8=obj;
	process_sleep(0x20);
	
	/* dissappear */
	tsound(0x0);
	tsound(0x1);
	CREATE(PID_FX,baby_flash);
	create_fx(FX_INVISO_POOF);
	process_sleep(10);
	
	delobjp(obj);
	if (ctbl->c_char==FT_KAMEL)
		dallprc(PID_KAMELEON);
		
	f_wait_for_wings-=WINGS_P2_DEC;
	if ((f_wait_for_wings & WINGS_P2_MASK)==0) 
	{
		/* load main character again */
		character_texture_load(p2_char,CHAR_NORMAL,p2_heap,SYNC_LOAD);
	}
	
	process_sleep(0x30);
	
	play_background_tune();
	return;	
}

char txt_p1_intro[]="PLAYER ONE\nGET READY !!";

char txt_p2_intro[]="PLAYER TWO\nGET READY !!";
char txt_secret_return[]="NOW, YOU MUST RETURN\nTO KOMBAT";
extern OIMGTBL MUG_QUESTION;
extern void *dlists_only_q[];

void q_white(void) 
{
	WORD ta9=irqskye;
	void *ta11;
	
	irqskye=0xffff;
	
	ta11=dlists;
	dlists=dlists_only_q;
	process_sleep(6);
	dlists=ta11;
	irqskye=ta9;
	process_sleep(6);
	return;
}

void toasty_check(WORD pa0) 
{
	WORD pchar,pstate;
	long ta10,ta11;
	LONG scale;
	OBJECT *obj;
	
	if (pa0==0)
	{
		if (p1_state!=PS_ACTIVE)
			return;
	}
	else
	{
		if (p2_state!=PS_ACTIVE)
			return;
	}
	
	if (gstate!=GS_FIGHTING)	
		return;
	
	if (curback!=BKGD_MK2PITSTAR_MOD)	
		return;
	
	if (abs(toasty_tick-tick)>0x40)	
		return;
	
	if (pa0==0)
	{
		if ((swcurr.u.p1pad & MASK_JDOWN)==0)		
			return;
	} 
	else
	{
		if ((swcurr.u.p2pad & MASK_JDOWN)==0)		
			return;
	}
	
	current_proc->procid=PID_MASTER;
	gstate=GS_SEC_INTRO;
	
	/* say who got in */
	if (pa0==0) 
	{
		p15_centered(txt_p1_intro,SCX(100)+24,(0x40));
	}
	else
	{
		p15_centered(txt_p2_intro,SCX(300)-24,(0x40));
	}
	
	scrolly.pos=0;
	stop_scrolling();
	
	f_novel=1;
	MURDER;
	nosounds();
	process_sleep(1);
	
	tsound(0x0);
	white_flash();
	process_sleep(8);
	
	tsound(0x1);
	white_flash();
	process_sleep(8);
	
	tsound(0x0);
	white_flash();
	process_sleep(0x70);
	
	
	murder_myoinit_score();
	tsound(0x8c);
	white_flash();
	
	do_background(BKGD_MONK_MOD);
	nosounds();
	process_sleep(2);
	
	shake_a11(0x3,0x30);
	tsound(0x87);
	process_sleep(0xa0);
	dallprc(PID_SHAKER);
	
	tsound(1);
	white_flash();
	
	/* load mugshot data */
	special_fx_load(FX_MUGS_LOAD);
	spec_fx=FX_NO_LOAD;
	
	ta11=MUG_QUESTION.size.u.xpos;
	ta10=MUG_QUESTION.size.u.ypos;
	current_proc->a10=ta10<<8;
	current_proc->a11=ta11<<8;
	
	gso_dmawnz_ns(obj,(ADDRESS)&MUG_QUESTION,0,0,0);
	alloc_cache((OIMGTBL *)&MUG_QUESTION,0,obj);
	set_xy_coordinates(obj,160-ta11/2,0x70);
	insert_object(obj,&objlst);
	
	scale=0x03000300;
	obj->oscale.yx=scale;
	center_scale(obj,scale);
	/* grow3 */
	do
	{
		obj->oscale.yx=scale;
		center_scale(obj,scale);
		process_sleep(1);
		scale-=0x00100010;
	}
	while(scale!=0x00600060);
	
	sound_music_start(MUSIC_GREEN);
	
	q_white();
	q_white();
	q_white();
	
	
	/* grow4 */
	do
	{
		obj->oscale.yx=scale;
		center_scale(obj,scale);
		process_sleep(1);
		scale+=0x00100010;
	}
	while(scale!=0x03000300);
	delobjp(obj);
	
	/* congrats msg */
	current_proc->a0=2;
	current_proc->a1=0x1a;
	msg_rise();
	process_sleep(0x70);
	
	current_proc->a0=3;
	current_proc->a1=0x15;
	msg_rise();
	process_sleep(0x110);
	
	delolist(&objlst);
	process_sleep(0x20);
	
	current_proc->a0=4;
	current_proc->a1=0x1c;
	msg_rise();
	process_sleep(0xa0);
	
	current_proc->a0=5;
	current_proc->a1=0x10;
	msg_rise();
	process_sleep(0x60);
	
	current_proc->a0=6;
	current_proc->a1=0xb;
	msg_rise();
	process_sleep(0x60);
	
	nosounds();
	process_sleep(2);
	tsound(0x8c);
	fade_all_sky();
	process_sleep(0x60);
	murder_myoinit_score();
	clr_scrn();
	
	/* temp eliminate the other player */
	if (pa0==1)
	{
		pchar=p1_char;
		pstate=p1_state;
		p1_state=0;
		p1_char=FT_KAMEL;
	}
	else
	{
		pchar=p2_char;
		pstate=p2_state;
		p2_state=0;
		p2_char=FT_KAMEL;
	}
	
	p1_matchw=p2_matchw=0;
	round_num=0;
	c_three=0;
	
	/* toast6 */
	do
	{
		murder_myoinit_score();
		
		round_results=play_1_round();
		results_of_round(round_results);
		inc_winners_wiar();
		update_win_counters();
		
		f_thatsall=1;								/* flag: enough fighting already */
		bonus_count();
	}
	while(p1_matchw!=2 && p2_matchw!=2);
	
	if (pa0==0) 
	{
		p1_char=pchar;
		p1_state=pstate;
	}
	else
	{
		p2_char=pchar;
		p2_state=pstate;
	}
	
	
	delolist(&objlst2);
	p15_centered(txt_secret_return,160,(0x40));
	tsound(0xb0);
		
	process_sleep(0x80);
	MURDER;
	fade_all_sky();
	process_sleep(0x40);
	curback=randu(MAX_BACKGROUNDS)-1;
	round_num=0;
	stack_jump(post_mode_select);
}

