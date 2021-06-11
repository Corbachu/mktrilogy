**************************************************************************
*											     *
*  mk3 - Kitana / Mileena / Jade									*
*											     *
**************************************************************************
	.FILE	'mkfn.asm'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.include imgtbl.glo
	.include mainequ.asm
	.include sysequ.asm
	.include mkfn.tbl
	.include mkfn2.tbl

	.include mkfrend3.tbl
	.include fornow.tbl

	.text

fn_anitab1
	.long	a_stance	;  0 - stance
	.long	a_walkf		;  1 - walk forward
	.long	a_walkb		;  2 - walk backward
	.long	a_turn		;  3 - turn around (standing)
	.long	a_duck		;  4 - duck
	.long	a_duck_turn	;  5 - duck turnaround
	.long	a_duck_block	;  6 - duck block
	.long	a_duck_hit	;  7 - duck hit
	.long	a_duck_punch	;  8 - duck punch
	.long	a_duck_kick_hi	;  9 - duck high kick
	.long	a_duck_kick_lo	;  a - duck low kick
	.long	a_uppercut	;  b - uppercut
	.long	a_block		;  c - block (standing)
	.long	a_victory	;  d - victory
	.long	a_hipunch	;  e - punch high
	.long	a_lopunch	;  f - punch low
	.long	a_elbow		; 10
	.long	a_hikick 	; 11
	.long	a_lokick 	; 12
	.long	a_knee		; 13
	.long	a_sweep_kick	; 14
	.long	a_roundhouse	; 15
	.long	a_jump		; 16
	.long	a_jump_kick	; 17
	.long	a_flip_punch	; 18
	.long	a_flip_kick	; 19
	.long	a_fflip		; 1a
	.long	a_bflip		; 1b
	.long	a_hit_hi	; 1c
	.long	a_hit_lo	; 1d
	.long	a_knockdown	; 1e
	.long	a_sweep_fall	; 1f
	.long	a_stumble	; 20
	.long	a_getup		; 21
	.long	a_sweepup	; 22 -
	.long	a_throw		; 23 -
	.long	a_zap		; 24 - 
	.long	a_dizzy		; 25 -
	.long	a_fb_kano	; 26 - flipped by kano
	.long	a_fb_sonya	; 27 - flipped by sonya
	.long	a_fb_jax	; 28 - flipped by jax
	.long	a_fb_ind	; 29 - flipped by indian
	.long	a_fb_sz		; 2a	- flipped by subzero
	.long	a_fb_swat	; 2b - flipped by swat
	.long	a_fb_lia	; 2c	- flipped by lia
	.long	a_fb_robo	; 2d	- flipped by robot ninja
	.long	a_fb_robo2	; 2e	- flipped by robot ninja 2
	.long	a_fb_lao	; 2f	- flipped by kung lao
	.long	a_fb_tusk	; 30 - flipped by tusk
	.long	a_fb_sg         ; 31 - flipped by she goro
	.long	a_fb_st		; 32	- flipped by shang tsung
   	.long	a_fb_lk		; 33 - flipped by liu kang
	.long	a_fb_smoke	; 34	- flipped by smoke
	.long	a_fb_kitana	; 35 -
	.long	a_fb_jade	; 36 -
	.long	a_fb_mileena	; 37 - flipped by mileena
	.long	a_fb_nj		; 38 - flipped by male ninja (scorpion)
	.long	a_fb_nj		; 39 - flipped by male ninja (reptile)
	.long	a_fb_nj		; 3a - flipped by male ninja (ermac)
	.long	a_fb_nj		; 3b - flipped by male ninja (oldsz)
	.long	a_fb_nj		; 3c - flipped by male ninja (oldsmoke)
	.long	a_fb_nj		; 3d - flipped by male ninja (noob)
	.long	a_fb_nj		; 3e - flipped by male ninja (rain)
	.long	a_fb_nj		; 3f - flipped by male ninja (rayden)
	.long	a_fb_nj		; 40 - flipped by male ninja (baraka)

	.long	a_afb_kano	; 3d - air flipped by kano
	.long	a_legged	; 3e - legged by sonya
	.long	a_projectile	; 3f - projectile animation
	.long	a_shook		; 40 - shook by kano
	.long	a_afb_robo2	; 41 - air flipped by robo2
	.long	a_zoomed	; 42 - zoomed
	.long	a_orb_banged	; 43 - hit by reptile's obj thingy
	.long	a_jade_shook	; 44 - shook by jade
	.long	0			; 45
	.long	a_run		; 46 - run
	.long	a_thudd		; 47	-
	.long	a_scared	; 48 
	
	.long	a_back_break
	.long	a_baby
	.long	a_big_head
	.long	a_half_cutup
	.long	a_cutup
	.long	a_float
	.long	a_pounded
	.long	a_reach
	.long	a_skin_rip
	.long	a_stretch
	.long	a_suk
	.long	a_shocked
	.long	a_shredded

fn_anitab2
	.long	a_kit_airfan			; 0
	.long	a_fan_lift			; 1
	.long	a_jade_zap			; 2
	.long	a_square			; 3
	.long	a_boomerang			; 4
	.long	a_fan_decap			; 5
	.long	a_kitana_kiss			; 6
	.long	0
	.long	a_kitana_bubbles		; 8
	.long	a_bunny				; 9
	.long	a_rod_shaker			; a
	.long	a_rod_impale			; b
	.long	a_kitty				; c
	.long	a_pogo_stick			; d
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	a_mileena_elbow			; 13
	.long	a_throw_sai			; 14
	.long	a_sai_fly			; 15
	.long	a_swallow_nails			; 16
	.long	0
	.long	a_suck_spit			; 18
	.long	a_skunk				; 19
	.long	a_mirror_mirror			; 1a

;**********************************************************************

a_dummy
a_stance
	.long	ani_ochar_jump
	.long	ft_jade
	.long	a_jade_stance

	.long	ani_ochar_jump
	.long	ft_mileena
	.long	a_mileena_stance

	.long	KTSTANCE1
	.long	KTSTANCE2
	.long	KTSTANCE3
	.long	KTSTANCE4
	.long	KTSTANCE5
	.long	KTSTANCE6
	.long	KTSTANCE7
	.long	KTSTANCE8
	.long	ani_jump,a_stance

KTSTANCE1
	.long	KTSTANCE1A,KTSTANCE1B,0
KTSTANCE2
	.long	KTSTANCE2A,KTSTANCE2B,0
KTSTANCE3
	.long	KTSTANCE3A,KTSTANCE3B,0
KTSTANCE4
	.long	KTSTANCE4A,KTSTANCE4B,0
KTSTANCE5
	.long	KTSTANCE5A,KTSTANCE5B,0
KTSTANCE6
	.long	KTSTANCE6A,KTSTANCE6B,0
KTSTANCE7
	.long	KTSTANCE7A,KTSTANCE7B,0
KTSTANCE8
	.long	KTSTANCE8A,KTSTANCE8B,0

a_jade_stance
	.long	JDSTANCE1
	.long	JDSTANCE2
	.long	JDSTANCE3
	.long	JDSTANCE4
	.long	JDSTANCE5
	.long	JDSTANCE6
	.long	JDSTANCE7

;	.long	ani_jump,a_st_2_jade

	.long	ani_jump,a_jade_stance

JDSTANCE1
	.long	JDSTANCE1A,JDSTANCE1B,0
JDSTANCE2
	.long	JDSTANCE2A,JDSTANCE2B,0
JDSTANCE3
	.long	JDSTANCE3A,JDSTANCE3B,0
JDSTANCE4
	.long	JDSTANCE4A,JDSTANCE4B,0
JDSTANCE5
	.long	JDSTANCE5A,JDSTANCE5B,0
JDSTANCE6
	.long	JDSTANCE6A,JDSTANCE6B,0
JDSTANCE7
	.long	JDSTANCE7A,JDSTANCE7B,0


a_mileena_stance
	.long	MLSTANCE1
	.long	MLSTANCE2
	.long	MLSTANCE3
	.long	MLSTANCE4
	.long	MLSTANCE5
	.long	MLSTANCE6
	.long	MLSTANCE7
	.long	MLSTANCE8
	.long	MLSTANCE9
	.long	ani_jump,a_mileena_stance

MLSTANCE1
	.long	MLSTANCE1A,MLSTANCE1B,0
MLSTANCE2
	.long	MLSTANCE2A,MLSTANCE2B,0
MLSTANCE3
	.long	MLSTANCE3A,MLSTANCE3B,0
MLSTANCE4
	.long	MLSTANCE4A,MLSTANCE4B,0
MLSTANCE5
	.long	MLSTANCE5A,MLSTANCE5B,0
MLSTANCE6
	.long	MLSTANCE6A,MLSTANCE6B,0
MLSTANCE7
	.long	MLSTANCE7A,MLSTANCE7B,0
MLSTANCE8
	.long	MLSTANCE8A,MLSTANCE8B,0
MLSTANCE9
	.long	MLSTANCE9A,MLSTANCE9B,0






a_walkf	.long	KTWALK1
	.long	KTWALK2
	.long	KTWALK3
	.long	KTWALK4
	.long	KTWALK5
	.long	KTWALK6
	.long	KTWALK7
	.long	KTWALK8
	.long	KTWALK9
	.long	ani_jump,a_walkf

a_walkb	.long	KTWALK9
	.long	KTWALK8
	.long	KTWALK7
	.long	KTWALK6
	.long	KTWALK5
	.long	KTWALK4
	.long	KTWALK3
	.long	KTWALK2
	.long	KTWALK1
	.long	ani_jump,a_walkb

KTWALK1	.long	KTWALKLEG1A,KTWALKLEG1B,KTTORSO1A,0
KTWALK2	.long	KTWALKLEG2A,KTWALKLEG2B,KTTORSO2A,0
KTWALK3	.long	KTWALKLEG3A,KTTORSO3A,0
KTWALK4	.long	KTWALKLEG4A,KTWALKLEG4B,KTTORSO4A,0
KTWALK5	.long	KTWALKLEG5A,KTWALKLEG5B,KTTORSO5A,0
KTWALK6	.long	KTWALKLEG6A,KTTORSO6A,0
KTWALK7	.long	KTWALKLEG7A,KTTORSO7A,0
KTWALK8	.long	KTWALKLEG8A,KTWALKLEG8B,KTTORSO8A,0
KTWALK9	.long	KTWALKLEG9A,KTWALKLEG9B,KTTORSO9A,0

;**********************************************************************

a_turn
	.long	KTTURN1
	.long	KTTURN2
	.long	ani_flip
	.long	KTTURN1
	.long	0

KTTURN1	.long	KTTURN1A,KTTURN1B,0
KTTURN2	.long	KTTURN2A,KTTURN2B,0

;**********************************************************************

a_duck
	.long	KTDUCK1
	.long	KTDUCK2
	.long	KTDUCK3
	.long	0

KTDUCK1	.long	KTDUCK1A,KTDUCK1B,0
KTDUCK2	.long	KTDUCK2A,KTDUCK2B,0
KTDUCK3	.long	KTDUCK3A,0

;**********************************************************************

a_duck_turn
	.long	KTDUCKTURN1
	.long	KTDUCKTURN2
	.long	ani_flip
	.long	KTDUCKTURN1
	.long	KTDUCK3
	.long	0

KTDUCKTURN1
	.long	KTDUCKTURN1A,KTDUCKTURN1B,0
KTDUCKTURN2
	.long	KTDUCKTURN2A,KTDUCKTURN2B,0

;**********************************************************************

a_duck_block
	.long	KTDUCKBLOCK1
	.long	KTDUCKBLOCK2
	.long	KTDUCKBLOCK3
	.long	0

KTDUCKBLOCK1
	.long	KTDUCKBLOCK1A,KTDUCKBLOCK1B,0
KTDUCKBLOCK2
	.long	KTDUCKBLOCK2A,KTDUCKBLOCK2B,0
KTDUCKBLOCK3
	.long	KTDUCKBLOCK3A,KTDUCKBLOCK3B,0

;**********************************************************************

