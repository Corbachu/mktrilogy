/*
;****************************************
;** MUST MATCH DEFINITIONS IN mkutil.h **
;****************************************
*/
#define CUT_FRAME       1

ani_jump		=	1		/* animation script "jump" command	*/
ani_flip		=	2		/* animation script "flip" command	*/
ani_adjustx		=	3		/* animation script "adjust x" command	*/
ani_adjustxy	=	4		/* animation script "adjust xy" command	*/
ani_nosleep		=	5		/* animation script "skip sleep" command	*/
ani_calla		=	6		/* animation script call routine (next long)	*/
ani_sound		=	7		/* animation script make a sound call	*/
ani_ochar_jump	=	8		/* animation script ochar conditional jump	*/
ani_flip_v		=	9		/* animation script vertical flip	*/
ani_offset_xy	=	10		/* animation script offset xy	*/
ani_sladd		=	11		/* animation script add slave	*/
ani_slani		=	12		/* animation script slave animate	*/
ani_swpal		=	13		/* animation script switch to next img pal	*/
ani_slani_sleep =	14		/* animation script slave animate then sleep	*/
ani_ochar_sound	= 	15		/* animation script player char sound	*/
ani_lastcom		=	15		/* last animation command	*/

ft_kano			= 0
ft_sonya		= 1
ft_jax			= 2
ft_indian		= 3
ft_subzero		= 4
ft_swat			= 5
ft_lia			= 6
ft_robo1		= 7
ft_robo2		= 8
ft_lao			= 9
ft_tusk			= 10
ft_sg			= 11	
ft_st			= 12			
ft_lk			= 13			
ft_smoke		= 14
ft_kitana		= 15
ft_jade			= 16
ft_mileena		= 17
ft_scorpion		= 18
ft_reptile		= 19
ft_ermac		= 20
ft_oldsz		= 21
ft_oldsmoke		= 22
ft_noob			= 23
ft_rayden		= 24
ft_baraka		= 25
ft_rain			= 26
ft_kamel		= 27
ft_motaro		= 30
ft_sk	  		= 31

/* ENDING OVERLAYS 	*/
OVL_END1	=	4
OVL_END2	=	5
OVL_END3	=	6
OVL_END4	=	7
OVL_END5	=	8
OVL_END6	=	9

/* FONT INFO	*/
FONT15			= 0			/* 15 pt italic	*/
FONT7			= 1			/* 7 pt italic	*/
FONT7N			= 2			/* 7 pt normal	*/

/* TEXT ROUTINES	*/
STRCNRMOS		= 0
STRCNRMOS_SCR	= 1
STRLNRMOS_SCR	= 2
STRRNRMOS_SCR	= 3
STRCNRMO_SCR	= 4
STRLNRMO_SCR	= 5
STRRNRMO_SCR	= 6


/* FLASH STUFF	*/
END_STUFF = 0x0000
RGB_BLACK = 0x0001
RGB_RED = 0xf801
RGB_BLUE = 0x003f
RGB_WHITE = 0xffff
RGB_GREY = 0xb601
RGB_YELLOW = 0xffc1
RGB_GREEN = 0x0701
RGB_DARK_BLUE =	0x0029

/* calla codes index, must match in mkani.h	*/
/* JAX	*/
sweep_sounds		=	1
lineup_number_2		=	2

/*INDIAN	*/
delete_slave		=	3

/*TUSK	*/
rsnd_big_whoosh		=	4

/*SONYA	*/
player_normpal		=	5
sans_repell_3		=	6
sonya_zap_pal		=	7
rsnd_footstep		=	8

/*LIU KANG	*/
air_dragon			=	9
lower_dragon		= 10

/*LIA	*/
slave_inviso		=	11
slave_viso			=	12
new_float_ani		=	13

/*ROBO1 ROBO2	*/
shock_init			=	14
stun_speed_3		=	15
stun_speed_6		=	16
shock_check			=	17
set_a10_to_him		=	18
set_a10_to_slave	=	19

/*SWAT	*/
stsw_sound		=	20

/*SHANG	*/
st_tumble_sound		=	21
morph_swpal		=	22

/*MOTARO	*/
motaro_leg_stance	=	23

rsnd_stab		=	24
rsnd_whoosh = 25
rsnd_big_block = 26
camp_fire_sound = 27
beep_sound = 28
robo_laugh_sound = 29

/*Shao	*/
sk_ray1 = 30
sk_ray2 = 31
sk_ray3 = 32

rsnd_small_block	=	33

/*JADE	*/
boomerang_adjust	=	34

/*KITANA	*/
spawn_bubble	=	35

use_shakbod_pal	=	36

/* rayden */
me_in_back	= 37

/* rain */
adj_rain_proj	= 38

/* noob */
adj_noob_proj	= 39

low_z_slavepri	= 40

arrow_red_check = 41
axe_red_check = 42
slave_pal_change = 43

/*PERM PALETTE	*/
	.extern	SCORE_P		
	.extern	bpal_black_P		
	.extern	bpal_red_P		
	.extern	bpal_blue_P		
	.extern	bpal_white_P		
	.extern	bpal_flash1_P		
	.extern	bpal_flash2_P		
	.extern	bpal_flash3_P		

	.extern	WHITE_p		
	.extern	RED_p		
	.extern	BLACK_p		

