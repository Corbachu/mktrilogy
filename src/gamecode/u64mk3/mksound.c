/******************************************************************************
 File: mksound.c

 Date: Dec 1994

 (C) Williams Entertainment

 Mortal Kombat III vs Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkbonus.h"
#include "mksound.h"
#include "wessapi.h"
#include "seqload.h"

#define TS_FEET_LAND	RSND_FS3
#define TS_SK_SHOW_MERCY 0
#define TS_SK_WINS       0
#define TS_SK_VS         0


//MISSING STUFF
#define TS_ITS_OFFICAL	0		//-remove at some point
#define TUNE_SELECT		0		//-remove at some piunt
#define TUNE_GAMEOVER	0		//-remove at some piunt
#define TS_ONEPLAY_END	0		//-remove at some point

#define TS_PLAY_BUY		TS_CURSOR_MOVE
#define TS_MONKEY		RSND_STAB2

/* remapped stuff */
#define TS_SK_FIGHT		RNDFIGHT
#define TS_SK_ROUND1	RND1
#define TS_SK_ROUND2	RND2
#define TS_SK_ROUND3	RND3
#define TS_SK_ROUND4	RND4

/***************************************************************************
***************************************************************************/
short gs_death[]=
{
	1,
   	GS_DEATH_GIRL,		// girl = eb
   	GS_DEATH_VP,			// vp = hey
   	GS_DEATH_DF,			// df = df
   	GS_DEATH_EB,	 		// eb
   	GS_DEATH_JH,	 		// 4 = eb
   	GS_DEATH_ROBO,	 		// 5 = hey
   	GS_DEATH_KANG,			// kang
	GS_DEATH_SG,			// sheeva
	GS_DEATH_SK			// shao kahn
};

short gs_shook[]=
{
	1,
	GS_SHOOK_GIRL,	   	// Girl #1: Wast #2
	GS_SHOOK_VP,		// VP: shook
	GS_SHOOK_DF,		// DF: shook
	GS_SHOOK_EB,		// EB: shook
	GS_SHOOK_JH,		// EB: shook
	GS_SHOOK_ROBO,	 	// robo: shook
	GS_SHOOK_KANG,	 	// kang: run (borrow)
	GS_SHOOK_SG,			// sheeva
	GS_SHOOK_SK			// shao kahn
};

short gs_run[]=
{
	1,
  	GS_RUN_GIRL,	  	// Girl #1: run
  	GS_RUN_VP,			// VP: run
  	GS_RUN_DF,			// DF: run
  	GS_RUN_EB,		// EB: run
  	GS_RUN_JH,		// JH: run
  	GS_RUN_ROBO,	 	// robo: run
  	GS_RUN_KANG,		// kang: run
	GS_RUN_SG,			// sheeva
	GS_RUN_SG			// shao kahn
};

short gs_tripped_voice[]=
{
	1,
	GS_TV_GIRL,	   	// Girl #1: tripped voice
	GS_TV_VP,			// VP: attack #1
	GS_TV_DF,			// DF: tripped
	GS_TV_EB,		// EB: tripped
	GS_TV_JH,		// JH: tripped
	-1,		 	// robo
	GS_TV_KANG,			// JH: tripped
	GS_TV_SG,			// sheeva
	GS_TV_SK			// shao kahn
};

short gs_face_hit_voice[]=
{
	3,
	GS_FHV_GIRL1,	  	// Girl: hit in face voice
	GS_FHV_GIRL2,	  	// Girl: hit in face voice
	GS_FHV_GIRL3,	  	// Girl: hit in face voice

	GS_FHV_VP1,		// VP: hit in face voice
	GS_FHV_VP2,		// VP: hit in face voice
	GS_FHV_VP3,		// VP: hit in face voice

	GS_FHV_DF1,	 	// DF: hit in face voice
	GS_FHV_DF2,	 	// DF: hit in face voice
	GS_FHV_DF3,	 	// DF: hit in face voice

	GS_FHV_EB1,	  	// EB: hit in face voice
	GS_FHV_EB2,	 	// EB: hit in face voice
	GS_FHV_EB3,	  	// EB: hit in face voice

	GS_FHV_JH1,	  	// JH: hit in face voice
	GS_FHV_JH2,	  	// JH: hit in face voice
	GS_FHV_JH3,	  	// JH: hit in face voice

	GS_FHV_ROBO1,	 	// robo: hit in face
	GS_FHV_ROBO2,	 	// robo: hit in face
	GS_FHV_ROBO3,		// robo: hit in face

	GS_FHV_KANG1,	  	// kang: hit in face voice
	GS_FHV_KANG2,	  	// kang: hit in face voice
	GS_FHV_KANG3,		// kang: hit in face voice

	GS_FHV_SG1,			// sheeva
	GS_FHV_SG2,			// sheeva
	GS_FHV_SG3,			// sheeva

	GS_FHV_SK1,			// shao kahn
	GS_FHV_SK2,			// shao kahn
	GS_FHV_SK3			// shao kahn

};

short gs_attack[]=
{
	2,						// 2 entries per group
	GS_ATK_GIRL1,	 	// Girl #1: attack #1
	GS_ATK_GIRL2,	 	// Girl #1: attack #2
	GS_ATK_VP1,	// VP: attack #1
	GS_ATK_VP2,	// VP: attack #2
	GS_ATK_DF1,		// DF: attack #1
	GS_ATK_DF2,		// DF: attack #2
	GS_ATK_EB1,	 	// EB: attack #1
	GS_ATK_EB2,	 	// EB: attack #2
	GS_ATK_JH1,	 	// JH: attack #1
	GS_ATK_JH2,	 	// JH: attack #2
	-1,		 				// robo attack #1
	-1,		 				// robo attack #2
	GS_ATK_KANG1,	 	// kang: attack #1
	GS_ATK_KANG2,		// kang: attack #2
	GS_ATK_SG1,			// sheeva
	GS_ATK_SG2,			// sheeva
	GS_ATK_SK1,			// shao kahn
	GS_ATK_SK2			// shao kahn
};

short gs_jump[]=
{
	1,
   	GS_JUMP_GIRL,	  	// Girl #1: jump
   	GS_JUMP_VP,		// VP: jump
   	GS_JUMP_DF,		// DF: jump
   	GS_JUMP_EB,		// EB: jump
   	GS_JUMP_JH,		// JH: jump
	-1,		 				// robo = sans
   	GS_JUMP_KANG,		// kang: jump
	GS_JUMP_SG,			// sheeva
	GS_JUMP_SK			// shao kahn
};

short gs_grab[]=
{
	1,
   	GS_GRAB_GIRL,	// girl grab
   	GS_GRAB_VP,		// VP: grab ??
   	GS_GRAB_DF,		// DF: grab ??
   	GS_GRAB_EB,		// EB: grab ??
   	GS_GRAB_JH,		// JH: grab ??
   	GS_GRAB_ROBO,				 	// robo: grab
   	GS_GRAB_KANG,		// kang: grab
	GS_GRAB_SG,			// sheeva
	GS_GRAB_SK			// shao kahn
};

short gs_slam[]=
{
	1,
	GS_SLAM_GIRL,	// girl throw voice
	GS_SLAM_VP,		// VP: throw voice
	GS_SLAM_DF,		// DF: throw voice
	GS_SLAM_EB,		// EB: throw voice
	GS_SLAM_JH,		// JH: throw voice
	GS_SLAM_ROBO,	 	// robo: throw voice
	GS_SLAM_KANG,		// kang: throw voice
	GS_SLAM_SG,			// sheeva
	GS_SLAM_SK			// shao kahn
};

short gs_wasted[]=
{
	2,
	GS_WST_GIRL1,	  	// Girl #1: Wast #1
	GS_WST_GIRL2,	  	// Girl #1: Wast #2
	GS_WST_VP1,			// VP: Wast #1
	GS_WST_VP2,			// VP: Wast #2
	GS_WST_DF1,			// DF: Wast
	GS_WST_DF2,			// DF: Wast
	GS_WST_EB1,		  	// EB: Wast #1
	GS_WST_EB2,		  	// EB: Wast #2
	GS_WST_JH1,		  	// JH: Wast #1
	GS_WST_JH2,		  	// JH: Wast #2
	GS_WST_ROBO1,	 	// robo: wasted
	GS_WST_ROBO2,	 	// robo: wasted
	GS_WST_KANG1, 	// kang: Wast #1
	GS_WST_KANG2, 	// kang: Wast #2
	GS_WST_SG1,			// sheeva
	GS_WST_SG2,			// sheeva
	GS_WST_SK1,			// shao kahn
	GS_WST_SK2			// shao kahn
};

