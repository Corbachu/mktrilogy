/******************************************************************************
 File: mkvs.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III vs Routines
******************************************************************************/


/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkobj.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkjoy.h"
#include "mkguys.h"
#include "mktext.h"
#include "mkinit.h"
#include "mkpal.h"
#include "mkmain.h"
#include "mksound.h"
#include "mkladder.h"
#include "mkvs.h"
#include "mksel.h"
#include "mkdma.h"
#include "mkfade.h"

#include "vcache.h"

#if SYS_DEBUG==1
#define SK_TEST 	1
#else
#define SK_TEST 	0
#endif

/* local externs */
extern WORD brite_p[];
extern WORD bricka_PAL[];
extern WORD brickb_PAL[];

extern void *a_badge_spin[];
extern void *MKBRICK[];
extern void *MKBRICK2[];
extern void *UPEVILA[];
extern void *UPEVILB[];

extern void *ENDUR_RED[];
extern void *HDKITANA[];
extern void *HDREPTILE[];
extern void *HDSONYA[];
extern void *HDJAX[];
extern void *HDINDIAN[];
extern void *HDJADE[];
extern void *HDSCORPION[];
extern void *HDKANO[];
extern void *HDMILEENA[];
extern void *HDERMAC[];
extern void *HDCLASSUB[];
extern void *HDSUBZERO[];
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
extern void *BOX_01[];			// hidden questions

