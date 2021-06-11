/******************************************************************************
 File: mkfx.c

 Date: August 1994

 (C) Williams Entertainment

 Mortal Kombat III Special effects
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkobj.h"
#include "mkos.h"
#include "mkgame.h"
#include "mkguys.h"
#include "mkutil.h"
#include "moves.h"
#include "mkani.h"
#include "mkpal.h"
#include "mkmain.h"
#include "mktext.h"
#include "mkfx.h"
#include "mkfatal.h"
#include "mkfade.h"
#include "mkzap.h"
#include "mkblood.h"
#include "mksound.h"
#include "mkdma.h"
#include "mkscore.h"
#include "vcache.h"

#include <math.h>

/* externs */

/* spinning in/out objects */
extern OIMGTBL FINHIM1;
extern OIMGTBL FINHER1;
extern OIMGTBL FINFITE1;
extern void *a_fight_out[];
extern void *a_finhim_out[];
extern void *a_finher_out[];
extern WORD MKFIGHT_P[];
extern WORD FITEYEL_P[];
extern BYTE fight_dict[];
extern BYTE finhim_dict[];
extern BYTE finher_dict[];

/* exploding objects */
extern void *a_ground_explode[];
extern void *a_puff[];
extern void *a_dave_explode[];
extern void *PUFF1[];

/* mercy stuff */
extern void *MERCY_01[];
extern void *a_mercy[];

/* blood stuff */
extern void *a_blood_explode[];
extern void *ARM01[];
extern void *a_arm[];
extern void *ARM13[];
extern void *a_arm_land[];
extern void *ARM_B01[];
extern void *a_arm2[];
extern void *LEG01[];
extern void *a_leg[];
extern void *LEG_B01[];
extern void *a_leg2[];
extern void *XLIMB01[];
extern void *a_limb[];
extern void *BONE01[];
extern void *a_bone[];
extern void *CAGE01[];
extern void *a_rib_cage[];
extern void *SKULL01[];
extern void *a_skull[];
extern void *PORK01[];
extern void *a_pork[];
extern void *a_goro_arm[];
extern void *GOROARM02[];
extern BYTE blood_dict[];

/* rocks street */
extern void *a_small_rock[];
extern void *a_med_rock[];
extern void *a_large_rock[];
extern void *a_crumple[];
extern void *SMALL01[];
extern void *MEDIUM01[];
extern void *LARGE01[];
extern BYTE rock_dict[];

/* palettes */
extern WORD RBLDXPD_P[];
extern WORD SBLDXPD_P[];
extern WORD BLDXPD_P[];
extern WORD SMDRIP_P[];
extern WORD SHEDRIP6_PAL[];
extern WORD ROBOSMDRIP6_PAL[];

/* combo stuff */
extern void *damage_s[];
extern void *hits_s[];
extern void *TOASTY[];

/* danger */
extern void *DANGER[];

/* explode stuff */
extern BYTE explode_dict[];

/* blood palettes for blood explode */
/* blood palettes for blood explode */
WORD *ochar_bloodxpd_palettes[]=
{
	BLDXPD_P,			// 0
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,			// 5
	BLDXPD_P,
	RBLDXPD_P,
	RBLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,			// 10
	SBLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	RBLDXPD_P,
	BLDXPD_P,			// 15
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	SBLDXPD_P,
	BLDXPD_P,			// 20
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	
	BLDXPD_P,		//-u64-
	BLDXPD_P,
	BLDXPD_P,
	BLDXPD_P,
	
	BLDXPD_P,
	BLDXPD_P,

	SBLDXPD_P,
	BLDXPD_P,
};

WORD *ochar_blooddrip_palettes[]=
{
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	ROBOSMDRIP6_PAL,
	ROBOSMDRIP6_PAL,
	SMDRIP_P,
	SMDRIP_P,
	SHEDRIP6_PAL,
	SMDRIP_P,
	SMDRIP_P,
	ROBOSMDRIP6_PAL,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SHEDRIP6_PAL,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,
	
	SMDRIP_P,		//-u64-
	SMDRIP_P,
	SMDRIP_P,
	SMDRIP_P,

	SMDRIP_P,
	SMDRIP_P,
	
	SHEDRIP6_PAL,
	SMDRIP_P
};

/******************************************************************************
 Function: void shake_a11(WORD pixels,WORD shake)

 By: David Schwartz

 Date: Nov 1994

 Parameters: pixels - amount to shake world [32..16]
			 shake - # of times to shake world [15..0]

 Returns: None

 Description:	setup to shake the world
******************************************************************************/
void shake_a11(WORD pixels,WORD shake)
{
	PROCESS *ptemp;

	ptemp=create_and_kill(PID_SHAKER,es_sub);

	ptemp->a11=(long)pixels;
	ptemp->a10=shake;

	return;
}

/******************************************************************************
 Function: void es_sub(void)

 By: David Schwartz

 Date: Nov 1994

 Parameters: None

 Returns: None

 Description:	shake the world (up/down) routine
******************************************************************************/
void es_sub(void)
{
	do
	{
		worldtly.u.intpos-=current_proc->a11;
		process_sleep(3);							// hey, check out the fault!!
		current_proc->a11=-current_proc->a11;
	}
	while(--current_proc->a10);

	process_suicide();
}

void fx_inviso_poof_noshake(void);

FUNC fx_table[]=
{
	sonya_proj_globs,	// 0
	trail_proc,			// 1
	floor_explode,		// 2
	freeze_blast,		// 3
	rocket_puff,		// 4
	dave_explode,		// 5
	scream_shaker,		// 6
	robo_dizzy_bolts,	// 7
	robo_tele_explode,	// 8
	robo_tele_implode,	// 9
	robo_bomb_explode,	// a
	fx_fight_intro,		// b
	robo_crunch_limbs,	// c
	fx_combo,			// d
	fx_comment,			// e
	jax_zap_puff,		// f
	lineup_explode,		// 10
	fx_finish_him,		// 11
	fx_finish_her,		// 12
	fx_charge_bars,		// 13
	smoke_a_guy,		// 14
	laser_explode,		// 15
	fatality_drip,		// 16
	fx_forden_a11,		// 17
	swat_bomb_explode,		// 18
	skinny_blood,		// 19
	pit_mulch,		// 1a
	sonya_animal_fx,		// 1b
	fx_animality,		// 1c
	fx_mercy,		// 1d
	fx_inviso_poof,		// 1e
	smoke_smoke,		// 1f
	stand_blood_explode,	// 20
	jax_stomp_explode,	// 21
	cyrax_fatal_explode,	// 22
	cyrax_cutup_blood,	// 23
	lao_nado_pieces,		// 24
	lia_spin_fx,		// 25
	inflate_boom,		// 26
	danger_danger,		// 27
	spike_blood_explode,	// 28
	subway_rox,		// 29
	fx_friendship,		// 2a
	fx_babality,		// 2b
	sonya_crush_explode,	// 2c
	sz_rips_guts,		// 2d
	cyrax_copter_guts,	// 2e
	spit_glob,			// 2f
	jade_smoke,			// 30
	mileena_bone,		// 31
	fx_throw_encouraged,// 32
	ex2on2_kombat_bang,	// 33
	fx_lava_dan,		// 34
	fx_ego_explode,		// 35		-u64-
	fx_smoke_lightning,	// 36
	fx_brutality,		// 37		
	fx_agressor_trail,	// 38
	fx_inviso_poof_noshake, 	//39
};

/******************************************************************************
 Function: PROCESS *create_fx(WORD fxnum)

 By: David Schwartz

 Date: Nov 1994

 Parameters: fxnum - effect to start

 Returns: None

 Description:	create a special effects process
******************************************************************************/
PROCESS *create_fx(WORD fxnum)
{
	PROCESS *ptemp;

	ptemp=CREATE(PID_FX,fx_table[fxnum]);
	ptemp->pdata.p_otherproc=current_proc->pdata.p_otherproc;
	ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	return(ptemp);
}

//******************************************************************************
//******************************************************************************
char txt_outstanding[]="OUTSTANDING THROW !";
char txt_superb[]="SUPERB THROW !";
char txt_excellent[]="EXCELLENT THROW !";
char txt_welldone[]="WELL DONE THROW !";
char txt_yes[]="YES !";

char *encourage_table[]=
{
	txt_outstanding,
	txt_superb,
	txt_excellent,
	txt_welldone,
	txt_yes,
};

BYTE encourage_table_fx[]=
{
	0x7e,			// outstanding
	0x74,			// suberb
	0x7c,			// excellent
	0x75,			// well done
	0x79			// laugh
};

void fx_throw_encouraged(void)
{
	char *pa8;
	OBJECT *oa6,*oa3,*oa5;

	current_proc->procid=PID_ENCOURAGE;
	process_sleep(0x45);

	current_proc->a0=randu(5)-1;
	pa8=encourage_table[current_proc->a0];
	tsound(encourage_table_fx[current_proc->a0]);

	oa6=objlst2;

	objlst2=NULL;
	pds_centered_soff(pa8,SCX(0xc8),SCY(0xed));
	oa3=objlst2;
	objlst2=oa6;
	oa6=oa3;

	/* give new text special id */
	do
	{
		oa3->oid=OID_ENCOURAGE;
		oa3->ozval=0x1000;
		oa5=oa3;
		oa3=oa3->olink;
	}
	while(oa3!=NULL);

	oa5->olink=objlst;
	objlst=oa6;
	process_sleep(0x40);

	dallobj(OID_ENCOURAGE);
	process_suicide();
}

//******************************************************************************
//******************************************************************************
void spit_glob(void)
{
	current_proc->a6=21;
	do
	{
		CREATE(PID_BLOOD_GLOB,glob_proc);
	}
	while(--current_proc->a6>0);

	process_suicide();
}

void glob_proc(void)
{
	OBJECT *obj=current_proc->pa8;

	gso_dmawnz(obj,(ADDRESS)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9)),obj->odict,obj->oheap,0);
	alloc_cache(COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9)),obj->oheap,obj);
	lineup_1pwm(obj,(OBJECT *)current_proc->a10);

	obj->oypos.u.intpos=ground_y-randu_minimum(SCY(0x30),SCY(0x40));
	insert_object(obj,&objlst);

	current_proc->pdata.p_ganiy=ground_y+randu(8);

	obj->oxvel.pos=srandarc(0xa0000);
	(ADDRESS *)current_proc->a6=NULL;
	gravity_ani(5,-((long)(randu_minimum(SCX(0x40000),SCX(0x60000)))),SCY(0x6000));

	find_part2();
	framew(5);
	delobjp(obj);
	process_suicide();
}

//******************************************************************************
//******************************************************************************
ADDRESS *mileena_bones_table[]=
{
	(ADDRESS *)a_arm2,
	(ADDRESS *)a_leg,
	(ADDRESS *)a_bone,
	(ADDRESS *)a_rib_cage,
	NULL
};

extern BYTE blood_dict[];
void mileena_bone(void)
{
	ADDRESS **ta11=mileena_bones_table;
	void *animframe;
	OBJECT *obj=current_proc->pa8;
	PROCESS *ptemp;

	current_proc->a10=(ADDRESS)current_proc->pa8;

	while(*ta11!=0)
	{
		animframe=*ta11;
		animframe=(void*)COMPUTE_ADDR(0,GET_LONG(animframe));	// get ptr to frame
		gso_dmawnz(obj,(ADDRESS)animframe,blood_dict,0,0);
		alloc_cache(animframe,0,obj);

		lineup_1pwm(obj,(OBJECT *)current_proc->a10);
		multi_adjust_xy(obj,-SCX(0x40),SCY(0x40));
		insert_object(obj,&objlst);
		ptemp=CREATE(PID_BLOOD,one_bone_proc);
		if (ptemp!=NULL)
			ptemp->pa9=*ta11;
		process_sleep(1);
		ta11++;
	}

	process_suicide();
}

void one_bone_proc(void)
{
	current_proc->pdata.p_ganiy=ground_y-randu(6)+6;

	/* fall down to ground */
	set_proj_vel(current_proc->pa8,-(SCX(0xa000)+randu(SCX(0x30000))),-1);

	single_flight(DONT_TOUCH,current_proc->pdata.p_ganiy,SCY(0x8000),2);

	/* bounce */
	set_proj_vel(current_proc->pa8,-(SCX(0x4000)+randu(0x30000)),-1);

	single_flight(DONT_TOUCH,-(SCY(0x8000)+randu(SCY(0x10000))),SCY(0x8000),2);

	single_flight(DONT_TOUCH,-(SCY(0x40000)+randu(SCY(0x40000))),SCY(0x8000),2);

	stop_a8(current_proc->pa8);
	
	process_suicide();
}

//******************************************************************************
//******************************************************************************
GEXPLODE ge_2on2[]=
{
	{1,SCX(0),SCY(0x20),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x200)&0xfffe)+1,SCX(0x0),SCY(0xb00),SCY(0x400),3,6},
	{2,SCX(0),SCY(0x20),SCY(0x4000),LEG01,a_leg,(SCX(0x200)&0xfffe)+1,SCX(0x0),SCY(0xb00),SCY(0x400),3,6},
	{2,SCX(0),SCY(0x40),SCY(0x4000),BONE01,a_bone,(SCX(0x400)&0xfffe)+1,SCX(0x0),SCY(0xa00),SCY(0x400),3,6},
	{1,SCX(0),SCY(0x40),SCY(0x4000),CAGE01,a_rib_cage,(SCX(0x200)&0xfffe)+1,SCX(0x0),SCY(0xb00),SCY(0x400),3,6},
	{1,SCX(0),SCY(0x40),SCY(0x4000),SKULL01,a_skull,(SCX(0x200)&0xfffe)+1,SCX(0x0),SCY(0xb00),SCY(0x400),3,6},
	{0}
};

