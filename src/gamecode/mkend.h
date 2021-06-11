/******************************************************************************
 File: mkend.h

 By: David Schwartz

 Date: Jan 1995

 (C) Williams Entertainment

 Mortal Kombat III endship header
******************************************************************************/

#ifndef __mk_mkend_h__
#define __mk_mkend_h__

/*
 * 	DEFINITIONS
 */
#define BPAL_WHITE 0xffff
#define BPAL_BLACK 0x0001

typedef struct 
{
	short	s_bkgd;
	short	s_p1;
	short	s_p2;
	short	s_p1x;
	short 	s_p2x;
	FUNC	s_p1func;
	FUNC	s_p2func;
	short	s_sleep;
} SCENERIO;

typedef struct sk_ray
{
	void *a_ray;
	short x,y;
} SK_RAY;

typedef struct thankx
{
	char *txt;
	WORD sleep;
} THANKX;

typedef struct dteam
{
	void *t1;
	short x1,y1;
} DTEAM;

#define MAX_ARCADE_CODES	3
#define ARCADE_L1_PROB		2		// depth of easy table to allowed
#define ARCADE_L2_PROB		4		// depth of med table to allowed
#define ARCADE_L3_PROB		6		// depth of hard table allowed
/*
 *	RAM
 */

/*
 *	PROTOTYPES
 */

void shao_kahn_death_fx(void);
void sk_die_background(WORD pa9,WORD pa10,WORD pa11h,WORD pa11l);
void sk_die_pit(WORD pa10,WORD pa11h,WORD pa11l);
void init_and_multi_plane(WORD pa0);

void shao_kahn_dying2(void);
void shao_kahn_dying(void);
void sk_die_setup(void);
void kahn_flash(WORD pa0,void *pa1);

void victory_message(void);
void msg_rise(void);
void winner_msg_rise(void);

void end_of_tournament(void);

void set_objlst2_vel(long pa1);
void sk_ray1(void);
void sk_ray2(void);
void sk_ray3(void);
void sk_ray_setup(void);

void select_yer_ending(void);

void do_normal_ending(void);
void do_random_prize(void);
void do_space_game(void);
void do_pong_game(void);
void do_fatality_tour_1(void);
void do_fatality_tour_2(void);
void do_fatality_tour_3(void);
void do_fatality_tour_4(void);
void do_fatality_tour_5(void);
void do_fatality_tour_6(void);
void do_fatality_tour_7(void);
void do_animality_tour_1(void);
void do_animality_tour_2(void);
void do_animality_tour_3(void);
void do_baby_tour_1(void);
void do_friend_tour_1(void);
void do_all_fatals(void);
void fatl3(SCENERIO *pa11,char *pa8,char *pa10);

void select_retp(void);
void print_paragraph(BYTE **ta11);
void scroll_paragraph(BYTE *ta11);

void mk3_cast_o_characters(void);
OBJECT *make_ending_char(WORD pchar,WORD pcount);
void take_a_bow(void);
void wake_me_up(void);
void run_away(void);


void mk3_thank_you(void);
void set_letter_vel(void);
void text_deleter(void);

void mk3_design_team(DTEAM *);
void team_print(DTEAM *pa0);

/*
 *	MACROS
 */
extern DTEAM arcade_team_table[];
extern DTEAM sony_team_table[];

#endif /* __mk_mkend_h__ */

