/******************************************************************************
 File: mkguys.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Fighter Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mktext.h"
#include "mkos.h"
#include "mkdma.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkgame.h"
#include "mkinit.h"
#include "mkcanned.h"
#include "mkpal.h"
#include "mkmain.h"
#include "mkjoy.h"
#include "mkdrone.h"
#include "mkguys.h"


short shadow_adjustments[] =
{
	0xfff6,				// 0 - kano
	-9,					// 1 - sonya
	0xfff7,				// 2 - jax
	0xfff9,	 			// 3 - indian
	0xfff6,				// 4 - turk (subzero)
	-9,					// 5 - swat dude
	0xfff9,				// 6 - lia
	0xfff8,				// 7 - robot ninja
	0xfff8,				// 8 - robot ninja
	0xfff9,				// 9 - kung lao
	0xfffa,					// 10 - tusk
	0xfff6,					// 11 - she goro
	0xfff9,					// 12 - shang tsung
	0xfff9,				// 13 - liu kang
	0xfff8,					// 14 - smoke
	-10,				// 15 kitana
	-10,				// 16 jade
	-10,				// 17 mileena
	-8,				// 18 scorpion
	-8,				// 19 reptile
	-8,				// 20
	-8,				// 21
	-8,				// 22
	-8,				// 23
	-8,				// 24 rayden		-u64-
	-14,				// 25 baraka
	-12,				// 26 rain
	-10,				// 27 kamel
	0,				// 28
	0,				// 29
	-6,					// 24 - motaro
	-6					// 25 - shao kahn
};

short ochar_ground_offsets[] = {
	SCY(0x90)-2,			// kano
	SCY(0x8f),				// sonya
	SCY(0x9e)-2,			// jax
	SCY(0x90)-3,			// indian
	SCY(0x8e)+3,			// turk (subzero)
	SCY(0x93)-2,			// swat
	SCY(0x90)-3,			// lia
	SCY(0x93),				// robo
	SCY(0x93),				// robo
	SCY(0x8c)-4,			// kung lao
 	SCY(0x94)-1,			// tusk
	SCY(0x9e)-2,			// she goro
	SCY(0x88)-3,			// shang tsung
	SCY(0x8b)-2,			// kang
	SCY(0x93),				// smoke
	SCY(0x8b),	// 15 - kitana
	SCY(0x8b),	// 16 - jade
	SCY(0x8b),	// 17 - mileena
	SCY(0x8b)-2,	// 18 - scorpion
	SCY(0x8b)-2,	// 19 - reptile
	SCY(0x8b)-2,	// 20 - ermac
	SCY(0x8b)-2,	// 21 - old sz
	SCY(0x8b)-2,	// 22 - old smoke
	SCY(0x8b)-2,	// nobb
	SCY(0x8b)+4,	// rayden			//-u64-
	SCY(0x8b)+4,	// baraka
	SCY(0x8b)-2,	// rain
	SCY(0x8b),	// kamel
	0,
	0,
	SCY(0xaa),				// motaro
	SCY(0xad),				// kahn
};

extern WORD RAIN1_P[];
extern WORD INBLU_P_64[];
extern WORD INYEL_P_64[];
extern WORD REP1_P_64[];
extern WORD SCORP1_P_64[];
extern WORD KAMEL1_P[];
extern WORD noob2_p[];
extern WORD JCBLU_P[];
extern WORD KAM2_P[];

void *character_palettes_1[] = {
	KANORED_P,    	// 0 - kano
	SBGREEN_P,    	// 1 - sonya
	JAXPRP_P,     	// 2 - jax
	INBLU_P,     	// 3 - indian
	JCBLU_P,	     	// 4 - turk (subzero)
	OLTBLU_P,	     	// 5 - swat
	LPRP_P,	     	// 6 - lia
	R1PAL1_P,	    	// 7 - robo1
	R2PAL1_P,		// 8 - robo2
	KUNG_P,			// 9 - kung lao
	TSKTAN_P,		//10 - tusk
	FGRED_P,			//11 - she goro
	TSYEL_P,			//12 - shang tsun
	LKRED_P,			//13 - kang
	SMOKE1_P,			//14 - smoke
	KIT1_P,			// 15 - kitana
	JADE1_P,		// 16 - jade
	MIL1_P,			// 17 - mileena
	SCORP1_P,		// 18 - scorpion
	REP1_P,			// 19 - reptile
	ERMAC1_P,		// 21 - ermac
	SUBZ1_P,		// 20 - classic subzero
	NJSMOKE_P,		// 21 - ninja smoke
	noob_p,			// Noob Saibot

	RADBLUE_P,			// rayden			//-u64-
	UGRED_P,			// baraka
	RAIN1_P,			// rain
	KAMEL1_P,			// 15 - kitana

	noob_p,			//
	noob_p,			//

	MOTARO_P,			//15 - motaro
	BGPAL1_P,			// 16 - shao kahn
};

extern WORD NJSMOKE2_P[];
extern WORD JCARED_P[];
void *character_palettes_2[] = {
	KANOBLU_P,		// 0 - kano
	SBLTBLU_P,		// 1 - sonya
	JZXGRN_P,		// 2 - jax
	INYEL_P,		// 3 - indian
	JCARED_P,		// 4 - turk
	OBRED_P,		// 5 - swat
	LBLU_P,			// 6 - lia
	R1PAL2_P,	    // 7 - robo1
	R2PAL2_P,		// 8 - robo2
	KUNGBLU_P,		//  9 - kung lao
	TSBLU_P,		// 10 - tusk
	FGBLUE_P,		// 11 - she goro
	TSRED_P,		// 12 - shang tsung
	LKYELO_P,		// 13 - kang
	SMOKE2_P,		// 14 - smoke
	KIT2_P,		// 15 - kitana
	JADE2_P,		// 16 - jade
	MIL2_P,		// 17 - mileena
	SCORP2_P,
	REP2_P,
	ERMAC2_P,
	SUBZ2_P,
	NJSMOKE2_P,	// 21 - ninja smoke
	noob2_p,		// Noob Saibot

	RADRED_P,			// rayden			//-u64-
	UGBLUE_P,			// baraka
	RAIN2_P,			// rain

	KAM2_P,				// kamel
	noob_p,		// Noob Saibot
	noob_p,		// Noob Saibot

	MOTARO_P,			//15 - motaro
	BGPAL1_P,			// 16 - shao kahn
};

void tot_my_pal(void) 
{
	if ((current_proc->pdata.p_otherguy)->ochar==(current_proc->pa8)->ochar)	
		swpal(character_palettes_2[(current_proc->pa8)->ochar],current_proc->pa8);
	else swpal(character_palettes_1[(current_proc->pa8)->ochar],current_proc->pa8);

	return;
}

/******************************************************************************
 Function: void setup_players(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Initialize players 1 & 2
******************************************************************************/
void setup_players(void)
{
	OBJECT *obj;
	PROCESS *ptemp1;
	PROCESS *ptemp2;

	/* for now there are now wingmen */
	f_wait_for_wings=0;
	
	/* setup shadow adjust ram */
	p1_shadadj=	shadow_adjustments[p1_char];
	p2_shadadj=shadow_adjustments[p2_char];

	/* give advantage to players */
	if (random()<0)
	{
		/* advantage p2 */
		setup_player_2(TRUE);
		setup_player_1(TRUE);
	}
	else
	{
		/* advantage p1 */
		setup_player_1(TRUE);
		setup_player_2(TRUE);
	}

	init_p_others();

	return;
}