a_duck_hit
	.long	KTDUCKHIT2
	.long	KTDUCKHIT3
	.long	KTDUCKHIT2
	.long	KTDUCKHIT1
	.long	0

KTDUCKHIT1
	.long	KTDUCKHIT1A,KTDUCKHIT1B,0
KTDUCKHIT2
	.long	KTDUCKHIT2A,KTDUCKHIT2B,0
KTDUCKHIT3
	.long	KTDUCKHIT3A,KTDUCKHIT3B,0

;*************************************

a_duck_punch
	.long	KTDUCKPUNCH1
	.long	KTDUCKPUNCH2
	.long	KTDUCKPUNCH3
	.long	0
	.long	KTDUCKPUNCH2
	.long	KTDUCKPUNCH2
	.long	KTDUCK3
	.long	0

KTDUCKPUNCH1
	.long	KTDUCKPUNCH1A,KTDUCKPUNCH1B,0
KTDUCKPUNCH2
	.long	KTDUCKPUNCH2A,KTDUCKPUNCH2B,0
KTDUCKPUNCH3
	.long	KTDUCKPUNCH3A,KTDUCKPUNCH3B,0

;*************************************

a_duck_kick_hi
	.long	KTDUCKHIKICK1
	.long	KTDUCKHIKICK2
	.long	KTDUCKHIKICK3
	.long	KTDUCKHIKICK4
	.long	0
	.long	KTDUCKHIKICK3
	.long	KTDUCKHIKICK2
	.long	KTDUCKHIKICK1
	.long	KTDUCK3
	.long	0

KTDUCKHIKICK1
	.long	KTDUCKHIKICK1A,0
KTDUCKHIKICK2
	.long	KTDUCKHIKICK2A,KTDUCKHIKICK2B,0
KTDUCKHIKICK3
	.long	KTDUCKHIKICK3A,KTDUCKHIKICK3B,0
KTDUCKHIKICK4
	.long	KTDUCKHIKICK4A,KTDUCKHIKICK4B,0

;*************************************

a_duck_kick_lo
	.long	KTDUCKLOKICK1
	.long	KTDUCKLOKICK2
	.long	KTDUCKLOKICK3
	.long	0
	.long	KTDUCKLOKICK2
	.long	KTDUCKLOKICK1
	.long	KTDUCK3
	.long	0

KTDUCKLOKICK1
	.long	KTDUCKLOKICK1A,KTDUCKLOKICK1B,0
KTDUCKLOKICK2
	.long	KTDUCKLOKICK2A,KTDUCKLOKICK2B,0
KTDUCKLOKICK3
	.long	KTDUCKLOKICK3A,KTDUCKLOKICK3B,KTDUCKLOKICK3C,0

;*************************************

a_uppercut
	.long	KTUPPERCUT2
	.long	KTUPPERCUT3
	.long	KTUPPERCUT4
	.long	KTUPPERCUT5
	.long	ani_nosleep	; dont sleep after next frame
	.long	KTUPPERCUT8
	.long	0
	.long	KTHIPUNCH1
	.long	0

KTUPPERCUT2
	.long	KTUPPERCUT2A,0
KTUPPERCUT3
	.long	KTUPPERCUT3A,0
KTUPPERCUT4
	.long	KTUPPERCUT4A,KTUPPERCUT4B,0
KTUPPERCUT5
	.long	KTUPPERCUT5A,KTUPPERCUT5B,KTUPPERCUT5C,0
KTUPPERCUT8
	.long	KTUPPERCUT8A,KTUPPERCUT8B,0

;*************************************

a_block
	.long	KTBLOCK1
	.long	KTBLOCK2
	.long	KTBLOCK3
	.long	0

KTBLOCK1
	.long	KTBLOCK1A,KTBLOCK1B,0
KTBLOCK2
	.long	KTBLOCK2A,KTBLOCK2B,0
KTBLOCK3
	.long	KTBLOCK3A,KTBLOCK3B,0

;*************************************

a_victory
	.long	ani_ochar_jump
	.long	ft_jade
	.long	a_jade_victory		; jade has a different victory

	.long	ani_ochar_jump
	.long	ft_mileena
	.long	a_mileena_vic

	.long	KTVICTORY1
	.long	KTVICTORY2
	.long	KTVICTORY3
	.long	KTVICTORY4
	.long	KTVICTORY5
	.long	KTVICTORY6
	.long	0

a_jade_victory
	.long	ani_sladd,ROD2
	.long	JDVICTORY2
	.long	ani_slani,ROD3
	.long	JDVICTORY3
	.long	ani_slani,ROD4
	.long	JDVICTORY4
	.long	ani_slani,ROD5
	.long	JDVICTORY5
	.long	ani_slani,ROD6
	.long	JDVICTORY6
	.long	ani_slani,ROD7
	.long	JDVICTORY7
	.long	ani_slani,ROD8
	.long	JDVICTORY8
	.long	ani_slani,ROD9
	.long	JDVICTORY9
	.long	ani_slani,ROD10
	.long	JDVICTORY10
	.long	ani_slani,ROD11
	.long	JDVICTORY11
	.long	ani_slani,ROD12
	.long	JDVICTORY12
	.long	ani_slani,ROD13
	.long	JDVICTORY13
	.long	ani_slani,ROD14
	.long	JDVICTORY14
	.long	ani_slani,ROD15
	.long	JDVICTORY15
	.long	ani_calla,delete_slave
	.long	0

ROD2	.long	RODJDVICTOR2,0
ROD3	.long	RODJDVICTOR3,0
ROD4	.long	RODJDVICTOR4,0
ROD5	.long	RODJDVICTOR5,0
ROD6	.long	RODJDVICTOR6,0
ROD7	.long	RODJDVICTOR7,0
ROD8	.long	RODJDVICTOR8,0
ROD9	.long	RODJDVICTOR9,0
ROD10	.long	RODJDVICTOR10,0
ROD11	.long	RODJDVICTOR11,0
ROD12	.long	RODJDVICTOR12,0
ROD13	.long	RODJDVICTOR13,0
ROD14	.long	RODJDVICTOR14,0
ROD15	.long	RODJDVICTOR15,0

KTVICTORY1
	.long	KTVICTORY1A,KTVICTORY1B,KTVICTORY1C,0
KTVICTORY2
	.long	KTVICTORY2A,KTVICTORY2B,KTVICTORY2C,KTVICTORY2D,0
KTVICTORY3
	.long	KTVICTORYLEG1A,KTVICTORY3A,KTVICTORY3B,0
KTVICTORY4
	.long	KTVICTORYLEG1A,KTVICTORY4A,0
KTVICTORY5
	.long	KTVICTORYLEG1A,KTVICTORY5A,0
KTVICTORY6
	.long	KTVICTORYLEG1A,KTVICTORY6A,0

;*************************************

a_mileena_vic
	.long	MLVICTORY1
	.long	MLVICTORY2
	.long	MLVICTORY3
	.long	MLVICTORY4
	.long	MLVICTORY5
	.long	0

MLVICTORY1
	.long	MLVICTORY1A,MLVICTORY1B,0
MLVICTORY2
	.long	MLVICTORY2A,MLVICTORY2B,MLVICTORY2C,MLVICTORY2D,0
MLVICTORY3
	.long	MLVICTORY3A,MLVICTORY3B,0
MLVICTORY4
	.long	MLVICTORY4A,MLVICTORY4B,MLVICTORYLEG1A,0
MLVICTORY5
	.long	MLVICTORY5A,MLVICTORY5B,MLVICTORYLEG1A,0

;*************************************

JDVICTORY2
	.long	JDVICTORY2A,JDVICTORY2B,0
JDVICTORY3
	.long	JDVICTORY3A,JDVICTORY3B,0
JDVICTORY4
	.long	JDVICTORY4A,JDVICTORY4B,0
JDVICTORY5
	.long	JDVICTORY5A,JDVICTORY5B,0
JDVICTORY6
	.long	JDVICTORY6A,JDVICTORY6B,0
JDVICTORY7
	.long	JDVICTORY7A,JDVICTORY7B,0
JDVICTORY8
	.long	JDVICTORY8A,0
JDVICTORY9
	.long	JDVICTORY9A,JDVICTORY9B,0
JDVICTORY10
	.long	JDVICTORY10A,0
JDVICTORY11
	.long	JDVICTORY11A,JDVICTORY11B,JDVICTORY11C,0
JDVICTORY12
	.long	JDVICTORY12A,JDVICTORY12B,JDVICTORY12C,0
JDVICTORY13
	.long	JDVICTORY13A,JDVICTORY13B,JDVICTORY13C,0
JDVICTORY14
	.long	JDVICTORY14A,JDVICTORY14B,JDVICTORY14C,0
JDVICTORY15
	.long	JDVICTORY15A,JDVICTORY15B,JDVICTORY15C,0

;*********************************************************************

a_hipunch
	.long	KTHIPUNCH1
	.long	KTHIPUNCH2
	.long	KTHIPUNCH3
	.long	0

	.long	KTHIPUNCH4
	.long	KTHIPUNCH5
	.long	KTHIPUNCH6
	.long	0

	.long	KTHIPUNCH5
	.long	KTHIPUNCH4
	.long	ani_jump,a_hipunch+(32*2)
	.long	0					; we NEED this "0"
*
* Unhipunch #1
*
	.long	KTHIPUNCH2
	.long	KTHIPUNCH1
	.long	0
*
* Unhipunch #2
*
	.long	KTHIPUNCH7
	.long	0
*
* Hi to Med #1
*
	.long	KTHIPUNCH4
	.long	KTLOPUNCH5
	.long	ani_jump,a_lopunch+(32*6)
	.long	0
*
* Hi to Med #2
*
	.long	KTHIPUNCH5
	.long	KTLOPUNCH2
	.long	ani_jump,a_lopunch+(32*2)
	.long	0


a_lopunch
	.long	KTHIPUNCH1
	.long	KTLOPUNCH1
	.long	KTLOPUNCH2
	.long	0

	.long	KTLOPUNCH3
	.long	KTLOPUNCH4
	.long	KTLOPUNCH5
	.long	0

	.long	KTLOPUNCH4
	.long	KTLOPUNCH3
	.long	ani_jump,a_lopunch+(32*2)
	.long	0
*
* Unlopunch #1
*
	.long	KTLOPUNCH1
	.long	KTHIPUNCH1
	.long	0
*
* Unlopunch #2
*
	.long	KTLOPUNCH4
	.long	0
*
* Med to High #1
*
	.long	KTLOPUNCH3
	.long	KTLOPUNCH4
	.long	ani_jump,a_hipunch+(32*6)
	.long	0
*
* Med to High #2
*
	.long	KTLOPUNCH4
	.long	KTHIPUNCH5
	.long	ani_jump,a_hipunch+(32*2)


KTHIPUNCH1
	.long	KTHIPUNCH1A,KTHIPUNCH1B,0
KTHIPUNCH2
	.long	KTHIPUNCH2A,KTHIPUNCH2B,0
KTHIPUNCH3
	.long	KTHIPUNCH3A,KTHIPUNCH3B,KTHIPUNCH3C,0
KTHIPUNCH4
	.long	KTHIPUNCH4A,KTHIPUNCH4B,KTHIPUNCH4C,0
KTHIPUNCH5
	.long	KTHIPUNCH5A,KTHIPUNCH5B,0
KTHIPUNCH6
	.long	KTHIPUNCH6A,KTHIPUNCH6B,KTHIPUNCH6C,0
KTHIPUNCH7
	.long	KTHIPUNCH7A,KTHIPUNCH7B,KTHIPUNCH7C,0

KTLOPUNCH1
	.long	KTLOPUNCH1A,KTLOPUNCH1B,0
KTLOPUNCH2
	.long	KTLOPUNCH2A,KTLOPUNCH2B,0
KTLOPUNCH3
	.long	KTLOPUNCH3A,KTLOPUNCH3B,0
KTLOPUNCH4
	.long	KTLOPUNCH4A,KTLOPUNCH4B,0
KTLOPUNCH5
	.long	KTLOPUNCH5A,KTLOPUNCH5B,0

;*************************************

