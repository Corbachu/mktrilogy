/******************************************************************************
 File: mkpong.c

 Date: Dec 25

 Source: pong.asm (mk2)

 (C) Williams Entertainment


******************************************************************************/

/************************************
Revisions:
	DHS	12/26/95	Created file
************************************/

#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkfx.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkgame.h"
#include "mkguys.h"
#include "mkmain.h"
#include "mkpal.h"
#include "mkend.h"
#include "mkamode.h"
#include "mkjoy.h"
#include "mkinit.h"
#include "mksound.h"

#include "vcache.h"

/************************************
Local Prototypes:
************************************/
WORD pongscore1;		// player 1 score
WORD pongscore2;		// player 2 score
OBJECT *ball;			// ball object
POS	bxv;			// ball xvel
POS byv;			// ball yvel
OBJECT *play1;		// player 1 paddle
OBJECT *play2;		// player 2 paddle
POS globalvx;		// global vel x
POS globalvy1;		// global level y1 (inner hit)
POS globalvy2;		// global level y2 (outer hit)


#define BALL_INITVX 	0x38000
#define BALL_INITVY1 	0x12aaa
#define BALL_INITVY2 	0x25555

OBJECT *digits[28];
#define p1digit1 (&digits[0])
#define p1digit2 (&digits[7])
#define p2digit1 (&digits[14])
#define p2digit2 (&digits[21])

OBJECT *topbar;
OBJECT *bottombar;
OBJECT *centerbar;

#define TOP_LINE_X -5
#define TOP_LINE_Y (18-16)
#define BOTTOM_LINE_X -5
#define BOTTOM_LINE_Y (225-16)
#define LINE_WIDTH	330
#define LINE_HEIGHT 5

#define CENTER_LINE_X (160-3)
#define CENTER_LINE_Y TOP_LINE_Y
#define CLINE_WIDTH	5
#define CLINE_HEIGHT  (BOTTOM_LINE_Y-TOP_LINE_Y+1)

#define PADDLE1_X 12
#define PADDLE1_Y 80

#define PADDLE2_X 294
#define PADDLE2_Y 80

#define PADDLE_HEIGHT	39
#define PADDLE_WIDTH	6

#define BALL_X 90
#define BALL_Y 10
#define BALL_HEIGHT	5
#define BALL_WIDTH	5
#define BALL_DX	24

#define SCREEN_Y_OFF	16

WORD digit_table[]= 
{
	0x1fbf,			//01111110111111,	0
	0x033f,			//00001100111111,	1
	0x36bf,			//11011010111111,	2
	0x27bf,			//10011110111111,	3
	0x2b3f,			//10101100111111,	4
	0x2dbf,			//10110110111111,	5
	0x3dbf,			//11110110111111,	6
	0x073f,			//00011100111111,	7
	0x3fbf,			//11111110111111,	8
	0x2f3f,			//10111100111111,	9
	0x1f86,			//01111110000110,	10
	0x0306,			//00001100000110,	11
	0x3686,			//11011010000110,	12
	0x2786,			//10011110000110,	13
	0x2b06,			//10101100000110,	14
	0x2d86,			//10110110000110,	15
};

WORD segment_table[]=
{
	SCX(0),SCY(26),SCX(21),SCY(6),	//segment 0
	SCX(15),SCY(16),SCX(6),SCY(16),	//segment 1
	SCX(15),SCY(0),SCX(6),SCY(16),	//segment 2
	SCX(0),SCY(0),SCX(21),SCY(6),	//segment 3
	SCX(0),SCY(0),SCX(6),SCY(16),	//segment 4
	SCX(0),SCY(16),SCX(6),SCY(16),	//segment 5
	SCX(0),SCY(13),SCX(21),SCY(6),	//segment 6
};

short digit_start_table[]=
{
	SCX(80),SCY(15),
	SCX(105),SCY(15),
	SCX(275),SCY(15),
	SCX(300),SCY(15),
};

void draw_line(OBJECT *obj) 
{
	if (!(obj->oflags2 & M_INVISO)) 
	{
		gutil_draw_box(obj->oxpos.u.intpos,obj->oypos.u.intpos,obj->header.t_width,obj->header.t_height,0xffff);
	}
	return;
}

void draw_pong(void) 
{
	int i;

	draw_line(topbar);
	draw_line(bottombar);
	draw_line(centerbar);
	for (i=0;i<28;i++)
		draw_line(digits[i]);
	draw_line(play1);
	draw_line(play2);
	draw_line(ball);

	return;
}

OBJECT *put_solid_down(short xsize,short ysize,short xpos,short ypos) 
{

	OBJECT *obj;

	obj=get_object();

	obj->osize.u.xpos=obj->header.t_width=xsize;
	obj->osize.u.ypos=obj->header.t_height=ysize;
	obj->oxpos.u.intpos=xpos;
	obj->oypos.u.intpos=ypos+SCREEN_Y_OFF;		//16 factor to center
	obj->oflags=M_BOX_POLY;
	obj->oflags2=M_NOSCROLL;
	obj->oconst=0xffff;
	
	insert_object(obj,&objlst);
	return(obj);
}						 

