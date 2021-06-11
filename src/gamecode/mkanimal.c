/******************************************************************************
 File: mkanimal.c

 Date: Jan 1995

 (C) Williams Entertainment

 Mortal Kombat III Animality Routines
******************************************************************************/

#define ANIMAL 0

/* INCLUDES */
#include "u64main.h"

#include "mkbkgd.h"
#include "mkos.h"
#include "mkobj.h"
#include "mkfx.h"
#include "mkutil.h"
#include "mkzap.h"
#include "mkani.h"
#include "mkgame.h"
#include "mkjoy.h"
#include "moves.h"
#include "mkcanned.h"
#include "mkguys.h"
#include "mkanimal.h"
#include "mkfatal.h"
#include "mkfade.h"
#include "mkreact.h"
#include "mkblood.h"
#include "mkpal.h"
#include "mkdma.h"
#include "mksound.h"
#include "mkdma.h"
#include "vcache.h"

void rain_elephant(void);
void cage_roo(void);
void noob_anteater(void);

JUMPTBL ochar_animalities[]=
{
	kano_spider,            // 0
	sonya_eagle,            // 1
	jax_lion,               // 2
	indian_wolf,            // 3
	cage_roo,				// 4
	swat_dino,              // 5
	sindel_wasp,            // 6
	sektor_bat,             // 7
	cyrax_shark,            // 8
	lao_cheetah,            // 9
	kabal_skeleton,         // 10
	sheeva_scorpion,                // 11
	shang_tsung_snake,      // 12
	liu_kang_dragon,                // 13
	smoke_bull_shit,         // 14
	kitana_bunny,			// 15
	jade_kitty,					// 16
	mileena_skunk,			// 17
	scorpion_pengo,			// 18
	reptile_monkey,			// 19
	ermac_frog,				// 20 
	sz_polar,
	osm_porcupine,
	noob_anteater,
	
	rayden_eel,				//-u64-
	baraka_vulture,
	rain_elephant,
	null_animal,
	
	null_animal,
	null_animal,
};

void setup_body_pieces(void);
/******************************************************************************
 Function: void do_animality(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   perform fighter animality
******************************************************************************/
void do_animality(void)
{
	animality_start_pause();
	init_special(current_proc->pa8);
	kill_kamel();
	ochar_animalities[(current_proc->pa8)->ochar]();
}

void animality_start_pause(void)
{
	OBJECT *obj=current_proc->pa8;

	init_death_blow(FAT_ANIMALITY);

	/* sleep for fade */
	process_sleep(0x20);

	return;
}


//******************************************************************************
//******************************************************************************
void null_animal(void) 
{
	process_sleep(0x40);
	animality_complete(0);
}

//******************************************************************************
//******************************************************************************
void noob_anteater(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	void *heap;
	PROCESS *ptemp;
	
	animality_tune();
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	sans_repell_for_good();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_ARDVARK);
	animal_appear();
	ground_a8();
	
	/* raise head */
	mframew(5);
	takeover_him(r_kiss_suck);
	process_sleep(34);
	/* start suck */
	tsound(0x87);
	mframew(5);
	tsound(0x60);
	ptemp=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	death_scream;
	current_proc=ptemp;
//	process_sleep(10);
	
	/* finish suck */
	mframew(5); 
	process_sleep(0x30);
	
	/* run frame */
	mframew(4);
	process_sleep(0x20);
	
	animality_complete(1);
}

//******************************************************************************
//******************************************************************************
void cage_roo(void) 
{
	animality_tune();

	get_char_ani(ANIM_TABLE2,ANIM_JC_KANGAROO);
	animal_appear();
	multi_adjust_xy(current_proc->pa8,-24,32);
	process_sleep(30);
	sans_repell_for_good();
	kill_and_stop_scrolling();

	mframew(5);
	shake_a11(0xa,0xa);

	takeover_him(hit_by_bull);

	process_sleep(0x50);

	get_char_ani(ANIM_TABLE2,ANIM_JC_KANGAROO);
	
	/* unmorph */
	backwards_ani(5,0xffff);
	
	death_blow_complete();
	wait_forever();
}

//******************************************************************************
//******************************************************************************
void rain_elephant(void)
{
	ADDRESS animframe;
	OBJECT *obj;
	void *heap;
	
	animality_tune();
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	sans_repell_for_good();
	get_char_ani(ANIM_TABLE1,ANIM_NJ_ELEPHANT);
	animal_appear();
	flip_multi(current_proc->pa8);
	ground_a8();
	
	process_sleep(0x20);
	
	mframew(5);
	borrow_ochar_sound(0x22,FT_SMOKE);
	
	/* make him rip */
	borrow_ochar_sound(0x8,FT_LIA);
	takeover_him(r_scream_ripped);
	process_sleep(24);
	
	/* run frame */
	mframew(4);
	
	death_blow_complete();
	wait_forever();
}

//******************************************************************************
//******************************************************************************
void mileena_skunk(void) 
{
	OBJECT *obj;
	ADDRESS animframe;
	PROCESS *pa0;

	cute_animality_start();

	current_proc->a11=(ADDRESS)current_proc->pa8;

	get_char_ani(ANIM_TABLE2,ANIM_SKUNK);

	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	a8_front_plus_1(obj);

	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	multi_adjust_xy(obj,-(0x20),SCY(0x20));
	ground_a8();
	insert_object(obj,&objlst);

	current_proc->a10=(ADDRESS)current_proc->pa9;

	current_proc->a11=3;
	/* sku4 */
	do
	{
		(ADDRESS)current_proc->pa9=current_proc->a10;
		framew(5);
	}
	while(--current_proc->a11>0);

	pa0=CREATE(PID_BLOOD,odor_proc);
	pa0->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	pa0->pdata.p_otherproc=current_proc->pdata.p_otherproc;

	current_proc->a11=2;
	/* sku5 */
	do
	{
		(ADDRESS)current_proc->pa9=current_proc->a10;
		framew(5);
	}
	while(--current_proc->a11>0);

	takeover_him(r_scared_of_skunk);
	process_sleep(0x30);

	animality_complete(1);
}

void odor_proc(void) 
{
	PROCESS *pa0;

	current_proc->a11=60;
	/* ordor3 */
	do
	{
		process_sleep(2);
		pa0=CREATE(PID_BLOOD,stink_cloud);
		pa0->pdata.p_otherguy=current_proc->pdata.p_otherguy;
		pa0->pdata.p_otherproc=current_proc->pdata.p_otherproc;
	}
	while(--current_proc->a11>0);
	process_suicide();
}

extern void *a_puff[];
extern WORD STINK_P[];
void stink_cloud(void) 
{
	ADDRESS animframe;
	OBJECT *obj=current_proc->pa8;

	current_proc->a11=(ADDRESS)current_proc->pa8;
#if 0	
	(ADDRESS)current_proc->pa9=current_proc->a10;
	find_part2();
	animframe=(ADDRESS)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,obj->odict,obj->oheap,0);
	alloc_cache((OIMGTBL *)animframe,obj->oheap,obj);
