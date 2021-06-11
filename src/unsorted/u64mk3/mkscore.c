/******************************************************************************
 File: mkscore.c

 Date: Dec 1994

 (C) Williams Entertainment

 Mortal Kombat III vs Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkmain.h"
#include "mkguys.h"
#include "mkgame.h"
#include "mkbkgd.h"
#include "mkobj.h"
#include "mkdma.h"
#include "mkscore.h"
#include "mkdiag.h"
#include "mkpal.h"
#include "mksound.h"
#include "mkfx.h"
#include "vcache.h"
#include "wessapi.h"

extern OIMGTBL *control_panel_info[];
extern OIMGTBL *name_anim_imgs[];

short p2_powerbar_names[] =
{
	SCX(0x0153)-2,				// p kano
	SCX(0x014c)-2,				// p sonya
	SCX(0x015a)-2,				// p jax
	SCX(0x0132)-2,				// p nightwolf
	225,				// p cage
	SCX(0x0140)-2,				// p stryker
	SCX(0x0149)-2,				// p sindle
	SCX(0x0149)-2,				// p sektor
	SCX(0x0149)-2,				// p cyrax
	SCX(0x0139)-2,				// p kunglao
	SCX(0x014f)-2,				// p kabal
	SCX(0x0149)-2,				// p sheeva
	SCX(0x0123)-2,				// p shang tsung
	SCX(0x013d)-2,				// p liu kang
	SCX(0x0149)-2,				// p smoke
	265-4,				// p kitana
	273-4,				// p jade
	259-4,				// p mileena
	252-4,				// p scorpion
	263-4-8,				// p reptile
	266-4,				// p ermac
	SCX(0x013c)-2,				// p old subzero
	SCX(0x0149)-2,				// p old smoke
	SCX(0x0127)-2,				// p noob

	265-4-8,				// p RAyde	-u64-
	265-4-8,				// p bara
	SCX(0x153)-2,				// p RAIN

	SCX(0x0132)-2-9,				// p kamel
	252-4,				// p scorpion
	263-4-8,				// p reptile

	SCX(0x0144)-2,				// p motaro
	SCX(0x0132)-2,				// p shao
};

BYTE score_nums_tbl[]=
{
	X_SHADNUM0,
	X_SHADNUM1,
	X_SHADNUM2,
	X_SHADNUM3,
	X_SHADNUM4,
	X_SHADNUM5,
	X_SHADNUM6,
	X_SHADNUM7,
	X_SHADNUM8,
	X_SHADNUM9
};

BYTE clock_nums[] =
{
	COUNTDOWN_0,
	COUNTDOWN_1,
	COUNTDOWN_2,
	COUNTDOWN_3,
	COUNTDOWN_4,
	COUNTDOWN_5,
	COUNTDOWN_6,
	COUNTDOWN_7,
	COUNTDOWN_8,
	COUNTDOWN_9
};

/******************************************************************************
 Function: void setup_score_ram(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	init things so we can display the score area stuff
******************************************************************************/
void setup_score_ram(void)
{
	CPENTRY *sr_ptr;

	f_doscore=0;					// flag: dont do score area DMAS
	sr_ptr=score_ram;

	/* win knotches (4 entries, 1-2-3-4) */
	SET_SCORE_RAM(sr_ptr,P1_K1_X,P_KNOTCH_Y,MKMEDAL2,0);		// p1 notch #1 = NULL
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P1_K2_X,P_KNOTCH_Y,MKMEDAL2,0);		// p1 notch #2 = NULL
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_K1_X,P_KNOTCH_Y,MKMEDAL2,0);		// p2 notch #1 = NULL
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_K2_X,P_KNOTCH_Y,MKMEDAL2,0);		// p2 notch #2 = NULL
	sr_ptr++;

	/* coin message/ player score (2 entries) (5-6) */
	SET_SCORE_RAM(sr_ptr,0,0,BAR_NULL,0);		// p1 = null entry
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,0,0,BAR_NULL,0);		// p2 = null entry
	sr_ptr++;

	/* clock digits (2 entries) (7-8) */
	SET_SCORE_RAM(sr_ptr,CLOCK_TENS_X,CLOCK_TENS_Y,COUNTDOWN_9,1);		// clock tens init with 9
	sr_ptr++;

	SET_SCORE_RAM(sr_ptr,CLOCK_ONES_X,CLOCK_ONES_Y,COUNTDOWN_9,1);		// clock ones init with 9
	sr_ptr++;

	/* score digits for player "# of wins" (6 entries) (9-10-11-12-13-14) */
	SET_SCORE_RAM(sr_ptr,P1_MSG_X+0*DIGIT_SIZE,P1_MSG_Y,X_SHADNUM0,1);		// p1 digit #1 (hundreds)
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P1_MSG_X+1*DIGIT_SIZE,P1_MSG_Y,X_SHADNUM0,1);		// p1 digit #1 (tens)
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P1_MSG_X+2*DIGIT_SIZE,P1_MSG_Y,X_SHADNUM0,1);		// p1 digit #1 (ones)
	sr_ptr++;

	SET_SCORE_RAM(sr_ptr,P2_MSG_X+0*DIGIT_SIZE,P2_MSG_Y,X_SHADNUM0,1);		// P2 digit #1 (hundreds)
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_MSG_X+1*DIGIT_SIZE,P2_MSG_Y,X_SHADNUM0,1);		// P2 digit #1 (tens)
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_MSG_X+2*DIGIT_SIZE,P2_MSG_Y,X_SHADNUM0,1);		// P2 digit #1 (ones)
	sr_ptr++;

	/* backdrops for powerbars (2 entries) (15-16) */
	SET_SCORE_RAM(sr_ptr,P1_BACKBAR_X,BACKBAR_Y,PWRBAR_LA,1);		// p1 bar backdrop
	sr_ptr++;

	SET_SCORE_RAM(sr_ptr,P2_BACKBAR_X,BACKBAR_Y,PWRBAR_RA,1);		// p2 bar backdrop
	sr_ptr++;

	/* solid color powerbars (2 entries) (17-18) */
	SET_SCORE_RAM(sr_ptr,P1_BACKBAR_X,BACKBAR_Y,P1_BACKPWR_SPEC,get_safe_powerbar(&p1_bar));		// p1 backdrop for powerbar
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_BACKBAR_X+BACKBAR_WIDTH-1,BACKBAR_Y,P2_BACKPWR_SPEC,get_safe_powerbar(&p2_bar));		// p2 backdrop for powerbar
	sr_ptr++;

	/* turbo bars (19-20) */
	SET_SCORE_RAM(sr_ptr,P1_TURBO_X+1-CENTER_OFFSET,P1_TURBO_Y+1,P1_TURBO_SPEC,1);
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,P2_TURBO_X+TURBOBAR_WIDTH-1+CENTER_OFFSET,P2_TURBO_Y+1,P2_TURBO_SPEC,1);
	sr_ptr++;
   
	/* character names in front of powerbars (2 entries) (21-22) */
	SET_SCORE_RAM(sr_ptr,2+SCX(0x19)+CENTER_OFFSET,SCY(0x1a)+18,P1_NAME_SPEC,1);		// p1 name
	sr_ptr++;
	SET_SCORE_RAM(sr_ptr,p2_powerbar_names[p2_name_char]+2-CENTER_OFFSET,SCY(0x1a)+18,P2_NAME_SPEC,1);		// p2 name
	sr_ptr++;

	return;

}

