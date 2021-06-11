/******************************************************************************
 File: mksel.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Player Select Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkutil.h"
#include "mkani.h"
#include "mktext.h"
#include "mkinit.h"
#include "mkgame.h"
#include "mkdma.h"
#include "mkmain.h"
#include "mkguys.h"
#include "mkpal.h"
#include "mkjoy.h"
#include "mksound.h"
#include "mkcanned.h"
#include "mksel.h"
#include "wessapi.h"
#include "vcache.h"

/* local stuff */
extern FNTSETUP pf_auto_msg_1[];
extern FNTSETUP pf_auto_msg_2[];
extern FNTSETUP coin_mess[];
extern FNTSETUP buyin_coin_mess[];
extern void *fl_cursor1[];
extern void *fl_cursor2[];
extern void *fl_cursor3[];
extern void *fl_cursor4[];
extern void *fl_cursor5[];
extern void *fl_cursor6[];
extern void *fl_auto[];
extern char *background_names[];
extern WORD bpal_flash6_P[];
extern WORD bpal_flash7_P[];
extern WORD f_special_endur;
extern WORD hidden_included[];

/* mkpsel.s */
extern void *a_badge_spin[];

extern void *ENDUR_RED[];
extern void *ENDUR_GREEN[];
extern void *ENDUR_MAG[];
extern void *ENDUR_GOLD[];
extern void *HDKITANA[];
extern void *HDREPTILE[];
extern void *HDSONYA[];
extern void *HDJAX[];
extern void *HDINDIAN[];
extern void *HDJADE[];
extern void *HDSCORPION[];
extern void *HDKANO[];
extern void *HDMILEENA[];
extern void *HDOSM[];
extern void *HDKAMEL[];
extern void *HDERMAC[];
extern void *HDCLASSUB[];
extern void *HDCAGE[];
extern void *HDKETCHUP[];
extern void *HDBRIDE[];
extern void *HDSWAT[];
extern void *HDMUSTARD[];
extern void *HDLAO[];
extern void *HDTUSKAN[];
extern void *HDSHEGORO[];
extern void *HDSHANG[];
extern void *HDLIUKANG[];
extern void *HDSMOKE[];
extern void *HDRAIN[];
extern void *HDNOOB[];
extern void *HDRAYDEN[];
extern void *HDBARAKA[];
extern void *BOX_01[];			// hidden questions

extern void *HDSHAO[];
extern void *HDMOTARO[];
extern void *QUESTION[];
extern void *SCURSOR[];
extern void *NSCURSOR[];
extern void *MKCOIN_01[];
extern void *MKCOIN_02[];
extern void *MKCOIN_03[];
extern void *MKCOIN_04[];
extern void *MKCOIN_05[];
extern void *MKCOIN_06[];
extern void *MKCOIN_07[];
extern void *MKCOIN_08[];
extern void *MKCOIN_09[];

extern void *HDRAIN2_P[];
extern void *HDNOOB2_P[];
extern void *HDRAYDEN2_P[];
extern void *HDSA2_P[];

extern void *HDSHAG_P[];
extern void *HDSUBZ_P[];
extern void *HDSWAT_P[];
extern void *HDBRDE_P[];
extern void *HDJAX_P[];
extern void *HDLAO_P[];
extern void *HDSOYN_P[];
extern void *HDKANO_P[];
extern void *HDMUST_P[];
extern void *HDKANG_P[];
extern void *HDGORO_P[];
extern void *HDINDY_P[];
extern void *HDKETC_P[];
extern void *HDSAND_P[];
extern void *HDMOTA_P[];
extern void *HDSMOK_P[];
extern void *HDSHAO_P[];

extern void *HDKANOD_P[];
extern void *HDSOYND_P[];
extern void *HDJAXD_P[];
extern void *HDINDYD_P[];
extern void *HDCAGED_P[];
extern void *HDSWATD_P[];
extern void *HDBRDED_P[];
extern void *HDKETCD_P[];
extern void *HDMUSTD_P[];
extern void *HDLAOD_P[];
extern void *HDSANDD_P[];
extern void *HDGOROD_P[];
extern void *HDSHAGD_P[];
extern void *HDKANGD_P[];
extern void *HDKITA2_P[];
extern void *HDJADE2_P[];
extern void *HDMILE2_P[];
extern void *HDSCOR2_P[];
extern void *HDREPT2_P[];
extern void *HDRMAC2_P[];
extern void *HDZERP2_P[];

extern void *psel_module[];

WORD select_active;
short move_sel_now;
void setup_level_select(void) 
{
	select_active=1;
	tsound(1);
	shake_a11(8,8);
	
//	if (curback<MAX_BACKGROUNDS)
//		pds_centered(background_names[curback],SCX(0xc8),SCY(0xec)+22);
	
	process_suicide();
}

void setup_special_endur(void) 
{
	f_special_endur=1;
	tsound(0x7d);
	
	shake_a11(7,6);
	
	process_suicide();
}

/******************************************************************************
 Function: void join_in_during_psel(WORD *pstate)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pstate - player state of controler that joined in

 Returns: None

 Description:	Other player jumps in during play select, setup him up
******************************************************************************/
void join_in_during_psel(WORD *pstate)
{
	PROCESS *ptemp;
	
//	if (f_fighter_load==0)				// dont allow join in until scaled up
//		process_suicide();

	while (move_sel_now==0)
		process_sleep(1);

	tsound(0x93);				// join in sound 

	*pstate=PS_PSEL;

	ptemp=exprc_er(PID_MASTER);		// find central controller

	/* Note: this routine finds the PID_MASTER process that is already started.  We are modifying the arcade source to
			 make this possible from C.  Instead of reseting the stack and changing the wakeup/return address we will
			 set the p_comp_flag.  The PID_MASTER will recoginize this flag and call player_joinin.
	*/
	ptemp->a6=1;

	player_joinin();
	
	process_suicide();
}

#define MUG1_X	(SCX(0x1f)+27+6)
#define MUG1_Y	(SCY(0x1b)-8)

#define XY_SCALE_STEP	32.0	//32.0
#define XY_SCALE_SIZE	0x0100
#define XY_SCALE_START	0x0340

#define X_SPACE	((34<<8)/(XY_SCALE_SIZE))
#define Y_SPACE	((45<<8)/(XY_SCALE_SIZE))
	  
MUGS mug_shot_table[]=
{
	{(OIMGTBL *)HDNOOB,0,0,FT_NOOB},
	{(OIMGTBL *)HDBARAKA,1,0,FT_BARAKA},
	{(OIMGTBL *)HDCAGE,2,0,FT_JCAGE},
	{(OIMGTBL *)HDSONYA,3,0,FT_SONYA},
	{(OIMGTBL *)HDRAYDEN,4,0,FT_RAYDEN},
	{(OIMGTBL *)HDRAIN,5,0,FT_RAIN},

	{(OIMGTBL *)HDMUSTARD,0,1,FT_ROBO2},
	{(OIMGTBL *)HDSCORPION,1,1,FT_SCORPION},
	{(OIMGTBL *)1,2,1,FT_OLDSMOKE},

	{(OIMGTBL *)2,3,1,FT_KAMEL},
	
	{(OIMGTBL *)HDREPTILE,4,1,FT_REPTILE},

	{(OIMGTBL *)HDJAX,5,1,FT_JAX},

	{(OIMGTBL *)HDKETCHUP,0,2,FT_ROBO1},
	{(OIMGTBL *)HDLIUKANG,1,2,FT_LK},
	{(OIMGTBL *)HDJADE,2,2,FT_JADE},
	{(OIMGTBL *)HDSHEGORO,3,2,FT_SG},
	{(OIMGTBL *)HDLAO,4,2,FT_LAO},
	{(OIMGTBL *)HDSMOKE,5,2,FT_SMOKE},
	
	{(OIMGTBL *)HDINDIAN,0,3,FT_INDIAN},
	{(OIMGTBL *)HDBRIDE,1,3,FT_LIA},
	{(OIMGTBL *)HDERMAC,2,3,FT_ERMAC},
	{(OIMGTBL *)HDCLASSUB,3,3,FT_OLDSZ},
	{(OIMGTBL *)HDSWAT,4,3,FT_SWAT},
	{(OIMGTBL *)HDTUSKAN,5,3,FT_TUSK},
	
	{(OIMGTBL *)HDKITANA,1,4,FT_KITANA},
	{(OIMGTBL *)HDKANO,2,4,FT_KANO},
	{(OIMGTBL *)HDSHANG,3,4,FT_ST},
	{(OIMGTBL *)HDMILEENA,4,4,FT_MILEENA},
	
	{NULL},
};

void *hidden_info[]=
{
	HDOSM,	// 0 = mug shot
	&f_oldsm,	// 1 = flag to obey
	HDKAMEL,
	&f_kamel,
};
	  
PDDATA p1_cdata=
{
	1,					// 0
	fl_cursor1,		// 1
	(WORD *)&swcurr.u.p1pad,		// 2
	&p1_char,			// 3
	&p2_char,			// 4
	psel_drone,		// 5
	mug_shot_table,		// 6
	M_P1ACTION,		// 7

	bpal_flash1_P,		// 0
	OID_CURSOR1,		// 1
	0x0d,			// 2
	PID_P1,			// 3
	0x31-4,			// 4
	1,
	-22+12,
};


