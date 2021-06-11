#include <regdef.h>
#include "mkbkgd.inc"

	.option	pic0
	.set	noreorder

/*
//#******************************************************************************
//# File: mkcombo.s
//#
//# By: David Schwartz
//#
//# Date: August 1994
//#
//# (C) Williams Entertainment
//#
//# Mortal Kombat III Combo Tables
//#******************************************************************************
*/

sw_hi_punch	= 0
sw_lo_punch	= 1
sw_block	= 2
sw_hi_kick	= 3
sw_lo_kick	= 4
sw_run		= 5
sw_up		= 6
sw_down		= 7
sw_left		= 8
sw_right	= 9

x_ground = 0
x_airborn = 1
x_fatal = 2
x_mercy = 3
x_animal = 4
x_close_animal = 5
x_friend = 6
x_baby	= 7

	.extern	do_jc_zaphi
	.extern do_jc_shoruken
	.extern do_jc_zaplo
	.extern do_jc_shadowk
	.extern do_jc_shadowkr

	.extern sk_pound
	.extern q_sk_fatal_hammer
	
	.extern	do_animality		
	.extern	do_baby		
	.extern	do_floor_blade		
	.extern	do_friendship		
	.extern	do_ind_zap		
	.extern	do_inviso		
	.extern	do_kano_swipe		
	.extern	do_kano_zap		
	.extern	do_lao_spin		
	.extern	do_lia_forward		
	.extern	do_lia_scream		
	.extern	do_mercy		
	.extern	do_noogy		
	.extern	do_pit_fatality		
	.extern	do_robo_tele		
	.extern	do_smoke_spear		
	.extern	do_square_wave		
	.extern	do_st_2_ind		
	.extern	do_st_2_jax		
	.extern	do_st_2_kano		
	.extern	do_st_2_lao		
	.extern	do_st_2_lia		
	.extern	do_st_2_lk		
	.extern	do_st_2_robo1		
	.extern	do_st_2_robo2		
	.extern	do_st_2_sg		
	.extern	do_st_2_swat		
	.extern	do_st_2_tusk		
	.extern	do_st_2_smoke		
	.extern	do_st_2_rain		
	.extern scorpion_hell
	.extern	q_noob_friend
	.extern	q_noob_animal
	.extern	q_animal_req		
	.extern	q_bubble_fatal		
	.extern	q_close_animal		
	.extern	q_dinger_friend		
	.extern	q_earth_fatal		
	.extern	q_eatit_fatal		
	.extern	q_floor_blade		
	.extern	q_friend		
	.extern	q_grow_fatal		
	.extern	q_ind_axe_fatal		
	.extern	q_ind_friend		
	.extern	q_inflate_fatal		
	.extern	q_kabal_animal		
	.extern	q_kano_animal		
	.extern	q_lao_hat_fatal		
	.extern	q_lia_hair_fatal		
	.extern	q_lia_scream		
	.extern	q_lk_animal		
	.extern	q_lk_friend		
	.extern	q_lk_mk_fatal		
	.extern	q_mercy_req		
	.extern	q_pit_fatal		
	.extern	q_robo_crush_fatal		
	.extern	q_scream_fatal		
	.extern	q_shang_animal		
	.extern	q_sherip_fatal		
	.extern	q_skel_fatal		
	.extern	q_smoke_animal		
	.extern	q_smoke_friend		
	.extern	q_smoke_tele		
	.extern	q_sonya_friend		
	.extern	q_spear		
	.extern	q_osz_spike_fatal		
	.extern	q_st_spike_fatal		
	.extern	q_swat_animal		
	.extern	q_sz_forward_zap		
	.extern	q_shang_morph_osz		
	.extern	q_shang_morph_ermac
	.extern	q_shang_morph_mileena
	.extern	q_shang_morph_lk		
	.extern	q_shang_morph_sg		
	.extern	q_shang_morph_lao		
	.extern	q_shang_morph_robo1		
	.extern	q_shang_morph_swat		
	.extern	q_shang_morph_tusk		
	.extern	q_shang_morph_ind		
	.extern	q_shang_morph_robo2		
	.extern	q_shang_morph_kano		
	.extern	q_shang_morph_jax		
	.extern	q_shang_morph_jc
	.extern	q_shang_morph_lia		
	.extern q_shang_morph_kit
	.extern q_shang_morph_rep
	.extern q_shang_morph_noob
	.extern q_shang_morph_rayden
	.extern q_shang_morph_baraka
	.extern q_shang_morph_jade
	.extern q_shang_morph_scorpion
	.extern	q_shang_morph_smoke		
	.extern	q_shang_morph_osm
	.extern	q_shang_morph_rain
	.extern	do_axe_up		
	.extern	do_fast_axe_up		
	.extern	do_fatality_1		
	.extern	do_fatality_2		
	.extern	do_reflect		
	.extern	do_sg_pounce		
	.extern	do_sg_quake		
	.extern	do_sg_zap		
	.extern	do_shake		
	.extern	do_st_2_jc
	.extern	do_st_zap1		
	.extern	do_st_zap2		
	.extern	do_st_zap3		
	.extern	do_stick_sweep		
	.extern	do_summon		
	.extern	do_super_kang		
	.extern	do_swat_bomb_hi		
	.extern	do_swat_bomb_lo		
	.extern	do_swat_bombslohi
	.extern	do_swat_bombshilo
	.extern	do_swat_zoom		
	.extern	do_sz_decoy		
	.extern	do_tusk_blur		
	.extern	do_tusk_zap		
	.extern	lk_bike_kick		
	.extern	lk_sbike_kick		
	.extern	lk_zap_hi		
	.extern	lk_zap_lo		
	.extern	q_babality		
	.extern	q_bike_req		
	.extern	q_blurred_req		
	.extern	q_close_fatal		
	.extern	q_fatality_req		
	.extern	q_half_screen_fatal		
	.extern	q_pounce_ok_now		
	.extern	q_robo_flame_fatal		
	.extern	q_robo_net		
	.extern	q_ind_charge		
	.extern	q_swat_zoom		
	.extern	q_sz_decoy		
	.extern	q_taser_fatal		
	.extern hc_kamel
	.extern hc_ukk
	.extern hc_oldsm
	.extern	hc_cheat		
	.extern	hc_cheat1		
	.extern	hc_free_play		
#if 0	
	.extern	hc_f_ermac		
	.extern	hc_f_mileena		
	.extern	hc_f_oldsz		
#endif
	.extern	do_motaro_zap		
	.extern	motaro_tele		
	.extern	motaro_grab_punch_human		
	.extern	q_motaro_zap		

	.extern	sk_air_charge		
	.extern	sk_laugh		
	.extern	sk_taunt		
	.extern	do_sk_zap		
	.extern	sk_hammer		
	.extern	q_sk_hammer		
	.extern	sk_charge		

/*;-u6- */
	.extern	do_rain_zap
	.extern q_rain_zap
	.extern	do_rain_bolt
	.extern	q_rain_bolt
	
	.extern	do_raiden_dive
	.extern	do_combo_raiden_dive
	.extern	do_raiden_melt
	.extern	do_throw_lightning
	.extern	do_raiden_shocker
	.extern	do_shred
	.extern	do_sa_zap
	.extern	do_sa_spin

	.extern	q_rd_melt
	.extern	q_rd_shocker

	.extern	do_noob_zap
	.extern	do_noob_alterego
	.extern q_noob_ego
	.extern	do_noob_slam
	.extern	q_noob_slam
/*-u6- */

	.extern	q_ermac_fatal		
	.extern	q_ermac_slam		
	.extern	do_ermac_slam		
	.extern	q_ermac_decap		
	.extern	do_ermac_zap		
	.extern	q_scorp_tele		
	.extern	do_ermac_tele		
	.extern	q_kano_swipe		
	.extern	do_scorp_tele		
	.extern	do_scorp_telef
	.extern	do_scorpion_spear		
	.extern	q_scorp_airthrow		
	.extern	do_air_slam		
	.extern	q_skull_fatal		
	.extern	q_hand_fatal		
	.extern	q_close_friend		
	.extern	q_reptile_orb_fast		
	.extern	do_reptile_orb_fast		
	.extern	do_spit		
	.extern	q_reptile_orb_slow		
	.extern	do_reptile_orb		
	.extern	q_slide		
	.extern	do_ninja_slide		
	.extern	q_tongue_fatal		
	.extern	do_reptile_inv		
	.extern	q_vomit_fatal		
	.extern	do_reptile_dash		
	.extern	do_mileena_tele		
	.extern	q_far_fatal		
	.extern	q_mileena_roll		
	.extern	do_mileena_roll		
	.extern	q_mileena_zap		
	.extern	do_mileena_zap		
	.extern	do_jade_zap_hi		
	.extern	q_jade_zap_ret		
	.extern	do_jade_zap_ret		
	.extern	do_jade_zap_med		
	.extern	q_jade_prop		
	.extern	do_jade_prop		
	.extern	do_jade_zap_lo		
	.extern	q_jade_flash		
	.extern	do_jade_flash		
	.extern	q_kit_fan		
	.extern	do_kitana_zap		
	.extern	q_fan_lift		
	.extern	do_fan_lift		
	.extern	q_kit_animal		
	.extern	do_robo_net		
	.extern	do_osz_zap		
	.extern	q_floor_ice		
	.extern	do_floor_ice		
	.extern	do_ind_charge		
	.extern	do_ind_charge_fast
	.extern	q_noogy		
	.extern	q_jax_zap		
	.extern	do_jax_zap1		
	.extern	do_jax_zap2		
	.extern	q_jax_dash		
	.extern	jax_dash_punch		
	.extern	q_swat_gun		
	.extern	do_swat_gun		
	.extern	q_lao_spin		
	.extern	q_sa_spin		
	.extern	do_st_2_kitana		
	.extern	do_st_2_oldsz		
#if 0	
	.extern	q_f_oldsz		
	.extern	q_f_ermac		
	.extern	q_f_mileena		
#endif	
	.extern	do_st_2_mileena		
	.extern	do_st_2_reptile		
	.extern	do_st_2_ermac		
	.extern	do_st_2_jade		
	.extern	do_st_2_scorpion		
	
	.extern do_st_2_rayden
	.extern do_st_2_baraka
	.extern do_st_2_rain
	.extern do_st_2_noob
	
	.extern	q_st_zap		
	.extern	q_tusk_blur		
	.extern	q_kano_upball		
	.extern	do_kano_upball		
	.extern	do_kano_pyscho

	.extern q_rd_fatalp	
	.extern q_baraka_fatal
	.extern q_baraka_decap

MASK_JLEFT		=	0x8000
MASK_JRIGHT		=	0x2000
MASK_JDOWN		=	0x4000
MASK_JUP		=	0x1000
MASK_JBLOCK		=	0x0008
MASK_JRUN		=	0x0004
MASK_JHIP		=	0x0010
MASK_JLOP		=	0x0080
MASK_JHIK		=	0x0020
MASK_JLOK	   	=	0x0040

p1b0 = (MASK_JHIP)
p1b1 = (MASK_JLOP)
p1b2 = (MASK_JBLOCK)
p1b3 = (MASK_JHIK)
p1b4 = (MASK_JLOK)
p1b5 = (MASK_JRUN)
p1sf2 = 0

p2b0 =	(MASK_JHIP)
p2b1 =	(MASK_JLOP)
p2b2 =	(MASK_JBLOCK)
p2b3 =	(MASK_JHIK)
p2b4 =	(MASK_JLOK)
p2b5 =	(MASK_JRUN)
p2sf2 = 0


	.data

	.align 2
	.globl	scom_robo_zap1
scom_robo_zap1:
	.half	0x20		   	
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	
	.align 2
	.globl	scom_robo_2zap1
scom_robo_2zap1:
	.half	0x20		   	
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	

	.align 2
	.globl	scom_robo_zap2
scom_robo_zap2:
	.half	0x16		   	
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0

	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_bomb_mid
scom_bomb_mid:
	.half	0x18		   	
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_bomb_full
	.globl	scom_robo_tele
scom_bomb_full:
scom_robo_tele:
	.half	0x18		   	
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0


	.align 2
	.globl	scom_robo2_tele
scom_robo2_tele:
	.half	0x18		   	
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0


	.align 2
	.globl	scom_robo_air_grab
scom_robo_air_grab:
	.half	0x18		   	
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_fly
scom_fly:
	.half	0x28		   	
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0


	.align 2
	.globl	scom_lia_anglez
scom_lia_anglez:
	.half	0x12		   	
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_bike
scom_bike:
	.half	0x20		   	
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0


	.align 2
	.globl	scom_sonya_zap
scom_sonya_zap:
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_sky_zap_on
scom_sky_zap_on:
	.half	0x20		   	
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl 	scom_osz_fatal
scom_osz_fatal:
	.half	0x30
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0		
	

	.align 2
	.globl	scom_sky_zap_behind
scom_sky_zap_behind:
	.half	0x30		   	
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_sky_zap_front
scom_sky_zap_front:
	.half	0x30		   	
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_sw_zap
scom_sw_zap:
	.half	0x24		   	
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0


	.align 2
	.globl scom_lao_dbl_teleport
scom_lao_dbl_teleport:
	.half	0x1a
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_lao_teleport
scom_lao_teleport:
	.half	0x10
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.align 2
	.globl	scom_lao_angle_kick
scom_lao_angle_kick:
	.half	0x20		   	
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0

	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0


	.align 2
	.globl	scom_lao_zap
scom_lao_zap:
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0

/*
//**************************************************************************
//*											     *
//*  Secret Move tables									     *
//*											     *
//* entry format:
//* typedef struct smove {
//*	WORD s_p1leg//			// p1 requirements, format change long-0xword
//* 	WORD s_p2leg//			// p2 requirements, format change long-0xword
//* 	LONG s_xfer//			// xfer type index, format change word-0xlong
//* 	LONG s_yes_no//			// yes/no routine
//* 	FUNC *s_routine//			// address of secret move
//*
//* 	WORD s_time//			// time for move
//* 	WORD s_r1//				// move right 1
//* 	WORD s_r2//				// move right 2
//* 	WORD s_r3//				// move right 3
//* 	WORD s_r4//				// move right 4
//* 	WORD s_r5//				// move right 5
//* 	WORD s_r6//				// move right 6
//* 	WORD s_l1//				// move left 1
//* 	WORD s_l2//				// move left 2
//* 	WORD s_l3//				// move left 3
//* 	WORD s_l4//				// move left 4
//* 	WORD s_l5//				// move left 5
//* 	WORD s_l6//				// move left 6
//* 	WORD s_pad//				// padding added to keep alignment
//* } SMOVE//:
//**************************************************************************
*/

	.align 2
	.globl	sm_rain_bc