void init_p_others(void)
{
	p1_proc->pdata.p_otherguy=p2_obj;
	p1_proc->pdata.p_otherproc=p2_proc;

	p2_proc->pdata.p_otherguy=p1_obj;
	p2_proc->pdata.p_otherproc=p1_proc;

	if (f_special_match==1)
 		setup_1on1_wingmen();		// 1 on 1 (Standard Mortal Kombat)
 	else
 	{
		switch (mode_of_play)
		{
			case 1:
				setup_2on2_wingmen();		// 2 on 2 mode
				break;
			case 4:
				setup_3on3_wingmen();		// 2 on 2 mode
				break;
			case 2:							// tournament
				break;
			case 0:
			default:
				setup_1on1_wingmen();		// 1 on 1 (Standard Mortal Kombat)
				break;
		}
 	}

	return;
}

char txt_1p_endur[]="ENDURANCE ROUND";
extern WORD *endurance_tables[];

void setup_1on1_wingmen(void) 
{
	WORD t_a0;			// ptr to endurance players
	WORD *table;

	init_intro_buckets();
	
	if (count_active_players()==0 || count_active_players()==2)
		return;				// 0 or 2 players -4 get it

	round_results=who_is_alone()-1;		// needed for next routine
	if (is_endurance_possible()==SYSTEM_CARRY_CLR)
		return;					

	pds_centered(txt_1p_endur,SCX(0xc8),SCY(0xed));		// text: 1p endurance

	t_a0=current_proc->a0;
	table=endurance_tables[t_a0 & 0x7f];

	if (p1_state==PS_ACTIVE) 
	{
		p2_wing(*(table+((LONG)current_proc->pdata.p_slave)+1),0x20,4);
		p2_obj->oxpos.u.intpos-=0x10;
	}
	else
	{
		p1_wing(*(table+((LONG)current_proc->pdata.p_slave)+1),0x20,2);
		p1_obj->oxpos.u.intpos+=0x10;
	}
	
	return;
} 

extern char txt_2_on_2[];
void setup_2on2_wingmen(void) 
{
	pds_centered(txt_2_on_2,SCX(0xc8),SCY(0x80));
	init_intro_buckets();
	
	p1_wing(p3_char,0x28,2);
	p2_wing(p4_char,0x28,4);

	return;
}

extern char txt_3_on_3[];
void setup_3on3_wingmen(void) 
{
	pds_centered(txt_3_on_3,SCX(0xc8),SCY(0x80));

	init_intro_buckets();
	
	p1_obj->oxpos.u.intpos+=12;
	p2_obj->oxpos.u.intpos-=12;
	
	p1_wing(p3_char,0x18,2);
	p1_wing(p5_char,0x3c,3);
	p2_wing(p4_char,0x18,4);
	p2_wing(p6_char,0x3c,5);

	return;
}

void p2_wing(WORD pchar,short xpos,WORD index) 
{
	OBJECT *obj;
	
	f_wait_for_wings+=WINGS_P2_DEC;
	obj=make_intro_ochar_obj(pchar,SCRRGT-2*SCX(0x30)+xpos,index);
	flip_multi(obj);		// new "fighter" obj
	CREATE(PID_WINGS2,wings2);			// new "fighter" proc
	return;
}

void p1_wing(WORD pchar,short xpos,WORD index) 
{
	OBJECT *obj;

	f_wait_for_wings+=WINGS_P1_DEC;
	obj=make_intro_ochar_obj(pchar,SCX(0x30)*2-xpos,index);
	CREATE(PID_WINGS1,wings1);			// new "fighter" proc
	
	return;
}