#endif
	current_proc->pa9=a_puff;
	animframe=GET_LONG(current_proc->pa9);
	gso_dmawnz(obj,(ADDRESS)animframe,0,0,0);
	alloc_cache((OIMGTBL *)animframe,0,obj);
	swpal((void*)STINK_P,obj);
		
	obj->oypos.u.intpos=((OBJECT*)current_proc->a11)->oypos.u.intpos;
	obj->oxpos.u.intpos=((OBJECT*)current_proc->a11)->oxpos.u.intpos;

	if (((OBJECT*)current_proc->a11)->oflags & M_FLIPH)
	{
		flip_single(obj);
		obj->oxpos.u.intpos+=16;
	}

	insert_object(obj,&objlst);

	set_proj_vel(obj,SCX(0x10000)+randu(SCX(0x30000)),-1);
	obj->oyvel.pos=-(SCY(0x10000)+randu(SCY(0x20000)));
	obj->ozval=FRONT_Z+200;
	framew(6);
	process_sleep(12);
	delobjp(obj);
	process_suicide();
}

//******************************************************************************
//******************************************************************************
void scorpion_pengo(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	PROCESS *pa0;
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	cute_animality_start();
	current_proc->a11=(ADDRESS)current_proc->pa8;

	get_char_ani(ANIM_TABLE1,ANIM_NJ_PENGO);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	a8_front_plus_1(obj);

	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	ground_a8();
	insert_object(obj,&objlst);

	set_vel_flip(SCX(0x20000));
	current_proc->a10=(ADDRESS)current_proc->pdata.p_otherguy;
	get_char_ani(ANIM_TABLE1,ANIM_NJ_PENGO);
	frame_a9(obj);
	process_sleep(0x10);

	init_anirate(5);

	/* pengo_walk */
	do
	{
		process_sleep(1);
		pengo_animate();
	}
	while(abs(obj->oxpos.u.intpos-((OBJECT*)current_proc->a10)->oxpos.u.intpos)>SCX(8) );

	pa0=CREATE(PID_BLOOD,egg_proc);
	pa0->pdata.p_otherguy=current_proc->pdata.p_otherguy;
	pa0->pdata.p_otherproc=current_proc->pdata.p_otherproc;
	center_around_him();

	stop_a8(obj);
	current_proc->a10=0x10;
	/* pwalk2 */
	do
	{
		process_sleep(1);
		pengo_animate();
	}
	while(--current_proc->a10>0);

	set_vel_flip(SCX(0x20000));
	current_proc->a10=0x20;
	/* pwalk3 */
	do
	{
		process_sleep(1);
		pengo_animate();
	}
	while(--current_proc->a10>0);

	stop_a8(obj);
	current_proc->pa8=(OBJECT*)current_proc->a11;		// bug fix FOR HEAPS
	death_blow_complete();
	(current_proc->pa8)->oheap=finish_heap_ptr;
	wait_forever();
}

void egg_proc(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE1,ANIM_NJ_EGG);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	a8_front_plus_1(obj);
	obj->oxpos.u.intpos=((OBJECT*)current_proc->a11)->oxpos.u.intpos;
	ground_a8();
	insert_object(obj,&objlst);
	get_char_ani(ANIM_TABLE1,ANIM_NJ_EGG);
	framew(5);

	process_sleep(0x20);
	takeover_him(r_egg);
	delobjp(obj);
	process_suicide();
}

void pengo_animate(void) 
{
	next_anirate();
	if (current_proc->pdata.p_anicount==1)
		rsnd_small_block();
	return;
}

void r_egg(void) 
{
	death_scream;
	set_inviso(current_proc->pa8);
//	current_proc->pa8=current_proc->pdata.p_otherguy;
	create_fx(FX_SWAT_BEXP);
	current_proc->pa8=(OBJECT*)current_proc->a11;
	white_flash();
	wait_forever();
}

//******************************************************************************
//******************************************************************************
void reptile_monkey(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	cute_animality_start();
	current_proc->a11=(ADDRESS)current_proc->pa8;

	get_char_ani(ANIM_TABLE1,ANIM_NJ_MONKEY);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	a8_front_plus_1(obj);

	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	ground_a8();
	insert_object(obj,&objlst);

	takeover_him(r_scared_of_monkey);
	process_sleep(0x50);

	set_vel_flip(SCX(0x40000));

	get_char_ani(ANIM_TABLE1,ANIM_NJ_MONKEY);
	tsound(0xb3);

	current_proc->a10=20;
	/* monk5 */
	do
	{
		frame_a9(obj);
		process_sleep(4);
	}
	while(--current_proc->a10>0);

	death_blow_complete();

	/* monk6 */
	current_proc->a10=40;
	do
	{
		frame_a9(obj);
		process_sleep(4);
	}
	while(--current_proc->a10>0);

	wait_forever();
}

void set_vel_flip(long pa0) 
{
	if ((current_proc->pa8)->oflags & M_FLIPH)
		pa0=-pa0;

	(current_proc->pa8)->oxvel.pos=pa0;

	return;
} 

