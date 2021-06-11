/******************************************************************************
 File: mkinit.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Initialization and Main Loop Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"
#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkdma.h"
#include "mkgame.h"
#include "mkinit.h"
#include "mkmain.h"
#include "mkutil.h"
#include "mkguys.h"
#include "mkani.h"
#include "mkjoy.h"
#include "mkdiag.h"
#include "mkend.h"
#include "mkamode.h"
#include "moves.h"
#include "mkreact.h"
#include "mkscore.h"
#include "mkbug.h"
#include "mktext.h"
#include "mkdiag.h"
#include "mksound.h"
#include "mkpal.h"
#include "mkfade.h"
#include "mkfx.h"

#include "gdefaults.h"
#include "gutil.h"

#include "vcache.h"
#include "bench.h"

extern WORD mk_dbug;

typedef struct
{
	WORD pid;									/* process id */
	JUMPTBL proc_func;							/* function to excute */
} SWTAB;

static SWTAB swtab[64] =
{
	{0,NULL},								/* open 0 */
	{0,NULL},								/* open 1 */
	{PID_SWITCH1,p1_button5_open},			/* open 2, PLAYER 1 RUN */
	{PID_SWITCH1,p1_button2_open},			/* open 3, PLAYER 1 BLOCK */
	{PID_SWITCH1,p1_button0_open},			/* open 4, PLAYER 1 HI PUNCH */
	{PID_SWITCH1,p1_button3_open},			/* open 5, PLAYER 1 HI KICK */
	{PID_SWITCH1,p1_button4_open},			/* open 6, PLAYER 1 LOW KICK */
	{PID_SWITCH1,p1_button1_open},			/* open 7, PLAYER 1 LOW PUNCH */
	{0,NULL},								/* open 8 */
	{0,NULL},								/* open 9 */
	{0,NULL},								/* open a */
	{PID_SWITCH1,p1_start_open},			/* open b, clear pause thaw state */
	{0,NULL},								/* open c */
	{0,NULL},								/* open d */
	{0,NULL},								/* open e */
	{0,NULL},								/* open f */
	{0,NULL},								/* open 10 */
	{0,NULL},								/* open 11 */
	{PID_SWITCH2,p2_button5_open},			/* open 12, PLAYER 2 RUN */
	{PID_SWITCH2,p2_button2_open},			/* open 13, PLAYER 2 BLOCK */
	{PID_SWITCH2,p2_button0_open},			/* open 14, PLAYER 2 HI PUNCH */
	{PID_SWITCH2,p2_button3_open},			/* open 15, PLAYER 2 HI KICK */
	{PID_SWITCH2,p2_button4_open},			/* open 16, PLAYER 2 LOW KICK */
	{PID_SWITCH2,p2_button1_open},			/* open 17, PLAYER 2 LOW PUNCH */
	{0,NULL},								/* open 18 */
	{0,NULL},								/* open 19 */
	{0,NULL},								/* open 1a */
	{PID_SWITCH2,p2_start_open},			/* open 1b, clear pause thaw state */
	{0,NULL},								/* open 1c */
	{0,NULL},								/* open 1d */
	{0,NULL},								/* open 1e */
	{0,NULL},								/* open 1f */
	{PID_SWITCH1,p_profile},				/* close 20/0, poor mans profile */
	{PID_SWITCH1,p_grid},					/* close 21/1, grid */
	{PID_SWITCH1,p1_button5},				/* close 22/2, PLAYER 1 RUN */
	{PID_SWITCH1,p1_button2},				/* close 23/3, PLAYER 1 BLOCK */
	{PID_SWITCH1,p1_button0},				/* close 24/4, PLAYER 1 HI PUNCH */
	{PID_SWITCH1,p1_button3},				/* close 25/5, PLAYER 1 HI KICK */
	{PID_SWITCH1,p1_button4},				/* close 26/6, PLAYER 1 LOW KICK */
	{PID_SWITCH1,p1_button1},				/* close 27/7, PLAYER 1 LOW PUNCH */
	{PID_SWITCH1,p_colbox},					/* close 28/8, collision box */
	{PID_SWITCH1,p_profile},				/* close 29/9, poor mans profile */
	{PID_SWITCH1,p_grid},					/* close 2a/a, grid */
	{PID_SWITCH1,p1_start_button},			/* close 2b/b, PLAYER 1 START */
	{PID_SWITCH1,p1_joy_up},  				/* close 2c/c, PLAYER 1 JOYSTICK UP */
	{PID_SWITCH1,p1_joy_right},				/* close 2d/d, PLAYER 1 JOYSTICK RIGHT */
	{PID_SWITCH1,p1_joy_down},				/* close 2e/e, PLAYER 1 JOYSTICK DOWN */
	{PID_SWITCH1,p1_joy_left},				/* close 2f/f, PLAYER 1 JOYSTICK LEFT */
	{PID_SWITCH2,p_profile},				/* close 30/10, poor mans profile */
	{PID_SWITCH2,p_grid},					/* close 31/11, grid */
	{PID_SWITCH2,p2_button5},				/* close 32/12, PLAYER 2 RUN */
	{PID_SWITCH2,p2_button2},				/* close 33/13, PLAYER 2 BLOCK */
	{PID_SWITCH2,p2_button0},				/* close 34/14, PLAYER 2 HI PUNCH */
	{PID_SWITCH2,p2_button3},				/* close 35/15, PLAYER 2 HI KICK */
	{PID_SWITCH2,p2_button4},				/* close 36/16, PLAYER 2 LOW KICK */
	{PID_SWITCH2,p2_button1},				/* close 37/17, PLAYER 2 LOW PUNCH */
	{PID_SWITCH2,p_colbox},					/* close 38/18, collision box */
	{PID_SWITCH2,p_profile},				/* close 39/19, poor mans profile */
	{PID_SWITCH2,p_grid},					/* close 3a/1a, grid */
	{PID_SWITCH2,p2_start_button},			/* close 3b/1b, PLAYER 2 START */
	{PID_SWITCH2,p2_joy_up},  				/* close 3c/1c, PLAYER 2 JOYSTICK UP */
	{PID_SWITCH2,p2_joy_right},				/* close 3d/1d, PLAYER 2 JOYSTICK RIGHT */
	{PID_SWITCH2,p2_joy_down},				/* close 3e/1e, PLAYER 2 JOYSTICK DOWN */
	{PID_SWITCH2,p2_joy_left}				/* close 3f/1f, PLAYER 2 JOYSTICK LEFT */

};