PDDATA p2_cdata=
{
	2,		   	// 0
	fl_cursor2,			   	// 1
	(WORD *)&swcurr.u.p2pad,			   	// 2
	&p2_char,				   	// 3
	&p1_char,				   	// 4
	psel_drone,			   	// 5
	mug_shot_table+5,	// 6
	M_P2ACTION,				// 7

	bpal_flash2_P,				// 0
	OID_CURSOR2,				// 1
	0x22,				// 2
	PID_P2,					// 3
	SCRRGT-0x33+7,				// 4
	1,
	-22+12,
};

PDDATA p1_cteam=
{
	1,		// 0
	fl_cursor1,		// 1
	(WORD *)&swcurr.u.p1pad,			   	// 2
	&p1_char,			// 3
	&p2_char,			// 4
	psel_drone,		// 5
	mug_shot_table,		// 6
	M_P1ACTION,		// 7

	bpal_flash1_P,		// 0
	OID_CURSOR1,		// 1
	0x0d,			// 2
	PID_P1,			// 3
	0x28-4,			// 4 - world x offset
	0x10, 			// 5 - z position of drone
	-22+13,
};

PDDATA p2_cteam=
{
	2,			   	// 0
	fl_cursor2,			   	// 1
	(WORD *)&swcurr.u.p1pad,			   	// 2
	&p2_char,				   	// 3
	&p1_char,				   	// 4
	psel_drone,			   	// 5
	mug_shot_table+(1),	// 6
	M_P1ACTION,				// 7

	bpal_flash2_P,				// 0
	OID_CURSOR2,				// 1
	0x0d,					// 2
	PID_P2,					// 3
	0x3c-4,					// 4 - world x offset
	0x08,					// 5 - z position of drone
	-24+13,
};

PDDATA p3_cteam=
{
	3,				// 0
	fl_cursor3,			   	// 1
	(WORD *)&swcurr.u.p2pad,			   	// 2
	&p3_char,				   	// 3
	&p1_char,				   	// 4
	psel_drone,			   	// 5
	mug_shot_table+(5),	// 6
	M_P2ACTION,				// 7

	bpal_flash3_P,				// 0
	OID_CURSOR3,				// 1
	0x22,					// 2
	PID_P3,					// 3
	SCRRGT-0x28+0,   				// 4 - world x offset
	0x10,				// 5 - z position of drone
	-22+13,
};

PDDATA p4_cteam=
{
	4,		   	// 0
	fl_cursor4,			   	// 1
	(WORD *)&swcurr.u.p2pad,			   	// 2
	&p4_char,				   	// 3
	&p1_char,			   	// 4
	psel_drone,			   	// 5
	mug_shot_table+(4),	// 6
	M_P2ACTION,				// 7

	bpal_flash4_P,				// 0
	OID_CURSOR4,				// 1
	0x22,					// 2
	PID_P4,					// 3
	SCRRGT-0x3c+0,   				// 4 - world x offset
	0x08,					// 5 - z position of drone
	-24+13,
};

PDDATA p5_cteam=
{
	5,			   	// 0
	fl_cursor5,			   	// 1
	(WORD *)&swcurr.u.p1pad,			   	// 2
	&p5_char,				   	// 3
	&p1_char,				   	// 4
	psel_drone,			   	// 5
	mug_shot_table+(2),	// 6
	M_P1ACTION,				// 7

	bpal_flash6_P,				// 0
	OID_CURSOR5,				// 1
	0x0d,					// 2
	PID_P5,					// 3
	0x3c-4+14,					// 4 - world x offset
	0x00,					// 5 - z position of drone
	-24+13,
};

PDDATA p6_cteam=
{
	6,		   	// 0
	fl_cursor6,			   	// 1
	(WORD *)&swcurr.u.p2pad,			   	// 2
	&p6_char,				   	// 3
	&p1_char,			   	// 4
	psel_drone,			   	// 5
	mug_shot_table+(3),	// 6
	M_P2ACTION,				// 7

	bpal_flash7_P,				// 0
	OID_CURSOR6,				// 1
	0x22,					// 2
	PID_P6,					// 3
	SCRRGT-0x3c-14,   				// 4 - world x offset
	0x00,					// 5 - z position of drone
	-24+13,
};


extern char txt_curback_subway[];
extern char txt_curback_street[];
extern char txt_curback_hidden[];
extern char txt_curback_ktower[];
extern char txt_curback_bridge[];
extern char txt_curback_soul[];
extern char txt_curback_bell[];
extern char txt_curback_temple[];
extern char txt_curback_grave[];
extern char txt_curback_pit3[];
extern char txt_curback_mk2pit[];
extern char txt_curback_mk2pitstar[];
extern char txt_curback_lost[];
extern char txt_curback_kung2[];
extern char txt_curback_kung5[];
extern char txt_curback_kung5bot[];
extern char txt_curback_desert[];
extern char txt_curback_kkave[];
extern char txt_curback_hell[];
extern char txt_curback_river[];
extern char txt_curback_deadpool[];
extern char txt_curback_battle[];
extern char txt_curback_city[];
extern char txt_curback_armory[];
extern char txt_curback_forest[];
extern char txt_curback_tower[];
extern char txt_curback_monk[];
extern char txt_curback_lair[];
extern char txt_curback_tomb[];
char txt_select_back[]="SELECT KOMBAT ZONE";
char *background_names[]=
{
	txt_curback_subway,
	txt_curback_street,
	txt_curback_kung2,
	txt_curback_kung5,
	txt_curback_ktower,
	txt_curback_bridge,
	txt_curback_soul,
	txt_curback_bell,
	txt_curback_temple,
	txt_curback_grave,
	txt_curback_pit3,
	txt_curback_river,
	txt_curback_hell,
	txt_curback_kkave,
	txt_curback_desert,
	txt_curback_lost,
	txt_curback_hidden,
	txt_curback_deadpool,
	txt_curback_battle,
	txt_curback_city,
	txt_curback_armory,
	txt_curback_forest,
	txt_curback_tower,
	txt_curback_monk,
	txt_curback_lair,
	txt_curback_tomb,
	txt_curback_mk2pit,
	txt_curback_mk2pitstar,
	txt_curback_kung5bot,
};

#if 0
char txt_select_msg[]="SELECT YOUR FIGHTER";
char txt_select_team[]="SELECT YOUR TEAMS";
char txt_select_tour[]="TOURNAMENT KOMBAT";
#endif
/******************************************************************************
 Function: void player_select(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: ptr to map to use

 Description:	player select screen setup
******************************************************************************/
#define X_CENTER 	3
#define Y_CENTER	3

short stbl[][2]=
{
	{57-160,14-110},
	{91-160,14-110},
	{125-160,14-110},
	{159-160,14-110},
	{193-160,14-110},
	{227-160,14-110},
	
	{57-160,59-110},
	{91-160,59-110},
	{125-160,59-110},
	{159-160,59-110},
	{193-160,59-110},
	{227-160,59-110},
	
	{57-160,104-110},
	{91-160,104-110},
	{125-160,104-110},
	{159-160,104-110},
	{193-160,104-110},
	{227-160,104-110},
	
	{57-160,149-110},
	{91-160,149-110},
	{125-160,149-110},
	{159-160,149-110},
	{193-160,149-110},
	{227-160,149-110},
	
	{91-160,194-110},
	{125-160,194-110},
	{159-160,194-110},
	{193-160,194-110},
};

void scale_mugs(void) 
{
	int h,index;
	int centerx,centery;
	float t;
	OBJECT *obj;
	short scx,scy;			// new scale size
	short scw,sch;			// new scale width/height
	float fudge;

	tsound(0x98);
	
	centerx=MUG1_X+(X_SPACE*X_CENTER);
	centery=MUG1_Y+(Y_SPACE*Y_CENTER)+Y_SPACE/2;
	
	for (h=0;h<=XY_SCALE_STEP;h++)
	{
		obj=(OBJECT *)current_proc->pdata.p_store1;
	
		/* calc new scale size and dim of boxes */
		t=h/XY_SCALE_STEP;
		
		scx=(short)((float)XY_SCALE_START+t*(XY_SCALE_SIZE-XY_SCALE_START));
		scy=(short)((float)XY_SCALE_START+t*(XY_SCALE_SIZE-XY_SCALE_START));
		
		scw=(obj->header.t_width<<8)/scx;
		sch=(obj->header.t_height<<8)/scy;
		while (obj!=NULL)
		{
			clear_inviso(obj);
			
			index=a0_ochar_to_position(obj->ochar);
			
			obj->oscale.u.xpos=scx;
			obj->oscale.u.ypos=scy;
			
//			obj->oxpos.u.intpos=centerx+(mug_shot_table[index].m_xpos-X_CENTER)*scw;//-((float)(X_SPACE/2))*t;
//			obj->oypos.u.intpos=110+(centery-110)*t+(mug_shot_table[index].m_ypos-Y_CENTER)*sch-((float)(Y_SPACE/2))*t;

			obj->oxpos.u.intpos=160+(short)(((float)(stbl[index][0]<<16)/(float)scx)/256);

			if ((int)t==1) 
				obj->oypos.u.intpos=110+(short)((float)(((stbl[index][1])<<16)/(float)scy)/256);	//-(stbl[index][1]-stbl[index][1]*t);
			else obj->oypos.u.intpos=110+(short)((float)(((stbl[index][1]+2)<<16)/(float)scy)/256);	//-(stbl[index][1]-stbl[index][1]*t);
			
			/* next mug */
			obj=(OBJECT *)obj->oslink;
		}

		process_sleep(1);
	}
	
	return;
}