void stp3(WORD pa9,OBJECT **ta2) 
{
	int ta1;
	OBJECT *obj;

	pa9=digit_table[pa9];

	ta1=14;
	do
	{
		obj=*ta2++;
		obj->oflags2=(pa9 & 1) ? M_NOSCROLL:M_NOSCROLL|M_INVISO;
		pa9>>=1;
	}
	while(--ta1>0);

	return;
}

void score_to_parts(void) 
{
	stp3(pongscore1,p1digit1);
	stp3(pongscore2,p2digit1);
	return;	
}

void mb_sc(void) 
{
	tsound(randu(3)-1+0x1b);		
	score_to_parts();
	
	/* each point ball goes a little faster */
	globalvx.pos+=((0x0100)*globalvx.pos)>>12;
	globalvy1.pos+=((0x0100)*globalvy1.pos)>>12;
	globalvy2.pos+=((0x0100)*globalvy2.pos)>>12;
	
	if (globalvx.pos>BALL_INITVX*3)
		globalvx.pos=BALL_INITVX*3;

	if (globalvy1.pos>BALL_INITVY1*3)
		globalvy1.pos=BALL_INITVY1*3;

	if (globalvy2.pos>BALL_INITVY2*3)
		globalvy2.pos=BALL_INITVY2*3;
	
	return;
}

void serve_ball_left(void) 
{
	ball->oxpos.u.intpos=PADDLE2_X-BALL_DX;
	ball->oxpos.u.fracpos=0;

	ball->oypos.u.intpos=BALL_Y+SCREEN_Y_OFF+TOP_LINE_Y+LINE_HEIGHT;
	ball->oypos.u.fracpos=0;
	bxv.pos=-globalvx.pos;
	byv.pos=globalvy1.pos;

	return;
}

void serve_ball_right(void) 
{
	ball->oxpos.u.intpos=PADDLE1_X+BALL_DX;
	ball->oxpos.u.fracpos=0;

	ball->oypos.u.intpos=BALL_Y+SCREEN_Y_OFF+TOP_LINE_Y+LINE_HEIGHT;
	ball->oypos.u.fracpos=0;
	bxv.pos=globalvx.pos;
	byv.pos=globalvy1.pos;

	return;
}


WORD score_p1(void) 
{
	pongscore1++;
	if (pongscore1==7)
		return(SYSTEM_CARRY_SET);

	serve_ball_right();
	mb_sc();
	return(SYSTEM_CARRY_CLR);
}

WORD score_p2(void) 
{
	pongscore2++;
	if (pongscore2==7)
		return(SYSTEM_CARRY_SET);

	serve_ball_left();
	mb_sc();
	return(SYSTEM_CARRY_CLR);
}

WORD move_ball(void) 
{
	long ta0,ta1;

	ball->oxpos.pos+=bxv.pos;

	if (ball->oxpos.u.intpos<(PADDLE1_X-BALL_DX))
	{
		return(score_p2());
	}

	if (ball->oxpos.u.intpos>(PADDLE2_X+BALL_DX))
		return(score_p1());

	ball->oypos.pos+=byv.pos;

	if (ball->oypos.u.intpos<(TOP_LINE_Y+LINE_HEIGHT+SCREEN_Y_OFF) || ball->oypos.u.intpos>(BOTTOM_LINE_Y+SCREEN_Y_OFF-BALL_HEIGHT))
	{
		tsound(0xc);			
		byv.pos=-byv.pos;
		ball->oypos.pos+=2*byv.pos;
	}

	/* player 1 collision check 
		a1=ball->oxpos.u.intpos
		a3=ball->oypos.u.intpos
	*/
	ta0=play1->oxpos.pos-ball->oxpos.pos;
	if (ta0>=-SCX(0x50000) && ta0<=SCX(0x50000))
	{
		ta0=-(play1->oypos.pos-ball->oypos.pos);
		if (ta0>=-(0x50000) && ta0<=(0x260000))
		{
			/* hit paddle */
			bxv.pos=globalvx.pos;		// set x vel
			ta1=globalvy2.pos;			// regions -5,5   6,16   17,27   28,38
			if (ta0<=(0x1b0000)) 
			{
				ta1=-ta1;
				if (ta0>(0x60000)) 
				{
					ta1=globalvy1.pos;
					if (ta0<=(0x100000))
						ta1=-ta1;
				}
			}

			byv.pos=(random()>>18)+ta1;

			tsound(0xd);			

		}
	}

	/* not_p1, player 2 collision check 
		a1=ball->oxpos.u.intpos
		a3=ball->oypos.u.intpos
	*/
	ta0=play2->oxpos.pos-ball->oxpos.pos;
	if (ta0>=-SCX(0x50000) && ta0<=SCX(0x50000))
	{
		ta0=-(play2->oypos.pos-ball->oypos.pos);
		if (ta0>=-(0x50000) && ta0<=(0x260000))
		{
			/* hit paddle */
			bxv.pos=-globalvx.pos;		// set x vel
			ta1=globalvy2.pos;			// regions -5,5   6,16   17,27   28,38
			if (ta0<=(0x1b0000))
			{
				ta1=-ta1;
				if (ta0>(0x60000))
				{
					ta1=globalvy1.pos;
					if (ta0<=(0x100000))
						ta1=-ta1;
				}
			}

			byv.pos=(((long)random())>>18)+ta1;

			tsound(0xd);			

		}
	}

	return(SYSTEM_CARRY_CLR);
}

