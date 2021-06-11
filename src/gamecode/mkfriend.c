/******************************************************************************
 File: mkfriend.c

 Date: Jan 1995

 (C) Williams Entertainment

 Mortal Kombat III Friendship Routines
******************************************************************************/

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkfx.h"
#include "mkutil.h"
#include "mkani.h"
#include "mkgame.h"
#include "mkguys.h"
#include "mkanimal.h"
#include "mkfriend.h"
#include "mkzap.h"
#include "mkfatal.h"
#include "mkpal.h"
#include "mksound.h"
#include "mktext.h"
#include "moves.h"
#include "mkreact.h"
#include "mkcanned.h"
#include "mkjoy.h"
#include "mkdma.h"

#include "vcache.h"


JUMPTBL ochar_friends[]=
{
	f_kano,			// 0
	f_sonya,			// 1
	f_jax,			// 2
	f_indian,   		// 3
	f_jcage,		// 4
	f_swat,			// 5
	f_sindel,   		// 6
	f_sektor,   		// 7
	f_cyrax,			// 8
	f_lao,			// 9
	f_kabal,			// 10
	f_sheeva,  		// 11
	f_shang,			// 12
	f_liu,			// 13
	f_smoke_ninja,		// 14
	f_kitana,		// 15
	f_jade,			// 16
	fr_mileena,		// 17

	f_scorpion,
	f_reptile,
	f_ermac,
	f_osz,
	f_osm,		// no smoking
	f_noob,
	
	f_rd_friendship,			//-u64-
	f_sa_friendship,
	f_rain_friendship,
	f_null_friendship,
	
	f_null_friendship,
	f_null_friendship,
};

//******************************************************************************
//******************************************************************************
extern WORD RADKID_P[];
extern void *fl_kidd[];
extern FNTSETUP pf_kidd[];
extern WORD RD_ELEC_P[];
void kidd_thunder_proc(void) 
{
	OBJECT *obj;
	
	obj=current_proc->pa8=(OBJECT *)current_proc->a10;
	
	tsound(0x1);		//-SOUND
	((ADDRESS *)current_proc->pa9)++;
	mframew(3);
	
	(current_proc->pa8)->ochar=FT_RAYDEN;
	swpal(RADKID_P,current_proc->pa8);
	
	mframew(4);
	
//	CREATE(PID_AUTO_CYCLE,boonpal_stuff)->a11=(ADDRESS)fl_kidd;
	lm_printf(pf_kidd);
	
	current_proc->pa8=obj;
	borrow_ochar_sound(0xe,FT_RAYDEN);
	process_sleep(0x40);
	wait_forever();
}

void f_rd_friendship(void) 
{
	OBJECT *obj=current_proc->pa8;
	void *stka9;
	
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_DZAP2);
	mframew(4);
	
	stka9=current_proc->pa9;
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_KIDD);
	current_proc->a11=(ADDRESS)current_proc->pa9;
	get_proj_obj_m(obj);
	swpal(RD_ELEC_P,(OBJECT*)current_proc->a10);
	insert_object((OBJECT *)current_proc->a10,&objlst);
	CREATE(PID_BONES,kidd_thunder_proc)->pa9=current_proc->pa9;
	current_proc->pa8=obj;
	current_proc->pa9=stka9;
	
	process_sleep(0x78);
	
	dallobj(OID_TEXT);
	
	death_blow_complete();
	player_normpal();
	
	process_sleep(0x10);
	stack_jump(victory_animation);
}

void rain_flowers(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	process_sleep(3+randu(10));
	get_char_ani(ANIM_TABLE2,ANIM_NJ_FLOWER);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);

	obj->oxpos.u.intpos=current_proc->pdata.p_store1+20-randu(40);

	ground_a8();
	obj->oypos.u.intpos+=randu(SCY(5));
	obj->ozval=666;
	insert_object(obj,&objlst);

	get_char_ani(ANIM_TABLE2,0x14);
	framew(3+randu(6));
	process_suicide();
}

void rain_drop(void) 
{
	OBJECT *obj;
	
	/* create drop */
	current_proc->a10=(ADDRESS)current_proc->pa8;
	find_ani_part_a14(ANIM_ZAP,3);
	((ADDRESS*)current_proc->pa9)+=5;
	gso_dmawnz(obj,COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9)),(current_proc->pa8)->odict,(current_proc->pa8)->oheap,PFLAG_PALLOAD);
	obj->ochar=((OBJECT *)(current_proc->a10))->ochar;		// pass sonya id
	
	obj->oxpos.u.intpos=current_proc->pdata.p_store1;
	obj->oxpos.u.intpos+=50-randu(100);
	obj->oypos.u.intpos=-16;
	obj->ozval=999;
	
	insert_object(obj,&objlst);
	
	animate(SINGLE_ANI0,(OIMGTBL *)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9)),obj->oflags);
	
	current_proc->a0=(long)(0x6000);
	set_proj_vel(obj,(long)current_proc->a0,1);

	current_proc->pdata.p_ganiy=ground_y-15;			// set the ground

	obj->oyvel.pos=0x0000;
	obj->ograv.pos=0x6000;
	
	/* fall to ground */
	do
	{
		obj->oyvel.pos+=obj->ograv.pos;
		process_sleep(1);
	}
	while (!(obj->oyvel.pos>=0 && hit_ground_yet(obj)==SYSTEM_CARRY_SET));

	rsnd_splish();

	stop_a8(obj);
	ground_player(obj);
	
	/* splash */
	find_ani_part_a14(ANIM_ZAP,4);

	framew(4);				// splash on ground

	delobjp(obj);

	process_suicide();
}