short *group_table[]=
{
	gs_attack,			// 0 = quick attacks
	gs_jump, 			// 1 = jump
	gs_wasted,			// 2 = wasted
	gs_grab,  			// 3 = grab
	gs_slam,  			// 4 = throw voice
	gs_tripped_voice,	// 5 =
	gs_face_hit_voice,	// 6 =
	gs_run,				// 7 =
	gs_shook,			// 8 =
	gs_death			// 9
};

short ochar_voice_groups[]=
{
 	GP_MALE3,	//
	GP_FEMALE,	//
	GP_MALE3,	//
	GP_MALE2,	//
	GP_MALE4,	//
	GP_MALE1,	//
	GP_FEMALE,	//
	GP_ROBO,		//
	GP_ROBO,		//
	GP_MALE4,	//
	GP_MALE1,	//
	GP_SHEEVA,	//
	GP_MALE3,	//
	GP_KANG,		//
	GP_ROBO,	//
 
   	GP_FEMALE,	
   	GP_FEMALE,	
   	GP_FEMALE,	
   	GP_MALE1,	
   	GP_MALE2,	
   	GP_MALE3,	
   	GP_MALE4,	
   	GP_MALE1,	
   	GP_MALE2,
   	
	GP_MALE4,		//-u64
   	GP_MALE3,
   	GP_MALE2,
   	GP_FEMALE,	
	
   	GP_MALE2,
   	GP_MALE2,
	-1,
	GP_SHAO_KAHN
};


static volatile int music_seq_playing;		// -1 = none
static volatile int music_seq_waiting;		// -1 = none
//========================================================================================
// Public functions:

//////////////////////////////////////////////////////////////////////////////////////////
// sound_reset - resets the sound system. All sound is stopped.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_reset( void ) {
	CRITICAL_DEFS;

	ENTER_CRITICAL;
		music_seq_playing = -1;
		music_seq_waiting = -1;
	LEAVE_CRITICAL;
}

/******************************************************************************
 Function: void group_sound(WORD offset)

 By: David Schwartz

 Date: Apr 1995

 Parameters: offset - group offset

 Returns: None

 Description:
******************************************************************************/
void group_sound(WORD offset)
{
	short *stbl;
	OBJECT *obj=current_proc->pa8;
	short ta1;


	stbl=get_group_table(offset);
	current_proc->a2=GET_WORD(stbl)++;				// # of entries
	current_proc->a3=current_proc->a2;

	ta1=ochar_voice_groups[obj->ochar];		// a1 = my group (offset into groups data)

	if (ta1<0)
		return;									// neg = no group for me
	else
	{
		stbl+=(current_proc->a2*ta1);	// # of words to skip to get to our group data
	}

	/* gsnd5 */
	next_table_sound(current_proc->a3,stbl);

	return;
}

/******************************************************************************
 Function: void kill_group_sound(WORD offset,OBJECT *obj)

 By: David Schwartz

 Date: Apr 1995

 Parameters: offset - group offset
						 obj - group to kill from

 Returns: None

 Description:
******************************************************************************/
void kill_group_sound(WORD offset,OBJECT *obj)
{
	short *stbl;
	short ta1;

	stbl=get_group_table(offset);
	current_proc->a2=GET_WORD(stbl)++;				// # of entries
	current_proc->a3=current_proc->a2;

	ta1=ochar_voice_groups[obj->ochar];		// a1 = my group (offset into groups data)

	if (ta1<0)
		return;									// neg = no group for me
	else
	{
		stbl+=(current_proc->a2*ta1);	// # of words to skip to get to our group data
	}

	/* gsnd5 */
	do
	{
		wess_seq_stop(*stbl);						// kill all sounds for that group
		stbl++;
	} while ( --current_proc->a3>0 );

	return;
}

/******************************************************************************
 Function: void his_group_sound(WORD offset)

 By: David Schwartz

 Date: Apr 1995

 Parameters: offset - group offset

 Returns: None

 Description:
******************************************************************************/
void his_group_sound(WORD offset)
{
	OBJECT *ta8;

	ta8=current_proc->pa8;
	current_proc->pa8=current_proc->pdata.p_otherguy;
	group_sound(offset);
	current_proc->pa8=ta8;

	return;
}


/******************************************************************************
RANDOM SELECT SOUND EFFECTS
******************************************************************************/
short rsnd_fs[]=
{
	RSND_FS1,	// 5 - foot step #1
	RSND_FS2,	// 6 - foot step #2
	RSND_FS3,	// 7 - foot step #3
	RSND_FS4	// 8 - foot step #4
};
void rsnd_footstep(void)
{
	next_table_sound(4,rsnd_fs);
}

short rsnd_skb[]=
{
	ST_SK_PATHETIC, 	// 1 - Shao Kahn: That was Pathetic
	ST_SK_NEVER_WIN,	// 2 - Shao Kahn: You will never win
	ST_SK_STILL_TRYING,	// 3 - Shao Kahn: You're still trying to win?
	ST_SK_DONT_LAUGH,		// 4 - Shao Kahn: Don't make me laugh
	ST_SK_DONT_LAUGH	// 5 - Shao Kahn: I win
};
void rsnd_sk_bonus_win(void)
{
	next_table_sound(5,rsnd_skb);
	return;
}


short rsnd_bb[]=
{
	RSND_BB1,			// block a Major hit
	RSND_BB2			// block a Major hit
};
void rsnd_big_block(void)
{
	next_table_sound(2,rsnd_bb);
}

short rsnd_sb[]=
{
	RSND_SB1,	// block
	RSND_SB2	// block
};
void rsnd_small_block(void)
{
	next_table_sound(2,rsnd_sb);
}

short rsnd_lsmack[]=
{
	RSND_SM1,		// 13 - face hit #1
	RSND_SM2		// 14 - face hit #2
};
void rsnd_smack(void)
{
	next_table_sound(2,rsnd_lsmack);
}

short rsnd_msmack[]=
{
	RSND_MSM1,
	RSND_MSM2,
	RSND_MSM3
};
void rsnd_med_smack(void)
{
	next_table_sound(3,rsnd_msmack);
}

short rsnd_bsmack[]=
{
	RSND_BSM1,		// 2 - Old big hit #1
	RSND_BSM2		// 3 - Old big hit #2
};
void rsnd_big_smack(void)
{
	next_table_sound(2,rsnd_bsmack);
}

short rsnd_rcks[]=
{
	RSND_ROCK1,		//      Rock #1
	RSND_ROCK2,		//      Rock #2
	RSND_ROCK3,		//      Rocks #1
	RSND_ROCK4,		//      Rocks #2
	RSND_ROCK5		//      Rocks #3
};
void rsnd_rocks(void)
{
	next_table_sound(5,rsnd_rcks);
}

void sweep_sounds(void)
{
	rsnd_big_whoosh();
	group_sound(0);
}

short rsnd_bhit[]=
{
   	RSND_BHT1, 		// 10 - body hit #1
   	RSND_BHT2		// 11 - body hit #2
};
void rsnd_body_hit(void)
{
	next_table_sound(2,rsnd_bhit);
}

short rsnd_gnd[]=
{
   	RSND_GND1,  	//2c - fall #1
   	RSND_GND2,  	//2d - fall #2
   	RSND_GND3,  	//2e - fall #3
   	RSND_GND4  	//2f - fall #4
};
void rsnd_ground(void)
{
	next_table_sound(4,rsnd_gnd);
}

short rsnd_whsh[]=
{
	RSND_WHSH1, 	//24 - whoosh #1
	RSND_WHSH2, 	//25 - whoosh #2
	RSND_WHSH3,	//26 - whoosh #3
	RSND_WHSH4 	//21 - big whoosh #2
};
void rsnd_whoosh(void)
{
	next_table_sound(4,rsnd_whsh);
}

