/******************************************************************************
mkmode.c  File: mkcoin.c

 Date: Nov 1995

 (C) Williams Entertainment

 Mortal Kombat III Coin Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkbkgd.h"
#include "mkobj.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkutil.h"
#include "mkinit.h"
#include "mkfx.h"
#include "mkpal.h"
#include "mkjoy.h"
#include "mktext.h"
#include "mkmain.h"
#include "mksound.h"
#include "mkmode.h"
#include "mkdma.h"
#include "vcache.h"

extern void amode(void);

extern void *fl_coin_cursor[];
extern char txt_mkcoin1[];
extern char txt_mkcoin2a[];
extern char txt_mkcoin2b[];
extern char txt_mkcoin3a[];
extern char txt_mkcoin3b[];
extern char txt_mkcoin4[];
extern char txt_mkcoin4a[];
extern char txt_mkcoin4b[];
extern char txt_freeplay[];
extern FNTSETUP pf_credit_mode[];
extern BYTE nucoin_dict[];

extern WORD NWHITEPAL_PAL[];
extern WORD NREDPAL_PAL[];

extern WORD RED_p[];

WORD RED_p[]=
{
	0,16,
	0x0000, 0x0001, 0x7001, 0x8001, 0x8801, 0x9801, 0xA001, 0xA801, 0xB001, 0xB801,
	0xC001, 0xC801, 0xD801, 0xE001, 0xE801, 0xF001
};



//******************************************************************************
//******************************************************************************
#define SLOT_START_X	(0x6+7)
#define SLOT_START_Y	(0x40+10)
#define SLOT_INC_X		(0x4c-3)
#define CC_WIDTH		67
#define CC_HEIGHT		85
#define CC_THICK		4

extern void *CP_MK1[];
extern void *CP_MK2[];
extern void *CP_MK3[];
extern void *CP_UMK3[];
extern void *CP_2ON2[];
extern void *CP_3ON3[];
extern void *CP_MORTAL[];
extern void *CP_KOMBAT[];
extern void *CP_TOURNAMENT[];


WORD coinpage_cursor[]=
{
	CC_WIDTH,CC_THICK,SLOT_START_X,SLOT_START_Y,
	CC_THICK,CC_HEIGHT,SLOT_START_X,SLOT_START_Y,
	CC_THICK,CC_HEIGHT,SLOT_START_X+CC_WIDTH-CC_THICK,SLOT_START_Y,
	CC_WIDTH,CC_THICK,SLOT_START_X,SLOT_START_Y+CC_HEIGHT-CC_THICK,
	0xffff
};

WORD mode_map[]=
{
	 0,		// 0
	 1,		// 1
	 4,		// 2
	 2,		// 3
	 3,		// 4
};

void update_cursor_color(void)
{
	OBJECT *ta1;
	WORD palid,color;

	palid=findpal(bpal_flash1_P);
	color=pal_buffer[2+(palid*2)*(256/sizeof(u64))];

	ta1=current_proc->pa8;
	
	do
	{
		ta1->oconst=color;
		ta1=(OBJECT *)ta1->oslink;
	}
	while(ta1!=NULL );

	return;
}


void mode_select(void)
{
	WORD padvalue;
	WORD ta9;
	OBJECT *obj;
	WORD palid;

	DISPLAY_ON;
	gstate=GS_MODE_SELECT;
	coinpage_setup();

	CREATE(PID_MODE,mode_mood_sounds);

	CREATE(PID_AMODE,boonpal_stuff)->a11=(ADDRESS)fl_coin_cursor;
	
	make_cursor_objects(coinpage_cursor,OID_AMODE,0x7801);
	obj=current_proc->pa8=(OBJECT*)current_proc->a10;
	
	current_proc->a11=0;
	change_letter_colors(NREDPAL_PAL);

	current_proc->pdata.p_anicount=0x40*15;			// time to choose

	current_proc->a10=20;
	do
	{
		update_cursor_color();
		process_sleep(1);
	}
	while(--current_proc->a10>0);

	/* msp2 */
	do
	{
		current_proc->a10=12;
		/* msp3 */
		do
		{
			update_cursor_color();
			process_sleep(1);

			if (--current_proc->pdata.p_anicount==0)
				mode_select_timeout();

		}
		while(--current_proc->a10>0);

		/* msp4 */
		padvalue=swcurr.u.p1pad|swcurr.u.p2pad;		// either player can select
		
		if (padvalue & MASK_JRIGHT) 
		{
			if (current_proc->a11!=3)
			{
				change_letter_colors(NWHITEPAL_PAL);
				current_proc->a11++;
				change_letter_colors(NREDPAL_PAL);
				move_cursor(SLOT_INC_X,0);
			}
		}

		if (padvalue & MASK_JLEFT) 
		{
			if (current_proc->a11!=0)
			{
				change_letter_colors(NWHITEPAL_PAL);
				current_proc->a11--;
				change_letter_colors(NREDPAL_PAL);
				move_cursor(-SLOT_INC_X,0);
			}
		}

		if (swcurr.u.p1pad & M_P1START)
		{
			if (swcurr.u.p1pad & MASK_JUP)
				current_proc->a11=4;
			
			ta9=0;
			break;
		}

		if (swcurr.u.p2pad & M_P2START)
		{
			if (swcurr.u.p2pad & MASK_JUP)
				current_proc->a11=4;
		
			ta9=1;
			break;
		}
		
	}
	while(1);

	/* msp_picked */
	mode_of_play=mode_map[current_proc->a11];
	MURDER;
	dallobj(OID_AMODE);

	f_nosound=0;
	tsound(0x6f);					


	if (ta9==0)
		p1_state=PS_PSEL;
	else p2_state=PS_PSEL;
	
	CREATE(PID_MODE,mode_shaker);
	
	if (current_proc->a11==4)
		goto FAST_EXIT;
	
	current_proc->a10=8;
	/* mspp3 */
	do
	{
		shift_letters(-SCX(6));
		process_sleep(3);
		shift_letters(SCX(6));
		process_sleep(3);
	}
	while(--current_proc->a10>0);

	process_sleep(0x30);