sm_rain_bc:
	.half	p1b2
	.half	p2b2
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x40
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl sm_rain_lpc
sm_rain_lpc:
	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	p1b1
	.half	p2b1
	.word	x_friend
	.word	q_friend		
	.word	do_friendship
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.word	0


	.align 2
	.globl sm_rain_hpc
sm_rain_hpc:
	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_ground
	.word	q_rain_zap				/* yes/no routine */
	.word	do_rain_zap		/* address of secret move */
	.half	0x18	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */
	
	.half	p1b0     		/* player 1 requirements */
	.half	p2b0      		/* player 2 requirements */
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_ground
	.word	q_rain_bolt				/* yes/no routine */
	.word	do_rain_bolt		/* address of secret move */
	.half	0x14	   	/* time to do entire switch combo */
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_fatal
	.word	q_close_fatal				/* yes/no routine */
	.word	do_fatality_1		/* address of secret move */
	.half	0x18	   	/* time to do entire switch combo */
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */
	
	.half 	0


	.align 2
	.globl sm_rain_hkc
sm_rain_hkc:
	.half 	p1b3     		/* player 1 requirements */
	.half 	p2b3      		/* player 2 requirements */
	.word	x_fatal
	.word	q_tongue_fatal				/* yes/no routine */
	.word	do_fatality_2		/* address of secret move */
	.half	0x38	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					/* added field */
	
	.half 	0


	.align 2
	.globl sm_noob_lpc
sm_noob_lpc:
	.half	p1b1     		/* player 1 requirements */
	.half	p2b1      		/* player 2 requirements */
	.word	x_ground
	.word	q_noob_zap				/* yes/no routine */
	.word	do_noob_zap		/* address of secret move */
	.half	0x15
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half	p1b1     		/* player 1 requirements */
	.half	p2b1      		/* player 2 requirements */
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	0

	.align 2
	.globl sm_noob_hpc
sm_noob_hpc:
	.half	p1b0     		/* player 1 requirements */
	.half	p2b0      		/* player 2 requirements */
	.word	x_friend
	.word	q_noob_friend		
	.word	do_friendship		
	.half	0x38
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_ground
	.word	q_noob_ego				/* yes/no routine */
	.word	do_noob_alterego		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	.half 	0

	.align 2
	.globl sm_noob_hkc
sm_noob_hkc:
	.half 	p1b3     		/* player 1 requirements */
	.half 	p2b3      		/* player 2 requirements */
	.word	x_fatal
	.word	q_half_screen_fatal		
	.word	do_fatality_1		/* address of secret move */
	.half	0x30	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0					/* added field */
	
	.half	p1b3
	.half	p2b3	     	
	.word	x_animal
	.word	q_noob_animal	
	.word	do_animality 	
	.half	0x40
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	
	.half 	0

	.align 2
	.globl sm_noob_uc
sm_noob_uc:
	.half 	p1b0|p1b1|p1b3|p1b4     		/* player 1 requirements */
	.half 	p2b0|p2b1|p2b3|p2b4      		/* player 2 requirements */
	.word	x_ground
	.word	q_noob_slam				/* yes/no routine */
	.word	do_noob_slam		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	.half 	0
			 
	.align 2
	.globl sm_noob_bc
sm_noob_bc:
	.half	p1b2
	.half	p2b2
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.word	0

	.align 2
	.globl sm_noob_rc
sm_noob_rc:
	.half	p1b5|p1b2
	.half	p2b5|p1b2
	.word	x_fatal
	.word   q_fatality_req
	.word	do_fatality_2
	.half	0x30
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.word	0

	.align 2
	.globl	sm_sa_hpo
sm_sa_hpo:
	.half	p1b0
	.half	p2b0	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl sm_sa_lpc
sm_sa_lpc:
	.half	p1b1     		/* player 1 requirements */
	.half	p2b1      		/* player 2 requirements */
	.word	x_ground
	.word	0				/* yes/no routine */
	.word	do_shred		/* address of secret move */
	.half	0x22
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half	p1b1     		/* player 1 requirements */
	.half	p2b1      		/* player 2 requirements */
	.word	x_fatal
	.word	q_baraka_fatal				/* yes/no routine */
	.word	do_fatality_2		/* address of secret move */
	.half	0x38
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	0
	
	
	.align 2
	.globl sm_sa_hkc
sm_sa_hkc:
	.half	p1b3     		/* player 1 requirements */
	.half	p2b3      		/* player 2 requirements */
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x38
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half	p1b3     		/* player 1 requirements */
	.half	p2b3      		/* player 2 requirements */
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	0
	

	.align 2
	.globl sm_sa_hpc
sm_sa_hpc:
	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_ground
	.word	0				/* yes/no routine */
	.word	do_sa_zap		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	
	.half 	p1b0     		/* player 1 requirements */
	.half 	p2b0      		/* player 2 requirements */
	.word	x_fatal
	.word	q_baraka_decap				/* yes/no routine */
	.word	do_fatality_1		/* address of secret move */
	.half	0x38	   	/* time to do entire switch combo */
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0

	.half	0					/* added field */
	
	.half 	0
	
	
	.align 2
	.globl sm_sa_bc
sm_sa_bc:
	.half 	p1b2     		/* player 1 requirements */
	.half 	p2b2      		/* player 2 requirements */
	.word	x_ground
	.word	q_sa_spin				/* yes/no routine */
	.word	do_sa_spin		/* address of secret move */
	.half	0x30	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	.half	0 

	.align 2
	.globl sm_sa_rc
sm_sa_rc:
	.half		p1b5
	.half		p2b5
	.word		x_ground
	.word		q_pit_fatal		
	.word		do_pit_fatality 	
	.half		0x26
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_lo_kick
	.half		0
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_lo_kick
	.half		0
	.half		0

	.half		0


	.align 2
	.globl sm_rd_hpc
sm_rd_hpc:
	.half		p1b0
	.half		p2b0
	.word		x_ground
	.word		q_pit_fatal		
	.word		do_pit_fatality 	
	.half		0x30
	.half		sw_down
	.half		sw_down
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		sw_down
	.half		sw_down
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		0

	.half		0
	

	.align 2
	.globl sm_rd_uc
sm_rd_uc:
	.half 	p1b0|p1b1|p1b3|p1b4     		/* player 1 requirements */
	.half 	p2b0|p2b1|p2b3|p2b4      		/* player 2 requirements */
	.word	x_ground
	.word	q_rd_melt				/* yes/no routine */
	.word	do_raiden_melt		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	.half 	0

	.align 2
	.globl sm_rd_rc
sm_rd_rc:
	.half 	p1b0|p1b1|p1b3|p1b4     		/* player 1 requirements */
	.half 	p2b0|p2b1|p2b3|p2b4      		/* player 2 requirements */
	.word	x_airborn
	.word	0				/* yes/no routine */
	.word	do_raiden_dive		/* address of secret move */
	.half	0x20	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0

	.half	0					/* added field */
	.half 	0

	.align 2
	.globl sm_rd_hpo
sm_rd_hpo:
	.half	p1b0	   	/* player 1 requirements */
	.half	p2b0   		/* player 2 requirements */
	.word	x_fatal
	.word	q_rd_fatalp		/* yes/no routine */
	.word	do_fatality_1		
	.half	0x00	      	/* 0 = yes !! */
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		/* added field */

	.half	p1b0	   	/* player 1 requirements */
	.half	p2b0   		/* player 2 requirements */
	.word	x_ground
	.word	q_rd_shocker/* yes/no routine */
	.word	do_raiden_shocker	/* address of secret move */
	.half	0x00	      	/* 0 = yes !! */
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		/* added field */
	.half	0

	.align 2
	.globl sm_rd_lko
sm_rd_lko:
	.half	p1b4	   	/* player 1 requirements */
	.half	p2b4   		/* player 2 requirements */
	.word	x_fatal
	.word	q_rd_fshocker	/* yes/no routine */
	.word	do_fatality_2	/* address of secret move */
	.half	0x00	      	/* 0 = yes !! */
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		/* added field */
	.half	0

	.align 2
	.globl sm_rd_lpo
sm_rd_lpo:
	.half 	p1b0|p1b1|p1b2|p1b3|p1b4|p1b5     		/* player 1 requirements */
	.half 	p2b0|p2b1|p2b2|p2b3|p2b4|p2b5     		/* player 2 requirements */
	.word	x_ground
	.word	0				/* yes/no routine */
	.word	do_throw_lightning		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half 	p1b0|p1b1|p1b2|p1b3|p1b4|p1b5     		/* player 1 requirements */
	.half 	p2b0|p2b1|p2b2|p2b3|p2b4|p2b5     		/* player 2 requirements */
	.word	x_ground
	.word	0				/* yes/no routine */
	.word	do_reverse_throw_lightning		/* address of secret move */
	.half	0x10	   	/* time to do entire switch combo */
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */
	.half 	0





	.align 2
	.globl sm_rd_hkc
sm_rd_hkc:
	.half	p1b3	   	/* player 1 requirements */
	.half	p2b3   		/* player 2 requirements */
	.word	x_friend
	.word	q_ind_friend		/* yes/no routine */
	.word	do_friendship		
	.half	0x30	      	/* 0 = yes !! */
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0		/* added field */

	.half	p1b3	   	/* player 1 requirements */
	.half	p2b3   		/* player 2 requirements */
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x30	      	/* 0 = yes !! */
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0		/* added field */
	
	.half	p1b3
	.half	p2b3	     	
	.word	x_animal
	.word	q_smoke_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	0


	.align 2
	.globl	sm_home_codes
sm_home_codes:
	.half	p1b5	     	
	.half	p2b5	     	
	.word	0
	.word	0				
	.word	hc_free_play	
	.half	0x50
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b2	     	
	.half	p2b2	     	
	.word	0
	.word	0				
	.word	hc_ukk	
	.half	0x60
	.half	sw_up
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	sw_up
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b5
	.half	p2b5	     	
	.word	0
	.word	0				
	.word	hc_cheat1
	.half	0x60
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	sw_lo_punch
	.half	sw_lo_kick
	.half	sw_hi_kick
	.half	sw_hi_punch
	.half	0
	.half	0
	.half	0

	.half	p1b5	    
	.half	p2b5	    
	.word	0
	.word	0			
	.word	hc_cheat
	.half	0x60
	.half	sw_run
	.half	sw_block
	.half	sw_lo_punch
	.half	sw_hi_punch
	.half	sw_lo_kick
	.half	sw_hi_kick
	.half	sw_lo_punch
	.half	sw_hi_punch
	.half	sw_lo_kick
	.half	sw_hi_kick
	.half	0
	.half	0
	.half	0

	.half	p1b4	    
	.half	p2b4
	.word	0
	.word	0			
	.word	hc_kamel
	.half	0x80
	.half	sw_lo_kick
	.half	sw_hi_kick
	.half	sw_lo_punch
	.half	sw_block
	.half	sw_run
	.half	sw_hi_kick
	.half	sw_lo_kick
	.half	sw_hi_punch
	.half	sw_run
	.half	sw_block
	.half	0
	.half	0
	.half	0

	.half	p1b4	    
	.half	p2b4
	.word	0
	.word	0			
	.word	hc_oldsm
	.half	0x80
	.half	sw_down
	.half	sw_left
	.half	sw_up
	.half	sw_down
	.half	sw_up
	.half	sw_right
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0


	
	.word	0				

#if 0
	.align 2
	.globl	sm_home_codes1
sm_home_codes1:
	.half	p1b0	     	
	.half	p2b0	     	
	.word	0
	.word	0				
	.word	hc_f_mileena	
	.half	0x50
	.half	sw_right
	.half	sw_down
	.half	sw_up
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b1	     	
	.half	p2b1	     	
	.word	0
	.word	0				
	.word	hc_f_oldsz	
	.half	0x50
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b5|p1b2	     	
	.half	p2b5|p1b2	     	
	.word	0
	.word	0				
	.word	hc_f_ermac	
	.half	0x50
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.word	0
#endif

	.align 2
	.globl	sm_all_ro
sm_all_ro:
	.half	p1b5	     	
	.half	p2b5	     	
	.word	x_mercy
	.word	q_mercy_req	
	.word	do_mercy 	
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				
	.half	0				

	.align 2
	.globl	sm_ermac_bc
sm_ermac_bc:
	.half	p1b2     		
	.half	p2b2      		
	.word	x_fatal
	.word	q_ermac_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_up
	.half	sw_down
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0					

	.half 	0

	.align 2
	.globl	sm_ermac_hkc
sm_ermac_hkc:
	.half		p1b3     		
	.half		p2b3      		
	.word		x_ground
	.word		q_ermac_slam		
	.word		do_ermac_slam		
	.half		0x18
	.half		sw_left
	.half		sw_down
	.half		sw_left
	.half		0
	.half		0
	.half		0
	.half		sw_right
	.half		sw_down
	.half		sw_right
	.half		0
	.half		0
	.half		0
	.half		0

	
	.half			p1b3     		
	.half			p2b3      		
	.word			x_fatal
	.word			q_close_fatal
	.word			do_fatality_2		
	.half			0x30
	.half			sw_hi_kick
	.half			sw_run
	.half			sw_run
	.half			sw_block
	.half			sw_run
	.half			0
	.half			sw_hi_kick
	.half			sw_run
	.half			sw_run
	.half			sw_block
	.half			sw_run
	.half			0
	.half			0
	.half	0
	

	.align 2
	.globl	sm_osm_hkc
sm_osm_hkc:
	.half			p1b3     		
	.half			p2b3      		
	.word			x_fatal
	.word			q_half_screen_fatal
	.word			do_fatality_2		
	.half			0x30
	.half			sw_hi_kick
	.half			sw_run
	.half			sw_run
	.half			sw_block
	.half			sw_run
	.half			0
	.half			sw_hi_kick
	.half			sw_run
	.half			sw_run
	.half			sw_block
	.half			sw_run
	.half			0
	.half			0
	
	.half	p1b3
	.half	p2b3	     	
	.word	x_animal
	.word	q_smoke_animal	
	.word	do_animality 	
	.half	0x38
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					
	
	.half	0

	.align 2
	.globl	sm_ermac_lkc