short rsnd_bwhsh[]=
{
	RSND_BWHSH1, 	// 20 - big whoosh #1
	RSND_BWHSH2 	// 22 - big whoosh #3
};
void rsnd_big_whoosh(void)
{
	next_table_sound(2,rsnd_bwhsh);
}

short rsnd_eboom[]=
{
	RSND_EBOOM1,
	RSND_EBOOM2,
	RSND_EBOOM3
};
void rsnd_enemy_boom(void)
{
	next_table_sound(3,rsnd_eboom);
}

short rsnd_splsh[]=
{
	RSND_SPLISH1,
	RSND_SPLISH2,
	RSND_SPLISH3
};
void rsnd_splish(void)
{
	next_table_sound(3,rsnd_splsh);
}

short rsnd_stb[]=
{
	RSND_STAB1,
	RSND_STAB2,
	RSND_STAB3,
	RSND_STAB4
};
void rsnd_stab(void)
{
	next_table_sound(4,rsnd_stb);
}

short rsnd_klng[]=
{
	RSND_KLANG1,
	RSND_KLANG2
};
void rsnd_klang(void)
{
	next_table_sound(2,rsnd_klng);
}

void rsnd_react_voice(void)
{
	group_sound(6);
	return;
}

/******************************************************************************
******************************************************************************/
short triple_sndtab[]=	
{
	TS_EXP_ST1,			// 0 - Explode thru street
	TS_EXP_ST2,			// 1 - Explode thru street
	TS_RNDHOUSE,			// 2 - roundhouse whoosh
	TS_BIGDOOR_CLOSE,		// 3 - big door closing
	TS_BIGDOOR_SLAM,		// 4 - big door slam shut
	TS_WIND,				// 5 - wind
	0x8000|TS_WHOOSH1,			// 6 - whoosh #1
	0x8000|TS_WHOOSH3,			// 7 - whoosh #3
	TS_SUB_APPROACH, 		// 8 - subway approaching
	TS_SUB_STEADY,	  		// 9 - subway steady state
	TS_SUB_GOING,	  		// a - subway going away
	TS_CROWD_OOO,	  		// b - crowd: "Ooooo"
	TS_P1_CURS,		  	// c - p1 cursor
	TS_P2_CURS,		  	// d - p2 cursor
	TS_P1_PICKED,	  		// e - p1 picked
	TS_P2_PICKED,	  		// f - p2 picked
	TS_SK_FIGHT,			// 10 - Shao Kahn: Fight! #3
	TS_SK_ROUND1,			// 11 - Shao Kahn: Round One
	TS_SK_ROUND2,			// 12 - Shao Kahn: Round Two
	TS_SK_ROUND3,			// 13 - Shao Kahn: Round Three
	TS_SK_ROUND4,			// 14 - Shao Kahn: Round Four
	TS_SK_FIN_HIM,			// 15 - Shao Kahn: Finish Him!
	TS_SK_FIN_HER,			// 16 - Shao Kahn: Finish Her!
	TS_CLOCK_TICK,	 		// 17 - clock time down tik !!
	0x8000|TS_FEET_LAND,	// 18 - players feet landing on ground
	TS_MAP_ZOOM,			// 19 - 1 player map zoom sound
	TS_COIN_SND,			// 1a - coin sound, 

	TS_DF_TOASTY,			// 1b - DF: toasty
	TS_DF_FROSTY,			// 1c - DF: frosty
	TS_DF_CRISPY,			// 1d - DF: crispy
	0x8000|TS_SHOCK, 		// 1e - shock sound !!

	0x8000|TS_FLAME,		// 1f - flame throw
	0x8000|TS_BURNING, 		// 20 - burning flames!!
	0x8000|TS_BONES,	 	// 21 - bones fall
	TS_PIT_MACH1,			// 22 - pit machine sound
	TS_PIT_MACH2,			// 23 - pit machine sound
	0x8000|TS_CRUNCH1,		// 24 - crunch #1
	0x8000|TS_CRUNCH2,		// 25 - crunch #2
	TS_ANIM_SIZZLE1,		// 26 - animality sizzle
	TS_ANIM_MORPH,			// 27 - animality morph

	TS_DRAGON_SPIN,			// 28 - option whosh icon move
	TS_GONG,			// 29 - Shao Kahn: Sonya
	0,			// 2a - Shao Kahn: Jax
	0,			// 2b - Shao Kahn: Night Wolf
	0,			// 2c - Shao Kahn: Sub-Zero
	0,			// 2d - Shao Kahn: Stryker
	0,			// 2e - Shao Kahn: Sindel
	0,			// 2f - Shao Kahn: Sektor
	0,			// 30 - Shao Kahn: Cyrax
	0,			// 31 - Shao Kahn: Kung Lao
	0,			// 32 - Shao Kahn: Kabal
	0,			// 33 - Shao Kahn: Sheeva
	0,			// 34 - Shao Kahn: Shang Tsung
	0,			// 35 - Shao Kahn: Liu Kang
	0,			// 36 - Shao Kahn: Smoke
	0,			// 37 - Shao Kahn: Kitana
	0,			// 38 - Shao Kahn: Jade
	0,			// 39 - Shao Kahn: Mileena
	0,			// 3a - Shao Kahn: Scorpion
	0,			// 3b - Shao Kahn: Reptile
	0,			// 3c - Shao Kahn: Ermac
	0,			// 3d - Shao Kahn: Sub-Zero
	0,			// 3e - Shao Kahn: Smoke
	0,			// 3f - Shao Kahn: Kano wins
	0,			// 40 - Shao Kahn: Sonya wins
	0,			// 41 - Shao Kahn: Jax wins
	TS_SWORD_EJECT,			// 42 - Shao Kahn: Nightwolf wins
	0,			// 43 - Shao Kahn: Sub-Zero wins
	0,			// 44 - Shao Kahn: Stryker wins
	0,			// 45 - Shao Kahn: Sindel wins
	0,			// 46 - Shao Kahn: Sector wins
	0,			// 47 - Shao Kahn: Cyrax wins
	0,			// 48 - Shao Kahn: Kung Lao wins
	0,			// 49 - Shao Kahn: Cabal wins
	0,			// 4a - Shao Kahn: Sheeva wins
	0,			// 4b - Shao Kahn: Shang Tsung wins
	0,			// 4c - Shao Kahn: Liu Kang wins
	0,			// 4d - Shao Kahn: Smoke wins
	0,			// 4e - Shao Kahn: Kitana wins
	0,			// 4f - Shao Kahn: Jade wins
	0,			// 50 - Shao Kahn: Mileena wins
	0,			// 51 - Shao Kahn: Scorpion wins
	0,			// 52 - Shao Kahn: Reptile wins
	0,			// 53 - Shao Kahn: Ermac wins
	0,			// 54 - Shao Kahn: SZ wins
	0,			// 55 - Shao Kahn: Smoke wins
	0,			// 56 - Shao Kahn: Its Offical wins
	0,			// 57 - Shao Kahn: Motaro wins
	0,			// 58 - Shao Kahn: I wins
	0,			// 59 -
	0,			// 5a -
	0,			// 5b -
	0,			// 5c -
	0,			// 5d -

	TS_BURNING_FLAMES,		// 5e - burning flames (NOT USED)
	0x8000|TS_LAVA_SIZZLE,	// 5f - lava acid sizzle hit
	TS_KISS,				// 60 - explode thru street (kiss sound)


	TS_SK_FLAWLESS,		// 61 - Shao Kahn: Flawless Victory
	TS_SK_FATALITY,		// 62 - Shao Kahn: Fatality!
	0,					// 63 - Shao Kahn: Mercy
	TS_SK_ANIMALITY,	// 64 - Shao Kahn: Animality
	TS_SK_BABALITY,		// 65 - Shao Kahn: Babality
	TS_SK_CRISPY,		// 66 - Shao Kahn: Crispy
	TS_SK_FROSTY,		// 67 - Shao Kahn: Frosty
	TS_SK_FRIEND,		// 68 - Shao Kahn: Friendship
	TS_SK_FRIEND1,		// 69 - Shao Kahn: Friendship!?!
	TS_SK_AGAIN,		// 6a - Shao Kahn: Again?
	0,					// 6b - Shao Kahn: Toasty High
	TS_SK_TOASTYL,		// 6c - Shao Kahn: Toasty Low
	TS_SK_OMAW,			// 6d - Shao Kahn: Oh maw
	TS_CURSOR_MOVE,		// 6e - mode select cursor move
	TS_CURSOR_PICK,		// 6f -	mode select cursor pick

	0x8000|TS_NASTY_GOO,		// 70 - nasty goo
	TS_DANGER,					// 71 - danger danger
	TS_FLAWLESS_TONE,			// 72 - flawless tone
	0,							// 73 
	TS_SK_SUBERB,				// 74 - Shao Kahn: Superb
	TS_SK_WELL_DONE,			// 75 - Shao Kahn: Well Done
	TS_SK_VS,					// 76 - Shao Kahn: ... versus ...
	TS_SK_WINS,					// 77 - Shao Kahn: ... wins
	TS_SK_SHOW_MERCY,			// 78 - Shao Kahn: ... shows mercy
	TS_SK_LAUGH1,				// 79 - Shao Kahn: Laugh #1
	TS_SK_LAUGH2,				// 7a - Shao Kahn: Laugh #2
	TS_SK_LAUGH3,				// 7b - Shao Kahn: Laugh #3
	TS_SK_EXCELLENT,			// 7c - Shao Kahn: Excellent
	TS_SK_NEVER_WIN, 			// 7d - Shao Kahn: You will never win
	TS_SK_OUTSTANDING,			// 7e - Shao Kahn: Outstanding
	TS_SK_LAST_HIT,				// 7f - Shao Kahn: Last Hit

	TS_HGAME_FIRE,				// 80 - hidden game fire
	RSND_EBOOM2,				// 81 - hidden game explode
	ST_SK_PATHETIC,				// 82 - Shao Kahn: That was Pathetic
	TS_KLANG1,					// 83 - klang 1
	TS_SUB_APPROACH,			// 84 - subway approaching
	TS_SUB_STEADY,				// 85 - subway steady state
	TS_SUB_GOING,				// 86 - subway going away
	TS_FINAL_DEATH,				// 87 - Final Death Quake Loop
	TS_SK_DEATH,				// 88 - Shao Kahn Death Scream
	TS_DEATH_QUAKE,				// 89 - Final Death Quake Loop Crescendo (3x)
	0x8000|TS_DOG,				// 8a - dog
	0x8000|TS_DOG_OUCH,			// 8b - dog ouch
	TS_BABY_POOF,		// 8c - babality poof
	0x8000|TS_BABY_CRY,			// 8d - baby cry
	TS_CHURCH_BELL,				// 8e - bell - bell
	TS_ITS_OFFICAL,				// 8f - its offical

	TS_SK_MOTARO,			// 90 - Shao Kahn: Motaro
	TS_SK_CHOOSE,			// 91 - Shak Kahn: Choose your destiny
	TS_ANIM_ROAR,			// 92 - Huge Animal Roar!
	TS_PLAY_BUY,			// 93 - player buys in
	TS_MUSIC_MERCY,			// 94 - mercy music hit 
	TS_ANIM_BONUS,			// 95 - animality bonus count roar
	TS_SKBRUTE,						// 96 - brutality
	TS_SCREENFL,						// 97 - logo off
	TS_SCREENIN,						// 98 - mugs on

	TS_AGGRESOR,						// 99 - Agressor
	TEAM1_W,						// 9a - TEAM 1 WINS
	TEAM2_W,						// 9b - TEAM 2 WINS
	0,						// 9c - Shao Kahn: Nightwolf shows mercy
	0,						// 9d - Shao Kahn: Sub-Zero shows mercy
	0,						// 9e - Shao Kahn: Stryker shows mercy
	0,						// 9f - Shao Kahn: Sindel shows mercy
	0,						// a0 - Shao Kahn: Sektor shows mercy
	0,						// a1 - Shao Kahn: Cyrax shows mercy
	0,						// a2 - Shao Kahn: Kung Lao shows mercy
	0,						// a3 - Shao Kahn: Cabal shows mercy
	0,						// a4 - Shao Kahn: Sheeva shows mercy
	0,						// a5 - Shao Kahn: Shang Tsung shows mercy
	0,						// a6 - Shao Kahn: Liu Kang shows mercy
	0,						// a7 - Shao Kahn: Smoke shows mercy
	0,						// a8 - Shao Kahn: Kitana shows mercy
	0,						// a9 - Shao Kahn: Jade shows mercy
	0,						// aa - Shao Kahn: Mileena shows mercy
	0,						// ab - Shao Kahn: Scorpion shows mercy
	0,						// ac - Shao Kahn: Reptile shows mercy
	0,						// ad - Shao Kahn: Ermac shows mercy
	0,						// ae - Shao Kahn:  shows mercy
	0,						// af - Shao Kahn:  shows mercy

	TUNE_VERSUS,			// b0 - vs tune
	TUNE_SELECT,			// b1 - select
	TUNE_GAMEOVER,			// b2 - game over
	TS_MONKEY,				// b3 - monkey scream
	TS_FROG,				// b4 - frog ribit
	TS_TREE_ROAR,			// b5 - tree roar (mk2)
	TS_SPLASH,				// b6 - dead pool splash (mk2)
	TS_BUBBLE,				// b7 - dead pool bubble (mk2)
	TS_OH_MAW,				// b8 - dead pool oh maw
	TS_VORTEX1,				// b9 - vortex effect #1
	TS_VORTEX2,				// ba - vortex effect #2
};