a_mileena_elbow
	.long	ani_adjustx
	.word	5
	.long	MLCOMBO3
	.long	ani_adjustx
	.word	5
	.long	MLCOMBO4
	.long	MLCOMBO5
	.long	0
*
* part 2 = retract
*
	.long	MLCOMBO4
	.long	MLCOMBO3
	.long	0
*
* part 3 = hit 2
*
	.long	ani_adjustx
	.word	8
	.long	MLCOMBO6
	.long	ani_adjustx
	.word	8
	.long	MLCOMBO7
	.long	MLCOMBO8
	.long	MLCOMBO9
	.long	MLCOMBO10
	.long	0
*
* part 4 = hit 3
*
	.long	ani_adjustx
	.word	7
	.long	MLCOMBO3
	.long	ani_adjustx
	.word	7
	.long	MLCOMBO4
	.long	MLCOMBO5
	.long	0
*
* part 5 = hit 4
*
	.long	ani_adjustx
	.word	8
	.long	MLCOMBO6
	.long	ani_adjustx
	.word	8
	.long	MLCOMBO7
	.long	MLCOMBO8
	.long	MLCOMBO9
	.long	ani_nosleep
	.long	MLCOMBO10
	.long	0
*
* part 6 = retract
*
	.long	MLCOMBO9
	.long	MLCOMBO8
	.long	MLCOMBO7
	.long	0

MLCOMBO3
	.long	MLCOMBO3A,MLCOMBO3B,0
MLCOMBO4
	.long	MLCOMBO4A,MLCOMBO4B,0
MLCOMBO5
	.long	MLCOMBO5A,MLCOMBO5B,MLCOMBO5C,0
MLCOMBO6
	.long	MLCOMBO6A,MLCOMBO6B,0
MLCOMBO7
	.long	MLCOMBO7A,MLCOMBO7B,0
MLCOMBO8
	.long	MLCOMBO8A,MLCOMBO8B,MLCOMBO8C,0
MLCOMBO9
	.long	MLCOMBO9A,MLCOMBO9B,0
MLCOMBO10
	.long	MLCOMBO10A,MLCOMBO10B,0

;*************************************

a_elbow
	.long	ani_ochar_jump
	.long	ft_jade
	.long	a_jade_elbow

	.long	ani_adjustx
	.word	5
	.long	KTCOMBO2
	.long	ani_adjustx
	.word	5
	.long	KTCOMBO3
	.long	KTCOMBO4
	.long	KTCOMBO5
	.long	0
*
* part 2 = retract hit 1
*
j_unelbow
	.long	ani_ochar_jump
	.long	ft_jade
	.long	j_jade_unelbow

	.long	KTCOMBO5
	.long	KTCOMBO4
	.long	KTCOMBO3
	.long	KTCOMBO2
	.long	0
*
* part 3 = hit 2 !!
*
	.long	ani_ochar_jump
	.long	ft_jade
	.long	j_jade_elbow2

	.long	KTCOMBO7
	.long	ani_adjustx
	.word	8
	.long	KTCOMBO8
	.long	ani_adjustx
	.word	8
	.long	KTCOMBO9
	.long	KTCOMBO10
	.long	0
*
* part 4 = hit 3
*
	.long	ani_ochar_jump
	.long	ft_jade
	.long	j_jade_elbow3

	.long	ani_adjustx
	.word	8
	.long	KTCOMBO2
	.long	ani_adjustx
	.word	8
	.long	KTCOMBO3
	.long	KTCOMBO4
	.long	KTCOMBO5
	.long	0
*
* part 5 = hit 4
*
	.long	ani_ochar_jump
	.long	ft_jade
	.long	j_jade_elbow4

	.long	KTCOMBO7
	.long	ani_adjustx
	.word	8
	.long	KTCOMBO8
	.long	ani_adjustx
	.word	8
	.long	KTCOMBO9
	.long	KTCOMBO10
	.long	0

	.long	KTLOPUNCH1
	.long	KTHIPUNCH1
	.long	0


a_jade_elbow
;	.long	ani_sladd,JADEROD2
;	.long	ani_slani,JADEROD3
	.long	JDCOMBO3
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD4
	.long	JDCOMBO4
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD5
	.long	JDCOMBO5
	.long	0
*
* part 2 = unelbow
*
j_jade_unelbow
;	.long	ani_slani,JADEROD3
	.long	JDCOMBO3
;	.long	ani_slani,JADEROD2
	.long	JDCOMBO2
	.long	ani_calla,delete_slave
	.long	0
*
* part 3 = hit #2
*
j_jade_elbow2
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD5
	.long	JDCOMBO5
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD6
	.long	JDCOMBO6
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD7
	.long	JDCOMBO7
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD8
	.long	JDCOMBO8
	.long	0
*
* part 4 = hit #3
*
j_jade_elbow3
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD9
	.long	JDCOMBO9
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD10
	.long	JDCOMBO10
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD11
	.long	JDCOMBO11
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD4
	.long	JDCOMBO4
	.long	0

j_jade_elbow4
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD5
	.long	JDCOMBO5
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD6
	.long	JDCOMBO6
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD7
	.long	JDCOMBO7
	.long	ani_adjustx
	.word	8
;	.long	ani_slani,JADEROD8
	.long	JDCOMBO8
	.long	0

;	.long	ani_slani,JADEROD3
	.long	JDCOMBO3
;	.long	ani_slani,JADEROD2
	.long	JDCOMBO2
	.long	0

KTCOMBO2	.long	KTCOMBO2A,KTCOMBO2B,0
KTCOMBO3	.long	KTCOMBO3A,KTCOMBO3B,KTCOMBO3C,0
KTCOMBO4	.long	KTCOMBO4A,KTCOMBO4B,KTCOMBO4C,KTCOMBO4D,0
KTCOMBO5	.long	KTCOMBO5A,KTCOMBO5B,KTCOMBO5C,0
KTCOMBO7	.long	KTCOMBO7A,KTCOMBO7B,KTCOMBO7C,KTCOMBO7D,0
KTCOMBO8	.long	KTCOMBO8A,KTCOMBO8B,KTCOMBO8C,0
KTCOMBO9	.long	KTCOMBO9A,KTCOMBO9B,0
KTCOMBO10
	.long	KTCOMBO10A,KTCOMBO10B,0

;*************************************

JDCOMBO2
	.long	JDCOMBO2A,JDCOMBO2B,0
JDCOMBO3
	.long	JDCOMBO3A,JDCOMBO3B,0
JDCOMBO4
	.long	JDCOMBO4A,JDCOMBO4B,JDCOMBO4C,0
JDCOMBO5
	.long	JDCOMBO5A,JDCOMBO5B,JDCOMBO5C,0
JDCOMBO6
	.long	JDCOMBO6A,JDCOMBO6B,0
JDCOMBO7
	.long	JDCOMBO7A,JDCOMBO7B,JDCOMBO7C,0
JDCOMBO8
	.long	JDCOMBO8A,JDCOMBO8B,JDCOMBO8C,0
JDCOMBO9
	.long	JDCOMBO9A,JDCOMBO9B,JDCOMBO9C,0
JDCOMBO10
	.long	JDCOMBO10A,JDCOMBO10B,JDCOMBO10C,0
JDCOMBO11
	.long	JDCOMBO11A,JDCOMBO11B,JDCOMBO11C,0

;*************************************

JADEROD2
	.long	JADEROD2A,JADEROD2B,0
JADEROD3
	.long	JADEROD3A,JADEROD3B,0
JADEROD4
	.long	JADEROD4A,0
JADEROD5
	.long	JADEROD5A,0
JADEROD6
	.long	JADEROD6A,JADEROD6B,0
JADEROD7
	.long	JADEROD7A,JADEROD7B,0
JADEROD8
	.long	JADEROD8A,JADEROD8B,0
JADEROD9
	.long	JADEROD9A,JADEROD9B,0
JADEROD10
	.long	JADEROD10A,0
JADEROD11
	.long	JADEROD11A,0

;*************************************

a_hikick 
	.long	KTLOKICK1
	.long	KTLOKICK2
	.long	KTLOKICK3
	.long	KTLOKICK4
	.long	KTHIKICK1
	.long	KTHIKICK2
	.long	0
	.long	KTHIKICK1
	.long	KTLOKICK4
	.long	KTLOKICK3
	.long	KTLOKICK2
	.long	KTLOKICK1
	.long	0

a_lokick 
	.long	KTLOKICK1
	.long	KTLOKICK2
	.long	KTLOKICK3
	.long	KTLOKICK4
	.long	KTLOKICK5
	.long	KTLOKICK6
	.long	0
	.long	KTLOKICK5
	.long	KTLOKICK4
	.long	KTLOKICK3
	.long	KTLOKICK2
	.long	KTLOKICK1
	.long	0

KTLOKICK1
	.long	KTLOKICK1A,0
KTLOKICK2
	.long	KTLOKICK2A,0
KTLOKICK3
	.long	KTLOKICK3A,KTLOKICK3B,0
KTLOKICK4
	.long	KTLOKICK4A,0
KTLOKICK5
	.long	KTLOKICK5A,0
KTLOKICK6
	.long	KTLOKICK6A,0
KTHIKICK1
	.long	KTHIKICK1A,KTHIKICK1B,0
KTHIKICK2
	.long	KTHIKICK2A,KTHIKICK2B,0

;*************************************

a_knee
	.long	KTAXEKICK1
	.long	KTKNEE1
	.long	KTKNEE2
	.long	0

	.long	KTKNEE1
	.long	KTAXEKICK1
	.long	0
*
* part 3 = hit 2
*
	.long	ani_adjustx
	.word	6
	.long	KTKNEECOMBO1
	.long	ani_adjustx
	.word	6
	.long	KTKNEECOMBO2
	.long	KTKNEECOMBO3
	.long	0
*
* part 4 = hit 3
*
	.long	ani_adjustx
	.word	8
	.long	KTAXEKICK1
	.long	ani_adjustx
	.word	8
	.long	KTAXEKICK2
	.long	ani_adjustx
	.word	8
	.long	KTAXEKICK3
	.long	ani_adjustx
	.word	8
	.long	KTAXEKICK4
	.long	0
*
* part 5 = hit 4
*
	.long	ani_adjustx
	.word	5
	.long	KTSPINKICK1
	.long	ani_adjustx
	.word	5
	.long	KTSPINKICK2
	.long	ani_adjustx
	.word	5
	.long	KTSPINKICK3
	.long	ani_adjustx
	.word	5
	.long	KTSPINKICK4
	.long	ani_nosleep
	.long	KTSPINKICK5
	.long	0
*
* part 6 - retract hit 4
*
	.long	KTSPINKICK4
	.long	KTSPINKICK3
	.long	KTSPINKICK2
	.long	KTSPINKICK1
	.long	0
*
* part 7 - retract axe kick
*
	.long	KTAXEKICK3
	.long	KTAXEKICK2
	.long	KTAXEKICK1
	.long	0



KTKNEE1	.long	KTKNEE1A,0
KTKNEE2	.long	KTKNEE2A,KTKNEE2B,0

KTAXEKICK1
	.long	KTAXEKICK1A,0
KTAXEKICK2
	.long	KTAXEKICK2A,KTAXEKICK2B,0
KTAXEKICK3
	.long	KTAXEKICK3A,KTAXEKICK3B,0
KTAXEKICK4
	.long	KTAXEKICK4A,KTAXEKICK4B,0
KTKNEECOMBO1
	.long	KTKNEECOMBO1A,KTKNEECOMBO1B,0
KTKNEECOMBO2
	.long	KTKNEECOMBO2A,0
KTKNEECOMBO3
	.long	KTKNEECOMBO3A,KTKNEECOMBO3B,0


a_sweep_kick
	.long	KTSWEEPKICK1
	.long	KTSWEEPKICK2
	.long	KTSWEEPKICK3
	.long	KTSWEEPKICK4
	.long	KTSWEEPKICK5
	.long	0
	.long	KTSWEEPKICK6
	.long	KTSWEEPKICK7
	.long	KTSWEEPKICK8
	.long	0

KTSWEEPKICK1
	.long	KTSWEEPKICK1A,KTSWEEPKICK1B,0
