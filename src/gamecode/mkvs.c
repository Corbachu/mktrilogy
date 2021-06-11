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
#include "mkinit.h"
#include "mkmain.h"
#include "mksound.h"
#include "mkvs.h"
#include "mkladder.h"
#include "mkfade.h"
#include "mkdma.h"
#include "wessapi.h"
#include "vcache.h"

extern void *vs_module[];
extern void *a_mklight[];
extern void *a_vs_s[];
extern void *a_vs_v[];
extern void *symbol_table[];
extern void *BURNV1[];
extern void *BURNS1[];
extern void *BATTLE0[];
extern void *BATTLE[];
extern void *MKLIGHT1[];
extern void *BOX2[];
extern void *I_DRAGON[];
extern OIMGTBL *battle_digits[];

/******************************************************************************
 Function: void vs_or_ladder(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	The cool vs screen
******************************************************************************/
void vs_or_ladder(void)
{

	if (gstate!=GS_AMODE)
	{
#if MK_EJBBUG
		if (df_fastrun!=0)
			return;
#endif

		if (count_active_players()==1)
		{
			mk_ladder();
			return;
		}
		SET_GAME_STATE(GS_VS);
	}

	/* vs3 */

	/* loopit, not_highest_battle */
	murder_myoinit();
	irqskye=0;

	/* load background data */
	load_bkgd=BKGD_VS_MOD;
	init_background_module(vs_module);
	multi_plane();
	dlists=dlists_bogus;

	/* load character 1 and character 2 data */
	loadoverlay(SYS_VSPLAY_OVL);


	DISPLAY_OFF;
	nosounds();
	
	CREATE(PID_FX,mk_bat_signal);
	CREATE(PID_FX,mk_bat_signal_f);
	CREATE(PID_FX,mk_battle);
	CREATE(PID_FX,mk_vs);
//	CREATE(PID_FX,mk_names);
	CREATE(PID_COMB,combination_proc);

	process_sleep(1);

	fadein_jsrp(0);
	slide_in_huge_players();

	tsound(0xb0); 
	
	process_sleep(0xd0);

	dallprc(PID_COMB);				// stop combinations proc

	/* arcade display flow */
	process_sleep(4);
	murder_myoinit_score();
	clr_scrn();
	process_sleep(0x08);

	/* vs_exit */
	return;
}

/******************************************************************************
 Function: void mk_vs(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	Vs burn fx stuff
******************************************************************************/
extern BYTE vs_dict[];
void mk_vs(void)
{
	OBJECT *obj;

	gso_dmawnz_ns(obj,(ADDRESS)BURNV1,vs_dict,0,0);
	set_xy_coordinates(obj,SCX(0xab),SCY(0x50)+4);
	alloc_cache(BURNV1,0,obj);
	insert_object(obj,&objlst);
	current_proc->pa9=a_vs_v;
	framew(2);

	gso_dmawnz_ns(obj,(ADDRESS)BURNS1,vs_dict,0,0);
	set_xy_coordinates(obj,SCX(0xd3),SCY(0x50)+4);
	alloc_cache(BURNS1,0,obj);
	insert_object(obj,&objlst);
	current_proc->pa9=a_vs_s;
	framew(2);

	process_suicide();
}