short triple_sndtab2[]=	
{
	TS_SK_KANO,				// 0 - Shao Kahn: Kano
	TS_SK_SONYA,			// 1 - Shao Kahn: Sonya
	TS_SK_JAX,				// 2 - Shao Kahn: Jax
	TS_SK_NIGHTWOLF, 		// 3 - Shao Kahn: Night Wolf
	TS_JOHNCAGE,			// 4 - Shao Kahn: Johnny Cage
	TS_SK_STRYKER,			// 5 - Shao Kahn: Stryker
	TS_SK_SINDEL,			// 6 - Shao Kahn: Sindel
	TS_SK_SEKTOR,			// 7 - Shao Kahn: Sektor
	TS_SK_CYRAX,			// 8 - Shao Kahn: Cyrax
	TS_SK_LAO,				// 9 - Shao Kahn: Kung Lao
	TS_SK_KABAL,			// a - Shao Kahn: Kabal
	TS_SK_SHEEVA,			// b - Shao Kahn: Sheeva
	TS_SK_ST,				// c - Shao Kahn: Shang Tsung
	TS_SK_LKANG,			// d - Shao Kahn: Liu Kang
	TS_SK_SMOKE,			// e - Shao Kahn: Smoke
	TS_SK_KITANA,			// f - Shao Kahn: Kitana
	TS_SK_JADE,				// 10 - Shao Kahn: Jade
	TS_SK_MILEENA,			// 11 - Shao Kahn: Mileena
	TS_SK_SCORP,			// 12 - Shao Kahn: Scorpion
	TS_SK_REPTILE,			// 13 - Shao Kahn: Reptile
	TS_SK_ERMAC,			// 14 - Shao Kahn: Ermac
	TS_SK_SUBZERO,			// 15 - Shao Kahn: Sub-Zero
	TS_SK_SMOKE,			// 16 - Shao Kahn: Smoke
	TS_SK_NOOB,			// 17 - Shao Kahn: Noob
	TS_SK_RAIDEN,			// 18 - Shao Kahn: Rayden
	TS_SK_BARAKA,			// 19 - Shao Kahn: Baraka
	TS_SK_RAIN,				// 1a - Shao Kahn: Rain
	TS_SKCHAM,			// 1b - Shao Kahn: Chamelon
	TS_SK_SMOKE,			// 1c - Shao Kahn: C2
	TS_SK_SMOKE,			// 1d - Shao Kahn: C3
	TS_SK_MOTARO,			// 1e - Shao Kahn: Motaro
	TS_SK_SMOKE,			// 1f - Shao Kahn: Shao Kahn
	
	KANO_W,				// 20 - Shao Kahn: Kano Wins
	SONYA_W,			// 21 - Shao Kahn: Sonya Wins
	JAX_W,				// 22 - Shao Kahn: Jax Wins
	NITWLF_W, 			// 23 - Shao Kahn: Night Wolf Wins
	JCAGE_W,				// 24 - Shao Kahn: Johnny Cage Wins
	STRYK_W,			// 25 - Shao Kahn: Stryker Wins
	SINDEL_W,			// 26 - Shao Kahn: Sindel Wins
	SECTOR_W,			// 27 - Shao Kahn: Sektor Wins
	CYRAX_W,			// 28 - Shao Kahn: Cyrax Wins
	KUNG_W,				// 29 - Shao Kahn: Kung Lao Wins
	CABAL_W,			// 2a - Shao Kahn: Kabal Wins
	SHEEV_W,			// 2b - Shao Kahn: Sheeva Wins
	SHANG_W,			// 2c - Shao Kahn: Shang Tsung Wins
	LIUK_W,				// 2d - Shao Kahn: Liu Kang Wins
	SMOKE_W,			// 2e - Shao Kahn: Smoke Wins
	KITANA_W,			// 2f - Shao Kahn: Kitana Wins
	JADE_W,				// 30 - Shao Kahn: Jade Wins
	MALENA_W,			// 31 - Shao Kahn: Mileena Wins
	SCORP_W,			// 32 - Shao Kahn: Scorpion Wins
	REPT_W,				// 33 - Shao Kahn: Reptile Wins
	ERMAC_W,			// 34 - Shao Kahn: Ermac Wins
	SUBZ_W,				// 35 - Shao Kahn: Sub-Zero Wins
	SMOKE_W,			// 36 - Shao Kahn: Smoke Wins
	NOOB_W,			// 37 - Shao Kahn: Noob Wins
	RAIDEN_W,			// 38 - Shao Kahn: Rayden Wins
	BARAKA_W,			// 39 - Shao Kahn: Baraka Wins
	RAIN_W,				// 3a - Shao Kahn: Rain Wins
	KAMEL_W,			// 3b - Shao Kahn: Camel Wins
	SMOKE_W,			// 3c - Shao Kahn: C2 Wins
	SMOKE_W,			// 3d - Shao Kahn: C3 Wins
	MOTAR_W,			// 3e - Shao Kahn: Motaro Wins
	SMOKE_W,			// 3f - Shao Kahn: Shao Kahn Wins
	
	KANO_S,				// 40 - Shao Kahn: Kano mercy
	SONYA_S,			// 41 - Shao Kahn: Sonya mercy
	JAX_S,				// 42 - Shao Kahn: Jax mercy
	NITWLF_S, 			// 43 - Shao Kahn: Night Wolf mercy
	JCAGE_S,				// 44 - Shao Kahn: JOHNNY CAGE mercy
	STRYK_S,			// 45 - Shao Kahn: Stryker mercy
	SINDEL_S,			// 46 - Shao Kahn: Sindel mercy
	SECTOR_S,			// 47 - Shao Kahn: Sektor mercy
	CYRAX_S,			// 48 - Shao Kahn: Cyrax mercy
	KUNG_S,				// 49 - Shao Kahn: Kung Lao mercy
	CABAL_S,			// 4a - Shao Kahn: Kabal mercy
	SHEEV_S,			// 4b - Shao Kahn: Sheeva mercy
	SHANG_S,			// 4c - Shao Kahn: Shang Tsung mercy
	LIUK_S,				// 4d - Shao Kahn: Liu Kang mercy
	SMOKE_S,			// 4e - Shao Kahn: Smoke mercy
	KITANA_S,			// 4f - Shao Kahn: Kitana mercy
	JADE_S,				// 50 - Shao Kahn: Jade mercy
	MALENA_S,			// 51 - Shao Kahn: Mileena mercy
	SCORP_S,			// 52 - Shao Kahn: Scorpion mercy
	REPT_S,				// 53 - Shao Kahn: Reptile mercy
	ERMAC_S,			// 54 - Shao Kahn: Ermac mercy
	SUBZ_S,				// 55 - Shao Kahn: Sub-Zero mercy
	SMOKE_S,			// 56 - Shao Kahn: Smoke mercy
	NOOB_S,			// 57 - Shao Kahn: Noob mercy
	RAIDEN_S,			// 58 - Shao Kahn: Rayden mercy
	BARAKA_S,			// 59 - Shao Kahn: Baraka mercy
	RAIN_S,				// 5a - Shao Kahn: Rain mercy
	KAMEL_S,			// 5b - Shao Kahn: C1 KAMEL
	SMOKE_S,			// 5c - Shao Kahn: C2 mercy
	SMOKE_S,			// 5d - Shao Kahn: C3 mercy
	MOTAR_S,			// 5e - Shao Kahn: Motaro mercy
	SMOKE_S,			// 5f - Shao Kahn: Shao Kahn mercy
};