FAST_EXIT:	
	MURDER;
	current_proc->a10=0;

	return;
}

void mode_select_timeout(void)
{
	map_start=NULL;			// reset any map stuff
	murder_myoinit_score();
	stack_jump(amode);
}

void move_cursor(short pa0,short pa1)
{
	OBJECT *ta1;

	ta1=current_proc->pa8;
	
	do
	{
		ta1->oxpos.u.intpos+=pa0;
		ta1=(OBJECT *)ta1->oslink;
	}
	while(ta1!=NULL );

	tsound(0x6e);				// cursor move sound 
	return;
}

void change_letter_colors(WORD *pa1)
{
	OBJECT *ta2;
	OBJECT *pa8=current_proc->pa8;

	switch (current_proc->a11)
	{
		case 0:
			ta2=(OBJECT *)&baklst2;
			break;
		case 1:
			ta2=(OBJECT *)&baklst3;
			break;
		case 2:
			ta2=(OBJECT *)&baklst4;
			break;
		case 3:
			ta2=(OBJECT *)&baklst5;
			break;
		case 4:
			ta2=(OBJECT *)&baklst6;
			break;
	}

	current_proc->pa8=ta2->olink;
	do
	{
		swpal(pa1,current_proc->pa8);
		current_proc->pa8=(current_proc->pa8)->olink;
	}
	while(current_proc->pa8!=NULL);

	current_proc->pa8=pa8;

	return;
}

void shift_letters(short pa1)
{
	OBJECT *ta2;
	OBJECT *pa8=current_proc->pa8;

	switch (current_proc->a11)
	{
		case 0:
			ta2=(OBJECT *)&baklst2;
			break;
		case 1:
			ta2=(OBJECT *)&baklst3;
			break;
		case 2:
			ta2=(OBJECT *)&baklst4;
			break;
		case 3:
			ta2=(OBJECT *)&baklst5;
			break;
		case 4:
			ta2=(OBJECT *)&baklst6;
			break;
	}

	current_proc->pa8=ta2->olink;
	do
	{
		(current_proc->pa8)->oxpos.u.intpos+=pa1;
		current_proc->pa8=(current_proc->pa8)->olink;
	}
	while(current_proc->pa8!=NULL);

	current_proc->pa8=pa8;

	return;
}

