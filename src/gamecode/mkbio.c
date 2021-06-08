/******************************************************************************
 File: mkbio.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Bios Setup
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkbio.h"
#include "mkdma.h"
#include "mktext.h"
#include "mkvs.h"
#include "mksound.h"

/* local externs */
void slide_paragraph(BYTE *ta11,short line_base);

/******************************************************************************
 Function: void ultimate_bio(WORD p_a0)

 By: David Schwartz

 Date: Mar 1995

 Parameters:  p_a0 - bio to show

 Returns: None

 Description:  lets see a history of our fighter
******************************************************************************/
extern char txt_kano_bio[];
extern char txt_sonya_bio[];
extern char txt_jax_bio[];
extern char txt_ind_bio[];
extern char txt_jc_bio[];
extern char txt_swat_bio[];
extern char txt_sindel_bio[];
extern char txt_sektor_bio[];
extern char txt_cyrax_bio[];
extern char txt_lao_bio[];
extern char txt_kabal_bio[];
extern char txt_sg_bio[];
extern char txt_st_bio[];
extern char txt_lk_bio[];
extern char txt_smoke_bio[];
extern char txt_kitana_bio[];
extern char txt_jade_bio[];
extern char txt_mileena_bio[];
extern char txt_scorpion_bio[];
extern char txt_reptile_bio[];
extern char txt_ermac_bio[];
extern char txt_oldsz_bio[];
extern char txt_oldsmoke_bio[];
extern char txt_noob_bio[];
extern char txt_rain_bio[];
extern char txt_rayden_bio[];
extern char txt_baraka_bio[];
extern char txt_kamel_bio[];

char *bio_titles[]=
{
	txt_kano_bio,
	txt_sonya_bio,
	txt_jax_bio,
	txt_ind_bio,
	txt_jc_bio,
	txt_swat_bio,
	txt_sindel_bio,
	txt_sektor_bio,
	txt_cyrax_bio,
	txt_lao_bio,
	txt_kabal_bio,
	txt_sg_bio,
	txt_st_bio,
	txt_lk_bio,

	txt_smoke_bio,

	txt_kitana_bio,
	txt_jade_bio,
	txt_mileena_bio,

	txt_scorpion_bio,
	txt_reptile_bio,
	txt_ermac_bio,
	txt_oldsz_bio,
	txt_oldsmoke_bio,
	txt_noob_bio,
	txt_rayden_bio,
	txt_baraka_bio,
	txt_rain_bio,
	txt_kamel_bio,
	txt_rain_bio,
	txt_rain_bio,
};

extern FNTSETUP pf_bio[];

void ultimate_bio(WORD p_a0)
{
	c_amode_bio++;
	if (c_amode_bio>=FT_CHARS_PLAY)
	{
		if (c_amode_bio==FT_CHARS_PLAY && f_kamel==1)
			goto SKIP_RESET;
		c_amode_bio=0;
	}
SKIP_RESET:		
	slide_in_left(p_a0);
	process_sleep(4);

	slide_paragraph(bio_titles[p_a0],13);
	sound_music_start(MUSIC_BUYIN);
	f_novel=1;
	process_sleep(40);
	f_novel=0;
	process_sleep(0x40*10);
	
	murder_myoinit_score();
	clr_scrn();
	process_sleep(10);
	return;
}

void slide_in_left(WORD p_a0) 
{
	OBJECT *oa1;
	DISPLAY_ON;
	murder_myoinit_score();					// display hell background
	do_background(BKGD_FIRE_MOD);

	/* load after any background stuff */
	loadoverlay(SYS_VSPLAY_OVL);
	build_huge_left(p_a0);			// slide in dude
	process_sleep(0x1a);

	f_novel=1;			// stop
	
	oa1=objlst;
	do
	{
		oa1->oxvel.pos=0;
	}
	while((oa1=oa1->olink)!=NULL);
	
	tsound2(0x00+p_a0);		// say the name

	return;
}