extern void floor_code_setup(void);
void mk_joystick(void);

extern u64 gfx_ybuf[];

OSTask	vid_rsptask =						/* Task descriptor */
{
    M_GFXTASK,			/* task type */
    OS_TASK_DP_WAIT,		/* task flags */
    (u64 *)rspbootTextStart,		/* boot ucode pointer */
    0,	/* boot ucode size */
    (u64 *)gspFast3DTextStart,		/* task ucode pointer */
    SP_UCODE_SIZE,		/* task ucode size */
    (u64 *)gspFast3DDataStart,			/* task ucode data pointer */
    SP_UCODE_DATA_SIZE,		/* task ucode data size */
    sys_rcp_stack,		/* task dram stack pointer */
    SP_DRAM_STACK_SIZE8,	/* task dram stack size */
    NULL,		/* task output buffer ptr (not always used) */
    0,			/* task output buffer size ptr */
    NULL,			/* task data pointer (fill in later) */
    0,				/* task data size (fill in later) */
    gfx_ybuf,			/* task yield buffer ptr (not used here) */
    OS_YIELD_DATA_SIZE			/* task yield buffer size (not used here) */
};

/******************************************************************************
 Function: void mk3_main(short mdbug)

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: None

 Returns: None

 Description:	This is were the game starts.
******************************************************************************/
extern OSTime	gamepad_vbi_to_start_delay;
extern volatile short randadj;		// inc value for random seed, feed off of joy values

extern OSTask *vid_next_atask;		// audio task to be started on next VBI
extern OSTask *vid_atask_ready;		// audio task ready for submission
extern OSTask *vid_rsp_atask;		// audio task being processed by RSP
extern volatile short gfx_yielded;	// 1=gfx task yeild request has been sent to rsp
extern short vid_rsp_atask_submitted;	// 1=audio task has been submitted to RSP