void r_scared_of_monkey(void) 
{
	center_around_me();
	death_scream;
	face_opponent(current_proc->pa8);
	pose_a9(0,ANIM_SCARED);

	shake_a8_up(current_proc->pa8,3,0,3,8);
	process_sleep(20);

	flip_multi(current_proc->pa8);
	kill_and_stop_scrolling();
	sans_repell_for_good();
	no_edge_both_players();

	away_x_vel(current_proc,current_proc->pa8,SCX(0x80000));

	get_char_ani(ANIM_TABLE1,ANIM_RUN);
	init_anirate(3);
	current_proc->a10=0x50;
	/* cross3 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--current_proc->a10>0);

	stop_me(current_proc->pa8);
	wait_forever();
}

//******************************************************************************
//******************************************************************************
void ermac_frog(void)
{
	ADDRESS animframe;
	OBJECT *obj;
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	sans_repell_for_good();
	cute_animality_start();

	current_proc->a11=(ADDRESS)current_proc->pa8;		// create cute frog
	get_char_ani(ANIM_TABLE1,ANIM_NJ_FROG);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	ground_a8();
	insert_object(obj,&objlst);

	tsound(0xb4);
	current_proc->pdata.p_store1=(ADDRESS)current_proc->pa9;		// ribit
	framew(4);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(4);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(4);
	
	tsound(0xb4);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(4);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(4);
	obj->ozval=FRONT_Z+1000;							   
	framew(4);
	find_ani_part_a14(ANIM_NJ_FROG,3);
	takeover_him(eaten_by_snake);

	shake_a11(0xa,0xa);

	framew(5);

	process_sleep(0x20);

	death_blow_complete();

	/* ribit forever */
	while (1)
	{
		tsound(0xb4);
		(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
		framew(5);
		(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
		framew(5);
		(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
		framew(5);
	}
}

//******************************************************************************
//******************************************************************************
void jade_kitty(void) 
{
	ADDRESS animframe;
	OBJECT *obj;

	sans_repell_for_good();
	cute_animality_start();

	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_KITTY);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);

	multi_adjust_xy(obj,SCX(0x4b+10),0);
	a8_front_plus_1(obj);
	ground_a8();
	insert_object(obj,&objlst);

	current_proc->pdata.p_store1=(ADDRESS)current_proc->pa9;
	framew(3);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(3);

	tsound(0x92);			
	framew(3);

	current_proc->a11=(ADDRESS)current_proc->pa9;
	framew(3);

	takeover_him(hair_spin);
	kitty_spin();
	kitty_spin();
	kitty_spin();
	
	process_sleep(0x10);
	framew(3);
	(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
	framew(5);
	death_blow_complete();

	/* wiggle_forever */
	while (1)
	{
		(ADDRESS)current_proc->pa9=current_proc->pdata.p_store1;
		framew(5);
	}
}

void kitty_spin(void) 
{
	(ADDRESS)current_proc->pa9=current_proc->a11;
	framew(5);
	return;
}

void cute_animality_start(void) 
{
	face_opponent(current_proc->pa8);
	animality_tune();
	process_sleep(0x20);
	tsound(0x8c);				
	current_proc->a10=(ADDRESS)current_proc->pa8;
	create_fx(FX_INVISO_POOF);
	process_sleep(8);
	set_inviso(current_proc->pa8);
	return;
}

//******************************************************************************
//******************************************************************************
void r_scared_of_porc(void)
{
	scared_pose();
	process_sleep(10);

	shake_a8_up(current_proc->pa8,7,7,3,8);

	/* hit by nails */
	CREATE(PID_BLOOD,nails_blood_spawner);
	shake_a11(6,0x10);

	shake_a8_up(current_proc->pa8,4,0,3,3);

//	away_x_vel(current_proc,current_proc->pa8,SCX(0x40000));
	set_noedge(current_proc->pa8);
	kill_and_stop_scrolling();
	shake_a8_up(current_proc->pa8,0x4,0,3,10);
	stop_me(current_proc->pa8);
	set_inviso(current_proc->pa8);
	create_fx(FX_SWAT_BEXP);
	wait_forever();
}


void needle_proc(void)
{
	OBJECT *obj;
	void *animframe;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	find_ani_part_a14(ANIM_NJ_PORCUPINE,5);

	animframe=(void*)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT *)current_proc->a10);
	if (((OBJECT*)current_proc->a10)->oflags & M_FLIPH)
		adjust_xy_a5(obj,-SCX(0x18),12);
	else adjust_xy_a5(obj,SCX(0x18),12);
	a8_front_plus_1(obj);
	insert_object(obj,&objlst);

	set_proj_vel(obj,-SCX(0xc0000),-1);
	obj->oyvel.pos=-(long)randu(SCY(0x50000));

	/* nail3 */
	do
	{
		process_sleep(1);
	}
	while(abs(((OBJECT*)current_proc->a11)->oxpos.u.intpos-obj->oxpos.u.intpos)>SCX(15));

	if (random() & 0x80000000)
		rsnd_stab();

	/* nail5 */
	stop_a8(obj);

	current_proc->a10=20;
	/* nail4 */
	do
	{
		process_sleep(1);
//		obj->oxpos.u.intpos=((OBJECT*)current_proc->a11)->oxpos.u.intpos;
//		multi_adjust_xy(obj,0,18);
	}
	while(--current_proc->a10>0);
	delobjp(obj);
	process_suicide();
}

void needle_spawn_proc(void)
{
	current_proc->a10=30;
	do
	{
		CREATE(PID_BLOOD,needle_proc);
		process_sleep(1);
		CREATE(PID_BLOOD,needle_proc);
		process_sleep(1);
		rsnd_small_block();
	}
	while(--current_proc->a10>0);

	process_suicide();
}

void osm_porcupine(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	void *heap;
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	sans_repell_for_good();
	cute_animality_start();

	current_proc->a11=(ADDRESS)current_proc->pa8;		// create cute porcupine
	get_char_ani(ANIM_TABLE1,ANIM_NJ_PORCUPINE);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);

	ground_a8();
	insert_object(obj,&objlst);
	
	process_sleep(0x16);
	
	/* look reverse and get ready to launch */
	framew(7);
	framew(7);
	flip_single(obj);
	
	/* situp */
	takeover_him(r_scared_of_porc);
	framew(5);
	process_sleep(0x20);
	
	/* pose for attack */
	framew(5);
	CREATE(PID_BLOOD,needle_spawn_proc)->a11=(ADDRESS)current_proc->pdata.p_otherguy;
	
	process_sleep(0x90);
	
	find_ani_part_a14(ANIM_NJ_PORCUPINE,6);
	framew(5);
	
	animality_complete(1);
}

//******************************************************************************
//******************************************************************************
void eel_scared(void) 
{
	short ta11;
	
	death_scream;
	
	get_char_ani(ANIM_TABLE1,ANIM_SCARED);
	do_next_a9_frame(current_proc->pa8);
	
	ta11=15;
	while (--ta11!=0)
	{
		borrow_ochar_sound(5,FT_RAYDEN);
		
		adjust_xy_a5(current_proc->pa8,4,0);
		process_sleep(3);
		adjust_xy_a5(current_proc->pa8,-4,0);
		process_sleep(3);
		player_froze_pal();
		adjust_xy_a5(current_proc->pa8,4,0);
		process_sleep(3);
		adjust_xy_a5(current_proc->pa8,-4,0);
		process_sleep(3);
		player_normpal();
	}
	
	stack_jump(collapse_on_ground);
}

void rayden_eel(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	OBJECT *pa8=current_proc->pa8;
	WORD ta11;
	short x,y;
	short xdist;
	WORD ochar=(current_proc->pdata.p_otherguy)->ochar;
	
	sans_repell_for_good();
	cute_animality_start();
	
	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_EEL);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);
	adjust_xy_a5(obj,-16,0);
	ground_a8();
	insert_object(obj,&objlst);
	
	framew(4);
	
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_EEL);
	find_part2();

	set_proj_vel(obj,SCX(0x30000),4);
	xdist=(obj->oxvel.pos>0)?64:48;
	do
	{
		next_anirate();
		process_sleep(1);
	}
	while(get_x_dist>xdist);
	
	stop_a8(obj);
	
	/*raise head */
	find_ani2_part_a14(ANIM_RAIDEN_EEL,3);
	frame_a9(obj);
	process_sleep(0x20);
	frame_a9(obj);
	process_sleep(8);
	
	/* attack */
	lineup_1pwm(obj,current_proc->pdata.p_otherguy);
	x=(obj->osize.u.xpos-(current_proc->pdata.p_otherguy)->osize.u.xpos);
	y=(obj->osize.u.ypos-(current_proc->pdata.p_otherguy)->osize.u.ypos)/2;
	
	switch (ochar)
	{
		case FT_JADE:
		case FT_MILEENA:
		case FT_KITANA:
		case FT_JCAGE:
		case FT_SWAT:
		case FT_LIA:
		case FT_SCORPION:
		case FT_REPTILE:
		case FT_ERMAC:
		case FT_OLDSZ:
		case FT_OLDSMOKE:
		case FT_NOOB:
		case FT_RAIN:
			adjust_xy_a5(obj,-x-9,-y);
			break;
		case FT_SG:
			adjust_xy_a5(obj,-x-28,-y);
			break;
		case FT_ST:
			adjust_xy_a5(obj,-x,-y-5);
			break;
		default:
			adjust_xy_a5(obj,-x-24,-y);
			break;
	}
	
	obj->ozval=566;
	
	
	takeover_him(eel_scared);
	
	flip_single(obj);
	find_ani2_part_a14(ANIM_RAIDEN_EEL,4);
	framew(4);
	find_ani2_part_a14(ANIM_RAIDEN_EEL,4);
	framew(4);
	find_ani2_part_a14(ANIM_RAIDEN_EEL,4);
	framew(4);
	
	get_char_ani(ANIM_TABLE2,ANIM_RAIDEN_EEL);