void ex2on2_kombat_bang(void)
{
	OBJECT *obj=current_proc->pa8;
	LONG ta10=current_proc->a10;
	tsound(0);
	tsound(1);
	shake_a11(0xc,0x12);

	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_2on2,blood_dict);
	
	current_proc->pa8=obj;
	current_proc->a10=ta10;
	CREATE(PID_BLOOD,blood_explode);
	
	process_suicide();
}

/******************************************************************************
 Function: void cyrax_copter_guts(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	cyrax copter guts
******************************************************************************/
GEXPLODE ge_copter[]=
{
	{1,SCX(0),-SCY(0x10),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x800)&0xfffe)+1,SCX(0x100),SCY(0),SCY(0),3,3},
	{1,SCX(0),-SCY(0x10),SCY(0x4000),LEG01,a_leg,(SCX(0x800)&0xfffe)+1,SCX(0x100),SCY(0),SCY(0),3,3},
	{1,SCX(0),-SCY(0x10),SCY(0x4000),BONE01,a_bone,(SCX(0x800)&0xfffe)+1,SCX(0x100),SCY(0),SCY(0),3,3},
	{0}
};

void cyrax_copter_guts(void)
{
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_copter,blood_dict);
	process_suicide();
}

/******************************************************************************
 Function: void sz_rips_guts(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	subzero rips guts
******************************************************************************/
#if 0	//-SONY-
GSEXPLODE ge_sz_rip[]=
{
	{1,SCX(0),SCY(0x00),SCY(0x4000),ANIM_ARM2,(SCX(0x401)&0xfffe)+1,SCX(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),ANIM_LEG,(SCX(0x401)&0xfffe)+1,SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{5,SCX(0),SCY(0x00),SCY(0x4000),ANIM_BONE,(SCX(0x401)&0xfffe)+1,SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),ANIM_CAGE,(SCX(0x401)&0xfffe),SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),ANIM_SKULL,(SCX(0x401)&0xfffe),SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{0}
};
#endif

GEXPLODE ge_sz_rip[]=
{
	{1,SCX(0),SCY(0x00),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x401)&0xfffe)+1,SCX(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),LEG01,a_leg,(SCX(0x401)&0xfffe)+1,SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{5,SCX(0),SCY(0x00),SCY(0x4000),BONE01,a_bone,(SCX(0x401)&0xfffe)+1,SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),CAGE01,a_rib_cage,(SCX(0x401)&0xfffe),SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{1,SCX(0),SCY(0x00),SCY(0x4000),SKULL01,a_skull,(SCX(0x401)&0xfffe),SCY(0x00),SCY(0x200),SCY(0x200),3,3},
	{0}
};

void sz_rips_guts(void)
{
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_sz_rip,blood_dict);
	current_proc->pa8=(OBJECT*)current_proc->pa9;

	current_proc->a10=0;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x20;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0xffe0;
	CREATE(PID_BLOOD,blood_explode);
	process_suicide();
}

/******************************************************************************
 Function: void sonya_crush_explode(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:
******************************************************************************/
#if 0	//-SONY-
GSEXPLODE ge_krush[]=
{
	{1,SCX(0),SCY(0x90),SCY(0x4000),ANIM_ARM2,(SCX(0x101)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),ANIM_LEG,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{4,SCX(0),SCY(0x90),SCY(0x4000),ANIM_BONE,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),ANIM_CAGE,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),ANIM_SKULL,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{0}
};
#endif

GEXPLODE ge_krush[]=
{
	{1,SCX(0),SCY(0x90),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x101)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),LEG01,a_leg,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{4,SCX(0),SCY(0x90),SCY(0x4000),BONE01,a_bone,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),CAGE01,a_rib_cage,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x90),SCY(0x4000),SKULL01,a_skull,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x800),SCY(0x400),3,3},
	{0}
};

void sonya_crush_explode(void)
{
	CREATE(PID_BLOOD,stand_blood_explode);
	current_proc->pa9=(void *)current_proc->pa8;		// set to dude about to die
	special_gravity_explode(ge_krush,blood_dict);							// otherproc & otherguy should be pointing to SONYA or attacker
	process_suicide();
}

/******************************************************************************
 Function: void fx_babality(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:
******************************************************************************/
extern void *a_baby_text[];
void fx_babality(void)
{
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
		
	sound_music_start(MUSIC_BABALITY);			//send_code_a3(0x43);			//-MUSIC_IGNORE-
	
	special_fx_load(FX_BABY_LOAD);
	process_sleep(4);

	current_proc->a10=7;
	/* bab4 */
	do
	{
		CREATE(PID_FX,baby_letter);
	}
	while(--current_proc->a10>0);

	CREATE(PID_FX,baby_letter);
	process_sleep(0x60);
	tsound(0x65);				// speech babality

	spec_fx=FX_NO_LOAD;
	
	process_suicide();
}

extern BYTE baby_dict[];
void baby_letter(void)
{
	OBJECT *obj=current_proc->pa8;

	process_sleep(randu_minimum(0x10,0x10));

	(ADDRESS)current_proc->pa9=*(a_baby_text+current_proc->a10);				// get ptr to correct letter
	gso_dmawnz_ns(obj,(ADDRESS)current_proc->pa9,baby_dict,0,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,0,obj);

	obj->oxpos.u.intpos=current_proc->a10*SCX(0x26)+SCX(0x38);
	obj->oypos.u.intpos=-SCY(0x30);

	obj->ozval=(current_proc->a10==7)?0:current_proc->a10+500;
	insert_object(obj,&objlst);

	/* fall down */
	baby_fall(SCY(0x20000));
	baby_fall(-randu_minimum(SCY(0x20000),SCY(0x20000)));
	baby_fall(-randu_minimum(SCY(0x10000),SCY(0x10000)));
	process_suicide();
}

void baby_fall(long pa0)
{
	OBJECT *obj=current_proc->pa8;

	obj->oyvel.pos=pa0;
	process_sleep(2);
	/* babf4 */
	do
	{
		do
		{
			process_sleep(1);
			obj->oyvel.pos+=SCY(0x3000);
		}
		while(obj->oyvel.pos<0);

	}
	while(obj->oypos.u.intpos<SCY(0x4d)+8);

	obj->oypos.u.intpos=SCY(0x4d)+8;
	stop_a8(obj);

	return;
}

/******************************************************************************
 Function: void fx_friendship(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: current_proc->a11 - base heap ptr

 Returns: None

 Description:   show friendship message
******************************************************************************/
extern void *a_friend[];
extern void *a_ship[];
void fx_friendship(void)
{
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
	
	special_fx_load(FX_FRIEND_LOAD);

	CREATE(PID_FX,friendship_speech);
	CREATE(PID_FX,ship_proc);
	current_proc->pa9=a_friend;
	fani3(current_proc->pa9);
}

void ship_proc(void)
{
	current_proc->pa9=a_ship;
	fani3(current_proc->pa9);
}

extern BYTE friend_dict[];
void fani3(void *pa9)
{
	OBJECT *obj;

	current_proc->pa9=pa9;
	gmo_proc(friend_dict,0);

	obj=current_proc->pa8;
	set_noscroll(obj);
	obj->ozval=0x100;
	set_xy_coordinates(obj,SCX(0xc7),SCY(0x50)+4);
	insert_object(obj,&objlst);
	mframew(4);
	
	spec_fx=FX_NO_LOAD;
	
	process_suicide();
}

void friendship_speech(void)
{
	tsound(0x68);			// friendship
	process_sleep(0x40);
	tsound(0x69);			// friendship
	process_sleep(0x40);
	tsound(0x6a);			// friendship
	process_suicide();
}

/******************************************************************************
 Function: void subway_rox(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	Subway Rox
******************************************************************************/
void subway_rox(void)
{
	current_proc->a10=(ADDRESS)current_proc->pa8;
	tsound(0x00);				// eploxde floor
	tsound(0x01);				// eploxde floor

	shake_a11(0xa,0x10);
	
	do_rox(8,5,a_small_rock);
	do_rox(7,5,a_med_rock);
	do_rox(3,5,a_large_rock);

	process_suicide();
}

void do_rox(WORD pa0,WORD pa6,void *pa11)
{
	OBJECT *obj;
	PROCESS *ptemp;

	do
	{
		gso_dmawnz(obj,(ADDRESS)COMPUTE_ADDR(0,GET_LONG(pa11)),rock_dict,0,0);
		alloc_cache(COMPUTE_ADDR(0,GET_LONG(pa11)),0,obj);

		obj->oxpos.u.intpos=((OBJECT*)current_proc->a10)->oxpos.u.intpos;
		obj->oypos.u.intpos=((OBJECT*)current_proc->a10)->oypos.u.intpos;
		insert_object(obj,&objlst);
		ptemp=CREATE(PID_BLOOD,subway_rock_fall);
		if (ptemp!=NULL)
		{
			ptemp->pdata.p_store1=pa6;
			ptemp->pa9=pa11;
		}
	}
	while(--pa0>0);

	return;
}

void subway_rock_fall(void)
{
	process_sleep(randu(8));

	current_proc->pdata.p_ganiy=ground_y-randu_minimum(5,5)-SCY(0x10);

	(current_proc->pa8)->oxvel.pos=srandarc(SCX(0x20000));

	current_proc->a11=SCY(0x4000);
	gravity_a11();
	do_land_routine();
}

/******************************************************************************
 Function: void spike_blood_explode(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	spike blood exploding
******************************************************************************/
void spike_blood_explode(void)
{
	current_proc->a10=0x0070ffe0;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x0070fff0;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00700000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00700010;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00700020;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00700030;
	CREATE(PID_BLOOD,blood_explode);
	process_suicide();
}

/******************************************************************************
 Function: void inflate_boom(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	inflate boom the heads
******************************************************************************/
GEXPLODE  ge_laser[]=
{
 	{2,SCX(0),SCY(0x20),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xb00),SCY(0x400),3,3},
 	{2,SCX(0),SCY(0x20),SCY(0x4000),LEG01,a_leg,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xb00),SCY(0x400),3,3},
 	{7,SCX(0x0),SCY(0x40),SCY(0x4000),BONE01,a_bone,(SCX(0x401)&0xfffe)+1,SCX(0x00),SCY(0xa00),SCY(0x400),3,3},
	{1,SCX(0x0),SCY(0x40),SCY(0x4000),CAGE01,a_rib_cage,(SCX(0x201)&0xfffe),SCX(0x00),SCY(0xb00),SCY(0x400),3,3},
	{1,SCX(0x0),SCY(0x40),SCY(0x4000),SKULL01,a_skull,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xb00),SCY(0x400),3,3},
 	{0}
};


void inflate_boom(void)
{
	current_proc->pa9=(void*)current_proc->pa8;
	special_gravity_explode(ge_laser,blood_dict);
	current_proc->pa8=(OBJECT*)current_proc->pa9;

	shake_a11(0x6,0x10);
	tsound(0x0);
	tsound(0x1);
	white_flash();
	process_suicide();
}

/******************************************************************************
 Function: void lia_spin_fx(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	lia spin fatalaity
******************************************************************************/
GEXPLODE ge_hair[]=
{
	{1,SCX(0),SCY(0x20),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x601)&0xfffe)+1,SCX(0x400),SCY(0xa00),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x20),SCY(0x4000),LEG01,a_leg,(SCX(0x601)&0xfffe)+1,SCX(0x400),SCY(0xa00),SCY(0x400),3,3},
	{3,SCX(0),SCY(0x40),SCY(0x4000),BONE01,a_bone,(SCX(0x601)&0xfffe)+1,SCX(0x400),SCY(0xa00),SCY(0x400),3,3},
	{2,SCX(0),SCY(0x40),SCY(0x4000),PORK01,a_pork,(SCX(0x601)&0xfffe)+1,SCX(0x400),SCY(0xa00),SCY(0x400),3,3},
	{0}
};

void lia_spin_fx(void)
{
	PROCESS *ptemp;

	process_sleep(0x20);
	ptemp=CREATE(PID_BLOOD,hair_blood);
	if (ptemp!=NULL)
	{
		ptemp->pdata.p_otherproc=current_proc->pdata.p_otherproc;
		ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	}
	
	current_proc->a10=2;
	/* hspin3 */
	do
	{
		ptemp=CREATE(PID_BLOOD,hair_explode);
		if (ptemp!=NULL)
		{
			ptemp->pdata.p_otherproc=current_proc->pdata.p_otherproc;
			ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
		}
		
		process_sleep(20);
	}
	while(--current_proc->a10>0);

	process_suicide();
}

void hair_blood(void)
{
	hair3();
	process_sleep(20);
	hair3();
	process_sleep(20);
	tsound(0x24);
	tsound(0x25);
	process_suicide();
}

void hair3(void)
{
	PROCESS *ptemp;
	tsound(0x24);
	tsound(0x25);
	ptemp=CREATE(PID_BLOOD,nado_blood_explode);
	if (ptemp!=NULL)
	{
		ptemp->pdata.p_otherproc=current_proc->pdata.p_otherproc;
		ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	}
	return;
}

void hair_explode(void)
{
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_hair,blood_dict);
	process_suicide();
}

/******************************************************************************
 Function: void lao_nado_pieces(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	lao tornado
******************************************************************************/
GEXPLODE ge_nado[]=
{
	{1,SCX(0),SCY(0x20),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xa00),SCY(0x400),3,3},
	{1,SCX(0),SCY(0x20),SCY(0x4000),LEG01,a_leg,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xa00),SCY(0x400),3,3},
	{1,SCX(0x0),SCY(0x40),SCY(0x4000),BONE01,a_bone,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0xa00),SCY(0x400),3,3},
	{1,SCX(0x0),SCY(0x40),SCY(0x4000),PORK01,a_pork,(SCX(0x201)&0xfffe),SCX(0x00),SCY(0xa00),SCY(0x400),3,3},
	{0}
};