/******************************************************************************
 Function: void update_win_counters(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	update p1 & p2 win counters
******************************************************************************/
void update_win_counters(void)
{
	/* update player 1*/
	if (p1_state==PS_ACTIVE)
	{
		uwc_stuff(p1_wiar,entry_9,P1_MSG_X+SCX(0x2d),P1_MSG_Y);

		entry_6->x0=P1_MSG_X;				// coordinate for player 1 "WINS:" image
		entry_6->y0=P1_MSG_Y;
	}

	/* update player 2*/
	if (p2_state==PS_ACTIVE)
	{
		uwc_stuff(p2_wiar,entry_12,P2_MSG_X-SCX(0x0e),P2_MSG_Y);

		entry_5->y0=P2_MSG_Y;				// coordinate for player 1 "WINS:" image

		if (p2_wiar>100)
			entry_5->x0=P2_MSG_X-SCX(0x3a)-DIGIT_SIZE;
		else entry_5->x0=P2_MSG_X-SCX(0x3a);
	}

	return;
}

/******************************************************************************
 Function: void uwc_stuff(WORD pwiar,CPENTRY *sr_ptr,WORD xpos,WORD ypos)

 By: David Schwartz

 Date: Dec 1994

 Parameters: pwiar - # of wins in a row
			 sr_ptr - ptr to start of score ram to fill
		  	 xpos - x position for message
			 ypos - y position for message

 Returns: None

 Description:	setup ram entry for wins counter stuff
******************************************************************************/
void uwc_stuff(WORD pwiar,CPENTRY *sr_ptr,WORD xpos,WORD ypos)
{
	short h_flag=0;
	WORD digit;
	short adjust;

	/* clear ones, tens, hundreds digit display */
	(sr_ptr+0)->disp_flag=0;
	(sr_ptr+1)->disp_flag=0;
	(sr_ptr+2)->disp_flag=0;

	/* make each digit prove it should be displayed */
	if ((digit=(pwiar/100))!=0)
	{
		h_flag=1;
		pwiar%=100;							// take off 100's

		/* update_score_digit (100's) */
		adjust=(digit==1)?2:0;				// if 1's digit then nudge coord
		SET_SCORE_RAM(sr_ptr,xpos+adjust,ypos,score_nums_tbl[digit],1);
		xpos+=DIGIT_SIZE;
	}

	sr_ptr++;								// next entry

	digit=(pwiar/10);
	//if ((digit=(pwiar/10))!=0) // || h_flag==1)
	{
		pwiar%=10;							// take off 10's

		/* update_score_digit (10's) */
		adjust=(digit==1)?2:0;				// if 1's digit then nudge coord
		SET_SCORE_RAM(sr_ptr,xpos+adjust,ypos,score_nums_tbl[digit],1);
		xpos+=DIGIT_SIZE;
	}

	sr_ptr++;								// next entry
	digit=pwiar;

	/* update_score_digit (1's) */
	adjust=(digit==1)?2:0;				// if 1's digit then nudge coord
	SET_SCORE_RAM(sr_ptr,xpos+adjust,ypos,score_nums_tbl[digit],1);
	xpos+=DIGIT_SIZE;

	return;
}