//	flip_single(obj);
	ground_a8();
	adjust_xy_a5(current_proc->pa8,-55,16);
	framew(4);
	
	animality_complete(1);
}

//******************************************************************************
//******************************************************************************
void kitana_bunny(void) 
{
	ADDRESS animframe;
	OBJECT *obj;
	OBJECT *pa8=current_proc->pa8;

	sans_repell_for_good();
	cute_animality_start();

	current_proc->a11=(ADDRESS)current_proc->pa8;
	get_char_ani(ANIM_TABLE2,ANIM_BUNNY);
	animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,GET_LONG(current_proc->pa9));
	gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
	alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
	lineup_1pwm(obj,(OBJECT*)current_proc->a11);

	ground_a8();
	insert_object(obj,&objlst);
	
	framew(8);
	framew(3);
	tsound(0x92);			

	a8_front_plus_1(obj);
	obj->oyvel.pos=-SCY(0x80000);
	set_proj_vel(obj,SCX(0x60000),-1);
	process_sleep(9);

	kill_and_stop_scrolling();
	stop_a8(obj);

	takeover_him(r_rabbit);

	init_anirate(4);
	current_proc->a10=(ADDRESS)current_proc->pdata.p_otherguy;

	current_proc->a11=0x40*3;
	/* bunny5 */
	do
	{
		process_sleep(1);
		obj->oxvel.pos=((OBJECT*)current_proc->a10)->oxvel.pos;
		next_anirate();
	}
	while(--current_proc->a11>0);

	obj->oxvel.pos=0;

	current_proc->a11=(ADDRESS)current_proc->pa8;
	current_proc->pa8=pa8;
	pa8->oxpos.u.intpos=((OBJECT *)current_proc->a11)->oxpos.u.intpos;

	delobjp(obj);

	death_blow_complete();
	player_normpal();
	wait_forever();
}

void r_rabbit(void) 
{
	find_ani_part2(ANIM_STUMBLE);
	init_anirate(4);
	set_noedge(current_proc->pa8);

	death_scream;
	face_opponent(current_proc->pa8);
	away_x_vel(current_proc,current_proc->pa8,SCX(0x30000));

	CREATE(PID_FX,crunch_sounds);
	current_proc->a10=0x40*5;
	current_proc->pdata.p_store1=1;
	/* rrab4 */
	do
	{
		process_sleep(1);
		next_anirate();

		if (--current_proc->pdata.p_store1==0) 
		{
			create_blood_proc(BLOOD_HAT);
			current_proc->pdata.p_store1=5;
		}
	}
	while(--current_proc->a10>0);
	stop_me(current_proc->pa8);
	wait_forever();
}

void crunch_sounds(void) 
{
	current_proc->a10=6;
	do
	{
		tsound(0x24);			
		tsound(0x25);
		process_sleep(0x10);
	}
	while(--current_proc->a10>0);

	process_suicide();
}

/******************************************************************************
 Function: void cyrax_shark(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   cyrax shark
******************************************************************************/
void cyrax_shark(void)
{
	void *heap;
	
	animality_tune();

	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_R2_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);
	
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_SHARK);
	animal_morph(18);

	sans_repell_for_good();
	kill_and_stop_scrolling();

	towards_x_vel(current_proc,current_proc->pa8,SCX(0xa0000));
	process_sleep(8);
	kill_repell;
	set_noedge(current_proc->pa8);
	process_sleep(0x50-8);

	tsound(0x92);                           
	stop_me(current_proc->pa8);
	match_me_with_him();
	ground_player(current_proc->pa8);
	a8_back_minus_1(current_proc->pa8);
	mframew(7);

	takeover_him(eaten_by_shark);
	shake_a11(0xa,0xa);

	process_sleep(4);
	mframew(3);
	set_inviso(current_proc->pa8);
	process_sleep(0x30);
	clear_inviso(current_proc->pa8);

	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_ROBO_SHARK);
//	backwards_ani(5,0xffff);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(0);
}

void eaten_by_shark(void)
{
	death_scream;
	create_fx(FX_STAND_BLOOD);
	process_sleep(6);
create_fx(FX_STAND_BLOOD);
	process_sleep(6);
	create_fx(FX_STAND_BLOOD);
	process_sleep(6);

	eaten_by_snake();
}

void eaten_by_snake(void)
{
	tsound(0x24);
	tsound(0x25);                   // crunchy
	shake_a11(0xa,0xa);

	set_inviso(current_proc->pa8);
	wait_forever();
}

/******************************************************************************
 Function: void lao_cheetah(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   lao cheetah
******************************************************************************/
//extern void *a_cheetah[];
void lao_cheetah(void)
{
	animality_tune();
	get_char_ani(ANIM_TABLE2,ANIM_LAO_CHEETAH);
	animal_morph(18);

	sans_repell_for_good();
	process_sleep(0x18);

	tsound(0x95);				
	towards_x_vel(current_proc,current_proc->pa8,SCX(0x30000));
	mframew(7);

	takeover_him(lion_mauled);
	away_x_vel(current_proc->pdata.p_otherproc,current_proc->pdata.p_otherguy,SCX(0x20000));
	mframew(6);

	stop_me(current_proc->pa8);
	process_sleep(8);
	stop_him(current_proc->pdata.p_otherguy);

	animate_a0_frames(0x5,0x10);

	//current_proc->pa9=a_cheetah;
	get_char_ani(ANIM_TABLE2,ANIM_LAO_CHEETAH);
	find_part_a14(5);
	do_next_a9_frame(current_proc->pa8);
	wfe_him;
	process_sleep(0x28);

	//current_proc->pa9=a_cheetah;
	animality_complete(0);
}

/******************************************************************************
 Function: void liu_kang_dragon(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   lk dragon
******************************************************************************/
//extern void *a_dragon[];
void liu_kang_dragon(void)
{
	animality_tune();
	get_char_ani(ANIM_TABLE2,ANIM_LK_DRAGON);
	animal_morph(18);
	process_sleep(0x30);

	tsound(0x92);				
	mframew(4);
	takeover_him(bit_in_half);
	shake_a11(0xa,0xa);
	process_sleep(0x40);

	mframew(4);

	process_sleep(0x30);
	animality_complete(1);
}