void lao_nado_pieces(void)
{
	OBJECT *obj=current_proc->pa8;
	nado_spawn();
	process_sleep(0x18);
	current_proc->pa8=obj;
	nado_spawn();
	process_suicide();
}

void nado_spawn(void)
{
	CREATE(PID_BLOOD,nado_blood_explode);
	nado_pieces();
	tsound(0x24);
	tsound(0x25);
	return;
}

void nado_blood_explode(void)
{
	current_proc->a10=0x00100000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00200000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00300000;
	CREATE(PID_BLOOD,blood_explode);
	process_suicide();
}

void nado_pieces(void)
{
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_nado,blood_dict);
	return;
}

/******************************************************************************
 Function: void cyrax_fatal_explode(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	cyrax exploding blood time
******************************************************************************/
void cyrax_fatal_explode(void)
{
	tsound(0);
	tsound(1);

	shake_a11(0xc,0x12);
	(OBJECT*)current_proc->pa9=current_proc->pa8;
	special_gravity_explode(ge_laser,blood_dict);

	(OBJECT*)current_proc->pa9=current_proc->pdata.p_otherguy;
	special_gravity_explode(ge_laser,blood_dict);

	current_proc->pa8=(OBJECT*)current_proc->pa9;
	current_proc->a10=0x00200000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10+=0x00200000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10+=0x00200000;
	CREATE(PID_BLOOD,blood_explode);
	white_flash();
	process_suicide();
}

void stand_blood_explode(void)
{
	current_proc->a10=0;
	cbx3();
}

void cbx3(void)
{
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10+=0x00180000;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10+=0x00180000;
	CREATE(PID_BLOOD,blood_explode);
	process_suicide();
}

void cyrax_cutup_blood(void)
{
	current_proc->a10=0x0000fff0;
	CREATE(PID_BLOOD,blood_explode);
	current_proc->a10=0x00000020;
	CREATE(PID_BLOOD,blood_explode);
	process_suicide();
}

void jax_stomp_explode(void)
{
	current_proc->a10=0x00700000;
	CREATE(PID_BLOOD,blood_explode);

	current_proc->a10=0x00700010;
	CREATE(PID_BLOOD,blood_explode);

	current_proc->a10=0x00700020;
	CREATE(PID_BLOOD,blood_explode);

	current_proc->a10=0x00700030;
	CREATE(PID_BLOOD,blood_explode);

	process_suicide();
}

/******************************************************************************
 Function: void fx_mercy(void)

 By: David Schwartz

 Date: May 1995

 Parameters: current_proc->a10 - character showing mercy

 Returns: None

 Description:	show mercy effect
******************************************************************************/
extern WORD *death_fade_excludes[];
extern BYTE mercy_dict[];
void fx_mercy(void)
{
	OBJECT *obj;
	
	current_proc->procid=PID_MERCY;

	CREATE(PID_MERCY,make_db_tone);
	CREATE(PID_FADE,mercy_fader);
	
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
		
	special_fx_load(FX_MERCY_LOAD);
	
	process_sleep(0x30);
	
	tsound(0x94);

	gso_dmawnz_ns_coor(obj,(ADDRESS)MERCY_01,mercy_dict,0,0,SCX(0),0xffd0);
	alloc_cache(MERCY_01,0,obj);
	center_obj_x(obj);
	insert_object(obj,&objlst);

	current_proc->pa9=a_mercy;
	framew(4);
	new_mercy_pal();
	framew(4);
	new_mercy_pal();
	framew(4);

	current_proc->p_comp_flag=999;				// big hack
	
	tsound2(0x40+current_proc->a10);			// announce merciful dude

	process_sleep(0x8);

	delobjp(obj);

	process_sleep(0x8);

	spec_fx=FX_NO_LOAD;
	
	play_background_tune();
	
	process_suicide();
}

void new_mercy_pal(void)
{
	OBJECT *obj=current_proc->pa8;
	OIMGTBL *animframe;

	animframe=(OIMGTBL *)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9));
	animframe++;
	swpal((void*)GET_LONG(animframe),obj);
	return;
}

extern void mercy_skydown(void);
void mercy_fader(void)
{
	void *pa9;

	dallprc(PID_CYCLE);

	pa9=current_proc->pa9;
	(LONG)current_proc->pa9=0x400;
	CREATE(PID_FADE,mercy_skydown);
	current_proc->pa9=pa9;
	fadeout_mercy(death_fade_excludes);

	process_suicide();
}

/******************************************************************************
 Function: void sonya_animal_fx(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	sonya animality fxs
******************************************************************************/
void sonya_animal_fx(void)
{
	current_proc->a10=2;
	/* sony3 */
	do
	{
		create_blood_proc(BLOOD_UPPERCUT);
	}
	while(--current_proc->a10>0);

	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_laser,blood_dict);

	process_suicide();
}

/******************************************************************************
 Function: void pit_mulch(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	pit mulching
******************************************************************************/
GEXPLODE ge_pit_mulch[]=
{
	{1,SCX(0),SCY(0x20),SCY(0x4000),ARM_B01,a_arm2,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x700),SCY(0x300),3,4},
	{1,SCX(0),SCY(0x20),SCY(0x4000),LEG01,a_leg,(SCX(0x201)&0xfffe)+1,SCX(0x00),SCY(0x700),SCY(0x300),3,4},
	{3,SCX(0x0),SCY(0x40),SCY(0x4000),BONE01,a_bone,(SCX(0x401)&0xfffe)+1,SCX(0x00),SCY(0x600),SCY(0x200),3,4},
	{2,SCX(0x0),SCY(0x40),SCY(0x4000),PORK01,a_pork,(SCX(0x401)&0xfffe)+1,SCX(0x00),SCY(0x600),SCY(0x200),3,4},
	{0}
};

void pit_mulch(void)
{
	shake_a11(0x6,0xa);

	CREATE(PID_FX,pit_mulch_burst);
	current_proc->a10=0x00400000;
	pit_blood_explode();
	current_proc->a10=0x00300030;
	pit_blood_explode();
	current_proc->a10=0x0020ffc0;
//	pit_blood_explode();
	process_sleep(19);

	CREATE(PID_FX,pit_mulch_burst);
	current_proc->a10=0x00400030;
	pit_blood_explode();
	current_proc->a10=0x00200000;
	pit_blood_explode();
	current_proc->a10=0x00300030;
//	pit_blood_explode();
	process_suicide();
}

void pit_blood_explode(void)
{
	CREATE(PID_FX,pit_blood_explode_proc);
	process_sleep(7);
	return;
}

extern BYTE pit_dict[];
void pit_blood_explode_proc(void)
{
	OBJECT *oa11=current_proc->pa8;
	OBJECT *obj;

	current_proc->pa9=a_blood_explode;
	gmo_proc(blood_dict,0);
	obj=current_proc->pa8;

	obj->oxpos.u.intpos=oa11->oxpos.u.intpos+(short)(current_proc->a10 & 0xffff);
	obj->oypos.u.intpos=oa11->oypos.u.intpos+(short)(((long)current_proc->a10)>>16 & 0xffff);
	obj->ozval=100;
	insert_object(obj,&objlst);

//***********************************
	if (oa11->ochar<=FT_SK)
		(WORD *)current_proc->a0=ochar_bloodxpd_palettes[oa11->ochar];
	else (WORD *)current_proc->a0=ochar_bloodxpd_palettes[0];

	if ((WORD *)current_proc->a0!=BLDXPD_P)
		swpal((void *)current_proc->a0,obj);			// not normal blood switch
//***********************************

	mframew(5);
	delobjp(obj);
	process_suicide();
}

void pit_mulch_burst(void)
{
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_pit_mulch,blood_dict);
	process_suicide();
}

/******************************************************************************
 Function: void skinny_blood(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: current_proc->a11 Y:X adjustment
 			 current_proc->pa8 obj to follow

 Returns: None

 Description:	skinny blood
******************************************************************************/
extern void *a_skinny_blood[];
void skinny_blood(void)
{
	OBJECT *obj;
	void *animframe;
	OBJECT *oa11=current_proc->pa8;

	current_proc->procid=PID_BLOOD;

	process_sleep(randu_minimum(0x8,0x10));

	current_proc->a10=(ADDRESS)current_proc->pa8;		// obj to follow
	current_proc->pa9=a_skinny_blood;

	animframe=(void*)COMPUTE_ADDR(0,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,blood_dict,0,0);
	alloc_cache((OIMGTBL *)animframe,0,obj);
	
	lineup_1pwm(obj,(OBJECT*)current_proc->a10);

	multi_adjust_xy(obj,current_proc->a11 & 0xffff,(((long)current_proc->a11)>>16));

	obj->ozval=100;
	insert_object(obj,&objlst);


//***********************************
	if (oa11->ochar<=FT_SK)
		(WORD *)current_proc->a0=ochar_blooddrip_palettes[oa11->ochar];
	else (WORD *)current_proc->a0=ochar_blooddrip_palettes[0];

	if ((WORD *)current_proc->a0!=SMDRIP_P)
		swpal((void *)current_proc->a0,obj);			// not normal blood switch
//***********************************

	framew(5);				// drip stretch
	init_anirate(6);
	obj->oyvel.pos=SCY(0x10000);

	/* skbl3 */
	do
	{
		process_sleep(1);
		next_anirate();

	obj->oyvel.pos+=SCY(0x6000);		// gravity
	}
	while((ground_y-10)>obj->oypos.u.intpos);

	find_part2();
	stop_a8(obj);
	framew(5);				// puddle
	process_suicide();
}

/******************************************************************************
 Function: void fatality_drip(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	show fatality has happened
******************************************************************************/
extern OIMGTBL FATALITY01;
extern void *a_fatality_drip[];
extern BYTE fatal_dict[];
void fatality_drip(void)
{
	OBJECT *obj=current_proc->pa8;

	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
		
	tsound(0x62);
	special_fx_load(FX_FATAL_LOAD);

	gso_dmawnz_ns_coor(obj,(ADDRESS)&FATALITY01,fatal_dict,0,0,SCX(0x0),SCY(0x50)+4);
	alloc_cache(&FATALITY01,0,obj);
	center_obj_x(obj);
	obj->ozval=1000;
	insert_object(obj,&objlst);

	current_proc->pa9=a_fatality_drip;
	framew(4);

	spec_fx=FX_NO_LOAD;
	
	process_suicide();
}

extern BYTE brutal_dict[];
extern void *a_brutality[];
void brutal_letter(void)
{
	OBJECT *obj=current_proc->pa8;
	LONG pa10=current_proc->a10;

	process_sleep((0x3*(current_proc->a10)+0x4));

	(ADDRESS)current_proc->pa9=*(a_brutality+current_proc->a10);				// get ptr to correct letter
	gso_dmawnz(obj,(ADDRESS)current_proc->pa9,brutal_dict,0,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,0,obj);

	obj->oxpos.u.intpos=51+((OIMGTBL *)current_proc->pa9)->anixoff+worldtlx.u.intpos;
	obj->oypos.u.intpos=SCY(0x56)+worldtly.u.intpos;

	obj->ozval=800;
	insert_object(obj,&objlst);

	if (pa10 & 1) 
	{
		current_proc->pa8=obj;
		create_blood_proc(BLOOD_UPPERCUT);
	}

	rsnd_med_smack();

	process_suicide();
}

void fx_brutality(void)
{
	OBJECT *obj=current_proc->pa8;

	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
		
	special_fx_load(FX_BRUTAL_LOAD);
	process_sleep(4);

	current_proc->a10=8;
	/* bab4 */
	do
	{
		CREATE(PID_FX,brutal_letter);
	}
	while(--current_proc->a10>0);

	CREATE(PID_FX,brutal_letter);
	process_sleep(0x60);
	tsound(0x96);				// speech babality

	spec_fx=FX_NO_LOAD;
	
	process_suicide();
}

/******************************************************************************
 Function: void fx_animality(void)

 By: David Schwartz

 Date: May 1995

 Parameters: current_proc->a11 - base heap ptr

 Returns: None

 Description:	show animality has happened
******************************************************************************/
extern OIMGTBL ANIMALITY01;
extern void *a_animality[];
extern BYTE animal_dict[];
void fx_animality(void)
{
	OBJECT *obj=current_proc->pa8;

	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);

	tsound(0x95);
	special_fx_load(FX_ANIMAL_LOAD);

	gso_dmawnz_ns_coor(obj,(ADDRESS)&ANIMALITY01,animal_dict,0,0,SCX(0x50),SCY(0x50)+4);
	alloc_cache((OIMGTBL *)&ANIMALITY01,0,obj);
	obj->ozval=100;
	insert_object(obj,&objlst);

	current_proc->pa9=a_animality;						// SONY PSX CD HEAP
	framew(4);

	process_sleep(0x2a);
	tsound(0x64);					// speech animality

	spec_fx=FX_NO_LOAD;
	
	process_suicide();
}

/******************************************************************************
 Function: void swat_bomb_explode(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	swat bomb explode
******************************************************************************/
void swat_bomb_explode(void)
{
	tsound(0);
	tsound(1);
	shake_a11(0x000c,0x0012);
	current_proc->pa9=(void *)current_proc->pa8;
	
	special_gravity_explode(ge_laser,blood_dict);
	
	current_proc->pa8=(OBJECT*)current_proc->pa9;
	stand_blood_explode();
}