void rain_storm(void) 
{
	current_proc->a10=(ADDRESS)current_proc->pa8;
	while (1)
	{
		/* create rain drop */
		current_proc->pa8=current_proc->a10;
		CREATE(PID_BLOOD,rain_drop)->pdata.p_store1=current_proc->pdata.p_store1;
		process_sleep(randu(6)+3);
	}
}

void f_rain_friendship(void)  
{
	short xpos;
	PROCESS *ptemp;
	
	/* summon fire hand */
	animate2_a9(2,ANIM_SCORP_SUMMON);
	xpos=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;
	
	/* create rain storm */
	ptemp=CREATE(PID_BLOOD,rain_storm);
	ptemp->pdata.p_store1=xpos;
	ptemp->pa8=current_proc->pa8;
	process_sleep(0x50);
	
	/* grow three flowers below dudes feet */
	CREATE(PID_BLOOD,rain_flowers)->pdata.p_store1=xpos+5;
	CREATE(PID_BLOOD,rain_flowers)->pdata.p_store1=xpos;
	CREATE(PID_BLOOD,rain_flowers)->pdata.p_store1=xpos-5;

	process_sleep(15);

	stack_jump(friendship_complete);
}
//******************************************************************************
//******************************************************************************
short pin[][2]=
{
	{-34,0},

	{-22,+4},
	{-22,-4},
	
	{-10,8},
	{-10,0},
	{-10,-8},
	
	{2,12},
	{2,6},
	{2,-6},
	{2,-12},
};

void pin_proc(void) 
{
	OBJECT *obj;
	short zval=current_proc->a10;
	short oxpos=current_proc->a11;
	
	current_proc->pdata.p_store1=0;
	/* create pin */
	current_proc->a10=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE1,ANIM_NJ_PIN);
	gso_dmawnz(obj,COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9)),(current_proc->pa8)->odict,(current_proc->pa8)->oheap,PFLAG_PALLOAD);
	
	if (oxpos-worldtlx.u.intpos>SCRRGT/2)
		obj->oxpos.u.intpos=oxpos+pin[zval][0]-24;
	else 
	{
	 	obj->oxpos.u.intpos=oxpos-pin[zval][0]+24;	
		flip_single(obj);
	}
	
	obj->oypos.u.intpos=-16;
	obj->ozval=FRONT_Z+100+zval;
	
	insert_object(obj,&objlst);
	
	animate(SINGLE_ANI0,(OIMGTBL *)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9)),obj->oflags);
	
	current_proc->pdata.p_ganiy=ground_y-obj->osize.u.ypos-pin[zval][1];			// set the ground

	process_sleep(randu(8));
	obj->oyvel.pos=0x0000;
	obj->ograv.pos=0x6000;
	
	/* fall to ground */
	do
	{
		obj->oyvel.pos+=obj->ograv.pos;
		process_sleep(1);
	}
	while (!(obj->oyvel.pos>=0 && hit_ground_yet(obj)==SYSTEM_CARRY_SET));

	tsound(0x18);

	stop_a8(obj);
	ground_player(obj);

	/* wait for the bowling ball */
	while (current_proc->pdata.p_store1==0 || zval==6 || zval==9)
		process_sleep(1);
	
	set_proj_vel(obj,SCX(0x70000)+randu(0x40000),2);
	get_char_ani(ANIM_TABLE1,ANIM_NJ_PIN);
	obj->oyvel.pos=-SCY(0x90000)-randu(0x80000);
	obj->ograv.pos=SCY(0x6000);
	
	do
	{
		obj->oyvel.pos+=obj->ograv.pos;
		process_sleep(1);
	}
	while(proj_onscreen_test(obj)==SYSTEM_CARRY_SET);
	
	delete_proj_and_die(obj);
}

void pin_spawn_proc(void) 
{
	OBJECT *obj;
	OBJECT *oa8=current_proc->pa8;
	void *heap;
	int i;
	PROCESS *ptemp;
	
	/* load data */
	heap=oa8->oheap;		// save heap
	oa8->oheap=special_character_texture_load(SPEC_NJ_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);
	
	/* make pins */
	for (i=0;i<10;i++)
	{
		current_proc->pa8=oa8;
		ptemp=CREATE(PID_PROJ1,pin_proc);
		ptemp->pdata.p_otherguy=current_proc->pdata.p_otherguy;
		ptemp->a10=i;
		ptemp->a11=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;
	}
	
	process_sleep(2);
	
	oa8->oheap=heap;
	process_suicide();
}