sm_ermac_lkc:
	.half		p1b4
	.half		p2b4
	.word		x_ground
	.word		q_pit_fatal		
	.word		do_pit_fatality 	
	.half		0x38
	.half		sw_lo_kick
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		0
	.half		sw_lo_kick
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		sw_run
	.half		0
	.half		0


	.half	p1b4	     	
	.half	p2b4	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.half	0


	.align 2
	.globl	sm_ermac_lpc
sm_ermac_lpc:
	.half		p1b1     		
	.half		p2b1      		
	.word		x_ground
	.word		0			
	.word		do_ermac_zap		
	.half		0x10
	.half		sw_left
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		0
	.half		sw_right
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		0
	.half		0
	.word	0

	.align 2
	.globl	sm_ermac_hpc
sm_ermac_hpc:
	.half		p1b0     		
	.half		p2b0      		
	.word		x_airborn
	.word		q_scorp_tele		
	.word		do_ermac_tele		
	.half		0x10
	.half		sw_left
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		0
	.half		sw_right
	.half		sw_down
	.half		0
	.half		0
	.half		0
	.half		0
	.half		0
	
	
	.half	p1b0
	.half	p2b0
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					
	
	
	.half	p1b0
	.half	p2b0	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.word	0


	.align 2
	.globl	sm_smoke_lkc
sm_smoke_lkc:
	.half	p1b4     		
	.half	p2b4      		
	.word	x_airborn
	.word	q_smoke_tele		
	.word	do_robo_tele		
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	.word	0			

	.align 2
	.globl	sm_smoke_uc
sm_smoke_uc:
	.half	p1b2|p1b5     		
	.half	p2b2|p2b5      		
	.word	x_fatal
	.word	q_eatit_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_up
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_up
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_smoke_dc
sm_smoke_dc:
	.half	p1b2|p1b5     		
	.half	p2b2|p2b5      		
	.word	x_fatal
	.word	q_earth_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_down
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_smoke_hkc
sm_smoke_hkc:
	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_friend
	.word	q_smoke_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_hi_kick
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.word	0



	.align 2
	.globl	sm_smoke_bc
sm_smoke_bc:
	.half	p1b2	     	
	.half	p2b2	     	
	.word	x_animal
	.word	q_smoke_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_smoke_lpc
sm_smoke_lpc:
	.half	p1b1     	
	.half	p2b1     	
	.word	x_ground
	.word	q_spear		
	.word	do_smoke_spear 	
	.half	0x14
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_smoke_rc
sm_smoke_rc:
	.half	p1b5|p1b2     	
	.half	p2b5|p2b2     	
	.word	x_ground
	.word	0		
	.word	do_inviso 	
	.half	0x28
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

/*
**************************************************************************
*											     *
*     Shao Kahn										     *
*											     *
*************************************************************************
*/

	.align 2
	.globl	sm_sk_rc
sm_sk_rc:
	.half	p1b5		
	.half	p2b5    		
	.word	x_ground
	.word	0					
	.word	sk_laugh			
	.half	0x10
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			

	.half	p1b2|p1b5		
	.half	p2b2|p1b5    		
	.word	x_ground
	.word	0					
	.word	sk_taunt			
	.half	0x10
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			

	.word	0

	.align 2
	.globl	sm_sk_lkc
sm_sk_lkc:
	.half	p1b4		
	.half	p2b4    		
	.word	x_ground
	.word	0					
	.word	do_sk_zap			
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			
	.word	0


	.align 2
	.globl	sm_sk_hpc
sm_sk_hpc:
	.half	p1b0|p1b1		
	.half	p2b0|p2b1    		
	.word	x_ground
	.word	q_sk_hammer					
	.word	sk_hammer		
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			
	
	.half	p1b0
	.half	p2b0
	.word	x_fatal
	.word	q_sk_fatal_hammer					
	.word	sk_pound
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			

	.half	p1b0		
	.half	p2b0    		
	.word	x_ground
	.word	q_ind_charge	
	.word	sk_charge	
	.half	0x14
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			

	.word	0

	.align 2
	.globl	sm_sk_hkc
sm_sk_hkc:
	.half	p1b3		
	.half	p2b3    		
	.word	x_ground
	.word	q_ind_charge	
	.word	sk_air_charge	
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0			
	.word	0

/*
**************************************************************************
*											     *
*     Motaro										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_motaro_hpc
sm_motaro_hpc:
	.half	p1b0|p1b1		
	.half	p2b0|p2b1    		
	.word	x_ground
	.word	0					
	.word	motaro_grab_punch_human	
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			
	.word	0

	.align 2
	.globl	sm_motaro_hkc
sm_motaro_hkc:
	.half	p1b3|p1b4		
	.half	p2b3|p2b4    		
	.word	x_ground
	.word	q_scorp_tele					
	.word	motaro_tele	
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			
#if 1
	.half	p1b3
	.half	p2b3
	.word	x_fatal
	.word	q_mot_fatal_head
	.word	mot_fatal_head
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			
#endif	
	.word	0

	.align 2
	.globl	sm_motaro_lko
sm_motaro_lko:
	.half	p1b4	   	
	.half	p2b4   		
	.word	x_ground
	.word	q_motaro_zap	
	.word	do_motaro_zap	
	.half	0x00	      	
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0


/*
**************************************************************************
*											     *
*     Kano										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_kano_hkc
sm_kano_hkc:
	.half	p1b3|p1b4		
	.half	p2b3|p2b4    		
	.word	x_ground
	.word	q_kano_upball		
	.word	do_kano_upball		
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			

	.half	p1b3			
	.half	p2b3			
	.word	x_fatal
	.word	q_half_screen_fatal	
	.word	do_fatality_1		
	.half	0x28
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	0					

	.half	p1b3			
	.half	p2b3			
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x28
	.half	sw_hi_kick
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_kano_lpc
sm_kano_lpc:
	.half	p1b1|p1b4		
	.half	p2b1|p2b4		
	.word	x_ground
	.word	0			
	.word	do_shake		
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			

	.align 2
	.globl	sm_kano_hpc
sm_kano_hpc:
	.half	p1b0|p1b4      	
	.half	p2b0|p2b4      	
	.word	x_ground
	.word	q_kano_swipe		
	.word	do_kano_swipe 	
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b0|p1b4      	
	.half	p2b0|p2b4      	
	.word	x_ground
	.word	0		
	.word	do_kano_zap 	
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_kano_lpo
sm_kano_lpo:
	.half	p1b1			
	.half	p2b1			
	.word	x_fatal
	.word	q_skel_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_kano_lkc
sm_kano_lkc:
	.half	p1b4		
	.half	p2b4    		
	.word	x_ground
	.word	q_kano_upball		
	.word	do_kano_pyscho
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			

	.half	p1b4
	.half	p2b4
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b2|p1b4
	.half	p2b2|p2b4
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_left
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0					


	.word	0


	.align 2
	.globl	sm_kano_hpo
sm_kano_hpo:
	.half	p1b0	     	
	.half	p2b0	     	
	.word	x_animal
	.word	q_kano_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0



/*
*
* Sektor !!
*
*/
	.align 2
	.globl	sm_robo2_uc
sm_robo2_uc:
	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_robo1_dc
sm_robo1_dc:
	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_friend
	.word	q_dinger_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.half	p1b5
	.half	p2b5
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					


	.word	0



	.align 2
	.globl	sm_robo1_uc
sm_robo1_uc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x28		   	
	.half	sw_up
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_robo_hkc
sm_robo_hkc:
	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.word	0



	.align 2
	.globl	sm_robo_bc
sm_robo_bc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_fatal
	.word	q_robo_flame_fatal	
	.word	do_fatality_2		
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_fatal
	.word	q_robo_crush_fatal	
	.word	do_fatality_1		
	.half	0x28
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	0					

	.word	0

/*
**************************************************************************
*											     *
*   Scorpion										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_osm_hpc
sm_osm_hpc:
	.half	p1b0     		
	.half	p2b0      		
	.word	x_airborn
	.word	q_scorp_tele		
	.word	do_scorp_tele		
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				
	.half	0				

	.align 2
	.globl	sm_scorp_hpc
sm_scorp_hpc:
	.half	p1b0     		
	.half	p2b0      		
	.word	x_airborn
	.word	q_scorp_tele		
	.word	do_scorp_tele		
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				
	
	.half	p1b0     		
	.half	p2b0      		
	.word	x_airborn
	.word	q_scorp_tele		
	.word	do_scorp_telef
	.half	0x10
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b0   		
	.half	p2b0   		
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x30
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0				

	.word	0

	.align 2
	.globl	sm_scorp_lpc
sm_scorp_lpc:
	.half	p1b1     		
	.half	p2b1      		
	.word	x_fatal
	.word	q_hand_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0		

	.align 2
	.globl sm_osm_lpc
sm_osm_lpc:
	.half	p1b1     		
	.half	p2b1      		
	.word	x_ground
	.word	q_spear			
	.word	do_scorpion_spear	
	.half	0x10
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_up
	.half	sw_up
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0				


	.word	0

	.align 2
	.globl	sm_scorp_bc
sm_scorp_bc:
	.half	p1b2     		
	.half	p2b2      		
	.word	x_airborn
	.word	q_scorp_airthrow	
	.word	do_air_slam	
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0

	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_scorp_hkc
sm_scorp_hkc:
	.half	p1b3     		
	.half	p2b3      		
	.word	x_fatal
	.word	q_skull_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b3     		
	.half	p2b3      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x28
	.half	sw_up
	.half	sw_up
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_scorp_rc
sm_scorp_rc:
	.half	p1b5     		
	.half	p2b5      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	scorpion_hell
	.half	0x30
	.half	sw_up
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0		
	.word 	0
	
	.align 2
	.globl	sm_scorp_lkc
sm_scorp_lkc:
	.half	p1b4	     		
	.half	p2b4	      		
	.word	x_friend
	.word	q_close_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0		

	.word	0

		.align 2
	.globl	sm_osm_rc
sm_osm_rc:
	.half	p1b5     		/* player 1 requirements */
	.half	p2b5      		/* player 2 requirements */
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half	p1b5     		/* player 1 requirements */
	.half	p2b5      		/* player 2 requirements */
	.word	x_fatal
	.word	q_robo_flame_fatal
	.word	do_fatality_1
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					/* added field */

	.half	p1b5
	.half	p2b5	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x35
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.word	0

/*
**************************************************************************
*											     *
*   Reptile										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_rep_hpc
sm_rep_hpc:
	.half	p1b0|p1b1     		
	.half	p2b0|p2b1      		
	.word	x_ground
	.word	q_reptile_orb_fast	
	.word	do_reptile_orb_fast	
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0     		
	.half	p2b0      		
	.word	x_ground
	.word	0			
	.word	do_spit			
	.half	0x12
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0|p1b1     		
	.half	p2b0|p2b1      		
	.word	x_ground
	.word	q_reptile_orb_slow	
	.word	do_reptile_orb		
	.half	0x18
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_rep_lpc
sm_rep_lpc:
	.half	p1b0|p1b1     		
	.half	p2b0|p2b1      		
	.word	x_ground
	.word	q_reptile_orb_fast	
	.word	do_reptile_orb_fast	
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0|p1b1     	
	.half	p2b0|p2b1      	
	.word	x_ground
	.word	q_reptile_orb_slow		
	.word	do_reptile_orb			
	.half	0x18
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0


	.align 2
	.globl	sm_rep_bc
sm_rep_bc:
	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b2     		
	.half	p2b2      		
	.word	x_fatal
	.word	q_tongue_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b2
	.half	p2b2
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	0
	.half	0
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_rep_hkc
sm_rep_hkc:
	.half	p1b3	 		
	.half	p2b3 			
	.word	x_ground
	.word	0			
	.word	do_reptile_inv		
	.half	0x20
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b3           	
	.half	p2b3           	
	.word	x_fatal
	.word	q_vomit_fatal	
	.word	do_fatality_2  	
	.half	0x30
	.half	sw_up
	.half	sw_up
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0		

	.half	p1b3     		
	.half	p2b3      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x30
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_friend
	.word	q_close_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.word	0


	.align 2
	.globl	sm_rep_lkc
sm_rep_lkc:
	.half	p1b4	 		
	.half	p2b4 			
	.word	x_ground
	.word	0			
	.word	do_reptile_dash		
	.half	0x10
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b4   		
	.half	p2b4   		
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x2a
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0		

	.word	0

/*
**************************************************************************
*											     *
*  Mileena										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_mil_hpc
sm_mil_hpc:
	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0   		
	.half	p2b0   		
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0				

	.word	0

	.align 2
	.globl	sm_mil_lpc
sm_mil_lpc:
	.half	p1b1     		
	.half	p2b1      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0				

	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0

	.word	0

	.align 2
	.globl	sm_mil_lkc
sm_mil_lkc:
	.half	p1b4|p1b0	
	.half	p2b4|p2b0	
	.word	x_ground
	.word	0		
	.word	do_mileena_tele	
	.half	0x15
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b4     		
	.half	p2b4      		
	.word	x_fatal
	.word	q_far_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0		

	.word	0


	.align 2
	.globl	sm_mil_hkc
sm_mil_hkc:
	.half	p1b3|p1b0   	
	.half	p2b3|p2b0   	
	.word	x_ground
	.word	q_mileena_roll	
	.word	do_mileena_roll	
	.half	0x30	      	
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b3     		
	.half	p2b3      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_mil_hpo
sm_mil_hpo:
	.half	p1b0	   	
	.half	p2b0   		
	.word	x_airborn
	.word	q_mileena_zap	
	.word	do_mileena_zap	
	.half	0x00	      	
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

/*
**************************************************************************
*											     *
*   Jade											     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_jad_hpc
sm_jad_hpc:
	.half	p1b0   		
	.half	p2b0   		
	.word	x_ground
	.word	0		
	.word	do_jade_zap_hi	
	.half	0x10
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
    .half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0     		
	.half	p2b0      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_right
	.half	sw_down
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_jad_lpc
sm_jad_lpc:
	.half	p1b1   		
	.half	p2b1   		
	.word	x_ground
	.word	q_jade_zap_ret	
	.word	do_jade_zap_ret	
	.half	0x20
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1   		
	.half	p2b1   		
	.word	x_ground
	.word	0		
	.word	do_jade_zap_med	
	.half	0x10
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1     		
	.half	p2b1      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	sw_left

	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	0				

	.word	0

	.align 2
	.globl	sm_jad_rc
sm_jad_rc:
	.half	p1b5     		
	.half	p2b5      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0				

	.half	p1b5
	.half	p2b5
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0				

	.word	0


	.align 2
	.globl	sm_jad_lkc
sm_jad_lkc:
	.half	p1b4   		
	.half	p2b4   		
	.word	x_ground
	.word	q_jade_prop	
	.word	do_jade_prop	
	.half	0x10
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b4     		
	.half	p2b4      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0		

	.half	p1b4   		
	.half	p2b4   		
	.word	x_ground
	.word	0		
	.word	do_jade_zap_lo	
	.half	0x10
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		


	.word	0

	.align 2
	.globl	sm_jad_hkc
sm_jad_hkc:
	.half	p1b3   		
	.half	p2b3   		
	.word	x_ground
	.word	q_jade_flash	
	.word	do_jade_flash	
	.half	0x10
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0		

	.half	p1b3   		
	.half	p2b3   		
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x30
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.word	0

/*
**************************************************************************
*											     *
*  Kitana										     *
*											     *
**************************************************************************
*/
	.align 2
	.globl	sm_kt_lpc