/******************************************************************************
 Function: void laser_explode(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	laser explode
******************************************************************************/
void laser_explode(void)
{
	tsound(0x00);
	tsound(0x01);
	shake_a11(0x000c,0x0012);
	current_proc->pa9=(void *)current_proc->pa8;
	special_gravity_explode(ge_laser,blood_dict);
	current_proc->pa8=(OBJECT*)current_proc->pa9;
	process_sleep(2);
	white_flash();

	process_suicide();
}

/******************************************************************************
 Function: void smoke_smoke(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	add some smoke to smoke
******************************************************************************/
void smoke_smoke(void)
{
	current_proc->procid=PID_SMOKER;
	/* ssm1 */
	do
	{
		current_proc->a5=2;
		/* ssm3 */
		do
		{
			CREATE(PID_1_PUFF,smoke_smoke_1);
		}
		while(--current_proc->a5>0);

		/* ssm4 */
		do
		{
			process_sleep(9);
		}
		while(((current_proc->pa8)->ochar!=FT_OLDSMOKE  && (current_proc->pa8)->ochar!=FT_SMOKE) || (current_proc->pa8)->oflags2 & M_INVISO);
	}
	while(1);
}

void smoke_smoke_1(void)
{
	OBJECT *obj;

	obj=puff_init(FRONT_Z+1);

	multi_adjust_xy(obj,srandarc(SCX(0x18)),randu_minimum(SCY(0x40),SCY(0x20)));

	obj->oyvel.pos=-randu_minimum(SCY(0x30000),SCY(0x10000));
	obj->oxvel.pos=srandarc(SCX(0x18000));
	
	if (curback==BKGD_BRIDGE_MOD || curback==BKGD_STREET_MOD)
		obj->oxvel.pos+=0x20000;

	insert_object(obj,&objlst);
	stack_jump(puff_ani2);
}

void jade_smoke(void) 
{
	current_proc->procid=PID_SMOKER;
	current_proc->a10=6;
	do
	{
	 	current_proc->a5=4;
		do
		{
			CREATE(PID_1_PUFF,jade_puff);
			
		}
		while(--current_proc->a5>0);
		process_sleep(5);
	}
	while(--current_proc->a10>0);

	process_suicide();
}

void jade_puff(void) 
{
	puff_setup();
	current_proc->pa9=a_puff;
	framew(4);
	delobjp(current_proc->pa8);
	process_suicide();
}

/******************************************************************************
 Function: void smoke_a_guy(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: current_proc->a10 - # of puffs

 Returns: None

 Description:	smoke ring a guy
******************************************************************************/
void smoke_a_guy(void)
{
	while (1)
	{
		current_proc->procid=PID_SMOKER;

		current_proc->a5=current_proc->a10;
		/*sag4 */
		do
		{
			CREATE(PID_1_PUFF,smoke_a_1);
		}
		while(--current_proc->a5);
		process_sleep(4);
	}
}

void fx_smoke_lightning(void) 
{
	current_proc->procid=PID_SMOKER;
	current_proc->a10=3;
	do
	{
	 	current_proc->a5=2;
		do
		{
			CREATE(PID_1_PUFF,smoke_a_1);
			
		}
		while(--current_proc->a5>0);
		process_sleep(5);
	}
	while(--current_proc->a10>0);

	process_suicide();
}

void smoke_a_1(void)
{
	OBJECT *obj;

	puff_setup();

	obj=current_proc->pa8;
	obj->oyvel.pos=-randu_minimum(SCY(0x30000),SCY(0x10000));
	obj->oxvel.pos=srandarc(SCX(0x20000));

	stack_jump(puff_ani2);
}

void puff_ani2(void)
{
	current_proc->pa9=a_puff;
	framew(4);
	delobjp(current_proc->pa8);
	process_suicide();
}

void puff_setup(void) 
{
	OBJECT *obj;

	current_proc->pa8=obj=puff_init(FRONT_Z+1);

	multi_adjust_xy(obj,srandarc(SCX(0x20)),randu_minimum(SCY(0x70),0));

	insert_object(obj,&objlst);
	
	return;	
}
/******************************************************************************
 Function: void fx_combo(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	combo messages
******************************************************************************/
void fx_combo(void)
{
	OBJECT *ta8=current_proc->pa8;
	PROCESS *ta0;

	/* code to disable combos */
	if (f_no_combos)
		process_suicide();

	current_proc->pdata.p_store1=ta8->oid;			// player oid here!!

	dallprc(PID_COMBO_MSG);
	dallobj(OID_COMBO_MSG);
	current_proc->procid=PID_COMBO_MSG;			// there can only be one

	ta0=CREATE(PID_COMBO_MSG,hits_msg);
	ta0->pdata.p_store1=current_proc->pdata.p_store1;
	process_sleep(10);

	setup_combo_message(SCX(0),SCY(0x58)+16,damage_s,1,current_proc->a10);

	stack_jump(slide_combo_msg);
}

/******************************************************************************
 Function: void hits_msg(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	# of hits messages
******************************************************************************/
void hits_msg(void)
{
	setup_combo_message(SCX(0),SCY(0x48)+16,hits_s,7,current_proc->a11);

	if (current_proc->pdata.p_store1!=PID_P2)
	{
		(current_proc->pa8)->oxpos.u.intpos+=SCX(0x30);
		((OBJECT *)(current_proc->pa9))->oxpos.u.intpos+=SCX(0x30);

		if (current_proc->a10 != (ADDRESS)current_proc->pa9)
			((OBJECT *)(current_proc->a10))->oxpos.u.intpos+=SCX(0x30);
	}

	stack_jump(slide_combo_msg);
}

/******************************************************************************
 Function: void setup_combo_message(short pa4x,short pa4y,void *pa5,WORD pa6,WORD pa11)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa4x - x pos
			 pa4y - y pos
			 pa5 - frame image
			 pa6 - spacing
			 pa11 - number to display

 Returns: None

 Description:	setup message to display
******************************************************************************/
extern BYTE control_dict[];
void setup_combo_message(short pa4x,short pa4y,void *pa5,WORD pa6,WORD pa11)
{
	WORD ta3;
	OBJECT *obj;

	current_proc->a10=(ADDRESS)obj_free;				// in case our # is only 1 digit
	if (pa11>99)
		pa11=99;

	/* setc2 */
	ta3=pa11/10;			// compute tens digit
	if (ta3!=0)
	{
		(OBJECT*)current_proc->a10=a3_combo_number_obj(ta3,pa4x,pa4y,pa5);		// a10 = 1st digit
	}

	/* setc3 */
	ta3=pa11%10;			// compute ones digit
	(OBJECT*)current_proc->pa9=a3_combo_number_obj(ta3,pa4x,pa4y,pa5);		// a10 = 1st digit

	/* now do the "message" part */
	gso_dmawnz_ns_coor(obj,(ADDRESS)pa5,control_dict,0,0,pa4x,pa4y);
	alloc_cache(pa5,0,obj);
	
	/* arcade mod, need to remap palette for message from white_p to score_p */
	delpal(obj);
	obj->opal=get_fore_pal(SCORE_P);

	obj->oid=OID_COMBO_MSG;
	((OBJECT *)(current_proc->pa9))->oid=OID_COMBO_MSG;
	((OBJECT *)(current_proc->a10))->oid=OID_COMBO_MSG;

	current_proc->a3=SCX(0xf8000);				// text velocity

	/* place text outta sight */
	if (current_proc->pdata.p_store1!=PID_P2)
	{
		obj->oxpos.u.intpos=SCRRGT;
		(long)current_proc->a3=-((long)current_proc->a3);
	}
	else
	{
		obj->oxpos.u.intpos=-obj->osize.u.xpos;
	}

	/* fxcom3 */
	((OBJECT *)current_proc->pa9)->oxpos.u.intpos=obj->oxpos.u.intpos-((OBJECT *)current_proc->pa9)->osize.u.xpos-pa6;		// spacing for ones digit

	if (current_proc->a10!=(ADDRESS)current_proc->pa9)
		((OBJECT *)current_proc->a10)->oxpos.u.intpos=((OBJECT *)current_proc->pa9)->oxpos.u.intpos-((OBJECT *)current_proc->a10)->osize.u.xpos;		// spacing for ones digit

	/* fxcom5 */
	obj->oxvel.pos=(long)current_proc->a3;
	((OBJECT *)current_proc->pa9)->oxvel.pos=(long)current_proc->a3;
	((OBJECT *)current_proc->a10)->oxvel.pos=(long)current_proc->a3;

	(long)(obj->oslink)=(long)current_proc->a3;
	(long)(((OBJECT *)current_proc->pa9)->oslink)=(long)current_proc->a3;
	(long)(((OBJECT *)current_proc->a10)->oslink)=(long)current_proc->a3;

	insert_object(obj,&objlst);
	insert_object((OBJECT *)current_proc->pa9,&objlst);

	if ((ADDRESS)current_proc->pa9!=current_proc->a10)
		insert_object((OBJECT *)current_proc->a10,&objlst);

	/* fxcom6 */
	return;
}

/******************************************************************************
 Function: OBJECT *a3_combo_number_obj(WORD pa3,short pa4x,short pa4y)

 By: David Schwartz

 Date: Mar 1995

 Parameters: pa3 - digit to dispaly
 			 pa4x - x pos
			 pa4y - y pos
			 pa5 - frame

 Returns: obj - ptr to new object (current_proc->pa8 also set)

 Description:	create digit for combo message
******************************************************************************/
extern BYTE font_dict[];
OBJECT *a3_combo_number_obj(WORD pa3,short pa4x,short pa4y,void *pa5)
{
	OIMGTBL *fptr;
	OBJECT *obj;
	OBJECT *strptr;

	gso_dmawnz_ns_coor(obj,(ADDRESS)pa5,font_dict,0,0,pa4x,pa4y);		// setup object & paleet

	/* setup small number object */
	fptr=*(font_lists[FONT_7]+(WORD)'0'+(WORD)pa3-0x21);
	obj->osag=fptr;
	obj->oimg=(LONG)fptr;	//-u64-
	
	/* load correct number */
  	strptr=current_proc->pa8;				//-u64-
  	current_proc->pa8=obj;							//-u64-
  	animate(SINGLE_ANI0,fptr,obj->oflags);			//-u64-
  	current_proc->pa8=strptr;						//-u64-

	return(obj);
}

/******************************************************************************
 Function: void slide_combo_msg(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	slide in combo message
******************************************************************************/
void slide_combo_msg(void)
{
	OBJECT *ta8,*ta9,*ta10;

	ta8=current_proc->pa8;
	ta9=(OBJECT*)current_proc->pa9;
	ta10=(OBJECT*)current_proc->a10;

	current_proc->a11=0x1f;
	do
	{
		process_sleep(1);
		ta8->oxvel.pos-=((ta8->oxvel.pos)>>3);
		ta9->oxvel.pos=ta10->oxvel.pos=ta8->oxvel.pos;		// damping to look cool
	}
	while(--current_proc->a11>0);

	process_sleep(2);

	ta8->oxvel.pos=ta9->oxvel.pos=ta10->oxvel.pos=0;

	process_sleep(0x4b);

	ta8->oxvel.pos=-((long)ta8->oslink);
	ta9->oxvel.pos=ta10->oxvel.pos=ta8->oxvel.pos;		// leave screen vel

	process_sleep(10);

	delobjp(ta8);
	delobjp(ta9);
	if (ta9!=ta10)
		delobjp(ta10);

	process_suicide();
}

/******************************************************************************
 Function: void fx_charge_bars(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	charge power bars
******************************************************************************/
void fx_charge_bars(void)
{
	current_proc->procid=PID_FX_CHARGE;

	p1_bar=p2_bar=0xffff;			// neg bar = flag: dont mess with bars

	p1_bar_view=p2_bar_view=0;

	current_proc->a10=FULL_STRENGTH;
	current_proc->a11=FULL_STRENGTH;

	(LONG)current_proc->pa8=4;
	/* gxcb5 */
	do
	{
		charge_stuff();
		process_sleep(1);
		((LONG)current_proc->pa8)+=2;
	}
	while(((LONG)current_proc->pa8)<FULL_STRENGTH);

	charge_stuff();

	process_suicide();
}

/******************************************************************************
 Function: void charge_stuff(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: current_proc->pa8 - charge value
			 current_proc->a10 - p1 max
			 current_proc->a11 - p2 max

 Returns: None

 Description:	charge powerbars to full
******************************************************************************/
void charge_stuff(void)
{
	if (((LONG)current_proc->pa8)<current_proc->a10)
	{
		p1_bar_view=(LONG)current_proc->pa8;
		p1_bar=(LONG)current_proc->pa8;
	}
	else
	{
		p1_bar_view=current_proc->a10;
		p1_bar=current_proc->a10;
	}

	if (((LONG)current_proc->pa8)<current_proc->a11)
	{
		p2_bar_view=(LONG)current_proc->pa8;
		p2_bar=(LONG)current_proc->pa8;
	}
	else
	{
		p2_bar_view=current_proc->a11;
		p2_bar=current_proc->a11;
	}

	return;
}

BYTE comment_table[]=			// default
{
	0x0b,		// Crowd "Oooo"
	0x74,		// superb
	0x75,		// well done
	0x79,		// laugh 1
	0x7a,		// laugh 2
	0x7b		// laugh 3
};