void move_diazs(void) 
{
	OBJECT *d1,*d2;
	int d1x,d2x;

	d1=baklst2;
	d2=baklst3;
	
	d1x=d1->oxpos.u.intpos;
	d2x=d2->oxpos.u.intpos;
	
	d1->oxpos.u.intpos-=76;
	d2->oxpos.u.intpos+=76;
	
	while (move_sel_now==0)
	{
		process_sleep(1);
	}
	
	while (d1->oxpos.u.intpos<d1x)
	{
		process_sleep(1);
		d1->oxpos.pos+=(0x30000);
		d2->oxpos.pos-=(0x30000);
	}
	
	process_suicide();
}

WORD line_table[][4]=
{

	{MUG1_X+34*0,MUG1_Y+45*0,34*6,1},
	{MUG1_X+34*0,MUG1_Y+45*1,34*6,1},
	{MUG1_X+34*0,MUG1_Y+45*2,34*6,1},
	{MUG1_X+34*0,MUG1_Y+45*3,34*6,1},
	{MUG1_X+34*0,MUG1_Y+45*4,34*6,1},
	{MUG1_X+34*1,MUG1_Y+45*5,34*4,1},
	{MUG1_X+34*1,MUG1_Y+45*6,34*4,1},
	
	{MUG1_X+34*0,MUG1_Y+45*0,1,45*4},
	{MUG1_X+34*1,MUG1_Y+45*0,1,45*5},
	{MUG1_X+34*2,MUG1_Y+45*0,1,45*5},
	{MUG1_X+34*3,MUG1_Y+45*0,1,45*5},
	{MUG1_X+34*4,MUG1_Y+45*0,1,45*5},
	{MUG1_X+34*5,MUG1_Y+45*0,1,45*5},
	{MUG1_X+34*6,MUG1_Y+45*0,1,45*4},
	
};

extern OBJECT *draw_logo(void);
void player_select(void)
{
	MUGS *mptr;
	OBJECT *obj;
	ADDRESS mug;
	XYTYPE ta9;
	long cx,cy;

	murder_myoinit();
	
	f_speech=0;
	select_active=0;			// no select level available, yet
	f_doscore=0;				// dont display score
	f_fighter_load=0;			// fighter data not loaded yet

	init_player_variables();
	
	clear_buckets();
	
	send_code_a3(0);

	load_bkgd=BKGD_MK3_PSEL;
	init_background_module(psel_module);
	multi_plane();

	CREATE(PID_BANI,move_diazs);
	move_sel_now=0;

	f_start=0;					// flag: dont fight !!
	p1_char=p2_char=p3_char=p4_char=0xffff;			// null the characters
	
	sound_music_start(MUSIC_SELECTSC);
	
	/* display logo and scale down */
	obj=draw_logo();
	tsound(0x29);
	
	process_sleep(8+24);
//	tsound(0x97);
	
	cx=obj->oxpos.pos+(obj->header.t_width<<16)/2;
	cy=obj->oypos.pos+(obj->header.t_height<<16)/2;
	
	ta9.yx=0x01000100;
	
	do
	{
		process_sleep(1);

		ta9.u.xpos+=0x0030;
		ta9.u.ypos+=0x0030;

		obj->oxpos.pos=cx-(((obj->header.t_width<<8)/ta9.u.xpos)<<16)/2;
		obj->oypos.pos=cy-(((obj->header.t_height<<8)/ta9.u.ypos)<<16)/2;

		obj->oscale.yx=ta9.yx;
	}
	while(ta9.u.ypos<0x0500);
	
	delobjp(obj);

	process_sleep(1);
	
	/* load mugshot data */
	special_fx_load(FX_MUGS_LOAD);
	spec_fx=FX_NO_LOAD;

	/* display mugshots */
	mptr=mug_shot_table;
	(OBJECT *)current_proc->pa9=obj_free;
	(OBJECT *)current_proc->pdata.p_store1=obj_free;		// last object save here

	/* psel3 */
	while (mptr->m_mug!=NULL)
	{
		mug=mptr->m_mug;
		
		if (mug<3)
		{
			if (*((WORD *)hidden_info[(mug-1)*2+1])==1)
				mug=(ADDRESS)hidden_info[(mug-1)*2];
			else mug=(ADDRESS)BOX_01;
		}

		/* psel_hidden */
		gso_dmawnz_ns(obj,mug,0,0,PFLAG_CLEAR);
		(OBJECT *)((OBJECT *)current_proc->pa9)->oslink=obj;			// link mugs together
		((OBJECT *)current_proc->pa9)=obj;
		set_xy_coordinates(obj,mptr->m_xpos,mptr->m_ypos);
		(void *)obj->oshape=(void  *)((LONG)(mptr->m_char));				// char id

		alloc_cache((OIMGTBL *)mug,0,obj);
		obj->ochar=mptr->m_char;
		
		set_inviso(obj);
		insert_object(obj,&baklst4);

		mptr++;
	}

	/* psel2 */
	obj->oslink=NULL;					// last object = 0 list

	/* psela */
#if SELECT_OLD	
	switch (mode_of_play)
	{
		case 0:
			p15_centered(txt_select_msg,SCX(0xc8),SCY(0xb)+8);
			break;
		case 1:
		case 4:
			p15_centered(txt_select_team,SCX(0xc8),SCY(0xb)+8);
			break;
		case 2:
			p15_centered(txt_select_tour,SCX(0xc8),SCY(0xb)+8);
			break;
	}
#endif
	move_sel_now=1;
	
	create_cursor_procs();
	
	scale_mugs();
	
	/* draw grey line border */
	for (cx=0;cx<14;cx++ )
	{
		obj=make_solid_object(0x7bdb,line_table[cx][2],line_table[cx][3]);
		obj->oxpos.u.intpos=line_table[cx][0];
		obj->oypos.u.intpos=line_table[cx][1];
		obj->ozval=1000;
		insert_object(obj,&baklst4);
	}

	current_proc->a6=0;
	psel6();
	move_sel_now=0;
	return;
}

/******************************************************************************
 Function: void player_joinin(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	player select 2nd player joinin setup
******************************************************************************/
void player_joinin(void)
{
	create_cursor_procs();
//**********************************************
//psel6(); ARCADE MOD: Since this is called from PSEL6 we only want to return, see note in PSEL6
//**********************************************

	return;
}

/******************************************************************************
 Function: void psel6(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	player select main common routine, moves currsor, etc
******************************************************************************/
void psel6(void)
{
	/* psel6 */
	current_proc->a11=(mode_of_play==0) ?0x40*5 :0x40*15;
	current_proc->p_comp_flag=PC_CLEAR;				// mod from arcade, will be used to sinify if player joined in
	f_fighter_load=1;
	
	/* psel5 */
	while (exprc(PID_P1SEL)!=NULL || exprc(PID_P2SEL)!=NULL || exprc(PID_P3SEL)!=NULL || exprc(PID_P4SEL)!=NULL|| exprc(PID_P5SEL)!=NULL || exprc(PID_P6SEL)!=NULL)
	{
		current_proc->p_comp_flag=PC_PSEL_WAIT;
		process_sleep(3);

		/* NOTE: this is a mod from the arcade.  The arcade changes the stack and return address of this
				 process when it is sleeping if another player joins in.  We cannont due this easily in C
				 so we will use the p_comp_flag.  If it is set then we will call the player_joinin routine.
				 This will make everything ok.
		*/
		if (current_proc->a6==1)
		{
			current_proc->p_comp_flag=PC_CLEAR;
			current_proc->a11=0x40*5;
			current_proc->a6=0;
			player_joinin();
		}

		/* waiting_for_psel */
		if (--current_proc->a11==0)
		{
			/* psel9 */
			force_psel_choice(PID_P1SEL);		// timeout, force choice now
			force_psel_choice(PID_P2SEL);
			force_psel_choice(PID_P3SEL);
			force_psel_choice(PID_P4SEL);
			force_psel_choice(PID_P5SEL);
			force_psel_choice(PID_P6SEL);
			break;
		}
	}

	/* psel4 */
	gstate=GS_POST_PSEL;					// game state: post player select
	process_sleep(0x1c);

	p1_state=((short)p1_char!=-1) ? PS_ACTIVE:0;		// activate dudes

	p2_state=((short)p2_char!=-1) ? PS_ACTIVE:0;

	process_sleep(0x20);

	dallobj(OID_CURSOR1);
	dallobj(OID_CURSOR2);					// delete cursor objects

	/* secret cheat code activation */
	if (f_level_select || select_active==1)
		select_background();
	else process_sleep(0x30);
	
	process_sleep(0x20);

	dallobj(OID_TEXT);			// remove old text
	MURDER;

	wess_seq_stopall();			// kill looping sound effects
	return;
}

