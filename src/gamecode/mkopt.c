/******************************************************************************
 File: mkopt.c

 Date: April 1995

 (C) Williams Entertainment

 Mortal Kombat III SONY OPTION SCREENS ROUTINES
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkopt.h"
#include "mkinit.h"
#include "mkjoy.h"
#include "mktext.h"
#include "mkdiag.h"
#include "mkfade.h"
#include "mkguys.h"
#include "mkpal.h"
#include "mksound.h"
#include "mkdma.h"

#include "vcache.h"

/* local externs */
extern OIMGTBL *icon_list[];
extern OIMGTBL *button_list[];

extern FNTSETUP pf_dave_smallc[];
extern FNTSETUP pf_15point[];

extern WORD YELLOW_p[];
extern WORD WHITE_p[];
extern WORD BLUE_p[];

extern BYTE button_dict[];
extern BYTE option_dict[];

extern void *nuoptions_module[];
extern void *nuoptcoin_module[];

extern void *fire_module[];
extern void *firedark_module[];

/***************************************************
 Joystick Remap Setup and Convert Tables
***************************************************/

OPTMAP opt_p1bridge[]=
{
	{B_TRI,&pad_tri[0]},
	{B_X,&pad_x[0]},
	{B_CIRCLE,&pad_circle[0]},
	{B_SQUARE,&pad_square[0]},
	{B_L1,&pad_l1[0]},
	{B_L2,&pad_l2[0]},
	{B_R1,&pad_r1[0]},
	{B_R2,&pad_r2[0]},
	{0,NULL}
};

OPTMAP opt_p2bridge[]=
{
	{B_TRI,&pad_tri[1]},
	{B_X,&pad_x[1]},
	{B_CIRCLE,&pad_circle[1]},
	{B_SQUARE,&pad_square[1]},
	{B_L1,&pad_l1[1]},
	{B_L2,&pad_l2[1]},
	{B_R1,&pad_r1[1]},
	{B_R2,&pad_r2[1]},
	{0,NULL}
};

/******************************************************************************
 Function: void opt_main(void)

 By: David Schwartz

 Date: March 1995

 Parameters: None

 Returns: None

 Description:	main routine for the options
******************************************************************************/
#define ICON_MOVE_TIME	10		// # of ticks to move from point a to point b
#define ICON_BASE_POS	(-246)
#define ICON_SPACING	180
#define ICON_RIGHT_VEL	(ICON_SPACING/ICON_MOVE_TIME)
#define ICON_LEFT_VEL	(-ICON_RIGHT_VEL)
#define ICON_Y_MIN		50
#define ICON_Y_MAX		115
#define ICON_Y_VEL		2

short icon_pos[]=
{
	ICON_BASE_POS+ICON_SPACING*0,	// center-2 kombat
	ICON_BASE_POS+ICON_SPACING*1,	// center-1, game
	ICON_BASE_POS+ICON_SPACING*2,	// center, control
	ICON_BASE_POS+ICON_SPACING*3,	// center+1,	sound
	ICON_BASE_POS+ICON_SPACING*4,	// center+2, secret
	ICON_BASE_POS+ICON_SPACING*5,	// center+3, secret1
	ICON_BASE_POS+ICON_SPACING*6,	// center+4, secret2
	ICON_BASE_POS+ICON_SPACING*7,	// center+5, secret3
	ICON_BASE_POS+ICON_SPACING*8,	// center+6, secret2
};

