typedef struct brutalhdr 
{
	WORD	b_attack;		// AABB, AA=attack anim BB=ani part
	WORD	b_speed;		// CCDD, CC=Speed DD=BUTTON Search
	WORD	b_stk;			// EEFF, EE=stk routine FF=IGNORE
} BRUTAL;

extern BRUTAL brutal_kano[];
extern BRUTAL brutal_sonya[];
extern BRUTAL brutal_jax[];
extern BRUTAL brutal_indian[];
extern BRUTAL brutal_cage[];
extern BRUTAL brutal_swat[];
extern BRUTAL brutal_lia[];
extern BRUTAL brutal_robo1[];
extern BRUTAL brutal_robo2[];
extern BRUTAL brutal_lao[];
extern BRUTAL brutal_tusk[];
extern BRUTAL brutal_sg[];
extern BRUTAL brutal_st[];
extern BRUTAL brutal_lk[];
extern BRUTAL brutal_robo3[];
extern BRUTAL brutal_kit[];
extern BRUTAL brutal_jade[];
extern BRUTAL brutal_mil[];
extern BRUTAL brutal_scorp[];
extern BRUTAL brutal_rep[];
extern BRUTAL brutal_ermac[];
extern BRUTAL brutal_osz[];
extern BRUTAL brutal_osm[];
extern BRUTAL brutal_noob[];
extern BRUTAL brutal_rayden[];
extern BRUTAL brutal_baraka[];
extern BRUTAL brutal_rain[];
extern BRUTAL brutal_kamel[];

BRUTAL *brutal_table[]=
{
	brutal_kano,
	brutal_sonya,
	brutal_jax,
	brutal_indian,
	brutal_cage,

	brutal_swat,
	brutal_lia,
	brutal_robo1,
	brutal_robo2,
	brutal_lao,

	brutal_tusk,
	brutal_sg,
	brutal_st,
	brutal_lk,
	brutal_robo3,

	brutal_kit,
	brutal_jade,
	brutal_mil,
	brutal_scorp,
	brutal_rep,

	brutal_ermac,
	brutal_osz,
	brutal_osm,
	brutal_noob,
	brutal_rayden,
	
	brutal_baraka,
	brutal_rain,
	brutal_kamel,
	NULL,
	NULL,
	
	NULL,
	NULL,
	NULL,
};

void do_elbow(void)
{
	WORD pcombo;
	OBJECT *obj=current_proc->pa8;

	init_special(obj);
	
	pcombo=(obj==p1_obj)?f_opt_combo1:f_opt_combo2;

	if (ochar_elbow_animations[obj->ochar] & 0x80) 
		current_proc->pa9=get_char_ani(ANIM_TABLE2,ochar_elbow_animations[obj->ochar] & 0x7f);
	else current_proc->pa9=get_char_ani(ANIM_TABLE1,ochar_elbow_animations[obj->ochar] & 0x7f);

	if (striker(SI_STRIKER_NORMAL,1,ACT_ELBOW,0xffff,5,0xf)==SYSTEM_CARRY_SET)
	{
		if (winner_status==3 && am_i_joy()==SYSTEM_CARRY_SET)
		{
			if (brutal_table[obj->ochar]!=NULL)
				process_brutal_table(brutal_table[obj->ochar]);
			goto RETRACT;	
		}
			
		if (ochar_elbow_combos[obj->ochar]!=NULL && (!f_no_combos) && (pcombo!=0))
		{
			process_combo_table(ochar_elbow_combos[obj->ochar]);
		}
		else
		{
			/* elbow4 */
			current_proc->pdata.p_action=ACT_ELBOW_SD;
			process_sleep(10);
		}
	}

	/* elbow5 */
RETRACT:	
	retract_strike_act(ACT_ELBOW_SD,3);

	return;
}

void do_brutality(void) 
{
	OBJECT *obj=current_proc->pa8;
	
	if (brutal_table[obj->ochar]!=NULL)
		process_brutal_table(brutal_table[obj->ochar]);
	wait_forever();	
}