extern void *HDSHAO[];
extern void *HDMOTARO[];
extern void *HDQUESTION[];
extern void *SCURSOR[];
extern void *MKCOIN_01[];
extern void *TXT_NOVICE[];
/*******************************************************************************
 MAP ROM TABLES
*******************************************************************************/
WORD map_1[]=
{
	FT_SCORPION,
	FT_INDIAN,
	FT_JADE,
	FT_JCAGE,
	FT_ROBO2,
	FT_ENDUR3,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 0

	FT_REPTILE,
	FT_SONYA,
	FT_KITANA,
	FT_SWAT,
	FT_SG,
	FT_SMOKE,
	FT_ENDUR4,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_REPTILE,
	FT_JAX,
	FT_SWAT,
	FT_ST,
	FT_JADE,
	FT_KITANA,
	FT_LAO,
	FT_ENDUR5,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_KITANA,
	FT_INDIAN,
	FT_REPTILE,
	FT_LK,
	FT_JADE,
	FT_SCORPION,
	FT_TUSK,
	FT_ENDUR6,
	FT_ENDUR10,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_2[]=
{
	FT_REPTILE,
	FT_ST,
	FT_SG,
	FT_JADE,
	FT_TUSK,
	FT_ENDUR7,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 0

	FT_JADE,
	FT_ROBO2,
	FT_LAO,
	FT_SCORPION,
	FT_LIA,
	FT_KITANA,
	FT_ENDUR8,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1
 
	FT_SCORPION,
	FT_SWAT,
	FT_KITANA,
	FT_SCORPION,
	FT_JCAGE,
	FT_INDIAN,
	FT_SONYA,
	FT_ENDUR9,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_KITANA,
	FT_JADE,
	FT_REPTILE,
	FT_SCORPION,
	FT_LIA,
	FT_INDIAN,
	FT_LAO,
	FT_ENDURA,
	FT_ENDUR11,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_3[]=
{
	FT_KITANA,
	FT_SMOKE,
	FT_LK,
	FT_JADE,
	FT_SG,
	FT_ENDURB,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 0

	FT_JADE,
	FT_TUSK,
	FT_KITANA,
	FT_ROBO2,
	FT_SWAT,
	FT_ROBO1,
	FT_ENDUR5,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_REPTILE,
	FT_ST,
	FT_LAO,
	FT_SCORPION,
	FT_SMOKE,
	FT_LK,
	FT_SG,
	FT_ENDUR6,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_SCORPION,
	FT_JCAGE,
	FT_KITANA,
	FT_JAX,
	FT_INDIAN,
	FT_SMOKE,
	FT_LK,
	FT_ENDUR7,
	FT_ENDUR12,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_4[]=
{
  	FT_REPTILE,
  	FT_SWAT,
  	FT_LIA,
  	FT_JCAGE,
  	FT_ROBO1,
  	FT_ENDURF,
  	FT_MOTARO,
  	FT_SK,
  	SP_END,		// MAP 0

  	FT_JADE,
  	FT_ROBO1,
  	FT_KITANA,
  	FT_LAO,
  	FT_TUSK,
  	FT_LK,
  	FT_ENDUR3,
  	FT_MOTARO,
  	FT_SK,
  	SP_END,		// MAP 1

  	FT_SCORPION,
  	FT_KITANA,
  	FT_LK,
  	FT_JADE,
  	FT_KANO,
  	FT_INDIAN,
  	FT_LAO,
  	FT_ENDUR4,
  	FT_MOTARO,
  	FT_SK,
  	SP_END,		// MAP 2

  	FT_SCORPION,
  	FT_JCAGE,
  	FT_KITANA,
  	FT_JAX,
  	FT_ROBO2,
  	FT_SMOKE,
  	FT_SG,
  	FT_ENDUR8,
  	FT_ENDUR10,
  	FT_MOTARO,
  	FT_SK,
  	SP_END,		// MAP 3
};

WORD map_5[]=
{
	FT_JADE,
	FT_SMOKE,
	FT_KANO,
	FT_SCORPION,
	FT_SONYA,
	FT_ENDUR5,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 0,

	FT_KITANA,
	FT_REPTILE,
	FT_SG,
	FT_INDIAN,
	FT_TUSK,
	FT_LAO,
	FT_ENDUR6,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1,

	FT_JADE,
	FT_SONYA,
	FT_KITANA,
	FT_SG,
	FT_SMOKE,
	FT_ROBO2,
	FT_JAX,
	FT_ENDUR7,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_SCORPION,
	FT_LK,
	FT_JADE,
	FT_REPTILE,
	FT_LAO,
	FT_SONYA,
	FT_KANO,
	FT_ENDUR9,
	FT_ENDUR11,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_6[]=
{
	FT_ERMAC,
	FT_MILEENA,
	FT_SMOKE,
	FT_OLDSZ,
	FT_SONYA,
	FT_ENDURD,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 

	FT_OLDSZ,
	FT_ST,
	FT_ERMAC,
	FT_KITANA,
	FT_MILEENA,
	FT_JADE,
	FT_ENDURE,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_MILEENA,
	FT_ERMAC,
	FT_OLDSZ,
	FT_JADE,
	FT_KITANA,
	FT_JCAGE,
	FT_SWAT,
	FT_ENDURF,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_OLDSZ,
	FT_MILEENA,
	FT_ERMAC,
	FT_REPTILE,
	FT_JADE,
	FT_LIA,
	FT_SMOKE,
	FT_ENDURD,
	FT_ENDUR13,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_7[]=
{
	FT_JADE,
	FT_BARAKA,
	FT_LIA,
	FT_SCORPION,
	FT_SONYA,
	FT_ENDUR15,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 0,

	FT_KITANA,
	FT_REPTILE,
	FT_RAYDEN,
	FT_INDIAN,
	FT_TUSK,
	FT_RAIN,
	FT_ENDUR6,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1,

	FT_NOOB,
	FT_SONYA,
	FT_KITANA,
	FT_SG,
	FT_SMOKE,
	FT_ROBO2,
	FT_JAX,
	FT_ENDUR3,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_SCORPION,
	FT_JCAGE,
	FT_JADE,
	FT_RAYDEN,
	FT_LK,
	FT_SONYA,
	FT_KANO,
	FT_ENDUR15,
	FT_ENDUR12,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_8[]=
{
	FT_OLDSZ,
	FT_MILEENA,
	FT_SMOKE,
	FT_SONYA,
	FT_BARAKA,
	FT_ENDURF,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 

	FT_BARAKA,
	FT_RAIN,
	FT_ROBO1,
	FT_KITANA,
	FT_MILEENA,
	FT_JADE,
	FT_ENDUR15,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_MILEENA,
	FT_ROBO2,
	FT_JADE,
	FT_OLDSZ,
	FT_JCAGE,
	FT_KITANA,
	FT_SWAT,
	FT_ENDUR14,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_NOOB,
	FT_MILEENA,
	FT_LIA,
	FT_BARAKA,
	FT_REPTILE,
	FT_JADE,
	FT_SMOKE,
	FT_ENDURA,
	FT_ENDUR16,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};

WORD map_endur[]=
{
	FT_RAIN,
	FT_RAYDEN,
	FT_SONYA,
	FT_ENDUR0,
	FT_MOTARO,
	FT_ENDUR2,
	FT_ENDUR5,
	FT_SK,
	SP_END,		// MAP 

	FT_MILEENA,
	FT_KITANA,
	FT_JADE,
	FT_ENDUR1,
	FT_ENDUR9,
	FT_ENDUR15,
	FT_ENDUR16,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_INDIAN,
	FT_JAX,
	FT_KANO,
	FT_ENDURB,
	FT_ENDUR7,
	FT_ENDUR8,
	FT_ENDUR10,
	FT_ENDUR14,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_KAMEL,
	FT_MOTARO,
	FT_ENDURB,
	FT_ENDUR4,
	FT_ENDUR16,
	FT_ENDURC,
	FT_ENDUR4,
	FT_ENDUR12,
	FT_ENDURA,
	FT_ENDUR16,
	FT_SK,
	SP_END,		// MAP 3
};

#if SK_TEST
WORD map_t[]=
{
	FT_OLDSZ,
	FT_MILEENA,
	FT_SMOKE,
	FT_SONYA,
	FT_OLDSZ,
	FT_ENDUR2,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 

	FT_BARAKA,
	FT_RAIN,
	FT_ROBO1,
	FT_KITANA,
	FT_MILEENA,
	FT_JADE,
	FT_ENDUR15,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 1

	FT_MILEENA,
	FT_ROBO2,
	FT_JADE,
	FT_OLDSZ,
	FT_JCAGE,
	FT_KITANA,
	FT_SWAT,
	FT_ENDUR14,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 2

	FT_NOOB,
	FT_MILEENA,
	FT_LIA,
	FT_BARAKA,
	FT_REPTILE,
	FT_JADE,
	FT_SMOKE,
	FT_ENDURA,
	FT_ENDUR16,
	FT_MOTARO,
	FT_SK,
	SP_END,		// MAP 3
};
#endif

#if SK_TEST
WORD *rom_maps_tbl[]=
{
	map_t,
	map_t,
	map_t,
	map_t,
	map_t,
	map_t,
	map_t,
	map_t,
};
#else
WORD *rom_maps_tbl[]=
{
	map_1,
	map_2,
	map_3,
	map_4,
	map_5,
	map_6,
	map_7,
	map_8,
};
#endif

WORD e_kitana_jade[]=
{
	FT_KITANA,
	FT_JADE,
	0xffff
};

WORD e_mileena_jade[]=
{
 	FT_MILEENA,
 	FT_JADE,
 	0xffff
};

WORD e_ermac_jade[]=
{
	FT_ERMAC,
	FT_JADE,
	0xffff
};

WORD e_noob_ermac[]=
{
	FT_NOOB,
	FT_ERMAC,
	0xffff
};

WORD e_osz_osm[]=
{
	FT_OLDSZ,
	FT_OLDSMOKE,
	0xffff
};

WORD e_mega_endurance[]=
{
  	FT_NOOB,
	FT_OLDSZ,
	FT_OLDSMOKE,
	FT_ERMAC,
	FT_MILEENA,
	0xffff
};

WORD e_scorpion_jade_kit[]=
{
	FT_SCORPION,
	FT_JADE,
	FT_KITANA,
	0xffff
};

WORD e_rayden_sonya_nightwolf[]=
{
	FT_SONYA,
	FT_RAYDEN,
	FT_INDIAN,
	0xffff
};

WORD e_reptile_indian_lia[]=
{
	FT_REPTILE,
	FT_INDIAN,
	FT_LIA,
	0xffff
};	

WORD e_scorp_swat_st[]=
{
	FT_SCORPION,
	FT_SWAT,
	FT_ST,
	0xffff
};	

WORD e_ermac_mileena_osz[]=
{
	FT_ERMAC,
	FT_MILEENA,
	FT_OLDSZ,
	0xffff
};	

WORD e_jade_reptile[]=
{
	FT_JADE,
	FT_REPTILE,
	0xffff
};

WORD e_kitana_scorpion[]=
{
	FT_KITANA,
	FT_SCORPION,
	0xffff
};

WORD e_kano_sonya[]=
{
	FT_KANO,
	FT_SONYA,
	0xffff
};

WORD e_jax_ind[]=
{
	FT_JAX,
	FT_INDIAN,
	0xffff
};

WORD e_sz_swat[]=
{
	FT_JCAGE,
	FT_SWAT,
	0xffff
};

WORD e_lia_robo1[]=
{
	FT_LIA,
	FT_ROBO1,
	0xffff
};

WORD e_robo2_lao[]=
{
  	FT_ROBO2,
	FT_LAO,
	0xffff
};

WORD e_sg_st[]=
{
	FT_SG,
	FT_ST,
	0xffff
};

WORD e_lk_smoke[]=
{
	FT_LK,
	FT_SMOKE,
	0xffff
};

WORD e_ermac_mileena[]=
{
	FT_ERMAC,
	FT_MILEENA,
	0xffff
};

WORD e_osz_sz[]=
{
	FT_OLDSZ,
	FT_JCAGE,
	0xffff
};

WORD e_kano_kano[]=
{
	FT_KANO,
	FT_KANO,
	0xffff
};

WORD e_rayden_baraka[]=
{
	FT_RAYDEN,
	FT_BARAKA,
	0xffff
};

WORD e_rain_noob[]=
{
	FT_RAIN,
	FT_NOOB,
	0xffff
};

WORD e_mninja[]=
{
	FT_SCORPION,
	FT_REPTILE,
	FT_ERMAC,	
	FT_OLDSZ,	
	FT_OLDSMOKE,
	FT_NOOB,		
	FT_RAIN,
	0xffff
};

WORD e_fninja[]=
{
	FT_KITANA,
	FT_JADE,
	FT_MILEENA,
	FT_KAMEL,
	0xffff
};

WORD e_rd_sa_cage[]=
{
	FT_RAYDEN,
	FT_BARAKA,
	FT_JCAGE,
	0xffff
};

/* mhe tables */
OBJECT *mhe_list[]=
{
	(OBJECT *)&baklst2,
	(OBJECT *)&baklst6,
	(OBJECT *)&baklst4
};

WORD *endurance_tables[]=
{
	e_noob_ermac,		// >80 = noob & ermac
	e_osz_osm,		// >81 = old sz & old smoke
	e_mega_endurance,	// >82 = old sz & old smoke

	e_jade_reptile,		// >83 =
	e_kitana_scorpion,	// >84 =
	e_kano_sonya,		// >85 =
	e_jax_ind,		// >86 =
	e_sz_swat,		// >87 =
	e_lia_robo1,		// >88 =
	e_robo2_lao,		// >89 =
	e_sg_st,			// >8a =
	e_lk_smoke,		// >8b =
	e_kitana_jade,		// >8c =

	e_ermac_jade,		// >8d = secret characters
	e_osz_sz,		// >8e = secret characters
	e_ermac_mileena,		// >8f = secret characters

	e_scorpion_jade_kit,	// >90
	e_reptile_indian_lia,	// >91
	e_scorp_swat_st,		// >92
	e_ermac_mileena_osz,	// >93
	e_rayden_baraka,		// 94
	e_rain_noob,			// 95
	e_rayden_sonya_nightwolf,	// 96
	e_mninja,
	e_fninja,
	e_rd_sa_cage,
};

typedef struct 
{
	OBJECT *lorder_lst;
	WORD	lorder_routine;
	short 	lorder_yoff;
} LORDER;

#define LO_RETURN	0
#define LO_XMINUS	1
#define LO_X2MINUS	2
#define LO_XPLUS	3
#define LO_X2PLUS	4

LORDER lorder_0123[]=
{
	{(OBJECT *)&baklst1,LO_XPLUS,ENTRIES_0-ENTRIES_0},
	{(OBJECT *)&baklst2,LO_XPLUS,ENTRIES_1-ENTRIES_0},
	{(OBJECT *)&baklst3,LO_XPLUS,ENTRIES_2-ENTRIES_0},
	{(OBJECT *)&baklst4,LO_RETURN,ENTRIES_3-ENTRIES_0},
	{NULL},
};

LORDER lorder_1023[]=
{
	{(OBJECT *)&baklst2,LO_XMINUS,ENTRIES_1-ENTRIES_0},
	{(OBJECT *)&baklst1,LO_X2PLUS,ENTRIES_0-ENTRIES_0},
	{(OBJECT *)&baklst3,LO_XPLUS,ENTRIES_2-ENTRIES_0},
	{(OBJECT *)&baklst4,LO_RETURN,ENTRIES_3-ENTRIES_0},
	{NULL},
};

LORDER lorder_2310[]=
{
	{(OBJECT *)&baklst3,LO_XPLUS,ENTRIES_2-ENTRIES_0},
	{(OBJECT *)&baklst4,LO_X2MINUS,ENTRIES_3-ENTRIES_0},
	{(OBJECT *)&baklst2,LO_XMINUS,ENTRIES_1-ENTRIES_0},
	{(OBJECT *)&baklst1,LO_RETURN,ENTRIES_0-ENTRIES_0},
	{NULL},
};

LORDER lorder_3210[]=
{
	{(OBJECT *)&baklst4,LO_XMINUS,(ENTRIES_3-ENTRIES_0)},
	{(OBJECT *)&baklst3,LO_XMINUS,(ENTRIES_2-ENTRIES_0)},
	{(OBJECT *)&baklst2,LO_XMINUS,(ENTRIES_1-ENTRIES_0)},
	{(OBJECT *)&baklst1,LO_RETURN,(ENTRIES_0-ENTRIES_0)},
	{NULL},
};

LORDER lorder_closeup[]=
{
	{(OBJECT *)&baklst1,LO_RETURN,0},
	{(OBJECT *)&baklst2,LO_RETURN,0},
	{(OBJECT *)&baklst3,LO_RETURN,0},
	{(OBJECT *)&baklst4,LO_RETURN,0},
	{NULL}
};

/******************************************************************************
 Function: void mk_ladder(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	The cool ladder screen
******************************************************************************/
extern void *ladder_module[];
extern WORD f_special_endur;
void mk_ladder(void)
{
	murder_myoinit_score();
	f_doscore=0;

	/* load mugshot data */
	special_fx_load(FX_MUGS_LOAD);
	spec_fx=FX_NO_LOAD;

	load_bkgd=BKGD_LADDER_MOD;
	init_background_module(ladder_module);
	multi_plane();
	master_fade=0x10000;

	if ( map_start==NULL )
		sound_music_start(MUSIC_ONEPLAYE);
		
	f_novel=1;

	if (map_start!=NULL)			// have we set out map yet??,
	{	
		ladder_order=(LONG)lorder_closeup;
		setup_close_ladder();
	}
	else
	{
		/* lad2 */
		current_proc->a0=8;
		current_proc->a0=randu(current_proc->a0)-1;
		ladder_base=(f_special_endur==0)?rom_maps_tbl[current_proc->a0]:map_endur;
		setup_distant_ladder();
		ladder_switch_scan();
		map_position=perform=0;
		ladder=current_proc->a11;
		init_map_start();
		tower_picked_fx();
		pan_to_pick_tower();
		zoom_in();
		pan_down();
		set_match_1_diff();			// set diff

#if SK_TEST
	map_position=7;
#endif
	}

	/* lad1p */
	sound_music_start(MUSIC_ENDONEPL);
	
	process_sleep(0x40);
	set_drone_ochar();

	/* arcade display flow */
	murder_myoinit_score();

	return;
}

DBS diff_build_setup[]=
{
	{LAST_ENTRY_0,ENTRIES_0,(OBJECT*)&baklst1},
	{LAST_ENTRY_1,ENTRIES_1,(OBJECT*)&baklst2},
	{LAST_ENTRY_2,ENTRIES_2,(OBJECT*)&baklst3},
	{LAST_ENTRY_3,ENTRIES_3,(OBJECT*)&baklst4},
};

/******************************************************************************
 Function: void setup_close_ladder(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:
******************************************************************************/
void setup_close_ladder(void)
{
	long ta1;
	OBJECT *oa1;
	OBJECT *obj;
	DBS *ta0;

	ta0=diff_build_setup+ladder;
	build_tower(ta0);

	ladder_scale.yx=0x01000100;			// full scale

	if ((ta1=map_position-1)<0)
		ta1=0;							// position 1&0 --> bottom

	/* scl4 */
	ladder_y.u.intpos=SCY(0xa7)-62*ta0->dbs_ent;


	if (ta1==0) 
	{
		ta1=61+27;
	}
	else
	{
		ta1=62*map_position+24;
	}

	ladder_y.u.intpos+=ta1;
	ladder_x.pos=(SCRRGT/2)<<16;
	call_every_tick=ladder_irq;				// ladder IRQ ---> go !!

	switch (ladder)
	{
		case 0:
			oa1=(OBJECT*)baklst1;
			break;
		case 1:
			oa1=(OBJECT*)baklst2;
			break;
		case 2:
			oa1=(OBJECT*)baklst3;
			break;
		case 3:
			oa1=(OBJECT*)baklst4;
			break;
		case 4:
			oa1=(OBJECT*)baklst5;
			break;
		case 5:
			oa1=(OBJECT*)baklst6;
			break;
		case 6:
			oa1=(OBJECT*)baklst7;
			break;
		case 7:
			oa1=(OBJECT*)baklst8;
			break;
		case 8:
			oa1=(OBJECT*)baklst9;
			break;
	}

	/* scl5 */
	do
	{
		oa1->oyvel.pos=0;				// stop all other vels
//		obj=(OBJECT *)oa1->oslink;					// ptr to assoc mug
//		obj->oyvel.pos=0;				// clear mugshot velocity also
		oa1=oa1->olink;
	}
	while(oa1!=NULL);
	f_novel=0;							// and allow normal vel

	gso_dmawnz_ns_coor(obj,(current_proc->a5=get_player_ochar_a5()),0,0,0,SCX(0x88)+3,181);
	alloc_cache((void *)current_proc->a5,0,obj);
	insert_object(obj,&objlst2);
	(OBJECT *)current_proc->pa9=obj;
	obj=solid_backdrop_box();
	insert_object(obj,&objlst2);
	process_sleep(0x12);

	if (map_position!=0)				// dont move on first pos
	{
		current_proc->a10=(long)(obj->oypos.u.intpos);
		obj->oyvel.pos=-SCY(0x30000);
		((OBJECT *)current_proc->pa9)->oyvel.pos=-SCY(0x30000);

		/* scl7 */
		do
		{
			process_sleep(1);
		}
		while(abs(obj->oypos.u.intpos-(long)current_proc->a10)<64);

		obj->oyvel.pos=0;
		((OBJECT *)current_proc->pa9)->oyvel.pos=0;
	}

	/* scl8 */
	process_sleep(0x10);
	return;
}

/******************************************************************************
 Function: void setup_distant_ladder(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:
******************************************************************************/
void lbadge_spinner(void)
{
	current_proc->pa9=a_badge_spin;
	framew(3);

	wait_forever();
}

char txt_ladder[]="CHOOSE YOUR DESTINY";
extern BYTE select_dict[];
extern BYTE sdragon_dict[];
void setup_distant_ladder(void)
{
	OBJECT *obj;
	OBJECT *oa9;

	tsound(0x91);					// shao: choose your destiny 

	pds_centered(txt_ladder,SCX(0xc8),SCY(0x8)+16);

	ladder_scale.yx=0x04000400;
	ladder_y.pos=ORIGIN_Y+0x200000;
	ladder_x.pos=ORIGIN_X;

	ladder_x_vel.pos=0;
	ladder_left_x=0;
	ladder_right_x=0;
	build_tower(&diff_build_setup[0]);
	build_tower(&diff_build_setup[1]);
	build_tower(&diff_build_setup[2]);
	build_tower(&diff_build_setup[3]);

	ladder_order=(LONG)lorder_0123;

	call_every_tick=ladder_irq;
	gso_dmawnz_ns_coor(obj,(ADDRESS)MKCOIN_01,sdragon_dict,0,0,(ORIGIN_X>>16)-SCX(0x15),SCY(0xd0)+16);	// start at novice
	alloc_cache(MKCOIN_01,0,obj);
	insert_object(obj,&objlst2);
	oa9=(OBJECT *)current_proc->pa9=current_proc->pa8;

	gso_dmawnz_ns(obj,(ADDRESS)TXT_NOVICE,select_dict,0,0);
	alloc_cache(TXT_NOVICE,0,obj);
	obj->oypos.u.intpos=oa9->oypos.u.intpos+SCY(0x10)+2;
	obj->ozval=oa9->ozval+1;

	obj->oxpos.u.intpos=(oa9->oxpos.u.intpos+(oa9->osize.u.xpos)/2)-(obj->osize.u.xpos)/2;		// center spot
	insert_object(obj,&objlst2);
	current_proc->pa8=oa9;
	current_proc->pa9=(void*)obj;

	CREATE(PID_BANI,lbadge_spinner);		// a9=text/a8=coin
	return;
}

void build_tower(DBS *ta0) 
{
	OBJECT *ta11,*ta3;
	OBJECT *stk_ta11,*stk_ta3;
	WORD *ta7;

	stk_ta11=ta11=obj_free;			// 1st brick
	stk_ta3=ta3=ta11->olink;			// 1st mug shot

	ta7=ladder_base+ta0->dbs_le;
	current_proc->a10=ta0->dbs_ent;
	/* lad05 */
	do
	{
		(OBJECT *)current_proc->pa9=current_proc->pa8;
		get_a_brick(*ta7);
		ta7--;
		ta11->olink=current_proc->pa8;
		ta3->olink=(OBJECT*)current_proc->a1;
		ta11=current_proc->pa8;
 	  	ta3=(OBJECT*)current_proc->a1;
	}
	while(--current_proc->a10>0);

	ta11=stk_ta11;
	ta3=stk_ta3;

	((OBJECT*)current_proc->pa8)->olink=ta3;
	*((OBJECT **)ta0->dbs_lst)=ta11;

	ta11->ochar=0;

	return;
}

/******************************************************************************
 Function: void ladder_switch_scan(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	scan switches for ladder
******************************************************************************/
void ladder_switch_scan(void)
{
	WORD *pa3;

	current_proc->a11=0;				// start pos = center
	current_proc->a10=0;				// debounce

	/* lad91 */
	if (p1_state==PS_ACTIVE)
	{
		current_proc->pdata.p_store1=M_P1ACTION;
		pa3=(WORD *)&swcurr.u.p1pad;
	}
	else
	{
		current_proc->pdata.p_store1=M_P2ACTION;
		pa3=(WORD *)&swcurr.u.p2pad;
	}

	/* lad92 */
	current_proc->a0=0x40*5;
	do
	{
		current_proc->pdata.p_store3=current_proc->a0;
		process_sleep(1);

		if (current_proc->a10!=0)
		{
			--current_proc->a10;
			if (current_proc->a10>0)
				goto LAD97;
		}

		/* lad93 */
		if ((*pa3) & current_proc->pdata.p_store1)
			return;								// action button exit

		if ((*pa3) & M_PJOY)
		{
			/* stick left */
			current_proc->a10=10;					// debounce speed
			if ((*pa3) & MASK_JLEFT)
			{
				if (current_proc->a11!=0)
				{
					current_proc->a11--;
					move_dragon_logo(-BADGE_X_JUMP);
				}
			}
			else
			{
				/* lad96, stick right */
				if ((*pa3) & MASK_JRIGHT)
				{
					if (current_proc->a11 !=3)
					{
						current_proc->a11++;
					   	move_dragon_logo(BADGE_X_JUMP);
					}
				}
			}
		}
LAD97:
		current_proc->a0=current_proc->pdata.p_store3;
	}
	while(--current_proc->a0>0);

	return;
}

/******************************************************************************
 Function: void tower_picked_fx(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	spin the neat dragon
******************************************************************************/
WORD kahn_comments[]=
{
	0x7c,			
	0x7d,
	0x7e,
	0x74,
};
void tower_picked_fx(void)
{
	OBJECT *ta9;

	send_code_a3(TS_P1_PICKED);

	CREATE(PID_FX,fx_tower_flash);

	(void *)ta9=current_proc->pa9;			// save diff text

	dallprc(PID_BANI);					// stop badge rotator dude
	current_proc->pa9=a_badge_spin;
	current_proc->a10=0x40;
	dallobj(OID_TEXT);

	/* lad9a */
	do
	{
		process_sleep(1);
		frame_a9(current_proc->pa8);
	}
	while(--current_proc->a10>0);
	delobjp2(current_proc->pa8);				// delete badge obj
	delobjp2(ta9);								// delete diff text

	tsound(kahn_comments[current_proc->a11]);			// shao kahn comment
	process_sleep(8);
	return;
}

void fx_tower_flash(void) 
{
	OBJECT *ta10;
	OBJECT *ta0;
	OBJECT *ta2;
	OBJECT *ta3;
	
	ta10=diff_build_setup[current_proc->a11].dbs_lst;

	ta0=ta10=ta10->olink;		// 1st obj

	while (ta0->oslink==NULL)
		ta0=ta0->olink;

	/* towf2 */
	while (ta0->oslink!=NULL)
	{
		ta2=ta0->olink;
		(OBJECT*)ta2->oshape=ta0;	// backward link
		ta3=ta0;
		ta0=ta2;
	}

	/* towf3 */
	current_proc->a11=(ADDRESS)ta3->oshape;	// skip offscreen brick
	current_proc->a11=ta3;

	current_proc->pa8=(OBJECT*)current_proc->a11;
	up_ewe_go(brite_p);
	current_proc->pa8=(OBJECT*)current_proc->a11;
	up_ewe_go(bricka_PAL);
	process_suicide();
}

void up_ewe_go(WORD *pa9) 
{
	do
	{
		swpal(pa9,current_proc->pa8);
		//process_sleep(2);
		process_sleep(1);
		current_proc->pa8=(OBJECT*)(current_proc->pa8)->oshape;
	}
	while(current_proc->pa8!=NULL);
	return;
}

LORDER *diff_lorders[]=
{
	lorder_0123,
	lorder_1023,
	lorder_2310,
	lorder_3210,
};

long diff_y_vels[]=
{
	SCY(0x20000),
	SCY(0x20000),
	-SCY(0x50000),
	-SCY(0x50000),
};


/******************************************************************************
 Function: void pan_to_pick_tower(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	pan to the correct tower
******************************************************************************/
void pan_to_pick_tower(void)
{
	OBJECT *obj;


	switch (current_proc->a11)
	{
		case 0:
			obj=(OBJECT*)baklst1;
			break;
		case 1:
			obj=(OBJECT*)baklst2;
			break;
		case 2:
			obj=(OBJECT*)baklst3;
			break;
		case 3:
			obj=(OBJECT*)baklst4;
			break;
		case 4:
			obj=(OBJECT*)baklst5;
			break;
		case 5:
			obj=(OBJECT*)baklst6;
			break;
		case 6:
			obj=(OBJECT*)baklst7;
			break;
		case 7:
			obj=(OBJECT*)baklst8;
			break;
		case 8:
			obj=(OBJECT*)baklst9;
			break;
	}

	while (obj->oslink==NULL)
		obj=obj->olink;

	ladder_x_vel.pos=SCX(0x20000*2);

	if (current_proc->a11>=2)
		ladder_x_vel.pos*=-1;

	/* wait for top birck to be centered */

	/* ladd7 */
	do
	{
		process_sleep(1);
	}
	while(abs(obj->oxpos.u.intpos-SCX(0xb0))>SCX(3));

	ladder_x_vel.pos=0;
	ladder_x.pos=(SCRRGT/2)<<16;
	ladder_order=(LONG)diff_lorders[current_proc->a11];

	return;
}

/******************************************************************************
 Function: void zoom_in(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	pan to the correct tower
******************************************************************************/
void zoom_in(void)
{
	XYTYPE ta9;

	process_sleep(0x10);

	ladder_y_vel.pos=-diff_y_vels[current_proc->a11];

	tsound(0x19);

	/* ZOOM IN ! */
	ta9.u.xpos=0x0400;
	ta9.u.ypos=0x0400;
	/* zoom3 */
	do
	{
		process_sleep(1);
		ladder_scale.yx=ta9.yx;
		ta9.u.xpos-=0x0010*2;
		ta9.u.ypos-=0x0010*2;
	}
	while(ta9.yx!=0x01000100);

	ladder_x_vel.pos=0;
	ladder_y_vel.pos=0;					// stop moving already
	ladder_scale.yx=ta9.yx;
	process_sleep(2);					// ok now everyone is full scale

	process_sleep(10);					// ok now everyone is full scale

	call_every_tick=NULL;

	return;
}

/******************************************************************************
 Function: void pan_down(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	pan down
******************************************************************************/
void pan_down(void)
{
	create_base_object();

	current_proc->a5=get_player_ochar_a5();
	base_offset_obj(current_proc->a5,SCX(0x20),-64+8);

	(OBJECT*)current_proc->pa9=current_proc->pa8;
	solid_backdrop_box();
	(current_proc->pa8)->olink=((OBJECT*)current_proc->a10)->olink;
	((OBJECT*)current_proc->a10)->olink=current_proc->pa8;
	(current_proc->pa8)->oyvel.pos=-PANDOWN;
	
	f_novel=0;

	current_proc->a11=0x10;			// button exit timer !!

	/* pandown4 */
	do
	{
		process_sleep(1);

		if (p1_state==PS_ACTIVE)
			current_proc->a1=swcurr.u.p1pad & M_P1ACTION;
		else current_proc->a1=swcurr.u.p2pad & M_P2ACTION;

		if (current_proc->a1!=0)
		{
			if (--current_proc->a11==0)
				break;
		}
	}
	while(((OBJECT *)current_proc->a10)->oypos.u.intpos>SCY(0xa7)+64-8+16);

	/* pandown9 */
	f_novel=1;
	return;
}

/******************************************************************************
 Function: OBJECT *solid_backdrop_box(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	draw a solid back box
******************************************************************************/
OBJECT *solid_backdrop_box(void)
{
	OBJECT *obj;

	obj=get_object();

	obj->oflags|=M_BOX_POLY;

	/* set color */
	obj->oconst=0xf801;				// set red box color

	obj->osize.u.xpos=38;		// set size of box
	obj->osize.u.ypos=50;

	obj->oxpos.u.intpos=((OBJECT *)current_proc->pa9)->oxpos.u.intpos-2;
	obj->oypos.u.intpos=((OBJECT *)current_proc->pa9)->oypos.u.intpos-2;		// set coord

	current_proc->pa8=obj;

	return(obj);
}

extern ADDRESS ochar_order_mugs[];
/******************************************************************************
 Function: ADDRESS get_player_ochar_a5(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: ptr to correct char face

 Description:	retrieve the correct player face
******************************************************************************/
ADDRESS get_player_ochar_a5(void)
{
	if (p1_state==PS_ACTIVE)
		return(ochar_order_mugs[p1_char]);
	else return(ochar_order_mugs[p2_char]);
}

/******************************************************************************
 Function: void create_base_object(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: current_proc->a10 last object
		  current_proc->pa8 object

 Description:	create the base object of the mountain
******************************************************************************/
void create_base_object(void)
{
	OBJECT *obj,*ta2;

	switch (current_proc->a11)
	{
		case 0:
			obj=(OBJECT*)baklst1;
			break;
		case 1:
			obj=(OBJECT*)baklst2;
			break;
		case 2:
			obj=(OBJECT*)baklst3;
			break;
		case 3:
			obj=(OBJECT*)baklst4;
			break;
		case 4:
			obj=(OBJECT*)baklst5;
			break;
		case 5:
			obj=(OBJECT*)baklst6;
			break;
		case 6:
			obj=(OBJECT*)baklst7;
			break;
		case 7:
			obj=(OBJECT*)baklst8;
			break;
		case 8:
			obj=(OBJECT*)baklst9;
			break;
	}

	/* cbo3 */
	do
	{
		obj=obj->olink;
		ta2=obj->olink;
		ta2=(OBJECT*)ta2->oslink;
	}
	while(ta2!=NULL);

	(OBJECT *)current_proc->a10=obj;
	(OBJECT*)current_proc->a11=obj;

	gso_dmawnz_ns(obj,(ADDRESS)MKBRICK2,select_dict,0,0);
	alloc_cache(MKBRICK2,0,obj);
	obj->ozval=2000;
	obj->oyvel.pos=-PANDOWN;
	obj->oxpos.u.intpos=((OBJECT *)current_proc->a10)->oxpos.u.intpos;
	obj->oypos.u.intpos=((OBJECT *)current_proc->a10)->oypos.u.intpos+((OBJECT *)current_proc->a10)->osize.u.ypos;	// pos under last
	obj->olink=((OBJECT *)current_proc->a10)->olink;
	((OBJECT *)current_proc->a10)->olink=obj;			// new last obj
	current_proc->a10=(ADDRESS)obj;		// new last obj
	(OBJECT*)current_proc->a11=obj;

	/* create mountain objects */
//	base_offset_obj((ADDRESS)UPEVILA,-96,48);
//	base_offset_obj((ADDRESS)UPEVILB,80-16,48);

	return;
}

/******************************************************************************
 Function: void move_dragon_logo(short pa1)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa1 - amount to move dragon logo

 Returns: None

 Description:	move the dragon logo to the correct screen pos
******************************************************************************/
extern OIMGTBL *emh_images[];
#define diff_images emh_images
void move_dragon_logo(short pa1)
{
	OBJECT *ta8=current_proc->pa8;

	/* update diff text */
	current_proc->pa8=(OBJECT *)current_proc->pa9;
	animate(SINGLE_ANI,emh_images[current_proc->a11],(current_proc->pa8)->oflags);
	current_proc->pa8=ta8;

	(current_proc->pa8)->oxpos.u.intpos+=pa1;
	((OBJECT*)current_proc->pa9)->oxpos.u.intpos+=pa1;

	send_code_a3(TS_P1_CURS);
	return;
}

/******************************************************************************
 Function: void base_offset_obj(ADDRESS pa5,short pa6,short pa7)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa5 - frame to setup
			 pa6 - x offset
			 pa7 - y offset

 Returns: current_proc->a8  - ptr to newly created object

 Description:	retieve current object list
******************************************************************************/
void base_offset_obj(ADDRESS pa5,short pa6,short pa7)
{
	OBJECT *obj;

	gso_dmawnz_ns(obj,pa5,select_dict,0,0);
	alloc_cache((void *)pa5,0,obj);

	obj->olink=NULL;
	obj->ozval=50;
	obj->oxpos.u.intpos=((OBJECT *)current_proc->a10)->oxpos.u.intpos+pa6;
	obj->oypos.u.intpos=((OBJECT *)current_proc->a10)->oypos.u.intpos+pa7;

	obj->olink=((OBJECT*)current_proc->a11)->olink;
	((OBJECT*)current_proc->a11)->olink=obj;
	obj->oyvel.pos=-PANDOWN;

	return;
}

/******************************************************************************
 Function: void ladder_irq(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	routine to call on ladder screen every tick
******************************************************************************/
long ca10,ca11,ca2,ca3;
void ladder_irq(void)
{
	long ta10,ta11,ta3;
	LORDER *ta6;
	long ta1;

	ladder_y.pos+=ladder_y_vel.pos;			// y vel if any

	ladder_x.pos+=ladder_x_vel.pos;			// x vel if anx

	ta10=135<<8;
	ta11=62<<8;

	ta11=ta11/ladder_scale.u.ypos;
	ta10=ta10/ladder_scale.u.xpos;

	ta3=SCX(0x19e)<<8;
	ta3=ta3/ladder_scale.u.xpos;

	ca3=ta3;
	ca11=ta11;
	ca10=ta10;

	ca2=ladder_x.u.intpos;
	
	ta6=(LORDER *)ladder_order;

	/* ladq3 */
	while (ta6->lorder_lst!=NULL)
	{
		scale_ladders(ta6->lorder_lst,ta6->lorder_yoff);
		switch (ta6->lorder_routine)
		{
			case LO_XMINUS:		// x_minus
				ta1=((0x120)<<8)/ladder_scale.u.xpos;
				ca2-=ta1;
				break;
			case LO_X2MINUS:	// x_2minus
				ta1=((0x120)<<8)/ladder_scale.u.xpos;
				ca2-=ta1*2;
				break;
			case LO_XPLUS:		// x_plus
				ta1=((0x120)<<8)/ladder_scale.u.xpos;
				ca2+=ta1;
				break;
			case LO_X2PLUS:		// x_2plus
				ta1=((0x120)<<8)/ladder_scale.u.xpos;
				ca2+=ta1*2;
				break;
		}

		ta6++;
	}

	return;
}

/******************************************************************************
 Function: void scale_ladders();

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa0 - object list to process
			 pa2 - x position to center around

 Returns: None

 Description:	process tower
******************************************************************************/
void scale_ladders(OBJECT *pa0,short pa1)
{
	OBJECT *obj;
	OBJECT *oa0;
	OBJECT *ta7;

	obj=*((OBJECT**)pa0);

	if (obj==NULL)
		return;								// empty list

	while (obj->oslink==NULL)
		obj=obj->olink;

	obj->oypos.u.intpos=ladder_y.u.intpos-(ca11)*pa1;		// starting local
	obj->oxpos.u.intpos=(ca2)-((ca10)>>1);		// center image on screen

	if (obj->oxpos.u.intpos>SCRRGT-SCX(0xf)) 
	{
		/* scale delete */
		*((OBJECT **)pa0)=NULL;
		return;
	}

	oa0=(OBJECT *)obj->oslink;					// ptr to assoc mug
	/* lq3 */
	do
	{
		obj->oscale.yx=ladder_scale.yx;		// update each object
		oa0->oscale.yx=ladder_scale.yx;

		oa0->oxpos.u.intpos=obj->oxpos.u.intpos+(short)((74<<8)/ladder_scale.u.xpos)+1;
		oa0->oypos.u.intpos=obj->oypos.u.intpos+(short)((15<<8)/ladder_scale.u.ypos)+1;

		ta7=obj;				// prev object
		obj=obj->olink;
		if (obj==NULL)
			break;

		oa0=(OBJECT *)obj->oslink;					// ptr to assoc mug
		if (oa0==NULL)
			break;

		obj->oxpos.u.intpos=(ta7)->oxpos.u.intpos;
		obj->oypos.u.intpos=(ta7)->oypos.u.intpos+ca11;
	}
	while(1);

	/* lq9 */
	return;
}

/******************************************************************************
 Function: void get_a_brick(WORD pa0)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa0 - char #

 Returns: current_proc->pa8 - created object

 Description:	draw a brick
******************************************************************************/
void get_a_brick(WORD pa0)
{
	OBJECT *obj;
	OBJECT *obj1;

	gso_dmawnz_ns(obj,(ADDRESS)MKBRICK,select_dict,0,0);
	alloc_cache(MKBRICK,0,obj);
	obj->oyvel.pos=-PANDOWN;
	obj->ozval=0;
	obj->olink=NULL;

	if (pa0 & FT_ENDUR0) 
	{
		pa0=(pa0 & (~FT_ENDUR0))+0x25;
	}

	gso_dmawnz_ns(obj1,ochar_order_mugs[pa0],0,0,0);
	alloc_cache((void *)ochar_order_mugs[pa0],0,obj1);
	obj1->oyvel.pos=-PANDOWN;
	obj1->ozval=1;
	obj1->ochar=0;

	current_proc->a1=(ADDRESS)obj1;
	current_proc->pa8=obj;
	
	(OBJECT *)(obj->oslink)=obj1;
	obj1->oslink=NULL;
	obj1->olink=NULL;

	return;
}

/******************************************************************************
 Function: void set_match_1_diff(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	set match difficulty
******************************************************************************/
short diff_match_1_diffs[]={0,1,2,3};

void set_match_1_diff(void)
{
	stuff_a0_diff((ladder<=3)?diff_match_1_diffs[ladder]:diff_match_1_diffs[3]);
	return;
}

/******************************************************************************
 Function: void init_map_start(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	start the map position
******************************************************************************/
WORD diff_starts[]=
{
	0,
	(1*ENTRIES_0)+1,
	(1*ENTRIES_0)+(1*ENTRIES_1)+1+1,
	(1*ENTRIES_0)+(1*ENTRIES_1)+(1*ENTRIES_2)+1+1+1,
};
void init_map_start(void)
{
	WORD *ta0;

	if ((ta0=ladder_base)==NULL)
		ta0=map_1;							// safety net

	/* im3 */
	current_proc->a1=current_proc->a11;
	map_start=ta0+diff_starts[ladderorder_a1()];	
	return;
}