void mk3_main(short mdbug)
{
	WORD swindex;
	WORD swpid;
	FUNC swproc_func;
	DYNAMIC *dptr;

POWERUP:
	
WARMBOOT:
	system_marker=0;

#if MK_EJBBUG
	dbug_pmax=0;
#endif

	/* Initialize Game System and Stacks Switches */
	main_init();
	
MAIN_GO:
	system_marker=SYSTEM_INIT_MARKER;
	coinflag=0;							/* not on coinpage, yet */

	if (mdbug==0)	
	{
		f_mileena=f_ermac=f_oldsz=1;
//		f_level_select=1;
		f_no_clock=1;
		f_cheat_menu=2;
		f_one_win=df_nopower=1;
		f_unlim_fatal=1;
	}	
	else
	{
		f_mileena=f_ermac=f_oldsz=1;
//		f_level_select=1;
		f_no_clock=1;
		f_cheat_menu=2;
	}
	/* create attact mode process */
	CREATE(PID_AMODE,amode);

#if BENCH
	bench_reset_all();
#endif

	/* MAIN GAME LOOP (EXEC) */
	while (TRUE)
	{
/****************************************************************************
		 START VBLANK CODE STUFF (mkdisp.asm)
 ****************************************************************************/
#if BENCH
	bench_stop(BENCHSW_CPU_IDLE);
	bench_start(BENCHSW_CPU_WORKING);
#endif					
 
		POLLING;
		
/****************************************************************************
		 START MAIN LOOP CODE STUFF (mkinit.asm)
 ****************************************************************************/
		/* unstack switch processes */
		current_proc=(PROCESS *)&active_head;
		while (swstack != swstmn)
		{
			if (free_head==NULL) break;				/* if no free processes save for next loop */

			swstack--;								/* pop stack */

			swindex=*swstack;						/* retrieve index */

			swproc_func=swtab[swindex].proc_func;	/* create process if not NULL */
			if (swproc_func != NULL && f_pause<PAUSE_OFF)
			{
				swpid=swtab[swindex].pid;
				CREATE(swpid,swproc_func);
			}
		}

		process_dispatch();
		
#ifdef MK_EJBBUG
		/* end of process links should be null or we got a problem */
		if (current_proc->plink != NULL)
			while (TRUE);
#endif /* MK_EJBBUG */

		/* do sound update, ARCADE POINT */

		/* player bar stuff */
		update_bar(&p1_bar,&p1_bar_view);				/* update player 1 strength bar */
		raise_turbo_bar(&p1_turbo,&p1_turbo_view,&p1_dont_raise);

		update_bar(&p2_bar,&p2_bar_view);				/* update player 2 strength bar */
		raise_turbo_bar(&p2_turbo,&p2_turbo_view,&p2_dont_raise);

		position_p2_bar();

		/* reseed process start */
		current_proc=(PROCESS *)&active_head;

/****************************************************************************
		 END MAIN LOOP CODE STUFF (mkinit.asm)
 ****************************************************************************/
		/* palette transfers */
 		transfer_palettes();

		/* routine to run every vblank */
		if (call_every_tick!=NULL) 
			call_every_tick();
		
		if (f_pause<PAUSE_OFF || f_pause==PAUSE_P1_INIT || f_pause==PAUSE_P2_INIT)
		{
  			/* gravity & keep in bounds */
			if (p1_obj !=NULL)
				gravity_n_bounds(p1_obj,left_edge+LEFT_PADDING,right_edge+(SCRRGT-RIGHT_PADDING));

			if (p2_obj !=NULL)
				gravity_n_bounds(p2_obj,left_edge+LEFT_PADDING,right_edge+(SCRRGT-RIGHT_PADDING));

			/* update scrolling */
			worldtlx8.pos+=scrollx8.pos;
			worldtlx7.pos+=scrollx7.pos;
			worldtlx6.pos+=scrollx6.pos;
			worldtlx5.pos+=scrollx5.pos;
			worldtlx4.pos+=scrollx4.pos;
			worldtlx3.pos+=scrollx3.pos;
			worldtlx2.pos+=scrollx2.pos;
			worldtlx1.pos+=scrollx1.pos;

			worldtlx.pos+=scrollx.pos;
			worldtly.pos+=scrolly.pos;

			/* parallax floor */
			floor_code_setup();			//-DHS- might need to mod to allow for double buffering system
		}

		/* Set Graphics List Segments */
		gSPSegment( Glp++, SYS_RSPSEG_PHYSICAL, 0 );
		gSPSegment( Glp++, SYS_RSPSEG_FBUF, OS_K0_TO_PHYSICAL(dbl_buffer_ptr->draw_ptr));
		gSPSegment( Glp++, SYS_RSPSEG_K0, SYS_MEMMAP_KERNEL );
		gSPSegment( Glp++, SYS_RSPSEG_PAL, 0 );
		
		/* Set Graphics Pipeline Defaults */
		gSPDisplayList( Glp++, osVirtualToPhysical(gutil_gfxinit) );
		
		/* Set Graphics Framebuffer */
		gDPSetColorImage(Glp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, BUFFER_WIDTH, OS_K0_TO_PHYSICAL(dbl_buffer_ptr->draw_ptr));
		
		/* setup graphics list */
		if (f_white==1) 
		{
			/* white out screen no need to draw anything except clearing screen buffer */
			gutil_clear_screen(0xffff);
		}
		else
		{
			if (f_auto_erase) 
			{
				/* clear frame buffer */
				gutil_clear_screen(irqskye);
			}
														    
			if (f_auto_erase !=9)	
			{
				/* Run through VCache List and Uncompress all data */
				vram_cache_decomp_clear();
				vcache_uncompress(); 
			
				/* transfer display lists to hardware system */
				setup_and_draw();
			}
		}
	
		/* setup RSP tasklist */
		gDPFullSync( Glp++ );
		gSPEndDisplayList( Glp++ );
		
		/* verify we haven't blown our glist area */
		if ((Glp-dbl_buffer_ptr->glist)>GLIST_LEN)			// debugging function overrun 
			printf(("GLIST OVERFLOW\n"));
		
		/* Object Sort Routine, wait until vblank (SYNC at 60 Frames) */
#if BENCH
	bench_stop(BENCHSW_CPU_WORKING);
	bench_start(BENCHSW_CPU_IDLE);
#endif					

		/* sync, to deal with code going under 60 fps, lame u64 can't keep up */
		if (irq_timer)
			irq_timer=0;
			
		while (!irq_timer)
		{
			yzsort();
		}

		while (dp_flag!=-1)		
		{
			irq_timer=0;
			while (!irq_timer)
			{
#if 1
		if ((swcurr.u.p1pad & MASK_SELECT) || (swcurr.u.p2pad & MASK_SELECT)) 
		{
			printf(("SP=%d DP=%d GFXY=%d VidRSPAtask=%x VidAtaskReady=%x\n",
					sp_flag,dp_flag,gfx_yielded,vid_rsp_atask,vid_atask_ready));

			printf(("VidNext=%x SUBMIT=%d DRAW=%d\n",
					vid_next_atask,vid_rsp_atask_submitted,draw_flag));
		}
#endif
			
				yzsort();
			}
		}
		
		/* get joy inputs */
		mk_joystick();
		
		/* setup RSP tasklist */
		vid_rsptask.t.ucode_boot_size=(int)rspbootTextEnd - (int)rspbootTextStart;	// set ucode size (waste but who cares)
		vid_rsptask.t.data_ptr=(u64*)dbl_buffer_ptr->glist;							// set start of gfx
		vid_rsptask.t.data_size=(u32)((Glp-dbl_buffer_ptr->glist)*sizeof(Gfx));		// set length of gfx commands
		
		/* Swap Dynamic Buffers */
		dptr=(dbl_buffer_ptr==&dbl_buffer[1]) ? &dbl_buffer[0]:&dbl_buffer[1];	// swap buffer
		
		/* Signal Buffer Being Rendered */
		dbl_buffer_ptr->frame_done=DBL_FRAME_DRAW;			//signal we are drawing the frame
			
		/* Swap Buffers */
		dbl_buffer_ptr=dptr;
		dbl_buffer_ptr->frame_done=DBL_FRAME_READY;			// reset finish flag
		(BYTE *)idcomp_ptr=dbl_buffer_ptr->idcmp_base;					// reset compress area
		tmem_palptr=NULL;
		Glp=dbl_buffer_ptr->glist;
					
#if BENCH
		bench_stop(BENCHSW_RSP_IDLE);
		bench_stop(BENCHSW_RDP_IDLE);
		bench_start(BENCHSW_RSP_WORKING_GFX);
		bench_start(BENCHSW_RDP_WORKING);
#endif					
		/* Start Rendering Next Frame */
		draw_flag=1;
		kickstart();
					
#if BENCH
//----------------------------------------------------------------------------------------
// print benchmarks...

		//bench_print();
#endif

	}
}