void bball_proc(void) 
{
	PROCESS *ptemp;
	short xdist;
	OBJECT *obj=current_proc->pa8;
	short xpos=(current_proc->pdata.p_otherguy)->oxpos.u.intpos;

	obj->ozval=FRONT_Z+111;
	
	ground_a8();
	
	find_ani2_part_a14(ANIM_NJ_BOWLING,3);
		
	/* move ball towards pins */
	set_proj_vel(obj,SCX(0x90000),2);
	
	xdist=(obj->oxvel.pos>0)?30:60;
	/* when balls is close to pins release */
	tsound(0x0);
	current_proc->pdata.p_store1=0;
	
	do
	{
		next_anirate();
		process_sleep(1);
		
		if (abs(obj->oxpos.u.intpos+obj->osize.u.xpos-xpos)<xdist && current_proc->pdata.p_store1==0) 
		{
			current_proc->pdata.p_store1=1;
			ptemp=(PROCESS *)&active_head;
			while (ptemp->plink!=NULL)
			{
				ptemp=ptemp->plink;
				
				if (ptemp->procid==PID_PROJ1)
					ptemp->pdata.p_store1=1;
			}
			
			tsound(0x0);
			tsound(0x1);
			shake_a11(6,8);
		}
	}
	while(proj_onscreen_test(obj)==SYSTEM_CARRY_SET);
	
	delete_proj_and_die(obj);
}


void f_noob(void) 
{
	OBJECT *obj=current_proc->pa8;
	OBJECT *oball=current_proc->pa8;
	
	CREATE(PID_BLOOD,pin_spawn_proc)->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	process_sleep(0x40);
	
	/* make bowling ball */
	get_char_ani(ANIM_TABLE2,ANIM_NJ_BOWLING);
	find_part2();
	get_proj_obj_m(oball);
	current_proc->a11=(ADDRESS)current_proc->pa9;
	multi_adjust_xy((OBJECT*)current_proc->a10,0,SCY(0x60));
	insert_object((OBJECT *)current_proc->a10,&objlst);
	
	/* go into bowling motion */
	get_char_ani(ANIM_TABLE2,ANIM_NJ_BOWLING);
	double_mframew(4);
	
	/* release ball process */
	create_proj_proc(bball_proc);
	
	process_sleep(0x60);
	
	tsound(0x82);
	process_sleep(0x40);
	death_blow_complete();
	player_normpal();

	stack_jump(victory_animation);
}

//******************************************************************************
//******************************************************************************
void levitate_explode(void) 
{
	(OBJECT *)current_proc->a10=current_proc->pa8;
	borrow_ochar_sound(0xd,FT_ROBO1);
	get_explode_obj();
	(current_proc->pa8)->ozval=999;
	multi_adjust_xy(current_proc->pa8,SCX(0x00),SCY(0x50));
	mframew(4);
	delete_proj_and_die(current_proc->pa8);
}

void r_levitate(void) 
{
	short ta11;
	ADDRESS animframe;
	OBJECT *obj=current_proc->pa8;
	
	/* due knockdown frame */
	find_ani_part2(ANIM_KDOWN);
	do_next_a9_frame(obj);
	set_ignore_y(obj);
	
	/* raise above ground */
	obj->ograv.pos=-0x5000;
	do
	{
		process_sleep(1);
	}
	while(distance_off_ground(current_proc,current_proc->pa8)<0x50);
	stop_me(current_proc->pa8);
	
	/* float up and down a bit */
	ta11=6;
	do
	{
		/* move up */
		obj->oyvel.pos=-0x8000;
		process_sleep(12);
		
		/* move down */
		obj->oyvel.pos=0x8000;
		process_sleep(12);
	}
	while(--ta11>0);
	
	/* poof and dissappear */
	borrow_ochar_sound(0xd,FT_ROBO1);
	CREATE(PID_FX,levitate_explode);
	process_sleep(10);
	set_inviso(current_proc->pa8);
	wait_forever();
}

void poof_rabbit(void)
{
	short ta11;
	ADDRESS animframe;
	OBJECT *obj;

	obj=current_proc->pa8=current_proc->pdata.p_otherguy;
	
	/* poof and your a rabit */
	tsound(0x8c);				
	current_proc->a10=(ADDRESS)current_proc->pa8;
	create_fx(FX_INVISO_POOF);
	process_sleep(8);
	
	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_NJ_BUNNY);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	adjust_xy_a5(obj,18,0);

	ground_a8();
	obj->ozval=3233;
	insert_object(obj,&objlst);

	framew(8);
	wait_forever();
}

void f_ermac(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	/* annouce lift */
	obj->ochar=FT_REPTILE;		// fool victory
	get_char_ani(ANIM_TABLE1,ANIM_VICTORY);
	shake_a11(6,8);
	mframew(5);
	obj->ochar=FT_ERMAC;
	
	process_sleep(16);
	ochar_sound(0xf);
	
	/* make other dude levitate */
	takeover_him(r_levitate);
	process_sleep(0xe0);
	
	animate2_a9(0x2,ANIM_REP_INV);
	takeover_him(poof_rabbit);
	process_sleep(0x40);
	
	stack_jump(friendship_complete);
}

//******************************************************************************
//******************************************************************************
void f_sa_friendship(void) 
{
	OBJECT *obj=current_proc->pa8;
	void *stka9;
	
	get_char_ani(ANIM_TABLE2,ANIM_BARAKA_FRIEND);
	mframew(4);
	process_sleep(0x18);
	
	mframew(8);
	
	stka9=current_proc->pa9;
	get_char_ani(ANIM_TABLE2,ANIM_BARAKA_GIFT);
	current_proc->a11=(ADDRESS)current_proc->pa9;
	get_proj_obj_m(obj);
	insert_object((OBJECT *)current_proc->a10,&objlst);
	current_proc->pa9=stka9;
	
	double_mframew(8);
	process_sleep(10);

	stack_jump(friendship_complete);
}

