/******************************************************************************
 File: mkladder.h

 By: David Schwartz

 Date: Mar 1995

 (C) Williams Entertainment

 Mortal Kombat III ladder Player Header
******************************************************************************/

#ifndef __mk_mkladder_h__
#define __mk_mkladder_h__

/* 
 * 	DEFINITIONS
 */
#define PANDOWN	SCY(0x30000)

#define ORIGIN_X	(SCX(0x4a)<<16)
#define ORIGIN_Y	(SCY(0x65)<<16)
#define BADGE_X_JUMP	(0x48)

#define ENTRIES_0	8
#define ENTRIES_1	9
#define ENTRIES_2	10
#define ENTRIES_3	11

#define LAST_ENTRY_0	((ENTRIES_0-1)*1)
#define LAST_ENTRY_1	((ENTRIES_0+ENTRIES_1-1)*1+1)
#define LAST_ENTRY_2	((ENTRIES_0+ENTRIES_1+ENTRIES_2-1)*1+1+1)
#define LAST_ENTRY_3	((ENTRIES_0+ENTRIES_1+ENTRIES_2+ENTRIES_3-1)*1+1+1+1)

typedef struct
{
	WORD	dbs_le;
	WORD	dbs_ent;
	OBJECT *dbs_lst;
} DBS;

typedef struct mhe_ord 
{
	OBJECT *olist;			// object list
	short 	bskip;			// # of blocks to skip
	FUNC routine;			// routine to run
} MHE_ORD;


/* 
 *	RAM 
 */
__EXTERN__ XYTYPE ladder_scale;
__EXTERN__ POS ladder_y;
__EXTERN__ POS ladder_y_vel;
__EXTERN__ POS ladder_x;
__EXTERN__ POS ladder_x_vel;
__EXTERN__ short ladder_left_x;
__EXTERN__ short ladder_right_x;
__EXTERN__ LONG ladder_order;			
__EXTERN__ WORD *ladder_base;
__EXTERN__ short ladder;

/*
 *	PROTOTYPES 
 */
void mk_ladder(void);

void setup_close_ladder(void);
void setup_distant_ladder(void);
void build_tower(DBS *ta0);
void ladder_switch_scan(void);
void tower_picked_fx(void);
void up_ewe_go(WORD *pa9);
void pan_to_pick_tower(void);
void zoom_in(void);
void pan_down(void);
OBJECT *solid_backdrop_box(void);
ADDRESS get_player_ochar_a5(void);
void create_base_object(void);
void move_dragon_logo(short pa1);
void base_offset_obj(ADDRESS pa5,short pa6,short pa7);

void ladder_irq(void);
void scale_ladders(OBJECT *pa0,short pa1);
void fx_tower_flash(void);
void get_a_brick(WORD pa0);

void set_match_1_diff(void);
void init_map_start(void);
void ladder_badge_spinner(void);

/*
 *	MACROS
 */
#endif /* __mk_mkladder_h__ */