void mode_shaker(void)
{
	shake_a11(8,8);
	process_suicide();
}

WORD mood_sounds[]=	
{
	0x79,
	0x7a,
	0x7b,
	0x95,
	0x7d
};

void mode_mood_sounds(void)
{
	sound_music_start(MUSIC_BUYIN);
	
	/* mms2 */
	do
	{
		current_proc->a10=0;
		do
		{
			process_sleep(0x40*3);
			tsound(mood_sounds[current_proc->a10]);
			current_proc->a10++;
		}
		while(current_proc->a10!=9);
	}
	while(1);
}

extern FNTSETUP pf_dave_smallc_soff[];
void pds_coin(OBJECT **pa10,char *pa8,short x,short y)
{
	OBJECT *ta11;

	ta11=objlst2;

	objlst2=NULL;
	lm_setup(pf_dave_smallc_soff);
	fnt_state.fnt_posx=x;
	fnt_state.fnt_posy=y;
	mk_printf(pa8);

	*pa10=objlst2;
	objlst2=ta11;

	return;
}

#if 0
void p15_coin(OBJECT **pa10,char *pa8,short x,short y)
{
	OBJECT *ta11;

	ta11=objlst2;

	objlst2=NULL;
	p15_centered(pa8,x,y);

	*pa10=objlst2;
	objlst2=ta11;

	return;
}
void tack_a14_on_a0(OBJECT *pa14,OBJECT *pa0)
{
	OBJECT *pa1;

	do
	{
		pa1=pa0;
		pa0=pa0->olink;
	}
	while(pa0!=NULL);

	pa1->olink=pa14;
	pa14->olink=NULL;

	return;
}
#endif

void coinpage_setup(void)
{
	OBJECT *obj;
	
	send_code_a3(0);
	
	murder_myoinit_score();
	do_background(BKGD_COIN_MODE);

	/* print MORTAL KOMBAT OPTION */
//	pds_coin(&baklst2,txt_mkcoin1,40,134);
	gso_dmawnz_ns(obj,(ADDRESS)CP_MORTAL,nucoin_dict,0,0);
	alloc_cache(CP_MORTAL,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,18+8-2,134-32);
	insert_object(obj,&baklst2);

	gso_dmawnz_ns(obj,(ADDRESS)CP_KOMBAT,nucoin_dict,0,0);
	alloc_cache(CP_KOMBAT,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,18+8-2,146-32);
	insert_object(obj,&baklst2);
#if 0	
	gso_dmawnz_ns(obj,(ADDRESS)CP_MK1,nucoin_dict,0,0);
	alloc_cache(CP_MK1,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,11+8-2,76);
	insert_object(obj,&baklst7);
#endif

	/* print 4 PLAYER 2 on 2 KOMBAT */
//	p15_centered_soff(txt_mkcoin2a,120,120-20);
//	pds_coin(&baklst3,txt_mkcoin2b,120,134);
	gso_dmawnz_ns(obj,(ADDRESS)CP_2ON2,nucoin_dict,0,0);
	alloc_cache(CP_2ON2,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,101+1,134-32);
	insert_object(obj,&baklst3);

	gso_dmawnz_ns(obj,(ADDRESS)CP_KOMBAT,nucoin_dict,0,0);
	alloc_cache(CP_KOMBAT,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,95+2,146-32);
	insert_object(obj,&baklst3);

	current_proc->a14=(ADDRESS)objlst2;
	objlst2=NULL;
//	tack_a14_on_a0((OBJECT *)current_proc->a14,(OBJECT *)&baklst3);

#if 0
	gso_dmawnz_ns(obj,(ADDRESS)CP_MK2,nucoin_dict,0,0);
	alloc_cache(CP_MK2,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,89+2,96-13);
	insert_object(obj,&baklst7);
#endif

	/* print 6 PLAYER 3 on 3 KOMBAT */
//	p15_centered_soff(txt_mkcoin4a,200,120-20);
//	pds_coin(&baklst4,txt_mkcoin4b,200,134);
	gso_dmawnz_ns(obj,(ADDRESS)CP_3ON3,nucoin_dict,0,0);
	alloc_cache(CP_3ON3,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,180-1-3-1,134-32);
	insert_object(obj,&baklst4);

	gso_dmawnz_ns(obj,(ADDRESS)CP_KOMBAT,nucoin_dict,0,0);
	alloc_cache(CP_KOMBAT,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,177-3-3-1,146-32);
	insert_object(obj,&baklst4);

	current_proc->a14=(ADDRESS)objlst2;
	objlst2=NULL;
//	tack_a14_on_a0((OBJECT *)current_proc->a14,(OBJECT *)&baklst6);

#if 0
	gso_dmawnz_ns(obj,(ADDRESS)CP_MK3,nucoin_dict,0,0);
	alloc_cache(CP_MK3,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,166-3,85-13);
	insert_object(obj,&baklst7);
#endif

	/* Print Tournament */
//	p15_centered_soff(txt_mkcoin3a,280,120-20);
//	pds_coin(&baklst5,txt_mkcoin3b,280,134);
	gso_dmawnz_ns(obj,(ADDRESS)CP_TOURNAMENT,nucoin_dict,0,0);
	alloc_cache(CP_TOURNAMENT,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,253-4-9+3-1,134-32);
	insert_object(obj,&baklst5);

	gso_dmawnz_ns(obj,(ADDRESS)CP_KOMBAT,nucoin_dict,0,0);
	alloc_cache(CP_KOMBAT,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,253-4-9+3,146-32);
	insert_object(obj,&baklst5);

	current_proc->a14=(ADDRESS)objlst2;
	objlst2=NULL;
//	tack_a14_on_a0((OBJECT *)current_proc->a14,(OBJECT *)&baklst4);

#if 0
	gso_dmawnz_ns(obj,(ADDRESS)CP_UMK3,nucoin_dict,0,0);
	alloc_cache(CP_UMK3,0,obj);
	obj->ozval=0;
	set_xy_coordinates(obj,242-6,79-10);
	insert_object(obj,&baklst7);
#endif

	/* print options */
	pds_coin(&baklst6,txt_mkcoin4,160-6,218);

	return;
}