static WORD f_dummy=0;
static WORD f_centered;
void opt_main(void)
{
	OBJECT *obj;
	PROCESS *ptemp;
	int i,l;

	current_proc->pdata.p_store5=gstate;		// save current state so we can restore it

	gstate=GS_OPTIONS;					// set game state so that we don't have multiple copies runned

	murder_myoinit_score();
	f_doscore=0;

	/* allow D/A to loop */
	sound_music_start(MUSIC_FASTATTR);

	while (TRUE)
	{
		DISPLAY_OFF;
		murder_myoinit_score();

#if 0
		load_bkgd=BKGD_MK3_OPTION;
		init_background_module(nuoptions_module);
#endif
		load_bkgd=BKGD_FIRE_MOD;
		init_background_module(fire_module);
		multi_plane();
		dlists=dlists_bogus;

		/* setup and create icons */
		switch (f_cheat_menu)
		{
			case 0:
			case 1:
				l=OPT_ICON_SECRET;
				break;
			case 2:
				l=OPT_ICON_SECRET1;
				break;
			case 3:
				l=OPT_ICON_SECRET2;
				break;
			case 4:
				l=OPT_ICON_SECRET2;
				break;
		}

		for (i=0;i<l;i++)
		{
			gso_dmawnz_ns_coor(obj,(ADDRESS)icon_list[i],option_dict,0,0,icon_pos[i],ICON_Y_MIN+randu(ICON_Y_MAX-ICON_Y_MIN));
			alloc_cache((OIMGTBL*)icon_list[i],0,obj);
			insert_object(obj,&objlst);

			ptemp=CREATE(PID_OPTION,opt_icon);
			ptemp->pdata.p_store1=i;			// set index # into icon table
			ptemp->pdata.p_store2=i;			// set position number
			ptemp->pdata.p_store3=l;			// max # of positions
			ptemp->pdata.p_otherproc=current_proc;
		}

		/* adjust so kombat is in the center */
		i=2;				// move to right twice
		do
		{
			current_proc->a0=OPT_CMD_RIGHT;
			current_proc->pdata.p_store3=l;
			current_proc->pdata.p_store2++;
			while (current_proc->pdata.p_store3!=0)
			{
				process_sleep(1);
				current_proc->a0=OPT_CMD_NONE;
			}

		}
		while(--i>0);


		current_proc->a0=OPT_CMD_NONE;						// command none
		current_proc->pdata.p_store2=0;			// current position (center=kombat==0)
		current_proc->pdata.p_store3=0;			// # of dudes still doing a command

		fadein_jsrp(0x16);

		current_proc->a10=0;					// joy debounce
		/* main select loop */
		do
		{
			process_sleep(1);

			current_proc->a0=OPT_CMD_NONE;		// no command

			if (current_proc->a10!=0)
				current_proc->a10--;

			if (swcurr.padvalue & P1P2_ACTION)
			{
				/* we have made a selection */
				tsound(0x24);
				break;
			}

			if ((swcurr.padvalue & P1P2_LEFT) && current_proc->a10==0 && current_proc->pdata.p_store3==0)
			{
				/* move icons to the left */
				current_proc->a10=12;
				current_proc->a0=OPT_CMD_LEFT;
				current_proc->pdata.p_store3=l;				// # of guys doing a command
				if (++current_proc->pdata.p_store2==l)
					current_proc->pdata.p_store2=0;			// set to min
				tsound(0x28);

			}
			else
			{
				if ((swcurr.padvalue & P1P2_RIGHT) && current_proc->a10==0 && current_proc->pdata.p_store3==0)
				{
					/* move icons to the right */
					current_proc->a10=12;
					current_proc->a0=OPT_CMD_RIGHT;
					current_proc->pdata.p_store3=l;				// # of guys doing a command
					if (current_proc->pdata.p_store2--==0)
						current_proc->pdata.p_store2=l-1;			// set to max
					tsound(0x28);
				}
			}
		}
		while(1);

		/* selection made, do it */
		process_sleep(30);
		fast_fadeout_jsrp(20);

		switch (current_proc->pdata.p_store2)
		{
			case OPT_IKOMBAT:			// ready to return to caller
				gstate=current_proc->pdata.p_store5;
				murder_myoinit_score();
				init_vram_cache();
				return;
			case OPT_IGAME:		// game options
				murder_myoinit_score();
				f_centered=0;
				option_select(OPT_SCRN_GAME);
				init_vram_cache();
				break;
			case OPT_ISOUND:		// music options
				murder_myoinit_score();
				option_select(OPT_SCRN_MUSIC);
				init_vram_cache();
				break;
			case OPT_IKONTROL:		// joystick configuration
				murder_myoinit_score();
				opt_pad_setup(opt_p1bridge,pad1_map_tbl);
				opt_pad_setup(opt_p2bridge,pad2_map_tbl);
				option_select(OPT_SCRN_CONTROLS);
				opt_pad_remap(opt_p1bridge,pad1_map_tbl);
				opt_pad_remap(opt_p2bridge,pad2_map_tbl);
				init_vram_cache();
				break;
			case OPT_IQUEST1:
				murder_myoinit_score();
				option_select(OPT_SCRN_CHEAT1);
				init_vram_cache();
				break;
			case OPT_IQUEST2:
				murder_myoinit_score();
				option_select(OPT_SCRN_CHEAT2);
				init_vram_cache();
				break;
			case OPT_IQUEST3:
				murder_myoinit_score();
				option_select(OPT_SCRN_CHEAT3);
				init_vram_cache();
				break;
			case OPT_IQUEST4:
				murder_myoinit_score();
				mk3_thank_you();
				sound_music_start(MUSIC_FASTATTR);
				murder_myoinit_score();
				//option_select(OPT_SCRN_CHEAT2);
				//init_vram_cache();
				break;
		}
	}
	return;
}

#if 1
/* 
 current_proc->pdata.p_store8	->variable to monitor  (WORD *)
 current_proc->pdata.p_store6,7	->x,y position of slider
 current_proc->pdata.p_store5 	->id of slider so we can talk to outside world
 current_proc->pdata.a11		-> communication area
 
*/
extern void *VOLUME[];
extern BYTE control_dict[];
#define SLIDER_SIZE	68
#define SLIDER_MAX	124

#define SLIDER_DIE	0xffff
#define SLIDER_NOCOMM	0x00
#define SLIDER_HILITE	0x01
#define SLIDER_DARK		0x02

void slider_proc(void) 
{
	WORD *sptr;
	OBJECT *objbar,*objslider;
	short slider_size;
	
	current_proc->procid=current_proc->pdata.p_store5;
	
	/* set ptr of variable to monitor */
	sptr=(WORD *)current_proc->pdata.p_store8;
	
	/* setup and display slider object */
	gso_dmawnz(objslider,VOLUME,control_dict,0,0);
	alloc_cache((OIMGTBL *)VOLUME,0,objslider);
	objslider->oxpos.u.intpos=current_proc->pdata.p_store6;
	objslider->oypos.u.intpos=current_proc->pdata.p_store7;
	objslider->ozval=0;
	insert_object(objslider,&objlst);
	
	/* setup slider bar */
	slider_size=((*sptr)*SLIDER_SIZE)/SLIDER_MAX;
	objbar=make_solid_object(0x003f,slider_size,8);
	objbar->oxpos.u.intpos=objslider->oxpos.u.intpos+15;
	objbar->oypos.u.intpos=objslider->oypos.u.intpos+3;
	objbar->ozval=300;
	insert_object(objbar,&objlst);
	
	/* monitor and update slider bar */
	do
	{
		objbar->oflags&=~M_XLU_ON;		// unhilte
		
		if (current_proc->a11==SLIDER_HILITE)
		{
			/* hilite slider bar */
			objbar->oflags|=M_XLU_ON;
			objbar->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu
		}
		
		current_proc->a11=SLIDER_NOCOMM;
		
		/* update bar */
		slider_size=((*sptr)*SLIDER_SIZE)/SLIDER_MAX;
		objbar->osize.u.xpos=slider_size;
		process_sleep(1);
	} while (current_proc->a11!=SLIDER_DIE);
	
	delobjp(objbar);
	delobjp(objslider);
	process_suicide();
}
#endif