KTSWEEPKICK2
	.long	KTSWEEPKICK2A,KTSWEEPKICK2B,0
KTSWEEPKICK3
	.long	KTSWEEPKICK3A,0
KTSWEEPKICK4
	.long	KTSWEEPKICK4A,0
KTSWEEPKICK5
	.long	KTSWEEPKICK5A,KTSWEEPKICK5B,0
KTSWEEPKICK6
	.long	KTSWEEPKICK6A,0
KTSWEEPKICK7
	.long	KTSWEEPKICK7A,KTSWEEPKICK7B,0
KTSWEEPKICK8
	.long	KTSWEEPKICK8A,KTSWEEPKICK8B,0

;*************************************

a_roundhouse
	.long	KTSPINKICK1
	.long	KTSPINKICK2
	.long	KTSPINKICK3
	.long	KTSPINKICK4
	.long	ani_nosleep
	.long	KTSPINKICK5
	.long	0
	.long	KTSPINKICK6
	.long	KTSPINKICK7
	.long	KTSPINKICK8
	.long	0

KTSPINKICK1
	.long	KTSPINKICK1A,KTSPINKICK1B,0
KTSPINKICK2
	.long	KTSPINKICK2A,KTSPINKICK2B,0
KTSPINKICK3
	.long	KTSPINKICK3A,0
KTSPINKICK4
	.long	KTSPINKICK4A,KTSPINKICK4B,0
KTSPINKICK5
	.long	KTSPINKICK5A,KTSPINKICK5B,0
KTSPINKICK6
	.long	KTSPINKICK6A,KTSPINKICK6B,0
KTSPINKICK7
	.long	KTSPINKICK7A,0
KTSPINKICK8
	.long	KTSPINKICK8A,KTSPINKICK8B,0

;*************************************

a_jump
	.long	KTJUMP1
	.long	KTJUMP2
	.long	KTJUMP3
	.long	0

KTJUMP1	.long	KTJUMP1A,KTJUMP1B,0
KTJUMP2	.long	KTJUMP2A,KTJUMP2B,0
KTJUMP3	.long	KTJUMP3A,KTJUMP3B,0

;*************************************

a_jump_kick
	.long	KTJUMPKICK1
	.long	KTJUMPKICK2
	.long	KTJUMPKICK3
	.long	0
	.long	KTJUMPKICK2
	.long	KTJUMPKICK1
	.long	0

KTJUMPKICK1
	.long	KTJUMPKICK1A,0
KTJUMPKICK2
	.long	KTJUMPKICK2A,KTJUMPKICK2B,0
KTJUMPKICK3
	.long	KTJUMPKICK3A,KTJUMPKICK3B,0

;*************************************

a_flip_punch
	.long	KTFLIPUNCH1
	.long	KTFLIPUNCH2
	.long	KTFLIPUNCH3
	.long	0
	.long	KTFLIPUNCH2
	.long	KTFLIPUNCH1
	.long	0

KTFLIPUNCH1
	.long	KTFLIPUNCH1A,0
KTFLIPUNCH2
	.long	KTFLIPUNCH2A,0
KTFLIPUNCH3
	.long	KTFLIPUNCH3A,KTFLIPUNCH3B,KTFLIPUNCH3C,0

;*************************************

a_flip_kick
	.long	KTFLIPKICK1
	.long	KTFLIPKICK2
	.long	KTFLIPKICK3
	.long	0
	.long	KTFLIPKICK2
	.long	KTFLIPKICK1
	.long	0
*
* part 3 for mileena tele kick
*
	.long	KTFLIPKICK3
	.long	KTFLIPKICK3
	.long	KTFLIPKICK3
	.long	KTFLIPKICK2
	.long	KTFLIPKICK1
	.long	0



KTFLIPKICK1
	.long	KTFLIPKICK1A,0
KTFLIPKICK2
	.long	KTFLIPKICK2A,KTFLIPKICK2B,0
KTFLIPKICK3
	.long	KTFLIPKICK3A,KTFLIPKICK3B,0

;*************************************

a_fflip
	.long	KTJUMPFLIP1
	.long	KTJUMPFLIP2
	.long	KTJUMPFLIP3
	.long	KTJUMPFLIP4
	.long	KTJUMPFLIP5
	.long	KTJUMPFLIP6
	.long	KTJUMPFLIP7
	.long	KTJUMPFLIP8
	.long	ani_jump,a_fflip+32

a_bflip
	.long	KTJUMPFLIP1
	.long	KTJUMPFLIP8
	.long	KTJUMPFLIP7
	.long	KTJUMPFLIP6
	.long	KTJUMPFLIP5
	.long	KTJUMPFLIP4
	.long	KTJUMPFLIP3
	.long	KTJUMPFLIP2
	.long	ani_jump,a_bflip+32


KTJUMPFLIP1
	.long	KTJUMPFLIP1A,KTJUMPFLIP1B,0
KTJUMPFLIP2
	.long	KTJUMPFLIP2A,0
KTJUMPFLIP3
	.long	KTJUMPFLIP3A,0
KTJUMPFLIP4
	.long	KTJUMPFLIP4A,0
KTJUMPFLIP5
	.long	KTJUMPFLIP5A,0
KTJUMPFLIP6
	.long	KTJUMPFLIP6A,0
KTJUMPFLIP7
	.long	KTJUMPFLIP7A,0
KTJUMPFLIP8
	.long	KTJUMPFLIP8A,0

;************************************

a_hit_hi
	.long	KTHIHIT2
	.long	KTHIHIT3
	.long	KTHIHIT2
	.long	KTHIHIT1
	.long	0

KTHIHIT1
	.long	KTHIHIT1A,KTHIHIT1B,0
KTHIHIT2
	.long	KTHIHIT2A,KTHIHIT2B,0
KTHIHIT3
	.long	KTHIHIT3A,KTHIHIT3B,0

;*************************************

a_hit_lo
	.long	KTLOHIT2
	.long	KTLOHIT3
	.long	KTLOHIT2
	.long	KTLOHIT1
	.long	0

KTLOHIT1	.long	KTLOHIT1A,KTLOHIT1B,0
KTLOHIT2	.long	KTLOHIT2A,KTLOHIT2B,0
KTLOHIT3	.long	KTLOHIT3A,KTLOHIT3B,0

;*************************************

a_knockdown
	.long	KTKNOCKDOWN1
	.long	KTKNOCKDOWN2
	.long	KTKNOCKDOWN3
	.long	KTKNOCKDOWN4
	.long	KTKNOCKDOWN5
	.long	0
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0

KTKNOCKDOWN1
	.long	KTKNOCKDOWN1A,KTKNOCKDOWN1B,0
KTKNOCKDOWN2
	.long	KTKNOCKDOWN2A,0
KTKNOCKDOWN3
	.long	KTKNOCKDOWN3A,KTKNOCKDOWN3B,0
KTKNOCKDOWN4
	.long	KTKNOCKDOWN4A,KTKNOCKDOWN4B,0
KTKNOCKDOWN5
	.long	KTKNOCKDOWN5A,0
KTKNOCKDOWN6
	.long	KTKNOCKDOWN6A,0
KTKNOCKDOWN7
	.long	KTKNOCKDOWN7A,0

;*************************************

a_sweep_fall
	.long	KTSWEEPFALL1
	.long	KTSWEEPFALL2
	.long	KTSWEEPFALL3
	.long	KTSWEEPFALL4
	.long	KTSWEEPFALL5
	.long	0
	.long	KTSWEEPFALL6
	.long	KTSWEEPFALL7
	.long	0

KTSWEEPFALL1
	.long	KTSWEEPFALL1A,KTSWEEPFALL1B,0
KTSWEEPFALL2
	.long	KTSWEEPFALL2A,KTSWEEPFALL2B,0
KTSWEEPFALL3
	.long	KTSWEEPFALL3A,KTSWEEPFALL3B,0
KTSWEEPFALL4
	.long	KTSWEEPFALL4A,KTSWEEPFALL4B,0
KTSWEEPFALL5
	.long	KTSWEEPFALL5A,KTSWEEPFALL5B,0
KTSWEEPFALL6
	.long	KTSWEEPFALL6A,0
KTSWEEPFALL7
	.long	KTSWEEPFALL7A,0


a_stumble
	.long	KTSTUMBLE1
	.long	KTSTUMBLE2
	.long	KTSTUMBLE3
	.long	KTSTUMBLE4
	.long	KTSTUMBLE5
	.long	KTSTUMBLE6
	.long	KTSTUMBLE7
	.long	KTSTUMBLE8
	.long	0

j_stumble
	.long	KTSTUMBLE1
	.long	KTSTUMBLE2
	.long	KTSTUMBLE3
	.long	KTSTUMBLE4
	.long	KTSTUMBLE5
	.long	KTSTUMBLE6
	.long	KTSTUMBLE7
	.long	KTSTUMBLE8
	.long	ani_jump,j_stumble

KTSTUMBLE1
	.long	KTSTUMBLE1A,KTSTUMBLE1B,0
KTSTUMBLE2
	.long	KTSTUMBLE2A,KTSTUMBLE2B,KTSTUMBLE2C,0
KTSTUMBLE3
	.long	KTSTUMBLE3A,KTSTUMBLE3B,0
KTSTUMBLE4
	.long	KTSTUMBLE4A,KTSTUMBLE4B,0
KTSTUMBLE5
	.long	KTSTUMBLE5A,KTSTUMBLE5B,KTSTUMBLE5C,0
KTSTUMBLE6
	.long	KTSTUMBLE6A,KTSTUMBLE6B,0
KTSTUMBLE7
	.long	KTSTUMBLE7A,KTSTUMBLE7B,0
KTSTUMBLE8
	.long	KTSTUMBLE8A,KTSTUMBLE8B,0

;**********************************************************

a_getup
	.long	KTGETUP1
	.long	KTGETUP2
	.long	KTGETUP3
	.long	KTGETUP4
	.long	KTGETUP5
	.long	KTGETUP6
	.long	0

KTGETUP1	.long	KTGETUP1A,0
KTGETUP2	.long	KTGETUP2A,0
KTGETUP3	.long	KTGETUP3A,0
KTGETUP4	.long	KTGETUP4A,KTGETUP4B,0
KTGETUP5	.long	KTGETUP5A,0
KTGETUP6	.long	KTGETUP6A,0

;*************************************

a_sweepup
	.long	KTSWEEPUP1
	.long	KTSWEEPUP2
	.long	KTSWEEPUP3
	.long	KTSWEEPUP4
	.long	KTSWEEPUP5
	.long	KTSWEEPUP6
	.long	0

KTSWEEPUP1
	.long	KTSWEEPUP1A,0
KTSWEEPUP2
	.long	KTSWEEPUP2A,0
KTSWEEPUP3
	.long	KTSWEEPUP3A,0
KTSWEEPUP4
	.long	KTSWEEPUP4A,0
KTSWEEPUP5
	.long	KTSWEEPUP5A,0
KTSWEEPUP6
	.long	KTSWEEPUP6A,0

;*************************************

a_throw
	.long	ani_ochar_jump
	.long	ft_jade
	.long	a_jade_throw		; yes = different throw animation

	.long	ani_ochar_jump
	.long	ft_mileena
	.long	a_mileena_throw		; yes = different throw animation

	.long	KTLEGFLIP1
	.long	KTLEGFLIP2
	.long	KTLEGFLIP3
	.long	KTLEGFLIP4
	.long	0

	.long	KTLEGFLIP5
	.long	KTLEGFLIP6
	.long	KTLEGFLIP7
	.long	KTLEGFLIP8
	.long	0

	.long	KTLEGFLIP9
	.long	KTDUCK2
	.long	0


a_jade_throw
	.long	JDSTAFFLIP2
	.long	JDSTAFFLIP3
	.long	0

	.long	JDSTAFFLIP4
	.long	JDSTAFFLIP5
	.long	JDSTAFFLIP6
	.long	JDSTAFFLIP7
	.long	JDSTAFFLIP9
	.long	JDSTAFFLIP10
	.long	JDSTAFFLIP11	; animate 2-gether
	.long	0
	.long	JDSTAFFLIP10
	.long	JDSTAFFLIP9
	.long	JDSTAFFLIP7
	.long	JDSTAFFLIP6
	.long	JDSTAFFLIP5
	.long	JDSTAFFLIP4
	.long	KTTURN1
	.long	KTTURN2
	.long	ani_flip
	.long	KTTURN2
	.long	KTTURN1
	.long	0