//******************************************************************************
//******************************************************************************
char txt_player_x[]="%d-";
char txt_tournament[]="MK TRILOGY TOURNAMENT";

extern void *dlist_tournament[];

extern WORD word1;
extern WORD word2;
extern WORD word3;
extern WORD word4;
extern WORD word5;
extern WORD word6;
extern WORD word7;
extern WORD word8;

#if 0
TREES tree_structure[]=
{
	{13,393,&word1},
	{50,393,&word2},
	{87,393,&word3},
	{124,393,&word4},
	{161,393,&word5},
	{198,393,&word6},
	{235,393,&word7},
	{272,393,&word8},

	{51,296,&twinners[0]},
	{107,296,&twinners[1]},
	{166,296,&twinners[2]},
	{225,296,&twinners[3]},

	{97,205,&twinners[4]},
	{166,205,&twinners[5]},

	{129,115,&twinners[6]},
	{0,0,NULL}
};

extern void *tourn_module[];

short match_scroll[]=
{
	240,240,240,240,143,143,51,0
};

void tournament_tree(WORD pa10)
{
	TREES *ta11;
	WORD ta0,ta8;

	DISPLAY_OFF;

	current_proc->pdata.p_flags=pa10;
	murder_myoinit_score();

	/* load mugshot data */
	special_fx_load(FX_MUGS_LOAD);
	spec_fx=FX_NO_LOAD;
	
	/* load bkgd */
	do_background(BKGD_MK3_TOURN);
	sound_music_start(MUSIC_SELECTSC);
	
	dlists=dlist_tournament;
	process_sleep(2);

	ta11=tree_structure;
	ta8=0;
	/* tree3 */
	while (ta11->t_x!=0)
	{
		ta0=*(ta11->t_wrd);
		if (ta0==0) 
		{
			tourn_face(TOURN_QUEST,ta11->t_x,ta11->t_y);
		}
		else
		{
			tourn_face(p1_tour[ta0-1],ta11->t_x,ta11->t_y);
			pds_centered_p1(txt_player_x,ta11->t_x+34/2,ta11->t_y+44,ta0);
		}

#if 0
		move_object_list(&objlst2,&objlst);

		if ((ta8>>1)==pa10) 
			move_object_list(&objlst,&baklst2);	// plane to flash
		else move_object_list(&objlst,&baklst3);	// plane not to flash
#endif

		move_object_list(&objlst,&baklst3);		// move faces to correct plane

		if ((ta8>>1)==pa10) 
			move_object_list(&objlst2,&baklst2);	// plane to flash
		else move_object_list(&objlst2,&baklst3);	// plane not to flash


		ta11++;
		ta8++;
	}

	/* treex */
	p7_centered(txt_tournament,SCX(0xc8),SCX(0x5)+16);

	DISPLAY_ON;

	/* move to correct place */
	scrolly.u.intpos=2;
	while (worldtly.u.intpos<match_scroll[pa10])
	{
		update_faces(-scrolly.u.intpos);
		process_sleep(1);
	}

	scrolly.u.intpos=0;
	update_faces(0);

	process_sleep(10);

	CREATE(PID_FX,ttext_flasher);
	process_sleep(0x40*4);

	return;
}