/******************************************************************************
 Function: void mk_battle(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	Vs Battle fx stuff
******************************************************************************/
void mk_battle(void)
{
	OBJECT *obj;
	WORD b0,b1,b2;

	gso_dmawnz_ns(obj,(ADDRESS)BATTLE,vs_dict,0,0);
	obj->oypos.u.intpos=10+4;
	center_obj_x(obj);
	alloc_cache(BATTLE,0,obj);
	insert_object(obj,&objlst);							// text battle

	current_proc->a0=(battle_num<1000)? battle_num:999;

	/* mkbat3 */
	b0=current_proc->a0/100;			// b0 = 100s
	current_proc->a0%=100;
	b1=current_proc->a0/10;				// b1 = 10s
	b2=current_proc->a0%10;				// b2 = 1s

	/* 3 digits */
	if (b0!=0)
	{
		do_mk_number(b0);
		(OBJECT *)current_proc->a10=current_proc->pa8;

		do_mk_number(b1);
		(OBJECT *)current_proc->pa9=current_proc->pa8;

		do_mk_number(b2);

		b0=(current_proc->pa8)->osize.u.xpos;
		b1=((OBJECT *)current_proc->pa9)->osize.u.xpos;
		b2=((OBJECT *)current_proc->a10)->osize.u.xpos;

		current_proc->a3=SCRRGT/2-((b0+b1+b2)>>1);

		((OBJECT *)current_proc->a10)->oxpos.u.intpos=(short)(current_proc->a3);
		current_proc->a3+=b2;
		((OBJECT *)current_proc->pa9)->oxpos.u.intpos=(short)(current_proc->a3);
		current_proc->a3+=b1;
		(current_proc->pa8)->oxpos.u.intpos=(short)(current_proc->a3);
	}
	else
	{
		/* 2 digits */
		if (b1!=0)
		{
			do_mk_number(b1);
			(OBJECT *)current_proc->pa9=current_proc->pa8;

			do_mk_number(b2);

			b0=(current_proc->pa8)->osize.u.xpos;
			b1=((OBJECT *)current_proc->pa9)->osize.u.xpos;

			current_proc->a3=SCRRGT/2-((b0+b1)>>1);

			((OBJECT *)current_proc->pa9)->oxpos.u.intpos=(short)(current_proc->a3);
			current_proc->a3+=b1;
			(current_proc->pa8)->oxpos.u.intpos=(short)(current_proc->a3);
		}
		else
		{
			/* 1 digit */
			do_mk_number(b2);

			b0=(current_proc->pa8)->osize.u.xpos;
			current_proc->a3=SCRRGT/2-((b0)>>1);
			(current_proc->pa8)->oxpos.u.intpos=(short)(current_proc->a3);
		}
	}

	process_suicide();
}

void do_mk_number(WORD pa0)
{
	OBJECT *obj;

	gso_dmawnz_ns(obj,(ADDRESS)BATTLE0,vs_dict,0,0);
	set_xy_coordinates(obj,SCX(0xc8),SCY(0x20)+4+3);
	alloc_cache(BATTLE0,0,obj);
	insert_object(obj,&objlst);

	animate(SINGLE_ANI,battle_digits[pa0],obj->oflags);
}

/******************************************************************************
 Function: void mk_bat_signal_f(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	Bat singnal flip
******************************************************************************/
void mk_bat_signal_f(void)
{
	OBJECT *obj;

	obj=make_a_mk_light(SCX(0x13d),4);
	flip_single(obj);

	/* signal4 */
	current_proc->pa9=a_mklight;
	framew(6);

	process_suicide();
}

/******************************************************************************
 Function: void mk_bat_signal(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	Bat singnal flip
******************************************************************************/
void mk_bat_signal(void)
{
	make_a_mk_light(0xfffe,4);

	/* signal4 */
	current_proc->pa9=a_mklight;
	framew(6);

	process_suicide();
}

/******************************************************************************
 Function: OBJECT *make_a_mk_light(short pa9x,short pa9y)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa9x - x coord of light
			 pa9y - y coord of light

 Returns: None

 Description:	Bat singnal flip
******************************************************************************/
OBJECT *make_a_mk_light(short pa9x,short pa9y)
{
	OBJECT *obj;

	gso_dmawnz_ns(obj,(ADDRESS)MKLIGHT1,vs_dict,0,0);
	set_xy_coordinates(obj,pa9x,pa9y);
	alloc_cache(BATTLE0,0,obj);
	insert_object(obj,&objlst);

	return(obj);
}

/******************************************************************************
 Function: void slide_in_huge_players(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	show the cool players coming together to fight
******************************************************************************/
extern VPIECE kano_pieces;
extern VPIECE sonya_pieces;
extern VPIECE jax_pieces;	
extern VPIECE ind_pieces;	
extern VPIECE sz_pieces;	
extern VPIECE jc_pieces;	
extern VPIECE swat_pieces;	
extern VPIECE lia_pieces;	
extern VPIECE robo1_pieces;
extern VPIECE robo2_pieces;
extern VPIECE lao_pieces;	
extern VPIECE tusk_pieces;	
extern VPIECE sg_pieces;	
extern VPIECE shang_pieces;	
extern VPIECE lk_pieces;	
extern VPIECE smoke_pieces;
extern VPIECE kitana_pieces;
extern VPIECE jade_pieces;	
extern VPIECE mileena_pieces; 
extern VPIECE kamel_pieces; 
extern VPIECE scorpion_pieces;
extern VPIECE reptile_pieces; 
extern VPIECE ermac_pieces;   
extern VPIECE oldsz_pieces;   
extern VPIECE oldsmoke_pieces;
extern VPIECE noob_pieces;	
extern VPIECE rain_pieces;	
extern VPIECE rayden_pieces;	
extern VPIECE baraka_pieces;	