OBJECT *make_intro_ochar_obj(WORD pchar,short ta1,WORD index) 
{
	BYTE *heap;

	heap=a9_intro_ochar_frame_1(pchar,index);			// base for data
	
	current_proc->a10=(ADDRESS)gmo_proc_special(heap,heap+256,PFLAG_PALLOAD);		// get obj for fake player
	
	(ADDRESS)(current_proc->pa8)->oslink=current_proc->a10;	// link dummy proc with obj
	
	(current_proc->pa8)->ochar=pchar;		// set fake players ochar
	
	ground_ochar();

	(current_proc->pa8)->oxpos.u.intpos=worldtlx.u.intpos+ta1;		// world x offset

	current_proc->pdata.p_flags|=PM_ALT_PAL;
	
	player_normpal();
	
	insert_object(current_proc->pa8,&objlst);

	return(current_proc->pa8);
}

OBJECT *make_tot_ochar_obj(WORD pchar,short xpos,BYTE *odict) 
{
	OBJECT *obj;
	void *heap;
	BYTE *dict=odict;
	ADDRESS *animframe;

//***************************************************
//	a9_ochar_frame_1 (start)
//***************************************************	
	/* we will use existing character to setup object */
	heap=dict+256;
 	animframe=(ADDRESS *)COMPUTE_ADDR(heap,*((ADDRESS *)heap));			// frame #1 stance
	/* mpo5 */
	while (*animframe==ANI_OCHAR_JUMP)
	{
		animframe++;
		if (*animframe==pchar) 
		{
			animframe++;
			animframe=(ADDRESS *)COMPUTE_ADDR(heap,*(animframe));
		}
		else
		{
			animframe+=2;
		}
	}
	current_proc->pa9=animframe;
//***************************************************
//	a9_ochar_frame_1 (end)
//***************************************************	
	gmo_proc(dict,dict+256);
	obj=current_proc->pa8;
	dealloc_vram_mem(obj->ovcache);
	obj->ochar=pchar;
	ground_ochar();
	
	obj->oxpos.u.intpos=xpos+worldtlx.u.intpos;
	current_proc->pdata.p_flags|=PM_ALT_PAL;
	
	player_normpal();
	
	//-DO NOT INSERT OBJECT, ALLOW OTHER ROUTINE TO DO THIS AFTER A GOOD LOAD CHARACTER
	
	return(obj);
}

void setup_player_1(WORD loadflag)
{
	WORD tid;

	tid=current_proc->procid;
	current_proc->procid=PID_P1;
	make_player_1_obj(loadflag);
	current_proc->procid=tid;

	if (p1_state==PS_ACTIVE)
		p1_proc=process_create(PID_P1,joy_begin);
	else p1_proc=process_create(PID_P1,drone_begin);

	p1_proc->pdata.p_ganiy=p1_obj->oypos.u.intpos;				/* set grounded y pos */

	(p1_proc->pa8)=p1_obj;									/* save object to process local a8 */

	sys_memset(&p1_proc->pdata,0,sizeof(PDATA));					/* clear pdata structure */

	p1_proc->pdata.p_ganiy=p1_obj->oypos.u.intpos;				/* set grounded y pos */

	p1_proc->pdata.p_joyport=(WORD*)&swcurr.u.p1pad;						/* setup switch stuff */

	get_player_palette(character_palettes_1);

	insert_object(p1_obj,&objlst);

	return;
}

void setup_player_2(WORD loadflag)
{
	WORD tid;

	tid=current_proc->procid;
	current_proc->procid=PID_P2;
	make_player_2_obj(loadflag);
	current_proc->procid=tid;

	if (p2_state==PS_ACTIVE)
		p2_proc=process_create(PID_P2,joy_begin);
	else p2_proc=process_create(PID_P2,drone_begin);

	p2_proc->pdata.p_ganiy=p2_obj->oypos.u.intpos;				/* set grounded y pos */

	p2_proc->pa8=p2_obj;									/* save object to process local a8 */

	sys_memset(&p2_proc->pdata,0,sizeof(PDATA));					/* clear pdata structure */

	p2_proc->pdata.p_ganiy=p2_obj->oypos.u.intpos;				/* set grounded y pos */

	p2_proc->pdata.p_joyport=(WORD*)&swcurr.u.p2pad;						/* setup switch stuff */

	/* player --> check player 1 ochar (dont use same palette) */
	if (gstate!=GS_PSEL && q_nice_pal()==SYSTEM_CARRY_CLR)
	{
		p2_obj->oflags2|=M_UGLY_PAL;
		get_player_palette(character_palettes_2);
	}
	else get_player_palette(character_palettes_1);

	insert_object(p2_obj,&objlst);

	return;
}

/******************************************************************************
 Function: void get_player_palette(void *paltbl)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	retrieve correct player palette
******************************************************************************/
void get_player_palette(void *paltbl)
{
	OBJECT *obj=current_proc->pa8;

	obj->opal=get_fore_pal( (WORD *) (*((ADDRESS *)paltbl+obj->ochar)));

	return;
}

/******************************************************************************
 Function: void make_player_1_obj(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Setup player 1 object
******************************************************************************/
void make_player_1_obj(WORD loadflag)
{
	character_texture_load(p1_char,CHAR_NORMAL,p1_heap,SYNC_LOAD);
		
	p1_heap_char=p1_char;							// assign character with heap
	p1_name_char=p1_char;
	p1_obj=make_player_obj(p1_char,SHADOW_MODE,PLAYER1_TYPE,p1_heap,0);

	p1_obj->oid=OID_P1;
	p1_obj->ozval=FRONT_Z;
	set_x_woff(p1_obj);

	current_proc->pa8=p1_obj;
	do_first_a9_frame(ANIM_STANCE);

	return;
}