//******************************************************************************
//******************************************************************************
// current_proc->pdata.p_store1	=	my index into icon table
// current_proc->pdata.p_store2 =	my index into current world
// current_proc->pdata.p_store3 =	max # of positions in world
// (current_proc->pdata.p_otherproc)->a0 -	cmd to perform
// (current_proc->pdata.p_otherproc)->pdata.p_store2 -	selected icon
void opt_icon(void)
{
	OBJECT *obj=current_proc->pa8;
	PROCESS *ptemp;
	short icon_vel;

	ptemp=current_proc->pdata.p_otherproc;
	icon_vel=ICON_Y_VEL;

	do
	{
		switch (ptemp->a0)
		{
			case OPT_CMD_LEFT:
				stop_a8(obj);
				if (obj->oxpos.u.intpos<=icon_pos[0])
					obj->oxpos.u.intpos=icon_pos[current_proc->pdata.p_store3];		// max # of entires
				obj->oxvel.u.intpos=ICON_LEFT_VEL;
				process_sleep(ICON_MOVE_TIME);
				stop_a8(obj);
				ptemp->pdata.p_store3--;				// tell master i am listening
				break;
			case OPT_CMD_RIGHT:
				stop_a8(obj);
				obj->oxvel.u.intpos=ICON_RIGHT_VEL;
				process_sleep(ICON_MOVE_TIME);
				stop_a8(obj);

				if (obj->oxpos.u.intpos>=icon_pos[current_proc->pdata.p_store3])
					obj->oxpos.u.intpos=icon_pos[0];		// max # of entires

				ptemp->pdata.p_store3--;				// tell master i am listening
				break;
			case OPT_CMD_EXIT:
				//goto OPEXIT;
				break;
			case OPT_CMD_NONE:
			default:
				/* icon hover */
				if (icon_vel>0)
				{
					if (obj->oypos.u.intpos>=ICON_Y_MAX)
					{
						obj->oypos.u.intpos=ICON_Y_MAX;
						icon_vel*=-1;
					}
				}
				else
				{
				if (icon_vel<0)
				{
					if (obj->oypos.u.intpos<=ICON_Y_MIN)
						{
							obj->oypos.u.intpos=ICON_Y_MIN;
							icon_vel*=-1;
						}
					}
				}

				obj->oyvel.u.intpos=icon_vel;
				process_sleep(1);
		}
	}
	while(1);

OPEXIT:
	wait_forever();

	if (ptemp->pdata.p_store2!=current_proc->pdata.p_store1)
	{
		delobjp(obj);
		process_suicide();
	}

	wait_forever();
}

/******************************************************************************
 Function: void option_select(WORD scrnindex)

 By: David Schwartz

 Date: April 1995

 Parameters: scrnindex = which option screen
			0 - game configure
			1 - music configure
			2 - control configure

 Returns: None

 Description:	game selection options
******************************************************************************/
char *opt_screen_list[]=
{
	"GAME KONFIGURE",
	"SOUND AND MUSIC",
	"KONTROL KONFIGURE",
	"KONTROL KONFIGURE",
	"MISCELLANEOUS KOMBAT",
	"MORE KOMBAT",
	"KOMBAT CHEATS",
	"UNDER CONSTRUCTION",
};
char opt_txt_bloody[]="BLOODY KOMBAT";
char opt_txt_agress[]="AGGRESSOR MODE";
char opt_txt_center[]="CENTER SCREEN";
char opt_txt_on[]="ON";
char opt_txt_off[]="OFF";
char opt_txt_diff[]="DIFFICULTY";
char opt_txt_blood[]="BLOOD";
char opt_txt_clock[]="TIMER";
//char opt_txt_stereo[]="STEREO";
char opt_txt_pan[]="PAN CONTROL";
char opt_txt_sound[]="SOUND";
char opt_txt_music[]="MUSIC";
char opt_txt_musict[]="MUSIC TEST";
char opt_txt_free[]="FREE PLAY";
char opt_txt_fatal[]="FATALITY TIME";
char opt_txt_level[]="LEVEL SELECT";
char opt_txt_1round[]="1 ROUND MATCHES";
char opt_txt_1hit[]="1 HIT DEATHS";
char opt_txt_enable[]="ENABLED";
char opt_txt_disable[]="DISABLED";
char opt_txt_veasy[]="VERY EASY";
char opt_txt_easy[]="EASY";
char opt_txt_med[]="MEDIUM";
char opt_txt_hard[]="HARD";
char opt_txt_vhard[]="VERY HARD";
char opt_txt_lr[]="L/R";
char opt_txt_rl[]="R/L";
char opt_txt_exit[]="EXIT";
char opt_txt_mileena[]="MILEENA";
char opt_txt_ermac[]="ERMAC";
char opt_txt_osz[]="CLASSIC SUB-ZERO";
char opt_txt_hk[]="HIGH KICK";
char opt_txt_lk[]="LOW KICK";
char opt_txt_hp[]="HIGH PUNCH";
char opt_txt_lp[]="LOW PUNCH";
char opt_txt_run[]="RUN";
char opt_txt_block[]="BLOCK";
char opt_txt_unass[]="UNASSIGNED";
char opt_txt_coll[]="COLLISION BOXES";
char opt_txt_combo1[]="PLAYER 1 KOMBOS";
char opt_txt_combo2[]="PLAYER 2 KOMBOS";
char opt_txt_auto[]="AUTO";
char opt_txt_throws[]="THROWING";
char opt_txt_runs[]="UNLIMITED RUNS";
char opt_txt_osm[]="SMOKE";
char opt_txt_kamel[]="KHAMELEON";

#if SYS_DEBUG
char opt_txt_anim[]="ANIMAL";
char opt_txt_anim1[]="ANIMAL END";
char opt_txt_bab[]="BABY";
char opt_txt_friend[]="FRIEND";
char opt_txt_youwin[]="U WIN";
char opt_txt_select[]="SELECT";
char opt_txt_vs[]="VS";
char opt_txt_oneplay[]="ONE PLAY";
char opt_txt_endone[]="END ONE PLAY";
char opt_txt_fast[]="FAST";
char opt_txt_fast1[]="FAST 0";
char opt_txt_bank []="BANK";
char opt_txt_banke[]="BANKE";
char opt_txt_bankf[]="BANKF";
char opt_txt_bridge[]="BRIDGE";
char opt_txt_bridgee[]="BRIDGEE";
char opt_txt_bridgef[]="BRIDGEF";
char opt_txt_church	[]="CHURCH";
char opt_txt_churche[]="CHURCHE";
char opt_txt_churchf[]="CHURCHF";
char opt_txt_grave	[]="GRAVE";
char opt_txt_gravee	[]="GRAVEE";
char opt_txt_gravef	[]="GRAVEF";
char opt_txt_green	[]="GREEN";
char opt_txt_greene	[]="GREENE";
char opt_txt_greenf	[]="GREENF";
char opt_txt_pit	[]="PIT";
char opt_txt_pite	[]="PITE";
char opt_txt_pitf	[]="PITF";
char opt_txt_roof	[]="ROOF";
char opt_txt_roofe	[]="ROOFE";
char opt_txt_rooff	[]="ROOFF";
char opt_txt_special[]="SPEC";
char opt_txt_speciale[]="SPECE";
char opt_txt_specialf[]="SPECF";
char opt_txt_street	 []="STREET";
char opt_txt_streete []="STREETE";
char opt_txt_streetf []="STREETF";
char opt_txt_train	 []="TRAIN";
char opt_txt_traine	 []="TRAINE";
char opt_txt_trainf	 []="TRAINF";
char opt_txt_buyin	 []="BUYIN";

