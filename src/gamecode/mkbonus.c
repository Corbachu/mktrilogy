/******************************************************************************
 File: mkbonus.c

 Date: Dec 1994

 (C) Williams Entertainment

 Mortal Kombat III bonus Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"
	   
#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkmain.h"
#include "mkblood.h"
#include "mkbonus.h"
#include "mkfx.h"
#include "mkdma.h"
#include "mktext.h"
#include "mksound.h"
#include "mkfade.h"

/* local extern info */
extern char txt_tie[];
extern char txt_single_flawless[];
/******************************************************************************
 Function: void bonus_count(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	After fight bonus screen display
******************************************************************************/
char txt_tie[]="DRAW";
char txt_single_flawless[]="FLAWLESS VICTORY";

BYTE fatality_animations[]=
{
	FX_FATAL_DRIP,
	FX_FATAL_DRIP,
	FX_ANIMALITY,
	FX_FRIENDSHIP,
	FX_BABALITY,
	FX_BRUTALITY,			
	FX_FATAL_DRIP
};

void bonus_count(void)
{
	WORD *pa4;
	WORD *pa5;
	WORD *pbar;
	ADDRESS ta11;
	PROCESS *ptemp;

	gstate=GS_BONUS;					// game state = bonus

	kill_lingerings();					// kill fx/dangers/etc...
	reset_aggressor();

//********************************************
	ptemp=process_exist(PID_MERCY,0xffff);
	if ( ptemp!=NULL  )
	{
		if ( ptemp->p_comp_flag==999 )
		{
			process_kill(ptemp);
		}
	}
//********************************************

	/* Print the Winner */
	if ( p1_bar!=p2_bar )
	{
		p15_centered(get_winner_text(),SCX(0xc8),SCY(0x38)+8);
		change_oid_list(&objlst2,OID_TEXT,OID_FX);		// change oid of PLAYER WINS TEXT
	}

	/* speech: winner annonced */
	play_ending_chord();
	process_sleep(0x40);
	
	current_proc->a0=(f_final_act==0)? 0:f_final_act-1;
	current_proc->pa8=(winner_status==1)?p1_obj:p2_obj;
		
	if (p1_bar!=p2_bar)
	{
		/* winner announcement */
 		if (get_winner_ochar()==FT_SK)
		{
			current_proc->pa8=(p1_char==FT_SK)?p1_obj:p2_obj;		// make sure point to an object for panning driver call
			rsnd_sk_bonus_win();
		}
		else
		{
#if 0		
			if (mode_of_play==1 || mode_of_play==4) 
			{
				if (winner_status==1)
					tsound(0x9a);
				else tsound(0x9b);
			}
			else 
#endif			
			tsound2(0x20+get_winner_ochar());
		}

		/* flawless check */
		if (p1_bar==FULL_STRENGTH || p2_bar==FULL_STRENGTH)
			tsound(0x72);

		/* bonus3 */
		wait_for_bonusv(300);

		if ((winner_status==1 && p1_state==PS_ACTIVE) ||
		   (winner_status==2 && p2_state==PS_ACTIVE))
		{
			/* flawless victory ? */
			if (winner_status==1)
			{
				pbar=&p1_bar;
				pa4=&p1_perfect;			// winner perfect
				pa5=&p2_perfect;			// loser perfect
			}
			else
			{
				pbar=&p2_bar;
				pa4=&p2_perfect;			// winner perfect
				pa5=&p1_perfect;			// loser perfect
			}

			/* bonus5 */
			*pa5=~0;						// loser = no chance for double perfect

			if (*pbar==FULL_STRENGTH)		// check for perfection
			{
				/* win5 */
				*pa4=1;			// flag: perfect round
				(char *)current_proc->pa8=txt_single_flawless;

				/* win51 */
				pds_centered((char *)current_proc->pa8,SCX(0xc8),SCY(0x60)+16);

				/* flawless announcement */
				tsound(0x61);
				wait_for_bonusv(340);
			}
		}
		else
		{
			/* stay awhile for a computer victory, NEED for streams */
			process_sleep(0x28);
		}

		/* win6 , fatality ? */
		if (f_death!=0)
		{
			dallobj(OID_TEXT);

			current_proc->a0=(f_final_act==0)? 0:f_final_act-1;
			current_proc->pa8=(winner_status==1)?p1_obj:p2_obj;

			/* display graphic data */
			current_proc->a11=ta11;
			create_fx(fatality_animations[current_proc->a0]);		// fatality drip fx
			process_sleep(2);
			wait_for_bonusv(300);
		}
	}
	else
	{
		/* bonus_count_draw */
		p15_centered(txt_tie,SCX(0xc8),SCY(0x38)+16);
		process_sleep(0x70);
	}

	/* bonus exit */
	if (p1_matchw!=2 && p2_matchw!=2)
	{
		dallprc(PID_CYCLE);			// kill any color cycle
		fast_fadeout_jsrp(0x20);
		freeze_2_pages();
		MURDER;

		/* amode display reset */
		f_doscore=0;
		clr_scrn();
		f_auto_erase=1;
		murder_myoinit();
		clr_scrn();
		/* amode display reset */
	}
	else
	{
		/* bonus7 */

		/* we have a winner on the level so revert back to orignal character selections if needed */
		if (p1_boss_char!=0xffff)		// if transformed to boss then revert back to orig
		{
			p1_char=p1_boss_char;
			
		}
		if (p2_boss_char!=0xffff)		// if transformed to boss then revert back to orig
		{
			p2_char=p2_boss_char;
			
		}
		p1_boss_char=p2_boss_char=0xffff;

		process_sleep(0x25);
	}

	send_code_a3(0);

	return;
}