/******************************************************************************
 Function: void make_player_2_obj(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	Setup player 2 object
******************************************************************************/
void make_player_2_obj(WORD loadflag)
{	
	character_texture_load(p2_char,CHAR_NORMAL,p2_heap,SYNC_LOAD);
	p2_heap_char=p2_char;							// assign character with heap
	p2_name_char=p2_char;

	p2_obj=make_player_obj(p2_char,SHADOW_MODE,PLAYER2_TYPE,p2_heap,0);

	p2_obj->oid=OID_P2;
	p2_obj->ozval=BACK_Z;
	set_x_woff(p2_obj);

	current_proc->pa8=p2_obj;

	do_first_a9_frame(ANIM_STANCE);
	flip_multi(p2_obj);

	return;
}

/******************************************************************************
 Function: OBJECT *make_player_obj(WORD pchar,WORD f_shad,WORD player,void *heap,void *mram)

 By: David Schwartz

 Date: Sept 1994

 Parameters: pchar - id of character
			 f_shad - shadows on/off (1=on 0=off)
			 player - player 1(0) or player 2(1)
			 heap - base start addr
			 mram - multipart ram area for player

 Returns: ptr to created object

 Description:	create a player object
******************************************************************************/
OBJECT *make_player_obj(WORD pchar,WORD f_shad,WORD player,void *heap,void *mram)
{
	WORD obj_flags=0;
	OBJECT *obj;
	ADDRESS *animframe;
	WORD palflag;
	BYTE *dict;
	
	dict=heap;
	heap=dict+256;

	palflag=(player==0) ? PFLAG_FIGHTER:(PFLAG_FIGHTER|PFLAG_FIGHTER2);

 	animframe=(ADDRESS *)COMPUTE_ADDR(heap,*((ADDRESS *)heap));			// frame #1 stance

	/* mpo5 */
	while (*animframe==ANI_OCHAR_JUMP)
	{
		animframe+=2;
		animframe=(ADDRESS *)COMPUTE_ADDR(heap,*(animframe));
	}

	/* mpo7 */
	obj=get_multi_obj((ADDRESS *)COMPUTE_ADDR(heap,*animframe),mram,dict,heap,palflag);			// init the object (palflag set for fighters)

	obj->ochar=pchar;								// set character

	obj->oflags |=(M_FIGHTER);					// set fighter flag for sony vram management

	obj->oflags2 |=(obj_flags);								// set palette & multipart bit

	ochar_bank_bit(obj);
	ground_ochar();

	current_proc->pdata.p_flags=0;						// clear process flags

	player_normpal();

	return(obj);
}

//***************************************************************
//***************************************************************
BYTE bucket_map[]=
{
	0,1,2,3,4,5,6,7,7,8,9,10,11,12,7,13,13,13,
	14,14,14,14,14,14,15,16,14,13,17,18,19,20
};
void clear_buckets(void) 
{
	int i;
	
	for (i=0;i<END_BUCKET_COUNT;i++ )
	{
		bucket[i].bchar=0xffff;
		bucket[i].bcnt=bucket[i].bdict=0;
	}

	bucket_mode=0;
}

void init_intro_buckets(void) 
{
	clear_buckets();
	
	/* set player 1 */
	bucket[0].bcnt=1;
	bucket[0].bchar=p1_char;
	bucket[0].bdict=(BYTE *)p1_heap;
	
	/* set player 2 */
	bucket[1].bcnt=1;
	bucket[1].bchar=p2_char;
	bucket[1].bdict=(BYTE *)p2_heap;
	
	return;
}

void remove_bucket(WORD pchar) 
{
	int i,count;
	
	count=(bucket_mode==0)?BUCKET_COUNT:END_BUCKET_COUNT;

	for (i=0;i<count;i++)
	{
		if (bucket_map[bucket[i].bchar]==bucket_map[pchar])
		{
#if SYS_DEBUG		
			if (bucket[i].bcnt==0)
				printf(("ERROR: RELEASEING BUCKET WITH COUNT OF 0\n"));
#endif			
			bucket[i].bcnt--;	
			return;
		}
	}
}

void *a9_ochar_frame_1(WORD pa9,WORD heapnum) 
{
	void *heap;
	BYTE *dict;
	ADDRESS *animframe;
	int i;
	int bsize,bcount;
	
	if (bucket_mode==0) 
	{
		bsize=BUCKET_SIZE;
		bcount=BUCKET_COUNT;
	}
	else
	{
		bsize=END_BUCKET_SIZE;
		bcount=END_BUCKET_COUNT;
	}
	
	/* see if character already loaded */
	for (i=0;i<bcount;i++)
	{
		if (bucket_map[bucket[i].bchar]==bucket_map[pa9] && bucket[i].bcnt!=0)  
		{
			bucket[i].bcnt++;
			dict=(BYTE *)p1_heap+i*(1024+bsize);
			goto SETUP_FRAME;
		}
	}
	
	/* find empty bucket */
	i=0;
	while (bucket[i].bcnt!=0)
	{
		i++;
		if (i==bcount)
		{
#if SYS_DEBUG
			printf(("ERROR: BUCKET COUNT EXCEED \n"));
#endif
			return(NULL);
		}
	}
	
	/* setup bucket */
	bucket[i].bchar=pa9;		// asign user
	bucket[i].bcnt=1;			// 1 user using it
	
	/* load character data */
	dict=(BYTE*)p1_heap+i*(1024+bsize);
	character_texture_load(pa9,(bucket_mode==0)?CHAR_SELECT:CHAR_ENDING,dict,SYNC_LOAD);


SETUP_FRAME:	
	heap=dict+256;
	
 	animframe=(ADDRESS *)COMPUTE_ADDR(heap,*((ADDRESS *)heap));			// frame #1 stance

	/* mpo5 */
	while (*animframe==ANI_OCHAR_JUMP)
	{
		animframe++;
		if (*animframe==pa9) 
		{
			animframe++;
			animframe=(ADDRESS *)COMPUTE_ADDR(heap,*(animframe));
		}
		else
		{
			animframe+=2;
		}
	}

	current_proc->pa9=animframe;

	return(dict);
}