sm_kt_lpc:
	.half	p1b0|p1b1     		
	.half	p2b0|p2b1      		
	.word	x_airborn
	.word	q_kit_fan		
	.word	do_kitana_zap		
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_kt_hpc
sm_kt_hpc:
	.half	p1b0|p1b1     		
	.half	p2b0|p2b1      		
	.word	x_airborn
	.word	q_kit_fan		
	.word	do_kitana_zap		
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0     		
	.half	p2b0      		
	.word	x_ground
	.word	q_fan_lift		
	.word	do_fan_lift		
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0     		
	.half	p2b0      		
	.word	x_ground
	.word	0			
	.word	do_square_wave		
	.half	0x28
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_kt_hkc
sm_kt_hkc:
	.half	p1b3     		
	.half	p2b3      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_1		
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0		

	.half	p1b3   		
	.half	p2b3   		
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x2a
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_kt_lkc
sm_kt_lkc:
	.half	p1b4     		
	.half	p2b4      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x28
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0		

	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0


	.align 2
	.globl	sm_kt_rc
sm_kt_rc:
	.half	p1b5     		
	.half	p2b5      		
	.word	x_animal
	.word	q_kit_animal		
	.word	do_animality		
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0		


	.word	0

/*
*
* Cyrax
*
*/
	.align 2
	.globl	sm_robo2_lkc
sm_robo2_lkc:
	.half	p1b4     		
	.half	p2b4      		
	.word	x_ground
	.word	q_robo_net		
	.word	do_robo_net		
	.half	0x20		   	
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_robo2_hpc
sm_robo2_hpc:
	.half	p1b0|p1b2     		
	.half	p2b0|p2b2      		
	.word	x_fatal
	.word	q_fatality_req		
	.word	do_fatality_2		
	.half	0x28
	.half	sw_down
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_down
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.half	p1b0
	.half	p2b0
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_robo2_dc
sm_robo2_dc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality		
	.half	0x28		   	
	.half	sw_down
	.half	sw_down
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0					


	.word	0

	.align 2
	.globl	sm_robo2_rc
sm_robo2_rc:
	.half	p1b5
	.half	p2b5
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x12
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b5|p1b2     		
	.half	p2b5|p2b2      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_1		
	.half	0x28
	.half	sw_up
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_up
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_lia_uc
sm_lia_uc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0					

	.half	p1b2
	.half	p2b2
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lia_hpc
sm_lia_hpc:
	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_ground
	.word	q_lia_scream		
	.word	do_lia_scream		
	.half	0x20		   	
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_animal
	.word	q_animal_req		
	.word	do_animality		
	.half	0x2a		   	
	.half	sw_up
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_lia_bc
sm_lia_bc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_fatal
	.word	q_lia_hair_fatal	
	.word	do_fatality_2		
	.half	0x30
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0					

	.half	p1b2|p1b5     		
	.half	p2b2|p2b5      		
	.word	x_fatal
	.word	q_scream_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lia_lpc
sm_lia_lpc:
	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_ground
	.word	0			
	.word	do_lia_forward2
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_ground
	.word	0			
	.word	do_lia_forward		
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					


	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x20
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_osz_hpc
sm_osz_hpc:
	.half	p1b0
	.half	p2b0
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0		



	.half	p1b0
	.half	p2b0
	.word	x_ground
	.word	q_osz_spike_fatal
	.word	do_fatality_2	 	
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_osz_lpc
sm_osz_lpc:
	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word	q_sz_forward_zap	
	.word	do_osz_zap	 	
	.half	0x10
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	
	.half	p1b1	     				/* new sz move */
	.half	p2b1	      		
	.word	x_airborn
	.word	q_sz_decoy		
	.word	do_sz_decoy		
	.half	0x14		   	
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		
	
	.half	p1b1
	.half	p2b1	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x38
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0					
	

	.word	0

	.align 2
	.globl	sm_osz_lkc
sm_osz_lkc:
	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b4	     		
	.half	p2b4	      		
	.word	x_friend
	.word	q_close_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0		

	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word	q_floor_ice    		
	.word	do_floor_ice   		
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_osz_hkc
sm_osz_hkc:
	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.align 2
	.globl	sm_osz_bc
sm_osz_bc:
	.half	p1b1|p1b2|p1b4 		
	.half	p2b1|p2b2|p2b4 		
	.word	x_ground
	.word	q_slide			
	.word	do_ninja_slide		
	.half	0x00
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

/*
*
* Johhny Cage
*
*/
	.align 2
	.globl	sm_jc_hpc
sm_jc_hpc:
	.half	p1b0
	.half	p2b0	      		
	.word	x_ground
	.word	0
	.word	do_jc_zaphi
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b0
	.half	p2b0	      		
	.word	x_ground
	.word	0
	.word	do_jc_shoruken
	.half	0x38
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	0
	

	.align 2
	.globl	sm_jc_lpc
sm_jc_lpc:
	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_ground
	.word	0
	.word	do_jc_zaplo
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_fatal
	.word	q_close_fatal
	.word	do_fatality_1
	.half	0x38
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					
	
	.word	0

	.align 2
	.globl	sm_jc_lkc
sm_jc_lkc:
	.half	p1b4
	.half	p2b4	      		
	.word	x_ground
	.word	0
	.word	do_jc_shadowkr
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4	      		
	.word	x_ground
	.word	0
	.word	do_jc_shadowk
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	p1b4     		/* player 1 requirements */
	.half	p2b4      		/* player 2 requirements */
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x40
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					/* added field */
	
	.half	p1b4     		/* player 1 requirements */
	.half	p2b4      		/* player 2 requirements */
	.word	x_fatal
	.word	q_robo_flame_fatal
	.word	do_fatality_2
	.half	0x40
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					/* added field */
	
	.word	0


	.align 2
	.globl	sm_jc_hkc
sm_jc_hkc:
	.half	p1b3
	.half	p2b3
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3	     	
	.word	x_animal
	.word	q_swat_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_ind_lkc
sm_ind_lkc:
	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word	q_ind_charge
	.word	do_ind_charge
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0		

	.word	0

	.align 2
	.globl	sm_ind_lpc
sm_ind_lpc:
	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word	0
	.word	do_ind_zap
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1
	.half	p2b1
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_ind_bc
sm_ind_bc:
	.half	p1b2
	.half	p2b2
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_1		
	.half	0x2a
	.half	sw_right
	.half	sw_left
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_ind_dc
sm_ind_dc:
	.half	p1b2	     	
	.half	p2b2	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_friend
	.word	q_ind_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_hi_punch
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_hi_punch
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_ind_hpo
sm_ind_hpo:
	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_fatal
	.word	q_ind_axe_fatal		
	.word	do_fatality_2		
	.half	0x28
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_ind_hpc
sm_ind_hpc:
	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_ground
	.word	0			
	.word	do_axe_up		
	.globl scom_axe_up
scom_axe_up:
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_ind_hkc
sm_ind_hkc:
	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_ground
	.word	0			
	.word	do_reflect		
	.half	0x20
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					
	
	.half	p1b3
	.half	p2b3
	.word	x_ground
	.word	q_ind_charge
	.word	do_ind_charge_fast
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0		


	.half	0			


	.align 2
	.globl	sm_sonya_hpc
sm_sonya_hpc:
	.half	p1b0     		
	.half	p2b0      		
	.word	x_ground
	.word	0			
	.word	do_square_wave		
	.half	0x18
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_fatal
	.word	q_pit_fatal		
	.word	do_pit_fatality		
	.half	0x22
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0



	.align 2
	.globl	sm_sonya_dc
sm_sonya_dc:
	.half	p1b2|p1b5     	
	.half	p2b2|p2b5     	
	.word	x_fatal
	.word	q_bubble_fatal	
	.word	do_fatality_2 	
	.half	0x30
	.half	sw_down
	.half	sw_left
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_sonya_rc
sm_sonya_rc:
	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_friend
	.word	q_sonya_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_fatal
	.word	q_fatality_req		
	.word	do_fatality_1		
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_sonya_lpo
sm_sonya_lpo:
	.half	p1b1	     	
	.half	p2b1	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.word	0



	.align 2
	.globl	sm_sonya_lkc
sm_sonya_lkc:
	.half	p1b4
	.half	p2b4
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					


	.half	0			


	.align 2
	.globl	sm_jax_lpc
sm_jax_lpc:

	.half	p1b1|p1b4
	.half	p2b1|p1b4
	.word	x_ground
	.word  q_noogy			
	.word	do_noogy
	.half	0x18
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_jax_hpc
sm_jax_hpc:
	.half	p1b0|p1b1|p1b4		
	.half	p2b0|p2b1|p2b4 		
	.word	x_ground
	.word	q_jax_zap		
	.word	do_jax_zap1		
	.half	0x10		   	
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			

	.half	p1b0|p1b1|p1b4		
	.half	p2b0|p2b1|p2b4 		
	.word	x_ground
	.word	q_jax_zap		
	.word	do_jax_zap2		
	.half	0x2a		   	
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0			

	.word	0

	.align 2
	.globl	sm_jax_hkc
sm_jax_hkc:
	.half	p1b3|p1b4     		
	.half	p2b3|p1b4      		
	.word	x_ground
	.word	q_jax_dash		
	.word	jax_dash_punch		
	.half	0x10		   	
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			

	.word	0

	.align 2
	.globl	sm_jax_lkc
sm_jax_lkc:
	.half	p1b4	     	
	.half	p2b4     	
	.word	x_fatal
	.word	q_grow_fatal	
	.word	do_fatality_2 	
	.half	0x30
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4			
	.half	p2b4			
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x2a
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_jax_bo
sm_jax_bo:
	.half	p1b2	     	
	.half	p2b2	     	
	.word	x_fatal
	.word	q_close_fatal	
	.word	do_fatality_1 	
	.half	0x28
	.half	sw_up
	.half	sw_right
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	sw_up
	.half	sw_left
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_jax_lpo
sm_jax_lpo:
	.half	p1b1	     	
	.half	p2b1	     	
	.word	x_animal
	.word	q_close_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0
/*
*
* Swat
*
*/
	.align 2
	.globl	sm_sw_bc
sm_sw_bc:
	.half	p1b2|p1b5     		
	.half	p2b2|p2b5      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.half	p1b2	     	
	.half	p2b2	     	
	.word	x_animal
	.word	q_swat_animal	
	.word	do_animality 	
	.half	0x28
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_sw_lkc
sm_sw_lkc:
	.half	p1b4	     		
	.half	p2b4	      		
	.word	x_fatal
	.word	q_taser_fatal		
	.word	do_fatality_1		
	.half	0x1f
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4	     		
	.half	p2b4	      		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_lo_punch
	.half	sw_run
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_lo_punch
	.half	sw_run
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_swat_hkc
sm_swat_hkc:
	.half	p1b2|p1b3      		
	.half	p2b2|p2b3      		
	.word	x_ground
	.word	q_swat_zoom	     		
	.word	do_swat_zoom		
	.half	0x1f
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b3|p1b2
	.half	p2b3|p2b2
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_up
	.half	sw_up
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_swat_lpc
sm_swat_lpc:
	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word	0				
	.word	do_swat_bombslohi
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_ground
	.word	0	     		
	.word	do_swat_bomb_lo		
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_ground
	.word	0	     		
	.word	do_stick_sweep		
	.half	0x10
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_friend
	.word	q_friend     		
	.word	do_friendship		
	.half	0x28
	.half	sw_lo_punch
	.half	sw_run
	.half	sw_run
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	sw_lo_punch
	.half	sw_run
	.half	sw_run
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_swat_hpc
sm_swat_hpc:
	.half	p1b0
	.half	p2b0
	.word	x_ground
	.word	0				
	.word	do_swat_bombshilo
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0		

	.half	p1b0				
	.half	p2b0		 		
	.word	x_ground
	.word	0				
	.word	do_swat_bomb_hi			
	.half	0x10
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b0
	.half	p2b0
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.half	p1b0				
	.half	p2b0		 		
	.word	x_ground
	.word	q_swat_gun			
	.word	do_swat_gun			
	.half	0x18
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0			


	.word	0			

/*
*
* Sheeva
*
*/
	.align 2
	.globl	sm_sg_bc
sm_sg_bc:
	.half	p1b2		    	
	.half	p2b2	     		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality 		
	.half	0x28
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_sg_hko
sm_sg_hko:
	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_fatal
	.word	q_sherip_fatal		
	.word	do_fatality_2		
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_sg_lpc
sm_sg_lpc:
	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_1		
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b1
	.half	p2b1
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0					



	.word	0


	.align 2
	.globl	sm_sg_hkc