void mk_joystick(void) 
{
	JOYPAD swprev1,swprev2;
	JOYPAD sw0,swstate;

	/* translate joystick stuff in game bits */
	gamepad_work();
	map_u64_to_sony();
	randadj+=(swcurr.u.p1pad+swcurr.u.p2pad);

	/* remap input to correct values */
	if ( gstate==GS_FIGHTING || gstate==GS_ROUND_INTRO)
	{
		swcurr.u.p1pad=joy_remap(swcurr.u.p1pad,pad1_map_tbl);
		swcurr.u.p2pad=joy_remap(swcurr.u.p2pad,pad2_map_tbl);
	}
	else
	{
		swcurr.u.p1pad=joy_remap(swcurr.u.p1pad,game_map_tbl);
		swcurr.u.p2pad=joy_remap(swcurr.u.p2pad,game_map_tbl);
	}

	/* save switch values */
	swprev1.padvalue=swtemp1.padvalue;					/* retrieve last joystick (P2:P1) */
	swprev2.padvalue=swtemp2.padvalue;					/* retrieve last last joystick (P2:P1) */

	swtemp2.padvalue=swtemp1.padvalue;					/* update last last joystick */
	swtemp1.padvalue=swcurr.padvalue;						/* update last joystick */

	if ((sw0.padvalue=swcurr.padvalue ^ swprev1.padvalue)) 			/* bits that changed */
	{
		/* closed switch tests */
		if ((swstate.padvalue=sw0.padvalue & swcurr.padvalue))		/* bits that changed and just closed */
		{
		 	swstate.padvalue &= ~(swprev1.padvalue | swprev2.padvalue);   	/* only pass if last 2 stats --> open, open */
		 	stack_switch_bits(swstate.padvalue,SW_STACK_CLOSE_OFFSET);
		}

		/* open switch tests */
		swstate.padvalue = ~swcurr.padvalue & swprev1.padvalue;		/* bits that changed and just opened */
		stack_switch_bits(swstate.padvalue,SW_STACK_OPEN_OFFSET);
	}
}