extern BYTE kano_dict[];
extern BYTE sonya_dict[];
extern BYTE jax_dict[];	
extern BYTE ind_dict[];	
extern BYTE sz_dict[];	
extern BYTE jc_dict[];	
extern BYTE swat_dict[];	
extern BYTE lia_dict[];	
extern BYTE robo_dict[];
extern BYTE lao_dict[];	
extern BYTE tusk_dict[];	
extern BYTE sg_dict[];	
extern BYTE shang_dict[];	
extern BYTE lk_dict[];	
extern BYTE fninja_dict[];
extern BYTE mninja_dict[];
extern BYTE nuguys_dict[];

VPIECE *ochar_pieces[]=
{
	&kano_pieces,	// 0
	&sonya_pieces,	// 1
	&jax_pieces,		// 2
	&ind_pieces,		// 3
	&jc_pieces,		// 4
//	&ind_pieces,		// 3

	&swat_pieces,	// 5
	&lia_pieces,		// 6
	&robo1_pieces,	// 7
	&robo2_pieces,	// 8
	&lao_pieces,		// 9

	&tusk_pieces,	// 10
	&sg_pieces,		// 11
	&shang_pieces,		// 12
	&lk_pieces,		// 13
	&smoke_pieces,	// 14

	&kitana_pieces,	// 15
	&jade_pieces,	// 16
	&mileena_pieces,	// 17
	&scorpion_pieces,	// 18
	&reptile_pieces,	// 19
	&ermac_pieces,	// 20
	&oldsz_pieces,	// 21
	&oldsmoke_pieces,	// 22
	&noob_pieces,	// 23
	&rayden_pieces,	// 24
	&baraka_pieces,	// 25
	&rain_pieces,	// 26
	&kamel_pieces,	// 15
	
	&rain_pieces,	// 28
	&rain_pieces,	// 29
};

BYTE *ochar_pieces_dict[]=
{
	kano_dict,	// 0
	sonya_dict,	// 1
	jax_dict,		// 2
	ind_dict,		// 3
	jc_dict,		// 4
//	ind_dict,		// 3

	swat_dict,	// 5
	lia_dict,		// 6
	robo_dict,	// 7
	robo_dict,	// 8
	lao_dict,		// 9

	tusk_dict,	// 10
	sg_dict,		// 11
	shang_dict,		// 12
	lk_dict,		// 13
	robo_dict,	// 14

	fninja_dict,	// 15
	fninja_dict,	// 16
	fninja_dict,	// 17
	mninja_dict,	// 18
	mninja_dict,	// 19
	mninja_dict,	// 20
	mninja_dict,	// 21
	mninja_dict,	// 22
	mninja_dict,	// 23
	nuguys_dict,	// 24
	nuguys_dict,	// 25
	mninja_dict,	// 26
	fninja_dict,	// 16
	
	mninja_dict,	// 28
	mninja_dict,	// 29
};

BYTE vs_index[]=
{
	0,		// kano
	1,		// sonya
	2,		// jax
	3,		// indian
//	3,		// jcage
	4,		// jcage
	5,		// swat
	6,		// lia
	7,		// robots
	7,		// robots
	8,		// lao
	9,		// tusk
	10,		// sheeva
	11,		// shang
	12,		// liu kang
	07,		// robots
	13,		// kitana
	13,		// jade
	13,		// mileena
	14,		// scorpion
	14,		// reptile
	14,		// ermac
	14,		// oldsz
	14,		// oldsmoke
	14,		// noob
	15,		// rayden
	15,		// baraka
	14,		// rain
	13,		// kamel
};

void slide_in_huge_players(void)
{
	VPIECE *vtbl;
	void *iptr;
	BYTE *storage;

	send_code_a3(TS_MAP_ZOOM);	// send_code_a3(0x451) Mortal Sans Pre-whoosh buildup

	f_novel=1;

	/* player 1 */
	build_huge_left(p1_char);

	/* player 2 */
	if (vs_index[p1_char]!=vs_index[p2_char])
	{
		storage=(BYTE *)p2_heap;
		storage+=1024*100;
		character_ziptexture_load(vs_index[p2_char],storage); 		// load data
	}
	else
	{
		storage=(BYTE *)p2_heap;
	}

	vtbl=ochar_pieces[p2_char];
	(VPIECE *)iptr=vtbl+1;			// get to piece info
	while (GET_LONG(iptr)!=0)
	{
		/* slide5 */
		create_1_piece(ochar_pieces_dict[p2_char],storage,iptr,vtbl->v_p2x,vtbl->v_p2y,1);
		((ADDRESS *)iptr)+=2;
	}

	/* slide6 */
	f_novel=0;

	process_sleep((SDIST/(SSPEED/0x10000))-8);
	  
	f_novel=1;

	return;
}