char *opt_music_list[]= 
{
	opt_txt_anim,
	opt_txt_anim1,
	opt_txt_bab,
	opt_txt_fatal,
	opt_txt_friend,
	opt_txt_youwin,
	opt_txt_select,
	opt_txt_vs,
	opt_txt_oneplay,
	opt_txt_endone,
	opt_txt_fast,
	opt_txt_fast1,
	opt_txt_bank,
	opt_txt_banke,
	opt_txt_bankf,
	opt_txt_bridge,
	opt_txt_bridgee,
	opt_txt_bridgef,
	opt_txt_church,
	opt_txt_churche,
	opt_txt_churchf,
	opt_txt_grave,
	opt_txt_gravee,
	opt_txt_gravef,
	opt_txt_green,
	opt_txt_greene,
	opt_txt_greenf,
	opt_txt_pit,
	opt_txt_pite,
	opt_txt_pitf,
	opt_txt_roof,
	opt_txt_roofe,
	opt_txt_rooff,
	opt_txt_special,
	opt_txt_speciale,
	opt_txt_specialf,
	opt_txt_street,
	opt_txt_streete,
	opt_txt_streetf,
	opt_txt_traine,
	opt_txt_trainf,
	opt_txt_train,
	opt_txt_buyin,
	NULL
};
#endif

char *opt_centered[]= 
{
	opt_txt_center,
	NULL
};

char *opt_control[]= 
{
	opt_txt_hp,
	opt_txt_lp,
	opt_txt_hk,
	opt_txt_lk,
	opt_txt_run,
	opt_txt_block,
	opt_txt_unass,
	NULL
};

char *opt_en_dis[]=
{
	opt_txt_enable,
	opt_txt_disable,
	NULL
};

char *opt_dis_en[]=
{
	opt_txt_disable,
	opt_txt_enable,
	NULL
};

char *opt_combo[]=
{
	opt_txt_off,
	opt_txt_on,
	opt_txt_auto,
	NULL
};

char *opt_off_on[]= 
{
	opt_txt_off,
	opt_txt_on,
	NULL
};

char *opt_on_off[]= 
{
	opt_txt_on,
	opt_txt_off,
	NULL
};

char *opt_diff[]= 
{
	opt_txt_veasy,
	opt_txt_easy,
	opt_txt_med,
	opt_txt_hard,
	opt_txt_vhard,
	NULL
};

WORD opt_hard_log[]={MASK_JHIP,MASK_JLOP,MASK_JHIK,MASK_JLOK,MASK_JRUN,MASK_JBLOCK,0x0000};

char *opt_pan[]= 
{
	opt_txt_off,
	opt_txt_lr,
	opt_txt_rl,
	NULL
};

OPTLIST game_opts[]=
{
	{OID_OPT_ID0,(WORD *)&cmos_diff,OPT_TOP_Y+30*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_diff,opt_diff,option_toggle,0},					// difficulty
	{OID_OPT_ID1,(WORD *)&f_no_blood,OPT_TOP_Y+30*1,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_blood,opt_on_off,option_toggle,0},			// blood
	{OID_OPT_ID2,(WORD *)&f_no_clock,OPT_TOP_Y+30*2,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_clock,opt_en_dis,option_toggle,0},					// difficulty
	{OID_OPT_ID3,(WORD *)&f_dummy,OPT_TOP_Y+30*3,160,160,NULL,opt_centered,option_center,0},							// exit
	{OID_OPT_ID4,NULL,OPT_TOP_Y+30*5,OPT_EXIT_X,OPT_EXIT_X,opt_txt_exit,NULL,option_exit,0}							// exit
};

OPTLIST cheat_opts2[]=
{
	{OID_OPT_ID0,(WORD *)&f_freeplay,OPT_TOP_Y+30*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_free,opt_off_on,option_toggle,0},	// violence
	{OID_OPT_ID1,(WORD *)&f_unlim_fatal,OPT_TOP_Y+30*1,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_fatal,opt_on_off,option_toggle,0},			// blood
	{OID_OPT_ID2,(WORD *)&f_colbox,OPT_TOP_Y+30*2,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_coll,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID3,(WORD *)&f_one_win,OPT_TOP_Y+30*3,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_1round,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID4,(WORD *)&df_nopower,OPT_TOP_Y+30*4,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_1hit,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID5,NULL,OPT_TOP_Y+30*5,OPT_EXIT_X,OPT_EXIT_X,opt_txt_exit,NULL,option_exit,0}							// exit
};		  

OPTLIST cheat_opts1[]=
{
	{OID_OPT_ID0,(WORD *)&f_opt_agress,OPT_TOP_Y+30*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_agress,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID2,(WORD *)&f_opt_combo1,OPT_TOP_Y+30*1,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_combo1,opt_combo,option_toggle,0},			// blood
	{OID_OPT_ID3,(WORD *)&f_opt_combo2,OPT_TOP_Y+30*2,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_combo2,opt_combo,option_toggle,0},			// blood
	{OID_OPT_ID5,NULL,OPT_TOP_Y+30*5,OPT_EXIT_X,OPT_EXIT_X,opt_txt_exit,NULL,option_exit,0}							// exit
};