//******************************************************************************
//******************************************************************************
void fr_mileena(void) 
{
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_FN_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_MIRROR_MIRROR);
	mframew(5);
	process_sleep(0x60);
	tsound(0x1);
	shake_a11(7,8);
	mframew(4);
	tsound(0x66);	
	process_sleep(0x20);
	
	(current_proc->pa8)->oheap=heap;
	
	stack_jump(friendship_complete);
}  

//******************************************************************************
//******************************************************************************
void f_scorpion(void) 
{
	jax_n_box_start();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_SKULLBOX);
	current_proc->a5=(ADDRESS)current_proc->pa9;
	stack_jump(pop_up_my_toy);
}

void f_osz(void) 
{
	jax_n_box_start();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_SNOWBOX);
	current_proc->a5=(ADDRESS)current_proc->pa9;
	stack_jump(pop_up_my_toy);
}

void f_reptile(void)
{
	clear_inviso(current_proc->pa8);
	jax_n_box_start();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_SNAKEBOX);
	current_proc->a5=(ADDRESS)current_proc->pa9;
	stack_jump(pop_up_my_toy);
}

void pop_up_my_toy(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	tsound(0x92);	
	shake_a11(6,6);

	takeover_him(r_scared_of_monkey);

	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	obj->ozval=100;
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	insert_object(obj,&objlst);

	framew(4);
	process_sleep(0x30);
	death_blow_complete();
	wait_forever();
}

void jax_n_box_start(void) 
{
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);
	
	center_around_me();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_CRANK);
	do_next_a9_frame(current_proc->pa8);
	process_sleep(0x10);
	current_proc->a11=(ADDRESS)current_proc->pa8;
	mframew(6);
	return;
}

//******************************************************************************
//******************************************************************************
extern WORD SMOKESIGN1_P[];
extern WORD SMOKESIGN2_P[];
extern WORD SMOKESIGN3_P[];
extern WORD SMOKESIGN4_P[];
extern WORD SMOKESIGN5_P[];

WORD *sign_tbl[]=
{
	SMOKESIGN1_P,
	SMOKESIGN2_P,
	SMOKESIGN3_P,
	SMOKESIGN4_P,
	SMOKESIGN5_P,
	SMOKESIGN4_P,
	SMOKESIGN3_P,
	SMOKESIGN2_P,
	NULL
};

void smoke_sign(void) 
{
	void *heap;
	ADDRESS animframe;
	OBJECT *obj;
	WORD **ta10;
	OBJECT *pa8=current_proc->pa8;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);
	
	/* create sign */
	get_char_ani(ANIM_TABLE1,ANIM_NJ_SSIGN);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz_ns(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	
	obj->oxpos.u.intpos=160;
	obj->oypos.u.intpos=-64;
	a8_front_plus_1(obj);
	insert_object(obj,&objlst);
	
	pa8->oheap=heap;
	
	obj->ograv.pos=SCY(0x8000);
	do
	{
		process_sleep(1);
		obj->oyvel.pos+=obj->ograv.pos;
		obj->oypos.pos+=obj->oyvel.pos;
	}
	while(obj->oypos.u.intpos<ground_y-obj->osize.u.ypos);
	
	stop_a8(obj);
	rsnd_big_block();
	
	/* cycle palette */
	while (1)
	{
		ta10=sign_tbl;

		do
		{
			free_pal(obj->opal);
			obj->opal=get_fore_pal((void *)(*ta10));
			process_sleep(13);
			
			ta10++;
		}
		while(*ta10!=NULL);
	}
}

void f_osm(void) 
{				
	shake_a11(0x6,0x10);
	
	process_sleep(0x20);
	
	CREATE(PID_BLOOD,smoke_sign);
	
	process_sleep(0x70);

	tsound(0xb8);
	dallprc(PID_SMOKER);
	
	process_sleep(0x50);

	stack_jump(friendship_complete);
}

//******************************************************************************
//******************************************************************************
void f_jade(void) 
{
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_FN_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	kill_and_stop_scrolling();
	get_char_ani(ANIM_TABLE1,ANIM_POGO_STICK);
	animate_a0_frames(4,3);
	process_sleep(0x10);
	CREATE(PID_FX,friend_ender);

	current_proc->a10=(ADDRESS)current_proc->pa9;
	current_proc->a10-=4;			// 1 LONG
	current_proc->a11=(ADDRESS)current_proc->pa9;
	
	/* pogo_bounce */
	while (1)
	{
		(ADDRESS)current_proc->pa9=current_proc->a11;
		do_next_a9_frame(current_proc->pa8);
		flight(current_proc->pa8,SCX(0x0),-SCY(0xa0000),SCY(0x9000),NEVER_ANI,-1);
		tsound(0xc);

		(ADDRESS)current_proc->pa9=current_proc->a10;
		do_next_a9_frame(current_proc->pa8);
		process_sleep(1);											
	}
}

void friend_ender(void) 
{
	process_sleep(0x40*2+0x20);
	death_blow_complete();
	process_suicide();
}

void f_null_friendship(void) 
{
	process_sleep(0x40*2);
	death_blow_complete();
	stack_jump(friendship_complete);
}