sm_sg_hkc:
	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_ground
	.word	0			
	.word	do_sg_quake		
	.half	0x1a
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_sg_hpc
sm_sg_hpc:
	.half	p1b0			
	.half	p2b0			
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b0				
	.half	p2b0		 		
	.word	x_ground
	.word	0				
	.word	do_sg_zap			
	.half	0x10
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	0			

	.align 2
	.globl	sm_sg_uc
sm_sg_uc:
	.half	p1b0|p1b1|p1b2|p1b3|p1b4		
	.half	p2b0|p2b1|p2b2|p2b3|p2b4 		
	.word	x_ground
	.word	q_pounce_ok_now				
	.word	do_sg_pounce				
	.half	0x10
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			

/*
*
* Kung Lao
*
*/
	.align 2
	.globl	sm_lao_lkc
sm_lao_lkc:
	.half	p1b4			
	.half	p2b4	 		
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x30
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_lo_punch
	.half	sw_run
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_lo_punch
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_lao_bc
sm_lao_bc:
	.half	p1b2		    	
	.half	p2b2	     		
	.word	x_animal
	.word	q_close_animal		
	.word	do_animality 		
	.half	0x28
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0					


	.half	0			

	.align 2
	.globl	sm_lao_hpc
sm_lao_hpc:
	.half	p1b0           		
	.half	p2b0         	  	
	.word	x_fatal
	.word	q_lao_hat_fatal		
	.word	do_fatality_2 		
	.half	0x30
	.half	sw_down
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b0
	.half	p2b0
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lao_dc
sm_lao_dc:
	.half	p1b0	     		
	.half	p2b0	      		
	.word	x_fatal
	.word	q_fatality_req		
	.word	do_fatality_1		
	.half	0x2a
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lao_rc
sm_lao_rc:
	.half	p1b5		
	.half	p2b5 		
	.word	x_ground
	.word	q_lao_spin		
	.word	do_lao_spin	
	.half	0x10
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			

/*
*
* Liu Kang
*
*/
	.align 2
	.globl	sm_lk_dc
sm_lk_dc:
	.half	p1b2|p1b5		
	.half	p2b2|p2b5 		
	.word	x_friend
	.word	q_lk_friend		
	.word	do_friendship		
	.half	0x20
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_lk_uc
sm_lk_uc:
	.half	p1b2	     	
	.half	p2b2	     	
	.word	x_animal
	.word	q_lk_animal	
	.word	do_animality 	
	.half	0x30
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			



	.align 2
	.globl	sm_lk_bc
sm_lk_bc:
	.half	p1b2|p1b5     		
	.half	p2b2|p2b5      		
	.word	x_fatal
	.word	q_lk_mk_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_up
	.half	sw_up
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_down
	.half	sw_up
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lk_lkc
sm_lk_lkc:
	.half	p1b4	     		
	.half	p2b4	      		
	.word	x_fatal
	.word	q_fatality_req		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lk_hkc
sm_lk_hkc:
	.half	p1b3|p1b4		
	.half	p2b3|p2b4 		
	.word	x_ground
	.word	0			
	.word	do_super_kang		
	.half	0x1e
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x20
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					


	.word	0


	.align 2
	.globl	sm_lk_hpc
sm_lk_hpc:
	.half	p1b0|p1b4		
	.half	p2b0|p2b4 		
	.word	x_airborn
	.word	0			
	.word	lk_zap_hi		
	.half	0x1a
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lk_lko
sm_lk_lko:
	.half	p1b4			
	.half	p2b4 			
	.word	x_ground
	.word	q_bike_req		
	.word	lk_sbike_kick		
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4			
	.half	p2b4 			
	.word	x_ground
	.word	q_bike_req		
	.word	lk_bike_kick		
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_lk_lpc
sm_lk_lpc:
	.half	p1b1|p1b4		
	.half	p2b1|p2b4		
	.word	x_ground
	.word	0			
	.word	lk_zap_lo		
	.half	0x1a
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

/*
*
* Shang Tsung
*
*/
	.align 2
	.globl	sm_st_hpo
sm_st_hpo:
	.half	p1b0	     	
	.half	p2b0	     	
	.word	x_animal
	.word	q_shang_animal	
	.word	do_animality 	
	.half	0x22
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_st_lpo
sm_st_lpo:
	.half	p1b1	     		
	.half	p2b1	      		
	.word	x_fatal
	.word	q_st_spike_fatal	
	.word	do_fatality_1		
	.half	0x30
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0					

	.half	p1b1|p1b2|p1b5 		
	.half	p2b1|p2b2|p2b5 		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_st_dc
sm_st_dc:
	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_lk	
	.word	do_st_2_lk		
	.half	0x18
	.half	sw_down
	.half	sw_right
	.half	sw_up
	.half	sw_left
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_up
	.half	sw_right
	.half	0
	.half	0
	.half	0					

	.half	p1b2			
	.half	p2b2			
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x28
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_st_lko
sm_st_lko:
	.half	p1b5			
	.half	p2b5			
	.word	x_ground
	.word	q_shang_morph_sg			
	.word	do_st_2_sg		
	.half	0x20
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_st_rc
sm_st_rc:
	.half	p1b5			
	.half	p2b5			
	.word	x_ground
	.word	q_shang_morph_lao			
	.word	do_st_2_lao		
	.half	0x20
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	sw_run
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0					
	

	.half	p1b5			
	.half	p2b5			
	.word	x_ground
	.word	q_shang_morph_osz
	.word	do_st_2_oldsz		
	.half	0x20
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0			

	.half	p1b5			
	.half	p2b5			
	.word	x_ground
	.word	q_shang_morph_kit
	.word	do_st_2_kitana		
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0			
	
	.half	p1b5			
	.half	p2b5			
	.word	x_ground
	.word	q_shang_morph_robo1			
	.word	do_st_2_robo1		
	.half	0x20
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0

	.align 2
	.globl	sm_st_hkc
sm_st_hkc:
	.half	p1b3			
	.half	p2b3			
	.word	x_ground
	.word	q_shang_morph_swat			
	.word	do_st_2_swat		
	.half	0x20
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b3			
	.half	p2b3			
	.word	x_ground
	.word	q_shang_morph_tusk			
	.word	do_st_2_tusk		
	.half	0x10
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_lo_punch
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b3			
	.half	p2b3			
	.word	x_ground
	.word	q_shang_morph_mileena
	.word	do_st_2_mileena		
	.half	0x18
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b3			
	.half	p2b3			
	.word	x_ground
	.word 	q_shang_morph_rep
	.word	do_st_2_reptile		
	.half	0x20
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0				

	.half	p1b3			
	.half	p2b3			
	.word	x_ground
	.word	q_shang_morph_noob
	.word	do_st_2_noob
	.half	0x20
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0				

	.word	0


	.align 2
	.globl	sm_st_uc
sm_st_uc:
	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_ind			
	.word	do_st_2_ind		
	.half	0x20
	.half	sw_up
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word 	q_shang_morph_ermac
	.word	do_st_2_ermac		
	.half	0x20
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_up
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0				

	.word	0


	.align 2
	.globl	sm_st_bc
sm_st_bc:
	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_robo2			
	.word	do_st_2_robo2		
	.half	0x13
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_kano			
	.word	do_st_2_kano		
	.half	0x0b
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_rayden
	.word	do_st_2_rayden
	.half	0x1a
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_baraka
	.word	do_st_2_baraka
	.half	0x1a
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_block
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0				

	.half	p1b2			
	.half	p2b2			
	.word	x_ground
	.word	q_shang_morph_jade
	.word	do_st_2_jade		
	.half	0x1a
	.half	sw_down
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0				

	.word	0


	.align 2
	.globl	sm_st_lpc
sm_st_lpc:
	.half	p1b1			
	.half	p2b1			
	.word	x_ground
	.word	q_shang_morph_jax			
	.word	do_st_2_jax		
	.half	0x1d
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b1|p1b2
	.half	p2b1|p2b2
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x28
	.half	sw_left
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_up
	.half	sw_up
	.half	0
	.half	0
	.half	0
	.half	0					


	.half	p1b1			
	.half	p2b1			
	.word	x_ground
	.word 	q_shang_morph_scorpion
	.word	do_st_2_scorpion	
	.half	0x1a
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0
	.half	0					

	.word	0


	.align 2
	.globl	sm_st_hpc
sm_st_hpc:
	.half	p1b0			
	.half	p2b0			
	.word	x_ground
	.word	q_shang_morph_jc
	.word	do_st_2_jc
	.half	0x18
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0

/*
* shang tsung zap 1
*/
	.half	p1b0			
	.half	p2b0			
	.word	x_ground
	.word	q_st_zap			
	.word	do_st_zap1		
	.half	0x24
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
/*
* shang zap 2
*/
	.half	p1b0			
	.half	p2b0			
	.word	x_ground
	.word	q_st_zap			
	.word	do_st_zap2		
	.half	0x28
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					
/*
* shang zap 3
*/
	.half	p1b0			
	.half	p2b0			
	.word	x_ground
	.word	q_st_zap			
	.word	do_st_zap3		
	.half	0x30
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0					
	.half	0			

	.align 2
	.globl	sm_st_lkc
sm_st_lkc:
	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	q_shang_morph_lia			
	.word	do_st_2_lia		
	.half	0x18
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	q_shang_morph_smoke			
	.word	do_st_2_smoke		
	.half	0x18
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	q_shang_morph_osm
	.word	do_st_2_osm
	.half	0x18
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	q_shang_morph_rain
	.word	do_st_2_rain
	.half	0x18
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					



/*
* summon
*/
	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	0			
	.word	do_summon		
	.half	0x28
	.half	sw_left
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0					

	.half	p1b4
	.half	p2b4
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0					
	.half	0			

/*
*
* Kabal (Tusk)
*
*/
	.align 2
	.globl	sm_tusk_hpo
sm_tusk_hpo:
	.half	p1b0			
	.half	p2b0			
	.word	x_close_animal
	.word	q_kabal_animal		
	.word	do_animality		
	.half	0x28
	.half	sw_right
	.half	sw_down
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	sw_left
	.half	sw_down
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0					

	.word	0
  
	.align 2
	.globl	sm_tusk_uc
sm_tusk_uc:
	.half	p1b5			
	.half	p2b5			
	.word	x_friend
	.word	q_friend		
	.word	do_friendship		
	.half	0x38
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	sw_run
	.half	0
	.half	0
	.half	sw_run
	.half	sw_run
	.half	sw_lo_kick
	.half	sw_run
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_tusk_hkc
sm_tusk_hkc:
	.half	p1b3	     		
	.half	p2b3	      		
	.word	x_fatal
	.word	q_close_fatal		
	.word	do_fatality_2		
	.half	0x30
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	sw_block
	.half	sw_run
	.half	0
	.half	0					

	.half	p1b3
	.half	p2b3
	.word	x_ground
	.word   q_pit_fatal		
	.word	do_pit_fatality 	
	.half	0x18
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	sw_hi_kick
	.half	sw_block
	.half	sw_block
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			

	.align 2
	.globl	sm_tusk_lkc
sm_tusk_lkc:
	.half	p1b4			
	.half	p2b4			
	.word	x_ground
	.word	q_tusk_blur	 	
	.word	do_tusk_blur		
	.half	0x12
	.half	sw_right
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					


	.half	p1b4
	.half	p2b4
	.word	x_baby
	.word	q_babality	
	.word	do_baby 	
	.half	0x28
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	sw_lo_kick
	.half	sw_run
	.half	sw_run
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_tusk_bc
sm_tusk_bc:
	.half	p1b2	     		
	.half	p2b2	      		
	.word	x_fatal
	.word	q_inflate_fatal		
	.word	do_fatality_1		
	.half	0x30
	.half	sw_right
	.half	sw_left
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	sw_left
	.half	sw_right
	.half	sw_down
	.half	sw_down
	.half	0
	.half	0
	.half	0					
	.half	0			


	.align 2
	.globl	sm_tusk_rc
sm_tusk_rc:
	.half	p1b5	     		
	.half	p2b5	      		
	.word	x_ground
	.word	q_floor_blade		
	.word	do_floor_blade		
	.half	0x20
	.half	sw_left
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			

	.align 2
	.globl	sm_tusk_zap
sm_tusk_zap:
	.half	p1b0			
	.half	p2b0			
	.word	x_airborn
	.word	0			
	.word	do_tusk_zap		
	.half	0x18
	.half	sw_left
	.half	sw_left
	.half	0
	.half	0
	.half	0
	.half	0
	.half	sw_right
	.half	sw_right
	.half	0
	.half	0
	.half	0
	.half	0
	.half	0					
	.half	0			


/*
//****************************************************************
// COMBO MOVE TABLES
//****************************************************************
//**************************************************************************
//*											     *
//*  combo table format:									     *
//* 											     *
//*     .half   0xaa         where aa = time allowed					*
//*     .half   0xbbcc       where bb = attack ani    cc = attack ani part  *
//*     .half   0xddee       where dd = attack speed  ee = button number    *
//*     .half   0xffgg       where ff = retract ani   gg = retract ani part *
//*     .half   0xhhii       where hh = stk offset	   ii = requirement      *
//*	   .half   0		   padding (not in arcade, make sure add to new entries)
//*     .word   0xjjjjjjjj   where jj = success pointer				     *
//*											     *
//**************************************************************************
*/

cb_hipunch	=	0x00
cb_lopunch	=	0x01
cb_block	=	0x02
cb_hikick	=	0x03
cb_lokick	=	0x04

cb_jump_address	=	0x1111


stk_0		=	0x0000	/* hit in face */
stk_1		=	0x0100	/* stumble away */
stk_2		=	0x0200	/* knocked on back */
stk_3		=	0x0300	/* knocked high on back */
stk_4		=	0x0400	/* NAILED ! */
stk_nailed	=	stk_4

stk_5		=	0x0500	/* uppercutted */
stk_klang	=		0x0600	/* hit but with a klang sound !! */

stk_1_stab	=		0x0700	/* stumble away */
stk_2_stab	=		0x0800	/* knocked on back */
stk_6		=		0x0900	/* knocked almost vertical on your back */

stk_1w		=		0x0b00	/* weak combo damage */
stk_1_stabw	=		0x0c00	/* weak stab damage */
stk_5w		=		0x0d00	/* uppercutted (weak) */