/******************************************************************************
 Function: void update_clock_digit(CPENTRY *sr_ptr,WORD xpos,WORD ypos,WORD digit)

 By: David Schwartz

 Date: Dec 1994

 Parameters: sr_ptr - score ram entry
			 xpos - xpos of digit
			 ypos - ypos of digit
			 digit - digit to display

 Returns: None

 Description:	update a clock digit
******************************************************************************/
void update_clock_digit(CPENTRY *sr_ptr,WORD xpos,WORD ypos,WORD digit)
{
	short adjust;

	adjust=(digit==1)?2:0;				// if 1's digit then nudge coord
	SET_SCORE_RAM(sr_ptr,xpos+adjust,ypos,clock_nums[digit],1);
}

/******************************************************************************
 Function: void update_knotches(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	updates the ram so the correct "knotches" state
                is represented in the score area.
******************************************************************************/
void update_knotches(void)
{
	switch (p1_matchw)
	{
		case 0:
			p1_knotch1->disp_flag=0;
			p1_knotch2->disp_flag=0;
			break;
		case 1:
			p1_knotch1->disp_flag=1;
			p1_knotch2->disp_flag=0;
			break;
		case 2:
			p1_knotch1->disp_flag=1;
			p1_knotch2->disp_flag=1;
			break;
	}

	switch (p2_matchw)
	{
		case 0:
			p2_knotch1->disp_flag=0;
			p2_knotch2->disp_flag=0;
			break;
		case 1:
			p2_knotch1->disp_flag=1;
			p2_knotch2->disp_flag=0;
			break;
		case 2:
			p2_knotch1->disp_flag=1;
			p2_knotch2->disp_flag=1;
			break;
	}
}

/******************************************************************************
 Function: void qwerty(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	update the powerbar dither every vblank
******************************************************************************/
void qwerty(void)
{

#if 0			// routine not needed since, we are using hardware to do what that do here
	if (entry_21->cpentry==PWRBAR_LA)
	{
		entry_21->cpentry=PWRBAR_LA;	//b
		entry_22->cpentry=PWRBAR_RA;
	}
	else
	{
		entry_21->cpentry=PWRBAR_LA;
		entry_22->cpentry=PWRBAR_RA;
	}
#endif

	return;
}