void clip_psel_box(WORD pa0,OBJECT *obj)
{
	obj->oflags|=M_CLIP;
	obj->ofset=0x500;
	obj->header.t_height-=5;
	return;
}

/******************************************************************************
 Function: void create_cursor_procs(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description: create a cursor proc for any player who is in the game.
******************************************************************************/
void create_cursor_procs(void)
{
	switch (mode_of_play)
	{
		case 2:			// cursor_tournament
			p1_state=p2_state=PS_ACTIVE;
		case 0:			// cursor_1_on_1
			create_psel_proc(PID_P1SEL,0,&p1_state,&p1_cdata,player_select_proc);
			create_psel_proc(PID_P2SEL,1,&p2_state,&p2_cdata,player_select_proc);
			break;
		case 1:			// cursor_2_on_2
			p1_state=p2_state=PS_ACTIVE;
			create_psel_proc(PID_P1SEL,0,&p1_state,&p1_cteam,player_select_proc);
			create_psel_proc(PID_P2SEL,0,&p1_state,&p2_cteam,player_select_proc);
			create_psel_proc(PID_P3SEL,1,&p2_state,&p3_cteam,player_select_proc);
			create_psel_proc(PID_P4SEL,1,&p2_state,&p4_cteam,player_select_proc);
			break;
		case 4:			// cursor_3_on_3
			p1_state=p2_state=PS_ACTIVE;
			create_psel_proc(PID_P1SEL,0,&p1_state,&p1_cteam,player_select_proc);
			create_psel_proc(PID_P2SEL,0,&p1_state,&p2_cteam,player_select_proc);
			create_psel_proc(PID_P5SEL,0,&p1_state,&p5_cteam,player_select_proc);
			create_psel_proc(PID_P3SEL,1,&p2_state,&p3_cteam,player_select_proc);
			create_psel_proc(PID_P4SEL,1,&p2_state,&p4_cteam,player_select_proc);
			create_psel_proc(PID_P6SEL,1,&p2_state,&p6_cteam,player_select_proc);
			break;
	}

	return;
}

void create_psel_proc(WORD pa0,WORD pa4,WORD *pa5,PDDATA *pa6,FUNC pa7)
{
	PROCESS *ta0;

	if (*pa5==PS_PSEL)
		goto CPP2;

	if (*pa5==PS_ACTIVE) 
		*pa5=PS_PSEL;
	else goto CPP3;

CPP2:
	ta0=create_if_gone(pa0,pa7);
	if (ta0!=NULL) 
	{
		ta0->pdata.p_store8=(ADDRESS)pa6;
		ta0->pdata.p_hit=pa4;
	}

CPP3:
	return;

}

/******************************************************************************
 Function: void force_psel_choice(WORD pid)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pid - id of process to force to choose

 Returns: None

 Description: force process id to pick a player
******************************************************************************/
void force_psel_choice(WORD pid)
{
	PROCESS *ptemp;

	if ((ptemp=exprc(pid))!=NULL)
		fastxfer(ptemp,cmove9);

	return;
}



/******************************************************************************
 Function: void player_select_proc()

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description: player 1 select
******************************************************************************/
WORD upsans[]={0,1,2,3,4,5,0xffff};
WORD dnsans[]={18,23,24,25,26,27,0xffff};
WORD lfsans[]={0,6,12,18,24,0xffff};
WORD rtsans[]={5,11,17,23,27,0xffff};

WORD up_change[]=
{
	0 ,		// 0 -
	1 ,		// 1 -
	2 ,		// 2 -
	3 ,		// 3 -
	4 ,		// 4 -
	5 ,		// 5 -
	
	0 ,		// 6 -
	1 ,		// 7 -
	2 ,		// 8 -
	3 ,		// 9 -
	4 ,		// 10 -
	5 ,		// 11 -
	
	6 ,		// 12 -
	7 ,		// 13 -
	8 ,		// 14 -
	9 ,		// 15 -
	10,		// 16 -
	11,		// 17 -
	
	12,		// 18 -
	13,		// 19 -
	14,		// 20 -
	15,		// 21 -
	16,		// 22 -
	17,		// 23 -
	
	19,		// 24 -
	20,		// 25 -
	21,		// 26 -
	22,		// 27 -
};

WORD down_change[]=
{
	6 ,	        // 0 -
	7 ,		// 1 -
    8 ,			// 2 -
	9 ,		// 3 -
	10,		// 4 -
	11,		// 5 -
	
	12,		// 6 -
	13,		// 7 -
	14,		// 8 -
	15,		// 9 -
	16,		// 10 -
	17,		// 11 -
	
	18,		// 12 -
	19,		// 13 -
	20,		// 14 -
	21,		// 15 -
	22,		// 16 -
	23,		// 17 -
	
	18,		// 18 -
	24,		// 19 -
	25,		// 20 -
	26,		// 21 -
	27,		// 22 -
	23,		// 23 -
	
	24,		// 24 -
	25,		// 25 -
	26,		// 26 -
	27,		// 27 -
};

WORD left_change[]=
{
	0 ,	    // 0 -
	0 ,		// 1 -
    1 ,		// 2 -
	2 ,		// 3 -
	3 ,		// 4 -
	4 ,		// 5 -
	
	6 ,		// 6 -
	6 ,		// 7 -
	7 ,		// 8 -
	8 ,		// 9 -
	9 ,		// 10 -
	10,		// 11 -
	
	12,		// 12 -
	12,		// 13 -
	13,		// 14 -
	14,		// 15 -
	15,		// 16 -
	16,		// 17 -
	
	18,		// 18 -
	18,		// 19 -
	19,		// 20 -
	20,		// 21 -
	21,		// 22 -
	22,		// 23 -
	
	24,		// 24 -
	24,		// 25 -
	25,		// 26 -
	26,		// 27 -
};

WORD right_change[]=
{
	1 ,	        // 0 -
	2 ,		// 1 -
    3 ,		// 2 -
	4 ,		// 3 -
	5 ,		// 4 -
	5 ,		// 5 -
	
	7 ,		// 6 -
	8 ,		// 7 -
	9 ,		// 8 -
	10,		// 9 -
	11,		// 10 -
	11,		// 11 -
	
	13,		// 12 -
	14,		// 13 -
	15,		// 14 -
	16,		// 15 -
	17,		// 16 -
	17,		// 17 -
	
	19,		// 18 -
	20,		// 19 -
	21,		// 20 -
	22,		// 21 -
	23,		// 22 -
	23,		// 23 -
	
	25,		// 24 -
	26,		// 25 -
	27,		// 26 -
	27,		// 27 -
};

void player_select_proc(void)
{
	PROCESS *ptemp;
	PDDATA *pa0;

	pa0=(PDDATA*)current_proc->pdata.p_store8;
	ptemp=CREATE(pa0->pd_pid,pa0->pd_func);
	current_proc->pdata.p_store7=(ADDRESS)ptemp;
	ptemp->pdata.p_store8=(ADDRESS)pa0;

	current_proc->pdata.p_joyport=pa0->pd_joy;			// look at p1 controls

	(WORD *)(current_proc->pdata.p_mychar)=pa0->pd_p1char;	// pointer to my char
	(WORD *)(current_proc->pdata.p_hischar)=pa0->pd_p2char;	// pointer to his char


	ptemp=CREATE(PID_FX,boonpal_stuff);
	ptemp->a11=(ADDRESS)pa0->pd_fldata;						// flash letters
	(PROCESS *)current_proc->pdata.p_store2=ptemp;		// save cursor flash

	current_proc->pdata.p_dronevar1=ptemp;		// record flasher process so we can kill it later
	
	stuff_number_shape(current_proc->pdata.p_hit);

	stack_jump(curs2);
}

extern WORD f_white;
extern BYTE select_dict[];
extern BYTE font_dict[];
extern BYTE sdragon_dict[];


void appear_cursor(void)
{
	OBJECT *clrlst;
	
	while (f_fighter_load==0)
		process_sleep(1);
	
	clrlst=(OBJECT *)&baklst4;
	while (clrlst->olink!=NULL)
	{
		clrlst=clrlst->olink;
		if (clrlst->oid==current_proc->pdata.p_store4)
			clear_inviso(clrlst);
	}	
}