//******************************************************************************
//******************************************************************************
void f_kitana(void) 
{
	PROCESS *pa0;

	/* calla_for_him */
	pa0=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	center_around_me();
	current_proc=pa0;

	animate2_a9(5,ANIM_KIT_BUBBLES);
	process_sleep(0x70);

	delete_slave();
	find_ani2_part2(ANIM_MIL_KISS);
	mframew(4);
	stack_jump(friendship_complete);
}

void spawn_bubble(void) 
{
	CREATE(PID_BLOOD,bubble_proc);
	return;
}

void bubble_proc(void) 
{
	current_proc->a10=40;
	do
	{
		CREATE(PID_FX,bub_1_proc);
		process_sleep(3);
	}
	while(--current_proc->a10>0);
	process_suicide();
}

void bub_1_proc(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	find_ani2_part2(ANIM_KIT_BUBBLES);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	current_proc->a11=(ADDRESS)current_proc->pa8;
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	insert_object(obj,&objlst);

	((ADDRESS *)current_proc->pa9)++;
	framew(1);

	set_proj_vel(current_proc->pa8,SCX(0x20000)+randu(SCX(0x30000)),-1);
	(current_proc->pa8)->oyvel.pos=srandarc(SCY(0x20000));

	process_sleep(20+randu(30));

	rsnd_small_block();

	framew(4);
	delobjp(current_proc->pa8);
	process_suicide();
}


/******************************************************************************
 Function: void do_friendship(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform fighter friendship
******************************************************************************/
void do_friendship(void)
{
	friendship_start_pause();
	init_special(current_proc->pa8);
	ochar_friends[(current_proc->pa8)->ochar]();
}

void friendship_start_pause(void)
{
	OBJECT *obj=current_proc->pa8;

	init_death_blow(FAT_FRIEND);

	/* sleep for fade */
	process_sleep(0x20);

	nosounds();
	sound_music_start(MUSIC_FRIENDSH);
	
	return;
}

void friendship_complete(void)
{
	death_blow_complete();
	player_normpal();

	wait_forever();
}

/******************************************************************************
 Function: void f_kano(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform kano friendship
******************************************************************************/
void f_kano(void)
{
	get_char_ani(ANIM_TABLE2,ANIM_KANO_FRIEND);
	mframew_5;
	stack_jump(friendship_complete);
}

/******************************************************************************
 Function: void f_sonya(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform sonya friendship
******************************************************************************/
void f_sonya(void)
{
	current_proc->a10=25;
	do
	{
		CREATE(PID_BLOOD,sonya_flower_proc);
	}
	while(--current_proc->a10>0);

	process_sleep(0x30);
	death_blow_complete();
	player_normpal();

	stack_jump(victory_animation);
}

void sonya_flower_proc(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	process_sleep(20+randu(10));
	get_char_ani(ANIM_TABLE2,ANIM_SONYA_PLANT);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz_ns(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);

	obj->oxpos.u.intpos=randu(SCRRGT);

	ground_a8();
	obj->oypos.u.intpos+=randu(SCY(5));
	a8_front_plus_1(obj);
	insert_object(obj,&objlst);

	get_char_ani(ANIM_TABLE2,ANIM_SONYA_PLANT);
	framew(3+randu(6));
	process_suicide();
}

/******************************************************************************
 Function: void f_jax(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform jax friendship
******************************************************************************/
void f_jax(void)
{
	CREATE(PID_BANI,end_friend_proc);
	//current_proc->pa9=a_jax_friend;
	get_char_ani(ANIM_TABLE2,ANIM_JAX_FRIEND);
	do_next_a9_frame(current_proc->pa8);
	process_sleep(0x20);
	mframew_3;
	stack_jump(friendship_complete);
}

void end_friend_proc(void)
{
	process_sleep(0x80);
	death_blow_complete();
	process_suicide();
}

/******************************************************************************
 Function: void f_indian(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform indian friendship
******************************************************************************/
void f_indian(void)
{
	OBJECT *obj,*ta8;
	void *heap;
	void *animframe;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_IND_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_IND_FRIEND);
	ochar_sound(0);

	CREATE(PID_FX,friend_ender);
	
	mframew_5;
	
	wait_forever();
}

#if 0
char txt_kano[]="I'VE NEVER SEEN A KANO TRANSFORMATION";
char txt_raiden1[]="NO, BUT I KNOW HOW TO DO";
char txt_raiden2[]="A RAYDEN TRANSFORMATION";
void f_indian(void)
{
	OBJECT *obj,*ta8;
	void *heap;
	void *animframe;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_IND_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_IND_FRIEND);
	other_ochar_sound(4,FT_ST);

	mframew_5;
	process_sleep(0x20);

	ta8=current_proc->pa8;
	current_proc->a10=(ADDRESS)current_proc->pa8;

	current_proc->a0=(ADDRESS)current_proc->pa9;
	animframe=(void*)get_char_ani(ANIM_TABLE1,ANIM_IND_MKGAME);		// get mk2game frame ptr
	current_proc->pa9=(void*)current_proc->a0;
	animframe=(void*)COMPUTE_ADDR(ta8->oheap,GET_LONG(animframe));

	gso_dmawnz(obj,(ADDRESS)animframe,ta8->odict,ta8->oheap,0);
	alloc_cache((OIMGTBL*)animframe,ta8->oheap,obj);

	lineup_1pwm(obj,(OBJECT *)current_proc->a10);
	multi_adjust_xy(obj,-(SCX(0x70)),-SCY(0x100));
	insert_object(obj,&objlst);
	gravity_ani_ysize(SCY(0x20000),SCY(0x6000));
	shake_n_sound();

	if ( random()<0 )
	{
		p7_centered(txt_raiden1,160,SCY(0xf0)-14);
		p7_centered(txt_raiden2,160,SCY(0xf0));
	}
	else
	{
		p7_centered(txt_kano,160,SCY(0xf0));
	}

	current_proc->pa8=ta8;
	process_sleep(0x60);
	death_blow_complete();
	
	wait_forever();
}
#endif
void other_ochar_sound(WORD pa0,WORD pa1)
{
	WORD ta2;

	ta2=(current_proc->pa8)->ochar;
	(current_proc->pa8)->ochar=pa1;
	ochar_sound(pa0);
	(current_proc->pa8)->ochar=ta2;
	return;
}