OPTLIST cheat_opts3[]=
{
	{OID_OPT_ID1,(WORD *)&f_level_select,OPT_TOP_Y+24*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_level,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID2,(WORD *)&f_opt_throws,OPT_TOP_Y+24*1,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_throws,opt_en_dis,option_toggle,0},			// blood
	{OID_OPT_ID3,(WORD *)&f_opt_runs,OPT_TOP_Y+24*2,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_runs,opt_dis_en,option_toggle,0},			// blood
	{OID_OPT_ID4,(WORD *)&f_opt_bloody,OPT_TOP_Y+24*3,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_bloody,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID5,(WORD *)&f_oldsm,OPT_TOP_Y+24*4,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_osm,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID6,(WORD *)&f_kamel,OPT_TOP_Y+24*5,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_kamel,opt_off_on,option_toggle,0},			// blood
	{OID_OPT_ID7,NULL,OPT_TOP_Y+30*5,OPT_EXIT_X,OPT_EXIT_X,opt_txt_exit,NULL,option_exit,0}							// exit
};

#define cheat_opts4 cheat_opts3

void option_music_test(void);
WORD f_music_test;
void option_slider_sound(void);
OPTLIST sound_opts[]=
{
//	{OID_OPT_ID0,(WORD *)&f_stereo,OPT_TOP_Y+30*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_stereo,opt_off_on,option_toggle_sound,0},			// sound on/off
	{OID_OPT_ID1,(WORD *)&f_no_pan,OPT_TOP_Y+30*0,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_pan,opt_pan,option_toggle_sound,0},			// pan control on/off, l/r r/l
	{OID_OPT_ID2,(WORD *)&f_sfx_vol,OPT_TOP_Y+30*1,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_sound,NULL,option_slider_sound,0},		// sound fx on/off
	{OID_OPT_ID3,(WORD *)&f_music_vol,OPT_TOP_Y+30*2,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_music,NULL,option_slider_sound,0},		// music silent,quiet,rockin,kranked
#if SYS_DEBUG	
	{OID_OPT_ID4,(WORD *)&f_music_test,OPT_TOP_Y+30*3,OPT_TOP_X_L,OPT_TOP_X_C,opt_txt_musict,opt_music_list,option_music_test,0},		// music silent,quiet,rockin,kranked
#endif	
	{OID_OPT_ID5,NULL,OPT_TOP_Y+30*5,OPT_EXIT_X,OPT_EXIT_X,opt_txt_exit,NULL,option_exit,0}							// exit
};

OPTLIST control1_opts[]=
{
	{OID_OPT_ID0,(WORD *)&pad_tri[0],OPT_TOP_Y+18*0,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_YLEFT,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID1,(WORD *)&pad_square[0],OPT_TOP_Y+18*1,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_YDOWN,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID2,(WORD *)&pad_circle[0],OPT_TOP_Y+18*2,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_YUP,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID3,(WORD *)&pad_x[0],OPT_TOP_Y+18*3,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_YRIGHT,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID4,(WORD *)&pad_l2[0],OPT_TOP_Y+18*4,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_R,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID5,(WORD *)&pad_l1[0],OPT_TOP_Y+18*5,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_A,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID6,(WORD *)&pad_r2[0],OPT_TOP_Y+18*6,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_L,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID7,(WORD *)&pad_r1[0],OPT_TOP_Y+18*7,OPT_CC_X_L,OPT_CC_X1_C,OPT_BUT_B,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID8,NULL,OPT_TOP_Y+30*5,OPT_CC_X1_C,OPT_CC_X1_C,opt_txt_exit,NULL,option_exit,0}							// exit
};	 

OPTLIST control2_opts[]=
{
	{OID_OPT_ID9,(WORD *)&pad_tri[1],OPT_TOP_Y+18*0,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_YLEFT,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID10,(WORD *)&pad_square[1],OPT_TOP_Y+18*1,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_YDOWN,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID11,(WORD *)&pad_circle[1],OPT_TOP_Y+18*2,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_YUP,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID12,(WORD *)&pad_x[1],OPT_TOP_Y+18*3,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_YRIGHT,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID13,(WORD *)&pad_l2[1],OPT_TOP_Y+18*4,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_R,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID14,(WORD *)&pad_l1[1],OPT_TOP_Y+18*5,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_A,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID15,(WORD *)&pad_r2[1],OPT_TOP_Y+18*6,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_L,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID16,(WORD *)&pad_r1[1],OPT_TOP_Y+18*7,OPT_CC_X_L,OPT_CC_X2_C,OPT_BUT_B,opt_control,option_toggle,0},					// difficulty
	{OID_OPT_ID17,NULL,OPT_TOP_Y+30*5,OPT_CC_X2_C,OPT_CC_X2_C,opt_txt_exit,NULL,option_exit,0}							// exit
};	 

OPTLIST *opt_tables[]={game_opts,sound_opts,control1_opts,control2_opts,cheat_opts1,cheat_opts3,cheat_opts2,cheat_opts2};

void convert_text_to_opt(WORD id,WORD zval) 
{
	OBJECT *obj;

	obj=(OBJECT *)&objlst2;
	while ( obj->olink!=NULL )
	{
		obj=obj->olink;
		if ( obj->oid==OID_TEXT )
		{
			obj->oid=id;
			obj->ozval+=zval;
		}
	}
}

void option_select(WORD scrnindex)
{
#if 0
	load_bkgd=BKGD_MK3_COINOPT;
	init_background_module(nuoptcoin_module);
#endif	
	load_bkgd=BKGD_FIRED_MOD;
	init_background_module(firedark_module);
	multi_plane();

	/* print title and change title text */
	p15_centered(opt_screen_list[scrnindex],160,16);
	convert_text_to_opt(OID_OPTION,0);

	/* lets do it */
	f_novel=1;								// disable velocities
	opt_done=0;								// # of process using routine

	/* activate 2nd player controls */
	current_proc->pdata.p_store7=OPT_P1MASK;
	if (scrnindex==OPT_SCRN_CONTROLS)
	{
		CREATE(PID_OPTCONTROL,opt_p2control);
	}
	else
	{
		current_proc->pdata.p_store7|=OPT_P2MASK;
	}

	current_proc->a11=scrnindex;
	opt_proc();

	while ( opt_done!=0 )
		process_sleep(1);

	fadeout_jsrp(0x30);						// fade down

	return;
}