/******************************************************************************
 Function: void update_pmsg(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	Update player messages
******************************************************************************/
void update_pmsg(void)
{
	PROCESS *ptemp;

	/* player 1 message */
	if (p1_state==PS_ACTIVE)
	{
		SET_SCORE_RAM(entry_6,SCX(0x0034),18+SCY(0x000c),X_SHADWINS,1);
	}
	else
	{
		entry_9->disp_flag=0;
		entry_10->disp_flag=0;
		entry_11->disp_flag=0;
		SET_SCORE_RAM(entry_6,P1_SIC_X,P1_SIC_Y,start_or_insertcoin(),1);
	}

	/* player 2 message */
	if (p2_state==PS_ACTIVE)
	{
		SET_SCORE_RAM(entry_5,SCX(0x012d),18+SCY(0x000c),X_SHADWINS,1);
	}
	else
	{
		entry_12->disp_flag=0;
		entry_13->disp_flag=0;
		entry_14->disp_flag=0;
		SET_SCORE_RAM(entry_5,P2_SIC_X,P2_SIC_Y,start_or_insertcoin(),1);
	}

	if ((ptemp=process_exist(PID_FLASHER,0xffff))!=NULL)
		fastxfer(ptemp,flash_pmsg2);
}

/******************************************************************************
 Function: WORD start_or_insertcoin(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: display index

 Description:	determine which message to display based on # of credits
******************************************************************************/
WORD start_or_insertcoin(void)
{
#if 0
	if (cr_strtp()==FALSE)
		return(INSERT_COIN);
	else return(PUSHSTART);
#endif
	return(PUSHSTART);
}

/******************************************************************************
 Function: void recharge_bars(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	give both players full power and cancel any bar drop values
******************************************************************************/
void recharge_bars(void)
{
	p1_bar=p1_bar_view=FULL_STRENGTH;
	p2_bar=p2_bar_view=FULL_STRENGTH;

	p1_turbo=p1_turbo_view=FULL_TURBO;
	p2_turbo=p2_turbo_view=FULL_TURBO;

	position_p2_bar();

	return;
}

/******************************************************************************
 Function: void position_p2_bar(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	pos p2 turbo and power bar
******************************************************************************/
void position_p2_bar(void)
{
	p2_bar_xpos=FULL_STRENGTH-p2_bar_view+P2_BACKBAR_X+1;

	p2_turbo_xpos=FULL_TURBO-p2_turbo_view+P2_TURBO_X+1;

	return;
}

extern void *AGRESSOR1[];
extern void *a_agressor[];
extern BYTE control_dict[];
extern WORD f_blast;
void agressor_flash(void) 
{
	OBJECT *obj;
	PROCESS *ptemp;
	int player=current_proc->a10;
	short dtemp;
	
	p_agressor_view[player]=0;
	
	/* make drones more difficult */
	ptemp=(player==0)?p1_proc:p2_proc;
	dtemp=diff;
	if ((ptemp->pdata.p_flags & PM_JOY)==0)
		stuff_a0_diff(dtemp+2);
		
	/* create object */
	gso_dmawnz(obj,(ADDRESS)AGRESSOR1,control_dict,0,0);
	alloc_cache(AGRESSOR1,0,obj);
	obj->oxpos.u.intpos=p_agressor_x[player];
	obj->oypos.u.intpos=p_agressor_y[player];
	set_noscroll(obj);
	obj->oid=OID_BLOOD;
	insert_object(obj,&objlst2);
	
	/* trigger sound effect */
	tsound(0x99);
	
	/* animate */
	current_proc->a10=7;
	do
	{
		init_anirate(8);
		current_proc->pa9=a_agressor;
		do
		{
			p_agressor_active[player]=AGRESS_WAIT;
			next_anirate();
			process_sleep(1);
		}
		while(GET_LONG(current_proc->pa9)!=ANI_END);
	}
	while(--current_proc->a10>0);
	
	obj->oxvel.pos=(player==0)?-SCX(0xe0000):SCX(0xe0000);
	p_agressor_active[player]=AGRESS_END;
	process_sleep(15);

	/* signal that agressor can rebuild */
	p_agressor_active[player]=AGRESS_NORMAL;
	
	stuff_a0_diff(dtemp);
	
	/* remove */
	delobjp2(obj);
	
	process_suicide();
}