/******************************************************************************
 Function: void kill_lingerings(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	kill lingering objects and processes that aren't needed
******************************************************************************/
void kill_lingerings(void)
{
	dallobj(PID_DANGER1);
	dallprc(PID_DANGER1);

	dallobj(PID_DANGER2);
	dallprc(PID_DANGER2);

	dallprc(PID_FX);
	dallobj(OID_FX);
	dallobj(OID_TEXT);

	return;
}

/******************************************************************************
 Function: char *get_winner_text(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	returns ptr to winners text
******************************************************************************/
char txt_kano_wins[]="KANO WINS";
char txt_sonya_wins[]="SONYA WINS";
char txt_jax_wins[]="JAX WINS";
char txt_sal_wins[]="NIGHTWOLF WINS";
char txt_sz_wins[]="SUB-ZERO WINS";
char txt_jc_wins[]="JOHNNY CAGE WINS";
char txt_swat_wins[]="STRYKER WINS";
char txt_lia_wins[]="SINDEL WINS";
char txt_robo1_wins[]="SEKTOR WINS";
char txt_robo2_wins[]="CYRAX WINS";
char txt_lao_wins[]="KUNG LAO WINS";
char txt_tusk_name_wins[]="KABAL WINS";
char txt_sg_name_wins[]="SHEEVA WINS";
char txt_st_name_wins[]="SHANG TSUNG WINS";
char txt_lk_name_wins[]="LIU KANG WINS";
char txt_smoke_wins[]="SMOKE WINS";
char txt_kitana_wins[]="KITANA WINS";
char txt_jade_wins[]="JADE WINS";
char txt_mileena_wins[]="MILEENA WINS";
char txt_scorpion_wins[]="SCORPION WINS";
char txt_rain_wins[]="RAIN WINS";
char txt_reptile_wins[]="REPTILE WINS";
char txt_ermac_wins[]="ERMAC WINS";
char txt_motaro_wins[]="MOTARO WINS";
char txt_shao_kahn_wins[]="SHAO KAHN WINS";
char txt_noob_wins[]="NOOB SAIBOT WINS";
char txt_rayden_wins[]="RAYDEN WINS";
char txt_baraka_wins[]="BARAKA WINS";
char txt_kamel_wins[]="KHAMELEON WINS";
char txt_boon_w[]="BOON WINS";
char txt_jc_t[]="KINTARO TRANSFORMATION ACTIVATED";
char txt_bj_t[]="GORO TRANSFORMATION ACTIVATED";
char txt_hyperf[]="HYPER FATAILITY";

char *ochar_winner_text[]=
{
	txt_kano_wins,
	txt_sonya_wins,
	txt_jax_wins,
	txt_sal_wins,
	txt_jc_wins,
	txt_swat_wins,
	txt_lia_wins,
	txt_robo1_wins,
	txt_robo2_wins,
	txt_lao_wins,
	txt_tusk_name_wins,
	txt_sg_name_wins,
	txt_st_name_wins,
	txt_lk_name_wins,
	txt_smoke_wins,
	txt_kitana_wins,
	txt_jade_wins,
	txt_mileena_wins,
	txt_scorpion_wins,
	txt_reptile_wins,
	txt_ermac_wins,
	txt_sz_wins,
	txt_smoke_wins,
	txt_noob_wins,
	txt_rayden_wins,
	txt_baraka_wins,			//-u64-
	txt_rain_wins,
	txt_kamel_wins,
	NULL,	
	NULL,
	txt_motaro_wins,
	txt_shao_kahn_wins,
};

char txt_team1_wins[]="TEAM 1 WINS";
char txt_team2_wins[]="TEAM 2 WINS";

char *get_winner_text(void)
{
	if (mode_of_play==1 || mode_of_play==4 )
		return((winner_status==1)?txt_team1_wins:txt_team2_wins);

	return(ochar_winner_text[get_winner_ochar()]);
}

WORD get_winner_ochar(void)
{
	PROCESS *pa1;
	OBJECT *pa0;

	switch (mode_of_play)
	{
		case 0:			// gwo_1_on_1
		case 2:			// gwo_tournament
			if (p1_obj==NULL)
				return((winner_status==1)?p1_char:p2_char);
			break;	
		case 1:			// gwo_2_on_2
		case 4:			// gwo_3_on_3
			if (p1_obj==NULL)
				return((winner_status==1)?p1_char:p3_char);		// default
			break;
	}

	if (winner_status==1)
	{
		pa0=p1_obj;
		pa1=p1_proc;
	}
	else
	{
		pa0=p2_obj;
		pa1=p2_proc;
	}

	if (pa1->pdata.p_flags & PM_SHANG)
		return(FT_ST);

	if (pa1->pdata.p_flags & PM_KAMEL)
		return(FT_KAMEL);
	else return(pa0->ochar);
}

/******************************************************************************
 Function: void wait_for_bonusv(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	wait for shao kahn voice to finish
******************************************************************************/
void wait_for_bonusv(WORD sector)
{
	current_proc->a10=0x49*2;
	/* wfb3 */
	do
	{
		process_sleep(1);
	}
	while(--current_proc->a10>0);

	return;
}