void curs2(void)
{
	OBJECT *obj;
	WORD jpad;
	PDDATA *pa0;
	MUGS *pa4;
	OIMGTBL *fptr;
	OBJECT *clrlst;

	pa0=(PDDATA*)current_proc->pdata.p_store8;
	pa4=pa0->pd_mug;

	/* curs2 */
	current_proc->pdata.p_store4=pa0->pd_oid;
	*((WORD *)current_proc->pdata.p_mychar)=pa4->m_char;

	(OBJECT *)current_proc->pa9=obj_free;
	(OBJECT *)current_proc->a10=obj_free;

	/* curs4 */
	obj=get_single_obj((LONG)NSCURSOR,select_dict,0,pa0->pd_pal,1);
	alloc_cache(NSCURSOR,0,obj);
	obj->oscale.u.xpos=XY_SCALE_SIZE;
	obj->oscale.u.ypos=XY_SCALE_SIZE;
	
	obj->oid=current_proc->pdata.p_store4;			// set oid of cur
	(OBJECT *)(((OBJECT *)current_proc->pa9)->oslink)=obj;		// link cursor

	obj->oxpos.u.intpos=MUG1_X+pa4->m_xpos*X_SPACE;
	obj->oypos.u.intpos=MUG1_Y+pa4->m_ypos*Y_SPACE;
	obj->ozval=5555;

	insert_object(obj,&baklst4);

	(OBJECT *)current_proc->pa9=obj;

	/* now do the player # indicator part of the cursor */
	if ((obj=get_object())==NULL)
		ermac(5);
	obj->osize.yx=0x000a000a;

	obj->opal=get_fore_pal(WHITE_p);

	obj->oid=current_proc->pdata.p_store4;
	obj->ozval=3;

	/* load correct number */
	fptr=*(font_lists[FONT_15]+(WORD)'0'-0x21+(LONG)current_proc->pdata.p_cursor_num);
	
	current_proc->a5=pa0->pd_y-6;
	obj->oheap=0;			
	obj->odict=font_dict;
	obj->osag=fptr;			
	obj->oimg=(LONG)fptr;	

	/* curs5, setup object for display */
	current_proc->pa8=obj;
	animate(SINGLE_ANI0,fptr,obj->oflags);

	(OBJECT *)((OBJECT *)(current_proc->pa9))->oslink=obj;

	/* set coords */
	obj->oxpos.u.intpos=MUG1_X+pa4->m_xpos*X_SPACE+12;
	obj->oypos.u.intpos=MUG1_Y+pa4->m_ypos*Y_SPACE+current_proc->a5;

	insert_object(obj,&baklst4);

	obj->oslink=NULL;
	current_proc->pa8=obj=(OBJECT *)current_proc->a10;				// a8 =1st object of cursor

	clrlst=(OBJECT *)&baklst4;
	while (clrlst->olink!=NULL)
	{
		clrlst=clrlst->olink;
		if (clrlst->oid==current_proc->pdata.p_store4)
			set_inviso(clrlst);
	}
	
	/* wait until other cursor done to continue */
	switch (mode_of_play)
	{
		case 1:
		case 4:
			current_proc->a10=0xffff;
			if (current_proc->procid==PID_P2SEL)
				current_proc->a10=PID_P1SEL;

			if (current_proc->procid==PID_P5SEL)
				current_proc->a10=PID_P2SEL;

			if (current_proc->procid==PID_P4SEL)
				current_proc->a10=PID_P3SEL;

			if (current_proc->procid==PID_P6SEL)
				current_proc->a10=PID_P4SEL;

			if (current_proc->a10!=0xffff) 
			{
				appear_cursor();
				
				do
				{
					process_sleep(1);
				}
				while(process_exist(current_proc->a10,0xffff)!=NULL);
			}
			else
			{
				appear_cursor();
			}
			break;
		default:
			appear_cursor();
			break;
	}
	
	/*********************************/
	/* cmove2, scan joystick buttons */
	/*********************************/
	process_sleep(0x20);
	current_proc->a10=0;			// joy debounce

	/* cmove3 */
	while (TRUE)
	{
		current_proc->p_comp_flag=PC_CURSOR_LOOP;
		process_sleep(1);
		current_proc->p_comp_flag=PC_CLEAR;

		/* psel_cursor_loop */
		if (current_proc->a10!=0)
			current_proc->a10--;

		/* cmove4 */
		if (current_proc->procid==PID_P1SEL)
		{
			if ((*current_proc->pdata.p_joyport) & pa0->pd_action)
			{
				cmove9();
			}
		}
		else
		{
			if ((*current_proc->pdata.p_joyport) & pa0->pd_action)
			{
				cmove9();
			}
		}

		/* cmove41 */
		if ((jpad=JOYSTICK_IN_A0(current_proc))!=0 && current_proc->a10==0) 	// any joy movement and debounce speed
		{
			if (mode_of_play==1 || mode_of_play==4)
				current_proc->a10=10;					// debounce speed
			else current_proc->a10=12;					// debounce speed
			
			current_proc->a1=*((WORD *)(current_proc->pdata.p_mychar));	// get current ochar
			
			/* special enable level select */
			if ((jpad & MASK_JUP) && (jpad & MASK_START) && select_active==0 && a0_ochar_to_position(FT_SONYA)==a0_ochar_to_position(current_proc->a1)) 
			{
				select_active=1;
				CREATE(PID_FLASHER,setup_level_select);
			}

			if ((jpad & MASK_JDOWN) && (jpad & MASK_START) && f_special_endur==0 && a0_ochar_to_position(FT_KANO)==a0_ochar_to_position(current_proc->a1)) 
			{
				CREATE(PID_FLASHER,setup_special_endur);
			}

			/* joystick up */
			if ((jpad & MASK_JUP) && is_move_legal(upsans)==SYSTEM_CARRY_SET)
			{
				new_cursor_position(up_change,0,-Y_SPACE,0);
			}
			else
			{
				/* joystick down */
				if ((jpad & MASK_JDOWN) && is_move_legal(dnsans)==SYSTEM_CARRY_SET)
				{
					new_cursor_position(down_change,0,Y_SPACE,0);
				}
				else
				{
					/* joystick left */
					if ((jpad & MASK_JLEFT) && is_move_legal(lfsans)==SYSTEM_CARRY_SET)
					{
						new_cursor_position(left_change,-X_SPACE,0,0);
					}
					else
					{
						/* joystick right */
						if ((jpad & MASK_JRIGHT) && is_move_legal(rtsans)==SYSTEM_CARRY_SET)
						{
							new_cursor_position(right_change,X_SPACE,0,0);
						}
					}
				}
			}
		}
	}
}

extern WORD DREDQ_P[];
extern WORD HDOSM2_P[];
extern WORD HDKAMEL2_P[];

void *ochar_picked_palettes[]=
{
	HDKANOD_P,
	HDSOYND_P,
	HDJAXD_P,
	HDINDYD_P,
	HDCAGED_P,
	HDSWATD_P,
	HDBRDED_P,
	HDKETCD_P,
	HDMUSTD_P,
	HDLAOD_P,
	HDSANDD_P,
	HDGOROD_P,
	HDSHAGD_P,
	HDKANGD_P,
	HDSMOK_P,

	HDKITA2_P,
	HDJADE2_P,
	HDMILE2_P,

	HDSCOR2_P,
	HDREPT2_P,
	HDRMAC2_P,
	HDZERP2_P,

	HDOSM2_P,
	
	HDNOOB2_P,		
	HDRAYDEN2_P,	
	HDSA2_P,		
	HDRAIN2_P,		
	HDKAMEL2_P,		
	HDRAIN2_P,		
	HDRAIN2_P,		
	HDRAIN2_P,		
};

