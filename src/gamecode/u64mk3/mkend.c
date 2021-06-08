/******************************************************************************
 File: mkend.c

 Date: Jan 1995

 (C) Williams Entertainment

 Mortal Kombat III Ending Stuff Routines
******************************************************************************/

#define DAVID_END 0

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkfx.h"
#include "mkfade.h"
#include "mkbkgd.h"							
#include "mkutil.h"
#include "mkani.h"
#include "mkgame.h"
#include "mkjoy.h"
#include "mkguys.h"
#include "mkinit.h"
#include "mkend.h"
#include "mkamode.h"
#include "mkmain.h"
#include "mkbio.h"
#include "mkpal.h"
#include "mktext.h"
#include "mkbuyin.h"
#include "mksound.h"
#include "mkbkgd.h"
#include "mkbonus.h"
#include "mkladder.h"
#include "mkboss.h"
#include "mkcanned.h"
#include "mkdma.h"
#include "mkvs.h"
#include "mkdma.h"
#include "vcache.h"
#include "mkfatal.h"
#include "mkanimal.h"
#include "mkfriend.h"
#include "mkstat.h"

extern void *dlists_bogus[];
extern void *symbol_table[];
extern void *BOX2[];

extern void amode_dizzy(void);
extern void do_brutality(void);

/******************************************************************************
 Function: void shao_kahn_death_fx(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	ultimate death seq
******************************************************************************/
#if 0
void falling_body(void) 
{
	OBJECT *obj=current_proc->pa8;
	WORD ta11=current_proc->a11;

	/* setup random position */
	obj->oxpos.u.intpos=worldtlx.u.intpos+32+randu(320-64);
	obj->oypos.u.intpos=worldtly.u.intpos-96;
	obj->ozval=999;
	
	obj->oyvel.pos=SCY(0x8000)*(ta11>>2);
	obj->ograv.pos=SCY(0x8000);
	
	death_scream;
	
	/* change to knockdown frame later */
	get_char_ani(ANIM_TABLE1,ANIM_KDOWN);
	find_last_frame();
	do_next_a9_frame(obj);
	
	set_ignore_y(obj);
	
	obj->oflags|=M_XLU_ON;
	obj->oflags|=0xff00;
	/* fall to the earth */
	current_proc->pdata.p_ganiy=ground_y-obj->osize.u.ypos-64;
	do
	{
		obj->oyvel.pos+=obj->ograv.pos;
		process_sleep(1);
		obj->oflags-=0x0400;
	}
	while(obj->oypos.u.intpos<current_proc->pdata.p_ganiy);

	stop_me(obj);
	
	/* hit ground so explode */
	tsound(0x81);
	create_fx(FX_INVISO_POOF_NS);
	process_sleep(3);
	set_inviso(obj);
	
	/* release object so another can use it */
	remove_bucket(obj->ochar);
	delobjp(obj);

	/* death */
	process_suicide();
}
#endif

void arcing_body(void) 
{
	OBJECT *obj=current_proc->pa8;
	WORD ta11=current_proc->a11;

	/* setup random position */
	obj->oxpos.u.intpos=worldtlx.u.intpos+SCRRGT/2;
	obj->oypos.u.intpos=worldtly.u.intpos+50;
	obj->ozval=0;
	
	obj->oxvel.pos=randu_minimum(SCX(0x20000),SCX(0x18000));
	if (randper(500)==SYSTEM_CARRY_SET)
		obj->oxvel.pos*=-1;
		
	obj->oyvel.pos=-SCY(0xc8000);
	obj->ograv.pos=randu_minimum(SCY(0xb000),SCY(0x5000));
	
	death_scream;
	
	/* change to knockdown frame later */
	get_char_ani(ANIM_TABLE1,ANIM_KDOWN);
	find_last_frame();
	do_next_a9_frame(obj);
	
	if (obj->oxvel.pos>0)
		flip_multi(obj);
	
	set_ignore_y(obj);
	
	obj->oflags|=M_XLU_ON;
	obj->oflags|=0xff00;

	/* arc to the ground */
	current_proc->pdata.p_ganiy=ground_y-obj->osize.u.ypos-64;
	
	do
	{
		obj->oyvel.pos+=obj->ograv.pos;
		process_sleep(1);
		obj->oflags-=0x0400;
	}
	while(obj->oypos.u.intpos<current_proc->pdata.p_ganiy);

	stop_me(obj);
	
	/* hit ground so explode */
	if (ta11 & 1)
		tsound(0x81);
	obj->oypos.u.intpos=ground_y-88-44;	
	create_fx(FX_INVISO_POOF_NS);
	process_sleep(3);
	set_inviso(obj);
	
	/* release object so another can use it */
	remove_bucket(obj->ochar);
	delobjp(obj);

	/* death */
	process_suicide();
}

WORD fall_table[]=
{
	19990,
	20020,
	20050,
	20070,
	20096,
	20122,
	20151,
	20175,
	20200,
	20212,
	20238,
	20262,
	20286,
	20309,
	20335,
	20356,
	20377,
	20396,
	20411,
	20425,
	20438,
	20452,
	20466,
	20480,
	20514,
	20527,
	20541,
	20555,
	20571,
	20592,
	20605,
	20619,
	20636,
	20645,
	20655,
	20670,
	20690,
	20710,
	20715,
	20730,
	20745,
	20760,
	20773,
	20786,
	20799,
	20812,
	20825,
	20837,
	20850,
	20860,
	20870,
	20880,
	20890,
	20900,
	20908,
	0xffff
};

void spawn_falling_bodies(void) 				 
{
	WORD *ta11=fall_table;
	WORD pchar;
	OBJECT *obj;
	PROCESS *ptemp;
	int i=0;
	
	clear_buckets();
	bucket_mode=1;
	
	while (*(ta11+1)!=0xffff)
	{
		/* select a character */
		pchar=randu(FT_CHARS_PLAY)-1;
//		pchar=FT_SWAT;
	
		while ((obj=make_ochar_psel_guy(pchar,0))==NULL)
		{
			process_sleep(1);
		}

		/* create falling process */
		ptemp=CREATE(PID_FX,arcing_body);
		ptemp->a11=i++;
		ptemp->pa8=obj;
		
		current_proc->pa8=obj=NULL;
		
		/* wait until time for next */
		process_sleep(*(ta11+1)-(*ta11));
		ta11++;
		
#if 0		
		process_sleep(15);
		while ((swcurr.u.p1pad & MASK_JBLOCK)!=MASK_JBLOCK)
		{
			process_sleep(1);
		}
		printf(("TICK BODY FALL=%d\n",tick));
#endif		
	}
	
	process_suicide();
}

void shao_kahn_death_fx(void)
{
	ADDRESS ta1,ta2,ta3,ta4,ta5,ta6,ta7;
	WORD winchar;
	p1_obj->oid|=0x8000;
	p2_obj->oid|=0x8000;

	kill_ocp(0,0x8000);				// kill all object except players

	if (p1_char==FT_SK)				// protect kahn process
	{
		p1_proc->procid|=0x8000;
		MURDER;
		p1_proc->procid&=0x7fff;
		fastxfer(p1_proc,wait_forever);		// disable sk proc
		winchar=p2_char;
	}
	else
	{
		p2_proc->procid|=0x8000;
		MURDER;
		p2_proc->procid&=0x7fff;
		fastxfer(p2_proc,wait_forever);		// disable sk proc
		winchar=p1_char;
	}
	scrolly.pos=0;
	stop_scrolling();					// stop screen
	stop_me(p1_obj);
	stop_me(p2_obj);

	swpal(bpal_black_P,p1_obj);				// both players --> black
	swpal(bpal_black_P,p2_obj);

	stop_scrolling();
	ta1=(ADDRESS)baklst1;
	ta2=(ADDRESS)baklst2;
	ta3=(ADDRESS)baklst3;
	ta4=(ADDRESS)baklst4;
	ta5=(ADDRESS)baklst5;
	ta6=(ADDRESS)baklst6;
	ta7=(ADDRESS)baklst7;

	baklst1=NULL;
	baklst2=NULL;
	baklst3=NULL;
	baklst4=NULL;
	baklst5=NULL;
	baklst6=NULL;
	baklst7=NULL;

	DONT_SHOW_SCORES;
	
	/* psycho flash !!! */
	current_proc->a10=7;
	do
	{
		tsound(0x7f);
		kahn_flash(0,bpal_white_P);
		kahn_flash(0xffff,bpal_black_P);
	}
	while(--current_proc->a10>0);

	if (p1_char==FT_SK)
	{
		current_proc->pa8=p1_obj;
		current_proc->a11=(ADDRESS)p1_proc;
		current_proc->a0=(ADDRESS)p2_obj;
	}
	else
	{
		current_proc->pa8=p2_obj;
		current_proc->a11=(ADDRESS)p2_proc;
		current_proc->a0=(ADDRESS)p1_obj;
	}

	/* skdie5, fade from white to normal */
	set_inviso((OBJECT *)current_proc->a0);		// make winner disappear
	dealloc_vram_mem(((OBJECT *)current_proc->a0)->ovcache);		// remove art from cache so no uncompress problems
	((OBJECT *)current_proc->a0)->ovcache=VCACHE_FAILED;
	
	nosounds();
	process_sleep(1);
	tsound(0);
	tsound(1);						// ka boom
	set_inviso(current_proc->pa8);	// all white = dont show sk
	process_sleep(4);

	baklst1=(OBJECT *)ta1;
	baklst2=(OBJECT *)ta2;
	baklst3=(OBJECT *)ta3;
	baklst4=(OBJECT *)ta4;
	baklst5=(OBJECT *)ta5;
	baklst6=(OBJECT *)ta6;
	baklst7=(OBJECT *)ta7;

	fastxfer((PROCESS*)current_proc->a11,shao_kahn_dying);
	shake_a11(0x3,0x40);

	fadein_white_jsrp();

	tsound(0x87);
	tsound(0x88);
	process_sleep(0x30);
	
	murder_myoinit_score();
	do_background(BKGD_PIT_MOD);
	CREATE(PID_FX,shao_kahn_dying2);
	shake_a11(0x3,0x40);
	process_sleep(0x40);
	
	tsound(0x87);
	tsound(0x88);

	sk_die_pit(0x30,0x6,0x40);

	tsound(0x87);
	tsound(0x88);

	CREATE(PID_FX,spawn_falling_bodies);
	
	sk_die_pit(0x10,0x8,0x40);

	current_proc->pdata.p_anirate=6;
	/* fastsk3 */
	do
	{
		sk_die_pit(0x30*3,0x8,0x30);
		tsound(0x87);
		tsound(0x88);
		
	}
	while(--current_proc->pdata.p_anirate>0);

	murder_myoinit_score();
	nosounds();
	do_background(BKGD_HADES_MOD);

	current_proc->a11=3;
	/* last_flash */
	do
	{
		tsound(0x00);
		tsound(0x01);
		white_flash();
		process_sleep(8);
	}
	while(--current_proc->a11>0);
			  
	irqskye=0xffff;			//0x0fff;
	process_sleep(3);

	fadein_white_jsrp();
	process_sleep(0x50);

	sound_music_start(MUSIC_YOUWINTU);
	
	p1_char=p2_char=winchar;					// set to correct winner
	victory_message();

	sound_music_start(MUSIC_GREEN);
	murder_myoinit_score();
	clr_scrn();
	process_sleep(8);

	end_of_tournament();
}