WORD retract_brutal(WORD pchar) 
{
	WORD retract;
	
	switch (pchar)
	{
		case FT_ERMAC:
		case FT_OLDSZ:
		case FT_REPTILE:
		case FT_RAIN:
		case FT_NOOB:
			retract=0x8002;
			break;
		case FT_MILEENA:
			retract=0x9302;
			break;
		default:
			retract=RETRACT_ELBOW;
	}
	
	return(retract);
}

WORD brutal_scan_a11(BRUTAL *btbl)
{
	WORD *cbutton;

	/* cscan1 */
	current_proc->a14=btbl->b_speed & 0x000f;		// this will be out "LAST" button

	cbutton=*(last_switch_ram+(current_proc->a14*2)+1);	// combo ram

	if (p2_obj==current_proc->pa8)
		cbutton++;						  

	/* comb5 */
	if (*cbutton!=0) 		// button presses since last sleep, combo time
	{
	
		/* make sure no other buttons pressed */
		current_proc->a2=0;
		current_proc->a1=(p1_obj==current_proc->pa8)?0:1;		// index into combo time ram

		/* loop unroll from arcade */
		if (c_hp[current_proc->a1] && current_proc->a10!=0)
			current_proc->a2++;
		if (c_lp[current_proc->a1] && current_proc->a10!=1)
			current_proc->a2++;
		if (c_block[current_proc->a1] && current_proc->a10!=2)
			current_proc->a2++;
		if (c_hk[current_proc->a1] && current_proc->a10!=3)
			current_proc->a2++;
		if (c_lk[current_proc->a1] && current_proc->a10!=4)
			current_proc->a2++;
			
		/* comb7, after loop */
		if (current_proc->a2>1)
			return(SYSTEM_CARRY_CLR);
		else return(SYSTEM_CARRY_SET);
	}

	/* cscan9 */
	return(SYSTEM_CARRY_CLR);
}