/******************************************************************************
 Function: void fx_comment(void)

 By: David Schwartz

 Date: Mar 1995

 Parameters: None

 Returns: None

 Description:	comment on stuff
******************************************************************************/
void fx_comment(void)
{
	if (p1_char==FT_SK||p2_char==FT_SK)
		process_suicide();

	if (p1_char==FT_MOTARO||p2_char==FT_MOTARO)
		process_suicide();

	dallprc(PID_COMMENT);			// there can only be one
	current_proc->procid=PID_COMMENT;

	process_sleep(0x13);

	if (randper((curback==BKGD_MK2PITSTAR_MOD)?0xa0:0x40)==SYSTEM_CARRY_SET)
		forden_peek(0x1b);		// sound: toasty
	else tsound(comment_table[randu(6)-1]);

	process_suicide();
}

/******************************************************************************
 Function: void fx_forden_a11(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	forden face sound
******************************************************************************/
void fx_forden_a11(void)
{
	if (gstate==GS_AMODE)
		process_suicide();

	process_sleep(0x13);

	forden_peek(current_proc->a11);
}

void forden_peek(WORD pa11)
{
	if (gstate==GS_AMODE)
		process_suicide();

	if (p1_bar==0 || p2_bar==0)			// round over: no toasty
		process_suicide();

	if (pa11==0x1b)			// if its toasty then do this
		toasty_tick=tick;	// record time
		
	current_proc->a11=pa11;
	stack_jump(fx_lava_dan);
}
	
void fx_lava_dan(void)
{
	OBJECT *obj;

	(ADDRESS)current_proc->pa9=current_proc->a11;
	current_proc->procid=PID_FORDEN;
	gso_dmawnz_ns(obj,(ADDRESS)TOASTY,control_dict,0,0);
	alloc_cache(TOASTY,0,obj);
	set_xy_coordinates(obj,SCX(0x158)+8,(0xa0)+12);
	obj->ozval=100;
	insert_object(obj,&objlst2);

	obj->oxvel.pos=-SCX(0x80000);
	current_proc->a11=0x6;
	/* ford3 */
	do
	{
		process_sleep(1);
	}
	while(--current_proc->a11>0);

	stop_a8(obj);
	tsound((LONG)current_proc->pa9);

	process_sleep(0x20);
	obj->oxvel.pos=SCX(0x80000);

	current_proc->a11=0x10;
	/* ford5 */
	do
	{
		process_sleep(1);
	}
	while(--current_proc->a11>0);

	delobjp2(obj);
	process_suicide();
}

/******************************************************************************
 Function: void fx_fight_intro(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	fight intro stuff
******************************************************************************/
void fx_fight_intro(void)
{
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);

	special_fx_load(FX_FIGHT_LOAD);
	grow_in_spin_out(0x00,&FINFITE1,a_fight_out,fight_dict);
	
	spec_fx=FX_NO_LOAD;
	process_suicide();
}

/******************************************************************************
 Function: void fx_finish_him(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	finish him time
******************************************************************************/
void fx_finish_him(void)
{
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
	special_fx_load(FX_FINHIM_LOAD);
	grow_in_spin_out(0x15,&FINHIM1,a_finhim_out,finhim_dict);
	
	spec_fx=FX_NO_LOAD;
	process_suicide();
}

/******************************************************************************
 Function: void fx_finish_her(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	finish her time
******************************************************************************/
void fx_finish_her(void)
{
	while (spec_fx!=FX_NO_LOAD)
		process_sleep(1);
	special_fx_load(FX_FINHER_LOAD);
	grow_in_spin_out(0x16,&FINHER1,a_finher_out,finher_dict);
	
	spec_fx=FX_NO_LOAD;
	process_suicide();
}

/******************************************************************************
 Function: void grow_in_spin_out(WORD pa0,OIMGTBL *pa5,void *pa9,BYTE *dict)

 By: David Schwartz

 Date: Feb 1995

 Parameters: pa0 - speech #
			 pa5 - first frame of graphics to display
			 pa9 - animation to run

 Returns: None

 Description:	grow in special messages
******************************************************************************/
void grow_in_spin_out(WORD pa0,OIMGTBL *pa5,void *pa9,BYTE *dict)
{
	OBJECT *obj;
	XYTYPE ta9;

	current_proc->procid=PID_GROW;

	current_proc->a11=(long)((pa5->size.u.xpos)<<8);			// shift for the formula
	current_proc->a10=(long)((pa5->size.u.ypos)<<8);			// shift for the formula

	gso_dmawnz_ns(obj,(ADDRESS)pa5,dict,0,0);
	alloc_cache((void *)pa5,0,obj);

	obj->oypos.u.intpos=SCY(0x48);
	center_obj_x(obj);
	ta9.yx=0x03000300;
	obj->oscale.yx=ta9.yx;					// start off real small
	insert_object(obj,&objlst);

	if (pa0!=0)
		tsound(pa0);

	/* grow3, grow loop */
	do
	{
		obj->oscale.yx=ta9.yx;
		center_scale(obj,ta9.yx);
		process_sleep(1);

		ta9.u.xpos-=0x0020;
		ta9.u.ypos-=0x0020;
	}
	while(ta9.yx!=0x01000100);			// full size

	ta9.yx=6;
	/* grow5 */
	do
	{
		swpal(FITEYEL_P,obj);
		process_sleep(4);
		swpal(MKFIGHT_P,obj);
		process_sleep(4);				// flash yellow and red
	}
	while(--ta9.yx>0);

	f_sync=1;								// quee event

	current_proc->pa9=pa9;
	framew(3);

	delobjp(obj);

	spec_fx=FX_NO_LOAD;
	process_suicide();
}

/******************************************************************************
 Function: void center_scale(OBJECT *obj,long pa9)

 By: David Schwartz

 Date: Feb 1995

 Parameters: current_proc->a11 - x image size
			 current_proc->a10 - y image size
			 pa9 - scale size
			 obj - object

 Returns: None

 Description:	scale message
******************************************************************************/
void center_scale(OBJECT *obj,long pa9)
{
	short ta3;

	ta3=pa9&0xffff;				// look at x
	ta3=((long)current_proc->a11)/ta3;
	obj->oxpos.u.intpos=(SCRRGT/2)-(ta3>>1);			// center image on the screen


	ta3=pa9>>16;				// look at y
	ta3=((long)current_proc->a10)/ta3;
	obj->oypos.u.intpos=(SCRBOT/2)-SCY(0x30)-(ta3>>1);			// center image on the screen

	return;
}

/******************************************************************************
 Function: void fx_inviso_poof(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	go inviso
******************************************************************************/
void fx_inviso_poof(void) 
{
	shake_a11(8,8);
	stack_jump(fx_inviso_poof_noshake);
}

void fx_inviso_poof_noshake(void)
{
	PROCESS *ptemp;
	OBJECT *obj;
	short ypos;

	current_proc->procid=PID_POOF;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	current_proc->pa9=a_ground_explode;

	ptemp=gmo_proc(explode_dict,0);
	obj=current_proc->pa8;
	obj->oplink=ptemp;
	a8_front_plus_1(obj);

	match_ani_points((OBJECT *)current_proc->a10,obj);
	switch (((OBJECT*)current_proc->a10)->ochar)
	{
		case FT_MOTARO:
		case FT_SK:
			ypos=SCY(0xb0);
			break;
		case FT_REPTILE:
		case FT_SCORPION:
		case FT_ERMAC:
		case FT_OLDSZ:
		case FT_OLDSMOKE:
		case FT_NOOB:
		case FT_RAIN:
			ypos=SCY(0x86);
			break;
		default:
			ypos=SCY(0x90);
			break;
	}
	multi_adjust_xy(obj,SCX(0),ypos);
	
	obj->oflags|=M_XLU_ON;
	obj->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu
	
	insert_object(obj,&objlst);

	mframew(3);
	delete_proj_and_die(obj);
}

/******************************************************************************
 Function: void robo_bomb_explode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	robot bomb explode apart
******************************************************************************/
void robo_bomb_explode(void)
{
	OBJECT *obj;
	PROCESS *ptemp;

	current_proc->procid=PID_GRAVP;			// id = gravity piece

	shake_a11(0x0008,0x0008);

	(OBJECT *)current_proc->a10=current_proc->pa8;

	current_proc->pa9=a_ground_explode;
	ptemp=gmo_proc(explode_dict,0);

	obj=current_proc->pa8;
	(PROCESS *)obj->oplink=ptemp;

	a8_front_plus_1(obj);

	(OBJECT *)current_proc->a11=obj;
	match_ani_points((OBJECT *)current_proc->a10,obj);

	multi_adjust_xy(obj,SCX(0x00),SCY(0x0a));

	insert_object(obj,&objlst);

	obj->oflags|=M_XLU_ON;
	obj->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu

	mframew(4);

	delete_proj_and_die(obj);
}

/******************************************************************************
 Function: void robo_tele_explode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	robot tele explode apart
******************************************************************************/
void robo_tele_explode(void)
{
	(OBJECT *)current_proc->a10=current_proc->pa8;

	shake_a11(0x0008,0x0008);
	ochar_sound(0xd);

	get_explode_obj();

	/* rplode3 */
	mframew(4);

	delete_proj_and_die(current_proc->pa8);
}

/******************************************************************************
 Function: void robo_tele_implode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	robot tele implode apart
******************************************************************************/
void robo_tele_implode(void)
{
	(OBJECT *)current_proc->a10=current_proc->pa8;

	ochar_sound(0x0e);

	get_explode_obj();
	find_part2();

	/* rplode3 */
	mframew(2);

	delete_proj_and_die(current_proc->pa8);

}

/******************************************************************************
 Function: void get_explode_obj(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	get explosion object
******************************************************************************/
void get_explode_obj(void)
{
	PROCESS *ptemp;
	OBJECT *obj;

	current_proc->procid=PID_EXPLODE;

	current_proc->pa9=a_dave_explode;
	ptemp=gmo_proc(explode_dict,0);
	obj=current_proc->pa8;
	obj->oheap=0;
	(PROCESS *)obj->oplink=ptemp;

	a8_back_minus_1(obj);

	(OBJECT *)current_proc->a11=obj;
	match_ani_points((OBJECT *)current_proc->a10,obj);

	multi_adjust_xy(obj,SCX(0x00),SCY(0x30));

	insert_object(obj,&objlst);

	obj->oflags|=M_XLU_ON;
	obj->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu

	return;
}

short puff_placements[][2]=
{
	{SCX(0x00),SCY(0x18)},			// 12
	{-SCX(0x08),SCY(0x10)}, 		// 1
	{-SCX(0x10),SCY(0x08)}, 		// 2
	{-SCX(0x18)+24,SCY(0x00)},		// 3
	{SCX(0x00),-SCY(0x18)},		// 4
	{-SCX(0x08),-SCY(0x10)},		// 5
	{-SCX(0x10),-SCY(0x08)},		// 6
	{-SCX(0x18)+24,SCY(0x00)},		// 7
	{SCX(0x00),SCY(00)}			// 8
};

/******************************************************************************
 Function: void jax_zap_puff(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	jax zap puff smoke routine
******************************************************************************/
void jax_zap_puff(void)
{
	OBJECT *obj;

	obj=puff_init(FRONT_Z+1);

	multi_adjust_xy(obj,SCX(0x30),SCY(0x40));	//+16

	/* puff ani */
	insert_object(obj,&objlst);

	current_proc->pa9=a_puff;
	framew(4);

	delobjp(obj);

	process_suicide();
}

/******************************************************************************
 Function: void rocket_puff(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	rocket puff smoke routine
******************************************************************************/
void rocket_puff(void)
{
	OBJECT *obj;

	obj=puff_init(0);

	multi_adjust_xy(obj,puff_placements[current_proc->a11][0]-24,puff_placements[current_proc->a11][1]);

	obj->ozval=0;				// behind players

	/* puff ani */
	insert_object(obj,&objlst);

	current_proc->pa9=a_puff;
	framew(4);

	delobjp(obj);

	process_suicide();
}

/******************************************************************************
 Function: OBJECT *puff_init(WORD zval)

 By: David Schwartz

 Date: Jan 1995

 Parameters: zval - z value

 Returns: ptr to created object

 Description:	init puff routine
******************************************************************************/
OBJECT *puff_init(WORD zval)
{
	OBJECT *obj;

	current_proc->procid=PID_1_PUFF;

	(OBJECT *)current_proc->a10=current_proc->pa8;			// a10 = rocket to follow

	gso_dmawnz(obj,(ADDRESS)PUFF1,explode_dict,0,0);
	alloc_cache((OIMGTBL*)PUFF1,0,obj);
	obj->ozval=zval;
	obj->oid=OID_1_PUFF;

	lineup_1pwm(obj,(OBJECT *)current_proc->a10);

	/* xlu on smoke */
	obj->oflags|=M_XLU_ON;
	obj->oflags|=HALF_XLU;
	
	return(obj);
}

/******************************************************************************
 Function: void robo_dizzy_bolts(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	create robot dizzy sparks
******************************************************************************/
void robo_dizzy_bolts(void)
{
	PROCESS *ptemp;
	short loop;

	current_proc->procid=PID_BOLT;

	(OBJECT *)current_proc->a10=current_proc->pa8;

	/* rdb4 */
	loop=6;
	do
	{
		ptemp=CREATE(PID_BOLT,one_dizzy_bolt);
		ptemp->pdata.p_store1=current_proc->pdata.p_store1;
		ptemp->a11=loop;
	}
	while(--loop>0);

	current_proc->pa8=(OBJECT *)current_proc->a10;

	/* rdb5 */
	while (TRUE)
	{
		ochar_sound(randu_minimum(3,0xf));
		process_sleep(randu_minimum(10,18));

		if (is_robo_still_dizzy()==SYSTEM_CARRY_CLR)
			robo_dizzy_abort();
	}
}