void sk_die_pit(WORD pa10,WORD pa11h,WORD pa11l)
{
	shake_a11(pa11h,pa11l);
	process_sleep(pa10);
	return;
}

void shao_kahn_dying(void)
{
	sk_die_setup();

	current_proc->pdata.p_flags|=PM_ALT_PAL;
	player_normpal();
	ground_player(current_proc->pa8);

	get_char_ani(ANIM_TABLE1,ANIM_SK_DIE);
	animate_a0_frames(0x5,0x7);

	find_ani_part2(ANIM_SK_DIE);
	mframew(5);
	wait_forever();
}

extern void *a_sk_die_cycle[];
extern void *sk_pieces[];

short sk_offset_table[]= 
{
	158-2,16,
	0,144,
	180,165,
	202,9,
	48,4,
	0,97,
	222,125,
};

void shao_kahn_dying2(void)
{
	OBJECT *obj;
	OBJECT *opiece;
	short *stbl;
	ADDRESS animframe;
	
	/* load in data */
	special_fx_load(FX_SKDIE_LOAD);
	
	/* setup character display */
	current_proc->pa9=a_sk_die_cycle;
	gmo_proc(0,0);
	obj=current_proc->pa8;
	dealloc_vram_mem(obj->ovcache);
	obj->ochar=FT_SK;
	ground_ochar();
	current_proc->pdata.p_flags|=PM_ALT_PAL;
	player_normpal();
	current_proc->procid=PID_P1;
	current_proc->pdata.p_ganiy=obj->oypos.u.intpos;
	obj->ozval=10;
	insert_object(obj,&objlst);
	
	
	/* point to correct death anim */
	dallprc(PID_P1);
	dallprc(PID_P2);
	
	sk_die_setup();
	
	/* display the death */
	current_proc->pa9=a_sk_die_cycle;
	do_next_a9_frame(current_proc->pa8);
	do_next_a9_frame(current_proc->pa8);
	
	/* setup pieces */
	current_proc->pa9=sk_pieces;
	stbl=sk_offset_table;
	while (GET_LONG(current_proc->pa9)!=0)
	{
		animframe=GET_LONG(current_proc->pa9)++;
		gso_dmawnz(opiece,(ADDRESS)animframe,0,0,0);
		alloc_cache((OIMGTBL *)animframe,0,opiece);
		opiece->ozval=obj->ozval;
		opiece->oxpos.u.intpos=obj->oxpos.u.intpos+(*stbl)-158;
		stbl++;
		opiece->oypos.u.intpos=obj->oypos.u.intpos+(*stbl)-99+10;
		stbl++;
		insert_object(opiece,&objlst);
	}
	current_proc->pa8=obj;
	
	/* display the death */
	current_proc->pa9=a_sk_die_cycle;
	do_next_a9_frame(current_proc->pa8);
	do_next_a9_frame(current_proc->pa8);
	
	mframew(8);
	wait_forever();
}

void sk_die_setup(void)
{
	clear_inviso(current_proc->pa8);
	(current_proc->pa8)->oxpos.u.intpos=SCRRGT/2+worldtlx.u.intpos;
	return;
}

void kahn_flash(WORD pa0,void *pa1)
{
	irqskye=pa0;
	swpal(pa1,p1_obj);
	swpal(pa1,p2_obj);
	process_sleep(4);
	return;
}

//***************************************************************************
//***************************************************************************

extern BYTE *ochar_endings1[];
extern FNTSETUP pf_bio[];
void do_normal_ending(void) 
{
	OBJECT *ta3;
	WORD ta0;

	ta0=get_winner_ochar();
	sound_music_start(MUSIC_GREEN);

	murder_myoinit_score();
	do_background(BKGD_FIRE_MOD);

	slide_in_left(ta0);

	ta3=objlst;
	do
	{
		ta3->oxvel.pos=0;
		ta3=ta3->olink;
	}
	while(ta3!=NULL);

	move_object_list(&objlst,&baklst3);
	process_sleep(2);

	scroll_paragraph(ochar_endings1[get_winner_ochar()]);
	process_sleep(0x40*3);
	select_retp();
	return;
}


#define PAUSE			-3
#define PAUSE_STOP		-2
#define END_OF_MESSAGE	-1

void scroll_paragraph(BYTE *ta11) 
{
	signed char ta0;
	
	CREATE(PID_FX,text_deleter);
	current_proc->pdata.p_store8=(ADDRESS)obj_free;
	
	/* scp2 */
	do
	{
		pds_centered_soff(ta11,SCX(0xd0),SCY(0xff));
		set_letter_vel();
		process_sleep(0x1a-7);
		
		/* scp3 */
		do
		{
			ta11++;
		}
		while(*ta11!=0);
		
		ta11++;
		
SCP4:
		ta0=*ta11;
		
		if (ta0==-2) 
		{
			current_proc->pa8=(OBJECT *)current_proc->pdata.p_store8;
			/* scp7 */
			do
			{
				process_sleep(1);
			}
			while((current_proc->pa8)->oypos.u.intpos>SCY(0x14));
			
			f_novel=1;
			process_sleep(0x40*5);
			ta11++;
			f_novel=0;
			current_proc->pdata.p_store8=(ADDRESS)obj_free;
			goto SCP4;
		}
		
		/* scp5 */
		if (ta0==-3) 
		{
			ta11++;
			ta0=*ta11++;
			process_sleep(((WORD)ta0) & 0x00ff);
			goto SCP4;
		}
		
		/* scp6 */
		if (ta0==-1)
			break;
	}
	while(1);
	
	return;
}

void eot_done(void)
{
	reset_map_variables();		// rev1.1
	gstate=GS_GAMEOVER;					// game state = bonus
	
	//mk3_cast_o_characters();
	//mk3_design_team(arcade_team_table);
	//mk3_design_team(sony_team_table);
	mk3_thank_you();

	stack_jump(game_over);
}

void select_retp(void) 
{
	murder_myoinit_score();
	stack_jump(eot_done);
}

#define SYMBOL_Y	SCY(0x5b)

void badge_spinner(void);
void make_six_symbols(short pa7,WORD pa10,WORD pa11,short ypos);
void new_symbol_flasher(WORD pa11);
void lineup_badge_with_symbol(WORD pa0);
void kill_symbol_flasher(void);
void do_random_prize(void); 
void do_space_game(void); 
void do_pong_game(void); 
void do_mega_endurance(void); 
void do_fight_osz_osm(void); 
void do_fight_noob_ermac(void); 
void do_fight_match(void); 
void do_fight_noob(void); 
void do_fight_ermac(void); 
void do_fight(WORD pa0);
void intro_screen(char *pa10,char *pa8,short pa9x,short pa9y,WORD pa11);
void set_mapstart_n_position(WORD *pa0,WORD pa1); 
void make_box_holder(void);
OBJECT *get_a0_symbol(WORD pa0);
void symbol_flasher(void);
void sk_flash_sleep(short pa0);

extern char txt_pick1[];
extern char txt_hidden_intro[];
extern void *ochar_order_mugs[];
extern void *MKCOIN_01[];


WORD map_mega_endurance[]={FT_ENDUR2,0};
WORD map_noob_ermac[]={FT_ENDUR0,0};
WORD map_osz_osm[]={FT_ENDUR1,0};
WORD map_mninja[]={FT_ENDUR17,0};
WORD map_fninja[]={FT_ENDUR18,0};
WORD map_rd_sa_cage[]={FT_ENDUR19,0};