short *triple_end = triple_sndtab+sizeof(triple_sndtab);
short *triple_end2 = triple_sndtab2+sizeof(triple_sndtab2);

/******************************************************************************
 Function: void next_table_sound(WORD pa0,short *pa1)

 By: David Schwartz

 Date: Apr 1995

 Parameters: pa0 - # of entries in table
			 pa1 - ptr to table of effects

 Returns: None

 Description:	rnd pick a sound effect call from the supplied table
******************************************************************************/
void next_table_sound(WORD pa0,short *pa1)
{
	short *sndptr;

#if 0
	if (f_no_sfx)
		return;
#endif	

	sndptr=pa1+((randu(pa0)-1));				// 1 short/sound effect

	tsnd0(sndptr,sound_pan_value());
}

WORD triple_sound(WORD pa0,WORD tbl)
{
	short *sndptr;

	if (tbl==0) 
	{
		sndptr=triple_sndtab+(pa0);				// get ptr to sound entry (2 short/sound effect)

		if (sndptr<triple_end)
			tsnd0(sndptr,(*sndptr & 0x8000)? sound_pan_value():64);
	}
	else
	{
		sndptr=triple_sndtab2+(pa0);				// get ptr to sound entry (2 short/sound effect)

		if (sndptr<triple_end2)
			tsnd0(sndptr,(*sndptr & 0x8000)? sound_pan_value():64);
	}

	return(*sndptr & 0x7fff);
}

void tsnd0(short *pa0,WORD pan)
{
	TriggerPlayAttr trigger;

	trigger.mask=TRIGGER_PAN;
	trigger.pan=pan;

	if (f_nosound==0)
		wess_seq_trigger_special(*pa0 & 0x7fff,&trigger);

	return;
}

/******************************************************************************
 Function: void psound_for_him(WORD offset)

 By: David Schwartz

 Date: Apr 1995

 Parameters: offset - sound offset num

 Returns: None

 Description:	lets a player make a sound call for another player by pretending he
				is him for an instance
******************************************************************************/
void psound_for_him(WORD offset)
{
	PROCESS *pa13;

	pa13=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	tsound(offset);
	current_proc=pa13;

	return;
}

/******************************************************************************
 Function: void nosounds(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	cancells all sound calls, zeros all priorities and kills any tunes running
******************************************************************************/
void nosounds(void)
{
	send_code_a3(0);
	return;
}

/******************************************************************************
 Function: void send_code_a3(WORD pa3)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa3 - sound effect # (0=shut up system)

 Returns: None

 Description:	play a sound effect directly or shut up the system
******************************************************************************/
extern WORD title_song;

void send_code_a3(WORD pa3)
{
	if (pa3==0)
	{
		wess_seq_stoptype(0);
		if (title_song!=1)
			wess_seq_stoptype(5);
	}
	else
	{
#if 0
		if (!f_no_sfx)
#endif	
			wess_seq_trigger(pa3);
	}

	return;
}

/******************************************************************************
 Function: void hob_ochar_sound(WORD hit_off,WORD block_off)

 By: David Schwartz

 Date: Jan 1995

 Parameters: hit_off (a0[31..16])
			 block_off  (a0[15..0])

 Returns: None

 Description:
******************************************************************************/
void hob_ochar_sound(WORD hit_off,WORD block_off)
{

	if (f_block)
		ochar_sound(block_off);
	else ochar_sound(hit_off);

	return;
}