short bolt_offsets[][2] =
{
	{SCX(0),SCY(0x20)},
	{SCX(0),SCY(0x40)},
	{SCX(-0x0d),SCY(0x70)},
	{SCX(-0x10),SCY(0x90)},
	{SCX(-0x08),SCY(0x60)},
	{SCX(0x10),SCY(0x60)}
};

/******************************************************************************
 Function: void one_dizzy_bolt(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	dizzy sparks process
******************************************************************************/
void one_dizzy_bolt(void)
{
	OBJECT *obj;
	WORD ta7;

	process_sleep(randu(30));		// random wait

	if (is_robo_still_dizzy()==SYSTEM_CARRY_CLR)
		robo_dizzy_abort();

	ta7=(current_proc->pa8)->ochar;

	get_char_ani(ANIM_TABLE2,ANIM_ROBO_BOLT);

	gso_dmawnz(obj,(ADDRESS)(COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9))),(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
 	alloc_cache((OIMGTBL *)(COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9))),obj->oheap,obj);
	obj->oid=OID_BOLT;

	obj->ochar=ta7;

	a8_front_plus_1(obj);

	insert_object(obj,&objlst);

	do
	{
		ta7=(WORD)current_proc->a11-1;

		lineup_1pwm(obj,(OBJECT *)current_proc->a10);

		multi_adjust_xy(obj,bolt_offsets[ta7][0],bolt_offsets[ta7][1]);

		get_char_ani(ANIM_TABLE2,ANIM_ROBO_BOLT);

		framew(2+randu(4));

		obj->oypos.u.intpos=0xf00;		// off screen

		process_sleep(0x10+randu(30));
	}
	while(((PROCESS *)(current_proc->pdata.p_store1))->p_comp_flag==PC_DIZZY);

	delobjp(obj);

	process_suicide();
}

void robo_dizzy_abort(void)
{
	dallprc(PID_BOLT);
	dallobj(OID_BOLT);
	process_suicide();
}

WORD is_robo_still_dizzy(void)
{
	PROCESS *pa0;

	pa0=(PROCESS *)current_proc->pdata.p_store1;
	if (pa0->p_comp_flag==PC_DIZZY)
		return(SYSTEM_CARRY_SET);
	else
	{
		return(SYSTEM_CARRY_CLR);
	}
}

/******************************************************************************
 Function: void lineup_explode(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: current_proc->a10 = starting y:x
			 current_proc->a1 = adjust y:x

 Returns: None

 Description:	lineup and explode routine
******************************************************************************/
void lineup_explode(void)
{
	PROCESS *ptemp;
	OBJECT *obj;

	current_proc->procid=PID_EXPLODE;

	current_proc->pa9=a_dave_explode;
	ptemp=gmo_proc(explode_dict,0);
	obj=current_proc->pa8;

	(PROCESS *)obj->oplink=ptemp;

	a8_front_plus_1(obj);

	set_xy_coordinates(obj,(current_proc->a10 & 0xffff),(((long)current_proc->a10)>>16));

	multi_adjust_xy(obj,(current_proc->a11 & 0xffff),(((long)current_proc->a11)>>16));

	insert_object(obj,&objlst);

	obj->oflags|=M_XLU_ON;
	obj->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu

	mframew(4);

	delete_proj_and_die(obj);
}

/******************************************************************************
 Function: void dave_explode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	neat explosion routine
******************************************************************************/
void dave_explode(void)
{
	PROCESS *ptemp;
	OBJECT *obj;

	current_proc->procid=PID_EXPLODE;

	current_proc->pa9=a_dave_explode;
	ptemp=gmo_proc(explode_dict,0);
	obj=current_proc->pa8;
	obj->oheap=0;

	(PROCESS *)obj->oplink=ptemp;

	obj->ozval=FRONT_Z+1;			// in front of player

	obj->oxpos.u.intpos=(short)current_proc->a10;
	obj->oypos.u.intpos=(short)current_proc->a11;

	obj->oflags|=M_XLU_ON;
	obj->oflags|=THREE_QUARTER_XLU;		// 1/2 xlu

	insert_object(obj,&objlst);

	mframew(4);

	delete_proj_and_die(obj);
}

/******************************************************************************
 Function: void sonya_proj_globs(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	create globs on projectile hit
******************************************************************************/
void sonya_proj_globs(void)
{
	int loop;

	for (loop=0;loop<GLOB_AWAY_CNT;loop++)
		CREATE(PID_BLOOD_GLOB,glob_away);

	for (loop=0;loop<GLOB_TOWARD_CNT;loop++)
		CREATE(PID_BLOOD_GLOB,glob_toward);

	process_suicide();
}

/******************************************************************************
 Function: void glob_toward(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup and run a glob towards instance
******************************************************************************/
void glob_toward(void)
{
	get_glob_and_vel;
	(current_proc->pa8)->oxvel.pos=-(current_proc->pa8)->oxvel.pos;		// the otherway dummy
	current_proc->a10=(long)(randu(SCY(0x3000)) + SCY(0x6000));			// gravity
	current_proc->a0=8;
	glob_fly();
}

/******************************************************************************
 Function: void glob_away(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	setup and run a glob away instance
******************************************************************************/
void glob_away(void)
{
	get_glob_and_vel;
	current_proc->a10=(long)(randu(SCY(0x3000)) + SCY(0x6000));			// gravity
	current_proc->a0=8;
	glob_fly();
}

/******************************************************************************
 Function: void glob_fly(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: current_proc->a0 - anim speed
			 current_proc->a1 - init y vel
			 current_proc->pa9 - anim table
			 current_proc->a10 - gravity

 Returns: None

 Description:	fly a glob to its death
******************************************************************************/
void glob_fly(void)
{
	OBJECT *obj=current_proc->pa8;
	WORD flip;

	flip=M_FLIPH;				// assume we want it to flip
	if (obj->oxvel.pos<0)
		flip=0;

	/* gfly1 */
	if ((obj->oflags & M_FLIPH)==flip)
		flip_single(obj);			// point in correct direction

	/* gfly2 */
	(ADDRESS *)current_proc->a6=NULL;
	gravity_ani((WORD)current_proc->a0,(long)current_proc->a1,(long)current_proc->a10);

	find_ani_part_a14(ANIM_ZAP,4);

	framew(4);				// splash on ground

	delobjp(obj);

	process_suicide();
}

/******************************************************************************
 Function: void get_glob_obj(long xvel_range,long xvel_add,long yvel_range,long yvel_add)
								(a0)		  (a1)	  		  (a2)			  (a3)
 By: David Schwartz

 Date: Dec 1994

 Parameters: self explainitory

 Returns: None

 Description:	init a flying glob object
******************************************************************************/
void get_glob_obj(long xvel_range,long xvel_add,long yvel_range,long yvel_add)
{
	OBJECT *obj;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	find_ani_part_a14(ANIM_ZAP,3);

	gso_dmawnz(obj,GET_LONG(current_proc->pa9),(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);

	obj->ochar=((OBJECT *)(current_proc->a10))->ochar;		// pass sonya id

	((ADDRESS *)current_proc->pa9)++;

	lineup_1pwm(obj,(OBJECT *)current_proc->a10);

	multi_adjust_xy(obj,SCX(0x80),SCY(0x40));
	insert_object(obj,&objlst);

	current_proc->a0=(long)(randu(xvel_range)+xvel_add);		// x velocity

	set_proj_vel(obj,(long)current_proc->a0,(WORD)xvel_add);

	current_proc->pdata.p_ganiy=ground_y;			// set the ground

	current_proc->a1=-((long)(randu(yvel_range)+yvel_add));		// y velocity
	
	return;
}

/******************************************************************************
 Function: void trail_proc(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	process to make a trial of images
******************************************************************************/
extern WORD ind_shadowr_p[];
extern WORD JCGSHAD_P[];
extern WORD LKYELO_P[];
extern WORD JCRSHAD_P[];
void trail_proc(void)
{
	short loop;
	PROCESS *ptemp;
	OBJECT *oa11;				// a11
	OBJECT *oa7;				// a7
	int indspeed;

	indspeed=current_proc->a11;
	
	(OBJECT *)current_proc->a11=oa11=current_proc->pa8;
	
	
	if (oa11->oid==OID_P1) 
	{
		if (p_agressor_active[0]==AGRESS_WAIT)
			process_suicide();
	}
	else
	{
		if (p_agressor_active[1]==AGRESS_WAIT)
			process_suicide();
	}
	
	dallprc(get_trail_pid(oa11));
	current_proc->procid=get_trail_pid(oa11);		// only 1 trail proc allowed per player

	dallobj(get_shadow_oid(oa11));				// kill prev shadow

	current_proc->pdata.p_store1=0;

	(OBJECT *)current_proc->pdata.p_store2=obj_free;	// save first object

	/* trail5 */
	oa7=NULL;

	loop=(oa11->ochar==FT_LK)?12:5;
	do
	{
		current_proc->a0=oa11->ochar;
		current_proc->pa8=oa11;
		get_char_ani(ANIM_TABLE1,ANIM_STANCE);
		
		while (GET_LONG(current_proc->pa9)==ANI_OCHAR_JUMP)
			((ADDRESS *)current_proc->pa9)+=3;
	
		current_proc->a5=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));

		get_multi_obj((ADDRESS *)current_proc->a5,sk_shadow_p,oa11->odict,oa11->oheap,PFLAG_PALLOAD);

		(current_proc->pa8)->oid=get_shadow_oid(oa11);

		animate2(current_proc->pa8,oa11->oshape);

		match_ani_points(oa11,current_proc->pa8);

		if (oa7!=NULL)
			(OBJECT *)oa7->oplink=current_proc->pa8;

		/* trail6 */
		if (oa11->ochar==FT_SK)
		{
			swpal(sk_shadow_p,current_proc->pa8);
		}

		if (oa11->ochar==FT_NOOB)
		{
			swpal(noob_p,current_proc->pa8);
		}

		if (oa11->ochar==FT_INDIAN)
		{
			if (indspeed==0)
				swpal(ind_shadow_p,current_proc->pa8);	
			else swpal(ind_shadowr_p,current_proc->pa8);	
		}

		if (oa11->ochar==FT_JCAGE)
		{
			if (indspeed==0)
				swpal(JCGSHAD_P,current_proc->pa8);	
			else swpal(JCRSHAD_P,current_proc->pa8);	
		}
		
		if (oa11->ochar==FT_LK) 
		{
			if (oa11->oid==OID_P2 && (p1_obj->ochar==p2_obj->ochar || (p2_proc->pdata.p_flags & PM_SHANG)))
				swpal(LKYELO_P,current_proc->pa8);
		}
		
		current_proc->pdata.p_store1++;
		(current_proc->pa8)->ozval=current_proc->pdata.p_store1;

		/* xlu trail */
		(current_proc->pa8)->oflags|=M_XLU_ON;
		
		if (oa11->ochar==FT_LK)
			(current_proc->pa8)->oflags|=HALF_XLU;
		else (current_proc->pa8)->oflags|=HALF_XLU+(((HALF_XLU>>8)/loop-(HALF_XLU>>8)/8)<<8);
		
		insert_object(current_proc->pa8,&objlst);

		process_sleep((oa11->ochar==FT_LK)?6:4);

		oa7=current_proc->pa8;				// prev shad obj

		if (oa11->oxvel.pos==0)
			break;						// stop moving, time to erase

	}
	while(--loop>0);

	(current_proc->pa8)->oplink=NULL;		// terminate list

	/* erase trail */

	/* trail7 */
	oa11=(OBJECT *)current_proc->pdata.p_store2;

	/* trail8 */
	do
	{
		(OBJECT *)current_proc->a10=(OBJECT *)oa11->oplink;
		delobjp(oa11);
		process_sleep(2);
	}
	while((oa11=(OBJECT *)current_proc->a10)!=NULL);


	process_suicide();
}


WORD get_trail_pid(OBJECT *pa11)
{
	if (pa11->oid==OID_P1)
		return(PID_TRAIL1);
	else return(PID_TRAIL2);
}

WORD get_shadow_oid(OBJECT *pa11)
{
	if (pa11->oid==OID_P1)
		return(OID_SHADOW1);
	else return(OID_SHADOW2);
}
/******************************************************************************
******************************************************************************/

GEXPLODE ge_floor[]=
{
	{7,0x0000,0x0020,SCY(0x4000),SMALL01,a_small_rock,(SCX(0x0200)&0xfffe)+1,SCX(0x0000),SCY(0x0d00),SCY(0x0600),3,0},
	{9,0x0000,0x0020,SCY(0x4000),MEDIUM01,a_med_rock,(SCX(0x0200)&0xfffe)+1,SCX(0x0100),SCY(0x0600),SCY(0x0400),3,1},
	{3,0x0000,0x0020,SCY(0x4000),LARGE01,a_large_rock,(SCX(0x0200)&0xfffe)+1,SCX(0x0000),SCY(0x0c00),SCY(0x0600),3,2},
	{0}
};

/******************************************************************************
 Function: void floor_explode(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	player explode through floor special effects
******************************************************************************/
void floor_explode(void)
{
	tsound(0);					// explode through floor sound
	tsound(1);					// explode through floor sound

	create_and_kill(PID_SHAKER,blast_shaker);
	
	gravity_explode(ge_floor,rock_dict,0);

	process_suicide();
}