void f_jcage(void)
{
	get_char_ani(ANIM_TABLE2,ANIM_JC_FRIEND);
	mframew(8);
	
	CREATE(PID_BONES,autograph_proc);
	
	get_char_ani(ANIM_TABLE2,ANIM_JC_FRIEND);
	do_next_a9_frame(current_proc->pa8);

	process_sleep(0x20);
	death_blow_complete();
	player_normpal();

	stack_jump(victory_animation);
}

void autograph_proc(void)
{
	OBJECT *obj;
	ADDRESS animframe;
	
	ochar_sound(0);
	
	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_JC_PHOTO);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);


	obj->oypos.u.intpos=SCY(0x40)+((OBJECT*)current_proc->a11)->oypos.u.intpos;
	obj->oxpos.u.intpos=SCX(0x0)+((OBJECT*)current_proc->a11)->oxpos.u.intpos;
	obj->ozval=8250+((OBJECT*)current_proc->a11)->ozval;
	insert_object(obj,&objlst);

	obj->oyvel.pos=SCY(0x50000);
	get_char_ani(ANIM_TABLE2,ANIM_JC_PHOTO);
	framew(2);
	
	stop_a8(obj);
	set_noscroll(obj);
	
	get_char_ani(ANIM_TABLE2,ANIM_JC_PAGE);
	frame_a9(obj);
	obj->oypos.u.intpos=SCRBOT+SCY(10);
	obj->oxpos.u.intpos=SCRRGT/2-SCX(0x20);
	process_sleep(8);
	
	obj->oyvel.pos=-SCY(0x80000);
	process_sleep(0x10);
	
	stop_a8(obj);
	
	process_suicide();
}

/******************************************************************************
 Function: void f_swat(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform swat friendship
******************************************************************************/
//extern void *a_swat_friend[];
void f_swat(void)
{
	CREATE(PID_BANI,swat_friend_proc);

	/* swatf3 */
#if 0
	do
	{
		CREATE(PID_BANI,swat_crossing_people);
	}
	while(--current_proc->a11>0);
#endif
	CREATE(PID_BANI,swat_crossing_people);

	//current_proc->pa9=a_swat_friend;
	get_char_ani(ANIM_TABLE2,ANIM_SWAT_FRIEND);
	do_next_a9_frame(current_proc->pa8);

	if ((current_proc->pa8)->oflags & M_FLIPH)
		flip_multi(current_proc->pa8);

	mframew_5;
	ochar_sound(8);
	process_sleep(0x40);
	mframew_5;
	stack_jump(friendship_complete);
}

void swat_friend_proc(void)
{
	process_sleep(0xa0);
	death_blow_complete();
	process_suicide();
}

void swat_crossing_people(void)
{
	OBJECT *odog,*owagon;
	void *dogani,*wagonani;

	current_proc->pdata.p_otherguy=current_proc->pa8;

	process_sleep(0x50);

	/* create dog */
	get_char_ani(ANIM_TABLE2,ANIM_SWAT_DOG);						// get ptr to anim table
	dogani=current_proc->pa9;
	current_proc->pa9=COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));	// get ptr to frame
	gso_dmawnz(odog,(ADDRESS)current_proc->pa9,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,(current_proc->pa8)->oheap,odog);

	odog->oxpos.u.intpos=worldtlx.u.intpos-SCX(0x30);
	odog->oxvel.pos=SCX(0x30000);
	odog->oypos.u.intpos=ground_y-SCY(0x20);
	odog->ozval=100;
	insert_object(odog,&objlst);

	/* create wagon */
	get_char_ani(ANIM_TABLE2,ANIM_SWAT_WAGON);						// get ptr to anim table
	wagonani=current_proc->pa9;
	current_proc->pa9=COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));	// get ptr to frame
	gso_dmawnz(owagon,(ADDRESS)current_proc->pa9,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,(current_proc->pa8)->oheap,owagon);

	match_ani_points(odog,owagon);				// match to two
	multi_adjust_xy(owagon,-62,-15);				// lineup wagon with dog
	owagon->oxvel.pos=SCX(0x30000);				// set speed to match dog
	owagon->ozval=200;
	insert_object(owagon,&objlst);

	/* cross */
	do
	{
		process_sleep(3);

		/* update dog */
		current_proc->pa8=odog;
		current_proc->pa9=dogani;
		frame_a9(odog);
		dogani=current_proc->pa9;

		/* update wagon */
		current_proc->pa8=owagon;
		current_proc->pa9=wagonani;
		frame_a9(owagon);
		wagonani=current_proc->pa9;
	} while (abs(worldtlx.u.intpos-odog->oxpos.u.intpos)<700);

	delobjp(odog);
	delobjp(owagon);

	process_suicide();
}

