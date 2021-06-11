/******************************************************************************
 File: mkamode.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III ATTRACT MODE ROUTINES
******************************************************************************/
#define DUMB_NINTENDO	1		// enable lame joystick messages

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkend.h"
#include "mkamode.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkmain.h"
#include "mktext.h"
#include "mkvs.h"
#include "mkfx.h"
#include "mkdiag.h"
#include "mkfade.h"
#include "mkrepell.h"
#include "mkscore.h"
#include "mksound.h"
#include "mkbio.h"
#include "mkinit.h"
#include "mkhstd.h"
#include "gamepad.h"
#include "mkdma.h"
#include "mkjoy.h"
#include "vcache.h"

/* local extern info */
extern void sony_graphics_setup(void);
extern void enter_initials(void);
void legal_page(void);
void mode_select(void);
extern short legal_displayed;
void do_story_intro(void);

extern FNTSETUP pf_15point[];
/******************************************************************************
 Function: void amode(void)

 By: David Schwartz

 Date: Aug 11, 1994

 Parameters: None

 Returns: None

 Description:	This is the main attract mode process
******************************************************************************/
WORD title_song=0;
void amode(void)
{
	int i,j;
	
	amode_init();
	gstate=GS_AMODE;
	
	/* amode_loop */
	do
	{
		title_song=0;
		
		/* load sound stuff */
		if (legal_displayed==0) 
		{
			midway_presents();
			legal_page();
			do_story_intro();
			title_page();
		}
		else
		{
			nosounds();
			sound_music_start(MUSIC_BUYIN);
			title_song=1;
			do_story_intro();
			title_page();
		}
		
#if 0
//		invaders_game_load();
	p1_state==PS_ACTIVE;
	gstate=GS_FIGHTING;
	mode_of_play=1;
	winner_status=1;
	p1_char=FT_JCAGE;
	select_yer_ending();
	winner_status=1;
	p1_char=FT_RAIN;
	select_yer_ending();
#endif	
		title_song=0;
		sound_music_start(MUSIC_FASTATTR);
		title_song=1;
		fast_edit_sequence(0);
		title_song=0;
		nosounds();
		tsound(0x29);
		
		print_rankings();
		nosounds();
		ultimate_bio(c_amode_bio);
		amode_demo_fight();
		
		print_rankings();
		ultimate_bio(c_amode_bio);
		amode_demo_fight();
	}
	while(1);

}
extern SCENERIO tbl_scenerio1[];
//extern SCENERIO tbl_scenerio2[];

void fast_edit_sequence(WORD editnum) 
{
	WORD stk_a0;
	
	f_start=0;		// dont start fighting
	
	p1_bar=p2_bar=FULL_STRENGTH;
	winner_status=0;
	
	stk_a0=f_nosound;
	f_nosound=1;
	send_code_a3(0);
	master_fade=0x10000;
	
	diff=9;
//	setup_scenerio((editnum==0)?tbl_scenerio1:tbl_scenerio2);
	setup_scenerio(tbl_scenerio1);
	
	f_nosound=stk_a0;
	
	return;
}

void setup_scenerio(SCENERIO *pa11) 
{
	do
	{
		murder_myoinit_score();
		
		send_code_a3(0);
		
		p1_char=pa11->s_p1;
		p2_char=pa11->s_p2;
		
		call_every_tick=NULL;

//		setup_score_ram();
//		update_win_counters();
//		update_knotches();
//		update_pmsg();
//		SHOW_SCORES;

		refresh_score();
		
		p1_bar=p2_bar=FULL_STRENGTH;
		p1_bar_view=p2_bar_view=FULL_STRENGTH;
		reset_aggressor();
		
		if (pa11->s_bkgd==-1)
			break;
			
		load_level=LVL_NONE;				// no data loaded at level_loadaddr
		load_bkgd=pa11->s_bkgd;
		init_background_module(table_o_mods[load_bkgd]);
		multi_plane();
		CREATE(PID_BACKG,background_routine);

		p1_char=pa11->s_p1;
		p2_char=pa11->s_p2;
		
		setup_players();
		refresh_score();
		
		p1_obj->oxpos.u.intpos=worldtlx.u.intpos+pa11->s_p1x;
		p2_obj->oxpos.u.intpos=worldtlx.u.intpos+pa11->s_p2x;
		
		if (pa11->s_p1func!=NULL)
			p1_proc->p_context.c_wakeup=pa11->s_p1func;
			
		if (pa11->s_p2func!=NULL)
			p2_proc->p_context.c_wakeup=pa11->s_p2func;
			
		CREATE(PID_REPELL,repell);
		CREATE(PID_SCROLL,scroller);
		start_shadows();
//		update_pmsg();
		
		if (pa11->s_sleep==0)
			break;
		
		process_sleep(pa11->s_sleep);

		freeze_2_pages();
		background_clear();
		
		pa11++;
	}
	while(1);
	
	return;
}