/******************************************************************************
 Function: void mk3_gradient(WORD pa0)

 By: David Schwartz

 Date: May 1995

 Parameters:  None

 Returns: None

 Description:  display fighter gradients
******************************************************************************/
extern void *gradient_txt[];
void mk3_gradient(WORD pa0)
{
	load_bkgd=BKGD_MK3_RGRAD+pa0;								// load correct gradient
	init_background_module(table_o_mods[load_bkgd]);
	multi_plane();
	return;
}



/* a11=oid, a10=direction */
#define SLIDE_STOP 284
void side_slider_proc(void) 
{
	OBJECT *oa1;
	short ta11=current_proc->a11;
	OBJECT *omin=NULL;
	short min=2000;
	short max=-9999;
	short overshoot;
	
	/* find min letter to search for */
	oa1=objlst;
	do
	{
		if (oa1->oid==ta11) 
		{
			if (oa1->oxpos.u.intpos>max) 
			{
				max=oa1->oxpos.u.intpos;
				omin=oa1;
			}
		}
	} 
	while ((oa1=oa1->olink)!=NULL);
	
	if (omin==NULL)
		process_suicide();

	/* wait until watch letter cross threshold */
	do
	{
		process_sleep(1);
		if (omin->oxvel.pos>0 && omin->oxpos.u.intpos>=SLIDE_STOP)
			break;
		
		if (omin->oxvel.pos<0 && omin->oxpos.u.intpos<=SLIDE_STOP)
			break;
	}
	while(1);

	overshoot=SLIDE_STOP-omin->oxpos.u.intpos;
	
	oa1=objlst;
	do
	{
		if (oa1->oid==ta11) 
		{
			oa1->oxvel.pos=0;
			oa1->oxpos.u.intpos+=overshoot;
		}
	} 
	while ((oa1=oa1->olink)!=NULL);
	
	process_suicide();
}

void set_slide_text(short oid,short direction)
{
	OBJECT *oa0;
	OBJECT *oa3;
	OBJECT *oa4,*oa5;
	
	f_novel=1;

	oa0=objlst2;
	if ( oa0!=NULL )
	{
		oa3=oa0;
		objlst2=NULL;

		/* scrp4 */
		do
		{
			if (oid!=OID_OPT_ID0)
				oa0->oxvel.pos=(direction==0)? -0x30000:0x40000;
			oa0->ozval=100;
			oa0->oid=oid;
		} while ((oa0=oa0->olink)!=NULL);

		oa4=objlst;
		if (oa4!=NULL )
		{
			/* scrp5 */
			do
			{
				oa5=oa4;
				oa4=oa4->olink;
			} while (oa4!=NULL);
			oa5->olink=oa3;
		}
		else objlst=oa3;
	}

	CREATE(PID_FLASHER,side_slider_proc)->a11=oid;
	
	/* slv9 */
	f_novel=0;

	return;
}

void slide_paragraph(BYTE *ta11,short line_base) 
{
	signed char ta0;
	PROCESS *ptemp;
	short oid;

	oid=OID_OPT_ID0;	
	do
	{
		if (oid==OID_OPT_ID0)
		{
		 	pds_centered_soff(ta11,220,line_base);		// print text
			line_base=fnt_state.fnt_posy-2;
			set_slide_text(oid,1);
		}
		else
		{
			if ((oid & 1)==0)
			{
				/* start on left side */
				pds_left_soff(ta11,0,line_base);		// print text
				line_base=fnt_state.fnt_posy-2;
				set_slide_text(oid,1);
			}
			else
			{
				/* start on right side */
				pds_right_soff(ta11,BUFFER_WIDTH,line_base);		// print text
				line_base=fnt_state.fnt_posy-2;
				set_slide_text(oid,0);
			}
		}
		
		/* goto next line */
		do
		{
			ta11++;
		}
		while(*ta11!=0);
		
		ta11++;
		
		ta0=*ta11;
		oid++;
	}
	while(ta0!=-1);
	
	return;
}