/******************************************************************************
 Function: void gravity_explode(GEXPLODE *gtbl,void *heap)

 By: David Schwartz

 Date: Jan 1995

 Parameters: gtbl - pointer to a list of animation to start

 Returns: None

 Description:	init a object to animate via gravity and then explode
******************************************************************************/
void gravity_explode(GEXPLODE *gtbl,BYTE *dict,void *heap)
{
	short xpos,ypos,loop;
	OBJECT *obj=(OBJECT *)(current_proc->pa9);

	while ((loop=gtbl->g_cnt)!=0)				// a10
	{
		xpos=obj->oxpos.u.intpos+gtbl->g_x;		// x coord
		ypos=obj->oypos.u.intpos+gtbl->g_y;		// y coord

		do
		{
			spawn_1_piece(gtbl,xpos,ypos,0,dict,heap);

			if (gtbl->g_xvrange & 1)
				spawn_1_piece(gtbl,xpos,ypos,1,dict,heap);		// do a flipped version
		}
		while(--loop>0);

		gtbl++;									// next entry
	}
	return;
}

/******************************************************************************
 Function: void spawn_1_piece(GEXPLODE *gtbl,short xpos,short ypos,WORD flip,BYTE *dict,heap)

 By: David Schwartz

 Date: Jan 1995

 Parameters: gtbl - pointer to a list of animation to start
			 xpos - start x pos
			 ypos - start y pos
			 flip - flip flag
			 heap - ptr to base of anims

 Returns: None

 Description:	spawn an object
******************************************************************************/
void spawn_1_piece(GEXPLODE *gtbl,short xpos,short ypos,WORD flip,BYTE *dict,void *heap)
{
	OBJECT *obj;
	PROCESS *ptemp;
	long min,range;

	ptemp=CREATE(PID_GRAVP,gravity_piece);
	if (ptemp==NULL)
		return;

	gso_dmawnz(obj,(ADDRESS)gtbl->g_simg,dict,heap,0);
 	alloc_cache(gtbl->g_simg,heap,obj);
	ptemp->pa8=obj;

	min=(gtbl->g_xvmin)<<7;
	range=(gtbl->g_xvrange & 0xfffe)<<8;				// rid "do a flip bit"

	min+=randu(range);

	obj->oxvel.pos=(flip==0)? min :-min;

	/* spawn2 */
	min=(gtbl->g_yvmin)<<7;
	range=(gtbl->g_yvrange)<<8;

	min+=randu(range);
	obj->oyvel.pos=-min;						// y = upwards

	obj->oxpos.u.intpos=xpos;
	obj->oypos.u.intpos=ypos;					// set start coord

	ptemp->pdata.p_store1=gtbl->g_land;			// land routine

	ptemp->pa9=gtbl->g_anim;
	(WORD)ptemp->a10=gtbl->g_aspeed;
	(long)ptemp->a11=gtbl->g_grav;

	insert_object(obj,&objlst);

	return;
}

JUMPTBL land_routines[] =
{
	land_small_rock,
	land_med_rock,
	land_large_rock,
	land_body_part,
	land_pit_bottom,
	land_subway_rock,
	land_ex2on2
};

/******************************************************************************
 Function: void gravity_piece(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: current_proc->a10 = anim speed
			 current_proc->a11 = gravity
			 current_proc->pa9 = animation table

 Returns: None

 Description:	Generic proc to control an exploding gravity piece
******************************************************************************/
void gravity_piece(void)
{
	current_proc->pdata.p_ganiy=ground_y;			// set our ground

	init_anirate((WORD)current_proc->a10);
	gravity_a11();

	do_land_routine();
}

void do_land_routine(void)
{
	stack_jump(land_routines[current_proc->pdata.p_store1]);
}


/******************************************************************************
 Function: void gravity_a11(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: current_proc->a11 = gravity
			 current_proc->pa9 = animation table

 Returns: None

 Description:	common gravity routine,
******************************************************************************/
void gravity_a11(void)
{
	OBJECT *obj=current_proc->pa8;

	/* ga11 */
	do
	{
		process_sleep(1);

		next_anirate();

		obj->oyvel.pos+=(long)current_proc->a11;		// simulate gravity

	} while (obj->oyvel.pos<0 || hit_ground_yet(obj)==SYSTEM_CARRY_CLR);

	return;
}

/******************************************************************************
 Function: void blast_shaker(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	shake the world vertically
******************************************************************************/
void blast_shaker(void)
{
	short loop,offset;

	loop=10;
	offset=6;
	do
	{
		worldtly.u.intpos-=offset;
		worldtly_t.u.intpos-=offset;
		process_sleep(3);
		offset=-offset;
	}
	while(--loop>0);

	process_suicide();
}

/******************************************************************************
 Function: void land_small_rock(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	land a small rock
******************************************************************************/
void land_small_rock(void)
{
	rock_bounce(SCY(0x40000),SCY(0x40000));

	/* med_rock_bounce */
	rock_bounce(SCY(0x30000),SCY(0x30000));

	rock_crumble();
}

/******************************************************************************
 Function: void rock_crumble(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	crumble rocks
******************************************************************************/
void rock_crumble(void)
{
	/* rock_crumble */
	stop_a8(current_proc->pa8);

	rsnd_rocks();

	current_proc->pa9=a_crumple;

	framew(3);					// crumple to nothing

	delobjp(current_proc->pa8);

	process_suicide();
}

/******************************************************************************
 Function: void land_large_rock(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	land a large rock
******************************************************************************/
void land_large_rock(void)
{
	rock_bounce(SCX(0x40000),SCY(0x40000));

	/* split in 3 */
	(OBJECT *)current_proc->a10=current_proc->pa8;
	spit_in_half();
	spit_in_half();
	current_proc->pa8=(OBJECT *)current_proc->a10;

	split_bounce();
}

/******************************************************************************
 Function: void split_bounce(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	split and bounce routine for rocks
******************************************************************************/
void split_bounce(void)
{
	/* split_bounce */
	rock_bounce(SCX(0x40000),SCY(0x40000));

	rock_crumble();
}

/******************************************************************************
 Function: void spit_in_half(void)

 By: David Schwartz

 Date: Feb 1995

 Parameters: None

 Returns: None

 Description:	split a large rock in half
******************************************************************************/
void spit_in_half(void)
{
	PROCESS *ptemp;
	OBJECT *obj;

	ptemp=CREATE(PID_ROCK,split_bounce);
	if (ptemp==NULL)
		return;

	gso_dmawnz(obj,(ADDRESS)MEDIUM01,rock_dict,0,0);

	obj->oxpos.u.intpos=((OBJECT *)current_proc->a10)->oxpos.u.intpos;
	obj->oypos.u.intpos=((OBJECT *)current_proc->a10)->oypos.u.intpos;
	insert_object(obj,&objlst);

	ptemp->pdata.p_ganiy=current_proc->pdata.p_ganiy;
	ptemp->pa9=a_med_rock;
	ptemp->pa8=obj;
}

void land_subway_rock(void)
{
	rock_bounce_nosound(SCY(0x20000),SCY(0x20000));
	stop_a8(current_proc->pa8);
	
	current_proc->pa9=a_crumple;
	
	framew(3);
	delobjp(current_proc->pa8);
	process_suicide();
}

/******************************************************************************
 Function: void rock_bounce(long min,long range)

 By: David Schwartz

 Date: Jan 1995

 Parameters: min - min y vel
			 range - range y vel

 Returns: None

 Description:	bounce a rock
******************************************************************************/
void rock_bounce(long min,long range)
{
	rsnd_rocks();
	single_flight(DONT_TOUCH,-(randu_minimum((min>>1),range)),(0x4000),2);
	(current_proc->pa8)->oyvel.pos=0;				// stop y only
	return;
}

/******************************************************************************
 Function: void rock_bounce_nosound(long min,long range)

 By: David Schwartz

 Date: Jan 1995

 Parameters: min - min y vel
			 range - range y vel

 Returns: None

 Description:	bounce a rock without sound
******************************************************************************/
void rock_bounce_nosound(long min,long range)
{
	single_flight(DONT_TOUCH,-(randu_minimum((min>>1),range)),(0x4000),2);
	(current_proc->pa8)->oyvel.pos=0;				// stop y only
	return;
}

/******************************************************************************
 Function: void land_body_part(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	body part land bounce routine
******************************************************************************/
void land_body_part(void)
{
//	rsnd_splish();

	single_flight(DONT_TOUCH,-randu_minimum(SCY(0x40000),SCY(0x40000)),0x4000,2);
	stop_a8(current_proc->pa8);
	tsound(0x18);
	process_suicide();
}

void land_pit_bottom(void)
{
	OBJECT *obj=current_proc->pa8;
	stop_a8(obj);
	obj->oyvel.pos=SCY(0x18000);
	shake_a8_up(obj,4,0,3,4);
	delobjp(obj);
	process_suicide();
}

void land_ex2on2(void) 
{
	rsnd_splish();
	single_flight(DONT_TOUCH,-randu_minimum(SCY(0x40000),SCY(0x40000)),0x4000,2);
	delobjp(current_proc->pa8);
	process_suicide();
}

/******************************************************************************
 Function: void single_flight(long xvel,long yvel,long grav,WORD anis)
						   (a0)        (a1)         (a2)      (a3)
 By: David Schwartz

 Date: Jan 1995

 Parameters: xvel - x velocity (16.0)
			 yvel - y velocity (16.0)
			 grav - gravity (16.0)
			 anis - animation speed

 Returns: None

 Description:	fly a rock
******************************************************************************/
void single_flight(long xvel,long yvel,long grav,WORD anis)
{
	OBJECT *obj=current_proc->pa8;
	short temp;

	if (xvel!=DONT_TOUCH)
		obj->oxvel.pos=xvel;

	if (yvel!=DONT_TOUCH)
		obj->oyvel.pos=yvel;

	init_anirate(anis);

	(long)current_proc->a11=grav;

	if ((long)current_proc->pa9>0)
		get_char_ani(ANIM_TABLE1,(LONG)current_proc->pa9);

	temp=current_proc->pdata.p_ganiy+obj->osize.u.ypos;

	if (obj->oypos.u.intpos>temp)
		obj->oypos.u.intpos=temp;

	gravity_a11();

	return;
}

/******************************************************************************
 Function: void scream_shaker(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	lia scream shaker effect
******************************************************************************/
void scream_shaker(void)
{
	short offset=6;

	do
	{
		worldtly.u.intpos-=offset;
		offset=-offset;
		process_sleep(3);
	}
	while(((PROCESS *)(current_proc->a10))->p_comp_flag==PC_SCREAM_WAKE);			// mod from orig code needed flag, since address comp wouldn't work

	process_suicide();

}

/******************************************************************************
 Function: void white_flash_proc(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	white flash screen effect proc
******************************************************************************/
void white_flash_proc(void)
{
	white_flash();
	process_suicide();
}

/******************************************************************************
 Function: void white_flash(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	white flash screen effect
******************************************************************************/
void white_flash(void)
{
	WORD ta9;

	ta9=irqskye;
	irqskye=0xffff;
	f_white=1;
	process_sleep(6);
	irqskye=ta9;
	f_white=0;
	return;
}

/******************************************************************************
 Function: void freeze_blast(void)

 By: David Schwartz

 Date: Jan 1995

 Parameters: None

 Returns: None

 Description:	subzero freeze blast effect
******************************************************************************/
void freeze_blast(void)
{
	OBJECT *obj=current_proc->pa8;
	void *heap_temp;
	PROCESS *ptemp;

	XYTYPE tl_dim,lr_dim;
	short xcenter,ycenter;
	
	current_proc->procid=PID_FBLAST;

	/* grab dims of decoy obj */
	tl_dim.u.xpos=leftmost_mpart(obj);
	tl_dim.u.ypos=highest_mpart(obj);
	lr_dim.u.xpos=rightmost_mpart(obj);
	lr_dim.u.ypos=lowest_mpart(obj);

	xcenter=tl_dim.u.xpos+abs(tl_dim.u.xpos-lr_dim.u.xpos)/2;
	ycenter=tl_dim.u.ypos+abs(tl_dim.u.ypos-lr_dim.u.ypos)/2;		// center of dude

	(OBJECT *)current_proc->a11=obj;		// a11 = decoy obj

	/* BUG FIX, heap ptr gets screwed up */
	current_proc->a6=obj->ochar;			// save ochar
	heap_temp=obj->oheap;					// save heap
	if ( p1_heap_char==FT_OLDSZ)
		obj->oheap=(BYTE *)p1_heap+256;
	else obj->oheap=(BYTE *)p2_heap+256;

	obj->ochar=FT_OLDSZ;					// animation found in subzero tables
	get_char_ani(ANIM_TABLE2,ANIM_OSZ_FREEZE_BLAST);
	obj->ochar=current_proc->a6;			// restore ochar

	ptemp=gmo_proc(((BYTE *)obj->oheap)-256,obj->oheap);
	obj->oheap=heap_temp;					// restore heap to orig obj

	obj=current_proc->pa8;					// new a8
	(PROCESS *)(obj->oplink)=ptemp;
	obj->ochar=FT_OLDSZ;					// animation found in subzero tables

	obj->oxpos.u.intpos=xcenter;
	obj->oypos.u.intpos=ycenter;			// center blast
	obj->ozval=FRONT_Z+2;					// set in front of players
	insert_object(obj,&objlst);

	get_char_ani(ANIM_TABLE2,ANIM_OSZ_FREEZE_BLAST);
	mframew(3);

	delete_proj_and_die(obj);
}