void build_huge_left(WORD pa0) 
{
	VPIECE *vtbl;
	void *iptr;
	
	/* load texture data for player */
	character_ziptexture_load(vs_index[pa0],(BYTE *)p2_heap); 		// load data
	
	/* build image */
	vtbl=(VPIECE *)ochar_pieces[pa0];
	(VPIECE *)iptr=vtbl+1;			// get to piece info
	while (GET_LONG(iptr)!=0)
	{
		/* slide3 */
		create_1_piece(ochar_pieces_dict[pa0],p2_heap,iptr,vtbl->v_p1x,vtbl->v_p1y,0);
		((ADDRESS *)iptr)+=2;
	}

	return;
}

/******************************************************************************
 Function: void create_1_piece(BYTE *dict,void *fixupptr,void *pa7,short pa0,short pa1,short pa2)

 By: David Schwartz

 Date: Feb 1995

 Parameters: dict - dictionary for pieces
 			 fixupptr - start of texture data
 			 pa7 - ptr to piece data
			 pa0 - x offset
			 pa1 - y offset
			 pa2 - flip flag (0=no(player1) 1=yes(player2))

 Returns: None

 Description:	create object for piece to display
******************************************************************************/
void create_1_piece(BYTE *dict,void *fixupptr,void *pa7,short pa0,short pa1,short pa2)
{
	OBJECT *obj;
	void *pal;
	LONG *animframe;
	LONG fixup;
	
	current_proc->pa9=pa7;
	
	/* fixup texture data */
	animframe=(LONG *)GET_LONG(current_proc->pa9);		// pt to multi part object
	animframe=(LONG *)GET_LONG(animframe);				// pt to frame info
	fixup=GET_LONG(animframe);							// get texture offset
	if ((fixup & 0x80000000)==0)
		fixup+=(LONG)fixupptr;								// convert offset into abs address
		
	*animframe=fixup;									// update memory with correct value
	
	/* build piece */
	gmo_proc(dict,0);
	obj=current_proc->pa8;

	/* alt pal check */
	if (pa2==1 && p1_char==p2_char)
	{
		pal=(void *)(GET_LONG(pa7+1));			// get palette ptr
		if (pal!=NULL)
			swpal(pal,obj);
	}

	/* cone3 */
	if (pa2)
	{
		flip_multi(obj);
		obj->oxvel.pos=-SSPEED;
		obj->oxpos.u.intpos=(pa0*SCF_X/100)-(-SDIST);
		obj->oypos.u.intpos=pa1*SCF_Y/100;
	}
	else
	{
		obj->oxvel.pos=SSPEED;
		obj->oxpos.u.intpos=(pa0*SCF_X/100)-(SDIST);
		obj->oypos.u.intpos=pa1*SCF_Y/100;
	}

	set_noscroll(obj);

	obj->ozval=0;
	obj->oid=0;

	insert_object(obj,&objlst);

	return;
}