/******************************************************************************
 Function: void f_sindel(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform sindel friendship
******************************************************************************/
//extern void *a_lia_friend[];
//extern void *a_football[];
void f_sindel(void)
{
	PROCESS *ta0;

	//current_proc->pa9=a_lia_friend;
	get_char_ani(ANIM_TABLE2,ANIM_LIA_FRIEND);
	mframew_5;

	rsnd_big_block();
	shake_a11(0x3,0x3);

	ta0=CREATE(PID_BANI,football_proc);
	ta0->pa9=(void *)current_proc->pdata.p_slave;
	current_proc->a10=(ADDRESS)ta0;
	current_proc->pdata.p_slave=NULL;
	do_next_a9_frame(current_proc->pa8);
	process_sleep(0x10);

	mframew_5;
	ochar_sound(9);
	process_sleep(0x40);
	stack_jump(friendship_complete);
}

void football_proc(void)
{
	if ((current_proc->pa8)->oflags & M_FLIPH)
		((OBJECT*)current_proc->pa9)->oxvel.pos=-SCX(0xa0000);
	else ((OBJECT*)current_proc->pa9)->oxvel.pos=SCX(0xa0000);

	((OBJECT*)current_proc->pa9)->oyvel.pos=-SCY(0xa0000);
	current_proc->pa8=(OBJECT *)current_proc->pa9;
	get_char_ani(ANIM_TABLE2,ANIM_LIA_BALL);
	find_part2();
	init_anirate(2);

	/* foot5 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(((current_proc->pa8)->oypos.u.intpos+100)>worldtly.u.intpos);

	delobjp(current_proc->pa8);

	process_suicide();
}

/******************************************************************************
 Function: void f_sektor(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform sektor friendship
******************************************************************************/
void f_sektor(void)
{
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_ROBO_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	CREATE(PID_BANI,dinger_proc);
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_FRIEND1);
	do_next_a9_frame(current_proc->pa8);
	process_sleep(0x50);
	mframew_5;
	
	stack_jump(friendship_complete);
}

void dinger_proc(void)
{
	ochar_sound(0x21);

	current_proc->a10=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_DINGER);
	gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);
	lineup_a0_onto_a1(current_proc->pa8,(OBJECT *)current_proc->a10);
	insert_object(current_proc->pa8,&objlst);
	mframew_5;
	process_sleep(0x40);
	mframew_5;
	process_suicide();
}

/******************************************************************************
 Function: void f_cyrax(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform cyrax  friendship
******************************************************************************/
void f_cyrax(void)
{
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_ROBO_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	CREATE(PID_BANI,end_friend_proc);
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_FRIEND2);
	mframew(10);
	stack_jump(friendship_complete);
}

/******************************************************************************
 Function: void f_lao(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform lao friendship
******************************************************************************/
void f_lao(void)
{
	CREATE(PID_BANI,end_friend_proc);
	CREATE(PID_BANI,cute_lil_doggy);
	CREATE(PID_BANI,lao_dog_sounds);

	//current_proc->pa9=a_lao_friend;
	get_char_ani(ANIM_TABLE2,ANIM_LAO_FRIEND);
	mframew_4;
	CREATE(PID_BANI,hat_proc);
	process_sleep(0x60);

	tsound(0x8b);
	mframew_4;
	process_sleep(0x30);

	mframew(8);
	stack_jump(friendship_complete);
}

void lao_dog_sounds(void)
{
	process_sleep(8);

	current_proc->a10=5;
	/* dog3 */
	do
	{
		tsound(0x8a);
		process_sleep(0x10);
	}
	while(--current_proc->a10>0 );
	process_suicide();
}

void cute_lil_doggy(void)
{
	OBJECT *obj;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_LAO_DOG);						// get ptr to anim table
	current_proc->pa9=COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));	// get ptr to frame
	gso_dmawnz(obj,(ADDRESS)current_proc->pa9,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,(current_proc->pa8)->oheap,obj);

	if (((OBJECT *)current_proc->a10)->oflags & M_FLIPH)
	{
		obj->oxpos.u.intpos=SCRRGT+SCX(0x30)+SCX(0x30)+worldtlx.u.intpos-SCX(0x30);
		obj->oxvel.pos=-SCX(0x60000);
		flip_single(obj);
	}
	else
	{
		obj->oxpos.u.intpos=worldtlx.u.intpos-SCX(0x30);
		obj->oxvel.pos=SCX(0x60000);
	}

	/* cute3 */
	obj->oypos.u.intpos=ground_y-SCY(0x20);
	obj->ozval=100;
	insert_object(obj,&objlst);

	//current_proc->pa9=a_dog;
	get_char_ani(ANIM_TABLE2,ANIM_LAO_DOG);
	init_anirate(3);
	do
	{
		next_anirate();
		process_sleep(1);

	} while (abs(worldtlx.u.intpos-obj->oxpos.u.intpos)<700);

	stop_a8(obj);

	wait_forever();
}