/******************************************************************************
 Function: void blood_explode(void)

 By: David Schwartz

 Date: May 1995

 Parameters: current_proc->a10 - pos offset

 Returns: None

 Description:	explode some blood from person
******************************************************************************/
extern BYTE blood_dict[];
void blood_explode(void)
{
	OBJECT *oa11=current_proc->pa8;
	OBJECT *obj;
	OBJECT *oa8;

	current_proc->pa9=a_blood_explode;
	gmo_proc(blood_dict,0);
	
	obj=current_proc->pa8;

	obj->oxpos.u.intpos=oa11->oxpos.u.intpos+(short)(current_proc->a10 & 0xffff);
	obj->oypos.u.intpos=oa11->oypos.u.intpos+(short)(((long)current_proc->a10)>>16 & 0xffff);
	obj->ozval=100;
	insert_object(obj,&objlst);
	
//***********************************
	if (oa11->ochar<=FT_SK)
		(WORD *)current_proc->a0=ochar_bloodxpd_palettes[oa11->ochar];
	else (WORD *)current_proc->a0=ochar_bloodxpd_palettes[0];

	if ((WORD *)current_proc->a0!=BLDXPD_P)
		swpal((void *)current_proc->a0,obj);			// not normal blood switch
//***********************************

	mframew(5);
	delobjp(obj);
	process_suicide();
}

/******************************************************************************
 Function: void danger_danger(void)

 By: David Schwartz

 Date: May 1995

 Parameters: current_proc->a11 - player to die

 Returns: None

 Description:	warn of impending death!
******************************************************************************/
void danger_danger(void)
{
	OBJECT *obj;

	if (gstate==GS_AMODE)
		process_suicide();

	gso_dmawnz_ns(obj,(ADDRESS)DANGER,control_dict,0,0);
	alloc_cache(DANGER,0,obj);

	if (current_proc->a11==1)
	{
		/* p1 in danger */
		(current_proc->pa8)->oid=PID_DANGER1;
		current_proc->procid=PID_DANGER1;
		set_xy_coordinates(current_proc->pa8,SCX(0x92),SCY(0x27)+16);
	}
	else
	{
		/* p2 in danger */
		(current_proc->pa8)->oid=PID_DANGER2;
		current_proc->procid=PID_DANGER2;
		set_xy_coordinates(current_proc->pa8,SCX(0xd7),SCY(0x27)+16);

	}

	insert_object(current_proc->pa8,&objlst);
	tsound(0x71);

	current_proc->a10=12;
	/* ddd6 */
	do
	{
		danger_y_adjust(-0x80);
		danger_y_adjust(0x80);
	}
	while(--current_proc->a10>0);

	delobjp(current_proc->pa8);

	process_suicide();
}

void danger_y_adjust(short pa1)
{
	OBJECT *obj=current_proc->pa8;

	obj->oypos.u.intpos+=pa1;
	process_sleep(0x6);
	return;
}


typedef struct rlb
{
	short r_anim;
	short r_x;
	short r_y;
	short r_flip;
} RLB	;

RLB robo_limb_spots[]=
{
	{0,SCX(0x50),SCY(0x28),0},
	{1,SCX(0x70),SCY(0x28),0},
	{2,SCX(0x90),SCY(0x28),1},
	{3,SCX(0xb0),SCY(0x28),1},

	{4,SCX(0xc0),SCY(0x28),1},
	{4,SCX(0xc0),SCY(0x28),1},
	{4,SCX(0xc0),SCY(0x28),0},
	{4,SCX(0xc0),SCY(0x28),0},

	{5,SCX(0xd0),SCY(0x28),1},
	{5,SCX(0xd0),SCY(0x28),1},
	{5,SCX(0xd0),SCY(0x28),1},

	{5,SCX(0x50),SCY(0x28),1},
	{5,SCX(0x60),SCY(0x28),0},
	{5,SCX(0x70),SCY(0x28),1},

	{6,SCX(0x80),SCY(0x28),1},
	{7,SCX(0x70),SCY(0x28),1},
	{-1}
};

void robo_crunch_limbs(void)
{
	RLB *ta11;
	OBJECT *obj;

	shake_a11(9,9);

	current_proc->a10=(ADDRESS)current_proc->pa8;
	ta11=robo_limb_spots;

	/* rcl3 */
	do
	{
		if (ta11->r_anim==-1)
			break;

		obj=get_a_limb(ta11->r_anim);
		match_ani_points((OBJECT *)current_proc->a10,obj);
		multi_adjust_xy(obj,ta11->r_x,ta11->r_y);

		if ( ta11->r_flip)
			CREATE(PID_BLOOD,squeeze_out_left);
		else CREATE(PID_BLOOD,squeeze_out_right);

		ta11++;
	} while ( 1 );

	process_suicide();
}

void squeeze_out_right(void)
{
	sol4(randu_minimum(SCX(0x10000),SCX(0x10000)));
}

void squeeze_out_left(void)
{
	sol4(-randu_minimum(SCX(0x10000),SCX(0x10000)));
}

void sol4(long pa0)
{
	set_proj_vel(current_proc->pa8,pa0,3);
	current_proc->pdata.p_store1=3;

	(long)current_proc->a11=randu_minimum(SCY(0x4000),SCY(0x2000));

	current_proc->pdata.p_ganiy=ground_y-(current_proc->pa8)->osize.u.ypos+SCY(0x20);

	init_anirate(3);
	gravity_a11();
	half_x_vel(current_proc->pa8);

	gravity_a11_yvel(current_proc->pa8,-SCY(0x30000));

	if ( random()<0 )
		gravity_a11_yvel(current_proc->pa8,-SCY(0x20000));

	/* sol7 */
	stop_a8(current_proc->pa8);

	process_suicide();
}

void *limb_table[]=
{
	a_arm,
	a_arm2,
	a_leg,
	a_leg2,
	a_limb,
	a_bone,
	a_rib_cage,
	a_skull,
	a_goro_arm
};

OBJECT *get_a_limb(WORD pa0)
{
	void *animframe;
	OBJECT *obj;

	current_proc->pa9=animframe=limb_table[pa0];
	animframe=(void*)COMPUTE_ADDR(0,GET_LONG(animframe));
	gso_dmawnz(obj,(ADDRESS)animframe,blood_dict,0,0);
	alloc_cache((OIMGTBL *)animframe,0,obj);
	
	obj->ozval=FRONT_Z+2;
	insert_object(obj,&objlst);

	return(obj);
}

/******************************************************************************
 Function: void fx_ego_explode

 By: David Schwartz

 Date: Mar 1996

 Parameters: None

 Returns: None

 Description:	create ego exploding effect
******************************************************************************/
void fx_ego_explode(void)
{
	int loop;

	shake_a11(0xa,0xa);
	
	for (loop=0;loop<36;loop++)		//-u64a-
	{
		CREATE(PID_BLOOD_GLOB,ego_fly)->a10=loop;
	}

	process_suicide();
}

void ego_fly(void)
{
	OBJECT *obj;
	WORD flip;


	get_ego_and_vel();
	
	obj=current_proc->pa8;

	flip=M_FLIPH;				// assume we want it to flip
	if (obj->oxvel.pos<0)
		flip=0;

	/* egofly1 */
	if ((obj->oflags & M_FLIPH)==flip)
		flip_single(obj);			// point in correct direction

	/* egofly2 */
	do
	{
		process_sleep(1);
		
		next_anirate();
	}
	while(proj_onscreen_test(obj)==SYSTEM_CARRY_SET && (obj->oypos.u.intpos-worldtly.u.intpos)>0 && (obj->oypos.u.intpos-worldtly.u.intpos)<SCRBOT+50); //-u64a-
	

	delobjp(obj);
	process_suicide();
}

float circle[][2]= 
{
	{1.0,0.0},
	{0.96592582,0.25881904},
	{0.866025,0.5},
	{0.7071067,0.7071067},
	{0.5,0.866025},
	{0.2588190,0.96592582},
	{0,1},
	{-0.2588190,0.96592582},
	{-0.5,0.866025},
	{-0.7071067,0.7071067},
	{-0.866025,0.5},
	{-0.96592582,0.25881904},
	{-1.0,0.0},
	{-0.96592582,-0.25881904},
	{-0.866025,-0.5},
	{-0.7071067,-0.7071067},
	{-0.5,-0.866025},
	{-0.2588190,-0.96592582},
	{0,-1},
	{0.2588190,-0.96592582},
	{0.5,-0.866025},
	{0.7071067,-0.7071067},
	{0.866025,-0.5},
	{0.96592582,-0.25881904},
	{1.0,0.0},
};

void get_ego_and_vel(void)
{
	OBJECT *obj;
	WORD index;
	long x,y;
	
	index=current_proc->a10;

	current_proc->a10=(ADDRESS)current_proc->pa8;

	get_char_ani(ANIM_TABLE2,ANIM_REP_SPITG);

	gso_dmawnz(obj,GET_LONG(current_proc->pa9),(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache(COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9)),obj->oheap,obj);
	swpal((void*)SHADOW_P,obj);

	obj->ochar=((OBJECT *)(current_proc->a10))->ochar;		// pass noob id

	lineup_1pwm(obj,(OBJECT *)current_proc->a10);


	insert_object(obj,&objlst);
	
	x=(long)randu_minimum(0x40000,0x60000);
	x=(long)((float) x * circle[index %24][0]);

	obj->oxvel.pos=x;

	current_proc->pdata.p_ganiy=ground_y+90;			// set the ground	-u64a-


	y=(long)(randu_minimum(SCY(0x40000),SCY(0x60000)));
	y=(long)((float)y * circle[index %24][1]);

	obj->oyvel.pos=current_proc->a1=y;

	return;
}


/******************************************************************************
 Function: void trail_proc(void)

 By: David Schwartz

 Date: Dec 1994

 Parameters: None

 Returns: None

 Description:	process to make a trial of images
******************************************************************************/
WORD get_trail_action(OBJECT *pa11)
{
	if (pa11->oid==OID_P1)
		return(p1_proc->pdata.p_action);
	else return(p2_proc->pdata.p_action);
}

void fx_agressor_trail(void)
{
	OBJECT *oa11;				// a11
	OBJECT *oa7;				// a7
	OBJECT *obj;
	int player=current_proc->a11;
	void *heap,*theap;
	BYTE *dict;
	WORD pal;
	
	heap=(current_proc->pa8)->oheap;
	dict=(current_proc->pa8)->odict;
	pal=(current_proc->pa8)->opal;
	
	(OBJECT *)current_proc->a11=oa11=current_proc->pa8;
	dallprc(get_trail_pid(oa11));
	current_proc->procid=get_trail_pid(oa11);		// only 1 trail proc allowed per player

	dallobj(get_shadow_oid(oa11));				// kill prev shadow

	current_proc->pdata.p_store1=0;
	
	(OBJECT *)current_proc->pdata.p_store2=NULL;	// save first object

	/* trail5 */
	oa7=NULL; 
	
	while (p_agressor_active[player]==AGRESS_WAIT)
	{
		/* create shadows */
		if (get_trail_action(oa11)!=ACT_BLURRED)
		{
			/* if dudes is moving create shadow object */
			current_proc->a0=oa11->ochar;
			
			theap=oa11->oheap;
			oa11->oheap=heap;
			current_proc->pa8=oa11;
			get_char_ani(ANIM_TABLE1,ANIM_STANCE);
			oa11->oheap=theap;
		
			while (GET_LONG(current_proc->pa9)==ANI_OCHAR_JUMP)
				((ADDRESS *)current_proc->pa9)+=3;
	
			current_proc->a5=(ADDRESS)COMPUTE_ADDR(heap,GET_LONG(current_proc->pa9));

			get_multi_obj((ADDRESS *)current_proc->a5,sk_shadow_p,dict,heap,PFLAG_PALLOAD);

			if ((OBJECT*)current_proc->pdata.p_store2==NULL)
				(OBJECT *)current_proc->pdata.p_store2=current_proc->pa8;
				
			(current_proc->pa8)->oid=get_shadow_oid(oa11);
			
			copy_pal(current_proc->pa8,pal);

			animate2(current_proc->pa8,oa11->oshape);

			match_ani_points(oa11,current_proc->pa8);

			if (oa7!=NULL)
				(OBJECT *)oa7->oplink=current_proc->pa8;

			/* trail6 */
			current_proc->pdata.p_store1++;
			(current_proc->pa8)->ozval=current_proc->pdata.p_store1;

			/* xlu trail */
			(current_proc->pa8)->oflags|=M_XLU_ON;
			(current_proc->pa8)->oflags|=HALF_XLU;
	    	//(current_proc->pa8)->oflags|=HALF_XLU+(((HALF_XLU>>8)/loop-(HALF_XLU>>8)/8)<<8);
		
			(current_proc->pa8)->oconst=tick;
			
			insert_object(current_proc->pa8,&objlst);

			oa7=current_proc->pa8;				// prev shad obj
			(current_proc->pa8)->oplink=NULL;		// terminate list
		}
		
		/* delete shadows */
		if ((obj=(OBJECT *)current_proc->pdata.p_store2)!=NULL) 
		{
			/* check to see if its time to delete shadow */
			if (abs(tick-obj->oconst)>15) 
			{
				(OBJECT *)current_proc->pdata.p_store2=(OBJECT *)obj->oplink;
				delobjp(obj);
			}
		}
		
		if ((p_agressor_active[0]+p_agressor_active[1])>=2)		// speed opt hopefully
			process_sleep(20);
		else process_sleep(8);
	}
	
	
	/* trail7 */
	oa11=(OBJECT *)current_proc->pdata.p_store2;

	/* trail8 */
	while (oa11!=NULL)
	{
		(OBJECT *)current_proc->a10=(OBJECT *)oa11->oplink;
		delobjp(oa11);
		process_sleep(2);
		oa11=(OBJECT *)current_proc->a10;
	};

	process_suicide();
}

void cancel_agressor(OBJECT *obj) 
{
	if (process_exist(get_trail_pid(obj),0xffff)!=NULL) 
	{
		dallprc(get_trail_pid(obj));			// kill any trails
		dallobj(get_shadow_oid(obj));			// kill prev shadow
	}
	
	return;
}