/******************************************************************************
 Function: void hit_or_blocked_sound(WORD hit_off,WORD block_off)

 By: David Schwartz

 Date: Jan 1995

 Parameters: hit_off (a0[31..16])
			 block_off  (a0[15..0])

 Returns: None

 Description:
******************************************************************************/
void hit_or_blocked_sound(WORD hit_off,WORD block_off)
{

	if (f_block)
		tsound(block_off);
	else tsound(hit_off);

	return;
}

/******************************************************************************
******************************************************************************/
short st_kano[]=
{
 	ST_KANO_AX,				//0 - Kano ax
	ST_KANO_SKNIFE,			//1 - Kano spinning knife
	ST_KANO_SKNIFE_HIT,		//2 - Kano knife hit
	ST_KANO_SKNIFE_BLK,		//3 - Kano knife blocked
	ST_KANO_BALL,		  	//4 - Kano ball trajectory
	FT_KANO_LASER,		 	//5 - kano laser (borrow)
	FT_KANO_LASER_BURN,	  	//6 - kano laser burn
	FT_KANO_SKELETON_RIP,	//7 - skeleton rip (borrow)
	FT_KANO_SKIN_FALL		//8 - skin falling to ground
};

short st_sonya[]=
{
   	ST_SONYA_RINGS,		  	//0 - sonya rings
   	ST_SONYA_RINGS_HIT,		//1 - sonya rings hit
   	ST_SONYA_RINGS_BLK,	 	//2 - sonya rings blocked
   	ST_SONYA_BIKE,		 	//3 - sonya bike kick
   	ST_SONYA_FLY,			//4 - Sonya Fly
   	ST_SONYA_BIKE_VOICE,	//5 - Sonya bike kick voice (nwtowtdutb)
	FT_SONYA_BLOW_KISS,		//6 - fatal blow kiss
	FT_SONYA_QUAKE,			//7 -
};

short st_jax[]=
{
   	ST_JAX_CANNON,			//0 - Jax Cannon fire
   	ST_JAX_ZAP_HIT,			//1 - jax zap hit
   	ST_JAX_ZAP_BLK,		//2 - jax zap blocked
   	ST_JAX_BLURR,	 		//3 - jax blurr
   	ST_JAX_GROUND,	 		//4 - jax ground smash
   	ST_JAX_SLAM,			//5 - jax slamming you on ground
	ST_JAX_GOTCHA,			//6 - gotcha!!
	FT_JAX_ARM_MORPH,		//7 - arm morph
	FT_JAX_CRUNCH1,			//8 - crunch!
	FT_JAX_CRUNCH2,			//9 - crunch #1
	FT_JAX_QUAKE,			//a - death quake
	ST_JAX_BREAK,			//b - bax break
	ST_ROBO_CLANG1,			//c - robo metal ball clang 1 
};

#if 0
short st_subzero[]=
{
   	ST_SZ_ICE_UP,	   		//0 - ice up
   	ST_SZ_ICE_DOWN,	   	//1 - ice down
   	ST_SZ_ICE_HIT,	 	  	//2 - ice hit
   	ST_SZ_ICE_BLOCK,   	//3 - ice blocked
   	ST_SZ_ICE_HIT2,	   	//4 - ice hit
   	ST_SZ_ICE_DECOY,   	//5 - hit by decoy
   	ST_SZ_SLIDE,		 	//6 - slide
	FT_SZ_BLOW,				// 7 - blow
	FT_SZ_FROZE				// 8 - froze dude
};
#endif
#define ST_JC_SNOT ST_JC_SNOT_HIT	
short st_jc[]=
{
	ST_JC_KISS,				//  0
	ST_JC_KICK,				//  1
	ST_JC_SNOT,				//  2
	ST_JC_SNOT_HIT,			//  3
	ST_JC_SNOT_BLK,			//  4
	ST_JC_SELBOW,			//  5
	ST_JC_SELBOW,			//  6
	ST_JC_SELBOW,			//  7
	ST_JC_SELBOW,			//  8
	ST_JC_SELBOW,			//  9
	ST_JC_SELBOW,			//  a
};

short st_swat[]=
{
	ST_SWAT_BOMB_EXP,  	//0 - swat bomb explode (borrow)
	ST_SWAT_BOMB_THROW,   	//1 - swat bomb throw (borrow)
	ST_SWAT_ZOOM,			//2 - swat zoom (borrow)
	ST_SWAT_STICK,			//3 - swat stick sweep kick (borrow)
	ST_SWAT_ZOOM_THROW, 	//4 - swat zoom throw
	ST_SWAT_BANG, 			//5 - swat gun bang
	FT_SWAT_TASER, 		//6 - taser shock sound
	FT_SWAT_TASER_FIRE,  	//7 - swat taser gun FIRE !
	FT_SWAT_WHISTLE
};

short st_indian[]=
{
  	ST_IND_ARROW_APPEAR,	 	//0 - arrow appear
  	ST_IND_ARROW_FIRE,	 	//1 - arrow fire
  	ST_IND_BURN_AXE,		  	//2 - burning axe
  	ST_IND_ARROW_HIT,		//3 - arrow hit
  	ST_IND_ARROW_BLK,		//4 - arrow blocked
  	ST_IND_AXE_UP,			//5 - indian axe up
  	ST_IND_KNEE_BREAK,		//6 - knee break
  	ST_IND_REFLECT,			//7 - reflector
  	ST_IND_SHADOW_SHLD,		//8 - shadow shoulder
  	ST_IND_AXE_HIT,			//9 - axe hit
  	FT_IND_LIGHT_START,		//a - ind light start
  	FT_IND_LIGHT_LOOP,		//b - ind light loop
  	FT_IND_LIGHT_END,		//c - ind light end
  	FT_IND_LIGHT_HIT_AXE,	//d - lightning hit axe
  	FT_IND_LIGHT_HIT_HIM	//e - lightning hit him!
};

short st_lia[]=
{
   	ST_LIA_HAIR,		   	  	//0 - hair throw sound
   	ST_LIA_SCREAM,			  	//1 - scream trap !!
   	ST_LIA_FIREBALL,	   	 	//2 - lia fireball
   	ST_LIA_FIREBALL_HIT,  	 	//3 - lia fireball hit
   	ST_LIA_FIREBALL_BLOCK,	 	//4 - lia fireball blocked
   	ST_LIA_FLY_UP,			  	//5 - lia fly up
   	ST_LIA_FLY_ACROSS,		 	//6 - lia fly across
	FT_LIA_HAIR,				//7 - lia hair tornado
	FT_LIA_QUAKE,				//8 - death quake loop borrow
	FT_LIA_TWFUN				//9 - that was fun
};

#define st_robo2 st_robo1
short st_robo1[]=
{
	ST_ROBO_ARM_OUT,			 	//0 - robo arm OUT
	ST_ROBO_ARM_THROW,		 	//1 - robo arm THROW
	ST_ROBO_ARM_IN,			 	//2 - robo arm IN
	ST_ROBO_FAST_ROCKET,		 	//3 - robo fast rocket
	ST_ROBO_CRUISE_ROCKET,  	//4 - robo criuse rocket
	ST_ROBO_NET,				 	//5 - robo net throw
	ST_ROBO_ZAP_HIT,				//6 - jax zap hit
	ST_ROBO_DROP,			 	//7 - robo drop through ground tele
	ST_ROBO_CLANG1,			 	//8 - robo metal ball clang 1
	ST_ROBO_CLANG2,			 	//9 - robo metal ball clang 2
	ST_ROBO_BALL_BOOM,		 	//a - robo metal ball BOOM
	ST_ROBO_CHEST_OPEN,		 	//b - robo chest open
	ST_ROBO_TARGET,			 	//c - robo target sound
	ST_ROBO_EXPLODE,			 	//d - robo explode himself
	ST_ROBO_IMPLODE,			 	//e - robo implode himself
	ST_ROBO_SPARK1,			 	//f - robo spark #1
	ST_ROBO_SPARK2,			 	//10 - robo spark #2
	ST_ROBO_SPARK3,				//11 - robo spark #3
	ST_ROBO_SPEECH1,			 	//12 - robo speech 1
	ST_ROBO_SPEECH2,			 	//13 - robo speech 2
	ST_ROBO_SPEECH3,			 	//14 - robo speech 3
	ST_ROBO_SPEECH4,				//15 - robo speech 3
	FT_ROBO_CRSH_OUT,				//16 - crusher comes out
	FT_ROBO_CRSH_DOWN,				//17 - crusher down !
	FT_ROBO_CRSH_SMOOSH1,			//18 - crusher smoosh
	ST_ROBO_SPEAR,					//19 - spear throw (FOR SPEAR CALL SMOKE)
	FT_ROBO_BEEP,					//1a - beep
	FT_ROBO_SELF_DESTRUCT,			//1b - self destruct sounds !!
	FT_ROBO_DESTRUCT_LAFF,			//1c - self destruct laugh !!
	FT_ROBO_WHIRL,					//1d -
	FT_ROBO_QUAKE,					//1e - death quake loop borrow
	ST_ROBO_SPEAR,					//1f - spear stab
	FT_ROBO_BAT,					//20 - bat sound
	FT_ROBO_SLIDE,					//21 - slide whistle
	FT_ROBO_HORN,					//22 - horn
	ST_ROBO_PROPELL,				//23 - cyrax propell move
};