void update_agressor(short player) 
{
	OIMGTBL *img;
	PROCESS *ptemp;
	
	if (p_agressor_active[player]!=AGRESS_NORMAL)
		return;
		
	/* update display agressor bar */
	p_agressor_view[player]=p_agressor[player];
	
	/* hit peak got for the kill */
	if (p_agressor_view[player]>=(AGRESSOR_SIZE<<8) && f_blast==0) 
	{
		p_agressor_active[player]=AGRESS_WAIT;
		p_agressor_view[player]=0;			// size 0, let flasher process set to continue
		p_agressor[player]=0;
		CREATE((player==0)?PID_AGRESSOR1:PID_AGRESSOR2,agressor_flash)->a10=player;
		ptemp=create_fx(FX_AGRESSOR);
		ptemp->a11=player;
		ptemp->pa8=(player==0)?p1_obj:p2_obj;
	}
	
	/* draw the agressor */
	if ((p_agressor_view[player]>>8)!=0)
	{
		img=(OIMGTBL *)AGRESSOR1;
		DrawObj.dp_palptr=&pal_buffer[(score_pal*2)*(256/sizeof(u64))];
		DrawObj.dp_scx=DrawObj.dp_scy=0x0100;
		DrawObj.dp_lclip=0;
		DrawObj.dp_x=p_agressor_x[player];
		DrawObj.dp_y=p_agressor_y[player];
	
		DrawObj.dp_imgptr=uncompress_image(img->isagptr,control_dict);
		DrawObj.dp_h=img->size.u.ypos;
		DrawObj.dp_w=img->size.u.xpos;
		DrawObj.dp_flags=0;
		DrawObj.dp_rclip=AGRESSOR_SIZE-(p_agressor_view[player]>>8);

		gutil_draw_object();			
	}
	
	return;
}

void reset_aggressor(void)
{
	p_agressor_active[0]=p_agressor_active[1]=0;
	p_agressor_view[0]=p_agressor_view[1]=0;
	p_agressor[0]=p_agressor[1]=0;
}