void opt_p2control(void)
{
	current_proc->a11=OPT_SCRN_CONTROLS2;
	current_proc->pdata.p_store7=OPT_P2MASK;
	opt_proc();
	process_suicide();
}

void opt_hilite(WORD id,WORD *pal) 
{
	OBJECT *obj;

	obj=(OBJECT *)&objlst2;
	while ( obj->olink!=NULL )
	{
		obj=obj->olink;
		if ( obj->oid==id ) 
		{
			delpal(obj);							// change back to original color
			obj->opal=get_fore_pal(pal);
		}
	}
	
}

/******************************************************************************
 Function: WORD init_option_table(OPTLIST *otbl)

 By: David Schwartz

 Date: April 1995

 Parameters:  otbl - ptr to a table of options

 Returns: # of options in table (includeing exit)

 Description:	setup a screen for options
	Option table must be terminated by using NULL in 'var' field
******************************************************************************/
WORD init_option_table(OPTLIST *otbl,WORD scrn)
{
	WORD index=0;
	OBJECT *obj;

	while (otbl->label_txt!=opt_txt_exit)
	{
		/* set choice index to current variable value */
		otbl->index=*(otbl->var);

		/* Create Label Object */
		if ((LONG)otbl->label_txt & 0x80000000)
		{
			/* text entry */
			p15_left(otbl->label_txt,otbl->xlabel,otbl->y);
			convert_text_to_opt(OID_OPTION,0);
		}
		else
		{
			if (otbl->label_txt!=NULL)
			{
				/* sprite entry */
				gso_dmawnz_ns_coor(obj,(ADDRESS)button_list[(LONG)otbl->label_txt-1],button_dict,0,0,otbl->xlabel,otbl->y);
				alloc_cache((OIMGTBL *)button_list[(LONG)otbl->label_txt-1],0,obj);
				obj->oid=OID_OPTION;
				insert_object(obj,&objlst);
			}
		}
		
		/* Create Choice Object */
		if ( otbl->choicetbl!=NULL )
		{
			if (scrn!=OPT_IKONTROL)
			{
				p15_centered_soff(*(otbl->choicetbl+otbl->index),otbl->xchoice,otbl->y);
				convert_text_to_opt(otbl->oid,0);
			}
			else
			{
				pds_centered_soff(*(otbl->choicetbl+otbl->index),otbl->xchoice,otbl->y);
				convert_text_to_opt(otbl->oid,0);
			}
		}

		otbl++;							// next entry
		index++;
	}

	/* setup exit object */
	p15_centered_soff(otbl->label_txt,otbl->xchoice,otbl->y);
	convert_text_to_opt(otbl->oid,0);

	return(index+1);
}

/******************************************************************************
 Function: void opt_proc(void)

 By: David Schwartz

 Date: April 1995

 Parameters:
				current_proc->pdata.p_store7 - joystick mask
								(OPT_P1MASK - player 1 joystick only)
								(OPT_P2MASK - player 2 joystick only)
 				current_proc->a11 = which option screen table to use
					0 = game configure
					1 = music configure
					2 = p1 control configure
					3 = p2 control configure
					4 = cheat screen

 Returns: None

 Description:	game selection options
******************************************************************************/
void opt_proc(void)
{
	OPTLIST *opt,*opt_table;
	WORD scrn;
	LONG ta11;
	PROCESS *pslider1;
	PROCESS *pslider2;
	
	ta11=current_proc->a11;

	opt=opt_table=opt_tables[current_proc->a11];
	
	if (current_proc->a11==OPT_SCRN_CONTROLS || current_proc->a11==OPT_SCRN_CONTROLS2)
		scrn=OPT_IKONTROL;

	/* setup all parameters, display and stuff for options */
	master_fade=0x10000;
	current_proc->a11=init_option_table(opt,scrn);			// max # of entries
	current_proc->pdata.p_store1=0;								// current entry pos
	current_proc->a10=0;													// debounce

	/* hilight palette of first choice */
	opt_hilite(opt->oid,YELLOW_p);
	
	/* slider checks */
	pslider1=NULL;
	pslider2=NULL;
	if (ta11==OPT_SCRN_MUSIC) 
	{
		pslider1=CREATE(OID_OPT_ID2,slider_proc);
		(short *)pslider1->pdata.p_store8=&f_sfx_vol;
		pslider1->pdata.p_store6=190;
		pslider1->pdata.p_store7=OPT_TOP_Y+30*1;
		pslider1->pdata.p_store5=OID_OPT_ID2;
		pslider1->a11=0;
	
		pslider2=CREATE(OID_OPT_ID3,slider_proc);
		(short *)pslider2->pdata.p_store8=&f_music_vol;
		pslider2->pdata.p_store6=190;
		pslider2->pdata.p_store7=OPT_TOP_Y+30*2;
		pslider2->pdata.p_store5=OID_OPT_ID3;
		pslider2->a11=0;
	}

	opt_done=1;
	current_proc->pdata.p_store6=1;
	while (current_proc->pdata.p_store6 && opt_done!=0)
	{
		process_sleep(1);

		if ( current_proc->a10!=0 )
		{
				current_proc->a10--;
		}

		/* check for cursor movement */
		if ((swcurr.padvalue & P1P2_UP & current_proc->pdata.p_store7) && current_proc->a10==0)
		{
			current_proc->a10=12;
			opt_hilite(opt->oid,WHITE_p);
			
			if (current_proc->pdata.p_store1==0)
				current_proc->pdata.p_store1=current_proc->a11-1;
			else current_proc->pdata.p_store1--;

			opt=opt_table+current_proc->pdata.p_store1;		// update opt ptr & object
			opt_hilite(opt->oid,YELLOW_p);

			tsound(0x0c);
		}
		else
		{
			if ((swcurr.padvalue & P1P2_DOWN & current_proc->pdata.p_store7) && current_proc->a10==0)
			{
				current_proc->a10=12;
				opt_hilite(opt->oid,WHITE_p);
				
				current_proc->pdata.p_store1++;

				if (current_proc->pdata.p_store1==current_proc->a11)
					current_proc->pdata.p_store1=0;

				opt=opt_table+current_proc->pdata.p_store1;		// update opt ptr & object
				opt_hilite(opt->oid,YELLOW_p);
			
				tsound(0x0c);
			}
		}

		current_proc->pdata.p_store4=(ADDRESS)opt_table;		// setup transfer vars
		current_proc->pdata.p_store5=(ADDRESS)opt;
		current_proc->pdata.p_store8=scrn;
		opt->toggle_func();
		(ADDRESS)opt_table=current_proc->pdata.p_store4;		// update transfer vars
		(ADDRESS)opt=current_proc->pdata.p_store5;
	}

	opt_done=0;

	/* unhilite object */
	opt_hilite(opt->oid,WHITE_p);

	/* kill sliders */
	if (pslider1!=NULL)
		pslider1->a11=SLIDER_DIE;

	if (pslider2!=NULL)
		pslider2->a11=SLIDER_DIE;
	return;
}