a_mileena_throw
	.long	MLFLIP1
	.long	MLFLIP2
	.long	0

	.long	MLFLIP3
	.long	MLFLIP4
	.long	MLFLIP5
	.long	MLFLIP6
	.long	MLFLIP8		; animate 2-gether
	.long	0

	.long	MLFLIP6
	.long	MLFLIP5
	.long	MLFLIP4
	.long	MLFLIP3
	.long	0

MLFLIP1	.long	MLFLIP1A,MLFLIP1B,MLFLIP1C,0
MLFLIP2	.long	MLFLIP2A,MLFLIP2B,MLFLIP2C,0
MLFLIP3	.long	MLFLIP3A,MLFLIP3B,0
MLFLIP4	.long	MLFLIP4A,MLFLIP4B,0
MLFLIP5	.long	MLFLIP5A,MLFLIP5B,0
MLFLIP6	.long	MLFLIP6A,MLFLIP6B,0
MLFLIP8	.long	MLFLIP8A,0


JDSTAFFLIP2
	.long	JDSTAFFLIP2A,JDSTAFFLIP2B,0
JDSTAFFLIP3
	.long	JDSTAFFLIP3A,JDSTAFFLIP3B,0
JDSTAFFLIP4
	.long	JDSTAFFLIP4A,JDSTAFFLIP4B,0
JDSTAFFLIP5
	.long	JDSTAFFLIP5A,JDSTAFFLIP5B,0
JDSTAFFLIP6
	.long	JDSTAFFLIP6A,JDSTAFFLIP6B,JDSTAFFLIP6C,0
JDSTAFFLIP7
	.long	JDSTAFFLIP7A,JDSTAFFLIP7B,JDSTAFFLIP7C,0
JDSTAFFLIP9
	.long	JDSTAFFLIP9A,JDSTAFFLIP9B,0
JDSTAFFLIP10
	.long	JDSTAFFLIP10A,JDSTAFFLIP10B,JDSTAFFLIP10C,0
JDSTAFFLIP11
	.long	JDSTAFFLIP11A,JDSTAFFLIP11B,JDSTAFFLIP11C,0


KTLEGFLIP1
	.long	KTLEGFLIP1A,0
KTLEGFLIP2
	.long	KTLEGFLIP2A,KTLEGFLIP2B,0
KTLEGFLIP3
	.long	KTLEGFLIP3A,KTLEGFLIP3B,0
KTLEGFLIP4
	.long	KTLEGFLIP4A,0
KTLEGFLIP5
	.long	KTLEGFLIP5A,0
KTLEGFLIP6
	.long	KTLEGFLIP6A,0
KTLEGFLIP7
	.long	KTLEGFLIP7A,0
KTLEGFLIP8
	.long	KTLEGFLIP8A,KTLEGFLIP8B,0
KTLEGFLIP9
	.long	KTLEGFLIP9A,KTLEGFLIP9B,0

a_kit_airfan
	.long	KTAIRFAN1
	.long	KTAIRFAN2
	.long	ani_sladd,KFANS1
	.long	ani_slani,KFANS4
	.long	KTAIRFAN3
	.long	0

	.long	KTAIRFAN4
	.long	0

a_zap
	.long	KTTHROWFAN1
	.long	KTTHROWFAN2
	.long	ani_sladd,KFANS1
	.long	ani_slani,KFANS4
	.long	0

	.long	KTTHROWFAN3
	.long	KTTHROWFAN4
	.long	KTTHROWFAN5
	.long	0

	.long	KTTHROWFAN4
	.long	KTTHROWFAN3
	.long	0
*
* part 4 = fan animation
*
j_fan	.long	KFANS13
	.long	KFANS12
	.long	KFANS11
	.long	KFANS10
	.long	KFANS9
	.long	KFANS8
	.long	KFANS7 
	.long	KFANS6 
	.long	KFANS5 
	.long	KFANS4 
	.long	ani_jump,j_fan

KFANS1	.long	FANS1,0
KFANS2	.long	FANS2,0
KFANS3	.long	FANS3,0
KFANS4	.long	FANS4,0
KFANS5	.long	FANS5,0
KFANS6	.long	FANS6,0
KFANS7	.long	FANS7,0
KFANS8	.long	FANS8,0
KFANS9	.long	FANS9,0
KFANS10	.long	FANS10,0
KFANS11	.long	FANS11,0
KFANS12	.long	FANS12,0
KFANS13	.long	FANS13,0
KFANS14	.long	FANS14,0
KFANS15	.long	FANS15,0
KFANS16	.long	FANS16,0

KTTHROWFAN1
	.long	KTTHROWFAN1A,KTTHROWFAN1B,0
KTTHROWFAN2
	.long	KTTHROWFAN2A,KTTHROWFAN2B,0
KTTHROWFAN3
	.long	KTTHROWFAN3A,KTTHROWFAN3B,0
KTTHROWFAN4
	.long	KTTHROWFAN4A,KTTHROWFAN4B,0
KTTHROWFAN5
	.long	KTTHROWFAN5A,KTTHROWFAN5B,0


KTAIRFAN1
	.long	KTAIRFAN1A,KTAIRFAN1B,0
KTAIRFAN2
	.long	KTAIRFAN2A,0
KTAIRFAN3
	.long	KTAIRFAN3A,0
KTAIRFAN4
	.long	KTAIRFAN4A,0

;************************************************

a_throw_sai
	.long	MLTHROWSAI1
	.long	MLTHROWSAI2
	.long	MLTHROWSAI3
	.long	MLTHROWSAI4
	.long	0
*
* part 2 = air sai
*
	.long	KTAIRSAI1
	.long	KTAIRSAI2
	.long	KTAIRSAI3
	.long	0

	.long	KTAIRSAI2
	.long	KTAIRSAI1
	.long	0


KTAIRSAI1
	.long	KTAIRSAI1A,0
KTAIRSAI2
	.long	KTAIRSAI2A,0
KTAIRSAI3
	.long	KTAIRSAI3A,0

MLTHROWSAI1
	.long	MLTHROWSAI1A,MLTHROWSAI1B,0
MLTHROWSAI2
	.long	MLTHROWSAI2A,MLTHROWSAI2B,0
MLTHROWSAI3
	.long	MLTHROWSAI3A,0
MLTHROWSAI4
	.long	MLTHROWSAI4A,MLTHROWSAI4B,0

;************************************************

a_sai_fly
	.long	SI1
	.long	SI2
	.long	SI3
	.long	SI4
	.long	SI5
	.long	SI6
	.long	0

	.long	SI7
	.long	SI8
	.long	SI10
	.long	SI12
	.long	SI14
	.long	SI16
	.long	SI18
	.long	0

SI1	.long	SIPROJ1,0
SI2	.long	SIPROJ2,0
SI3	.long	SIPROJ3,0
SI4	.long	SIPROJ4,0
SI5	.long	SIPROJ5,0
SI6	.long	SIPROJ6,0
SI7	.long	SIPROJ7,0
SI8	.long	SIPROJ8,0
SI10	.long	SIPROJ10,0
SI12	.long	SIPROJ12,0
SI14	.long	SIPROJ14,0
SI16	.long	SIPROJ16,0
SI18	.long	SIPROJ18,0

;************************************************

KTBUZZSAW1
	.long	KTBUZZSAW1A,KTBUZZSAW1B,0
KTBUZZSAW2
	.long	KTBUZZSAW2A,KTBUZZSAW2B,KTBUZZSAW2C,0
KTBUZZSAW3
	.long	KTBUZZSAW3A,KTBUZZSAW3B,0

;***********************************************

a_dizzy
	.long	KTSTUNNED1
	.long	KTSTUNNED2
	.long	KTSTUNNED3
	.long	KTSTUNNED4
	.long	KTSTUNNED5
	.long	KTSTUNNED6
	.long	KTSTUNNED7
	.long	KTSTUNNED8
	.long	KTSTUNNED9
	.long	ani_jump,a_dizzy

KTSTUNNED1
	.long	KTSTUNNED1A,KTSTUNNED1B,0
KTSTUNNED2
	.long	KTSTUNNED2A,KTSTUNNED2B,0
KTSTUNNED3
	.long	KTSTUNNED3A,KTSTUNNED3B,0
KTSTUNNED4
	.long	KTSTUNNED4A,KTSTUNNED4B,0
KTSTUNNED5
	.long	KTSTUNNED5A,KTSTUNNED5B,0
KTSTUNNED6
	.long	KTSTUNNED6A,KTSTUNNED6B,0
KTSTUNNED7
	.long	KTSTUNNED7A,KTSTUNNED7B,0
KTSTUNNED8
	.long	KTSTUNNED8A,KTSTUNNED8B,0
KTSTUNNED9
	.long	KTSTUNNED9A,KTSTUNNED9B,0

a_orb_banged
	.long	KTFLIPPED1
	.long	KTFLIPPED2
	.long	KTFLIPPED3
	.long	KTFLIPPED4
	.long	KTFLIPPED5
	.long	0

KTFLIPPED1
	.long	KTFLIPPED1A,0
KTFLIPPED2
	.long	KTFLIPPED2A,0
KTFLIPPED3
	.long	KTFLIPPED3A,KTFLIPPED3B,0
KTFLIPPED4
	.long	KTFLIPPED4A,0
KTFLIPPED5
	.long	KTFLIPPED5A,0

a_projectile

;************************************************************************


a_fb_kano
	.long	ani_offset_xy
	.word	->3c,->10		; we need even # of words here !
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->0f,->30
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>47,->3d
	.long	KTFLIPPED3
	.long	0

	.long	KTFLIPPED4
	.long	KTFLIPPED5
	.long	KTKNOCKDOWN4
	.long	KTKNOCKDOWN5
	.long	0

a_fb_sonya
	.long	ani_offset_xy
	.word	->25,>0d
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->0c,>02
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>26,->0b
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>56,->1b
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>81,->25
	.long	KTFLIPPED4
	.long	0

	.long	KTFLIPPED5
	.long	KTKNOCKDOWN4
	.long	KTKNOCKDOWN5
	.long	0

a_fb_jax
	.long	ani_offset_xy
	.word	->3e,->12
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->2f,->3f
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>0d,->50
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>40,->3a
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>55,->01
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>45,>03
	.long	KTKNOCKDOWN6
	.long	0

a_fb_ind
	.long	ani_offset_xy
	.word	->5e,->07
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->45,->48
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	->04,->66
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>3c,->4f
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>57,->35
	.long	KTKNOCKDOWN6
	.long	ani_offset_xy
	.word	>44,->07
	.long	KTKNOCKDOWN6
	.long	0

a_fb_sz
	.long	ani_offset_xy
	.word	->49,->32
	.long	KTFLIPPED1

	.long	ani_flip
	.long	ani_offset_xy
	.word	>53,->1b
	.long	KTFLIPPED5

	.long	ani_offset_xy
	.word	>35,>0b
	.long	KTFLIPPED5

	.long	ani_offset_xy
	.word	>0a,->0b
	.long	KTKNOCKDOWN5

	.long	ani_offset_xy
	.word	->33,->35
	.long	KTKNOCKDOWN5

	.long	ani_offset_xy
	.word	->7e,->6b
	.long	KTKNOCKDOWN5
	.long	0

a_fb_swat
	.long	ani_offset_xy
	.word	->57,->08
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->35,->52
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>32,->5c
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>63,->24
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>49,>01
	.long	KTKNOCKDOWN6
	.long	0

a_fb_lia
	.long	ani_offset_xy
	.word	->64,>00
	.long	KTSTUMBLE1
	.long	ani_offset_xy
	.word	->73,>03
	.long	KTSTUMBLE2

	.long	ani_offset_xy
	.word	->75,->1e
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->57,->3d
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->23,->46
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	>1e,->4e
	.long	KTFLIPPED1

	.long	ani_offset_xy
	.word	>a8,>12
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>8d,>00
	.long	KTKNOCKDOWN7
	.long	0