extern BYTE font_dict[];
void draw_text_queue(void) 
{
	TQUE *tptr;
	
	tptr=text_queue;
	
	while (tptr!=tque_ptr)
	{
		DrawObj.dp_palptr=&pal_buffer[(findpal(WHITE_p)*(256/sizeof(u64)))];
		DrawObj.dp_imgptr=uncompress_image(tptr->t_letter->isagptr,font_dict);
		DrawObj.dp_x=tptr->t_x;
		DrawObj.dp_y=tptr->t_y;
		DrawObj.dp_w=tptr->t_letter->size.u.xpos;
		DrawObj.dp_h=tptr->t_letter->size.u.ypos;
		DrawObj.dp_scx=0x0100;
		DrawObj.dp_scy=0x0100;
		DrawObj.dp_lclip=0;
		DrawObj.dp_rclip=0;
		DrawObj.dp_flags=0;

		gutil_draw_object();			// draw object
		
		tptr++;
	}
	
	return;
}

void half_combine_mode(void) 
{
	gDPPipeSync( Glp++ );
	gDPSetCombineMode( Glp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
	gDPSetPrimColor( Glp++, 0, 0, 255, 255, 255, 96 );
	combine_mode=COMBINE_OFF;
}

void default_combine_mode(void) 
{
	gDPPipeSync( Glp++ );
	gDPSetCombineMode_default( Glp++ );
	gDPSetPrimColor_default( Glp++ );
	combine_mode=COMBINE_OFF;
	return;
}

// Take internal game display lists and output external hardware display list
void setup_and_draw(void)
{
	FUNC disp_func;
	ADDRESS *display_list;

	/* traverse internal display lists */
	if (dlists != NULL)
	{
		dlists_ptr=dlists;

		disp_world.u.ypos=worldtly.u.intpos;

		while ((display_list=(*((ADDRESS **)dlists_ptr)++)) != 0)
		{
			if ((long)display_list==-1)
			{
				disp_func=(FUNC)GET_LONG(dlists_ptr)++;			// get func to execute
				disp_func();
			}
			else
			{
				disp_world.u.xpos=*((WORD *)(GET_LONG(dlists_ptr)++));

				display_object_lists(&disp_world,(OBJECT *)display_list);
			}
		}
	}

	/* draw control panel stuff */
	if (f_doscore!=0)
		update_control_panel();

	draw_text_queue();
	
	return;
}

/******************************************************************************
 Function: void update_bar(WORD *bar,WORD *bar_view,WORD *bram,WORD type)

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: *bar - ptr to player bar real strength variable
			 *bar_view - ptr to player bar strength view variable
			 *bram = ptr to player dont raise turbo flag
			  type = 1=raise_turbo bar 0=update_bar

 Returns: None

 Description:	update player's strength bar
******************************************************************************/
void update_bar_common(WORD *bar,WORD *bar_view,WORD *bram,WORD type)
{
	if ( f_pause>=PAUSE_OFF )
		return;

	/* raise_turbo_bar */
	if (type)
	{
		if (*bram)
		{
			(*bram)--;
		}
		else
		{
			(*bar)++;
			if (*bar>FULL_TURBO)
				*bar=FULL_TURBO;
		}
	}

	/* update bar */
	if (*bar & 0x8000)	return;					/* neg means effect going on, don't touch */

	if (*bar != 0)
	{
		/* upsb1, real power > 0 */
		if (*bar_view != *bar)
		{
			/* upsb4 */
			if (*bar_view<*bar)
				(*bar_view)++;			// viewable is smaller --> add
			else (*bar_view)--;			// viewable is biggger --> sub
		}

		/* upsb3 */
		if (*bar_view<3)
			*bar_view=3;
	}
	else
	{
		/* real power = 0 */
		if (*bar_view==0)					// viewable = 0 ---> stuff
			return;

		if ((--(*bar_view))<3)				// drop bar towards 0
			*bar_view=0;					// view<3 then zero it

		return;
	}
}

/******************************************************************************
 Function: void main_init(void)

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: None

 Returns: None

 Description:	Main system initialize routine.
******************************************************************************/
void main_init(void)
{
	swstack=swstmn;						/* initialize switch stack */
	curback=0;							/* set current background to 0 */
	text_draw=0;
	master_fade=0x10000;				/* full color intensity */

	/* clear overlay stuff */
	load_bkgd=0xffff;					// set to nada loaded
	load_level=LVL_NONE;				// no data loaded at level_loadaddr
	tque_ptr=text_queue;
	spec_fx=FX_NO_LOAD;
	f_top_load=f_skel_load=0;
	
	/* init random seed */
	randomize(osGetTime(),osGetTime());

	dipinit();							/* init dipswitch settings */

	process_initialize();				/* init process list */

	object_initialize();				/* init object list */

	/* load permanent art into VRAM */
	p1_heap_char=p2_heap_char=0xffff;

	/* enable video display */
	DISPLAY_ON;

	return;
}

/******************************************************************************
 Function: void dipinit(void)

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: None

 Returns: None

 Description:	Routine to initialize system according to dip switches (SECRET CODE SETTINGS)
******************************************************************************/
void dipinit(void)
{
	f_no_blood=0;
	diff=4;
	cmos_diff=2;
	f_freeplay=0;					// no free play
	f_no_clock=0;
	f_mileena=0;
	f_ermac=0;
	f_oldsz=0;
	f_shao=0;
	f_cheat_menu=0;
	df_nopower=0;
	f_unlim_fatal=0;
	f_level_select=0;
	f_one_win=0;
	credits=GAME_CREDITS;
	f_no_sfx=0;
	f_music=2;
	f_colbox=0;

#if JAP_VERSION
	f_voice=1;			// voice effects on
#endif

	f_no_pan=0;				// pan normal (OFF)
	f_stereo=1;				// stero on
	f_no_vs=0;
	f_blast=0;

	/* configure sound driver */
	sound_driver_config();

	return;
}

/******************************************************************************
 Function: void wipeout(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description: wipes the system clear of all other processes, objects	 	*
	  		and coordinates.						 			*
	  		it returns with the display system and auto-erase on,		*
	  		color ram cleared, and the bit map wiped clean.		 	*
	  		this is nice to use when switching between stuff.		 	*
******************************************************************************/
void wipeout(void)
{
	WORD pa0;

	coinflag=on_hstd=0;

	process_kill_class(0,0x8000);			// kill all procs except coin

	object_initialize();		// reinit object lists

	pa0=tick;
	while (tick==pa0);			// wait for new vblank

	clr_scrn();
	process_sleep(1);
	clr_scrn();
	process_sleep(1);
	irqskye=0;
	DISPLAY_ON;

	return;
}

/******************************************************************************
 Function: void p[1|2]_button[0..4][_open]

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: None

 Returns: None

 Description:	Various player switch processes.  These functions are expected to
				commit suicide at the end.  They will never return from the queue
				and jump routine!!!!!
******************************************************************************/
void p1_button0_open(void)
{
	queue_and_jump(SW_HI_PUNCH,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button1_open(void)
{
	queue_and_jump(SW_LO_PUNCH,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button2_open(void)
{
	queue_and_jump(SW_BLOCK,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button3_open(void)
{
	queue_and_jump(SW_HI_KICK,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button4_open(void)
{
	queue_and_jump(SW_LO_KICK,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button5_open(void)
{
	queue_and_jump(SW_RUN,p1_boq,PLAYER1_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button0_open(void)
{
	queue_and_jump(SW_HI_PUNCH,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button1_open(void)
{
	queue_and_jump(SW_LO_PUNCH,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button2_open(void)
{
	queue_and_jump(SW_BLOCK,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button3_open(void)
{
	queue_and_jump(SW_HI_KICK,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button4_open(void)
{
	queue_and_jump(SW_LO_KICK,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p2_button5_open(void)
{
	queue_and_jump(SW_RUN,p2_boq,PLAYER2_TYPE,SW_OPEN);
	process_suicide();
}

void p1_button0(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_HI_PUNCH,p1_bcq);
	queue_and_jump(SW_HI_PUNCH,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_button1(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LO_PUNCH,p1_bcq);

	queue_and_jump(SW_LO_PUNCH,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_button2(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_BLOCK,p1_bcq);

	queue_and_jump(SW_BLOCK,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_button3(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_HI_KICK,p1_bcq);

	queue_and_jump(SW_HI_KICK,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_button4(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LO_KICK,p1_bcq);

	queue_and_jump(SW_LO_KICK,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_button5(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_RUN,p1_bcq);

	queue_and_jump(SW_RUN,p1_bcq,PLAYER1_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button0(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_HI_PUNCH,p2_bcq);

	queue_and_jump(SW_HI_PUNCH,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button1(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LO_PUNCH,p2_bcq);

	queue_and_jump(SW_LO_PUNCH,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button2(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_BLOCK,p2_bcq);

	queue_and_jump(SW_BLOCK,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button3(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_HI_KICK,p2_bcq);

	queue_and_jump(SW_HI_KICK,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button4(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LO_KICK,p2_bcq);

	queue_and_jump(SW_LO_KICK,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p2_button5(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_RUN,p2_bcq);

	queue_and_jump(SW_RUN,p2_bcq,PLAYER2_TYPE,SW_CLOSE);
	process_suicide();
}

void p1_start_button(void)
{
	start_entry(&p1_state,0);
}

void p1_joy_up(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_UP,p1_jcq);

	queue_and_jump(SW_UP,p1_jcq,PLAYER1_TYPE,SW_CLOSE);
}

void p1_joy_right(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_RIGHT,p1_jcq);

	queue_and_jump(SW_RIGHT,p1_jcq,PLAYER1_TYPE,SW_CLOSE);
}

void p1_joy_down(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_DOWN,p1_jcq);

	queue_and_jump(SW_DOWN,p1_jcq,PLAYER1_TYPE,SW_CLOSE);
}

void p1_joy_left(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LEFT,p1_jcq);

	queue_and_jump(SW_LEFT,p1_jcq,PLAYER1_TYPE,SW_CLOSE);
}

void p2_start_button(void)
{
	start_entry(&p2_state,1);
}

void p2_joy_up(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_UP,p2_jcq);

	queue_and_jump(SW_UP,p2_jcq,PLAYER2_TYPE,SW_CLOSE);
}

void p2_joy_right(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_RIGHT,p2_jcq);

	queue_and_jump(SW_RIGHT,p2_jcq,PLAYER2_TYPE,SW_CLOSE);
}

void p2_joy_down(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_DOWN,p2_jcq);

	queue_and_jump(SW_DOWN,p2_jcq,PLAYER2_TYPE,SW_CLOSE);
}

void p2_joy_left(void)
{
	if (gstate==GS_AMODE)
		home_code_que(SW_LEFT,p2_jcq);

	queue_and_jump(SW_LEFT,p2_jcq,PLAYER2_TYPE,SW_CLOSE);
}

void p1_start_open(void)
{
	if (f_pause==PAUSE_P1_THAW)
		f_pause=0;

	process_suicide();
}

void p2_start_open(void)
{
	if (f_pause==PAUSE_P2_THAW)
		f_pause=0;

	process_suicide();
}

void p_grid(void)
{
	process_suicide();
#if DEBUG_GRID
	f_gridon^=1;
#else
	f_gridon=0;
#endif
	process_suicide();
}

void p_profile(void)
{
	process_suicide();
}

void p_colbox(void)
{
	//p2_bar=0;
	//process_suicide();

#if SCREEN_SHOTS
	while (!((swcurr.u.p1pad & P1_BUTTON_MASK) || (swcurr.u.p2pad & P2_BUTTON_MASK)))
		POLLING;

	process_suicide();
#endif

#if 0
#if COLLISION_BOX
	kilobj2(OID_CBOX,0xffff);
	f_colbox^=1;
#else
	f_colbox=0;
#endif
#endif
	process_suicide();
}

WORD *last_switch_ram[]=
{
	l_hp,c_hp,			// 0
	l_lp,c_lp,	   		// 1
	l_block,c_block,	// 2
	l_hk,c_hk,			// 3
	l_lk,c_lk,			// 4
	l_run,c_run,		// 5
	l_up,c_up,			// 6
	l_down,c_down,		// 7
	l_left,c_left,		// 8
	l_right,c_right 	// 9
};

/******************************************************************************
 Function: queue_and_jump

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: WORD swoffset - switch offset (0-8) (a0)
			 LONG *b_queue - array button queue to queue switch offset (a1)
			 WORD poffset - player offset (0-1) (a2)
			 WORD swtype - open/close (0/1) (a3)

 Returns: process will terminate in suicide

 Description:	0)	determine if player active, if not process commits suicide
 				1)	queues up a switch equate
				2)	loads up a player's info into process ram
				3)	compute jump of switch address and jump
				4)	if returns then commit suicide
******************************************************************************/
void queue_and_jump(WORD swoffset,LONG *b_queue,WORD poffset,WORD swtype)
{
	PROCESS *ptemp;
	WORD *pbutton;
	JUMPTBL *sw_ptr;

	/* check if player active otherwise ignore input */
	if (poffset==PLAYER1_TYPE)
		pdie2(p1_state,0,swtype,swoffset);
	else pdie2(p2_state,1,swtype,swoffset);

	switch_queue(swoffset,b_queue);			/* queue switch */

	/* load info based on player type */
	ptemp=current_proc;
	ptemp->a0=(ADDRESS)swoffset;
	ptemp->a2=(ADDRESS)poffset;

	if (poffset==PLAYER1_TYPE)
	{
		if (p2_obj==NULL)				// rev1.2
			process_suicide();
			
		ptemp->pdata.p_otherguy=p2_obj;

		ptemp->pdata.p_otherproc=p2_proc;

		(ADDRESS)ptemp->pdata.p_store4=(ADDRESS)p1_proc;

		ptemp->pdata.p_joyport=p1_proc->pdata.p_joyport;

		ptemp->pa8=p1_obj;
	}
	else
	{
		if (p1_obj==NULL)				// rev1.2
			process_suicide();
			
		ptemp->pdata.p_otherguy=p1_obj;

		ptemp->pdata.p_otherproc=p1_proc;

		(ADDRESS)ptemp->pdata.p_store4=p2_proc;

		ptemp->pdata.p_joyport=p2_proc->pdata.p_joyport;

		ptemp->pa8=p2_obj;
	}

	if (swtype==SW_CLOSE)
	{
		/* button table jump?? */
		if (poffset==PLAYER1_TYPE)
		{
			pbutton=p1_button;
			ptemp=p1_proc;
		}
		else
		{
			pbutton=p2_button;
			ptemp=p2_proc;
		}

		if ((*(pbutton+swoffset)) != JI_JOY_IGNORE)
		{
			ptemp->joyindex=*(pbutton+swoffset);				// set joystick routine index var
			fastxfer(ptemp,joy_proc);								// transfer player to start of joystick routine
		}

		/* update "time since last" ram */
		if (poffset==PLAYER1_TYPE)
		{
			/* player 1 update */
			pbutton=*(last_switch_ram+swoffset*2);		// last ram
			*pbutton=tick;

			pbutton=*(last_switch_ram+swoffset*2+1);	// combo ram
			*pbutton=tick;

		}
		else
		{
			/* player 2 update */
			pbutton=(*(last_switch_ram+swoffset*2))+1;		// last ram
			*pbutton=tick;

			pbutton=(*(last_switch_ram+swoffset*2+1))+1;	// combo ram
			*pbutton=tick;
		}
	}

	/* qaj6 */
	if (!f_no_special_moves)
	{
		if (swtype==SW_CLOSE)
			sw_ptr=*(switch_close_jumps+swoffset);
		else sw_ptr=*(switch_open_jumps+swoffset);

		if (*(sw_ptr+(current_proc->pa8)->ochar) != NULL)
			(*(sw_ptr+(current_proc->pa8)->ochar))();		// address to jump to
	}

	process_suicide();						/* kill self if every gets back to this point */
}

/******************************************************************************
 Function: switch_queue(WORD swoffset,LONG *bqueue)

 By: David Schwartz

 Date: Aug 8, 1994

 Parameters: WORD swoffset - switch offset (0-8)
			 LONG b_queue - array button queue to queue switch offset

 Returns: NONE

 Description:	adds a switch entry to the current queue
******************************************************************************/
void switch_queue(WORD swoffset,LONG *b_queue)
{
	LONG	index;

	index=b_queue[0];								/* next entry */
	b_queue[index++]=(LONG)((swoffset<<16)|tick);	/* stuff info, [switch,time] */

	if (index>=SQS+1) index=1;						/* update index, if end set to start */
	b_queue[0]=index;

	return;
}

/******************************************************************************
 Function: void shadow_p1p2(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	display shadows for player 1 and player 2
******************************************************************************/
void shadow_p1p2(void)
{
	if (f_shadows==1)							// shadows allowed?
	{
		/* setup pipeline for translucency */
		gDPPipeSync( Glp++ );
		gDPSetCombineMode( Glp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
		gDPSetPrimColor( Glp++, 0, 0, 0, 0, 0, 164 );
	
		shadow_code(p1_obj,p1_shadadj);

		shadow_code(p2_obj,p2_shadadj);
		
		/* restore default pipeline state */
		gDPPipeSync( Glp++ );
		gDPSetCombineMode_default( Glp++ );
		gDPSetPrimColor_default( Glp++ );
		combine_mode=COMBINE_OFF;
	}
}

/******************************************************************************
 Function: void pdie2(WORD pb0,WORD pb1,WORD pa3)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pb0 - pstate
			 pb1 - PLAYER1 =0 PLAYER2=1
			 pa3 - switch open/close (0/1) (a3)

 Returns: None

 Description:	routine to die if the player who hit the button is not in game
******************************************************************************/
void pdie2(WORD pb0,WORD pb1,WORD pa3,WORD swoffset)
{
	WORD *pbutton;

	if (gstate==GS_UNLOCK_HID)
		goto VS_SCREEN_BUTTON;

	if (pb0!=PS_ACTIVE)
		process_suicide();

	if (gstate==GS_VS)
	{
VS_SCREEN_BUTTON:

		if (pa3!=0)
		{
			pbutton=(pb1==PLAYER1_TYPE) ? *(last_switch_ram+swoffset*2):(*(last_switch_ram+swoffset*2))+1;	// "last ram to update "
			*pbutton=1;
		}

		process_suicide();
	}
	else
	{
		if (gstate!=GS_FIGHTING)
			process_suicide();
	}

	return;
}