/******************************************************************************
 Function: void cmove9(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description: cursor select button has been pushed, lets finish it
******************************************************************************/
WORD fs_mask[]={0x01,0x02,0x04,0x08,0x10,0x20};
void cmove9(void)
{
	PROCESS *ptemp=NULL;
	PDDATA *pa0;

	(WORD *)current_proc->a2=((WORD *)current_proc->pdata.p_mychar);		// my choice
	current_proc->a0=*((WORD *)current_proc->a2);		// my choice


	if (!(f_speech & fs_mask[current_proc->procid-PID_P1SEL])) 
	{
		ptemp=CREATE(PID_SELSPEECH,select_speech);
		ptemp->a10=current_proc->a0;
		f_speech|=fs_mask[current_proc->procid-PID_P1SEL];
	}

	ptemp=exprc_er(PID_MASTER);			// a0=master process else
	current_proc->a1=ptemp->pdata.p_store1;		// a1= 1st mugshot object

	current_proc->a0=current_proc->pdata.p_store1=*((WORD *)current_proc->a2);

	current_proc->a2=current_proc->a1;
	/* cmovea */
	do
	{
		current_proc->a1=current_proc->a2;
		(void *)current_proc->a4=(void *)(((OBJECT *)current_proc->a1)->oshape);
		(void *)current_proc->a2=((OBJECT *)current_proc->a1)->oslink;
	}
	while(current_proc->a0!=current_proc->a4);

	/* cmoveb, flash the mugshot */
	current_proc->pa8=(OBJECT *)current_proc->a1;

	cursor_sound(0xc,0xd);

	/* look2 */
	pa0=(PDDATA *)current_proc->pdata.p_store8;
	current_proc->a6=*(pa0->pd_p1char);
	current_proc->a0=pa0->pd_pid;
	ptemp=exprc_er(current_proc->a0);
	
	fastxfer(ptemp,psel_victory_animation);

	/* look3 */
	current_proc->a11=6;

	/* look4 */
	do
	{
		flash_sleep(bpal_white_P);								// mod from arcade, flash white then flash normal color

		(OIMGTBL *)current_proc->a0=((OIMGTBL *)((current_proc->pa8)->oimg))+1;
		current_proc->a0=GET_LONG(current_proc->a0);
		flash_sleep((void *)current_proc->a0);		// mod from arcade, flash normal pal

	}
	while(--(current_proc->a11)>0 );

	swpal(ochar_picked_palettes[current_proc->pdata.p_store1],current_proc->pa8);		// dim down

	koc2(&baklst4,current_proc->pdata.p_store4,0xffff);                                                 // traverse object list 3

	/* kill associated flasher process */
	if (mode_of_play!=0 && mode_of_play!=2)
		process_kill(current_proc->pdata.p_dronevar1);

	switch (mode_of_play)
	{
		case 0:			// picked_1_on_1
			if (current_proc->procid==PID_P1SEL)
				p1_state=PS_POST_PSEL;
			else p2_state=PS_POST_PSEL;
			break;
		case 1:			// picked_2_on_2
			if (current_proc->procid==PID_P1SEL || current_proc->procid==PID_P3SEL)
				process_suicide();

			if (current_proc->procid==PID_P2SEL)
				p1_state=PS_POST_PSEL;

			if (current_proc->procid==PID_P4SEL)
				p2_state=PS_POST_PSEL;
			break;
		case 2:			// picked tournament
		
			f_speech&=~fs_mask[current_proc->procid-PID_P1SEL];
		
			p1_tour[(WORD)current_proc->pdata.p_hit]=*((WORD *)current_proc->pdata.p_mychar);
			current_proc->a0=current_proc->pdata.p_hit+2;
			if (current_proc->a0==8 || current_proc->a0==9)
				process_suicide();

			current_proc->pdata.p_hit=current_proc->a0;

			stuff_number_shape(current_proc->a0);

			replace_drone();

			stack_jump(curs2);
			break;
		case 4:
			if (current_proc->procid==PID_P1SEL || current_proc->procid==PID_P3SEL || current_proc->procid==PID_P5SEL || current_proc->procid==PID_P6SEL)
				process_suicide();

			if (current_proc->procid==PID_P5SEL)
				p1_state=PS_POST_PSEL;

			if (current_proc->procid==PID_P6SEL)
				p2_state=PS_POST_PSEL;
			break;
	}


	/* cmoved */
	process_suicide();
}

void stuff_number_shape(WORD pa0) 
{
	((LONG)current_proc->pdata.p_cursor_num)=pa0+1;
	return;
}
/******************************************************************************
 Function: void flash_sleep(void *pal)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pal - palette to flash

 Returns: None

 Description: flash a palette and sleep a bit
******************************************************************************/
void flash_sleep(void *pal)
{
	swpal(pal,current_proc->pa8);
	current_proc->p_comp_flag=PC_FLASH_WAKE;
	process_sleep(2);
	current_proc->p_comp_flag=PC_CLEAR;
	return;
}

/******************************************************************************
 Function: WORD is_move_legal(WORD *dirtbl)

 By: David Schwartz

 Date: Jan 1995

 Parameters: dirtbl - ptr of words to legal moves
			 current_proc->a1 - my current ochar

 Returns: SYSTEM_CARRY_SET - move is legal
		  SYSTEM_CARRY_CLR - move is not legal

 Description: determine if a joystick move is legal
******************************************************************************/
WORD is_move_legal(WORD *dirtbl)
{
	WORD ochar;
	WORD tblentry;
	
	ochar=a0_ochar_to_position(current_proc->a1);

	while (GET_WORD(dirtbl)!=0xffff)
	{
		tblentry=GET_WORD(dirtbl)++;
		
		if (tblentry==ochar)
			return(SYSTEM_CARRY_CLR);
	}

	return(SYSTEM_CARRY_SET);
}

/******************************************************************************
 Function: WORD a0_ochar_to_position(WORD ochar)

 By: David Schwartz

 Date: Jan 1995

 Parameters: ochar - character to search for

 Returns: position value in mugshot table

 Description: determine character position in mugshot table
******************************************************************************/
WORD a0_ochar_to_position(WORD ochar)
{
	short loop=-1;

	while(mug_shot_table[++loop].m_char!=ochar);

	return(loop);
}

/******************************************************************************
 Function: void new_cursor_calla(WORD *tbl,short xoff,short yoff,short autoflag)

 By: David Schwartz

 Date: Jan 1995

 Parameters: tbl - pos change tbl for new spot
			 xoff - coord delta x
			 yoff - coord delta y

 Returns: None

 Description: handle moving cursor to a new position
******************************************************************************/
void new_cursor_calla(WORD *tbl,short xoff,short yoff,short autoflag)
{
	OBJECT *obj;
	short xadj;

	current_proc->a1=*(tbl+a0_ochar_to_position(current_proc->a1));			// new position

	xadj=xoff;
	/* skip center spot */
	if (( (current_proc->a1==8 && f_oldsm==0) || (current_proc->a1==9 && f_kamel==0)) && autoflag==0) 
	{
		if (tbl==up_change)
		{
			yoff<<=1;				// double dy
			current_proc->a1-=6; // force new spot
		}
		else
		{
			if (tbl==down_change)
			{
				yoff<<=1;				// double dy
				current_proc->a1+=6; // force new spot
			}
			else
			{
				if (tbl==left_change)
				{
					xadj=xoff;
					
				   	if (current_proc->a1==9 && f_kamel==0)
				   	{
						xadj+=xoff;
						current_proc->a1--;
				   	}
				   	
					if (current_proc->a1==8 && f_oldsm==0) 
				   	{
						xadj+=xoff;
						current_proc->a1--;
				   	}
				}
				else
				{
					if (tbl==right_change)
					{
						xadj=xoff;

				   		if (current_proc->a1==8 && f_oldsm==0) 
				   		{
							xadj+=xoff;
							current_proc->a1++;
				   		}

				   		if (current_proc->a1==9 && f_kamel==0)
				   		{
							xadj+=xoff;
							current_proc->a1++;
				   		}
					}
				}
			}

		}
	}

NCP3:
	/* ncp3, position --> ochar */
	xoff=xadj;

	*((WORD *)current_proc->pdata.p_mychar)=mug_shot_table[current_proc->a1].m_char;

	cursor_sound(0xc,0xd);

	obj=current_proc->pa8;
	do
	{
		obj->oxpos.u.intpos+=xoff;
		obj->oypos.u.intpos+=yoff;
		obj=(OBJECT *)(obj->oslink);
	}
	while(obj!=NULL);

	if (current_proc->a1==8 || current_proc->a1==9)  
	{
		if (current_proc->a1==8 && f_oldsm==1)
			replace_drone();
		if (current_proc->a1==9 && f_kamel==1)
			replace_drone();
	}
	else replace_drone();
		

	return;
}

extern void remove_bucket(WORD pchar);
void replace_drone(void) 
{
	PROCESS *pa5,*pa13;

	/* replace drone */
	pa5=(PROCESS*)current_proc->pdata.p_store7;
	
	remove_bucket((pa5->pa8)->ochar);

	pa13=current_proc;
	current_proc=pa5;
	delete_slave();
	current_proc=pa13;

	process_kill((pa5->pa8)->oslink);
	delobjp(pa5->pa8);

	pa13=process_create(PID_P1,psel_drone);
	pa13->pdata.p_store8=pa5->pdata.p_store8;		// pass info to new prpc
	current_proc->pdata.p_store7=(ADDRESS)pa13;

	process_kill(pa5);

	return;
}

/******************************************************************************
 Function: void psel_drone(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description: display fighter that cursor currently on, removing any old processes in the process
******************************************************************************/
void psel_drone(void)
{
	PDDATA *pa0;
	OBJECT *obj;
	short finalx;

	pa0=(PDDATA *)current_proc->pdata.p_store8;
	current_proc->procid=pa0->pd_pid;
	current_proc->pdata.p_flags&=~(PM_SHANG|PM_KAMEL);

	obj=make_ochar_psel_guy(*(pa0->pd_p1char),SCRRGT-SCX(0x30));
	obj->ozval=pa0->pd_zval;
	obj->oxpos.u.intpos=pa0->pd_x;
	obj->oid=pa0->pd_pid;

	if (pa0->pd_joy==&swcurr.u.p2pad)
		flip_multi(obj);

	current_proc->pdata.p_slave=NULL;

	current_proc->pdata.p_otherguy=current_proc->pa8;		/* link other proc and guy to prevent bugs */
	current_proc->pdata.p_otherproc=current_proc;

	stance_setup();
	
	obj->oypos.u.intpos+=pa0->pd_yy;
	current_proc->pdata.p_ganiy=obj->oypos.u.intpos;
	next_anirate();
	
	/* slide in fighters from the wings */
	if (f_fighter_load==0) 
	{
		/* slide in fighters from the wings */
		finalx=obj->oxpos.u.intpos;
		
		if (obj->oxpos.u.intpos<(worldtlx.u.intpos+SCRRGT/2)) 
		{
			/* set off to left with + vel */
			obj->oxpos.u.intpos-=76;
			obj->oxvel.pos=0x30000;
		}
		else
		{
			/* set off to right with - vel */
			obj->oxpos.u.intpos+=76;
			obj->oxvel.pos=-(0x30000);
		}
		
		do
		{
			process_sleep(1);
			next_anirate();
			
			if (obj->oxvel.pos>0) 
			{
				if (obj->oxpos.u.intpos>=finalx)
				{
					stop_a8(obj);
					obj->oxpos.u.intpos=finalx;
					break;
				}
			}
			else
			{
				if (obj->oxpos.u.intpos<=finalx)
				{
					stop_a8(obj);
					obj->oxpos.u.intpos=finalx;
					break;
				}
			}
			
		}
		while(1);
	}
	
	/* psel_drone_loop */
	while (TRUE)
	{
		process_sleep(1);

		next_anirate();
		if (obj->oid==2)			// player 2 check pal
		{
			/* player 2 --> check if alt palette is needed */
			if ((obj->oflags2 & M_UGLY_PAL) == 0)
			{
				if (p1_char==obj->ochar) 		// player 1 same char as me ?, yes
				{
					obj->oflags2|=M_UGLY_PAL;

					/* psd9 */
					player_swpal(current_proc,character_palettes_2[obj->ochar],obj);
				}
			}
			else
			{
				/* psd8 */
				if (p1_char!=obj->ochar)		// player 1 same char as me ?, no
				{
					obj->oflags2&=(~M_UGLY_PAL);
					player_swpal(current_proc,character_palettes_1[obj->ochar],obj);
				}
			}
		}
	}
}