/******************************************************************************
 Function: void combination_proc(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	secret combo process
******************************************************************************/
extern BYTE symbol_dict[];
void combination_proc(void)
{
	ADDRESS *ta3;
	OBJECT *obj;

	gso_dmawnz_ns(obj,(ADDRESS)BOX2,vs_dict,0,0);
	alloc_cache(BOX2,0,obj);

	obj->ozval=1;

	obj->oypos.u.intpos=SCY(0xe9)+0x10-4;
	center_obj_x(obj);
	start_off_screen(obj);
	current_proc->pa9=(OBJECT *)current_proc->pa8;

	/* symbols */
	ta3=&(current_proc->pdata.p_store1);
	current_proc->a7=6;
	current_proc->a6=SCX(2)+2;

	/* cproc5 */
	do
	{
		gso_dmawnz_ns(obj,(ADDRESS)I_DRAGON,symbol_dict,0,0);
		alloc_cache(I_DRAGON,0,obj);
		obj->oxpos.u.intpos=((OBJECT *)current_proc->pa9)->oxpos.u.intpos+current_proc->a6;
		obj->oypos.u.intpos=((OBJECT *)current_proc->pa9)->oypos.u.intpos+2;

		*ta3=(ADDRESS)current_proc->pa8;			// save object here
		ta3++;

		current_proc->a6+=19;				// next symbol to the right

		(LONG)obj->oslink=0;

		/* soff3 */
		insert_object(obj,&objlst);

		obj->ozval=2;
	}
	while(--current_proc->a7>0);

	if (gstate==GS_AMODE)
		process_suicide();

	f_novel=0;
	c_hp[0]=c_hp[1]=0;
	c_lp[0]=c_lp[1]=0;
	c_block[0]=c_block[1]=0;
	c_lk[0]=c_lk[1]=0;
	c_hk[0]=c_hk[1]=0;

	process_sleep(2);

	/* cproc 7 */
	while (1)
	{
		l_hp[0]=l_hp[1]=0;
		l_lp[0]=l_lp[1]=0;
		l_block[0]=l_block[1]=0;
		l_lk[0]=l_lk[1]=0;
		l_hk[0]=l_hk[1]=0;

		process_sleep(1);

		setup_direction(MASK_JUP<<0);			// p1 up
		current_proc->a0=0;
		check_button((OBJECT *)current_proc->pdata.p_store1);
		check_button((OBJECT *)current_proc->pdata.p_store2);
		check_button((OBJECT *)current_proc->pdata.p_store3);

		setup_direction(MASK_JUP<<16);			// p2 up
		check_button((OBJECT *)current_proc->pdata.p_store4);
		check_button((OBJECT *)current_proc->pdata.p_store5);
		check_button((OBJECT *)current_proc->pdata.p_store6);
	}
}


WORD *button_ram_spots[]=
{
	l_hp,		// symbol #1
	l_hk,	//l_block,		// symbol #2
	l_lk,	//l_lk,		// symbol #3
	l_hp+1,		// symbol #4
	l_hk+1,		//l_block+1,   	// symbol #5
	l_lk+1	//l_lk+1		// symbol #6
};

/******************************************************************************
 Function: setup_direction(LONG pa4)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	setup direction
******************************************************************************/
void setup_direction(LONG pa4)
{
	(long)current_proc->a3=(swcurr.padvalue & pa4) ? -1:1;

	return;
}

/******************************************************************************
 Function: void start_off_screen(OBJECT *obj)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	start offscreen
******************************************************************************/
void start_off_screen(OBJECT *obj)
{
	insert_object(obj,&objlst);

	return;
}

/******************************************************************************
 Function: void check_button(OBJECT *obj)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	start offscreen
******************************************************************************/
void check_button(OBJECT *obj)
{
	WORD *ta0,*ta2;
	long offset;

	current_proc->pa8=obj;

	ta0=button_ram_spots[current_proc->a0];

	if (*ta0 != 0 )
	{
		ta2=&combo_1+current_proc->a0;		// a2 ---> combo ram to change

		offset=(long)obj->oslink+(long)current_proc->a3;
		if (offset<0)
			offset=9;
		if (offset>9)
			offset=0;

		(long)obj->oslink=offset;
		*ta2=offset;					// stuff intro combo ram as well

		switch (offset)		// stuff new offset into ram
		{
			case 0:
				c_hp[0]=offset;
				break;
			case 1:
				c_hp[1]=offset;
				break;
			case 2:
				c_lp[0]=offset;
				break;
			case 3:
				c_lp[1]=offset;
				break;
			case 4:
				c_block[0]=offset;
				break;
			case 5:
				c_block[1]=offset;
				break;
			case 6:
				c_hk[0]=offset;
				break;
			case 7:
				c_hk[1]=offset;
				break;
			case 8:
				c_lk[0]=offset;
				break;
			case 9:
				c_lk[1]=offset;
				break;
		}

		current_proc->a1=(ADDRESS)COMPUTE_ADDR(0,symbol_table[offset]);
		swpal((void *)GET_LONG((((OIMGTBL *)current_proc->a1)+1)) ,obj);
		animate(SINGLE_ANI,(OIMGTBL*)current_proc->a1,obj->oflags);
	}
	current_proc->a0++;
	return;
}
#if 0
void mk_names(void) 
{
	WORD seq;

	if (mode_of_play==0)
		process_suicide();
		
	process_sleep(20);
		
	/* say player 1 name */
	seq=tsound2(p1_char);
	process_sleep(8);
	
	/* wait until done */
	while (wess_seq_status(seq)==SEQUENCE_PLAYING)
		process_sleep(1);
		
	process_sleep(0x8);	
	
	/* say player 2 name */
	seq=tsound2(p2_char);
	
	process_suicide();
}
#endif