extern OIMGTBL *ochar_order_mugs[];
void tourn_face(WORD p_a0,short pax,short pay) 
{
	OBJECT *obj;

	gso_dmawnz_ns_coor(obj,(ADDRESS)ochar_order_mugs[p_a0],0,0,0,pax+1,pay+1);
	alloc_cache((OIMGTBL*)ochar_order_mugs[p_a0],0,obj);
	
	insert_object(obj,&objlst);

	return;	
}

void update_faces(short pa0) 
{
	OBJECT *obj;

	obj=(OBJECT*)&baklst2;

	while (obj->olink!=NULL)
	{
		obj=obj->olink;
		obj->oyvel.u.intpos=pa0;
	}

	obj=(OBJECT*)&baklst3;

	while (obj->olink!=NULL)
	{
		obj=obj->olink;
		obj->oyvel.u.intpos=pa0;
	}

	return;
}

void ttext_flasher(void)
{
	OBJECT *ta10;

	ta10=baklst2;
	do
	{
		ttf_sleep(NULL);
		ttf_sleep(ta10);
	}
	while(1);
}

void ttf_sleep(OBJECT *pa0)
{
	baklst2=pa0;
	process_sleep(10);
	return;
}
#endif

#if 1	//umk3 way
TREES tree_structure[]=
{
	{TREEORGX,TREEORGY+(TREEYSP*0),&word1},
	{TREEORGX,TREEORGY+(TREEYSP*1),&word2},
	{TREEORGX,TREEORGY+(TREEYSP*2),&word3},
	{TREEORGX,TREEORGY+(TREEYSP*3),&word4},
	{TREEORGX,TREEORGY+(TREEYSP*4),&word5},
	{TREEORGX,TREEORGY+(TREEYSP*5),&word6},
	{TREEORGX,TREEORGY+(TREEYSP*6),&word7},
	{TREEORGX,TREEORGY+(TREEYSP*7),&word8},

	{TREEORG2X,TREEORG2Y+(TREEYSP*0),&twinners[0]},
	{TREEORG2X,TREEORG2Y+(TREEYSP*2),&twinners[1]},
	{TREEORG2X,TREEORG2Y+(TREEYSP*4),&twinners[2]},
	{TREEORG2X,TREEORG2Y+(TREEYSP*6),&twinners[3]},

	{TREEORG3X,TREEORG3Y+(TREEYSP*0),&twinners[4]},
	{TREEORG3X,TREEORG3Y+(TREEYSP*4),&twinners[5]},

	{TREEORG4X,TREEORG4Y,&twinners[6]},
	{0,0,NULL}
};
char txt_ques[]="? ? ? ? ? ";