a_fb_robo
	.long	ani_offset_xy
	.word	->47,->0b
	.long	KTFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->43,->2f
	.long	KTFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->31,->48
	.long	KTFLIPPED2		; 3

	.long	ani_offset_xy
	.word	>00,->74
	.long	KTFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>3c,->72
	.long	KTFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>60,->5b
	.long	KTFLIPPED4		; 6

	.long	ani_offset_xy
	.word	>7b,->17
	.long	KTFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>57,->08
	.long	KTKNOCKDOWN7		; 8
	.long	0


a_fb_robo2
	.long	ani_offset_xy
	.word	->26,->08
	.long	KTSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->21,->11
	.long	KTFLIPPED1		; 2
	.long	ani_offset_xy
	.word	->26,->29
	.long	KTFLIPPED2		; 3
	.long	ani_offset_xy
	.word	>26,->26
	.long	KTFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>30,->0d
	.long	KTFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>18,->06
	.long	KTFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->12,->12
	.long	KTKNOCKDOWN7		; 7
	.long	0


a_fb_lao
	.long	ani_offset_xy
	.word	->1d,>1a
	.long	KTSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	>00,>33
	.long	KTSTUMBLE1		; 2
	.long	ani_flip
	.long	ani_offset_xy
	.word	->22,>1d
	.long	KTFLIPPED1		; 3
	.long	ani_offset_xy
	.word	->39,->21
	.long	KTFLIPPED2		; 4
	.long	ani_offset_xy
	.word	->20,->56
	.long	KTFLIPPED3		; 5
	.long	ani_offset_xy
	.word	>20,->70
	.long	KTFLIPPED4		; 6
	.long	ani_offset_xy
	.word	>5d,->71
	.long	KTFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>67,->52
	.long	KTFLIPPED5		; 8
	.long	ani_offset_xy
	.word	>65,->1c
	.long	KTFLIPPED5		; 9
	.long	ani_offset_xy
	.word	>61,>23
	.long	KTFLIPPED5		; 10
	.long	0

a_fb_tusk
	.long	ani_offset_xy
	.word	->6e,>00
	.long	KTFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->5b,->57
	.long	KTFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->04,->84
	.long	KTFLIPPED3		; 3
	.long	ani_offset_xy
	.word	>48,->58
	.long	KTFLIPPED4		; 4
	.long	ani_offset_xy
	.word	>54,->16
	.long	KTFLIPPED5		; 5

	.long	ani_offset_xy
	.word	>1e,>1f
	.long	KTFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->20,->0f
  	.long	KTKNOCKDOWN6		; 7
	.long	ani_offset_xy
	.word	->72,>0c
	.long	KTFLIPPED1		; 8
	.long	ani_offset_xy
	.word	->49,->64
	.long	KTFLIPPED2		; 9
	.long	ani_offset_xy
	.word	>2d,->6e
	.long	KTFLIPPED3		; 10 

	.long	ani_offset_xy
	.word	>78,->08
	.long	KTFLIPPED5		; 11
	.long	ani_offset_xy
	.word	>64,>05
  	.long	KTKNOCKDOWN6		; 12
	.long	0


a_fb_sg
	.long	ani_offset_xy
	.word	->3d,->30
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	>00,->53
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>08,->5b
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>23,->4c
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>25,->2f
	.long	KTFLIPPED3
	.long	ani_flip
	.long	ani_offset_xy
	.word	->12,->14
  	.long	KTKNOCKDOWN7
	.long	0

a_fb_st
	.long	ani_offset_xy
	.word	->4c,>00
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->39,>0e
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->19,>01
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>07,>04
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>1a,>21
	.long	KTFLIPPED4

	.long	ani_offset_xy
	.word	->09,->0b
	.long	KTKNOCKDOWN6
	.long	ani_offset_xy
	.word	->23,->01
	.long	KTKNOCKDOWN6
	.long	ani_offset_xy
	.word	->37,->06
	.long	KTKNOCKDOWN6

	.long	ani_offset_xy
	.word	->54,>24
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->5c,->0b
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->34,->5a
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>3e,->50
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>56,->18
	.long	KTFLIPPED5
	.long	ani_offset_xy
	.word	>56,->0b
	.long	KTKNOCKDOWN6
	.long	0

a_fb_lk
	.long	ani_offset_xy
	.word	->42,>0c
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->3d,>0f
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->13,>07
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>1c,->03
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>3a,->04
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>78,->16
	.long	KTFLIPPED4
	.long	0

	.long	KTFLIPPED5
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0

a_fb_jade
	.long	ani_offset_xy
	.word	->5a,>04
	.long	KTKNOCKDOWN1
	.long	ani_offset_xy
	.word	->5b,->21
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->43,->6c
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	->05,->6d
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>5e,->6c
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>81,->3d
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>89,->0c
	.long	KTFLIPPED5
	.long	0

	.long	KTFLIPPED4
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	0

;***********************************************************************

a_fb_nj	.long	ani_offset_xy
	.word	->49,>06
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->3c,>0e
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->18,>00
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>11,->03
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>20,->02
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>5d,->17
	.long	KTFLIPPED4
	.long	0

	.long	KTFLIPPED5
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0

;***********************************************************************
a_fb_mileena
	.long	ani_offset_xy
	.word	->3a,->01
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->29,>07
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->1e,>01
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>0e,->1a
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>63,->34
	.long	KTFLIPPED4
	.long	0

	.long	KTFLIPPED5
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0

a_fb_kitana
	.long	ani_offset_xy
	.word	->20,->23
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->08,->40
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>32,->2d
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>3d,>0c
	.long	KTFLIPPED4
	.long	0

	.long	KTFLIPPED4
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	0

a_fb_smoke
a_afb_robo2
	.long	ani_offset_xy
	.word	->19,->3b
	.long	KTFLIPPED2
	.long	ani_offset_xy
	.word	>16,->52
	.long	KTFLIPPED3
	.long	ani_offset_xy
	.word	>37,->40
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>4f,->26
	.long	KTFLIPPED4
	.long	ani_offset_xy
	.word	>66,->17
	.long	KTKNOCKDOWN6
	.long	ani_offset_xy
	.word	>78,>0f
	.long	KTKNOCKDOWN6
	.long	0


a_afb_kano
	.long	ani_offset_xy
	.word	->2f,>0b
	.long	KTKNOCKDOWN1

	.long	ani_offset_xy
	.word	->2d,>05
	.long	KTKNOCKDOWN3

	.long	ani_offset_xy
 	.word	->57,>26
	.long	KTKNOCKDOWN4

	.long	0
*
* fall down solo
*
	.long	KTKNOCKDOWN4
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0


a_legged
	.long	ani_offset_xy
	.word	->5b,>00
	.long	KTKNOCKDOWN1

	.long	ani_offset_xy
	.word	->44,->29
	.long	KTFLIPPED1

	.long	ani_offset_xy
	.word	->0a,->50
	.long	KTFLIPPED3

	.long	ani_offset_xy
	.word	>38,->37
	.long	KTFLIPPED4

	.long	ani_offset_xy
	.word	>64,>00
	.long	KTFLIPPED5
	.long	0


a_zoomed
	.long	ani_offset_xy
	.word	>65,->28
	.long	KTKNOCKDOWN3	; 1

	.long	ani_offset_xy
	.word	>61,->0c
	.long	KTKNOCKDOWN4	; 2

	.long	ani_offset_xy
	.word	>2f,>01
	.long	KTKNOCKDOWN5	; 3

	.long	ani_offset_xy
	.word	->2b,>0a
	.long	KTKNOCKDOWN5	; 4

	.long	ani_offset_xy
	.word	->83,->04
	.long	KTFLIPPED1	; 5

	.long	ani_offset_xy
	.word	->27,->66
	.long	KTFLIPPED3	; 6
	.long	0

	.long	KTFLIPPED3
	.long	KTFLIPPED4
	.long	KTFLIPPED5
	.long	KTKNOCKDOWN5
	.long	KTKNOCKDOWN6
	.long	KTKNOCKDOWN7
	.long	0


a_shook
	.long	ani_offset_xy
	.word	->4f,->08
	.long	KTSTUMBLE2

	.long	ani_offset_xy
	.word	->38,->1f
	.long	KTSTUMBLE2

	.long	ani_offset_xy
	.word	->1b,->1c
	.long	KTSTUMBLE2
	.long	0

; loop
	.long	ani_offset_xy
	.word	->1d,->1a
	.long	KTSTUMBLE2	; 6

	.long	ani_offset_xy
	.word	->33,->2b
	.long	KTSTUMBLE2	; 7

	.long	ani_offset_xy
	.word	->44,->2d	
	.long	KTSTUMBLE2	; 8

	.long	ani_offset_xy
	.word	->33,->2b
	.long	KTSTUMBLE1	; 7
	.long	0


;***************************************

a_run	.long	KTRUN1
	.long	KTRUN2
	.long	KTRUN3
	.long	KTRUN4
	.long	ani_calla,rsnd_footstep
	.long	KTRUN5
	.long	KTRUN6
	.long	KTRUN7
	.long	KTRUN8
	.long	KTRUN9
	.long	ani_calla,rsnd_footstep
	.long	KTRUN10
	.long	KTRUN11
	.long	KTRUN12
	.long	ani_jump,a_run
	.long	0			; we need this zero !!

KTRUN1
	.long	KTRUN1A,KTRUN1B,0
KTRUN2
	.long	KTRUN2A,KTRUN2B,0
KTRUN3
	.long	KTRUN3A,KTRUN3B,0
KTRUN4
	.long	KTRUN4A,KTRUN4B,0
KTRUN5
	.long	KTRUN5A,0
KTRUN6
	.long	KTRUN6A,0
KTRUN7
	.long	KTRUN7A,KTRUN7B,0
KTRUN8
	.long	KTRUN8A,KTRUN8B,0
KTRUN9
	.long	KTRUN9A,KTRUN9B,0
KTRUN10
	.long	KTRUN10A,KTRUN10B,0
KTRUN11
	.long	KTRUN11A,0
KTRUN12
	.long	KTRUN12A,0

;*************************************

a_thudd
	.long	KTFALLTHUD1
	.long	KTFALLTHUD4
	.long	KTFALLTHUD5
	.long	KTFALLTHUD6
	.long	KTFALLTHUD7
	.long	0

KTFALLTHUD1
	.long	KTFALLTHUD1A,0
KTFALLTHUD4
	.long	KTFALLTHUD4A,0
KTFALLTHUD5
	.long	KTFALLTHUD5A,0
KTFALLTHUD6
	.long	KTFALLTHUD6A,0
KTFALLTHUD7
	.long	KTFALLTHUD7A,0

;*************************************************************************

a_fan_lift
	.long	KTFANSPIN1
	.long	KTFANSPIN2
	.long	KTFANSPIN3
	.long	0

j_fan_lift
	.long	KTFANSPIN13
	.long	KTFANSPIN12
	.long	KTFANSPIN11
	.long	KTFANSPIN10
	.long	KTFANSPIN9
	.long	KTFANSPIN8
	.long	KTFANSPIN7
	.long	KTFANSPIN6
	.long	KTFANSPIN5
	.long	KTFANSPIN4
	.long	ani_jump,j_fan_lift
	.long	0

	.long	KTFANSPIN3
	.long	KTFANSPIN2
	.long	KTFANSPIN1
	.long	0
*
* part 4 = wave images
*
	.long	FANSTUN1
	.long	FANSTUN2
	.long	FANSTUN3
	.long	FANSTUN4
	.long	FANSTUN5
	.long	FANSTUN6
	.long	FANSTUN7
	.long	FANSTUN8
	.long	FANSTUN9
	.long	FANSTUN10
	.long	FANSTUN11
	.long	0


KTFANSPIN1
	.long	KTFANSPIN1A,KTFANSPIN1B,0
KTFANSPIN2
	.long	KTFANSPIN2A,KTFANSPIN2B,0