WORD ladder_maximums[]={4,10,16,22,22};
WORD ladder_maximums_endur[]={6,12,18,23,23};

void do_normal_ending(void);		
void do_space_game(void);			
void do_fight_ermac(void);			
void do_fight_kamel(void);			
void do_fight_noob(void);			
void do_fight_mninja(void); 
void do_fight_fninja(void); 
void do_fight_rd_sa_cage(void); 
void do_random_prize(void);			
void do_fatality_tour_1(void);		
void do_fatality_tour_2(void);		
void do_fatality_tour_3(void);		
void do_brutality_tour(WORD pa0,WORD pa1);
void do_brutality_tour_1(void);		
void do_brutality_tour_2(void);		
void do_brutality_tour_3(void);		
void do_brutality_tour_4(void);		
void do_fight_noob_ermac(void);		
void do_fight_osz_osm(void);		
void do_mega_endurance(void);		
void do_all_fatals(void);
void do_clue_giveaway(void);
void do_space_invade(void);


JUMPTBL sk_treasure_jumptbl[]=
{
	do_normal_ending,		// 0
	do_space_game,			// 1
	do_fight_ermac,			// 2
	do_fight_noob,			// 3
	do_random_prize,		// 4
	do_fatality_tour_1,		// 5
	do_brutality_tour_2,	// 6
	do_fatality_tour_7,		// 7
	do_fight_noob_ermac,	// 8 
	do_fight_osz_osm,		// 9
	do_mega_endurance,		// 10
	do_fight_rd_sa_cage,	// 11
	
	do_pong_game,			// 12
	do_fight_mninja,		// 13
	do_animality_tour_1,	// 14
	do_brutality_tour_1,	// 15
	do_friend_tour_1,		// 16
	do_fight_kamel,			// 17
	do_fatality_tour_4,		// 18
	do_animality_tour_2,	// 19
	do_fight_fninja,		// 20
	do_all_fatals,			// 21
	do_space_invade,		// 22
	do_clue_giveaway,		// 23
};

char txt_clues[]="YOUR REWARD IS SECRETS\nFROM THE OUTLAND\n";
char txt_demo_all[]="SUPREME DEMONSTRATION";
char txt_yr_demo_all[]=" ";
char txt_brutdemo1[]="BRUTALITY DEMONSTRATION ONE";
char txt_brutdemo2[]="BRUTALITY DEMONSTRATION TWO";
char txt_brutdemo3[]="BRUTALITY DEMONSTRATION THREE";
char txt_brutdemo4[]="BRUTALITY DEMONSTRATION FOUR";
char txt_fatdemo1[]="FATALITY DEMONSTRATION ONE";
char txt_fatdemo2[]="FATALITY DEMONSTRATION TWO";
char txt_fatdemo3[]="FATALITY DEMONSTRATION THREE";
char txt_fatdemo4[]="FATALITY DEMONSTRATION FOUR";
char txt_fatdemo5[]="FATALITY DEMONSTRATION FIVE";
char txt_fatdemo6[]="FATALITY DEMONSTRATION SIX";
char txt_fatdemo7[]="FATALITY DEMONSTRATION SEVEN";
char txt_anidemo1[]="ANIMALITY DEMONSTRATION ONE";
char txt_anidemo2[]="ANIMALITY DEMONSTRATION TWO";
char txt_anidemo3[]="ANIMALITY DEMONSTRATION THREE";
char txt_babdemo1[]="BABALITY DEMONSTRATION ONE";
char txt_fredemo1[]="FRIENDSHIP DEMONSTRATION ONE";
char txt_yr_brutal[]="WITNESS THE BARBARISM\nWITHIN ALL WARRIORS.";
char txt_yr_fatal[]="YOUR REWARD IS THE OPPORTUNITY\nTO WITNESS THE MANY WAYS TO\nDEFEAT YOUR OPPONENTS.";
char txt_yr_animal[]="YOUR REWARD IS THE OPPORTUNITY\nTO WITNESS THE INNER ANIMAL\nALL WARRIORS POSSES.";
char txt_yr_baby[]="YOUR REWARD IS THE OPPORTUNITY\nTO WITNESS THE CHILD\nIN ALL OF US.";
char txt_yr_friend[]="WITNESS THE KIND\nSPIRIT WITHIN ALL WARRIORS.";
char txt_hidden_intro[]="YOUR REWARD IS THE OPPORTUNITY\nTO FACE ONE OF SHAO KAHN'S\nDEADLIEST WARRIORS.";
char txt_normal_ending[]="TOURNAMENT OUTCOME";
char txt_space_game[]="RELLIM OHCANEP";
char txt_pong_game[]="PAST HISTORY";
char txt_fight_ermac[]="BATTLE WITH ERMAC";
char txt_fight_old_school[]="OLD SCHOOL KOMBAT";
char txt_fight_noob[]="BATTLE WITH NOOB SAIBOT";
char txt_fight_mninja[]="MALE NINJA KOMBAT";
char txt_fight_fninja[]="FEMALE NINJA KOMBAT";
char txt_fight_kamel[]="BATTLE WITH KAMELEON";
char txt_fight_noob_ermac[]="NOOB SAIBOT / ERMAC ENDURANCE";
char txt_fight_osz_osm[]="MK2 CLASSIC ENDURANCE KOMBAT";
char txt_mega_endurance[]="MEGA ENDURANCE KOMBAT";
char txt_random_prize[]="RANDOM PRIZE";
char txt_space_invade[]="INVADERS FROM SPACE";
char txt_clue_giveaway[]="SECRETS OF TRILOGY";

extern void *vs_module[];

char *prize_text_table[]=
{
	txt_normal_ending,		// 0
	txt_space_game,			// 1
	txt_fight_ermac,		// 2
	txt_fight_noob,			// 3
	txt_random_prize,	    // 4
	txt_fatdemo1,			// 5
	txt_brutdemo2,			// 6
	txt_fatdemo7,			// 7
	txt_fight_noob_ermac,	// 8 
	txt_fight_osz_osm,		// 9
	txt_mega_endurance,		// 10
	txt_fight_old_school,	// 11
	
	txt_pong_game,			// 12
	txt_fight_mninja,		// 13
	txt_anidemo1,			// 14
	txt_brutdemo1,			// 15
	txt_fredemo1,			// 16
	txt_fight_kamel,		// 17
	txt_fatdemo4,			// 18
	txt_anidemo2,			// 19
	txt_fight_fninja,		// 20
	txt_demo_all,			// 21
	txt_space_invade,	    // 22
	txt_clue_giveaway,	    // 23
};