/******************************************************************************
 Function: void update_control_panel

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	This routine updates the control panel.  The panel consists of:
			1)	p1 & p2 win knotches
			2)	p1 & p2 coin messages (start pause etc)
			3)	p1 & p2 character names
			4)	p1 & p2 power bars
			5)	clock digits (10's 1's)
			6)	p1 wins (100's 10's 1's)
			7)	p2 wins (100's 10's 1's)
******************************************************************************/
/******************************************************************************
 Function: void update_control_panel

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	This routine updates the control panel.  The panel consists of:
			1)	p1 & p2 win knotches
			2)	p1 & p2 coin messages (start pause etc)
			3)	p1 & p2 character names
			4)	p1 & p2 power bars
			5)	clock digits (10's 1's)
			6)	p1 wins (100's 10's 1's)
			7)	p2 wins (100's 10's 1's)
******************************************************************************/
extern WORD title_song;
void update_control_panel(void)
{
	short loop;
	CPENTRY *sr_ptr;
	OIMGTBL *img;

	/* setup parameters that dont change */
	DrawObj.dp_scx=DrawObj.dp_scy=0x0100;
	DrawObj.dp_lclip=DrawObj.dp_rclip=0;

	for (loop=0;loop<SCORE_RAM_CNT;loop++)
	{
		sr_ptr=score_ram+loop;
		
		/* setup position */
		DrawObj.dp_x=sr_ptr->x0;
		DrawObj.dp_y=sr_ptr->y0;
		
		if (sr_ptr->disp_flag!=0)
		{
			DrawObj.dp_palptr=&pal_buffer[(score_pal*2)*(256/sizeof(u64))];
			switch (sr_ptr->cpentry)
			{
				case P1_BACKPWR_SPEC:
					/* draw red background bar (xlu) */
					gutil_draw_xlu_box(sr_ptr->x0+1,sr_ptr->y0+1,FULL_STRENGTH*80/100,POWERBAR_Y_SIZE+1,0xf801,128);
					
					if (p1_bar_view!=0)
						gutil_draw_box(sr_ptr->x0+1,sr_ptr->y0+1,(p1_bar_view*80/100),POWERBAR_Y_SIZE,0x003f);
					img=NULL;
					break;

				case P2_BACKPWR_SPEC:
					/* draw red background bar (xlu) */
					gutil_draw_xlu_box(sr_ptr->x0-(FULL_STRENGTH*80/100),sr_ptr->y0+1,(FULL_STRENGTH*80/100),POWERBAR_Y_SIZE+1,0xf801,128);
					
					if (p2_bar_view!=0)
						gutil_draw_box(sr_ptr->x0-(p2_bar_view*80/100),sr_ptr->y0+1,(p2_bar_view*80/100),POWERBAR_Y_SIZE,0x003f);
					img=NULL;
					break;

				case P1_TURBO_SPEC:
					/* draw red background bar (xlu) */
					gutil_draw_xlu_box(sr_ptr->x0,sr_ptr->y0,TURBOBAR_WIDTH,TURBOBAR_Y_SIZE+1,0xf801,128);
					
					if (p1_turbo_view!=0)
						gutil_draw_box(sr_ptr->x0,sr_ptr->y0,(p1_turbo_view*80/100),TURBOBAR_Y_SIZE,0x05c1);
					img=NULL;
					break;

				case P2_TURBO_SPEC:
					/* draw red background bar (xlu) */
					gutil_draw_xlu_box(sr_ptr->x0-(TURBOBAR_WIDTH),sr_ptr->y0,(TURBOBAR_WIDTH),TURBOBAR_Y_SIZE+1,0xf801,128);
				
					if (p2_turbo_view!=0)
						gutil_draw_box(sr_ptr->x0-(p2_turbo_view*80/100),sr_ptr->y0,(p2_turbo_view*80/100),TURBOBAR_Y_SIZE,0x05c1);
					img=NULL;
					break;

				case P1_NAME_SPEC:
					img=name_anim_imgs[p1_name_char];
					if (p1_name_char==FT_KAMEL) 
					{
						if (p1_obj!=NULL) 
						{
							switch (p1_obj->ochar)
							{
								case FT_JADE:
									DrawObj.dp_palptr=&pal_buffer[(jade_pal*2)*(256/sizeof(u64))];
									break;
								case FT_MILEENA:
									DrawObj.dp_palptr=&pal_buffer[(mil_pal*2)*(256/sizeof(u64))];
									break;
								case FT_KITANA:
									DrawObj.dp_palptr=&pal_buffer[(kit_pal*2)*(256/sizeof(u64))];
									break;
							}
						}
					}
					break;
				case P2_NAME_SPEC:
					img=name_anim_imgs[p2_name_char];
					if (p2_name_char==FT_KAMEL) 
					{
						if (p2_obj!=NULL) 
						{
							switch (p2_obj->ochar)
							{
								case FT_JADE:
									DrawObj.dp_palptr=&pal_buffer[(jade_pal*2)*(256/sizeof(u64))];
									break;
								case FT_MILEENA:
									DrawObj.dp_palptr=&pal_buffer[(mil_pal*2)*(256/sizeof(u64))];
									break;
								case FT_KITANA:
									DrawObj.dp_palptr=&pal_buffer[(kit_pal*2)*(256/sizeof(u64))];
									break;
							}
						}
					}
					break;
				case BAR_NULL:
					img=NULL;
					break;
				default:
					img=control_panel_info[sr_ptr->cpentry];
					break;
			}
			
			/* Draw Object */
			if (img!=NULL)
			{
				DrawObj.dp_imgptr=uncompress_image(img->isagptr,control_dict);
				DrawObj.dp_w=img->size.u.xpos;
				DrawObj.dp_h=img->size.u.ypos;
			
				if (sr_ptr->cpentry!=PWRBAR_RA)
					DrawObj.dp_flags=0;
				else DrawObj.dp_flags=M_FLIPH;

				gutil_draw_object();			// draw object
			}
		}
	}

//	if (f_pause<PAUSE_OFF || f_pause==PAUSE_P1_INIT || f_pause==PAUSE_P2_INIT)
//	{
		if (f_doagress && f_opt_agress && title_song==0)
		{
			update_agressor(0);
			update_agressor(1);
		}
		else
		{
			p_agressor[0]=p_agressor[1]=0;
			p_agressor_view[0]=	p_agressor_view[1]=0;
			p_agressor_active[0]=p_agressor_active[1]=0;
		}
//	}

	return;
}

/******************************************************************************
 Function: void refresh_score(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	reinit the score panel stuff
******************************************************************************/
void refresh_score(void)
{
	setup_score_ram();
	SHOW_SCORES;
	update_knotches();
	update_pmsg();
	update_win_counters();
	return;
}