char n_kano[]="KANO";
char n_sonya[]=	"SONYA";
char n_jax[]="JAX";
char n_ind[]="NIGHTWOLF";
char n_sz[]="SUBZERO";
char n_swat[]="STRYKER";
char n_lia[]="SINDEL";
char n_robo1[]="SEKTOR";
char n_robo2[]="CYRAX";
char n_lao[]="KUNG LAO";
char n_tusk[]="KABAL";
char n_sg[]="SHEEVA";
char n_st[]="SHANG";
char n_lk[]="LIU KANG";
char n_smoke[]=	"SMOKE";
char n_kitana[]="KITANA";
char n_jade[]="JADE";
char n_mileena[]="MILEENA";
char n_scorpion[]="SCORPION";
char n_reptile[]="REPTILE";
char n_ermac[]="ERMAC";
char n_noob[]="NOOB";
char n_rain[]="RAIN";
char n_rayden[]="RAYDEN";
char n_baraka[]="BARAKA";
char n_jc[]="CAGE";
char n_kamel[]="KHAMELEON";

char *tnames_table[]=
{
	n_kano,
	n_sonya,
	n_jax,
	n_ind,
	n_jc,

	n_swat,
	n_lia,
	n_robo1,
	n_robo2,
	n_lao,

	n_tusk,
	n_sg,
	n_st,
	n_lk,
	n_smoke,

	n_kitana,
	n_jade,
	n_mileena,
	n_scorpion,
	n_reptile,

	n_ermac,
	n_sz,
	n_smoke,
	n_noob,
	n_rayden,
	n_baraka,
	n_rain,
	n_kamel,
	n_kamel,
	n_kamel,
	n_kamel,
	n_kamel,
};

void tournament_tree(WORD pa10)
{
	TREES *ta11;
	WORD ta0,ta8;
	OBJECT **ta1;
	OBJECT *obj;

	DISPLAY_OFF;

	current_proc->pdata.p_flags=pa10;
	murder_myoinit_score();
//	load_bkgd=BKGD_MK3_TOURN;
//	init_background_module(tourn_module);
	load_bkgd=BKGD_VS_MOD;
	init_background_module(table_o_mods[load_bkgd]);
	multi_plane();
	dlists=dlist_tournament;
	process_sleep(2);

#if 1
	sound_music_start(MUSIC_SELECTSC);

//	freeze_2_pages();
//	background_clear();
//	f_auto_erase=0;
//	text_draw=1;

	ta8=0;			// match counter
	ta11=tree_structure;
	/* tree3 */
	while (ta11->t_x!=0)
	{
		ta0=*(ta11->t_wrd);
		if (ta0==0)
			pds_left(txt_ques,ta11->t_x,ta11->t_y);
		else
		{
			p7_left_p1(txt_player_x,ta11->t_x,ta11->t_y,ta0);
			pds_left(tnames_table[p1_tour[ta0-1]],fnt_state.fnt_posx,fnt_state.fnt_posy);
		}


		if ((ta8>>1)==pa10)
			ta1=&baklst2;
		else ta1=&baklst3;

		move_object_list(&objlst2,ta1);
		ta8++;
		ta11++;
	}

	/* treex */
#if 1
	obj=make_solid_object(0xf800,SCX(0x190),SCY(0x10)+16);
	set_xy_coordinates(obj,0,0);
	insert_object(obj,&objlst);

	obj=make_solid_object(0xf800,SCX(0x190),SCY(0x10)+16);
	set_xy_coordinates(obj,0,SCY(0xf8)+4);
	insert_object(obj,&objlst);
	process_sleep(2);
#endif

	p7_centered(txt_tournament,SCX(0xc8),SCX(0x5)+8);

	text_draw=0;

	process_sleep(3);
	noflip=1;
#endif

	fast_fadein_jsrp(0x10);
//	process_sleep(10);

	CREATE(PID_FX,ttext_flasher);
	process_sleep(0x40*4);

	noflip=0;
	f_auto_erase=1;

	return;
}

void ttext_flasher(void)
{
	OBJECT *ta10;

	ta10=baklst2;
	do
	{
		ttf_sleep(ta10);
		ttf_sleep(NULL);
	}
	while(1);
}

void ttf_sleep(OBJECT *pa0)
{
	baklst2=pa0;
	process_sleep(10);
	return;
}
#endif