extern BYTE sdragon_dict[];
extern BYTE symbol_dict[];
extern WORD map_endur[];
void select_yer_ending(void) 
{
	OBJECT *ta9,*obj;
	ADDRESS animframe;
	WORD t9;
	PROCESS *pholder;

	current_proc->procid=PID_MASTER;

	if (mode_of_play==2) 
	{
		/* winner_ochar_tournament */
		if (winner_status==1) 
		{
			p1_state=PS_ACTIVE;
			p2_state=0;
		}
		else
		{
			p2_state=PS_ACTIVE;
			p1_state=0;
		}
	}

	/* winner_ochar_?_on_? */
	murder_myoinit();
	irqskye=0;
	DISPLAY_OFF;
	process_sleep(4);

	/* load mugshot data */
	special_fx_load(FX_MUGS_LOAD);
	spec_fx=FX_NO_LOAD;

	/* setup screen */
	load_bkgd=BKGD_VS_MOD;
	init_background_module(vs_module);
	multi_plane();
	dlists=dlists_bogus;

	/* shao kahn treasures */
	pds_centered(txt_pick1,SCX(0xc7),SCY(0xd0));

	/* draw winning mug shot */
	animframe=(ADDRESS)ochar_order_mugs[(p1_state==PS_ACTIVE)?p1_char:p2_char];
	gso_dmawnz(obj,animframe,0,0,0);
	alloc_cache((OIMGTBL*)animframe,0,obj);
	set_xy_coordinates(obj,SCX(0xb0),SCY(0x10));
	obj->ozval=1;
	insert_object(obj,&objlst);
	ta9=obj;

	/* draw border box */
	obj=make_solid_object(0xf801,34+6,45+6);
	obj->ozval=0;
	obj->oxpos.u.intpos=ta9->oxpos.u.intpos-3;
	obj->oypos.u.intpos=ta9->oypos.u.intpos-3;
	insert_object(obj,&objlst);

	process_sleep(1);
	DISPLAY_ON;

	CREATE(PID_FX,mk_bat_signal);
	CREATE(PID_FX,mk_bat_signal_f);
	
	make_box_holder();
	(current_proc->pa8)->oxpos.u.intpos=(SCRRGT/2)-(current_proc->pa8)->osize.u.xpos+1;
	make_box_holder();
	(current_proc->pa8)->oxpos.u.intpos=SCRRGT/2-1;
	
	make_box_holder();
	(current_proc->pa8)->oxpos.u.intpos=(SCRRGT/2)-(current_proc->pa8)->osize.u.xpos+1;
	(current_proc->pa8)->oypos.u.intpos+=64;
	make_box_holder();
	(current_proc->pa8)->oxpos.u.intpos=SCRRGT/2-1;
	(current_proc->pa8)->oypos.u.intpos+=64;
	
#if 0	
	make_box_holder();
	(current_proc->pa8)->oxpos.u.intpos=(SCRRGT/2)-((current_proc->pa8)->osize.u.xpos/2);
	(current_proc->pa8)->oypos.u.intpos+=64;
#endif		
	/* make 12 symbols */
//	current_proc->pa9=&(current_proc->pdata);
	pholder=CREATE(PID_BLOOD,NULL);
	pholder->ptime=999999;
	current_proc->pdata.p_dronevar1=(ADDRESS)pholder;
	current_proc->pa9=&(pholder->p_context.c_stack);
	
	make_six_symbols(SCX(0x36)-SCX(0x18)*0+2,6,0,0);
	make_six_symbols(SCX(0x36)+SCX(0x18)*6+4,12,6,0);
	make_six_symbols(SCX(0x36)-SCX(0x18)*0+2,18,12,64);
	make_six_symbols(SCX(0x36)+SCX(0x18)*6+4,24,18,64);
#if 0	
	make_six_symbols(SCX(0x36)+19*3+4,18,12,64);
#endif
	/* spinning badge */
	gso_dmawnz_ns_coor(obj,(ADDRESS)MKCOIN_01,sdragon_dict,0,0,SCX(0x0153),(0x0010)+3);
	alloc_cache(MKCOIN_01,0,obj);
	lineup_badge_with_symbol(0);
	insert_object(obj,&objlst);
	CREATE(PID_BANI,badge_spinner);		// a8=text/a9=coin
	
	current_proc->a11=0;
	new_symbol_flasher(0);

	/* switch scan */
#if SYS_DEBUG	
	t9=23;
#else
	t9=(mode_of_play==2) ? 16:(ladder_base==map_endur)?ladder_maximums_endur[ladder]:ladder_maximums[ladder];
#endif	
	/* pend0 */
	do
	{
		current_proc->a10=10;
PEND2:
		pholder->ptime=999999;
		do
		{
			process_sleep(1);
			if (current_proc->a10==0)
				break;
		}
		while(--current_proc->a10);

		/* pend1 */
		current_proc->a0=(p1_state==PS_ACTIVE)?swcurr.u.p1pad:swcurr.u.p2pad;

		if (current_proc->a0 & MASK_JRIGHT) 
		{
			if (current_proc->a11>=t9)
				current_proc->a11=0;
			else current_proc->a11++;
		}
		else
		{
			/* pend5 */
			if (current_proc->a0 & MASK_JLEFT) 
			{
				if (current_proc->a11==0)
					current_proc->a11=t9;
				else current_proc->a11--;
			}
			else
			{
				/* pend6 */
				if (current_proc->a0 & P1_BUTTON_MASK) 
				{
					tsound(0x6f);
					shake_a11(0x8,8);
					kill_symbol_flasher();

					pds_centered(prize_text_table[current_proc->a11],SCX(0xc7),SCY(0xc0));
					process_sleep(0x40);
					MURDER;

					stack_jump(sk_treasure_jumptbl[current_proc->a11]);
					return;
				}
				else
				{
					goto PEND2;
				}
			}
		}

		/* pend9 */
		lineup_badge_with_symbol(current_proc->a11);
		kill_symbol_flasher();
		new_symbol_flasher(current_proc->a11);
		tsound(0xc);
	}
	while(1);

	return;	
}

JUMPTBL random_prize[]=
{
	do_mega_endurance,		// 0
	do_pong_game,			// 1
	do_fight_rd_sa_cage,	// 2
	do_fight_kamel,			// 3
	do_brutality_tour_3,	// 4
	do_baby_tour_1,			// 5
	do_animality_tour_3,	// 6
	do_brutality_tour_4,	// 7
	do_fatality_tour_3,		// 8
	do_fight_fninja,		// 9
	do_fatality_tour_6,		// 10
	do_fatality_tour_5,		// 11
};							

void do_random_prize(void) 
{
	murder_myoinit_score();
	stack_jump(random_prize[randu(12)-1]);		
}

void fatl3(SCENERIO *pa0,char *pa1,char *pa2) 
{
	murder_myoinit_score();
	p1_button=p2_button=bt_null;
	intro_screen(pa1,pa2,SCX(0xc8),SCY(0x30),BKGD_FIRE_MOD);

	f_fatal_demo=1;
	setup_scenerio(pa0);
	f_fatal_demo=0;
	select_retp();
}

void do_space_game(void) 
{
	process_sleep(0x40*2);
	hidden_game_load();
	select_retp();
}

void do_pong_game(void) 
{
	process_sleep(0x40*2);
	pong_game_load();
	select_retp();
}

void do_space_invade(void) 
{
	process_sleep(0x40*2);
	invaders_game_load((p1_state==PS_ACTIVE)?0:1,1);
	select_retp();
}


void invade_clue_system(WORD numclues,WORD maxclue);
void do_clue_giveaway(void) 
{
	murder_myoinit_score();
	p1_button=p2_button=bt_null;
	intro_screen(txt_clues,NULL,SCX(0xc8),SCY(0x30),BKGD_FIRE_MOD);
	
	loadoverlay(SYS_MARK_OVL);
	invade_clue_system(5,23);
	
	select_retp();
}

void be_a_baby(void) 
{
	stance_setup();
	current_proc->a10=0x20;
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--current_proc->a10>0);
	
	stack_jump(turn_into_a_baby);
}

SCENERIO fatal1_tour1[]=
{
	{BKGD_CAVE_MOD,FT_KANO,FT_SONYA,SCX(0x60),SCX(0x120),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_BRIDGE_MOD,FT_SONYA,FT_REPTILE,SCX(0x60),SCX(0x120),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_GRAVE_MOD,FT_JAX,FT_KANO,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_CITY_MOD,FT_INDIAN,FT_ST,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_CAVE_MOD,FT_JCAGE,FT_SG,SCX(0x60),SCX(0xa0),do_fatality_1,amode_dizzy,0x40*4},
	{BKGD_BRIDGE_MOD,FT_SWAT,FT_SCORPION,SCX(0x30),SCX(0x130),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_GRAVE_MOD,FT_LIA,FT_LAO,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_CITY_MOD,FT_ROBO1,FT_JADE,SCX(0x60),SCX(0xf0),do_fatality_1,amode_dizzy,0x40*4},
	{-1}
};

