/******************************************************************************
 File: mkvs.h

 By: David Schwartz

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III vs Player Header
******************************************************************************/

#ifndef __mk_mkvs_h__
#define __mk_mkvs_h__

/*
 * 	DEFINITIONS
 */
#define SSPEED SCX(0x60000)
#define SDIST (SCX(0xb0))


typedef struct vpiece {
	short v_p1x;				// player 1 x off
	short v_p1y;				// player 1 y off
	short v_p2x;				// player 2 x off
	short v_p2y;				// player 2 y off
} VPIECE;

/*
 *	RAM
 */

/*
 *	PROTOTYPES
 */
void vs_or_ladder(void);

void mk_names(void);
void mk_vs(void);
void mk_battle(void);

void mk_bat_signal_f(void);
void mk_bat_signal(void);

void do_mk_number(WORD pa0);

void combination_proc(void);
void slide_in_huge_players(void);
void build_huge_left(WORD pa0);
void setup_direction(LONG pa4);
void start_off_screen(OBJECT *);
void check_button(OBJECT *obj);

OBJECT *make_a_mk_light(short pa9x,short pa9y);

void create_1_piece(BYTE *dict,void *fixupptr,void *pa7,short pa0,short pa1,short pa2);

/*
 *	MACROS
 */

#endif /* __mk_mkvs_h__ */