extern void *LOGO_FRAME[];
extern void *TOP_FRAME[];
OBJECT *draw_logo(void) 
{
	OBJECT *obj;
	
	/* load logo art sprite */
	special_fx_load(FX_LOGO_LOAD);
	spec_fx=FX_NO_LOAD;
	
	gso_dmawnz(obj,(ADDRESS)LOGO_FRAME,0,0,0);
	alloc_cache(LOGO_FRAME,0,obj);
	obj->oxpos.u.intpos=79-7;
	obj->oypos.u.intpos=18-5;
	set_noscroll(obj);
	obj->ozval=50;
	insert_object(obj,&objlst);
	
	return(obj);
}

/******************************************************************************
 Function: void midway_presents(void);

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	midway presents
******************************************************************************/
extern void *logo_module[];
extern void *nuoptions_module[];
void midway_presents(void)
{
	OBJECT *obj;
	
//	nosounds();
//	sound_music_start(MUSIC_FASTATTR);

	amode_init_no_score();
#if 0
	load_bkgd=BKGD_LOGO_MOD;
	init_background_module(logo_module);
	multi_plane();

	fadein_jsrp(0x40*4);
	smooth_black_retp();
#endif
	return;
}

/******************************************************************************
 Function: void legal_page(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	legal page
******************************************************************************/
extern int audio_init;
extern void *legal_module[];
extern char txt_legals[];
extern FNTSETUP pf_dave_smallc[];
extern FNTSETUP pf_dave_smallc_soff[];

#if DUMB_NINTENDO
extern int				gamepad_count;			// number of game controllers
char txt_dumb0[]=
	"THERE ARE NO CONTROLLERS\n ATTACHED TO\n"
	"THE NINTENDO 64.\n\nPOWER OFF THE NINTENDO 64 AND\n"
	"CONNECT 1 OR 2 CONTROLLERS.\n";
char txt_dumb1[]=
	"THERE IS ONLY 1 CONTROLLER\nATTACHED TO THE NINTENDO 64.\n"
	"\nIF YOU WOULD LIKE TO PLAY\n"
	"A 2-PLAYER GAME, POWER\nOFF THE NINTENDO 64 AND\n"
	"CONNECT A 2ND CONTROLLER\nOR\nPRESS START TO CONTINUE.\n";
char txt_import[]="IMPORTANT:";

void dumb_joy(void) 
{
	if (gamepad_count==0) 
	{
		murder_myoinit();
		DISPLAY_ON;
		dlists=dlists_bogus;
		tsound(0x71);
		p15_centered(txt_import,160,24);
		lm_setup(pf_dave_smallc_soff);
		fnt_state.fnt_posx=160;
		fnt_state.fnt_posy=52;
		fnt_state.fnt_spacing=0xffff;
		mk_printf(txt_dumb0);
		wait_forever();
	}
	
	if (gamepad_count==1) 
	{
		murder_myoinit();
		DISPLAY_ON;
		dlists=dlists_bogus;
		tsound(0x71);
		p15_centered(txt_import,160,24);
		lm_setup(pf_dave_smallc_soff);
		fnt_state.fnt_posx=160;
		fnt_state.fnt_posy=52;
		fnt_state.fnt_spacing=0xffff;
		mk_printf(txt_dumb1);
		while ((swcurr.u.p1pad & MASK_START)==0 && (swcurr.u.p2pad & MASK_START)==0)
			process_sleep(1);
	}
	
	process_sleep(4);
	
	return;
}
#endif

void legal_page(void)
{
	OBJECT *obj;

	/* legal_page */
	object_initialize();
//	load_bkgd=BKGD_MK3_LEGAL;
//	init_background_module(legal_module);
//	multi_plane();
	
	/* draw logo sprite */
//	obj=draw_logo();
	dlists=dlists_bogus;

#if TEXT_QUE	
	text_draw=1;
#endif
	
	lm_setup(pf_dave_smallc_soff);
	fnt_state.fnt_posx=160;
	fnt_state.fnt_posy=24;
	fnt_state.fnt_spacing=0xffff;
	mk_printf(txt_legals);

#if TEXT_QUE	
	text_draw=0;
#endif
	
	process_sleep(4);
	init_audio_part2();
	sound_reset();
	sound_driver_config();
	nosounds();
	process_sleep(2);
	audio_init=1;
	
#if DUMB_NINTENDO
	object_initialize();
	dumb_joy();
#endif
	
	legal_displayed=1;
	sound_music_start(MUSIC_BUYIN);
	title_song=1;
	
	murder_myoinit();

	return;
}

/******************************************************************************
 Function: void title_page(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	title page
******************************************************************************/
extern void *title_module[];
void title_page(void)
{	
	OBJECT *obj;

	object_initialize();

	load_bkgd=BKGD_MK3_TITLE;
	init_background_module(title_module);
	multi_plane();

	tsound(0x29);
	fadein_jsrp(0x40*5);
//	process_sleep(0x40*5);

	smooth_black_retp();

	return;
}