OBJECT *make_ochar_psel_guy(WORD pa9,short pax) 
{
	BYTE *heap;
	WORD flags;

	/* setup to use fighter 1 & 2 buffers, then alloc memory */
	flags=PFLAG_PALLOAD;
	heap=a9_ochar_frame_1(pa9,current_proc->procid-PID_P1);			// base for data
	
	if (heap==NULL)
		return(NULL);
		
	current_proc->a10=(ADDRESS)gmo_proc_special(heap,heap+256,flags);		// get obj for fake player
	(ADDRESS)(current_proc->pa8)->oslink=current_proc->a10;	// link dummy proc with obj
	(current_proc->pa8)->ochar=pa9;		// set fake players ochar
	ground_ochar();

	(current_proc->pa8)->oxpos.u.intpos=worldtlx.u.intpos+pax;		// world x offset

	current_proc->pdata.p_flags|=PM_ALT_PAL;
	
	player_normpal();
	
	insert_object(current_proc->pa8,&objlst);

	return(current_proc->pa8);
}

/******************************************************************************
 Function: void select_speech(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: current_proc->a10=fighter

 Returns: None

 Description: make a speech call for selected fighter
******************************************************************************/
void select_speech(void)
{
	PROCESS *ptemp;
	WORD seq;

	current_proc->p_comp_flag=PC_SPEECH_WAKE;
	process_sleep(8);
	current_proc->p_comp_flag=PC_CLEAR;

SELSP1:
	if ((ptemp=process_exist(PID_SELSPEECH,-1))!=0) 		// dont intrupt another process
	{
		if (ptemp->p_comp_flag!=PC_SPEECH_WAKE)
		{
			process_sleep(1);
			goto SELSP1;
		}
	}

	seq=tsound2(0x00+current_proc->a10);
//	seq=tsound2(0x32);
	process_sleep(0x8);
	
	while (wess_seq_status(seq)==SEQUENCE_PLAYING)
		process_sleep(0x1);

	process_suicide();
}

/******************************************************************************
 Function: void cursor_sound(WORD p1_snd,WORD p2_snd)

 By: David Schwartz

 Date: Feb 1995

 Parameters: p1_snd - player 1 sound
			 p2_snd - player 2 sound

 Returns: None

 Description: make a cursor sound
******************************************************************************/
void cursor_sound(WORD p1_snd,WORD p2_snd)
{
	if (current_proc->procid==PID_P1SEL)
		tsound(p1_snd);
	else tsound(p2_snd);

	return;
}

/******************************************************************************
******************************************************************************/
BYTE p1_kano[]={MVRT,MVDN,MVDN,MVRT,MVRT,MVDN,MVDN,MVLF,0};
BYTE p1_sonya[]={MVRT,MVRT,MVRT,MVRT,MVLF,0};
BYTE p1_jax[]={MVDN,MVDN,MVRT,MVRT,MVRT,MVRT,MVRT,MVUP,0};
BYTE p1_ind[]={MVDN,MVDN,MVRT,MVDN,MVLF,0};
BYTE p1_sz[]={MVRT,MVRT,MVDN,MVLF,MVLF,0};
BYTE p1_swat[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,MVDN,0};
BYTE p1_lia[]={MVRT,MVDN,MVDN,MVDN,MVDN,MVUP,0};
BYTE p1_robo1[]={MVDN,MVDN,MVRT,MVLF,MVUP,MVDN,0};
BYTE p1_robo2[]={MVDN,MVUP,MVRT,MVRT,0};
BYTE p1_lao[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,0};
BYTE p1_tusk[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,MVDN,MVRT,0};
BYTE p1_sg[]={MVDN,MVDN,MVRT,MVRT,MVRT,0};
BYTE p1_st[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,MVDN,MVDN,MVLF,0};
BYTE p1_lk[]={MVRT,MVDN,MVDN,MVLF,MVRT,0};
BYTE p1_smoke[]={MVRT,MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,0};
BYTE p1_kit[]={MVDN,MVRT,MVRT,MVRT,MVUP,MVLF,MVLF,0};
BYTE p1_jad[]={MVDN,MVDN,MVRT,MVRT,0};
BYTE p1_mil[]={MVRT,MVRT,MVDN,MVRT,MVRT,MVUP,0};
BYTE p1_scorp[]={MVRT,MVRT,MVRT,MVDN,MVLF,MVLF,0};
BYTE p1_rep[]={MVDN,MVRT,MVRT,MVRT,MVRT,0};
BYTE p1_ermac[]={MVRT,MVDN,MVDN,MVDN,MVDN,MVRT,MVUP,0};
BYTE p1_osz[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,MVDN,MVLF,0};
BYTE p1_ray[]={MVRT,MVRT,MVRT,MVRT,MVDN,MVDN,MVDN,MVDN,0};
BYTE p1_sa[]={MVRT,MVDN,MVLF,MVDN,MVDN,MVRT,MVDN,0};
BYTE p1_rain[]={MVRT,MVRT,MVRT,MVRT,MVRT,0};
BYTE p1_noob[]={MVRT,MVRT,MVDN,MVLF,MVLF,MVUP,0};
BYTE p1_osm[]={MVDN,MVDN,MVDN,MVRT,MVRT,MVUP,MVUP,0};
BYTE p1_kamel[]={MVRT,MVRT,MVRT,MVDN,MVDN,MVUP,0};

BYTE p2_kano[]={MVDN,MVDN,MVDN,MVLF,MVLF,MVLF,MVDN,0};
BYTE p2_sonya[]={MVDN,MVLF,MVUP,MVLF,0};
BYTE p2_jax[]={MVLF,MVDN,MVDN,MVRT,MVUP,0};
BYTE p2_ind[]={MVLF,MVLF,MVLF,MVLF,MVLF,MVDN,MVDN,MVDN,0};
BYTE p2_sz[]={MVDN,MVLF,MVDN,MVLF,MVLF,MVLF,MVUP,MVLF,0};
BYTE p2_swat[]={MVDN,MVDN,MVDN,MVLF,0};
BYTE p2_lia[]={MVLF,MVLF,MVLF,MVLF,MVDN,MVDN,MVDN,0};
BYTE p2_robo1[]={MVDN,MVDN,MVLF,MVLF,MVLF,MVLF,MVLF,0};
BYTE p2_robo2[]={MVLF,MVLF,MVLF,MVLF,MVRT,0};
BYTE p2_lao[]={MVLF,MVDN,MVDN,MVRT,MVLF,0};
BYTE p2_tusk[]={MVDN,MVDN,MVDN,0};
BYTE p2_sg[]={MVLF,MVLF,MVDN,MVDN,0};						 
BYTE p2_st[]={MVLF,MVDN,MVDN,MVDN,MVDN,MVLF,0};
BYTE p2_lk[]={MVLF,MVLF,MVLF,MVLF,MVDN,MVDN,0};
BYTE p2_smoke[]={MVLF,MVDN,MVDN,MVRT,MVUP,MVDN,0};
BYTE p2_kit[]={MVLF,MVDN,MVUP,MVLF,MVLF,MVLF,0};
BYTE p2_jad[]={MVLF,MVLF,MVLF,MVLF,MVDN,MVDN,MVRT,0};
BYTE p2_mil[]={MVDN,MVDN,MVUP,MVUP,MVLF,0};
BYTE p2_scorp[]={MVLF,MVLF,MVLF,MVLF,MVDN,0};
BYTE p2_rep[]={MVDN,MVDN,MVDN,MVLF,MVUP,MVUP,0};
BYTE p2_ermac[]={MVLF,MVLF,MVDN,MVDN,MVDN,MVLF,0};
BYTE p2_osz[]={MVLF,MVLF,MVDN,MVDN,MVDN,0};
BYTE p2_noob[]={MVDN,MVDN,MVLF,MVLF,MVLF,MVLF,MVLF,MVUP,MVUP,0};
BYTE p2_ray[]={MVLF,MVDN,MVDN,MVDN,MVLF,MVDN,MVRT,0};
BYTE p2_sa[]={MVDN,MVDN,MVLF,MVLF,MVDN,MVDN,MVLF,MVLF,0};
BYTE p2_rain[]={MVDN,MVLF,MVDN,MVRT,MVUP,MVUP,0};
BYTE p2_osm[]={MVDN,MVLF,MVLF,MVLF,0};
BYTE p2_kamel[]={MVLF,MVLF,MVDN,MVDN,MVUP,0};