KTFANSPIN3
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS3,0
KTFANSPIN4
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS4,0
KTFANSPIN5
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS5,0
KTFANSPIN6
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS6,0
KTFANSPIN7
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS7,0
KTFANSPIN8
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS8,0
KTFANSPIN9
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS9,0
KTFANSPIN10
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS10,0
KTFANSPIN11
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS11,0
KTFANSPIN12
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS12,0
KTFANSPIN13
	.long	KTFANSPIN3A,KTFANSPIN3B,FANS13,0

;*************************************************************************

a_square
	.long	KTFLIPUNCH1
	.long	KTFLIPUNCH2
	.long	KTWAVEPUNCH1
	.long	0

KTWAVEPUNCH1
	.long	KTWAVEPUNCH1A,0

;*************************************************************************

a_jade_zap
	.long	ani_sladd,BRANG1
	.long	ani_slani,BRANG2
	.long	JDTHROWBLADE2
	.long	ani_slani,BRANG3
	.long	JDTHROWBLADE3

;	.long	ani_slani,BRANG4
	.long	ani_calla,boomerang_adjust
	.long	JDTHROWBLADE4
	.long	0

	.long	JDTHROWBLADE3
	.long	JDTHROWBLADE2
	.long	0

JDTHROWBLADE2
	.long	JDTHROWBLADE2A,JDTHROWBLADE2B,0
JDTHROWBLADE3
	.long	JDTHROWBLADE3A,JDTHROWBLADE3B,0
JDTHROWBLADE4
	.long	JDTHROWBLADE4A,JDTHROWBLADE4B,0

;***********
; badimages - SHIT !!!
;
;JDTHROWBLADE5
;	.long	JDTHROWBLADE5A,JDTHROWBLADE5B,0
;JDTHROWBLADE1
;	.long	JDTHROWBLADE1A,JDTHROWBLADE1B,0
;
;	.long	BRANG4
;***********

a_boomerang
	.long	BRANG5
	.long	BRANG6
	.long	BRANG7
	.long	BRANG8
	.long	BRANG9
	.long	BRANG10
	.long	BRANG11
	.long	ani_jump,a_boomerang
	.long	0

	.long	BOOMERANG1		; part 2 = 1st boomerang obj
	.long	BRTRAIL1
	.long	BRTRAIL2
	.long	BRTRAIL3
	.long	BRTRAIL4
	.long	BRTRAIL5
	.long	BRTRAIL6
	.long	0

BRANG1	.long	BOOMERANG1,0
BRANG2	.long	BOOMERANG2,0
BRANG3	.long	BOOMERANG3,0
BRANG4	.long	BOOMERANG4,0
BRANG5	.long	BOOMERANG5,0
BRANG6	.long	BOOMERANG6,0
BRANG7	.long	BOOMERANG7,0
BRANG8	.long	BOOMERANG8,0
BRANG9	.long	BOOMERANG9,0
BRANG10	.long	BOOMERANG10,0
BRANG11	.long	BOOMERANG11,0


a_scared
	.long	KTSCARRED2
	.long	0

KTSCARRED2
	.long	KTSCARRED2A,0


a_fan_decap
	.long	KTFANDECAP1

	.long	ani_adjustx
	.word	5
	.long	KTFANDECAP3
	.long	ani_adjustx
	.word	5
	.long	KTFANDECAP4
	.long	ani_adjustx
	.word	5
	.long	KTFANDECAP5
	.long	KTFANDECAP6
	.long	KTFANDECAP7
	.long	0

KTFANDECAP1
	.long	KTFANDECAP1A,KTFANDECAP1B,0
KTFANDECAP3
	.long	KTFANDECAP3A,KTFANDECAP3B,KTFANDECAP3C,0
KTFANDECAP4
	.long	KTFANDECAP4A,KTFANDECAP4B,0
KTFANDECAP5
	.long	KTFANDECAP5A,KTFANDECAP5B,0
KTFANDECAP6
	.long	KTFANDECAP6A,KTFANDECAP6B,0
KTFANDECAP7
	.long	KTFANDECAP7A,KTFANDECAP7B,0


a_kitana_kiss
	.long	KTKISS1
	.long	KTKISS2
	.long	KTKISS3
	.long	KTKISS4
	.long	ani_adjustx
	.word	5
	.long	KTKISS5
	.long	ani_adjustx
	.word	5
	.long	KTKISS6
	.long	ani_adjustx
	.word	5
	.long	KTKISS7
	.long	ani_adjustx
	.word	5
	.long	KTKISS8
	.long	KTKISS9
	.long	KTKISS10
	.long	0

	.long	KTKISS9
	.long	KTKISS8
	.long	KTKISS7
	.long	KTKISS6
	.long	KTKISS5
	.long	KTKISS4
	.long	KTKISS3
	.long	KTKISS2
	.long	KTKISS1
	.long	0

a_kitana_bubbles
	.long	KTKISS1
	.long	KTKISS2
	.long	KTKISS3
	.long	KTKISS4
	
	.long	ani_sladd,BUBBLE1
	.long	ani_slani,BUBBLE2
	.long	KTKISS5
	.long	ani_slani,BUBBLE3
	.long	KTKISS6
	.long	ani_slani,BUBBLE4
	.long	KTKISS7
	.long	ani_slani,BUBBLE5
	.long	KTKISS8
	.long	ani_slani,BUBBLE6
	.long	KTKISS9
	.long	ani_slani,BUBBLE7
	.long	ani_calla,spawn_bubble
	.long	KTKISS10
	.long	0

	.long	BLOBUBBLE1

	.long	BLOBUBBLE8
	.long	BLOBUBBLE9
	.long	BLOBUBBLE10
	.long	BLOBUBBLE11
	.long	BLOBUBBLE12

	.long	BLOBUBBLE13
	.long	0

	.long	BLOBUBBLE14
	.long	BLOBUBBLE15
	.long	BLOBUBBLE16
	.long	0


BUBBLE1	.long	BLOBUBBLE1,0
BUBBLE2	.long	BLOBUBBLE2,0
BUBBLE3	.long	BLOBUBBLE3,0
BUBBLE4	.long	BLOBUBBLE4,0
BUBBLE5	.long	BLOBUBBLE5,0
BUBBLE6	.long	BLOBUBBLE6,0
BUBBLE7	.long	BLOBUBBLE7,0
BUBBLE8	.long	BLOBUBBLE8,0
BUBBLE9	.long	BLOBUBBLE9,0
BUBBLE10	.long	BLOBUBBLE10,0
BUBBLE11	.long	BLOBUBBLE11,0
BUBBLE12	.long	BLOBUBBLE12,0
BUBBLE13	.long	BLOBUBBLE13,0
BUBBLE14	.long	BLOBUBBLE14,0
BUBBLE15	.long	BLOBUBBLE15,0
BUBBLE16	.long	BLOBUBBLE16,0

KTKISS1	.long	KTKISS1A,KTKISS1B,0
KTKISS2	.long	KTKISS2A,KTKISSLEG1A,KTKISSLEG1B,0
KTKISS3	.long	KTKISS3A,KTKISSLEG1A,KTKISSLEG1B,0
KTKISS4	.long	KTKISS4A,KTKISSLEG1A,KTKISSLEG1B,0
KTKISS5	.long	KTKISS5A,KTKISS5B,0
KTKISS6	.long	KTKISS6A,KTKISS6B,0
KTKISS7	.long	KTKISS7A,KTKISS7B,0
KTKISS8	.long	KTKISS8A,KTKISS8B,0
KTKISS9	.long	KTKISS9A,0
KTKISS10	.long	KTKISS10A,KTKISS10B,0


;*********************************
;**********************************************************

a_kitty
	.long	PUSSY1
	.long	PUSSY2
	.long	PUSSY3
	.long	PUSSY4
	.long	PUSSY5
	.long	PUSSY6
	.long	PUSSY7
	.long	PUSSY8
	.long	PUSSY9
	.long	PUSSY10
	.long	PUSSY11
	.long	0

	.long	PUSSY12
	.long	PUSSY13
	.long	PUSSY14
	.long	PUSSY15
	.long	PUSSY16
	.long	PUSSY17
	.long	0


	.long	PUSSY18
	.long	PUSSY19
	.long	PUSSY20
	.long	PUSSY21
	.long	PUSSY22
	.long	PUSSY23
	.long	0

	.long	PUSSY24
	.long	PUSSY25
	.long	PUSSY26
	.long	0


a_bunny
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	BUNNY2
	.long	BUNNY1
	.long	0

	.long	BUNNY3
	.long	BUNNY4
	.long	0

j_bunny	.long	BUNNY5
	.long	BUNNY6
	.long	ani_jump,j_bunny



a_skunk
	.long	SKUNK1
	.long	SKUNK2
	.long	SKUNK3
	.long	SKUNK4
	.long	SKUNK3
	.long	SKUNK2
	.long	SKUNK1
	.long	0

	.long	PUFF1
	.long	PUFF2
	.long	PUFF3
	.long	PUFF4
	.long	PUFF5
	.long	0

;**********************************************************

a_rod_shaker
	.long	JDSTAFFSHAKE1
	.long	JDSTAFFSHAKE2
	.long	JDSTAFFSHAKE3
	.long	JDSTAFFSHAKE4
	.long	0

j_shake	.long	JDSTAFFSHAKE5
	.long	ani_calla,rsnd_whoosh
	.long	JDSTAFFSHAKE6
	.long	JDSTAFFSHAKE7
	.long	JDSTAFFSHAKE6
	.long	ani_jump,j_shake
	.long	0
*
* part 3 - skeleton
*
	.long	ani_calla,use_shakbod_pal
j_bod	.long	SHAKBOD1
	.long	SHAKBOD6
	.long	SHAKBOD4
	.long	SHAKBOD6
	.long	ani_jump,j_bod


;**************************
;	.long	ani_sladd,SHAKROD1
;	.long	ani_slani_sleep,SHAKROD2
;	.long	ani_slani,SHAKROD3
;	.long	ani_slani,SHAKROD4
;	.long	JDSTAFFSHAKE7
;	.long	ani_slani_sleep,SHAKROD5
;	.long	ani_slani_sleep,SHAKROD6
;	.long	0

SHAKROD1	.long	SHAKROD1A,0
SHAKROD2	.long	SHAKROD2A,0
SHAKROD3	.long	SHAKROD3A,0
SHAKROD4	.long	SHAKROD4A,0
SHAKROD5	.long	SHAKROD5A,0
SHAKROD6	.long	SHAKROD6A,0

JDSTAFFSHAKE1
	.long	JDSTAFFSHAKE1A,JDSTAFFSHAKE1B,0
JDSTAFFSHAKE2
	.long	JDSTAFFSHAKE2A,JDSTAFFSHAKE2B,0
JDSTAFFSHAKE3
	.long	JDSTAFFSHAKE3A,JDSTAFFSHAKE3B,0
JDSTAFFSHAKE4
	.long	JDSTAFFSHAKE4A,JDSTAFFSHAKE4B,0
JDSTAFFSHAKE5
	.long	JDSTAFFSHAKE5A,JDSTAFFSHAKE5B,JDSTAFFSHAKE5C,0
JDSTAFFSHAKE6
	.long	JDSTAFFSHAKE6A,JDSTAFFSHAKE6B,0
JDSTAFFSHAKE7
	.long	JDSTAFFSHAKE7A,JDSTAFFSHAKE7B,JDSTAFFSHAKE7C,0
SHAKBOD1
	.long	SHAKBOD1A,SHAKBOD1B,0
SHAKBOD2
	.long	SHAKBOD2A,SHAKBOD2B,0
SHAKBOD3
	.long	SHAKBOD3A,SHAKBOD3B,0
SHAKBOD4
	.long	SHAKBOD4A,SHAKBOD4B,0
SHAKBOD5
	.long	SHAKBOD5A,SHAKBOD5B,0
SHAKBOD6
	.long	SHAKBOD6A,0

;**********************************************************

a_jade_shook
	.long	ani_offset_xy
	.word	->83,->18
	.long	KTFLIPPED1
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	KTSTUMBLE1
	.long	ani_offset_xy
	.word	->6d,>24
	.long	KTKNOCKDOWN2
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	KTSTUMBLE1
	.long	ani_jump,a_jade_shook