extern char txt_story[];
void do_story_intro(void) 
{
	OBJECT *ta3;
	WORD ta0;

	murder_myoinit_score();
	do_background(BKGD_LAIR_MOD);
	worldtlx.u.intpos+=64;

	scroll_paragraph(txt_story);
	process_sleep(0x40*3);
	murder_myoinit_score();
	return;
}

/******************************************************************************
 Function: void amode_demo_fight(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	show a small demo of what we got
******************************************************************************/
WORD c_demo_fight=0;
WORD amode_demo_matchups[]=
{
	FT_RAYDEN,FT_SCORPION,
	FT_JADE,FT_REPTILE,
	FT_KITANA,FT_KANO,
	FT_RAIN,FT_SONYA,
	FT_BARAKA,FT_JAX,
	FT_OLDSZ,FT_INDIAN,
	FT_MILEENA,FT_JCAGE,		
	FT_NOOB,FT_SWAT,
	FT_TUSK,FT_LIA,
	FT_SONYA,FT_BARAKA,
	FT_JCAGE,FT_RAYDEN,
	FT_ERMAC,FT_LAO,
	FT_SCORPION,FT_INDIAN,
	FT_REPTILE,FT_SG,
	FT_RAIN,FT_ST,
	FT_JADE,FT_LK,
	FT_JCAGE,FT_NOOB,
	FT_MILEENA,FT_ERMAC,
	FT_NOOB,FT_OLDSMOKE
};

void amode_demo_fight(void)
{
	WORD t_a0;

	amode_init_no_score();

//	t_a0=(randu(18)-1)<<1;
	t_a0=c_demo_fight<<1;
	if (++c_demo_fight>=18)
		c_demo_fight=0;
		
	p1_char=amode_demo_matchups[t_a0];
	p2_char=amode_demo_matchups[t_a0+1];

	curback=randu(MAX_BACKGROUNDS)-1;
	ochar_force_curback();

	if ( !f_no_vs )
		vs_or_ladder();
	CREATE(PID_AMODE,amode_demo_game);
	process_sleep(6);
	CREATE(PID_REPELL,repell);

	process_sleep(0x40*12);

	MURDER;
	/* freeze_2_pages modified fixes wierd bugs */
	f_novel=1;
	scrolly.pos=0;
	p1_heap_char=p2_heap_char=0xffff;
	stop_scrolling();
	send_code_a3(0);
	play_ending_chord();
	process_sleep(0x30);

	amode_fade_retp();

	return;
}

/******************************************************************************
 Function: void amode_init(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	Initialize game for attact mode
******************************************************************************/
void amode_init(void)
{
	WORD loop;

	mode_of_play=0;

	current_proc->pdata.p_hit=4;
	c_amodeloop=0;

	/* ainit4 */
	current_proc->procid=PID_AMODE;

	current_proc->pdata.p_action=randu(7)-1;

	update_pmsg();

	coinflag=0;

	/* setup ram for hidden codes */
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
	return;
}

/******************************************************************************
 Function: void amode_shutup(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	attact mode be quiet
******************************************************************************/
#if 0
void amode_shutup(void)
{
	nosounds();
	f_nosound=1;
	current_proc->pdata.p_hit=0;
	return;
}
#endif

/******************************************************************************
 Function: void amode_init_no_score(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	attact mode setup and dont show score board
******************************************************************************/
void amode_init_no_score(void)
{
	amode_oinit();
	DONT_SHOW_SCORES;
}

/******************************************************************************
 Function: void amode_oinit(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	attact mode setup
******************************************************************************/
void amode_oinit(void)
{
	murder_myoinit_score();

	dlists=dlists_bogus;

	irqskye=0;
	noflip=0;
	f_doscore=1;
	return;
}

/******************************************************************************
 Function: void amode_init_system(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	attact system setuyp
******************************************************************************/
void amode_init_system(void)
{
	murder_myoinit_score();

	irqskye=0;
	noflip=0;
	f_auto_erase=1;
	DONT_SHOW_SCORES;
	nosounds();
	clr_scrn();
	process_sleep(2);
	return;
}

/******************************************************************************
 Function: void gover_amode_entry(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	game over attract mode entry point,
******************************************************************************/
void gover_amode_entry(void)
{
	PROCESS *ptemp;

	ptemp=CREATE(PID_FADE,skydown);
	(long)(ptemp->pa9)=0x800;
	amode_fade_retp();

	amode_init();
	gstate=GS_AMODE;

	stack_jump(amode);
}

/******************************************************************************
 Function: void amode_fade_retp(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	attact mode fade and return to caller
******************************************************************************/
void amode_fade_retp(void)
{
	fadeout_jsrp(0x20);
	smooth_black_retp();
}

/******************************************************************************
 Function: void smooth_black_retp(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	smooth black fade transition
******************************************************************************/
void smooth_black_retp(void)
{
	amode_display_reset();

	process_sleep(0x6);

	return;
}

/******************************************************************************
 Function: void amode_display_reset(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	attact mode display reset routine
******************************************************************************/
void amode_display_reset(void)
{
	clr_scrn();
 	murder_myoinit();
	f_doscore=0;					// score bars = no
	f_auto_erase=1;

	return;
}