void hat_proc(void)
{
	OBJECT *obj;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	//gso_dmawnz(obj,(ADDRESS)&FETCHHAT2,friendship_anims,0);
	//alloc_cache(&FETCHHAT2,&friendship_anims,obj);
	get_char_ani(ANIM_TABLE2,ANIM_LAO_FETCH);						// get ptr to anim table
	current_proc->pa9=COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));	// get ptr to frame
	gso_dmawnz(obj,(ADDRESS)current_proc->pa9,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)current_proc->pa9,(current_proc->pa8)->oheap,obj);

	lineup_a0_onto_a1(obj,(OBJECT *)current_proc->a10);
	multi_adjust_xy(obj,SCX(0x50),SCY(0x10));
	insert_object(obj,&objlst);

	obj->oyvel.pos=-SCY(0x40000);
	set_proj_vel(obj,SCX(0xa0000),2);
	process_suicide();
}

/******************************************************************************
 Function: void f_kabal(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform kabal friendship
******************************************************************************/
void f_kabal(void)
{
	CREATE(PID_BANI,end_friend_proc);
	get_char_ani(ANIM_TABLE2,ANIM_TUSK_FRIEND);
	mframew_5;
	stack_jump(friendship_complete);
}

/******************************************************************************
 Function: void f_sheeva(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform sheeva friendship
******************************************************************************/
void f_sheeva(void)
{
	CREATE(PID_BANI,end_friend_proc);
	get_char_ani(ANIM_TABLE2,ANIM_SG_FRIEND);
	mframew_5;
	ochar_sound(6);
	mframew_5;
	stack_jump(friendship_complete);
}

/******************************************************************************
 Function: void f_shang(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform shang friendship
******************************************************************************/
//extern OIMGTBL *ostrich1;
void f_shang(void)
{
	OBJECT *obj=current_proc->pa8;
	void *animframe;

	CREATE(PID_BANI,end_friend_proc);
	tsound(0x8c);
	create_fx(FX_INVISO_POOF);

	process_sleep(8);

	set_inviso(current_proc->pa8);
	current_proc->a10=(ADDRESS)current_proc->pa8;

	get_char_ani(ANIM_TABLE2,ANIM_ST_FRIEND);
	animframe=(void*)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9));

	gso_dmawnz(obj,(ADDRESS)animframe,obj->odict,obj->oheap,0);
	alloc_cache((OIMGTBL *)animframe,obj->oheap,obj);

	obj->oxpos.u.intpos=((OBJECT*)current_proc->a10)->oxpos.u.intpos;
	obj->oypos.u.intpos=ground_y-SCY(0x20);
	insert_object(obj,&objlst);
	process_sleep(0x40);

	bounce();
	bounce();

	obj->oxvel.pos=SCX(0x30000);
	/* shang4 */
	current_proc->a10=5;
	do
	{
		bounce();
	}
	while(--current_proc->a10>0 );
	stop_a8(current_proc->pa8);
	wait_forever();
}

void bounce(void)
{
	long ta11;

	ta11=-randu_minimum(SCY(0x40000),SCY(0x40000));

	(current_proc->pa8)->oyvel.pos=ta11;
	process_sleep(2);

	/* bnc3 */
	do
	{
		process_sleep(1);
		(current_proc->pa8)->oyvel.pos=ta11;
		ta11+=SCY(0x8000);
	}
	while((current_proc->pa8)->oypos.u.intpos+SCY(0x20)<ground_y );
	tsound(0x71);

	return;
}

/******************************************************************************
 Function: void f_liu(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform liu kang friendship
******************************************************************************/
//extern void *a_kang_friend[];
//extern void *a_wall_dragon[];
void f_liu(void)
{
	CREATE(PID_BANI,wall_dragon_proc);
	//current_proc->pa9=a_kang_friend;
	get_char_ani(ANIM_TABLE2,ANIM_LK_FRIEND);
	mframew_5;
	process_sleep(0x20);
	mframew_5;
	process_sleep(10);
	mframew_5;
	process_sleep(0x30);
	stack_jump(friendship_complete);
}

void wall_dragon_proc(void)
{
	current_proc->a10=(ADDRESS)current_proc->pa8;
	//current_proc->pa9=a_wall_dragon;
	get_char_ani(ANIM_TABLE2,ANIM_LK_WALL);
	gmo_proc((current_proc->pa8)->odict,(current_proc->pa8)->oheap);

	lineup_a0_onto_a1(current_proc->pa8,(OBJECT *)current_proc->a10);
	multi_adjust_xy(current_proc->pa8,0,-SCY(0x30));
	insert_object(current_proc->pa8,&objlst);
	mframew_5;
	process_sleep(0x20);
	mframew_4;
	process_suicide();
}

/******************************************************************************
 Function: void f_smoke_ninja(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:	perform smoke friendship
******************************************************************************/
void f_smoke_ninja(void)
{
	void *heap;

	CREATE(PID_BANI,end_friend_proc);
	robo_open_chest(current_proc->pa8);

	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_ROBO_FRIEND,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_ROBO_FRIEND3);
	mframew(5);

	ochar_sound(0x22);		// horn
	mframew_5;

	process_sleep(0x10);
	mframew_5;
	delete_slave();

	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	robo_close_chest(current_proc->pa8);

	stack_jump(victory_animation);
}