;***************************************************************

a_rod_impale
	.long	ani_sladd,RIMPALE1
	.long	JDIMPALE1
	.long	ani_slani,RIMPALE3
	.long	JDIMPALE3
	.long	ani_slani,RIMPALE5
	.long	JDIMPALE5
	.long	ani_slani,RIMPALE6
	.long	JDIMPALE6
	.long	0

JDIMPALE1
	.long	JDIMPALE1A,JDIMPALE1B,0
JDIMPALE3
	.long	JDIMPALE3A,JDIMPALE3B,0
JDIMPALE5
	.long	JDIMPALE5A,JDIMPALE5B,JDIMPALE5C,0
JDIMPALE6
	.long	JDIMPALE6A,JDIMPALE6B,JDIMPALE6C,0

RIMPALE1	.long	RODIMPALE1,0
RIMPALE3	.long	RODIMPALE3,0
RIMPALE5	.long	RODIMPALE5,0
RIMPALE6	.long	RODIMPALE6,0

;***************************************************************

a_pogo_stick
	.long	JDPOGO1
	.long	JDPOGO2
	.long	JDPOGO3
	.long	JDPOGO4
	.long	0

JDPOGO1	.long	JDPOGO1A,JDPOGO1B,JDPOGO1C,0
JDPOGO2	.long	JDPOGO2A,JDPOGO2B,0
JDPOGO3	.long	JDPOGO3A,0
JDPOGO4	.long	JDPOGO4A,0

;***************************************************************
a_swallow_nails
	.long	MLSWALLOW1
	.long	MLSWALLOW2
	.long	MLSWALLOW3
	.long	MLSWALLOW4
	.long	MLSWALLOW5
	.long	MLSWALLOW6
	.long	MLSWALLOW7
	.long	MLSWALLOW8
	.long	MLSWALLOW9
	.long	MLSWALLOW10
	.long	MLSWALLOW11

j_swallow
	.long	MLSWALLOW12
	.long	MLSWALLOW13
	.long	MLSWALLOW14
	.long	MLSWALLOW15
	.long	ani_calla,rsnd_small_block

;j_swallow
;	.long	MLSWALLOW16
;	.long	MLSWALLOW17
;	.long	MLSWALLOW16
;	.long	MLSWALLOW15
;	.long	MLSWALLOW13
;	.long	MLSWALLOW14
;	.long	MLSWALLOW15

	.long	ani_jump,j_swallow
	.long	0

	.long	MLNAILSPIT1
	.long	MLNAILSPIT2
	.long	MLNAILSPIT3
	.long	MLNAILSPIT4
	.long	MLNAILSPIT5
	.long	MLNAILSPIT6
	.long	MLNAILSPIT7
	.long	MLNAILSPIT8
	.long	0

j_nail_spit
	.long	MLNAILSPIT9
	.long	MLNAILSPIT10
	.long	ani_jump,j_nail_spit
	.long	0
*
* part 4 = nail
*
	.long	NAIL1	
	.long	NAIL2
	.long	0


MLSWALLOW1
	.long	MLSWALLOW1A,MLSWALLOW1B,0
MLSWALLOW2
	.long	MLSWALLOW2A,MLSWALLOW2B,0
MLSWALLOW3
	.long	MLSWALLOW3A,MLSWALLOW3B,0
MLSWALLOW4
	.long	MLSWALLOW4A,MLSWALLOW4B,MLSWALLOW4C,0
MLSWALLOW5
	.long	MLSWALLOW5A,MLSWALLOW5B,0
MLSWALLOW6
	.long	MLSWALLOW6A,MLSWALLOW6B,0
MLSWALLOW7
	.long	MLSWALLOW7A,MLSWALLOW7B,0
MLSWALLOW8
	.long	MLSWALLOW8A,MLSWALLOW8B,0
MLSWALLOW9
	.long	MLSWALLOW9A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW10
	.long	MLSWALLOW10A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW11
	.long	MLSWALLOW11A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW12
	.long	MLSWALLOW12A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW13
	.long	MLSWALLOW13A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW14
	.long	MLSWALLOW14A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW15
	.long	MLSWALLOW15A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW16
	.long	MLSWALLOW16A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0
MLSWALLOW17
	.long	MLSWALLOW17A,MLSWALLOWLEG1A,MLSWALLOWLEG1B,0

MLNAILSPIT1
	.long	MLNAILSPIT1A,MLNAILSPIT1B,0
MLNAILSPIT2
	.long	MLNAILSPIT2A,MLNAILSPIT2B,0
MLNAILSPIT3
	.long	MLNAILSPIT3A,MLNAILSPIT3B,0
MLNAILSPIT4
	.long	MLNAILSPIT4A,MLNAILSPIT4B,0
MLNAILSPIT5
	.long	MLNAILSPIT5A,MLNAILSPIT5B,0
MLNAILSPIT6
	.long	MLNAILSPIT6A,MLNAILSPIT6B,0
MLNAILSPIT7
	.long	MLNAILSPIT7A,MLNAILSPIT7B,0
MLNAILSPIT8
	.long	MLNAILSPIT8A,MLNAILSPIT8B,0
MLNAILSPIT9
	.long	MLNAILSPIT9A,MLNAILSPITLEG1A,MLNAILSPITLEG1B,0
MLNAILSPIT10
	.long	MLNAILSPIT10A,MLNAILSPITLEG1A,MLNAILSPITLEG1B,0


a_suck_spit
	.long	MLSUCKSPIT1
	.long	MLSUCKSPIT2
	.long	MLSUCKSPIT3
	.long	MLSUCKSPIT4
	.long	MLSUCKSPIT5
	.long	MLSUCKSPIT6
	.long	0

MLSUCKSPIT1
	.long	MLSUCKSPIT1A,MLSUCKSPIT1B,0
MLSUCKSPIT2
	.long	MLSUCKSPIT2A,MLSUCKSPIT2B,0
MLSUCKSPIT3
	.long	MLSUCKSPIT3A,MLSUCKSPIT3B,0
MLSUCKSPIT4
	.long	MLSUCKSPIT4A,MLSUCKSPIT4B,0
MLSUCKSPIT5
	.long	MLSUCKSPIT5A,MLSUCKSPIT5B,0
MLSUCKSPIT6
	.long	MLSUCKSPIT6A,MLSUCKSPIT6B,0

;******************

a_mirror_mirror
	.long	MLMIRROR1
	.long	MLMIRROR2
	.long	MLMIRROR3
	.long	MLMIRROR4
	.long	MLMIRROR5
	.long	MLMIRROR6
;	.long	MLMIRROR7
	.long	MIRRORBREAK1
	.long	0

	.long	MIRRORBREAK2
	.long	MIRRORBREAK3
	.long	MIRRORBREAK4
	.long	MIRRORBREAK5
	.long	MIRRORBREAK6
	.long	MIRRORBREAK7
	.long	MIRRORBREAK8
	.long	MIRRORBREAK9
	.long	MIRRORBREAK10
	.long	MIRRORBREAK11
	.long	MIRRORBREAK12
	.long	MIRRORBREAK13
	.long	0


MLMIRROR1
	.long	MLMIRROR1A,MLMIRROR1B,0
MLMIRROR2
	.long	MLMIRROR2A,MLMIRROR2B,0
MLMIRROR3
	.long	MLMIRROR3A,MLMIRROR3B,0
MLMIRROR4
	.long	MLMIRROR4A,MLMIRROR4B,0
MLMIRROR5
	.long	MLMIRROR5A,MLMIRROR5B,MLMIRROR5C,0
MLMIRROR6
	.long	MLMIRROR6A,MLMIRROR6B,MLMIRROR6C,0
MLMIRROR7
	.long	MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0

MIRRORBREAK1
	.long	MIRRORBREAK1A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK2
	.long	MIRRORBREAK2A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK3
	.long	MIRRORBREAK3A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK4
	.long	MIRRORBREAK4A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK5
	.long	MIRRORBREAK5A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK6
	.long	MIRRORBREAK6A,MIRRORBREAK6B,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK7
	.long	MIRRORBREAK7A,MIRRORBREAK7B,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK8
	.long	MIRRORBREAK8A,MIRRORBREAK8B,MIRRORBREAK8C,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK9
	.long	MIRRORBREAK9A,MIRRORBREAK9B,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK10
	.long	MIRRORBREAK10A,MIRRORBREAK10B,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK11
	.long	MIRRORBREAK11A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK12
	.long	MIRRORBREAK12A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0
MIRRORBREAK13
	.long	MIRRORBREAK13A,MLMIRROR7A,MLMIRROR7B,MLMIRROR7C,0

;********************************************************************
a_back_break
	.long	KTBACKBREAK1
	.long	0

KTBACKBREAK1
	.long	KTBACKBREAK3A,KTBACKBREAK3B,0
;********************************************************************
a_baby
	.long	BABYKIT
	.long	0
	
;********************************************************************
a_big_head
	.long	BHKIT1
	.long	BHKIT2
	.long	BHKIT3
	.long	BHKIT4
	.long	BHKIT5
	.long	0
;********************************************************************
a_half_cutup
	.long	HALF_FN
	.long	0
	
HALF_FN
	.long	KTCAT1D,KTCAT1C,0

;********************************************************************
a_cutup
	.long	KTCAT1
	.long	0
	
KTCAT1
	.long	 KTCAT1A,KTCAT1B,KTCAT1C,KTCAT1D,0

;********************************************************************
a_float
	.long	FNFLOAT	
	.long	0
	
FNFLOAT	
	.long	BHKIT1,BHKIT2,BHKIT3,BHKIT4,BHKIT5,0
;********************************************************************
a_pounded
	.long	KTFALLTHUD1
	.long	0

;********************************************************************
a_reach
	.long	ani_adjustxy
	.word	0,-9
	.long	FNMOUTH4
	.long	FNMOUTH5
	.long	FNMOUTH6
	.long	FNMOUTH8
	.long	0
FNMOUTH4	.long	KTMOUTH4,KTSKELEG,0
FNMOUTH5	.long	KTMOUTH5,KTSKELEG,0
FNMOUTH6	.long	KTMOUTH6,0
FNMOUTH8	.long	KTMOUTH8,0
;********************************************************************
a_skin_rip
	.long	KTRIP1
	.long	0
KTRIP1	.long	KTRIP1A,KTRIP1B,0
;********************************************************************
a_stretch
	.long	GROKITANA2
	.long	GROKITANA4
	.long	GROKITANA5
	.long	0

GROKITANA2
	.long	GROKITANA2A,GROKITANA2B,0
GROKITANA4
	.long	GROKITANA4A,GROKITANA4B,0
GROKITANA5
	.long	GROKITANA5A,GROKITANA5B,0
;********************************************************************
a_suk
	.long	SUKKIT1
	.long	SUKKIT3
	.long	SUKKIT4
	.long	SUKKIT5
	.long	SUKKIT6
	.long	0

SUKKIT1
	.long	SUKKIT1A,SUKKIT1B,0
SUKKIT3
	.long	SUKKIT3A,SUKKIT3B,0
SUKKIT4
	.long	SUKKIT4A,0
SUKKIT5
	.long	SUKKIT5A,0
SUKKIT6
	.long	SUKKIT6A,0

;********************************************************************
a_shocked
	.long	KTBZZ1
	.long	KTBZZ2
	.long	KTBZZ3
	.long	KTBZZ4
	.long	0
KTBZZ1	.long	KTBUZZ1,0
KTBZZ2	.long	KTBUZZ2,0
KTBZZ3	.long	KTBUZZ3,0
KTBZZ4	.long	KTBUZZ4,0
;********************************************************************
a_shredded
	.long	ani_adjustxy
	.word	6,6
	.long	KTSTUMBLE1

	.long	ani_adjustxy
	.word	-6,-6
	.long	KTSTUMBLE2

	.long	ani_adjustxy
	.word	6,6
	.long	KTSTUMBLE3

	.long	ani_adjustxy
	.word	-6,-6
	.long	KTSTUMBLE2

	.long	ani_jump,a_shredded

	.end