void move_up(OBJECT *obj) 
{
	obj->oypos.u.intpos-=3;
	if (obj->oypos.u.intpos<(TOP_LINE_Y+LINE_HEIGHT+SCREEN_Y_OFF))
		obj->oypos.u.intpos=(TOP_LINE_Y+LINE_HEIGHT+SCREEN_Y_OFF);

	return;
}

void move_down(OBJECT *obj) 
{
	obj->oypos.u.intpos+=3;
	if (obj->oypos.u.intpos>(BOTTOM_LINE_Y-PADDLE_HEIGHT+SCREEN_Y_OFF))
		obj->oypos.u.intpos=(BOTTOM_LINE_Y-PADDLE_HEIGHT+SCREEN_Y_OFF);

	return;
}

void move_paddles(void) 
{
	if (swcurr.u.p1pad & MASK_JUP)
		move_up(play1);

	if (swcurr.u.p1pad & MASK_JDOWN)
		move_down(play1);

	if (swcurr.u.p2pad & MASK_JUP)
		move_up(play2);

	if (swcurr.u.p2pad & MASK_JDOWN)
		move_down(play2);
	
	return;
}

void start_ball(void) 
{
	/* create ball */
	ball=put_solid_down(BALL_WIDTH,BALL_HEIGHT,BALL_X,BALL_Y);

	serve_ball_right();
	return;
}

void init_velocities(void) 
{
	globalvx.pos=BALL_INITVX;
	globalvy1.pos=BALL_INITVY1;
	globalvy2.pos=BALL_INITVY2;
	return;
}

void speed_up_ball(void) 
{
	WORD ta8;

	process_sleep(500);
	
	ta8=6;
	/* sb1 */
	do
	{
		process_sleep(400);
		
		globalvx.pos=((0x1200)*globalvx.pos)>>12;
		globalvy1.pos=((0x1200)*globalvy1.pos)>>12;
		globalvy2.pos=((0x1200)*globalvy2.pos)>>12;
	}
	while(--ta8>0);

	process_suicide();
}

void init_screen(void) 
{
	OBJECT **ta9;
	short *ta1;
	WORD *ta2;
	WORD ta4x,ta4y;
	short ta7,ta6,ta5x,ta5y,ta3x,ta3y;

	murder_myoinit_score();
	
//	dlists=NULL;
	dlists=dlists_bogus;
	irqskye=0;

	/* setup and display screen */
	topbar=put_solid_down(LINE_WIDTH,LINE_HEIGHT,TOP_LINE_X,TOP_LINE_Y);
	bottombar=put_solid_down(LINE_WIDTH,LINE_HEIGHT,BOTTOM_LINE_X,BOTTOM_LINE_Y);
	centerbar=put_solid_down(CLINE_WIDTH,CLINE_HEIGHT,CENTER_LINE_X,CENTER_LINE_Y);

	/* make p1 paddle */
	play1=put_solid_down(PADDLE_WIDTH,PADDLE_HEIGHT,PADDLE1_X,PADDLE1_Y);

	/* make p2 paddle */
	play2=put_solid_down(PADDLE_WIDTH,PADDLE_HEIGHT,PADDLE2_X,PADDLE2_Y);

	/* make p2 digits */
	ta9=digits;
	ta7=4;
	ta1=digit_start_table;
	/* ndig */
	do
	{
		ta5x=*ta1++;
		ta5y=*ta1++;
		ta6=7;
		ta2=segment_table;
		do
		{
			ta4x=*ta2++;
			ta4y=*ta2++;
			ta3x=*ta2++;
			ta3y=*ta2++;
			ta4x+=ta5x;
			ta4y+=ta5y;
			*ta9=put_solid_down(ta3x,ta3y,ta4x,ta4y);
			ta9++;
		}
		while(--ta6>0);
	}
	while(--ta7>0);

	return;
}

void play_pong(void) 
{
	int i;

	send_code_a3(0);
	
	init_screen();
	
	DISPLAY_ON;
	
	CREATE(PID_PONG_SPEED,speed_up_ball);
	pongscore1=pongscore2=0;
	score_to_parts();
	init_velocities();
	start_ball();

	do
	{
		move_paddles();
		
		if (move_ball()==SYSTEM_CARRY_SET)
			break;

		process_sleep(1);
	}
	while(1);

	/* pongover */
	score_to_parts();
	dallprc(PID_PONG_SPEED);

	i=0x80;
	while (--i>0)
	{
		process_sleep(1);
	}

	return;
}