short st_lao[]=
{
  	ST_LAO_ANGLE,	  	//0 - kung lao angle kick
  	ST_LAO_HAT_THROW,  	//1 - lao hat throw
  	ST_LAO_HAT_HIT,	  	//2 - lao hat hit
  	ST_LAO_HAT_BLK,	  	//3 - lao hat bloked
  	ST_LAO_TELE,		  	//4 - lao tele (ejbpatch-borrowed from robo)
  	ST_LAO_THROW,	  	//5 - lao throw
	FT_LAO_TORNADO,			//6 - lao tornado
	FT_LAO_QUAKE,			//7 - death quake loop borrow
	FT_LAO_TORNADO_HIT		//8 - lao tornado
};

short st_tusk[]=
{
   	ST_TUSK_ZAP,		 	//0 - lia fireball hit
   	ST_TUSK_CANNON,		//1 - Jax Cannon fire (photon fire)
   	ST_TUSK_BLURR,	 	//2 - blurr (borrwed)
   	ST_TUSK_FLIP1,	 	//3 - kabal flip whoosh #1
   	ST_TUSK_FLIP2,		//4 - kabal flip whoosh #2
	ST_TUSK_SAW,			//5 - tusk saw
	ST_TUSK_REFLECT,		//6 - reflector
	FT_TUSK_BUBBLE,			//7 -
	FT_TUSK_GROW,			//8 -
	FT_TUSK_HEAD_SCREAM,	//9 - scary head scream
	FT_TUSK_BURN			//a - burning axe
};

short st_sg[]=
{
	ST_SG_TELE,		  	//0 - sg tele (borrow)
	ST_SG_POUNCE,	 	//1 - she pounce / jax slamming you on ground
	ST_SG_ZAP_HIT,		//2 - sg zap hit (borrow)
	ST_SG_ZAP,			//3 - sg zap (borrow)
	ST_SG_ZAP_START,	//4 - sg start zap (borrow)
	FT_SG_KLANG,		//5 - klang 2 (the sequel) !!
	FT_SG_SPIN			//6 - spin plate
};

short st_st[]=
{
   	ST_ST_CANNON,		//0 - Jax Cannon fire
   	ST_ST_SUMMON,	 	//1 - summon
   	ST_ST_FIRE_HIT,		//2 - fireball hit
   	ST_ST_SKULL,		//3 - sonya rings (skull fire)
   	ST_ST_MORPH,		//4 - morph
   	ST_ST_FLIP,		 	//5 - shang tsung flip tumble sound
   	ST_ST_FIRE_BLK,		//6 - fireball block
	FT_ST_SWORD,		//7 - sword rise
	FT_ST_CLOUD,		//8 - energy cloud
	FT_ST_BONES			//9 - bonz
};

short st_lk[]=
{
	ST_LK_FIRE,			//0 - lk fireball
	ST_LK_FIRE_HIT,		//1 - lk fireball hit
	ST_LK_SUPER_KICK,	//2 - super kick
	ST_LK_FIRE_BLK,		//3 - lk fireball blocked
	ST_LK_BIKE,		 	//4 - bike kick jibberish
	ST_LK_FLY_YELL,		//5 - flying kick yell
	FT_LK_FLAME_MORPH,	//6 - flame morph
	FT_LK_RUN,			//7 - kang: run (borrow)
	FT_LK_SLAM			//8 - jax slamming you on ground
};

short st_motaro[]=
{
  	ST_MOT_EFF1, 			//0 -
  	ST_MOT_EFF2, 			//1 -
  	ST_MOT_EFF3, 			//2 -
  	ST_MOT_HIT1, 			//3 - motaro hit 1
  	ST_MOT_HIT2, 			//4 - motaro hit 2
	ST_MOT_FIRE				//5 - fire
};

short st_sk[]=
{
	ST_SK_SHOULDER,		//0 - shadow shoulder (borrow)
	ST_SK_PHOTON,		//1 - fire photon (borrow from kabal)
	ST_SK_KLANG1,		//2 - klang 1 !!
	ST_SK_KLANG2,		//3 - klang 2 (the sequel) !!
	ST_SK_LAUGH1,		//4 - Shao Kahn: Laugh #1
	ST_SK_LAUGH2,		//5 - Shao Kahn: Laugh #2
	ST_SK_LAUGH3,		//6 - Shao Kahn: Laugh #3
	ST_SK_PATHETIC,		//7 - Shao Kahn: That was Pathetic
	ST_SK_NEVER_WIN,		//8 - Shao Kahn: You will never win
	ST_SK_STILL_TRYING,		//9 - Shao Kahn: You're still trying to win?
	ST_SK_DONT_LAUGH		//a - Shao Kahn: Don't make me laugh
};

short st_nj[]=		
{
	ST_SCORP_COME,			// 0 - Scorpion: Come here !!
	ST_SCORP_GET,			// 1 - Scorpion: Get over here !!
	ST_SCORP_SPEAR	,			// 2 - spear throw
	ST_OSZ_IBLOCK,			// 3 - ice blocked
	ST_OSZ_ICEHIT,			// 4 - ice hit
	ST_REP_EXP,			// 5 - orb explode
	ST_REP_SLIDE,			// 6 - slide
	ST_REP_INVISO,			// 7 - inviso
	ST_REP_SPIT,			// 8 - spit
	ST_ERMAC_POOF,			// 9 - inviso poof
	ST_SCORP_MASK,			// a - remove mask !!!
	ST_OSZ_ICEUP,			// b - ice up
	ST_SCORP_TELE,			// c - scorp tele sound
	ST_ERMAC_HIT,			// d - ermac zap hit (borrow)
	ST_OSZ_FLOOR,			// e - floor freeze
	ST_ERMAC_FLOOR,			// f - ermac floor rumble
	ST_REP_SIZZLE,			// 10 - acid sizzle hit
	ST_SCORP_STAB,			// 11 - spear stab
	ST_REP_ORB,			// 12 - orb move
	ST_REP_VOMIT,			// 13 - vomit start sound
   	ST_SZ_ICE_UP,	   		//14 - ice up
   	ST_SZ_ICE_DOWN,	   	//15 - ice down
   	ST_SZ_ICE_HIT,	 	  	//16 - ice hit
   	ST_SZ_ICE_BLOCK,   	//17 - ice blocked
   	ST_SZ_ICE_HIT2,	   	//18 - ice hit
   	ST_SZ_ICE_DECOY,   	//19 - hit by decoy
};

short st_fn[]=		
{
	ST_KIT_THROW,			//  0 - throw fan
	ST_KIT_FANH,			//  1 - fan hit
	ST_KIT_FANL,			//  2 - fan lift
	ST_KIT_KISS,			//  3 - Sonya blow kiss borrow
	ST_JADE_ARROW,			//  4 - arrow appear
	ST_JADE_ZAP,			//  5 - jade zap hit
	ST_JADE_PROP,			//  6 - jade prop sound
	ST_JADE_TELE,			//  7 - sg tele
	ST_MIL_SAI	,			//  8 - mileena sai throw
	ST_MIL_HIT	,			//  9 - mileena sai hit
	ST_MIL_ROLL	,			//  a - mileena roll
	ST_MIL_CLOUD,			//  b - energy cloud
	ST_JADE_FLASH,			//  c - jade flashy
};