void process_brutal_table(BRUTAL *btbl)
{
	WORD results;
	WORD auto_flag=0;
	BRUTAL *restoretbl=btbl;
	WORD sleep;
	short xtest;
	
	clear_combo_butn();
	
	/* brutality start */
 	pose_a9(0,0);
	f_death=FAT_BRUTAL;
	
	/* process tables */
	current_proc->a10=0;			// previouis button offset
	current_proc->pdata.p_action=ACT_BRUTAL;			// define my action, brutal mode


COMB0:	/* comb0 */
	current_proc->a0=12;
	
	if (am_i_joy()==SYSTEM_CARRY_CLR || auto_flag!=0)
	{
		process_sleep(4);
	}
	else
	{
		/* combj */
		current_proc->pdata.p_anicount=current_proc->a0;
		process_sleep(3);

		current_proc->pdata.p_anicount-=3;

		/* comb1 */
		do
		{
			process_sleep(1);

			if ((results=brutal_scan_a11(btbl))==SYSTEM_CARRY_SET)
				goto COMB8;
		}
		while(--current_proc->pdata.p_anicount>0);

		if (results==SYSTEM_CARRY_SET)
			goto COMB8;					// !! SUCCESS
			
		goto BRUTAL_2_LATE;
	}

	/* success -> do next animation */
COMB8:
	if (is_he_airborn()==SYSTEM_CARRY_CLR)
		stop_him(current_proc->pdata.p_otherguy);		// he is airborn dont stop him

	/* comb2 */
	clear_combo_butn();

	current_proc->a10=current_proc->a14;		// save last button pushed

	/* comba */
	a9_combo_ani(btbl->b_attack);

	if (auto_flag==1)
		sleep=(btbl->b_speed)>>9;			// anim speed (double time)
	else sleep=(btbl->b_speed)>>8;			// anim speed
	if (sleep==0)
		sleep=1;
	
	xtest=(current_proc->pa8)->oxpos.u.intpos;
		
	mframew(sleep);	
	
	(current_proc->pa8)->oxpos.u.intpos-=((current_proc->pa8)->oxpos.u.intpos-xtest)/2;
	
	if (strike_check(combo_strike_table[(btbl->b_stk)>>8],0)==SYSTEM_CARRY_SET)
	{
		zero_turbo_bar();		// avoid sprint abuse
		
		(BRUTAL *)current_proc->a7=btbl;
		btbl++;
		
		if ((current_proc->pa8)->oflags & M_FLIPH)
			(current_proc->pa8)->oxpos.u.intpos-=4;
		else (current_proc->pa8)->oxpos.u.intpos+=4;

		if (btbl->b_attack!=0xffff) 
		{
			goto COMB0;
		}
		
		/* high speed brutaltity time */
		if (auto_flag==0) 
		{
			init_death_blow(FAT_BRUTAL);
			auto_flag++;
			btbl=restoretbl;
			goto COMB0;
		}
		
		/* do an uppercut */
		a9_combo_ani(0x0b01);
		rsnd_big_smack();
		mframew(2);

		/* end it all */
		takeover_him(r_ex2on2);
		process_sleep(0x12+0x40);
		
		a9_combo_ani(retract_brutal((current_proc->pa8)->ochar));
		mframew(4);
		
		process_sleep(0x8);
		sound_music_stop();
		death_blow_complete();
		
		stack_jump(victory_animation);
	}
	else
	{
		/* combo_miss */
		process_sleep(0x10);
	}

BRUTAL_2_LATE:
	process_sleep(3);
	takeover_him(rd_cacell_victum);
	a9_combo_ani(retract_brutal((current_proc->pa8)->ochar));
	mframew(4);
	
	/* abort brutality, reset whatever stuff */
	sound_music_stop();
	f_death=-1;
	process_sleep(1);
	f_death=0;
	
	process_sleep(0x30);
	stack_jump(victory_animation);
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


/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_kano
brutal_kano:
	.half	atk_elbow1
	.half	c_speed1|cb_lopunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed1|cb_block
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed1|cb_hikick
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed2|cb_lokick
	.half	stk_0

	.half	atk_lokick
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed3|cb_hikick
	.half	stk_0
		
	.half	atk_upcut
	.half	c_speed3|cb_lokick
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_sonya
brutal_sonya:
	.half	atk_elbow1
	.half	c_speed1|cb_lokick
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed1|cb_block
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_elbow4
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	0x1007
	.half	c_speed2|cb_lopunch
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed3|cb_lokick
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_jax
brutal_jax:
	.half	atk_elbow1
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed2|cb_block  
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	0x1006
	.half	c_speed3|cb_hipunch
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_hipunch
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed3|cb_hipunch
	.half	stk_1

	.half	atk_roundh
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_elbow1
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_indian
brutal_indian:
	.half	atk_elbow1
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_lopunch
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed3|cb_hipunch
	.half	stk_0
		
	.half	atk_upcut
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_cage
brutal_cage:
	.half	atk_elbow1
	.half	c_speed1|cb_lokick
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed1|cb_hikick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_1

	.half	atk_knee2
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_lopunch
	.half	stk_0
		
	.half	atk_knee2
	.half	c_speed3|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_swat
brutal_swat:
	.half	atk_elbow1
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_hikick 
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed3|cb_lopunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_lokick
	.half	c_speed2|cb_hikick
	.half	stk_0

	.half	atk_hikick
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed3|cb_lokick 
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_lokick
	.half	stk_1

	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_lia
brutal_lia:
	.half	atk_elbow1
	.half	c_speed1|cb_block
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_lokick
	.half	c_speed2|cb_hikick
	.half	stk_1

	.half	atk_elbow1
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed3|cb_lopunch
	.half	stk_1
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_robo1
brutal_robo1:
	.half	atk_elbow1
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed3|cb_lokick
	.half	stk_1

	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed3|cb_hipunch
	.half	stk_1
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_robo2
brutal_robo2:
	.half	atk_elbow2
	.half	c_speed1|cb_hikick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_hikick
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_hikick
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed3|cb_hipunch
	.half	stk_1

	.half	atk_knee1
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed3|cb_lopunch
	.half	stk_1
				 		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_lao
brutal_lao:
	.half	atk_elbow1
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_hikick
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_knee2
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_knee3
	.half	c_speed3|cb_lokick
	.half	stk_1

	.half	atk_elbow1
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_1
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_tusk
brutal_tusk:
	.half	atk_knee2
	.half	c_speed1|cb_block
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_elbow4
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed3|cb_lopunch
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_hipunch
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_sg
brutal_sg:
	.half	atk_elbow2
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_knee3
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_lokick
	.half	stk_1

	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow4
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	atk_knee2
	.half	c_speed3|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_st
brutal_st:
	.half	atk_elbow1
	.half	c_speed1|cb_block
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_elbow1
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_lopunch
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_0
		
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_lk
brutal_lk:
	.half	atk_lokick
	.half	c_speed2|cb_lopunch
	.half	stk_0
		
	.half	atk_hikick
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1

	.half	atk_upcut
	.half	c_speed2|cb_lokick
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_knee3
	.half	c_speed2|cb_lopunch 
	.half	stk_1
	
	.half	atk_knee4
	.half	c_speed3|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_robo3
brutal_robo3:
	.half	atk_elbow2
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_knee1
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_block
	.half	stk_0
		
	.half	atk_elbow1
	.half	c_speed2|cb_lopunch
	.half	stk_0
		
	.half	atk_elbow2
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1

	.half	atk_elbow3
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_kit
brutal_kit:
	.half	atk_lokick
	.half	c_speed1|cb_hipunch
	.half	stk_0
		
	.half	atk_elbow1
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_knee2
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_knee3
	.half	c_speed2|cb_block
	.half	stk_1

	.half	atk_knee4
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_block
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_jade
brutal_jade:
	.half	atk_elbow2
	.half	c_speed1|cb_lokick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed1|cb_hipunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed2|cb_lopunch
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_knee3
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_knee4
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_block
	.half	stk_1

	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	atk_elbow4
	.half	c_speed3|cb_hikick
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_mil
brutal_mil:
	.half	0x1303|0x8000			
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_knee2
	.half	c_speed2|cb_hipunch
	.half	stk_0
	
	.half	atk_knee3
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_knee4
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_1

	.half	0x1303|0x8000			
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	0x1304|0x8000			
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	0x1305|0x8000			
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_scorp
brutal_scorp:
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_knee1
	.half	c_speed2|cb_hipunch
	.half	stk_1

	.half	atk_knee2
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_knee3
	.half	c_speed2|cb_lopunch
	.half	stk_0
		
	.half	atk_knee4
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_rep
brutal_rep:
	.half	atk_a2_3
	.half	c_speed1|cb_block
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_lokick
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_a2_3
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_a2_4
	.half	c_speed3|cb_lopunch
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed2|cb_lokick 
	.half	stk_1

	.half	atk_upcut
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_block
	.half	stk_0
		
	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_ermac
brutal_ermac:
	.half	0x8303			
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	0x8401
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed1|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_1

	.half	0x8303			
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	0x8401
	.half	c_speed2|cb_lokick
	.half	stk_0
		
	.half	0x8401
	.half	c_speed3|cb_hikick
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_osz
brutal_osz:
	.half	0x8303
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_a2_4
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_a2_4
	.half	c_speed2|cb_block
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed3|cb_lokick
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	0x8303
	.half	c_speed2|cb_hikick
	.half	stk_1

	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_1
	
	.half	0x1201|0x8000          
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	0x1201|0x8000          
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_osm
brutal_osm:
	.half	atk_elbow1
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_knee1
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_hipunch
	.half	stk_1

	.half	atk_knee3
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_knee4
	.half	c_speed2|cb_lopunch
	.half	stk_0
		
	.half	atk_roundh
	.half	c_speed2|cb_lokick
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_noob
brutal_noob:
	.half	atk_lokick
	.half	c_speed1|cb_lokick
	.half	stk_0
	
	.half	atk_elbow3
	.half	c_speed1|cb_lopunch
	.half	stk_1
	
	.half	0x1303|0x8000
	.half	c_speed2|cb_block 
	.half	stk_0
	
	.half	0x1303|0x8000
	.half	c_speed2|cb_lokick 
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hipunch
	.half	stk_0
	
	.half	0x1306|0x8000
	.half	c_speed2|cb_lopunch
	.half	stk_1

	.half	0x1306|0x8000
	.half	c_speed2|cb_block  
	.half	stk_1
	
	.half	0x1306|0x8000
	.half	c_speed3|cb_lokick
	.half	stk_0
		
	.half	atk_upcut
	.half	c_speed2|cb_hikick 
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_rayden
brutal_rayden:
	.half	atk_lokick
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed1|cb_lokick 
	.half	stk_1
	
	.half	atk_knee2
	.half	c_speed2|cb_lokick
	.half	stk_0
	
	.half	atk_hikick
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_roundh
	.half	c_speed3|cb_hikick
	.half	stk_1
	
	.half	atk_elbow1
	.half	c_speed1|cb_lopunch
	.half	stk_0
	
	.half	atk_upcut
	.half	c_speed1|cb_lopunch
	.half	stk_1

	.half	atk_elbow1
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed2|cb_block
	.half	stk_0
		
	.half	atk_upcut
	.half	c_speed3|cb_block
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_baraka
brutal_baraka:
	.half	atk_knee1
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_hipunch
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed3|cb_lopunch
	.half	stk_0
	
	.half	atk_elbow1
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	atk_elbow2
	.half	c_speed2|cb_hikick
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed3|cb_hikick
	.half	stk_1

	.half	atk_lokick
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed2|cb_lokick
	.half	stk_0
		
	.half	atk_roundh
	.half	c_speed3|cb_block
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_rain
brutal_rain:
	.half	0x1303|0x8000
	.half	c_speed1|cb_hipunch
	.half	stk_0
	
	.half	0x1303|0x8000
	.half	c_speed1|cb_block  
	.half	stk_1
	
	.half	0x1301|0x8000
	.half	c_speed2|cb_lokick 
	.half	stk_0
	
	.half	atk_lokick
	.half	c_speed2|cb_hikick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_1
	
	.half	atk_upcut
	.half	c_speed3|cb_lokick
	.half	stk_0
	
	.half	0x1305|0x8000
	.half	c_speed2|cb_hikick
	.half	stk_1

	.half	0x1306|0x8000
	.half	c_speed2|cb_block
	.half	stk_1
	
	.half	0x1305|0x8000
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	atk_roundh
	.half	c_speed3|cb_lopunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
	
	
/***************************************************************************
***************************************************************************/
	.align 2
	.globl brutal_kamel
brutal_kamel:
	.half	atk_elbow1
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch
	.half	stk_1
	
	.half	atk_elbow3
	.half	c_speed3|cb_hikick
	.half	stk_0
	
	.half	atk_elbow4
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_lokick
	.half	c_speed2|cb_lokick
	.half	stk_1
	
	.half	atk_hikick
	.half	c_speed3|cb_block
	.half	stk_0
	
	.half	atk_knee2
	.half	c_speed2|cb_lokick
	.half	stk_1

	.half	atk_knee3
	.half	c_speed2|cb_lopunch
	.half	stk_1
	
	.half	atk_knee4
	.half	c_speed2|cb_hikick 
	.half	stk_0
		
	.half	atk_roundh
	.half	c_speed2|cb_hipunch
	.half	stk_0
		
	.half	0xffff					/* terminate list */