void *a9_intro_ochar_frame_1(WORD pa9,WORD index) 
{
	void *heap;
	BYTE *dict;
	ADDRESS *animframe;
	int i;
	
	if (index<=1) 
	{
		if (index==0)
		{
			dict=(BYTE *)p1_heap;
		}
		else
		{
			dict=(BYTE *)p2_heap;
		}
	}
	else
	{
		/* see if character already loaded */
		for (i=2;i<BUCKET_COUNT;i++)
		{
			if (bucket_map[bucket[i].bchar]==bucket_map[pa9] && bucket[i].bcnt!=0)  
			{
				bucket[i].bcnt++;
				dict=bucket[i].bdict;
				goto SETUP_FRAME;
			}
		}
	
		/* setup bucket */
		if (index<4) 
		{
			dict=(((BYTE*)p1_heap)+PLAYER_HEAP_SIZE/2)-(index-1)*(INTRO_BUCKET_SIZE+1024);
		}
		else
		{
			dict=(((BYTE*)p2_heap)+PLAYER_HEAP_SIZE/2)-(index-3)*(INTRO_BUCKET_SIZE+1024);
		}
	}
	
	bucket[index].bchar=pa9;		// asign user
	bucket[index].bcnt=1;			// 1 user using it
	bucket[index].bdict=dict;			// location of data
	
	/* load character data */
	character_texture_load(pa9,CHAR_INTRO,dict,SYNC_LOAD);
SETUP_FRAME:	
	heap=dict+256;
	
 	animframe=(ADDRESS *)COMPUTE_ADDR(heap,*((ADDRESS *)heap));			// frame #1 stance

	/* mpo5 */
	while (*animframe==ANI_OCHAR_JUMP)
	{
		animframe++;
		if (*animframe==pa9) 
		{
			animframe++;
			animframe=(ADDRESS *)COMPUTE_ADDR(heap,*(animframe));
		}
		else
		{
			animframe+=2;
		}
	}

	current_proc->pa9=animframe;

	return(dict);
}
//***************************************************************
//***************************************************************

/******************************************************************************
 Function: void set_x_woff(OBJECT *pa8)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa8 - object

 Returns: None

 Description:	set starting position
******************************************************************************/
void set_x_woff(OBJECT *pa8)
{
	short ta3;
	short ta2;

	ta3=(pa8->ochar==FT_MOTARO)?SCX(0x30)+SCX(0x60):SCX(0x60);

	/* setx3 */
	ta2=worldtlx.u.intpos;
	if (p1_obj!=pa8)
	{
		ta2+=SCRRGT;
		ta3=-ta3;
	}

	pa8->oxpos.u.intpos=ta2+ta3;

	return;
}


/******************************************************************************
 Function: void ochar_bank_bit(OBJECT *pa8)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa8 - object

 Returns: ptr to created object

 Description:	set bank bit if neccessary
******************************************************************************/
void ochar_bank_bit(OBJECT *pa8)
{
	if (pa8->ochar<FT_SG)
		clear_bank_bit(pa8);
	else set_bank_bit(pa8);

	return;
}

/******************************************************************************
 Function: void *get_char_ani(WORD tableindex,short animnum)

 By: David Schwartz

 Date: Sept 1994

 Parameters: tableindex - which animation tables to use
				ANIM_TABLE1 = basic move tables
				ANIM_TABLE2 = special move tables
			animnum - which animation to get

 Returns: ptr to animation table
		  current_proc->pa9 - ptr to anim table

 Description:	finds the first frame to display of a character
******************************************************************************/
void *get_char_ani(WORD tableindex,short animnum)
{
	ADDRESS *animtab;

	animtab=(tableindex==ANIM_TABLE1) ? (ADDRESS *)(current_proc->pa8->oheap):((ADDRESS *)(current_proc->pa8->oheap)+ANIM_TABLE2_OFFSET);
	return((ADDRESS *)current_proc->pa9=(ADDRESS *)COMPUTE_ADDR(current_proc->pa8->oheap,(*(animtab+animnum))));
}

/******************************************************************************
 Function: void ground_ochar(void);

 By: David Schwartz

 Date: Sept 1994

 Parameters: current_proc->pa8 - object ptr

 Returns: None

 Description:	places fighter on ground
******************************************************************************/
void ground_ochar(void)
{
	OBJECT *obj;

	obj=current_proc->pa8;
	obj->oypos.u.intpos=ground_y-ochar_ground_offsets[obj->ochar];

	return;
}