stk_h0		=		0x1000	/* hit in face */
stk_h1		=		0x1100	/* stumble away */
stk_h2		=		0x1200	/* knocked on back */

c_speed1		=	0x0100
c_speed2		=	0x0200
c_speed3		=	0x0300

last_option	=	0x8000
b_last_option	=	15

req_none		=	0	/* requirement: none */
req_stkaway	=	1	/* requirement: joystick away */
req_fireball = 2 	/* requirement: fireball motion */
req_stktow	=	3	/* requirement: joystick towards */
req_stkdown	=	4
req_halfdamage = 5
req_stkup	= 6
req_q_no	=	7
req_quarterdamage = 8
req_stkawayrain	=	9	/* requirement: joystick away */

retract_elbow	=	0x1002
retract_knee	=	0x1302
retract_lokick	=	0x1202
retract_hikick	=	0x1102


atk_upcut	=	0x0b01

atk_elbow1	=	0x1001
atk_elbow2	=	0x1003
atk_elbow3	=	0x1004
atk_elbow4	=	0x1005
atk_knee1	=	0x1301
atk_knee2	=	0x1303
atk_knee3	=	0x1304
atk_knee4	=	0x1305
atk_knee5	=	0x1306
atk_hikick	=	0x1101
atk_lokick	=	0x1201
atk_roundh	=	0x1501

atk_a2_3	=	0x8003
atk_a2_4	=	0x8004

	.align 2
	.globl ct_ermac_elbow2
ct_ermac_elbow2:
	.half	9|last_option		
	.half	0x8303			
	.half	c_speed2|cb_hipunch	
	.half	0x8002			
	.half	stk_1|req_none		
	.half	0
	.word	ct_ermac_elbow3

	.align 2
	.globl ct_ermac_elbow3
ct_ermac_elbow3:
	.half	9|last_option		
	.half	0x8401			
	.half	c_speed2|cb_lopunch	
	.half	0x8002			
	.half	stk_1|req_stkaway	
	.half	0
	.word	ct_ermac_elbow4

	.align 2
	.globl ct_ermac_elbow4
ct_ermac_elbow4:
	.half	9		  	
	.half	atk_hikick
	.half	c_speed1|cb_hikick	
	.half	0x8402			
	.half	stk_1|req_none		
	.half	0
	.word	ct_ermac_hikick2

	.half	9|last_option		
	.half	0x8401			
	.half	c_speed2|cb_lopunch	
	.half	0x8402			
	.half	stk_5w|req_fireball	
	.word	0x0d

	.align 2
	.globl ct_ermac_hikick2
ct_ermac_hikick2:
	.half	9|last_option		
	.half	atk_hikick
	.half	c_speed1|cb_lokick	
	.half	0x1102			
	.half	stk_2|req_halfdamage	
	.half	0
	.word	0x0e



	.align 2
	.globl ct_osz_elbow2
ct_osz_elbow2:
	.half	9|last_option		
	.half	0x8303
	.half	c_speed2|cb_hipunch	
	.half	0x8002			
	.half	stk_1|req_none		
	.half	0
	.word	ct_osz_elbow3

	.align 2
	.globl ct_osz_elbow3
ct_osz_elbow3:
	.half	9		 	
	.half	atk_a2_4	  	
	.half	c_speed2|cb_lopunch	
	.half	0x8002		   	
	.half	stk_1|req_stkdown  	
	.half	0
	.word	ct_osz_elbow4

	.half	9|last_option	  	
	.half	atk_roundh	  	
	.half	c_speed2|cb_lokick	
	.half	0x8002		  	
	.half	stk_1|req_halfdamage	
	.word	ct_osz_knee2

	.align 2
	.globl ct_osz_elbow4
ct_osz_elbow4:
	.half	9|last_option	  	
	.half	atk_a2_4	  	
	.half	c_speed2|cb_hipunch	
	.half	0x8002		   	
	.half	stk_5|req_stkdown  	
	.half	0
	.word	0x08

	.align 2
	.globl ct_osz_knee2
ct_osz_knee2:
	.half	9|last_option		
	.half	0x1201|0x8000          
	.half	c_speed1|cb_hikick	
	.half	0x1502		  	
	.half	stk_1|req_stkaway  	
	.half	0
	.word	ct_osz_knee3

	.align 2
	.globl ct_osz_knee3
ct_osz_knee3:
	.half	9|last_option	 		
	.half	0x1201|0x8000         	 	
	.half	c_speed1|cb_lokick 		
	.half	0x1502		   		
	.half	stk_nailed|req_stktow  	
	.half	0
	.word	0x0e



	.align 2
	.globl ct_rep_elbow2
ct_rep_elbow2:
	.half	9|last_option			
	.half	atk_a2_3			
	.half	c_speed2|cb_hipunch		
	.half	0x8002				
	.half	stk_1|req_none			
	.half	0
	.word	ct_rep_elbow3

	.align 2
	.globl ct_rep_elbow3
ct_rep_elbow3:
	.half	9		 	
	.half	atk_hikick	  	
	.half	c_speed1|cb_hikick	
	.half	0x8002		  	
	.half	stk_1|req_none	  	
	.half	0
	.word	ct_rep_knee3

	.half	9|last_option	  	
	.half	atk_a2_4	  	
	.half	c_speed2|cb_lopunch	
	.half	0x8002		   	
	.half	stk_5|req_stkdown  	
	.word	0x10

	.align 2
	.globl ct_rep_knee2
ct_rep_knee2:
	.half	9|last_option		
	.half	atk_hikick	  	
	.half	c_speed1|cb_hikick	
	.half	retract_knee		
	.half	stk_1|req_none	  	
	.half	0
	.word	ct_rep_knee3

	.align 2
	.globl ct_rep_knee3
ct_rep_knee3:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_hikick		
	.half	stk_h2|req_stkaway	
	.half	0
	.word	0x10


	.align 2
	.globl ct_rain_elbow2
ct_rain_elbow2:
	.half	9|last_option			
	.half	0x1303|0x8000
	.half	c_speed2|cb_hipunch		
	.half	0x8002				
	.half	stk_0|req_none			
	.half	0
	.word	ct_rain_elbow3

	.align 2
	.globl ct_rain_elbow4
ct_rain_elbow4:
	.half	9|last_option			
	.half	0x1301|0x8000
	.half	c_speed2|cb_hipunch		
	.half	0x8002
	.half	stk_4|req_none			
	.half	0
	.word	0x0f

	.align 2
	.globl ct_rain_knee2
ct_rain_knee2:
	.half	9|last_option			
	.half	0x1305|0x8000
	.half	c_speed1|cb_hikick
	.half	retract_knee
	.half	stk_1|req_none			
	.half	0
	.word	ct_rain_knee3
	
	.align 2
	.globl ct_rain_knee3
ct_rain_knee3:
	.half	9
	.half	0x1306|0x8000
	.half	c_speed2|cb_lokick
	.half	retract_hikick
	.half	stk_1|req_none			
	.half	0
	.word	ct_rain_knee4
	
	.align 2
	.globl ct_rain_elbow3
ct_rain_elbow3:
	.half	9|last_option			
	.half	0x1303|0x8000
	.half	c_speed2|cb_lopunch		
	.half	0x8002				
	.half	stk_0|req_none			
	.half	0
	.word	ct_rain_elbow4

	.align 2
	.globl ct_rain_knee4
ct_rain_knee4:
	.half	9|last_option			
	.half	0x1305|0x8000
	.half	c_speed2|cb_hikick
	.half	retract_lokick
	.half	stk_1w|req_halfdamage
	.half	0
	.word	ct_rain_knee5

	.align 2
	.globl ct_rain_knee5
ct_rain_knee5:
	.half	9|last_option			
	.half	cb_jump_address
	.half	cb_hikick
	.half	retract_hikick
	.half	req_stkaway
	.half	0
	.word	do_roundhouse

	.align 2
	.globl ct_noob_elbow2
ct_noob_elbow2:
	.half	9|last_option			
	.half	atk_elbow3
	.half	c_speed2|cb_hipunch		
	.half	0x8002
	.half	stk_1|req_none			
	.half	0
	.word	ct_noob_elbow3

	.align 2
	.globl ct_noob_elbow3
ct_noob_elbow3:
	.half	9|last_option			
	.half	0x1303|0x8000
	.half	c_speed2|cb_lopunch		
	.half	0x8002
	.half	stk_0|req_none			
	.half	0
	.word	ct_noob_elbow4

	.align 2
	.globl ct_noob_elbow4
ct_noob_elbow4:
	.half	9|last_option			
	.half	0x1303|0x8000
	.half	c_speed2|cb_hikick
	.half	0x8002
	.half	stk_5|req_none			
	.half	0
	.word	0x10

	.align 2
	.globl ct_noob_knee2
ct_noob_knee2:
	.half	9|last_option			
	.half	0x1306|0x8000
/* 	.half	atk_lokick */
	.half	c_speed1|cb_lokick
	.half	retract_knee
	.half	stk_1|req_none			
	.half	0
	.word	ct_noob_knee3

	.align 2
	.globl ct_noob_knee3
ct_noob_knee3:
	.half	9|last_option			
	.half	0x1306|0x8000
/* 	.half	atk_lokick */
	.half	c_speed1|cb_lokick
	.half	retract_knee
	.half	stk_1|req_none			
	.half	0
	.word	ct_noob_knee4

	.align 2
	.globl ct_noob_knee4
ct_noob_knee4:
	.half	9|last_option			
	.half	0x1306|0x8000
/* 	.half	atk_lokick */
	.half	c_speed1|cb_lokick
	.half	retract_knee
	.half	stk_4|req_none			
	.half	0
	.word	0x10

	.align 2
	.globl ct_scorp_elbow2
ct_scorp_elbow2:
	.half	9|last_option			
	.half	atk_elbow2			
	.half	c_speed2|cb_hipunch		
	.half	retract_elbow			
	.half	stk_1|req_none			
	.half	0
	.word	ct_scorp_elbow3

	.align 2
	.globl ct_scorp_elbow3
ct_scorp_elbow3:
	.half	9				
	.half	atk_hikick			
	.half	c_speed1|cb_hikick		
	.half	retract_elbow			
	.half	stk_1|req_none			
	.half	0
	.word	ct_scorp_rhouse

	.half	9|last_option			
	.half	atk_elbow3			
	.half	c_speed2|cb_lopunch		
	.half	retract_elbow			
	.half	stk_2|req_stkup			
	.word	0x10

	.align 2
	.globl ct_scorp_rhouse
ct_scorp_rhouse:
	.half	9|last_option 			
	.half	atk_roundh			
	.half	c_speed2|cb_hikick		
	.half	retract_hikick			
	.half	stk_h2|req_stkaway		
	.half	0
	.word	0x10




	.align 2
	.globl ct_scorp_knee2
ct_scorp_knee2:
	.half	9|last_option			
	.half	atk_knee2			
	.half	c_speed3|cb_hikick		
	.half	retract_knee			
	.half	stk_1|req_none			
	.half	0
	.word	ct_scorp_knee3

	.align 2
	.globl ct_scorp_knee3
ct_scorp_knee3:
	.half	9|last_option			
	.half	atk_knee3			
	.half	c_speed2|cb_lokick		
	.half	retract_knee			
	.half	stk_1|req_none			
	.half	0
	.word	ct_scorp_knee4

	.align 2
	.globl ct_scorp_knee4
ct_scorp_knee4:
	.half	9|last_option			
	.half	atk_knee4			
	.half	c_speed2|cb_lokick		
	.half	retract_knee			
	.half	stk_2|req_none			
	.half	0
	.word	0x10



	.align 2
	.globl ct_jade_elbow2
ct_jade_elbow2:
	.half	9|last_option			
	.half	atk_elbow2			
	.half	c_speed2|cb_hipunch		
	.half	retract_elbow			
	.half	stk_1|req_none			
	.half	0
	.word	ct_jade_elbow3

	.align 2
	.globl ct_jade_elbow3
ct_jade_elbow3:
	.half	9|last_option			
	.half	atk_elbow3			
	.half	c_speed2|cb_lopunch		
	.half	retract_elbow			
	.half	stk_1|req_stkdown		
	.half	0
	.word	ct_jade_elbow4

	.align 2
	.globl ct_jade_elbow4
ct_jade_elbow4:
	.half	9				
	.half	atk_knee1			
	.half	c_speed2|cb_lokick		
	.half	retract_elbow			
	.half	stk_1|req_halfdamage		
	.half	0
	.word	ct_jade_knee2

	.half	9|last_option			
	.half	atk_elbow4			
	.half	c_speed2|cb_hipunch		
	.half	retract_elbow			
	.half	stk_3|req_stkdown		
	.word	0x10

	.align 2
	.globl ct_kitana_knee2
	.globl ct_jade_knee2
ct_kitana_knee2:
ct_jade_knee2:
	.half	9|last_option			
	.half	atk_knee2			
	.half	c_speed3|cb_hikick		
	.half	retract_knee			
	.half	stk_1|req_none			
	.half	0
	.word	ct_jade_knee3

	.align 2
	.globl ct_jade_knee3
ct_jade_knee3:
	.half	9|last_option			
	.half	atk_knee3			
	.half	c_speed3|cb_lokick		
	.half	retract_knee			
	.half	stk_1|req_none			
	.half	0
	.word	ct_jade_knee4

	.align 2
	.globl ct_jade_knee4
ct_jade_knee4:
	.half	9|last_option			
	.half	atk_knee4			
	.half	c_speed3|cb_hikick		
	.half	retract_knee			
	.half	stk_2|req_stkaway		
	.half	0
	.word	0x0e



	.align 2
	.globl ct_mileena_elbow2
ct_mileena_elbow2:
	.half	9|last_option			
	.half	0x1303|0x8000			
	.half	c_speed1|cb_hipunch		
	.half	0x1302|0x8000			
	.half	stk_1|req_none			
	.half	0
	.word	ct_mileena_elbow3

	.align 2
	.globl ct_mileena_elbow3
ct_mileena_elbow3:
	.half	9				
	.half	atk_knee2			
	.half	c_speed3|cb_hikick		
	.half	0x1306|0x8000			
	.half	stk_1|req_halfdamage	 	
	.half	0
	.word	ct_mileena_knee2

 	.half	9|last_option			
	.half	0x1304|0x8000			
	.half	c_speed2|cb_lopunch		
  	.half	0x1306|0x8000			
	.half	stk_1|req_stkup			
	.word	ct_mileena_elbow4

	.align 2
	.globl ct_mileena_elbow4