BYTE *p1_movements[]=
{
	p1_kano,
	p1_sonya,
	p1_jax,
	p1_ind,
	p1_sz,
	p1_swat,
	p1_lia,
	p1_robo1,
	p1_robo2,
	p1_lao,
	p1_tusk,
	p1_sg,
	p1_st,
	p1_lk,
	p1_smoke,
	p1_kit,
	p1_jad,
	p1_mil,
	p1_scorp,
	p1_rep,
	p1_ermac,
	p1_osz,
	
	p1_osm,		//-oldsmoke
	p1_noob,		//noob
	p1_ray,		//rad
	p1_sa,		//sa
	p1_rain,		//rain
	p1_kamel,		// c1
	p1_osz,		// c2
	p1_osz,		// c3
	
};

BYTE *p2_movements[]=
{
	p2_kano,
	p2_sonya,
	p2_jax,
	p2_ind,
	p2_sz,
	p2_swat,
	p2_lia,
	p2_robo1,
	p2_robo2,
	p2_lao,
	p2_tusk,
	p2_sg,
	p2_st,
	p2_lk,
	p2_smoke,
	p2_kit,
	p2_jad,
	p2_mil,
	p2_scorp,
	p2_rep,
	p2_ermac,
	p2_osz,
	
	p2_osm,		//-oldsmoke
	p2_noob,		//noob
	p2_ray,		//rad
	p2_sa,		//sa
	p2_rain,		//rain
	p2_kamel,		// c1
	p2_osz,		// c2
	p2_osz,		// c3
	
};


/******************************************************************************
 Function: void auto_player_select(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description: auto player select
******************************************************************************/
void auto_player_select(void)
{
	PROCESS *ta0;
	OBJECT *ta8;

	if ((ta0=process_exist(PID_MASTER,-1))!=NULL)
	{
		if (ta0->p_comp_flag==PC_PSEL_WAIT)
			ta0->a11=0x40*5;				// tell him to wait nol longer
	}

	/* aps0 */
	if ((ta0=process_exist(PID_AUTO_CYCLE,-1))==NULL)
	{
		ta0=CREATE(PID_AUTO_CYCLE,boonpal_stuff);
		ta0->a11=(ADDRESS)fl_auto;
	}

	/* aps1 */
	/* asp6 */
	ta8=current_proc->pa8;
	if (*((WORD*)current_proc->pdata.p_mychar)==FT_NOOB)
		lm_printf(pf_auto_msg_1);
	else lm_printf(pf_auto_msg_2);
	current_proc->pa8=ta8;

	process_sleep(4);

	/* asp_try_again */
	do
	{
		current_proc->a0=randu(FT_CHARS)-1;
		if ((current_proc->a0==FT_OLDSMOKE && f_oldsm==0) || (current_proc->a0==FT_KAMEL && f_kamel==0))			// no oldsmoke
			continue;
		else break;
	}
	while(1);

	/* asp9 */
	(BYTE *)current_proc->a11=(*((WORD*)current_proc->pdata.p_mychar)==FT_NOOB) ? p1_movements[(current_proc->a0)] : p2_movements[(current_proc->a0)];

	/* aps3 */
	while (TRUE)
	{
		current_proc->a0=*((BYTE *)current_proc->a11);
		((BYTE *)current_proc->a11)++;

		switch (current_proc->a0)
		{
			case 0:
				process_sleep(9);
				stack_jump(cmove9);
				break;
			case MVUP:		// auto_move_up
				new_auto_position(up_change,0,-Y_SPACE);
				break;
			case MVDN:	// auto_move_down
				new_auto_position(down_change,0,Y_SPACE);
				break;
			case MVRT:	// auto_move_right
				new_auto_position(right_change,X_SPACE,0);
				break;
			case MVLF:	// auto_move_left
				new_auto_position(left_change,-X_SPACE,0);
				break;
		}
	}
	return;
}

/******************************************************************************
 Function: void new_auto_position(WORD *pa2,short pa3,short pa4)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa2 - pos change table
			 pa3 - coord dx
			 pa4 - coord dy

 Returns: None

 Description: select new position
******************************************************************************/
void new_auto_position(WORD *pa2,short pa3,short pa4)
{
	current_proc->a1=*((WORD *)current_proc->pdata.p_mychar);		// a1 = my current ochar
	new_cursor_calla(pa2,pa3,pa4,1);
	if (mode_of_play==1 || mode_of_play==4)
		process_sleep(0x07);
	else process_sleep(0x0a);

	return;
}

/******************************************************************************
******************************************************************************/

/******************************************************************************
 Function: void position_badge(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	print the winners badge and spin the coin
******************************************************************************/
void position_badge(void)
{
	OBJECT *obj;

	if (winner_status==0)
		return;

	if (winner_status==1)
	{
		if (p1_state!=PS_ACTIVE)
			return;
	}
	else
	{
		if (p2_state!=PS_ACTIVE)
			return;							// winner drone: no stinkin badge
	}

	/* mint3 */
	if (winner_status==1)
	{
		gso_dmawnz_ns_coor(obj,(ADDRESS)MKCOIN_01,sdragon_dict,0,0,SCX(0x000d),(0x0010)+3);
	}
	else
	{
		gso_dmawnz_ns_coor(obj,(ADDRESS)MKCOIN_01,sdragon_dict,0,0,SCX(0x0153),(0x0010)+3);
	}

	alloc_cache(MKCOIN_01,0,obj);
	insert_object(obj,&objlst);
	CREATE(PID_BANI,badge_spinner);

	return;

}

/******************************************************************************
 Function: void badge_spinner(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	process to spin the pretty coin
******************************************************************************/
void badge_spinner(void)
{
	current_proc->pa9=a_badge_spin;
	framew(5);

	wait_forever();
}

/******************************************************************************
******************************************************************************/
extern FNTSETUP pf_bk_setup[];
/******************************************************************************
 Function: void select_background(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	select a valid background
******************************************************************************/
extern WORD hidden_included[];
void select_background(void)
{
	OBJECT *obj;
	WORD jpad;
	WORD oldback=0xffff;
	WORD delay;

	tsound(0x0);
	tsound(0x1);
	
	delay=(mode_of_play==1 || mode_of_play==4)?6:12;
	
	/* setup joy */
	dallobj(OID_TEXT);			// remove old text
	
	/* draw background box */
	obj=make_solid_object(0x0001,220,56);
	obj->opal=get_fore_pal(WHITE_p);
	obj->oxpos.u.intpos=50+worldtlx.u.intpos;
	obj->oypos.u.intpos=worldtly.u.intpos;
	obj->oflags|=M_XLU_ON;
	obj->oflags|=0xe000;			// set xlu value
	obj->oid=OID_CURSOR4;
	obj->ozval=1;
	insert_object(obj,&objlst2);
	
	p15_centered(txt_select_back,160,20);

	obj=(OBJECT *)&objlst2;
	while((obj=obj->olink)!=NULL)
		obj->oid=OID_R1;				// change all text id --> oid_r1

	current_proc->a10=0;	// debounce
	current_proc->pdata.p_store5=0x60*8;					// time to select kombat zone

	do
	{
		jpad=swcurr.u.p1pad|swcurr.u.p2pad;
		if (current_proc->a10!=0)
			current_proc->a10--;

		if ((jpad & MASK_JLEFT) && current_proc->a10==0)
		{
			/* down # */
			current_proc->a10=delay;

			c_curback--;
			if ((short)c_curback<0)
				c_curback=MAX_BACKGROUNDS-1;

		}
		else
		{
			if ((jpad & MASK_JRIGHT) && current_proc->a10==0)
			{
				/* up # */
				current_proc->a10=delay;

				c_curback++;

				if (c_curback>=MAX_BACKGROUNDS)
					c_curback=0;
			}
		}

		curback=hidden_included[c_curback];
		if (oldback!=curback)
		{
			oldback=curback;
			dallobj(OID_TEXT);
			lm_setup(pf_bk_setup);
			mk_printf(background_names[curback]);
		}
		process_sleep(1);
	}
	while((jpad & (P1B0|P1B2|P1B3|P1SF2|P1B1|P1B4|P1B5))==0 && (--current_proc->pdata.p_store5>0));

	tsound(0xd);

	dallobj(OID_TEXT);
	dallobj(OID_R1);
	return;
}