SCENERIO fatal1_tour2[]=
{
	{BKGD_STREET_MOD,FT_ROBO2,FT_REPTILE,SCX(0xc0),SCX(0x100),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_SOUL_MOD,FT_LAO,FT_TUSK,SCX(0x50),SCX(0x140),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_TOMB_MOD,FT_TUSK,FT_SWAT,SCX(0x80),SCX(0x130),do_fatality_1,amode_dizzy,0x40*6},
	{BKGD_GRAVE_MOD,FT_SG,FT_LIA,SCX(0x50),SCX(0xa0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_STREET_MOD,FT_ST,FT_SONYA,SCX(0xc0),SCX(0x100),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_SOUL_MOD,FT_LK,FT_ST,SCX(0xc0),SCX(0x100),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_TOMB_MOD,FT_SMOKE,FT_SCORPION,SCX(0x30),SCX(0x130),do_fatality_1,amode_dizzy,0x40*8},
	{-1}
};

SCENERIO fatal1_tour3[]=
{
	{BKGD_KUNGFU5BOT_MOD,FT_KITANA,FT_SCORPION,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*4},
	{BKGD_BATTLE_MOD,FT_JADE,FT_TUSK,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*7},
	{BKGD_CITY_MOD,FT_MILEENA,FT_SWAT,SCX(0x50),SCX(0x140),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_ARMORY_MOD,FT_SCORPION,FT_INDIAN,SCX(0x40),SCX(0xd0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_SKTOWER_MOD,FT_REPTILE,FT_SWAT,SCX(0x50),SCX(0x130),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_LAIR_MOD,FT_ERMAC,FT_JAX,SCX(0x80),SCX(0xe0),do_fatality_1,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO fatal1_tour4[]=
{
	{BKGD_KUNGFU5_MOD,FT_OLDSZ,FT_KITANA,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*4},
	{BKGD_BATTLE_MOD,FT_OLDSMOKE,FT_JADE,SCX(0x50),SCX(0x140),do_fatality_1,amode_dizzy,0x40*9},
	{BKGD_CITY_MOD,FT_RAYDEN,FT_MILEENA,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*4},
	{BKGD_ARMORY_MOD,FT_BARAKA,FT_SCORPION,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_NOOB,FT_JAX,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{BKGD_LOST_MOD,FT_RAIN,FT_JAX,SCX(0x60),SCX(0xb0),do_fatality_1,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO fatal2_tour4[]=
{
	{BKGD_TEMPLE_MOD,FT_KANO,FT_SONYA,SCX(0x60),SCX(0xa0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_TOWER_MOD,FT_SONYA,FT_REPTILE,SCX(0x60),SCX(0x120),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_BELL_MOD,FT_JAX,FT_KANO,SCX(0x20),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_SUBWAY_MOD,FT_INDIAN,FT_ST,SCX(0x40),SCX(0x100),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_JCAGE,FT_SG,SCX(0x40),SCX(0x120),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_BELL_MOD,FT_SWAT,FT_SCORPION,SCX(0x30),SCX(0x80),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_TOWER_MOD,FT_LIA,FT_LAO,SCX(0x60),SCX(0xc0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_SUBWAY_MOD,FT_ROBO1,FT_JADE,SCX(0x60),SCX(0x130),do_fatality_2,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO fatal2_tour5[]=
{
	{BKGD_WATER_MOD,FT_ROBO2,FT_REPTILE,SCX(0xc0),SCX(0x100),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_GRAVE_MOD,FT_LAO,FT_TUSK,SCX(0x50),SCX(0xa0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_DESERT_MOD,FT_TUSK,FT_SWAT,SCX(0x80),SCX(0xe0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_MONK_MOD,FT_SG,FT_LIA,SCX(0x50),SCX(0xa0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_WATER_MOD,FT_ST,FT_SONYA,SCX(0xc0),SCX(0x100),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_GRAVE_MOD,FT_LK,FT_ST,SCX(0xc0),SCX(0x100),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_DESERT_MOD,FT_SMOKE,FT_SCORPION,SCX(0x30),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO fatal2_tour6[]=
{
	{BKGD_LIAR_MOD,FT_KITANA,FT_SCORPION,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*6},
	{BKGD_TOMB_MOD,FT_JADE,FT_TUSK,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*4},
	{BKGD_MK2PIT_MOD,FT_MILEENA,FT_SWAT,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_LOST_MOD,FT_SCORPION,FT_INDIAN,SCX(0x60),SCX(0x110),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_DESERT_MOD,FT_REPTILE,FT_SWAT,SCX(0x50),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_CAVE_MOD,FT_ERMAC,FT_JAX,SCX(0x80),SCX(0xc0),do_fatality_2,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO fatal2_tour7[]=
{
	{BKGD_SKTOWER_MOD,FT_OLDSZ,FT_KITANA,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*4},
	{BKGD_STREET_MOD,FT_OLDSMOKE,FT_JADE,SCX(0x30),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_HIDDEN_MOD,FT_RAYDEN,FT_MILEENA,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*4},
	{BKGD_ARMORY_MOD,FT_BARAKA,FT_SCORPION,SCX(0x60),SCX(0xb0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_SUBWAY_MOD,FT_NOOB,FT_SWAT,SCX(0x40),SCX(0xe0),do_fatality_2,amode_dizzy,0x40*5},
	{BKGD_CITY_MOD,FT_RAIN,FT_SONYA,SCX(0x40),SCX(0xe0),do_fatality_2,amode_dizzy,0x40*5},
	{-1}
};

SCENERIO animal1_tour1[]=
{
	{BKGD_TEMPLE_MOD,FT_KANO,FT_SONYA,SCX(0xa0),SCX(0xe0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_SONYA,FT_REPTILE,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_JAX,FT_KANO,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_INDIAN,FT_ST,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_JCAGE,FT_SG,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_SWAT,FT_SCORPION,SCX(0x60),SCX(0xd0),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_LIA,FT_LAO,SCX(0xb0),SCX(0x100),do_animality,amode_dizzy,0x40*5},
	{BKGD_TEMPLE_MOD,FT_ROBO1,FT_JADE,SCX(0x60),SCX(0xf0),do_animality,amode_dizzy,0x40*5},
	{-1}
};


SCENERIO animal1_tour2[]=
{
	{BKGD_HADES_MOD,FT_ROBO2,FT_REPTILE,SCX(0xc0),SCX(0x100),do_animality,amode_dizzy,0x40*5},
	{BKGD_HADES_MOD,FT_LAO,FT_TUSK,SCX(0x70),SCX(0xc0),do_animality,amode_dizzy,0x40*5},
	{BKGD_HADES_MOD,FT_TUSK,FT_SWAT,SCX(0xa0),SCX(0x120),do_animality,amode_dizzy,0x40*4},
	{BKGD_HADES_MOD,FT_SG,FT_LIA,SCX(0x50),SCX(0xa0),do_animality,amode_dizzy,0x40*5},
	{BKGD_HADES_MOD,FT_ST,FT_SONYA,SCX(0xc0),SCX(0x130),do_animality,amode_dizzy,0x40*5},
	{BKGD_HADES_MOD,FT_LK,FT_ST,SCX(0xc0),SCX(0x128),do_animality,amode_dizzy,0x40*5},
	{BKGD_HADES_MOD,FT_SMOKE,FT_SCORPION,SCX(0x30),SCX(0x130),do_animality,amode_dizzy,0x40*4},
	{BKGD_HADES_MOD,FT_KITANA,FT_SCORPION,SCX(0xe0),SCX(0x130),do_animality,amode_dizzy,0x40*6},
	{-1}
};

SCENERIO animal1_tour3[]=
{
	{BKGD_KUNGFU2_MOD,FT_JADE,FT_TUSK,SCX(0x60),SCX(0xc0),do_animality,amode_dizzy,0x40*7},
	{BKGD_KUNGFU2_MOD,FT_MILEENA,FT_SWAT,SCX(0x80),SCX(0xe0),do_animality,amode_dizzy,0x40*7},
	{BKGD_KUNGFU2_MOD,FT_SCORPION,FT_INDIAN,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_REPTILE,FT_SWAT,SCX(0xa0),SCX(0xf0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_ERMAC,FT_MILEENA,SCX(0xa0),SCX(0xf0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_OLDSZ,FT_ERMAC,SCX(0x70),SCX(0xc0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_OLDSMOKE,FT_KITANA,SCX(0x40),SCX(0xe0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_RAYDEN,FT_JADE,SCX(0x40),SCX(0xe0),do_animality,amode_dizzy,0x40*4},
	{BKGD_KUNGFU2_MOD,FT_BARAKA,FT_LK,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*7},
	{BKGD_KUNGFU2_MOD,FT_RAIN,FT_LIA,SCX(0x60),SCX(0xb0),do_animality,amode_dizzy,0x40*5},
	{BKGD_KUNGFU2_MOD,FT_NOOB,FT_LAO,SCX(0x30),SCX(0xf0),do_animality,amode_dizzy,0x40*5},
	{-1}
};


SCENERIO baby_tour1[]=
{
	{BKGD_CAVE_MOD,FT_KANO,FT_SONYA,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_JAX,FT_INDIAN,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_OLDSZ,FT_SWAT,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_LIA,FT_ROBO1,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_ROBO2,FT_LAO,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_TUSK,FT_SG,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_ST,FT_LK,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_SMOKE,FT_KITANA,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_JADE,FT_MILEENA,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_SCORPION,FT_REPTILE,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_ERMAC,FT_RAIN,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_OLDSMOKE,FT_NOOB,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_RAYDEN,FT_BARAKA,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{BKGD_CAVE_MOD,FT_JCAGE,FT_LAO,SCX(0x60),SCX(0x120),be_a_baby,be_a_baby,0x40*2},
	{-1}
};


SCENERIO friend1_tour1[]=
{
	{BKGD_SOUL_MOD,FT_KANO,FT_SONYA,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_SOUL_MOD,FT_JAX,FT_INDIAN,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_SOUL_MOD,FT_JCAGE,FT_SWAT,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_BATTLE_MOD,FT_LIA,FT_ROBO1,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_BATTLE_MOD,FT_ROBO2,FT_LAO,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_BATTLE_MOD,FT_TUSK,FT_SG,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_CAVE_MOD,FT_ST,FT_LK,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_CAVE_MOD,FT_SMOKE,FT_KITANA,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_CAVE_MOD,FT_JADE,FT_MILEENA,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_GRAVE_MOD,FT_SCORPION,FT_REPTILE,SCX(0x60),SCX(0xb0),do_friendship,amode_dizzy,0x40*4},
	{BKGD_GRAVE_MOD,FT_REPTILE,FT_SCORPION,SCX(0x60),SCX(0xb0),do_friendship,amode_dizzy,0x40*4},
	{BKGD_GRAVE_MOD,FT_OLDSZ,FT_RAIN,SCX(0x60),SCX(0xb0),do_friendship,amode_dizzy,0x40*4},
	{BKGD_CAVE_MOD,FT_ERMAC,FT_KANO,SCX(0x60),SCX(0xf0),do_friendship,amode_dizzy,0x40*6},
	{BKGD_MONK_MOD,FT_RAYDEN,FT_BARAKA,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_MONK_MOD,FT_OLDSMOKE,FT_RAIN,SCX(0x60),SCX(0x120),do_friendship,do_friendship,0x40*4},
	{BKGD_MONK_MOD,FT_NOOB,FT_JCAGE,SCX(0x30),SCX(0x130),do_friendship,amode_dizzy,0x40*6},
	{-1}
};

void do_brutality_tour_1(void) 
{
	murder_myoinit_score();
	intro_screen(txt_brutdemo1,txt_yr_brutal,SCX(0xc8),SCY(0x50),BKGD_FIRE_MOD);
	do_brutality_tour(FT_KANO,FT_ROBO1);
	stack_jump(eot_done);
}

void do_brutality_tour_2(void) 
{
	murder_myoinit_score();
	intro_screen(txt_brutdemo2,txt_yr_brutal,SCX(0xc8),SCY(0x50),BKGD_FIRE_MOD);
	do_brutality_tour(FT_ROBO2,FT_SMOKE);
	stack_jump(eot_done);
}

void do_brutality_tour_3(void) 
{
	murder_myoinit_score();
	intro_screen(txt_brutdemo3,txt_yr_brutal,SCX(0xc8),SCY(0x50),BKGD_FIRE_MOD);
	do_brutality_tour(FT_KITANA,FT_OLDSZ);
	stack_jump(eot_done);
}

void do_brutality_tour_4(void) 
{
	murder_myoinit_score();
	intro_screen(txt_brutdemo4,txt_yr_brutal,SCX(0xc8),SCY(0x50),BKGD_FIRE_MOD);
	do_brutality_tour(FT_OLDSMOKE,FT_RAIN);
	stack_jump(eot_done);
}

void do_fatality_tour_1(void) 
{
	fatl3(fatal1_tour1,txt_fatdemo1,txt_yr_fatal);
}

void do_fatality_tour_2(void) 
{
	fatl3(fatal1_tour2,txt_fatdemo2,txt_yr_fatal);
}

void do_fatality_tour_3(void) 
{
	fatl3(fatal1_tour3,txt_fatdemo3,txt_yr_fatal);
}

void do_fatality_tour_4(void) 
{
	fatl3(fatal2_tour4,txt_fatdemo4,txt_yr_fatal);
}

void do_fatality_tour_5(void) 
{
	fatl3(fatal2_tour5,txt_fatdemo5,txt_yr_fatal);
}

void do_fatality_tour_6(void) 
{
	fatl3(fatal2_tour6,txt_fatdemo6,txt_yr_fatal);
}

void do_fatality_tour_7(void) 
{
	fatl3(fatal2_tour7,txt_fatdemo7,txt_yr_fatal);
}

void do_animality_tour_1(void) 
{
	fatl3(animal1_tour1,txt_anidemo1,txt_yr_animal);
}

void do_animality_tour_2(void) 
{
	fatl3(animal1_tour2,txt_anidemo2,txt_yr_animal);
}

void do_animality_tour_3(void) 
{
	fatl3(animal1_tour3,txt_anidemo3,txt_yr_animal);
}

void do_baby_tour_1(void) 
{
	fatl3(baby_tour1,txt_babdemo1,txt_yr_baby);
}

void do_friend_tour_1(void) 
{
	fatl3(friend1_tour1,txt_fredemo1,txt_yr_friend);
}


SCENERIO brutal_cheat[]=
{
	{BKGD_CITY_MOD,FT_RAIN,FT_JAX,SCX(0x60),SCX(0xa0),do_brutality,amode_dizzy,0x40*5},
	{-1}
};

void do_brutality_tour(WORD pa0,WORD pa1) 
{
	int i;
	int cback=randu(MAX_BACKGROUNDS)-1;
	int pchar=randu(FT_CHARS_PLAY)-1+(pa1-pa0)/2;
	
	if (pchar>(FT_CHARS_PLAY-1))
		pchar=pchar-(FT_CHARS_PLAY-1);
	
	for (i=pa0;i<=pa1;i++)
	{
		brutal_cheat[0].s_bkgd=cback;
		brutal_cheat[0].s_p1=i;
		brutal_cheat[0].s_p2=pchar;
		setup_scenerio(brutal_cheat);
		
		if (++cback>=MAX_BACKGROUNDS)
			cback=0;

		if (++pchar>=FT_CHARS_PLAY)
			pchar=0;
	}
}

void do_all_fatals(void) 
{
	murder_myoinit_score();
	intro_screen(txt_demo_all,txt_yr_demo_all,SCX(0xc8),SCY(0x30),BKGD_FIRE_MOD);
	
	
	setup_scenerio(fatal1_tour1);
	setup_scenerio(fatal1_tour2);
	setup_scenerio(fatal1_tour3);
	setup_scenerio(fatal1_tour4);
	
	setup_scenerio(fatal2_tour4);
	setup_scenerio(fatal2_tour5);
	setup_scenerio(fatal2_tour6);
	setup_scenerio(fatal2_tour7);
	
	do_brutality_tour(0,FT_CHARS_PLAY-1);
	
	setup_scenerio(animal1_tour1);
	setup_scenerio(animal1_tour2);
	setup_scenerio(animal1_tour3);
	setup_scenerio(friend1_tour1);
	setup_scenerio(baby_tour1);
	
	stack_jump(eot_done);
}

void do_mega_endurance(void) 
{
	set_mapstart_n_position(map_mega_endurance,0);
	set_drone_ochar();
	diff=6;
	do_fight_match();
}

void do_fight_osz_osm(void) 
{
	set_mapstart_n_position(map_osz_osm,0);
	set_drone_ochar();
	diff=9;
	do_fight_match();
}

void do_fight_mninja(void) 
{
	set_mapstart_n_position(map_mninja,0);
	set_drone_ochar();
	diff=5;
	do_fight_match();
}

void do_fight_fninja(void) 
{
	set_mapstart_n_position(map_fninja,0);
	set_drone_ochar();
	diff=5;
	do_fight_match();
}

void do_fight_rd_sa_cage(void) 
{
	set_mapstart_n_position(map_rd_sa_cage,0);
	set_drone_ochar();
	diff=6;
	do_fight_match();
}

void do_fight_noob_ermac(void) 
{
	set_mapstart_n_position(map_noob_ermac,0);
	set_drone_ochar();
	diff=9;
	do_fight_match();
}

WORD f_error=0;

void do_fight_match(void) 
{
	WORD results;

	round_init();
	round_num=p1_matchw=p2_matchw=0;

	p1_heap_char=p2_heap_char=0xffff;
	f_special_match=1;
	curback=randu(MAX_BACKGROUNDS-1);
	play_1_match();
	f_special_match=0;

	/* special_match_retp */
	select_retp();
}

void do_fight_noob(void) 
{
	do_fight(FT_NOOB);
}

void do_fight_kamel(void) 
{
	do_fight(FT_KAMEL);
}

void do_fight_ermac(void) 
{
	do_fight(FT_ERMAC);
}

void do_fight(WORD pa0) 
{
	/* hidden_fighter_intro */
	murder_myoinit_score();
	intro_screen(txt_hidden_intro,NULL,SCX(0xc8),SCY(0x50),BKGD_FIRE_MOD);

	if (p1_state==PS_ACTIVE)
		p2_char=pa0;
	else p1_char=pa0;
	diff=9;
	
	do_fight_match();
}

void intro_screen(char *pa10,char *pa8,short pa9x,short pa9y,WORD pa11) 
{
	do_background(pa11);

	if (pa8!=NULL) 
	{
		pds_centered(pa8,pa9x,pa9y);
		pa9y=SCY(0x20)+fnt_state.fnt_posy;
	}

	/* int3 */
	pds_centered(pa10,pa9x,pa9y);
 	send_code_a3(TS_MAP_ZOOM);		
	process_sleep(0x40*3);
	fast_fadeout_jsrp(0x20);
	murder_myoinit_score();
	return;
}

void set_mapstart_n_position(WORD *pa0,WORD pa1) 
{
	map_start=pa0;
	map_position=pa1;
	return;
}

void make_six_symbols(short pa7,WORD pa10,WORD pa11,short ypos) 
{
	OBJECT *obj;
	ADDRESS animframe;

	do
	{
		animframe=(ADDRESS)COMPUTE_ADDR(0,symbol_table[pa11]);
		gso_dmawnz_ns(obj,animframe,symbol_dict,0,0);
		alloc_cache((OIMGTBL *)animframe,0,obj);
		obj->oypos.u.intpos=SYMBOL_Y+ypos;
		
		obj->oxpos.u.intpos=pa7;
		pa7+=19;
		obj->ozval=10;
		insert_object(obj,&objlst);
		*((ADDRESS**)current_proc->pa9)=(ADDRESS *)obj;
		((ADDRESS *)current_proc->pa9)++;
		pa11++;
	}
	while(pa11<pa10);
	return;
} 

void new_symbol_flasher(WORD pa11) 
{
	PROCESS *ptemp;

	ptemp=CREATE(PID_SFLASH,symbol_flasher);
	ptemp->pa8=get_a0_symbol(pa11);
	ptemp->a11=pa11;
	return;
} 

void lineup_badge_with_symbol(WORD pa0) 
{
	OBJECT *obj;

	obj=get_a0_symbol(pa0);
	lineup_1pwm(current_proc->pa8,obj);
	(current_proc->pa8)->oxpos.u.intpos-=SCX(0xa);
	(current_proc->pa8)->oypos.u.intpos=SCY(0x7a)-1;
	return;
}

extern BYTE vs_dict[];
void make_box_holder(void) 
{
	OBJECT *obj;

	gso_dmawnz_ns(obj,(ADDRESS)BOX2,vs_dict,0,0);
	alloc_cache(BOX2,0,obj);
	obj->ozval=1;
	obj->oypos.u.intpos=SCY(0x59);
	insert_object(obj,&objlst);
	return;
} 

OBJECT *get_a0_symbol(WORD pa0) 
{
	OBJECT **ta1;
	OBJECT *obj;
	PROCESS *ptemp;
	
	ptemp=(PROCESS *)current_proc->pdata.p_dronevar1;
	ta1=(OBJECT**)&(ptemp->p_context.c_stack);
	ta1+=pa0;

	obj=*ta1;
	current_proc->a1=obj->oxpos.u.intpos+(obj->osize.u.xpos>>1);
	return(obj);	
}

void kill_symbol_flasher(void) 
{
	PROCESS *ptemp;

	ptemp=process_exist(PID_SFLASH,0xffff);
	if (ptemp!=NULL)
		ptemp->a10=0;
	return;
}

void symbol_flasher(void)
{
	WORD ta11=current_proc->a11;
	
	current_proc->a10=1;
	do
	{
		sk_flash_sleep(0x5000);
		sk_flash_sleep((ta11<12)?SYMBOL_Y:SYMBOL_Y+64);
	}
	while(current_proc->a10==1);
	process_suicide();

} 
void sk_flash_sleep(short pa0) 
{
	(current_proc->pa8)->oypos.u.intpos=pa0;
	process_sleep(6);
	return;
}

void end_of_tournament(void) 
{
	select_yer_ending();
	stack_jump(eot_done);
}

//***********************************************************************
extern char *end_winner_text[];
void victory_message(void)
{
	(char *)current_proc->a0=get_winner_text();
	current_proc->pdata.p_store1=0x19;
	winner_msg_rise();
	process_sleep(0xa0);

	current_proc->a0=0;
	current_proc->a1=0x13;
	msg_rise();
	process_sleep(0xa0);

	current_proc->a0=1;
	current_proc->a1=0xe;
	msg_rise();
	process_sleep(0xf0);

	return;
}

void msg_rise(void)
{
	current_proc->pdata.p_store1=current_proc->a1;
	current_proc->a0=(ADDRESS)end_winner_text[current_proc->a0];
	winner_msg_rise();
	return;
}

extern FNTSETUP pf_rise[];
void winner_msg_rise(void)
{
	OBJECT *ta0,*ta5,*ta1,*ta2;

	lm_setup(pf_rise);
	mk_printf((char *)current_proc->a0);

	f_novel=1;

	set_objlst2_vel(-(0x80000));

	f_novel=0;
	process_sleep(current_proc->pdata.p_store1);

	f_novel=1;
	set_objlst2_vel(0);

	ta0=objlst2;
	/* rise4 */
	do
	{
		ta5=ta0;
		ta0=ta0->olink;
	}
	while(ta0!=NULL);

	ta1=objlst;
	ta2=objlst2;

	objlst=objlst2=NULL;

	ta5->olink=ta1;
	objlst=ta2;

	return;
}

void set_objlst2_vel(long pa1)
{
	OBJECT *oa0;

	oa0=objlst2;

	/* rise3 */
	do
	{
		oa0->oyvel.pos=pa1;
		oa0=oa0->olink;
	}
	while(oa0!=NULL);

	return;
}


#if 0
/******************************************************************************
 Function: void mk3_cast_o_characters(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	introduce the cast!
******************************************************************************/
extern char txt_mk_cast[];
extern void *cast_table[];
void mk3_cast_o_characters(void)
{
	void *ta11;
	OBJECT *obj;
	PROCESS *ptemp;
	WORD pchar;
	WORD pcount;

	DISPLAY_ON;
	murder_myoinit();
	DONT_SHOW_SCORES;

	do_background(BKGD_BATTLE_MOD);

	p15_centered(txt_mk_cast,SCX(0xc8),SCY(0x30));
	process_sleep(0x70);

	dallobj(OID_TEXT);
	process_sleep(0x10);

	ta11=cast_table;

	while (GET_LONG(ta11)!=0)
	{ 
		/* load correct dudes overlay */
		//async_overlay_load(GET_LONG(ta11)++);

		/* coc3, print text of character names */
		while (GET_LONG(ta11)!=0)
		{
			(ADDRESS)current_proc->pa8=GET_LONG(ta11)++;		// get txt
			current_proc->a0=GET_WORD(ta11)++;			// get x pos
			current_proc->a1=GET_WORD(ta11)++;			// get y pos
			pds_centered((char*)current_proc->pa8,(short)current_proc->a0,(short)current_proc->a1);
		}

		((ADDRESS *)ta11)++;				// skip zero termination entry

		/* coc7, get dudes out here */

		/* setup dudes to display */
		pcount=0;
		do
		{
			pchar=GET_WORD(ta11)++;			// get char #
			obj=make_ending_char(pchar,pcount++);
			obj->ochar=pchar;
			obj->ozval=FRONT_Z;
			current_proc->pdata.p_flags=PM_ALT_PAL;
			player_normpal();
			insert_object(obj,&objlst);

			ptemp=CREATE(PID_FX,take_a_bow);
			ptemp->pdata.p_otherproc=ptemp;
			ptemp->pdata.p_otherguy=obj;

			ptemp->a11=GET_WORD(ta11)++;	// position
			process_sleep(1);
		}
		while(GET_WORD(ta11)!=0);

		((WORD *)ta11)++;				// skip zero termination entry

		if (GET_WORD(ta11)!=0) 
			tsound(GET_WORD(ta11));

		((WORD *)ta11)++;				// skip zero termination entry
		
		/* coc4 */
		if ( GET_LONG(ta11)!=0 )
		{
			process_sleep(0x140);
			dallobj(OID_TEXT);
		}
		else break;
	}

	/* coc8 */
	process_sleep(0x40*5);
	MURDER;
	process_sleep(0x20);
	murder_myoinit_score();
	process_sleep(8);
	return;
}

/* player select animation tables */
#if 0	//-SONY-
extern void *kano_endanitab1[];
extern void *sonya_endanitab1[];
extern void *jax_endanitab1[];
extern void *ind_endanitab1[];
extern void *sz_endanitab1[];
extern void *swat_endanitab1[];
extern void *lia_endanitab1[];
extern void *robo1_endanitab1[];
extern void *lao_endanitab1[];
extern void *tusk_endanitab1[];
extern void *st_endanitab1[];
extern void *lk_endanitab1[];
extern void *kit_endanitab1[];
extern void *scorp_endanitab1[];
extern void *sk_endanitab1[];
#endif

#define ANIM_END_JUMPUP	(ANIM_VICTORY+1)
#define ANIM_END_RUN	(ANIM_VICTORY+2)
void *character_cast_anitabs[] =
{
	NULL,
#if 0	
	kano_endanitab1,
	sonya_endanitab1,
	jax_endanitab1,
	ind_endanitab1,
	sz_endanitab1,
	swat_endanitab1,
	lia_endanitab1,
	robo1_endanitab1,
	robo1_endanitab1,
	lao_endanitab1,
	tusk_endanitab1,
	tusk_endanitab1,
	st_endanitab1,
	lk_endanitab1,
	robo1_endanitab1,
	kit_endanitab1,
	kit_endanitab1,
	kit_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	scorp_endanitab1,
	sk_endanitab1,
#endif	
};

OBJECT *make_ending_char(WORD pchar,WORD pcount) 
{
	void *heap;
	ADDRESS *animframe;
	WORD flags;

	/* setup to use fighter 1 & 2 buffers, then alloc memory */
	switch (pcount)
	{
		case 0:		// fighter 1
			flags=PFLAG_FIGHTER|PFLAG_PALLOAD;
			break;
		case 1:		// fighter 2
			flags=PFLAG_FIGHTER|PFLAG_FIGHTER2|PFLAG_PALLOAD;
			break;
		default:
			flags=PFLAG_PALLOAD;
			break;
	}

	heap=character_cast_anitabs[pchar];

 	animframe=(ADDRESS *)COMPUTE_ADDR(heap,*((ADDRESS *)heap));			// frame #1 stance

	/* mpo5 */
	while (*animframe==ANI_OCHAR_JUMP)
	{
		animframe+=2;
		animframe=(ADDRESS *)COMPUTE_ADDR(heap,*(animframe));
	}

	current_proc->pa9=animframe;

	gmo_proc_special(0,heap,flags);						// get obj for fake player

	current_proc->pdata.p_flags|=PM_ALT_PAL;
	player_normpal();
	
	return(current_proc->pa8);
}

void take_a_bow(void)
{
	OBJECT *obj=current_proc->pa8;

	current_proc->pdata.p_slave=NULL;

	ground_ochar();
	current_proc->pdata.p_ganiy=obj->oypos.u.intpos;
	obj->oypos.u.intpos+=0x90;
	obj->oxpos.u.intpos=worldtlx.u.intpos+(WORD)current_proc->a11;

	get_char_ani(ANIM_TABLE1,ANIM_END_JUMPUP);
	((ADDRESS *)current_proc->pa9)++;
	do_next_a9_frame(obj);

	obj->ograv.pos=0;
	obj->oyvel.pos=-SCY(0x90000);

	/* btf6 */
	do
	{
		process_sleep(1);
	}
	while(obj->oypos.u.intpos>current_proc->pdata.p_ganiy);

	/* tab7 */
	do
	{
		process_sleep(1);
		next_anirate();
		obj->oyvel.pos+=SCY(0xc000);
	}
	while(obj->oypos.u.intpos<current_proc->pdata.p_ganiy);

	tsound(0x18);			// feet land on ground
	ground_player(obj);
	stop_a8(obj);

	CREATE(PID_FX,wake_me_up)->a11=(ADDRESS)current_proc;		// pass my proc

	stack_jump(ending_victory_animation);
}

void wake_me_up(void)
{
	process_sleep(0xc0);
	fastxfer((PROCESS *)current_proc->a11,run_away);
	process_suicide();
}

void run_away(void)
{
	OBJECT *obj=current_proc->pa8;

	if (obj->ochar==FT_SK) 
	{
		set_inviso(obj);
		multi_adjust_xy(obj,0,SCY(0x20));
		create_fx(FX_INVISO_POOF);
		tsound(0x81);				
		process_sleep(8);
		delobjp(obj);
		process_suicide();
	}

	delete_slave();

	if ((obj->oflags & M_FLIPH)==0)
		flip_multi(obj);

	/* tab3 */
	if (obj->oxpos.u.intpos>=(worldtlx.u.intpos+SCRRGT/2))
	{
		(long)current_proc->a11=SCX(0x80000);
		flip_multi(obj);
	}
	else
	{
		(long)current_proc->a11=-SCX(0x80000);
	}

	/* rleft, exit stage right or left */
	get_char_ani(ANIM_TABLE1,ANIM_END_RUN);
	init_anirate(3);

	current_proc->a10=0x40;
	do
	{
		process_sleep(1);
		obj->oxvel.pos=(long)current_proc->a11;
		next_anirate();
	}
	while(--current_proc->a10>0);
	stop_a8(obj);
	delobjp(obj);
	process_suicide();
}
#endif

/******************************************************************************
 Function: void mk3_thank_you(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	thank all!
******************************************************************************/
extern char txt_execs[];
extern char txt_testers[];
extern char txt_production[];
extern char txt_thanx_alot[];
extern char txt_mk3_design[];
extern char txt_mktril[];

THANKX mk3_thanx[]=
{
	{txt_mk3_design,0x160},	
	{txt_mktril,0x160},	
	{txt_testers,0x160},
	{txt_production,0x100},
	{txt_thanx_alot,0x120},
	{(char *)0xffffffff,0}
};

void mk3_thank_you(void)
{
	THANKX *ta11;
	clr_scrn();
	murder_myoinit_score();
	sound_music_start(MUSIC_SPECIAL);
	process_sleep(4);

 f_error=1;
	do_background(BKGD_GRAVE_MOD);
	DISPLAY_ON;

	CREATE(PID_FX,text_deleter);

	ta11=mk3_thanx;
	/* des9 */
	do
	{
		if ( ta11->txt==(char *)0xffffffff)
			break;

		if ( ta11->txt!=NULL )
		{
			pds_centered_soff(ta11->txt,SCX(0xc8),(0xff));
			set_letter_vel();
		}

		/* des5 */
		process_sleep(ta11->sleep);
		ta11++;
	} while (1);

	/* des9 */
	process_sleep(0xc0);
	MURDER;

	fadeout_jsrp(10);

	return;
}

void set_letter_vel(void)
{
	OBJECT *oa0;
	OBJECT *oa3;
	OBJECT *oa4,*oa5;

	f_novel=1;

	oa0=objlst2;
	if ( oa0!=NULL )
	{
		oa3=oa0;
		objlst2=NULL;

		/* scrp4 */
		do
		{
			oa0->oyvel.pos=-(0x10000);
			oa0->ozval=100;
		} while ((oa0=oa0->olink)!=NULL);

		oa4=objlst;
		if (oa4!=NULL )
		{
			/* scrp5 */
			do
			{
				oa5=oa4;
				oa4=oa4->olink;
			} while (oa4!=NULL);
			oa5->olink=oa3;
		}
		else objlst=oa3;
	}

	/* slv9 */
	f_novel=0;

	return;
}

void text_deleter(void)
{
	OBJECT *oa0,*oa2;
	do
	{
		process_sleep(8);
		oa0=objlst;
		if ( oa0!=NULL )
		{
			/* objjd */
			do
			{
				oa2=oa0->olink;
				if ( oa0->oypos.u.intpos<-12 )
					delobjp(oa0);

				/* objjc */
				oa0=oa2;
			} while (oa0!=NULL  );
		}

	} while (1);
}

#if 0	//-SONY-
/******************************************************************************
 Function: void mk3_design_team(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	show the guys
******************************************************************************/
extern char txt_david[];
extern char txt_greg[];
extern char txt_markm[];
extern char txt_markg[];
extern char txt_rob[];
extern char txt_scott[];
extern char txt_ed[];
extern char txt_johnt[];
extern char txt_steve[];
extern char txt_dan[];
extern char txt_tonyg[];
extern char txt_dave[];
extern char txt_johnv[];

extern OIMGTBL a_DAVE;
extern OIMGTBL a_GREG;
extern OIMGTBL a_GUIDO;
extern OIMGTBL a_MARK;
extern OIMGTBL a_ROB;
extern OIMGTBL a_SCOTT;

extern OIMGTBL T_DFORDEN;
extern OIMGTBL T_MICHIC;
extern OIMGTBL T_JOHNV;
extern OIMGTBL T_BERAN;
extern OIMGTBL T_ED;
extern OIMGTBL T_GOSKIE;
extern OIMGTBL T_TOBIAS;
extern void *FACES_anims[];
char txt_mk3_dteam[]="ULTIMATE HOME MK3 SONY DEVELOPMENT TEAM";
char txt_mk_design[]="ULTIMATE MK3 DESIGN TEAM";
WORD team_fade_in[]={0,0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128,0xffff};
DTEAM sony_team_table[]=
{
	{txt_markm,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_MARK,0,0},
	{NULL,-1,0x8e},

	{txt_greg,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_GREG,100,-6},
	{NULL,-1,0x8e},

	{txt_david,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_DAVE,48,-22},
	{NULL,-1,0x1c},

	{txt_markg,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_GUIDO,-57,-29},
	{NULL,-1,0x8e},

	{txt_scott,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_SCOTT,79,-60},
	{NULL,-1,0x8e},

	{txt_rob,160,SCY(0xdd)+20},
	{NULL,0,0},
	{&a_ROB,4,-70},
	{NULL,-1,0x8e},

	{&a_ROB,-2,-2},

};

#define TEAM_X (SCX(0x6a)-76)
#define TEAM_Y (SCY(0x66)-80)

DTEAM arcade_team_table[]=
{
	{txt_ed,SCX(0x90),SCY(0xdd)+20},
	{txt_johnt,SCX(0x108),SCY(0xdd)+20},
	{&T_ED,TEAM_X+0,TEAM_Y+0},
	{&T_TOBIAS,TEAM_X+SCX(101),TEAM_Y+SCY(9)},
	{NULL,-1,-1},

	{txt_steve,SCX(0xc8),SCY(0xdd)+20},
	{NULL,0,0},
	{&T_BERAN,TEAM_X+SCX(46),TEAM_Y-SCY(19)},
	{NULL,-1,0x8e},

	{txt_dan,SCX(0xc8),SCY(0xdd)+20},
	{NULL,0,0},
	{&T_DFORDEN,TEAM_X-SCX(50),TEAM_Y-SCY(34)},
	{NULL,-1,0x1b},

	{txt_tonyg,SCX(0x90)-10,SCY(0xdd)+20},
	{txt_dave,SCX(0x108)+10,SCY(0xdd)+20},
	{&T_GOSKIE,TEAM_X+SCX(16),TEAM_Y-SCY(59)},
	{&T_MICHIC,TEAM_X+SCX(79),TEAM_Y-SCY(61)},
	{NULL,-1,0x8e},

	{txt_johnv,SCX(0xc8),SCY(0xdd)+20},
	{NULL,0,0},
	{&T_JOHNV,TEAM_X+SCX(154),TEAM_Y-SCY(42)},
	{NULL,-1,0x8e},

	{&a_ROB,-2,-2},

};

void mk3_design_team(DTEAM *dptr)
{
	OBJECT *oa0;
	WORD *pal;
	PROCESS *ptemp;

	clr_scrn();
	murder_myoinit_score();
	process_sleep(4);
	
	//-SONY_IGNORE-sony_graphics_setup();
	bkgd_graphics_setup();

	level_overlay_load(LVL_DTEAM);
	dlists=dlists_bogus;
	irqskye=0;

	if ( dptr==arcade_team_table )
		pds_centered(txt_mk_design,SCX(0xc8),SCY(0x18));
	else pds_centered(txt_mk3_dteam,SCX(0xc8),SCY(0x18));

	oa0=objlst2;
	/* team0 */
	do
	{
		oa0->oid=OID_FX;
		oa0=oa0->olink;
	}
	while(oa0!=NULL );

	process_sleep(0x30);

	current_proc->a10=10;

	/* team2 */
	do
	{
		/* print text */
		pds_centered((char *)dptr->t1,dptr->x1,dptr->y1-8);
		dptr++;
		if ( dptr->t1!=NULL )
			pds_centered((char *)dptr->t1,dptr->x1,dptr->y1-8);
		dptr++;

		/* draw face */
		while ( dptr->x1!=-1 )
		{
			gso_dmawnz_ns(oa0,(ADDRESS)dptr->t1,FACES_anims,0);
			alloc_cache((OIMGTBL *)dptr->t1,&FACES_anims,oa0);
			animate(SINGLE_ANI,(OIMGTBL*)dptr->t1,oa0->oflags);
			oa0->ozval=current_proc->a10;
			current_proc->a10--;
			insert_object(oa0,&objlst);
			set_xy_coordinates(oa0,64+dptr->x1,104+dptr->y1-8);

			/* cool face fadein */
			ptemp=CREATE(PID_FADE,fadeproc);
			pal=dptr->t1;
			((OIMGTBL *)pal)++;
			pal=(WORD *)GET_LONG(pal);
			(WORD *)ptemp->a11=team_fade_in;
			(LONG)ptemp->pa9=findpal(pal);
			(WORD *)ptemp->pa8=pal;              // palette local

			dptr++;
		};

		tsound(dptr->y1);		// correct sound effect

		process_sleep(0x70);
		dallobj(OID_TEXT);
		dptr++;
	}
	while(dptr->x1!=-2);

	/* team9 */
	tsound(0x8e);
	process_sleep(0xc0);
	dallobj(OID_TEXT);
	process_sleep(0x20);

	murder_myoinit_score();
	clr_scrn();
	process_sleep(8);

	return;
}
#endif