ct_mileena_elbow4:
	.half	9|last_option			
	.half	0x1305|0x8000			
	.half	c_speed1|cb_lopunch		
	.half	0x1302|0x8000			
	.half	stk_1|req_stkdown		
	.half	0
	.word	0x0e

	.align 2
	.globl ct_mileena_knee2
ct_mileena_knee2:
	.half	9|last_option			
  	.half	atk_knee2   			
	.half	c_speed2|cb_hikick		
	.half	retract_knee			
	.half	stk_1|req_none			
	.half	0
	.word	ct_mileena_knee3

	.align 2
	.globl ct_mileena_knee3
ct_mileena_knee3:
	.half	9				
	.half	atk_knee3			
	.half	c_speed1|cb_lokick		
	.half	retract_hikick			
	.half	stk_5w|req_fireball		
	.half	0
	.word	ct_mileena_dummy1

	.half	9|last_option			
	.half	atk_hikick			
	.half	c_speed1|cb_lokick		
	.half	retract_hikick			
	.half	stk_1|req_stkup			
	.word	ct_mileena_knee4

	.align 2
	.globl ct_mileena_knee4
ct_mileena_knee4:
	.half	9|last_option			
	.half	atk_knee4			
	.half	c_speed2|cb_hikick		
	.half	retract_hikick			
	.half	stk_2|req_stkup			
	.half	0
	.word	0x0e

	.align 2
	.globl ct_mileena_dummy1
ct_mileena_dummy1:
	.half	9|last_option			
	.half	atk_knee4			
	.half	c_speed2|cb_hikick		
	.half	retract_knee
	.half	stk_2|req_q_no			
	.half	0
	.word	0x0e



	.align 2
	.globl ct_kitana_elbow2
ct_kitana_elbow2:
	.half	9|last_option			
	.half	atk_elbow2			
	.half	c_speed2|cb_hipunch		
	.half	retract_elbow			
	.half	stk_1_stab|req_none		
	.half	0
	.word	ct_kit_elbow3

	.align 2
	.globl ct_kit_elbow3
ct_kit_elbow3:
	.half	9|last_option			
	.half	atk_elbow3			
	.half	c_speed2|cb_lopunch		
	.half	0x0e05				
	.half	stk_1_stab|req_stkaway	
	.half	0
	.word	ct_kit_elbow4

	.align 2
	.globl ct_kit_elbow4
ct_kit_elbow4:
	.half	9|last_option			
	.half	atk_elbow4			
	.half	c_speed2|cb_hipunch		
	.half	0x0e05				
	.half	stk_2_stab|req_stktow	
	.half	0
	.word	0x10



	.align 2
	.globl ct_tusk_elbow2
ct_tusk_elbow2:
	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow			
	.half	stk_1_stabw|req_halfdamage	
	.half	0
	.word	ct_tusk_elbow3

	.align 2
	.globl ct_tusk_elbow3
ct_tusk_elbow3:
	.half	9			
	.half	atk_hikick		
	.half	c_speed2|cb_hikick	
	.half	retract_elbow		
	.half	stk_1w|req_none		
	.half	0
	.word	ct_tusk_knee4

	.half	9			
	.half	atk_upcut		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_5w|req_stkdown	
	.word	0x10

	.half	9|last_option			
	.half	atk_elbow3			
	.half	c_speed3|cb_lopunch		
	.half	retract_elbow			
	.half	stk_1_stabw|req_stkdown	
	.word	ct_tusk_elbow4

	.align 2
	.globl ct_tusk_elbow4
ct_tusk_elbow4:
	.half	9|last_option		
	.half	atk_elbow4		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_2_stab|req_stkdown	
	.half	0
	.word	0x1a

	.align 2
	.globl ct_tusk_knee2
ct_tusk_knee2:
	.half	9|last_option		
	.half	atk_knee2		
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_1w|req_none		
	.half	0
	.word	ct_tusk_knee3

	.align 2
	.globl ct_tusk_knee3
ct_tusk_knee3:
	.half	9			
	.half	atk_roundh
	.half	c_speed2|cb_hikick	
	.half	0x1304			
	.half	stk_h2|req_stkaway	
	.half	0
	.word	0x10

	.half	9			
	.half	atk_elbow1		
	.half	c_speed2|cb_hipunch	
	.half	0x1304				
	.half	stk_1_stabw|req_none 	
	.half	0
	.word	ct_tusk_elbow2

	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed2|cb_hikick	
	.half	0x1304			
	.half	stk_h1|req_none		
	.half	0
	.word	ct_tusk_knee4

	.align 2
	.globl ct_tusk_knee4
ct_tusk_knee4:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	0x1102			
	.half	stk_h2|req_stkaway	
	.half	0
	.word	0x10


	.align 2
	.globl ct_rd_knee2
ct_rd_knee2:
	.half	6					/* time allowed */
	.half	atk_knee2			/* attack		*/
	.half	c_speed1|cb_hikick	/* speed,button	*/
	.half	retract_knee		/* retract = knee */
	.half	stk_0|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_rd_knee3

	.align 2
	.globl ct_rd_knee3
ct_rd_knee3:
	.half	9|last_option					/* time allowed */
	.half	atk_knee2			/* attack		*/
	.half	c_speed2|cb_lokick	/* speed,button	*/
	.half	retract_hikick		/* retract = knee */
	.half	stk_1|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_rd_knee4
	
	.align 2
	.globl ct_rd_knee4
ct_rd_knee4:
	.half	9|last_option					/* time allowed */
	.half	atk_roundh			/* attack		*/
	.half	c_speed1|cb_hikick	/* speed,button	*/
	.half	retract_hikick		/* retract = knee */
	.half	stk_2|req_stkaway		/* strike check / requirements*/
	.half	0
	.word   0x0e

	.align 2
	.globl 	ct_rd_elbow2
ct_rd_elbow2:
	.half	9|last_option					/* time allowed */
	.half	atk_upcut			/* attack		*/
	.half	c_speed2|cb_hipunch	/* speed,button	*/
	.half	retract_elbow		/* retract = knee */
	.half	stk_0|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_rd_elbow3

	.align 2
	.globl 	ct_rd_elbow3
ct_rd_elbow3:
	.half	9|last_option					/* time allowed */
	.half	atk_upcut			/* attack		*/
	.half	c_speed2|cb_lopunch	/* speed,button	*/
	.half	retract_elbow		/* retract = knee */
	.half	stk_1|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_rd_elbow4

	.align 2
	.globl 	ct_rd_elbow4
ct_rd_elbow4:
	.half	9					/* time allowed */
	.half	cb_jump_address
	.half	cb_hipunch	/* speed,button	*/
	.half	retract_elbow		/* retract = knee */
	.half	req_stktow	/* strike check / requirements*/
	.half	0
	.word 	do_combo_raiden_dive
	
	.half	9|last_option					/* time allowed */
	.half	atk_upcut			/* attack		*/
	.half	c_speed2|cb_lopunch	/* speed,button	*/
	.half	retract_elbow		/* retract = knee */
	.half	stk_6|req_none		/* strike check / requirements*/
	.half	0
	.word 	9

	.align 2
	.globl ct_sa_knee2
ct_sa_knee2:
	.half	9|last_option					/* time allowed */
	.half	atk_knee2			/* attack		*/
	.half	c_speed2|cb_hikick	/* speed,button	*/
	.half	retract_knee		/* retract = knee */
	.half	stk_0|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_sa_knee3

	.align 2
	.globl ct_sa_knee3
ct_sa_knee3:
	.half	9					/* time allowed */
	.half	atk_lokick			/* attack		*/
	.half	c_speed2|cb_lokick	/* speed,button	*/
	.half	retract_knee		/* retract = knee */
	.half	stk_1|req_none		/* strike check / requirements*/
	.half	0
	.word 	ct_sa_round1
	


	.align 2
	.globl ct_sa_elbow2
ct_sa_elbow2:
	.half	9|last_option			
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch		
	.half	retract_elbow			
	.half	stk_1_stabw|req_none			
	.half	0
	.word	ct_sa_elbow3

	.align 2
	.globl ct_sa_elbow4				
ct_sa_elbow4:
	.half	9|last_option			
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch		
	.half	retract_elbow			
	.half	stk_2_stab|req_stktow
	.half	0
	.word	0x10


	.align 2
	.globl ct_sa_round1
ct_sa_round1:
	.half	9|last_option					/* time allowed */
	.half	atk_roundh			/* attack		*/
	.half	c_speed2|cb_hikick	/* speed,button	*/
	.half	retract_lokick		/* retract = knee */
	.half	stk_h2|req_stkaway		/* strike check / requirements*/
	.half	0
	.word 	0x10

	.align 2
	.globl ct_sg_knee2
ct_sg_knee2:
	.half	9|last_option		
	.half	atk_knee2		
	.half	c_speed3|cb_hikick	
	.half	retract_knee		
	.half	stk_h1|req_none		
	.half	0
	.word	ct_sg_knee3

	.align 2
	.globl ct_sg_knee3
ct_sg_knee3:
	.half	9
	.half	atk_knee3		
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_sg_knee4

	.align 2
	.globl ct_sa_elbow3				/* slice 2 */
ct_sa_elbow3:
	.half	9|last_option			
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch		
	.half	retract_elbow			
	.half	stk_1_stab|req_stkaway			
	.half	0
	.word	ct_sa_elbow4

	.align 2
	.globl ct_sg_knee4
ct_sg_knee4:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_knee		
	.half	stk_h2|req_stkaway	
	.half	0
	.word	0x12


	.align 2
	.globl ct_sg_elbow2
ct_sg_elbow2:
	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_h1|req_none		
	.half	0
	.word	ct_sg_elbow3

	.align 2
	.globl ct_sg_elbow3
ct_sg_elbow3:
	.half	9|last_option		
	.half	atk_elbow3		
	.half	c_speed3|cb_lopunch	
	.half	retract_elbow		
	.half	stk_h1|req_none		
	.half	0
	.word	ct_sg_elbow4

	.align 2
	.globl ct_sg_elbow4
ct_sg_elbow4:
	.half	9			
	.half	atk_knee1		
	.half	c_speed2|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_sg_knee2

	.half	9|last_option		
	.half	atk_elbow4		
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		

	.half	stk_6|req_stktow	
	.word	0x1a



	.align 2
	.globl ct_sonya_knee2
ct_sonya_knee2:
	.half	6			
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_knee		
	.half	stk_0|req_none		
	.half	0
	.word	ct_sonya_roundh

	.half	9|last_option		
	.half	atk_elbow1
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.word	ct_sonya_elbow2

	.align 2
	.globl ct_sonya_roundh
ct_sonya_roundh:
	.half	9			
	.half	atk_roundh
	.half	c_speed3|cb_hikick	
	.half	retract_knee		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x0e

	.align 2
	.globl ct_sonya_elbow1
ct_sonya_elbow1:
	.half	9|last_option		
	.half	0x1007
	.half	c_speed2|cb_hipunch	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_sonya_elbow2


	.align 2
	.globl ct_ind_knee2
ct_ind_knee2:
	.half	9			
	.half	atk_elbow1		
	.half	c_speed2|cb_hipunch	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_ind_elbow2

	.half	6|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_knee		
	.half	stk_1|req_none		
	.word	ct_ind_roundh

	.align 2
	.globl ct_ind_roundh
ct_ind_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_swat_knee2
ct_swat_knee2:
	.half	9			
	.half	atk_elbow1		
	.half	c_speed1|cb_hipunch	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_swat_elbow2

	.align 2
	.globl ct_swat_hikick
ct_swat_hikick:
	.half	6|last_option		
	.half	atk_hikick		
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_swat_baton

	.align 2
	.globl ct_swat_baton
ct_swat_baton:
	.half	9			
	.half	atk_elbow3		
	.half	c_speed1|cb_lopunch	
	.half	retract_knee		
	.half	stk_1|req_stkaway	
	.half	0
	.word	ct_swat_roundh

	.align 2
	.globl ct_swat_roundh
ct_swat_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_swat_elbow2
ct_swat_elbow2:
	.half	6|last_option		
	.half	atk_elbow2		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_swat_elbow3

	.align 2
	.globl ct_swat_elbow3
ct_swat_elbow3:
	.half	4|last_option		
	.half	atk_elbow3		
	.half	c_speed1|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5|req_none		
	.half	0
	.word	0x08



	.align 2
	.globl ct_lk_elbow2
ct_lk_elbow2:
	.half	9			
	.half	atk_elbow2		
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_1w|req_none		
	.half	0
	.word	ct_lk_elbow3

	.align 2
	.globl ct_lk_knee1
ct_lk_knee1:
	.half	9|last_option		
	.half	atk_knee1		
	.half	c_speed3|cb_lokick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_lk_knee2

	.align 2
	.globl ct_lk_elbow3
ct_lk_elbow3:
	.half	9			
	.half	atk_elbow3
	.half	c_speed3|cb_block
	.half	retract_elbow		
	.half	stk_1w|req_none
	.half	0
	.word	ct_lk_knee1

	.half	9|last_option		
	.half	atk_upcut
	.half	c_speed2|cb_lopunch
	.half	retract_elbow		
	.half	stk_5w|req_stkaway
	.half 	0
	.word	0x10

	.align 2
	.globl ct_lk_knee2
ct_lk_knee2:
	.half	9|last_option		
	.half	atk_knee2		
	.half	c_speed3|cb_lokick	
	.half	retract_knee		
	.half	stk_h1|req_none		
	.half	0
	.word	ct_lk_knee3

	.align 2
	.globl ct_lk_knee3
ct_lk_knee3:
	.half	9|last_option		
	.half	atk_knee3		
	.half	c_speed3|cb_hikick	
	.half	retract_knee		
	.half	stk_1w|req_none		
	.half	0
	.word	ct_lk_knee4

	.align 2
	.globl ct_lk_knee4
ct_lk_knee4:
	.half	9|last_option		
	.half	atk_knee4		
	.half	c_speed3|cb_lokick	
	.half	retract_knee		
	.half	stk_4|req_none		
	.half	0
	.word	0x14



	.align 2
	.globl ct_st_knee2