/******************************************************************************
 Function: void player_normpal(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: current_proc->pa8 - object ptr
			 current_proc - controlling process

 Returns: None


 Description:	players use this routine to switch back to their normal palette
******************************************************************************/
void player_normpal(void)
{
	OBJECT *currobj;

	if ((current_proc->pdata.p_flags & PM_ALT_PAL) != 0)
	{
		currobj=current_proc->pa8;

		if (current_proc->pdata.p_flags & PM_KAMEL)
		{
			swpal(character_palettes_1[FT_KAMEL],currobj);
			return;
		}
		
		/* if same character and other char is using nice pal then use ugly pal */
		if (q_nice_pal()==SYSTEM_CARRY_CLR)
		{
			player_ugly_pal();
			return;
		}
		else
		{
			/* nice pal */
			currobj->oflags2 &=(~M_UGLY_PAL);		// flag: clear ugly palette
			swpal(character_palettes_1[currobj->ochar],currobj);
			current_proc->pdata.p_flags &=(~PM_ALT_PAL);		// flag: i am not using alt palette
			return;
		}
	}

	return;
}

void player_ugly_pal(void) 
{
	/* ugly pal */
	(current_proc->pa8)->oflags2 |=M_UGLY_PAL;			// flag: set ugly palette
	swpal(character_palettes_2[(current_proc->pa8)->ochar],current_proc->pa8);
	current_proc->pdata.p_flags &=(~PM_ALT_PAL);		// flag: i am not using alt palette

	return;
}

/******************************************************************************
 Function: void stance_setup(void)

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: None

 Description:	set fighter into his stance animation
******************************************************************************/
void stance_setup(void)
{
static BYTE stance_speeds[] = {
	8,   					// 0 - kano
	8,						// 1 - sonya
	6,						// 2 - jax
	10,						// 3 - indian
	6,						// 4 - turk (subzero)
	6,						// 5 - swat
	8,						// 6 - lia
	8,						// 7 - robot ninja
	8,						// 8 - robot ninja
	8,						// 9 - kung lao
	8,						// 10 - tusk
	6,						// 11 - she goro
	6,						// 12 - shang tsu
	6,						// 13 - liu kang
	8,						// 14 - smoke

	7,						// 15 - kitana
	8,						// 16 - jade
	8,						// 17 - mil
	8,						// 18 - scorpion
	8,						// 19 - reptile
	8,						// 20 - 
	8,						// 21 - 
	8,						// 22 - 
	8,						// 23 - 
	6,						// 24 - ray	-u64-
	6,						// 25 - bara
	8,						// 26 - rain
	
	8,						// 27 - 
	6,						// 28 - 
	8,						// 29 - 
	
	6,						// 24 - motaro
	8						// 25 - shao kahn
};

	current_proc->pdata.p_action=ACT_STANCE;

	current_proc->a5=(ADDRESS)current_proc->pa9;

	get_char_ani(ANIM_TABLE1,ANIM_STANCE);

	/* stset2 */
	current_proc->a7=(ADDRESS)current_proc->pa9;		// a7 = stance frame #1

	init_anirate(stance_speeds[current_proc->pa8->ochar]);

	/* stset0 */
	while (GET_LONG(current_proc->a7)==ANI_OCHAR_JUMP)		// are we at the "loop back pt"
	{
		((ADDRESS *)current_proc->a7)+=2;
		current_proc->a7=COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->a7));
	}

	/* stset1 */
	((ADDRESS *)current_proc->a7)+=4;			// set least this far

	/* stset3 */
	while (GET_LONG(current_proc->a7)!=ANI_JUMP)		// are we at the "loop back pt"
	{
		((ADDRESS *)current_proc->a7)++;
	}

	if (current_proc->a5>current_proc->a7)			// we were not in stance ---> new ani
		return;

	if (current_proc->a5<(ADDRESS)current_proc->pa9)			// we were not in stance ---> new ani
		return;

	(ADDRESS)current_proc->pa9=current_proc->a5;				// we were in stance ---> keep same ani
	return;
}

/******************************************************************************
 Function: LONG get_walk_info_f(void);

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: walk forward ani offset
		current_proc->a0 - walk forward animate speed
		current_proc->a1 - walk forward velocity
		current_proc->a2 - walk forward ani offset

 Description:	returns the walk forward info
******************************************************************************/
LONG get_walk_info_f(void)
{
	OBJECT *obj=current_proc->pa8;

	static short walk_forward_info[][2] = {
		/* anim speed, velocity */
		{7,SCX(0x3800)},	//  0 - kano
		{7,SCX(0x3000)},	//  1 - sonya
		{7,SCX(0x3000)},	//  2 - jax
		{7,SCX(0x3400)},	//  3 - indian
		{7,SCX(0x3400)},	//  4 - turk (subzero)
		{7,SCX(0x3000)},	//  5 - swat
		{7,SCX(0x3800)},	//  6 - lia
		{7,SCX(0x3400)},	//  7 - robot ninja
		{7,SCX(0x3400)},	//  8 - robot ninja
		{7,SCX(0x3400)},	//  9 - kung lao
		{7,SCX(0x3000)},	// 10 - tusk
		{7,SCX(0x3000)},	// 11 - she goro
		{7,SCX(0x3200)},	// 12 - shang tsung
		{7,SCX(0x3200)},	// 13 - kang
		{7,SCX(0x3400)},	// 14 - smoke

		{7,SCX(0x3400)},	// 15 - kitana
		{7,SCX(0x3800)},	// 16 - jade
		{7,SCX(0x3400)},	// 17 - mileena
		{7,SCX(0x3400)},	// 18 - scorpion
		{7,SCX(0x3400)},	// 19 - reptile
		{7,SCX(0x3400)},	// 20 - ermac
		{7,SCX(0x3400)},	// 21 - old subzero
		{7,SCX(0x4000)},	// 22 - old smoke
		{7,SCX(0x3400)},	// 23 - noob

		{7,SCX(0x3300)},	// 24 -  rayden
		{7,SCX(0x3600)},	// 25 -  baraka
		{7,SCX(0x3400)},	// 26 - rain

		{6,SCX(0x5000)},	// 27 - 
		{8,SCX(0x3400)},	// 28 - 
		{8,SCX(0x3400)},	// 29 - 

		{5,SCX(0x4000)},	// 24 - motaro
		{3,SCX(0x5000)},	// 25 - shao kahn
	};

	(LONG)current_proc->a0=walk_forward_info[obj->ochar][0];

	(long)current_proc->a1=(obj->oflags & M_FLIPH) ? -((long)(walk_forward_info[obj->ochar][1]<<4)):((long)(walk_forward_info[obj->ochar][1]<<4));

	return((LONG)current_proc->a2=ANIM_WALKF);
}