/******************************************************************************
 Function: void shang_tsung_snake(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   st snake
******************************************************************************/
void shang_tsung_snake(void)
{
	void *heap;
	
	animality_tune();
	
	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_ST_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);
	
	get_char_ani(ANIM_TABLE1,ANIM_ST_SNAKE);
	animal_morph(18);
	a8_front_plus_1(current_proc->pa8);

	mframew(5);
	takeover_him(eaten_by_snake);
	shake_a11(0xa,0xa);

	process_sleep(0x20);

	mframew(5);

	process_sleep(0x40);
	
	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_ST_SNAKE);
//	backwards_ani(5,0xffff);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(1);
}

/******************************************************************************
 Function: void sheeva_scorpion(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   sheeva scorpion
******************************************************************************/
void sheeva_scorpion(void)
{
	animality_tune();
	get_char_ani(ANIM_TABLE2,ANIM_SG_SCORP);
	animal_morph(18);

	mframew(5);
	takeover_him(stung_by_scorpion);

	process_sleep(0x40*3);

//	tsound(0x27);
//	get_char_ani(ANIM_TABLE2,ANIM_SG_SCORP);
//	backwards_ani(5,0xffff);
	animality_complete(0);
}

WORD scorp_fade_tab[]={1,2,4,6,8,10,12,14,16,18,20,0xffff};

void stung_by_scorpion(void)
{
	face_opponent(current_proc->pa8);
	away_x_vel(current_proc,current_proc->pa8,SCX(0x40000));
	rsnd_stab();
	group_sound(2);
	animate_a9(5,ANIM_STUMBLE);

	/* now the poision sets in */
	stop_me(current_proc->pa8);
	death_scream;
	pose_a9(0,ANIM_SCARED);

	fade_this_pal((current_proc->pa8)->opal,6,3,scorp_fade_tab);

	shake_a8_up(current_proc->pa8,3,0,3,20);

	set_inviso(current_proc->pa8);
	create_fx(FX_LASER_EXPLODE);
	wait_forever();
}

/******************************************************************************
 Function: void kabal_skeleton(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   kabal skeleton
******************************************************************************/
void kabal_skeleton(void)
{
	void *heap;
	
	animality_tune();
	
	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_TUSK_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);
	
	get_char_ani(ANIM_TABLE1,ANIM_TUSK_SKEL);
	animal_morph(18);

	towards_x_vel(current_proc,current_proc->pa8,SCX(0x80000));
	mframew(4);

	takeover_him(dino_bucked);
	stop_me(current_proc->pa8);
	process_sleep(0x10);

	mframew(5);
	process_sleep(0x10);

	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_TUSK_SKEL);
//	backwards_ani(5,0xffff);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(1);
}

void dino_bucked(void)
{
	create_blood_proc(BLOOD_UPPERCUT);
	shake_a11(6,6);
	death_scream;
	rsnd_stab();

	flight(current_proc->pa8,SCX(0x30000),-SCY(0x150000),SCY(0x5000),4,ANIM_KDOWN);
	land_on_my_back();
}

/******************************************************************************
 Function: void sektor_bat(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   sektor bat
******************************************************************************/
void sektor_bat(void)
{
	void *heap;
	
	animality_tune();

	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_R1_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	center_around_him();

	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BAT);
	animal_morph(18);
	sans_repell_for_good();
	set_noedge(current_proc->pa8);

	init_anirate(4);

	ochar_sound(0x20);
	(current_proc->pa8)->ograv.pos=-SCY(0x2000);
	towards_x_vel(current_proc,current_proc->pa8,SCX(0x80000));
	animate_till_a11_stop(q_bat_1);

	stop_me(current_proc->pa8);
	match_me_with_him();
	flip_multi(current_proc->pa8);
	multi_adjust_xy(current_proc->pa8,-SCRRGT,-SCY(0x40));

	ochar_sound(0x20);
	towards_x_vel(current_proc,current_proc->pa8,SCX(0xa0000));
	animate_till_a11(q_bat_2);

	takeover_him(r_bat_bite);
	(long)(current_proc->pdata.p_otherproc)->pdata.p_store1=(current_proc->pa8)->oxvel.pos;
	animate_till_a11(q_bat_3);
	process_sleep(0x40);

	/* land/unmorph */
	stop_me(current_proc->pa8);
	match_me_with_him();
	flip_multi(current_proc->pa8);
	multi_adjust_xy(current_proc->pa8,-SCX(0x60),-SCRBOT);
	(current_proc->pa8)->oyvel.pos=SCY(0x50000);
	animate_till_a11_stop(q_bat_4);

	ground_player(current_proc->pa8);
	
	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BAT);
//	backwards_ani(5,0xffff);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(0);
}

WORD q_bat_4(void)
{
	if (distance_off_ground(current_proc,current_proc->pa8)>3)
		q_no;
	else q_yes;
}

WORD q_bat_3(void)
{
	if (get_x_dist<SCX(0x100)+35)
		q_no;
	else q_yes;
}

WORD q_bat_2(void)
{
	if (get_x_dist>SCX(0x20))
		q_no;
	else q_yes;
}

WORD q_bat_1(void)
{
	if (get_x_dist<SCX(0x100)+25)
		q_no;
	else q_yes;
}

void r_ermac_upcut(void) 
{
	shake_a11(8,8);
	rsnd_big_smack();
	create_blood_proc(BLOOD_UPPERCUT);
	cutup_body_init();

	head_pop_off(SCX(0x10000),-SCY(0x80000));
}

void r_bat_bite(void)
{
	shake_a11(6,8);
	rsnd_stab();
	create_blood_proc(BLOOD_UPPERCUT);
	cutup_body_init();
	head_pop_off(SCX(0x10000),-SCY(0x20000));
}

void cutup_body_init(void)
{
	ADDRESS animframe,ta0;
	OBJECT *obj,*oa9;

	death_scream;

	current_proc->a10=(ADDRESS)current_proc->pa8;
	set_inviso(current_proc->pa8);
	
	get_char_ani(ANIM_TABLE1,ANIM_OCHAR_CUTUP);
	
	current_proc->pdata.p_store2=(ADDRESS)obj_free;
	setup_body_pieces();
	
	return;
}

void setup_body_pieces(void) 
{
	ADDRESS animframe,ta0;
	OBJECT *obj,*oa9;

	ta0=current_proc->pa9;
	(ADDRESS)oa9=(ADDRESS)obj_free;

	current_proc->a11=10;
	/* bb3 */
	do
	{
		animframe=GET_LONG(ta0)++;
		if ( animframe==0 )
			break;

		animframe=(ADDRESS)COMPUTE_ADDR((current_proc->pa8)->oheap,animframe);
		gso_dmawnz(obj,(ADDRESS)animframe,(current_proc->pa8)->odict,(current_proc->pa8)->oheap,0);
		alloc_cache((OIMGTBL *)animframe,(current_proc->pa8)->oheap,obj);
		cutup_correct_pal();

		(ADDRESS)oa9->oslink=(ADDRESS)obj;
		oa9=obj;

		lineup_1pwm(obj,(OBJECT*)current_proc->a10);
		insert_object(obj,&objlst);
		obj->ozval=current_proc->a11;
		current_proc->a11--;

	} while (1);
	
	return;
}