/******************************************************************************
 Function: void option_exit(void)

 By: David Schwartz

 Date: April 1995

 Parameters:  current_proc->pdata.p_store5 - current option table entry
							current_proc->pdata.p_store4 - base option table

 Returns: None

 Description:	see if its time to exit
******************************************************************************/
void option_exit(void)
{
	/* check for exit */
	if ((swcurr.padvalue & OPTION_EXIT & current_proc->pdata.p_store7))
		current_proc->pdata.p_store6=0;

	return;
}

/******************************************************************************
 Function: void option_center(void)

 By: David Schwartz

 Date: April 1995

 Parameters:  current_proc->pdata.p_store5 - current option table entry
							current_proc->pdata.p_store4 - base option table

 Returns: None

 Description:	see if its time to exit
******************************************************************************/
#define SCREEN_ADJ_Y	1
#define SCREEN_ADJ_X	1
#define SCREEN_ADJ_YMAX	16
#define SCREEN_ADJ_XMAX	16
#define SCREEN_DEBOUNCE	3
char txt_centered[]="USE THE CONTROL PAD TO\nCENTER SCREEN. PRESS ANY\nBUTTON WHEN FINISHED";

void option_center(void) 
{
	OBJECT *obj;
	int ta10;
	
	/* check for button activation */
	if (f_centered!=0) 
	{
		f_centered--;
		return;
	}
	
	if ((swcurr.padvalue & P1P2_ACTION)==0)
		return;
	
	f_centered=16;
	
	/* setup and display instructiuons */
	obj=make_solid_object(0x003f,280,56);
	obj->opal=get_fore_pal(WHITE_p);
	obj->oxpos.u.intpos=20+worldtlx.u.intpos;
	obj->oypos.u.intpos=110+worldtly.u.intpos;
//	obj->oflags|=M_XLU_ON;
	obj->oflags|=0xa000;			// set xlu value
	obj->oid=OID_OPT_ID16;
	obj->ozval=2;
	insert_object(obj,&objlst2);
	
	p15_centered_soff(txt_centered,160,115);
	convert_text_to_opt(OID_OPT_ID17,20);
	opt_hilite(OID_OPT_ID17,YELLOW_p);
	
	while (sort_list(&objlst2));
	
	/* pause for a moment of reflection */
	process_sleep(4);
	
	/* center screen routine */
	current_proc->a10=SCREEN_DEBOUNCE;
	do
	{
		process_sleep(1);

		if (current_proc->a10!=0)
			current_proc->a10--;

		ta10=current_proc->a10;

		/* check joy stick */
		if ((swcurr.padvalue & P1P2_UP) && current_proc->a10==0)
		{
			/* going up */
			ta10=SCREEN_DEBOUNCE;
			
			screen_adj_y-=SCREEN_ADJ_Y;
			
			if (screen_adj_y<-SCREEN_ADJ_YMAX)
				screen_adj_y=-SCREEN_ADJ_YMAX;
		}
		else
		{
			if ((swcurr.padvalue & P1P2_DOWN) && current_proc->a10==0)
			{
				/* going down */
				ta10=SCREEN_DEBOUNCE;
				screen_adj_y+=SCREEN_ADJ_Y;
			
				if (screen_adj_y>SCREEN_ADJ_YMAX)
					screen_adj_y=SCREEN_ADJ_YMAX;
			}
		}

		if ((swcurr.padvalue & P1P2_RIGHT) && current_proc->a10==0)
		{
			/* going right */
			ta10=SCREEN_DEBOUNCE;
			screen_adj_x+=SCREEN_ADJ_X;
			
			if (screen_adj_x>SCREEN_ADJ_XMAX)
				screen_adj_x=SCREEN_ADJ_XMAX;
		}
		else
		{
			if ((swcurr.padvalue & P1P2_LEFT) && current_proc->a10==0)
			{
				/* going left */
				ta10=4;
				screen_adj_x-=SCREEN_ADJ_X;
			
				if (screen_adj_x<-SCREEN_ADJ_XMAX)
					screen_adj_x=-SCREEN_ADJ_XMAX;
				
			}
		}

		current_proc->a10=ta10;
		
		if ((swcurr.padvalue & P1P2_ACTION)!=0 && current_proc->a10==0)
			break;
	}
	while(1);
	
	/* dealloc instructions */
	dallobj(OID_OPT_ID16);
	dallobj(OID_OPT_ID17);
	
	return;
}

/******************************************************************************
 Function: void option_toggle(void)

 By: David Schwartz

 Date: April 1995

 Parameters:  current_proc->pdata.p_store5 - current option table entry
							current_proc->pdata.p_store4 - base option table

 Returns: None

 Description:	std option toggle stuff, will toggle through a list based on joy input
******************************************************************************/
void option_toggle_sound(void)
{
	option_toggle();
	sound_driver_config();			// repeatedly set sound driver, a waste but no big deal
	return;
}