ct_st_knee2:
	.half	9			
	.half	atk_elbow1		
	.half	c_speed2|cb_hipunch	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_st_elbow2

	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed2|cb_hikick	
	.half	retract_knee		
	.half	stk_1|req_none		
	.word	ct_st_roundh

	.align 2
	.globl ct_st_elbow2
ct_st_elbow2:
	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_st_elbow3

	.align 2
	.globl ct_st_elbow3
ct_st_elbow3:
	.half	9|last_option		
	.half	atk_elbow3		
	.half	c_speed3|cb_lopunch	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_st_roundh

	.align 2
	.globl ct_st_roundh
ct_st_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_kano_elbow2
ct_kano_elbow2:
	.half	9|last_option		
	.half	0x1001			
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_kano_post_elbow2

	.align 2
	.globl ct_kano_knee2
ct_kano_knee2:
ct_kano_post_elbow2:
	.half	9			
	.half	atk_knee1		
	.half	c_speed3|cb_hikick	
	.half	retract_elbow		
	.half	0
	.half	stk_0|req_none		
	.word	ct_kano_hikick

	.half	9				
	.half	atk_elbow2			
	.half	c_speed3|cb_lopunch		
	.half	retract_elbow			
	.half	stk_klang|req_stkdown	
	.word	ct_kano_diff_upcut

	.half	9|last_option		
	.half	atk_upcut		
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5|req_none		
	.word	0x10


	.align 2
	.globl ct_ermac_knee2
ct_ermac_knee2:
	.half	9			
	.half	atk_knee1		
	.half	c_speed3|cb_hikick	
	.half	retract_knee		
	.half	stk_0|req_none		
	.half	0
	.word	ct_kano_hikick

	.half	9|last_option		
	.half	atk_upcut		
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5|req_none		
	.word	0x10


	.align 2
	.globl ct_kano_diff_upcut
ct_kano_diff_upcut:
	.half	9|last_option		
	.half	atk_upcut		
	.half	c_speed2|cb_hipunch	
	.half	0x1004			
	.half	stk_5|req_stkdown	
	.half	0
	.word	0x10

	.align 2
	.globl ct_kano_hikick
ct_kano_hikick:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_1|req_none		
	.half	0
	.word	ct_kano_roundh

	.align 2
	.globl ct_kano_roundh
ct_kano_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_knee		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10




	.align 2
	.globl ct_jax_knee2
ct_jax_knee2:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_knee		
	.half	stk_0|req_none		
	.half	0
	.word	ct_jax_roundh

	.align 2
	.globl ct_jax_roundh
ct_jax_roundh:
	.half	9			
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_knee
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10

	.align 2
	.globl ct_jax_elbow1
ct_jax_elbow1:
	.half	9|last_option		
	.half	atk_elbow1		
	.half	c_speed2|cb_hipunch	
	.half	retract_knee		
	.half	stk_1|req_stkdown	
	.half	0
	.word	ct_jax_elbow2


	.align 2
	.globl ct_jax_elbow2
ct_jax_elbow2:
	.half	9|last_option		
	.half	0x1003			
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_jax_elbow3

	.align 2
	.globl ct_jax_elbow3
ct_jax_elbow3:
	.half	9|last_option		
	.half	0x1004			
	.half	c_speed2|cb_block	
	.half	0x0e05			
	.half	stk_0|req_none		
	.half	0
	.word	ct_jax_elbow4

	.align 2
	.globl ct_jax_elbow4
ct_jax_elbow4:
	.half	9|last_option		
	.half	0x1005			
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_3|req_none		
	.half	0
	.word	ct_jax_elbow5

	.align 2
	.globl ct_jax_elbow5
ct_jax_elbow5:
	.half	9|last_option		
	.half	0x1006			
	.half	c_speed2|cb_hipunch	
	.half	0x0e04			
	.half	stk_4|req_stkaway	
	.half	0
	.word	0x0f



	.align 2
	.globl ct_sonya_elbow2
ct_sonya_elbow2:
	.half	9|last_option		
	.half	0x1003			
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_sonya_elbow3

	.align 2
	.globl ct_sonya_elbow3
ct_sonya_elbow3:
	.half	9			
	.half	atk_upcut		
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5|req_stkup		
	.half	0
	.word	0x10

	.half	9|last_option		
	.half	0x1004			
	.half	c_speed3|cb_lopunch	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.word	ct_sonya_elbow4

	.align 2
	.globl ct_sonya_elbow4
ct_sonya_elbow4:
	.half	9|last_option		
	.half	0x1005			
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x0f



	.align 2
	.globl ct_lia_elbow2
ct_lia_elbow2:
	.half	9|last_option		
	.half	0x1003			
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_1_stab|req_none 	
	.half	0
	.word	ct_lia_elbow3_up

	.align 2
	.globl ct_lia_elbow3_up
ct_lia_elbow3_up:
	.half	9			
	.half	0x1004			
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_1_stab|req_none	
	.half	0
	.word	ct_lia_hikick

	.half	9|last_option		
	.half	atk_upcut		
	.half	c_speed2|cb_hipunch	
	.half	retract_elbow		
	.half	stk_5|req_stkdown	
	.word	0x10

	.align 2
	.globl ct_lia_hikick
ct_lia_hikick:
	.half	9|last_option		
	.half	0x1101			
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_none		
	.half	0
	.word	0x08

	.align 2
	.globl ct_lia_knee
ct_lia_knee:
	.half	9			
	.half	0x1001			
	.half	c_speed2|cb_hipunch	
	.half	retract_knee
	.half	stk_1_stab|req_none	
	.half	0
	.word	ct_lia_elbow2

	.half	9|last_option		
	.half	0x1101			
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.word	ct_lia_roundh

	.align 2
	.globl ct_lia_roundh
ct_lia_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	retract_knee
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_sektor_elbow2
ct_sektor_elbow2:
	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_sektor_knee1

	.align 2
	.globl ct_sektor_knee1
ct_sektor_knee1:
	.half	9			
	.half	atk_knee1 		
	.half	c_speed3|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_sektor_roundh1

	.half	9|last_option		
	.half	atk_upcut		
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5|req_stkdown	
	.word	0x10

	.align 2
	.globl ct_sektor_roundh1
ct_sektor_roundh1:
	.half	9			
	.half	atk_knee2 		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10

	.align 2
	.globl ct_wimpy_hikick
ct_wimpy_hikick:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_sektor_roundh2

	.align 2
	.globl ct_sektor_roundh2
ct_sektor_roundh2:
	.half	9|last_option		
	.half	atk_knee2 		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_cyrax_elbow2
ct_cyrax_elbow2:
	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_cyrax_eknee1

	.align 2
	.globl ct_cyrax_eknee1
ct_cyrax_eknee1:
	.half	9			
	.half	0x1004			
	.half	c_speed3|cb_lopunch	
	.half	retract_elbow		
	.half	stk_2|req_none		
	.half	0
	.word	0x0e

	.half	9|last_option		
	.half	atk_knee1 		
	.half	c_speed3|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.word	ct_cyrax_elbow3

	.align 2
	.globl ct_cyrax_elbow3
ct_cyrax_elbow3:
	.half	9|last_option		
	.half	atk_elbow1		
	.half	c_speed3|cb_hipunch	
	.half	retract_knee		
	.half	stk_0|req_none		
	.half	0
	.word	ct_cyrax_eknee2

	.align 2
	.globl ct_cyrax_eknee2
ct_cyrax_eknee2:
	.half	9|last_option		
	.half	atk_knee1 		
	.half	c_speed3|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_cyrax_hikick

	.align 2
	.globl ct_cyrax_hikick
ct_cyrax_hikick:
	.half	9|last_option		
	.half	atk_hikick 		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10

	.align 2
	.globl ct_cyrax_knee2
ct_cyrax_knee2:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half  	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_cyrax_roundh2

	.align 2
	.globl ct_cyrax_roundh2
ct_cyrax_roundh2:
	.half	9|last_option		
	.half	atk_roundh 		
	.half	c_speed2|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x10



	.align 2
	.globl ct_sektor_knee2
ct_sektor_knee2:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_none		
	.half	0
	.word	0x0e



	.align 2
	.globl ct_smoke_elbow2
ct_smoke_elbow2:
	.half	9|last_option		
	.half	0x1003			
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_smoke_elbow3

	.align 2
	.globl ct_smoke_elbow3
ct_smoke_elbow3:
	.half	9			
	.half	0x1301			
	.half	c_speed3|cb_lokick	
	.half	retract_elbow		
	.half	stk_0|req_none		
	.half	0
	.word	ct_smoke_knee2

	.half	9			
	.half	0x1101			
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_none		
	.word	0x0e

	.half	9|last_option		
	.half	0x1004			
	.half	c_speed3|cb_lopunch	
	.half	retract_knee		
	.half	stk_2|req_none		
	.word	0x0e

	.align 2
	.globl ct_smoke_knee2
ct_smoke_knee2:
	.half	9|last_option		
	.half	atk_hikick		
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_1|req_none		
	.half	0
	.word	ct_smoke_turnaround

	.align 2
	.globl ct_smoke_turnaround
ct_smoke_turnaround:
	.half	9|last_option		
	.half	0x1004			
	.half	c_speed3|cb_lopunch	
	.half	retract_knee		
	.half	stk_2|req_none		
	.half	0
	.word	0x0e



	.align 2
	.globl ct_jc_elbow2
ct_jc_elbow2:
	.half	9|last_option		
	.half	atk_elbow2
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	stk_0
	.half	0
	.word	ct_jc_elbow3

	.align 2
	.globl ct_jc_elbow3
ct_jc_elbow3:
	.half	9|last_option
	.half	atk_elbow3		
	.half	c_speed3|cb_lopunch
	.half	retract_elbow		
	.half	stk_1w			
	.half	0
	.word	ct_jc_elbow4

	.align 2
	.globl ct_jc_elbow4
ct_jc_elbow4:
	.half	9|last_option
	.half	atk_elbow4
	.half	c_speed3|cb_lopunch	
	.half	retract_elbow		
	.half	stk_5w|req_stkdown
	.half	0
	.word	9

	.align 2
	.globl ct_jc_knee2
ct_jc_knee2:
	.half	12|last_option		
	.half	atk_knee2
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	0x0100	
	.half	0
	.word	ct_jc_knee3

	.align 2
	.globl ct_jc_knee3
ct_jc_knee3:
	.half	9|last_option		
	.half	atk_knee1
	.half	c_speed3|cb_hikick	
	.half	retract_knee		
	.half	stk_0
	.half	0
	.word	ct_jc_knee4

	.align 2
	.globl ct_jc_knee4
ct_jc_knee4:
	.half	9|last_option
	.half	atk_knee1
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_1
	.half	0
	.word	ct_jc_knee5

	.align 2
	.globl ct_jc_knee5
ct_jc_knee5:
	.half	9|last_option
	.half	atk_knee2
	.half	c_speed2|cb_lokick	
	.half	retract_knee		
	.half	stk_4
	.half	0
	.word	10


	.align 2
	.globl ct_ind_elbow2
ct_ind_elbow2:
	.half	9|last_option		
	.half	0x1003			
	.half	c_speed3|cb_hipunch	
	.half	retract_elbow		
	.half	0x0000			
	.half	0
	.word	ct_ind_elbow3

	.align 2
	.globl ct_ind_elbow3
ct_ind_elbow3:
	.half	9|last_option		
	.half	0x1004			
	.half	c_speed2|cb_lopunch	
	.half	retract_elbow		
	.half	0x0000			
	.half	0
	.word	ct_ind_hikick

	.align 2
	.globl ct_ind_hikick
ct_ind_hikick:
	.half	9			
	.half	cb_jump_address
	.half	cb_hipunch		
	.half	retract_elbow		
	.half	0x0002			
	.half	0
	.word	do_fast_axe_up

	.half	9|last_option		
	.half	0x1101			
	.half	c_speed1|cb_hikick	
	.half	retract_elbow		
	.half	stk_2|req_none		
	.word	0x20

/*
**************************************************************************
*											     *
*  Kung Lao Combos									     *
*											     *
**************************************************************************
*/
	.align 2
	.globl ct_lao_elbow2
ct_lao_elbow2:
	.half	9			
	.half	atk_hikick		
	.half	c_speed1|cb_lokick	
	.half	0x1002			
	.half	0x0000			
	.half	0
	.word	ct_lao_roundh

	.half	9|last_option		
	.half	atk_elbow2		
	.half	c_speed3|cb_lopunch	
	.half	0x1002			
	.half	0x0000			
	.word	ct_lao_elbow3		

	.align 2
	.globl ct_lao_elbow3
ct_lao_elbow3:
	.half	9|last_option		
	.half	0x1004  			
	.half	0x0300  			
	.half	0x1002			
	.half	0x0000			
	.half	0
	.word	ct_lao_elbow4		

	.align 2
	.globl ct_lao_elbow4
ct_lao_elbow4:
	.half	9|last_option		
	.half	0x1005  			
	.half	0x0301  			
	.half	0x1002			
	.half	0x0000			
	.half	0
	.word	ct_lao_e2k		



	.align 2
	.globl ct_lao_e2k
ct_lao_e2k:
	.half	9|last_option		
	.half	atk_knee1		
	.half	c_speed2|cb_lokick	
	.half	retract_elbow
	.half	stk_1|req_none		
	.half	0
	.word	ct_lao_knee2		

	.align 2
	.globl ct_lao_roundh
ct_lao_roundh:
	.half	9|last_option		
	.half	atk_roundh		
	.half	c_speed2|cb_hikick	
	.half	0x1102			
	.half	stk_2|req_stkaway	
	.half	0
	.word	0x0e			

	.align 2
	.globl ct_lao_knee2
ct_lao_knee2:
	.half	9|last_option		
	.half	atk_knee2		
	.half	c_speed3|cb_lokick	
	.half	retract_knee		
	.half	0x0000			
	.half	0
	.word	ct_lao_knee3		

	.align 2
	.globl ct_lao_knee3
ct_lao_knee3:
	.half	9|last_option		
	.half	atk_knee3		
	.half	c_speed2|cb_hikick	
	.half	0x1102			
	.half	stk_4|req_none		
	.half	0
	.word	0x0e	 		


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