/******************************************************************************
 Function: LONG get_walk_info_b(void);

 By: David Schwartz

 Date: Sept 1994

 Parameters: None

 Returns: walk backword ani offset
		current_proc->a0 - walk backward animate speed
		current_proc->a1 - walk backward velocity
		current_proc->a2 - walk backward ani offset

 Description:	returns the walk backward info
******************************************************************************/
LONG get_walk_info_b(void)
{
	OBJECT *obj=current_proc->pa8;

	static short walk_backward_info[][2] = {
		/* anim speed, velocity */
		{7,SCX(0x2400)},	// 0 - kano
		{7,SCX(0x2400)},	// 1 - sonya
		{7,SCX(0x2400)},	// 2 - jax
		{7,SCX(0x2400)},	// 3 - indian
		{7,SCX(0x2400)},	// 4 - turk (subzero)
		{7,SCX(0x2400)},	// 5 - swat
		{7,SCX(0x2400)},	// 6 - lia
		{7,SCX(0x2400)},	// 7 - robo
		{7,SCX(0x2400)},	// 8 - robo
		{7,SCX(0x2400)},	// 9 - kung lao
		{7,SCX(0x2400)},	//10 - tusk
		{7,SCX(0x2400)},	//11 - she goro
		{7,SCX(0x2400)},	//12 - shang tsung
		{7,SCX(0x2400)},	//13 - kang
		{7,SCX(0x2400)},	// 14 - smoke
		{7,SCX(0x2400)},	// 15 - kitana
		{7,SCX(0x2400)},	// 16 - jade
		{7,SCX(0x2400)},	// 17 - mileena
		{7,SCX(0x2400)},	// 18 - scorpion
		{7,SCX(0x2400)},	// 19 - reptile
		{7,SCX(0x2400)},	// 20 - ermac
		{7,SCX(0x2400)},	// 21 - oldsz
		{7,SCX(0x2800)},	// 22 - old smoke
		{7,SCX(0x2400)},	//
		
		{7,SCX(0x2300)},	// rayde 
		{7,SCX(0x2600)},	// bara
		{7,SCX(0x2400)},	// rain
		
		{6,SCX(0x3000)},	//
		{8,SCX(0x3000)},	//
		{8,SCX(0x3000)},	//
		

		{4,SCX(0x4000)},	// 15 - motaro
		{4,SCX(0x4000)}	// 16 - shao kahn
	};
	
	(LONG)current_proc->a0=walk_backward_info[obj->ochar][0];

	(long)current_proc->a1=(obj->oflags & M_FLIPH) ? ((long)(walk_backward_info[obj->ochar][1]<<4)):-((long)(walk_backward_info[obj->ochar][1]<<4));

	return((LONG)current_proc->a2=ANIM_WALKB);
}

extern WORD RAYFROZN_P[];
extern WORD UGFROZN_P[];
extern WORD JCFROZN_P[];
void *ochar_froze_pals[] =
{
	KNFROZN_P,	// 0
	SBFROZN_P,	// 1
	JXFROZN_P,	// 2
	INFROZN_P,	// 3
	JCFROZN_P,	// 4
	OBFROZN_P,	// 5
	LIFROZN_P,	// 6
	RBFROZN_P,	// 7
	RBFROZN_P,	// 8
	KLFROZN_P,	// 9 - kung lao
	TRFROZN_P,	// 10
	SHFROZN_P,	// 11
	TSFROZN_P,	// 12
	LUFROZN_P,	// 13
	RBFROZN_P,	// 14

	KTFRZ_P,
	KTFRZ_P,
	KTFRZ_P,

	SCFRZ_P,
	SCFRZ_P,
	SCFRZ_P,
	SCFRZ_P,
	SCFRZ_P,
	SCFRZ_P,

	RAYFROZN_P,		// rayden	-u64-
	UGFROZN_P,		// bara
	SCFRZ_P,
	KTFRZ_P,

	SCFRZ_P,
	SCFRZ_P,
	
	sk_shadow_p,	// 16 - shao kahn
	sk_shadow_p,	// 16 - shao kahn
	sk_shadow_p,	// 16 - shao kahn
	sk_shadow_p,	// 16 - shao kahn
};

/******************************************************************************
 Function: void player_froze_pal(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	freeze the current obj
******************************************************************************/
void player_froze_pal(void)
{
	player_swpal(current_proc,ochar_froze_pals[(current_proc->pa8)->ochar],current_proc->pa8);
	return;
}