void option_slider_sound(void) 
{
	OPTLIST *opt,*opt_table;
	PROCESS *ptemp;

	opt_table=(OPTLIST *)current_proc->pdata.p_store4;
	opt=(OPTLIST *)current_proc->pdata.p_store5;

	/* check for option change */
	if ((swcurr.padvalue & P1P2_RIGHT & current_proc->pdata.p_store7) && current_proc->a10==0)
	{

		current_proc->a10=4;

		/* toggle forward in options */
		*opt->var+=1;
		if (*opt->var>SLIDER_MAX)
			*opt->var=SLIDER_MAX;
	}
	else
	{
		if ((swcurr.padvalue & P1P2_LEFT & current_proc->pdata.p_store7) && current_proc->a10==0)
		{
			current_proc->a10=4;

			/* toggle forward in options */
			if (*opt->var!=0)
				*opt->var-=1;
		}
	}
	
	ptemp=process_exist(opt->oid,0xffff);
	
	if (ptemp==NULL) 
	{
		printf(("Error: Slider does not exist %d\n",opt->oid));
		LOCKUP;
	}
	else ptemp->a11=SLIDER_HILITE;

	/* update vars to other routines will know about changes */
	current_proc->pdata.p_store4=(ADDRESS)opt_table;
	current_proc->pdata.p_store5=(ADDRESS)opt;

	sound_driver_config();			// repeatedly set sound driver, a waste but no big deal
}

void option_music_test(void) 
{
	OPTLIST *opt,*opt_table;
	
	option_toggle();
	
	opt_table=(OPTLIST *)current_proc->pdata.p_store4;
	opt=(OPTLIST *)current_proc->pdata.p_store5;
	
	if ((swcurr.padvalue & (P1B0|(P2B0<<16)) & current_proc->pdata.p_store7))
	{
		sound_music_start(opt->index+SOUND_FIRST_MUSIC_SEQ_NUM);
	}

	if ((swcurr.padvalue & (P1B1|(P2B1<<16)) & current_proc->pdata.p_store7))
	{
		sound_music_stop();
	}
	
	return;
}

void option_toggle(void)
{
	OPTLIST *opt,*opt_table;

	opt_table=(OPTLIST *)current_proc->pdata.p_store4;
	opt=(OPTLIST *)current_proc->pdata.p_store5;

	/* check for option change */
	if ((swcurr.padvalue & P1P2_RIGHT & current_proc->pdata.p_store7) && current_proc->a10==0 && opt->choicetbl!=NULL)
	{

		current_proc->a10=12;

		/* kill old text */
		kill_ocp(opt->oid,0xffff);
		
		/* toggle forward in options */
		opt->index++;								// next option
		if ((current_proc->a0=*((opt->choicetbl)+opt->index))==NULL)		// if at end reset to start
		{
			opt->index=0;
			current_proc->a0=*opt->choicetbl;
		}

		/* update graphics */
		if (current_proc->pdata.p_store8!=OPT_IKONTROL)
			p15_centered_soff(*(opt->choicetbl+opt->index),opt->xchoice,opt->y);
		else pds_centered_soff(*(opt->choicetbl+opt->index),opt->xchoice,opt->y);
		
		convert_text_to_opt(opt->oid,1);
		opt_hilite(opt->oid,YELLOW_p);

		/* update variable */
		if ( opt->var!=NULL )
			*opt->var=opt->index;

	}
	else
	{
		if ((swcurr.padvalue & P1P2_LEFT & current_proc->pdata.p_store7) && current_proc->a10==0 && opt->choicetbl!=NULL)
		{
			current_proc->a10=12;

			/* kill old text */
			kill_ocp(opt->oid,0xffff);
			
			/* toggle backward in options */
			if (opt->index==0)
			{
				while (*((opt->choicetbl)+opt->index)!=NULL)
					opt->index++;
			}

			opt->index--;

			current_proc->a0=*((opt->choicetbl)+opt->index);

			/* update graphics */
			if (current_proc->pdata.p_store8!=OPT_IKONTROL)
				p15_centered_soff(*(opt->choicetbl+opt->index),opt->xchoice,opt->y);
			else pds_centered_soff(*(opt->choicetbl+opt->index),opt->xchoice,opt->y);
			convert_text_to_opt(opt->oid,1);
			opt_hilite(opt->oid,YELLOW_p);
		
			/* update variable */
			if ( opt->var!=NULL )
				*opt->var=opt->index;
		}
	}

	/* update vars to other routines will know about changes */
	current_proc->pdata.p_store4=(ADDRESS)opt_table;
	current_proc->pdata.p_store5=(ADDRESS)opt;
}

/******************************************************************************
 Function: void opt_pad_setup(OPTMAP *omap, WORD *padmap)

 By: David Schwartz

 Date: April 1995

 Parameters: omap - init table
						 index - 0=p1 1=p2

 Returns: None

 Description: read the current logical joystick values and convert them to viewable
							indecies for the option remap routines

 pad?_map_table[X] -> logical hardware value -> display object index
******************************************************************************/
void opt_pad_setup(OPTMAP *omap, WORD *padmap)
{
	WORD log_hard_val;

	while ( omap->storage!=NULL )
	{
		/* retrieve currentl logical hardware value from remap table */
		log_hard_val=*(padmap+omap->b_index);

		/* assign storage, dispaly object index with correct index type */
		switch ( log_hard_val )
		{
			case MASK_JHIP:
				*(omap->storage)=OCL_HP;
				break;
			case MASK_JLOP:
				*(omap->storage)=OCL_LP;
				break;
			case MASK_JHIK:
				*(omap->storage)=OCL_HK;
				break;
			case MASK_JLOK:
				*(omap->storage)=OCL_LK;
				break;
			case MASK_JRUN:
				*(omap->storage)=OCL_RUN;
				break;
			case MASK_JBLOCK:
				*(omap->storage)=OCL_BLOCK;
				break;
			default:
				*(omap->storage)=OCL_OFF;
				break;
		}
		omap++;
	}

	return;
}

/******************************************************************************
 Function: void opt_pad_remap(OPTMAP *omap, WORD *padmap)

 By: David Schwartz

 Date: April 1995

 Parameters: omap - init table
						 index - 0=p1 1=p2

 Returns: None

 Description: converts readable index into logical hardware value and stores into remap table

 display object index -> logical hardware value -> pad?_map_table[X]
******************************************************************************/
void opt_pad_remap(OPTMAP *omap, WORD *padmap)
{
	WORD log_hard_val;

	while ( omap->storage!=NULL )
	{
		/* retrieve current display index */
		log_hard_val=opt_hard_log[*(omap->storage)];

		/* assign storage, dispaly object index with correct index type */
		*(padmap+omap->b_index)=log_hard_val;

		omap++;
	}

	return;
}