void head_pop_off(long pa0,long pa1) 
{
	current_proc->pa8=(OBJECT *)current_proc->pdata.p_store2;
	if ((current_proc->pa8)->oflags & M_FLIPH)
		pa0=-pa0;

	(current_proc->pa8)->oxvel.pos=pa0;
	(current_proc->pa8)->ozval+=FRONT_Z;		// fix

	gravity_ani_ysize(pa1,SCY(0x6000));
	rsnd_stab();

	gravity_ani_ysize(-SCY(0x20000),SCY(0x6000));
	rsnd_stab();

	wait_forever();
}

void animate_till_a11_stop(FUNCW pa11)
{
	animate_till_a11(pa11);
	stop_me(current_proc->pa8);
	return;
}

void animate_till_a11(FUNCW pa11)
{
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(pa11()==SYSTEM_CARRY_CLR);

	return;
}

/******************************************************************************
 Function: void smoke_bull_shit(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   smoke bull
******************************************************************************/
void smoke_bull_shit(void)
{
	void *heap;
	
	animality_tune();

	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_R3_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BULL);
	animal_morph(18);

	sans_repell_for_good();
	kill_and_stop_scrolling();
	towards_x_vel(current_proc,current_proc->pa8,SCX(0xa0000));
	process_sleep(1);
	kill_repell;

	init_anirate(4);

	/* bull4 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(get_x_dist>SCX(0x60));

	//current_proc->pa9=a_bull;
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BULL);
	find_part2();
	do_next_a9_frame(current_proc->pa8);
	stop_me(current_proc->pa8);
	shake_a11(0xa,0xa);

	takeover_him(hit_by_bull);

	process_sleep(0x60);

	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BULL);
//	backwards_ani(5,0xffff);
	
	get_char_ani(ANIM_TABLE1,ANIM_ROBO_BULL);
	do_next_a9_frame(current_proc->pa8);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(1);
}

void hit_by_bull(void)
{
	create_blood_proc(BLOOD_UPPERCUT);
	shake_a11(0x6,0x6);
	death_scream;
	rsnd_stab();

	set_noedge(current_proc->pa8);

	away_x_vel(current_proc,current_proc->pa8,SCX(0x130000));
	if ( current_proc->pa8==p1_obj )
		(current_proc->pa8)->oxvel.pos=p1_xvel.pos;
	else (current_proc->pa8)->oxvel.pos=p2_xvel.pos;

	flight(current_proc->pa8,DONT_TOUCH,-SCY(0x80000),SCY(0x6000),4,ANIM_KDOWN);
	shake_n_sound();

	shake_on_my_back(3,1);

	process_sleep(4);
	wait_forever();
}

/******************************************************************************
 Function: void sindel_wasp(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   sindel wasp
******************************************************************************/
void sindel_wasp(void)
{
	void *heap;
	
	animality_tune();

	/* load data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_LIA_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	sans_repell_for_good();

	get_char_ani(ANIM_TABLE1,ANIM_LIA_WASP);
	animal_morph(10);

	animate_a0_frames(0x3,0x10);
	takeover_him(stung_a_bunch);
	face_him_at_me();

	match_me_with_him();
	flip_multi(current_proc->pa8);
	multi_adjust_xy(current_proc->pa8,-SCX(0x28),-SCY(0x48));

	kill_and_stop_scrolling();

	no_edge_both_players();
	away_x_vel(current_proc->pdata.p_otherproc,current_proc->pdata.p_otherguy,SCX(0x30000));
	towards_x_vel(current_proc,current_proc->pa8,SCX(0x30000));

	get_char_ani(ANIM_TABLE1,ANIM_LIA_WASP);
	find_part2();
	find_part2();
	animate_a0_frames(4,0x1a);

	set_inviso(current_proc->pdata.p_otherguy);
	stop_me(current_proc->pa8);
	process_sleep(0x40);
	death_blow_complete();
	dallprc(PID_REPELL);

	player_normpal();

	pose_a9(0,ANIM_STANCE);
	ground_ochar();
	(current_proc->pa8)->oypos.u.intpos+=SCY(0x90);
	(current_proc->pa8)->oxpos.u.intpos=worldtlx.u.intpos+SCX(0x60);

	(current_proc->pa8)->oyvel.pos=-SCY(0x20000);

	(current_proc->pa8)->oheap=heap;		// restore heap
	
	stack_jump(victory_animation);
}

void stung_a_bunch(void)
{
	process_sleep(8);
	death_scream;
	do
	{
		animate_a9(3,ANIM_HITHI);
	}
	while(1);
}

/******************************************************************************
 Function: void swat_dino(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   swat dinosaur
******************************************************************************/
void swat_dino(void)
{
	animality_tune();

	get_char_ani(ANIM_TABLE2,ANIM_SWAT_DINO);
	animal_morph(18);
	sans_repell_for_good();

	tsound(0x92);				
	process_sleep(0x30);

	mframew(5);
	shake_a11(0x8,0x8);
	takeover_him(bit_in_half);
	tsound(0x24);
	tsound(0x25);

	process_sleep(0x30);

	mframew(5);

//	tsound(0x27);
	ground_player(current_proc->pa8);
//	get_char_ani(ANIM_TABLE2,ANIM_SWAT_DINO);
//	backwards_ani(5,0xffff);
	animality_complete(1);
}

void bit_in_half(void)
{
	ADDRESS *animframe;

	shake_a11(0x6,0x6);
	death_scream;
	rsnd_stab();
	create_blood_proc(BLOOD_DINO_BLOOD);
	
	cutup_body_init();
	set_inviso((OBJECT *)current_proc->pdata.p_store2);		// no head
	set_inviso((OBJECT *)((OBJECT *)current_proc->pdata.p_store2)->oslink);		// no torso
	wait_forever();
}

#if 1
/******************************************************************************
 Function: void sz_polar(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   subzero polar
******************************************************************************/
void sz_polar(void)
{
	void *heap;
	
	animality_tune();

	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_NJ_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	get_char_ani(ANIM_TABLE1,ANIM_NJ_POLAR);
	animal_appear();
	process_sleep(18);
	
	get_char_ani(ANIM_TABLE1,ANIM_NJ_POLAR);
	find_part2();
	
	sans_repell_for_good();
	process_sleep(0x30);

	tsound(0x95);					
	towards_x_vel(current_proc,current_proc->pa8,SCX(0x20000));
	mframew(5);

	takeover_him(lion_mauled);
	stop_me(current_proc->pa8);
	stop_him(current_proc->pdata.p_otherguy);

	animate_a0_frames(0x5,0x20);
	wfe_him;
	process_sleep(8);

//	tsound(0x27);
	ground_player(current_proc->pa8);
	
	/* unmorph */
//	get_char_ani(ANIM_TABLE1,ANIM_NJ_POLAR);
//	backwards_ani(5,0xffff);
	
	/* restore heap */
	(current_proc->pa8)->oheap=heap;
	
	animality_complete(0);
	
}
#endif

/******************************************************************************
 Function: void kano_spider(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   kano spider
******************************************************************************/
void kano_spider(void)
{
	OBJECT *obj;

	wfe_him;
	pose_him_a9(0,ANIM_SCARED);
	face_him_at_me();

	animality_tune();

	get_char_ani(ANIM_TABLE2,ANIM_KANO_SPIDER);
	animal_morph(0x40);
	sans_repell_for_good();
	tsound(0x26);

	mframew(5);

//	if ((current_proc->pdata.p_otherguy)->ochar==FT_SG)
	{
		multi_adjust_xy(current_proc->pa8,SCX(0x20),0); // nudfe for sheeva
	}

	/* spid3 */
	obj=current_proc->pa8;
	current_proc->pa8=current_proc->pdata.p_otherguy;
	create_blood_proc(BLOOD_SPIDER);
	current_proc->pa8=obj;

	takeover_him(spider_shake);
	spider_shake_jsrp();

	get_char_ani(ANIM_TABLE2,ANIM_KANO_SPIDER);
	find_part_a14(3);
	mframew(5);

	takeover_him(collapse_on_ground);
	process_sleep(0x30);
//	tsound(0x27);
//	mframew(5);	// remove morph back
	animality_complete(1);
}

void spider_shake(void)
{
	spider_shake_jsrp();
	wait_forever();
}

void spider_shake_jsrp(void)
{
	shake_a8_up(current_proc->pa8,6,0,3,16);
	return;
}

/******************************************************************************
 Function: void sonya_eagle(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   sonya eagle
******************************************************************************/
void sonya_eagle(void)
{
	PROCESS *ptemp;

	animality_tune();

	//current_proc->pa9=a_sonya_hawk;
	get_char_ani(ANIM_TABLE2,ANIM_SONYA_HAWK);	

	animal_morph(1);
	sans_repell_for_good();

	init_anirate(5);
	(current_proc->pa8)->ograv.pos=-SCY(0x2000);
	/* eagle3 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(distance_off_ground(current_proc,current_proc->pa8)<SCY(0x38));

	stop_me(current_proc->pa8);

	/* eagle5 */
	do
	{
		process_sleep(1);
		towards_x_vel(current_proc,current_proc->pa8,SCX(0xa000));
		next_anirate();
	}
	while(get_x_dist>SCX(8));

	stop_me(current_proc->pa8);
	next_anirate_a10(0x30);

	(current_proc->pa8)->ograv.pos=-SCY(0x10000);
	(current_proc->pdata.p_otherguy)->ograv.pos=-SCY(0x10000);

	next_anirate_a10(0x18);
	stop_me(current_proc->pa8);
	stop_him(current_proc->pdata.p_otherguy);

	/* calla_for_him (death_scream */
	ptemp=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	death_scream;
	current_proc=ptemp;

	process_sleep(0x30);

	ptemp=create_fx_for_him(FX_SONYA_ANIMIAL);
	ptemp->pdata.p_otherguy=current_proc->pa8;
	ptemp->pdata.p_otherproc=current_proc;

	shake_a11(0x8,0xc);
	tsound(0x24);
	tsound(0x25);
	process_sleep(0x20);

	tsound(0x24);
	tsound(0x25);
	process_sleep(0x10);
	animality_complete(1);
}

void vulture_rip(void) 
{
	OBJECT *obj=current_proc->pdata.p_otherguy;
	OBJECT *head,*torso;

	current_proc->pdata.p_store1=0;
	shake_a11(0x6,0x6);
	death_scream;
	tsound(0x24);
	tsound(0x25);
	create_blood_proc(BLOOD_DINO_BLOOD);
	
	cutup_body_init();
	head=((OBJECT *)current_proc->pdata.p_store2);		// no head
	torso=((OBJECT *)((OBJECT *)current_proc->pdata.p_store2)->oslink);		// no torso
	
	head->oyvel.pos=0;
	torso->oyvel.pos=0;
	
	while (current_proc->pdata.p_store1==0)
	{
		head->oyvel.pos+=obj->ograv.pos;
		torso->oyvel.pos+=obj->ograv.pos;
		head->oypos.pos+=head->oyvel.pos;
		torso->oypos.pos+=torso->oyvel.pos;
		process_sleep(1);
	}
	
	process_sleep(0x30);
	current_proc->pa8=head;
	ground_y-=head->osize.u.ypos;
	init_anirate(5);
	head_grav(SCY(0x60000),SCX(0x8000));
	head_grav(-SCY(0x60000),SCX(0x6000));
	head_grav(-SCY(0x40000),SCX(0x4000));
	head_grav(-SCY(0x20000),SCX(0x4000));
	wait_forever();
}

void baraka_vulture(void)
{
	PROCESS *ptemp;

	animality_tune();

	get_char_ani(ANIM_TABLE2,ANIM_BARAKA_VULTURE);
	find_part2();
	animal_appear();
	
	get_char_ani(ANIM_TABLE2,ANIM_BARAKA_VULTURE);
	sans_repell_for_good();

	init_anirate(5);
	(current_proc->pa8)->ograv.pos=-SCY(0x2000);
	/* eagle3 */
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(distance_off_ground(current_proc,current_proc->pa8)<SCY(0x30));

	(current_proc->pa8)->ograv.pos=SCY(0x000);
	stop_me(current_proc->pa8);

	/* eagle5 */
	do
	{
		process_sleep(1);
		towards_x_vel(current_proc,current_proc->pa8,SCX(0xa000));
		next_anirate();
	}
	while(get_x_dist>SCX(16));

	stop_me(current_proc->pa8);
	next_anirate_a10(0x30);

	(current_proc->pa8)->ograv.pos=-SCY(0x10000);
	(current_proc->pdata.p_otherguy)->ograv.pos=-SCY(0x10000);
	takeover_him(vulture_rip);

	next_anirate_a10(0x18);
	stop_me(current_proc->pa8);
	stop_him(current_proc->pdata.p_otherguy);
	(current_proc->pdata.p_otherproc)->pdata.p_store1=1;

	/* calla_for_him (death_scream */
	process_sleep(0x30);
	process_sleep(0x20);
#if 0
	ptemp=create_fx_for_him(FX_SONYA_ANIMIAL);
	ptemp->pdata.p_otherguy=current_proc->pa8;
	ptemp->pdata.p_otherproc=current_proc;

	shake_a11(0x8,0xc);
	tsound(0x24);
	tsound(0x25);
	process_sleep(0x20);

	tsound(0x24);
	tsound(0x25);
	process_sleep(0x10);
#endif	
	animality_complete(1);
}

/******************************************************************************
 Function: void jax_lion(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   jax lion
******************************************************************************/
void jax_lion(void)
{
	animality_tune();

	//current_proc->pa9=a_jax_lion;
	get_char_ani(ANIM_TABLE2,ANIM_JAX_LION);
	animal_morph(18);
	sans_repell_for_good();
	process_sleep(0x30);

	towards_x_vel(current_proc,current_proc->pa8,SCX(0x20000));
	mframew(5);

	takeover_him(lion_mauled);

	stop_me(current_proc->pa8);
	stop_him(current_proc->pdata.p_otherguy);

	animate_a0_frames(0x5,0x20);
	wfe_him;
	process_sleep(8);

//	tsound(0x27);
//	get_char_ani(ANIM_TABLE2,ANIM_JAX_LION);
//	backwards_ani(5,0xffff);

	animality_complete(0);
}

void lion_mauled(void)
{
	death_scream;
	face_opponent(current_proc->pa8);
	animate_a9(3,ANIM_KDOWN);
	mframew(3);

	/* maul3 */
	do
	{
		create_blood_proc(BLOOD_LION);
		death_scream;
		tsound(0x24);
		shake_a8_up(current_proc->pa8,3,0,3,5);

		create_blood_proc(BLOOD_LION);
		tsound(0x25);
		shake_a8_up(current_proc->pa8,5,0,3,3);
	}
	while(1);
}

/******************************************************************************
 Function: void indian_wolf(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   jax lion
******************************************************************************/
void indian_wolf(void)
{
	void *heap;
	
	animality_tune();

	/* load texture data */
	heap=(current_proc->pa8)->oheap;		// save heap
	(current_proc->pa8)->oheap=special_character_texture_load(SPEC_IND_ANIMAL,((current_proc->pa8)==p1_obj) ? 0:1);

	/* due move */
	get_char_ani(ANIM_TABLE1,ANIM_IND_WOLF);
	animal_morph(18);
	sans_repell_for_good();
	process_sleep(0x18);

	tsound(0x95);					
	towards_x_vel(current_proc,current_proc->pa8,SCX(0x20000));
	mframew(5);

	takeover_him(lion_mauled);
	away_x_vel(current_proc->pdata.p_otherproc,current_proc->pdata.p_otherguy,SCX(0x20000));

	animate_a0_frames(0x6,0x2);
	stop_me(current_proc->pa8);
	process_sleep(8);
	stop_him(current_proc->pdata.p_otherguy);

	animate_a0_frames(7,10);

	get_char_ani(ANIM_TABLE1,ANIM_IND_WOLF);
	find_part_a14(4);
	do_next_a9_frame(current_proc->pa8);
	wfe_him;
	process_sleep(0x28);

//	tsound(0x27);
//	get_char_ani(ANIM_TABLE1,ANIM_IND_WOLF);
//	backwards_ani(5,0xffff);

	(current_proc->pa8)->oheap=heap;		// restore heap for victory

	animality_complete(0);
}

/******************************************************************************
 Function: void next_anirate_a10(WORD pa10)

 By: David Schwartz

 Date: May 1995

 Parameters: pa10 - # of frames to animate

 Returns: None

 Description:   animate
******************************************************************************/
void next_anirate_a10(WORD pa10)
{
	do
	{
		process_sleep(1);
		next_anirate();
	}
	while(--pa10>0);

	return;
}

/******************************************************************************
 Function: void create_fx_for_him(WORD pa0)

 By: David Schwartz

 Date: May 1995

 Parameters: pa0 - fx #

 Returns: None

 Description:   set other dude fx
******************************************************************************/
PROCESS *create_fx_for_him(WORD pa0)
{
	OBJECT *ta8=current_proc->pa8;
	PROCESS *ptemp;

	current_proc->pa8=current_proc->pdata.p_otherguy;
	ptemp=create_fx(pa0);
	current_proc->pa8=ta8;

	return(ptemp);
}

/******************************************************************************
 Function: void unmorph_and_exit(void)

 By: David Schwartz

 Date: May 1995

 Parameters: None

 Returns: None

 Description:   revert to normal
******************************************************************************/
#if 0
void unmorph_and_exit(void)
{
//	backwards_ani(5,0xffff);
	animality_complete(0);
}
#endif
/******************************************************************************
 Function: void animal_morph(WORD pa10)

 By: David Schwartz

 Date: May 1995

 Parameters: pa10 -sleep time

 Returns: None

 Description:   change into the beast within
******************************************************************************/
void animal_morph(WORD pa10)
{
	ADDRESS *animframe;
	OBJECT *obj=current_proc->pa8;

	if (gstate!=GS_AMODE)
		process_sleep(0x20);

	tsound(0x8c);				
	current_proc->a10=(ADDRESS)current_proc->pa8;
	create_fx(FX_INVISO_POOF);
	process_sleep(0x8);

	animframe=(ADDRESS *)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9));
	animframe=(ADDRESS *)COMPUTE_ADDR(obj->oheap,GET_LONG(animframe));
	((OIMGTBL *)animframe)++;                               // get ptr palette
	player_swpal(current_proc,(void*)GET_LONG(animframe),current_proc->pa8);
	do_next_a9_frame(current_proc->pa8);
	process_sleep(0x10);