/******************************************************************************
 Function: WORD q_nice_pal(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: SYSTEM_CARRY_SET - use nice palette
		  SYSTEM_CARRY_CLR - use ugly palette

 Description:	determine if both guys are same, if so then use ugly palette
******************************************************************************/
WORD q_nice_pal(void)
{
	if (winner_status==3 && (mode_of_play==1 || mode_of_play==4))
	{
		if (current_proc->pa8==p1_obj)
		{
			current_proc->a0=p1_char;
			current_proc->a1=p3_char;
		}
		else
		{
			current_proc->a0=p3_char;
			current_proc->a1=p1_char;
	   	}
	}
	else
	{
		if (gstate==GS_PSEL || gstate==GS_POST_PSEL) 
		{
			current_proc->a0=p1_char;
			current_proc->a1=p2_char;
		}
		else
		{
			if (current_proc->pa8==p1_obj)
			{
				current_proc->a0=p1_char;
				current_proc->a1=p2_char;
				
			}
			else
			{
				current_proc->a0=p2_char;
				current_proc->a1=p1_char;
	   		}
		}
	}
	
	/* pnp3 */
	if (current_proc->a1!=FT_ST)
	{
		/* he_is_not_shang */
		if (current_proc->a0==FT_ST)
		{
			/* i_am_shang_he_is_not */
			if ((current_proc->pa8)->ochar==FT_ST)
				return(SYSTEM_CARRY_SET);

			if ((current_proc->pa8)->ochar==current_proc->a1)
				return(SYSTEM_CARRY_CLR);
		}
		else
		{
			/* neither_are_shang */
			if (current_proc->a0==current_proc->a1)
			{
				/* neither_shang_same */
				if (p2_obj==current_proc->pa8)
					return(SYSTEM_CARRY_CLR);
				else return(SYSTEM_CARRY_SET);
			}
			else return(SYSTEM_CARRY_SET);				// neither_shang_different
		}
	}
	else
	{
		/* he_is_shang */
		if (current_proc->a0==current_proc->a1)
		{
			/* we_are_shangs */
			if (current_proc->pa8==p2_obj)	// && p2_obj->ochar==FT_ST)
				return(SYSTEM_CARRY_CLR);		// 2 shangs p2=ugly
			else return(SYSTEM_CARRY_SET);		// 2 shangs p1=nice
		}
	}
	return(SYSTEM_CARRY_SET);			// he_is_shang_i_am_not

}

/******************************************************************************
 Function: void player_swpal_a0_image(void *pal)

 By: David Schwartz

 Date: Jan 1995

 Parameters: pal - palette to switch to

 Returns: None

 Description:	switch pal
******************************************************************************/
void player_swpal_a0_image(void *pal)
{
	/* any changes to this routine and you will need to see
	   how this affects any code that uses it.  -NOTE-
	*/

	player_swpal(current_proc,pal,current_proc->pa8);

	return;
}

/******************************************************************************
 Function: void shock_init(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	init robo shock move
******************************************************************************/
void shock_init(void)
{
	current_proc->pdata.p_store1=1;
	return;
}

/******************************************************************************
 Function: void shock_check(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	check for shock
******************************************************************************/
void shock_check(void)
{
	WORD temp;
	if ((temp=(current_proc->pdata.p_store1-1))==0)
	{
		current_proc->pdata.p_anirate=3;		// only show this for 2 ticks

		/* this is a change from the code.  We do not have the same struct, since our
		   multi part objs are really only 1 part.  This routine call is supoose to
		   load the palette from the multipart image "ROBOSHOCK1A".  We are simulate the
		   correct results.
		*/
//		player_swpal_a0_image(ROBSHKB_P);
		((ADDRESS *)(current_proc->pa9))-=3;		// counter 2 lines ahead

		temp=(WORD)randu(4);
	}

	current_proc->pdata.p_store1=temp;
	((ADDRESS *)(current_proc->pa9))+=3;		// skip shock stuff

	return;
}

/******************************************************************************
 Function: void stun_speed_3(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	set stun anirate to 3
******************************************************************************/
void stun_speed_3(void)
{
	player_normpal();
	current_proc->pdata.p_anirate=5;
	return;
}

/******************************************************************************
 Function: void stun_speed_6(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	set stun anirate to 6
******************************************************************************/
void stun_speed_6(void)
{
	player_normpal();
	current_proc->pdata.p_anirate=9;
	return;
}

/******************************************************************************
 Function: void set_a10_to_him(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	switch other guy to a10
******************************************************************************/
void set_a10_to_him(void)
{
	(OBJECT *)current_proc->a10=current_proc->pdata.p_otherguy;
	return;
}

/******************************************************************************
 Function: void set_a10_to_slave(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	switch slave  to a10
******************************************************************************/
void set_a10_to_slave(void)
{
	(OBJECT *)current_proc->a10=current_proc->pdata.p_slave;
	return;
}

/******************************************************************************
 Function: void lineup_number_2(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: current_proc->a10

 Returns: None

 Description: 	lineup jax's 2nd missile
******************************************************************************/
void lineup_number_2(void)
{
	adjust_xy_a5((OBJECT *)current_proc->a10,-0x1a,-0x25);
	return;
}

/******************************************************************************
 Function: void sonya_zap_pal(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description: 	setup zap pal for sonya
******************************************************************************/
void sonya_zap_pal(void)
{
	if ((current_proc->pa8)->oflags2 & M_UGLY_PAL)
		player_swpal(current_proc,sbENG2_p,current_proc->pa8);		// we are using ugly pal, correct color
	else player_swpal(current_proc,sbENG_p,current_proc->pa8);
	return;
}