short st_sa[]= 
{
	FT_ST_SWORD,					// 0 - decap head swipe
	ST_SA_SWORD,					// 1 - sword plunge
	ST_SA_SPARK,					// 2 - throw sparsk
	ST_SA_SPARKH,					// 3 - throw spark hit
	ST_SA_SPARKB,					// 4 - throw spark block
};

short st_rd[]=
{
	FT_IND_LIGHT_HIT_AXE,		// 0 - raiden lightning explode
	FT_RD_DEATH_ZAP,			// 1 - death zap fry
	ST_RD_THROW_LIGHT,			// 2 - bolt throw
	ST_RD_LIGHT_HIT,			// 3 - bolt hit
	ST_RD_LIGHT_BLOCKED,		// 4 - bolt blocked
	ST_RD_FRY,					// 5 - raiden fry
	ST_RD_TELEPORT,				// 6 - raiden teleport
	ST_RD_GETUP,				// 7 - raiden getup
	ST_RD_DIVE,					// 8 - raiden dive
	ST_RD_BBB,					// 9 - raiden -->bbb
	ST_RD_SSS,					// a - raiden -->sss
	ST_RD_TTT,					// b - raiden -->ttt
	ST_RD_NGBAS,				// c - raiden -->ngbas
	ST_RD_SWALL,				// d - dive smack wall
	ST_RD_KIDD,					// e - kidd thunder
};								    

short *ochar_sound_tables[]=
{
	st_kano,
	st_sonya,
	st_jax,
	st_indian,
	st_jc,
	st_swat,
	st_lia,
	st_robo1,
	st_robo2,
	st_lao,
	st_tusk,
	st_sg,
	st_st,
	st_lk,
	st_robo2,

	st_fn,
	st_fn,
	st_fn,

	st_nj,
	st_nj,
	st_nj,
	st_nj,
	st_nj,
	st_nj,

	st_rd,		//-u64-
	st_sa,
	st_nj,

	st_fn,

	st_nj,
	st_nj,
	st_motaro,
	st_sk,
};

/******************************************************************************
 Function: void ochar_sound(WORD offset)

 By: David Schwartz

 Date: Jan 1995

 Parameters: offset - offset into char data sound effect #

 Returns: None

 Description:	play a character specific sound effect #
******************************************************************************/
void ochar_sound(WORD offset)
{
	short *stbl;

#if 0
	if (f_no_sfx)
		return;
#endif	

	stbl=ochar_sound_tables[(current_proc->pa8)->ochar]+(offset);
	tsnd0(stbl,sound_pan_value());

	return;
}

void ochar_sound_stop(WORD offset)
{
	short *stbl;

#if 0
	if (f_no_sfx)
		return;
#endif	

	stbl=ochar_sound_tables[(current_proc->pa8)->ochar]+(offset);
	wess_seq_stop(*stbl);

	return;
}

/******************************************************************************
 Function: void his_ochar_sound(WORD offset)

 By: David Schwartz

 Date: Jan 1995

 Parameters: offset - snd effect offset within char table

 Returns: None

 Description:	act as the otherdude to get the correct sound
******************************************************************************/
void his_ochar_sound(WORD offset)
{
	WORD ta1;

	ta1=(current_proc->pa8)->ochar;
	(current_proc->pa8)->ochar=(current_proc->pdata.p_otherguy)->ochar;
	ochar_sound(offset);
	(current_proc->pa8)->ochar=ta1;
	return;
}

/******************************************************************************
 Function: void rsnd_ochar_sound(WORD pa0l,WORD pa0h)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pa0l - # of entries to choose from
			 pa0h - base offset

 Returns: None

 Description:	play a rnd sound effect for a character in the correct range
******************************************************************************/
void rsnd_ochar_sound(WORD pa0l,WORD pa0h)
{
	ochar_sound(pa0h+randu(pa0l)-1);
}

/******************************************************************************
 Function: void borrow_ochar_sound(WORD pa0,WORD pa1)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pa0 - snd effect offset within char table
			 pa1 - dude to borrow from

 Returns: None

 Description:	borrow sound effect from other dude
******************************************************************************/
void borrow_ochar_sound(WORD pa0,WORD pa1)
{
	WORD ta1;

	ta1=(current_proc->pa8)->ochar;
	(current_proc->pa8)->ochar=pa1;
	ochar_sound(pa0);
	(current_proc->pa8)->ochar=ta1;
	return;
}

/******************************************************************************
 Function: void sound_pan_value(void)

 By: David Schwartz

 Date: Jun 1995

 Parameters: None

 Returns: None

 Description:	Compute the pan value (1-127) - 64 centered, base on pa8->center position
******************************************************************************/
WORD sound_pan_value(void)
{
	OBJECT *obj=current_proc->pa8;
	short pos;

	pos=obj->oxpos.u.intpos;	//-worldtlx.u.intpos;

	if (!(obj->oflags2 & M_NOSCROLL))
		pos-=worldtlx.u.intpos;

	if (pos<0)
		pos=0;

	if (pos>SCRRGT)
		pos=SCRRGT;

	return((WORD)32+((128*pos) / (SCRRGT/2) ) /4);	/*	  pan value
 																		   				32---------64---------96
																						 	left     center		 right
																							*/
}

void sound_driver_config(void)
{
	/* configure panning */
	wess_pan_mode_set(f_no_pan);			// set pan mode (0=off 1=l/r 2=r/l

	/* configure cd volume */
	wess_master_mus_vol_set(f_music_vol);
	wess_master_sfx_vol_set(f_sfx_vol);
	
	/* configure stereo */
	return;
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_work - called by game loop to handle synchronization of music sequences.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_work( void ) {
#if SYS_DEBUG
	int seq_size;
#endif

	if( music_seq_waiting >= 0 ) {
		if( music_seq_playing<0 || (wess_seq_status( music_seq_playing ) != SEQUENCE_PLAYING) ) 
		{
			if( music_seq_playing >= 0 ) 
				wess_seq_free( music_seq_playing );
#if SYS_DEBUG
			if( (seq_size=wess_seq_sizeof(music_seq_waiting)) > SOUND_MUSIC_SEQ_BUFFER_SIZE ) 
			{
				while (1);
				printf(( " <<<< WARNING: music seqload buffer overflow >>>>\n" ));
				printf(( "               buffer size: %d bytes\n", SOUND_MUSIC_SEQ_BUFFER_SIZE ));
				printf(( "               seq %d size: %d bytes\n", music_seq_waiting, seq_size ));
			}
#endif
			wess_seq_load( music_seq_waiting, sys_music_buf );
			
			wess_seq_trigger_type( music_seq_waiting,5 );
			music_seq_playing = music_seq_waiting;
			music_seq_waiting = -1;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_start - starts a music sequence playing as soon as possible. If another
//                     sequence is currently playing, that sequence is stopped first.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_start( int seq_num ) 
{
#if 0
	if (f_music==0 || f_nosound)
#else	
	if (f_nosound)
#endif	
		return;
		
	music_seq_waiting = -1;
	if( music_seq_playing >= 0 ) 
	{
		wess_seq_stop( music_seq_playing );
	}
	music_seq_waiting = seq_num;
}

//////////////////////////////////////////////////////////////////////////////////////////
// sound_music_stop - stops the current music sequence from playing.
//////////////////////////////////////////////////////////////////////////////////////////
void sound_music_stop( void ) 
{
	music_seq_waiting = -1;
	if( music_seq_playing >= 0 ) 
	{
		wess_seq_stop( music_seq_playing );
	}
}

void error_callback_routine(char *msg,int err1,int err2) 
{
	printf(("CALLBACK\n"));
#if SYS_DEBUG
	printf(("WESS ERROR (%d:%d): %s\n",err1,err2,msg));
#endif	

	return;
}