//	tsound(0x27);
	mframew(5);

	process_sleep(pa10);
	return;
}

void animal_appear(void)
{
	ADDRESS *animframe;
	OBJECT *obj=current_proc->pa8;

	if (gstate!=GS_AMODE)
		process_sleep(0x20);
	
	process_sleep(0x20);
	tsound(0x8c);				
	current_proc->a10=(ADDRESS)current_proc->pa8;
	create_fx(FX_INVISO_POOF);
	process_sleep(0x8);

	animframe=(ADDRESS *)COMPUTE_ADDR(obj->oheap,GET_LONG(current_proc->pa9));
	animframe=(ADDRESS *)COMPUTE_ADDR(obj->oheap,GET_LONG(animframe));
	((OIMGTBL *)animframe)++;                               // get ptr palette
	player_swpal(current_proc,(void*)GET_LONG(animframe),current_proc->pa8);
	do_next_a9_frame(current_proc->pa8);
	return;
}

void animality_tune(void)
{
	sound_music_start(MUSIC_ANIMALIT);

	return;
}

void animality_complete(WORD pa0)
{
	death_blow_complete();

	if (pa0==0)
	{
		player_normpal();
		stack_jump(victory_animation);
	}
	
	wait_forever();	
}

void face_him_at_me(void)
{
	PROCESS *ptemp;

	/* calla_for_him */
	ptemp=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	face_opponent(current_proc->pa8);
	current_proc=ptemp;

	return;
}

void kill_and_stop_scrolling(void)
{
	scrolly.pos=0;
	stop_scrolling();
	dallprc(PID_SCROLL);
	return;
}

void center_around_him(void)
{
	PROCESS *ptemp;

	/* calla_for_him */
	ptemp=current_proc;
	current_proc=current_proc->pdata.p_otherproc;
	center_around_me();
	current_proc=ptemp;

	return;
}

void ground_a8(void) 
{
	OBJECT *obj=current_proc->pa8;

	obj->oypos.u.intpos=ground_y-obj->osize.u.ypos-SCY(9);
	return;
}

