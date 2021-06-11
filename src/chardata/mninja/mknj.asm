**************************************************************************
*											     *
*  mk3 - Scorpion / Reptile / Subzero								*
*											     *
**************************************************************************
	.FILE	'mknj.asm'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.include imgtbl.glo
	.include mainequ.asm
	.include sysequ.asm
	.include mknj.tbl

	.text


nj_anitab1
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
	.long	a_ermac_zap		; 24 - 
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
	.long	a_fb_mileena	; 37 -


	.long	a_fb_nj		; 38 - flipped by male ninja (scorpion)
	.long	a_fb_nj		; 39 - flipped by male ninja (reptile)
	.long	a_fb_nj		; 3a - flipped by male ninja (ermac)
	.long	a_fb_nj		; 3b - flipped by male ninja (oldsz)
	.long	a_fb_nj		; 3c - flipped by male ninja (oldsmoke)
	.long	a_fb_nj		; 3d - flipped by male ninja (noob)
	.long	a_fb_nj		; 3e - flipped by male ninja (rain)
	.long	a_fb_nj		; 3f - flipped by male ninja (rayden)
	.long	a_fb_nj		; 40 - flipped by male ninja (baraka)

	.long	a_dummy		; 3c
	.long	a_afb_kano	; 3d - air flipped by kano
	.long	a_legged	; 3e - legged by sonya
	.long	a_projectile	; 3f - projectile animation
	.long	a_shook		; 40 - shook by kano
	.long	a_afb_robo2	; 41 - air flipped by robo2
	.long	a_zoomed	; 42 - zoomed
	.long	a_orb_banged	; 43 - hit by reptile's obj thingy
	.long	a_jade_shook	; 44 - shook by jade
	.long	0				; 45
	.long	a_run		; 46 - run
	.long	a_thudd		; 47 -
	.long	a_scared	; 48 -

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

nj_anitab2
	.long	a_reptile_elbow2	;  0 
	.long	a_reptile_inv		;  1
	.long	a_slide			;  2 - Subzero/Reptile slide move
	.long	a_osz_elbow		;  3
	.long	a_ermac_elbow3		;  4
	.long	a_release_orb		;  5
	.long	a_spit  		;  6 - reptile spitting
	.long	a_spit_glob		;  7 - a glob o spit
	.long	a_scorp_tele		;  8 -
	.long	a_throw_spear		;  9 -
	.long	a_air_throw		;  a - scorpion air slam
	.long	a_rep_dash_elbow	;  b
	.long	a_scorpion_summon 	;  c
	.long	a_mask_off		;  d
	.long	a_breath_fire		;  e
	.long	a_tony_flame		;  f - goskie mk2 flame
	.long	a_floor_ice		; 10 -
	.long	a_oldsz_zap		; 11	-
	.long	a_moving_roundhouse	; 12 -

	.long	a_vomit				; 14
	.long	a_hi_tongue			; 15
	.long	a_med_tongue		; 16
	.long	a_lo_tongue			; 17
	.long	a_reptile_chomp_head		; 18
	.long	a_schand			; 19
	.long	a_icespike			; 1a

a_dummy
a_zap
a_projectile

;*******************

a_stance
	.long	ani_ochar_jump
	.long	ft_reptile
	.long	a_reptile_stance

	.long	SCSTANCE1
	.long	SCSTANCE2
	.long	SCSTANCE3
	.long	SCSTANCE4
	.long	SCSTANCE5
	.long	SCSTANCE6
	.long	SCSTANCE7
	.long	SCSTANCE8
	.long	SCSTANCE9
	.long	ani_jump,a_stance

SCSTANCE1
	.long	SCSTANCE1A,SCSTANCE1B,0
SCSTANCE2
	.long	SCSTANCE2A,SCSTANCE2B,0
SCSTANCE3
	.long	SCSTANCE3A,SCSTANCE3B,0
SCSTANCE4
	.long	SCSTANCE4A,SCSTANCE4B,0
SCSTANCE5
	.long	SCSTANCE5A,SCSTANCE5B,0
SCSTANCE6
	.long	SCSTANCE6A,SCSTANCE6B,0
SCSTANCE7
	.long	SCSTANCE7A,SCSTANCE7B,0
SCSTANCE8
	.long	SCSTANCE8A,SCSTANCE8B,0
SCSTANCE9
	.long	SCSTANCE9A,SCSTANCE9B,0

;*******************

a_reptile_stance
	.long	RPSTANCE1
	.long	RPSTANCE2
	.long	RPSTANCE3
	.long	RPSTANCE4
	.long	RPSTANCE5
	.long	RPSTANCE6
	.long	RPSTANCE7
	.long	RPSTANCE8
	.long	RPSTANCE9
	.long	ani_jump,a_reptile_stance

RPSTANCE1
	.long	RPSTANCE1A,RPSTANCE1B,0
RPSTANCE2
	.long	RPSTANCE2A,RPSTANCE2B,0
RPSTANCE3
	.long	RPSTANCE3A,RPSTANCE3B,0
RPSTANCE4
	.long	RPSTANCE4A,RPSTANCE4B,0
RPSTANCE5
	.long	RPSTANCE5A,RPSTANCE5B,0
RPSTANCE6
	.long	RPSTANCE6A,RPSTANCE6B,0
RPSTANCE7
	.long	RPSTANCE7A,RPSTANCE7B,0
RPSTANCE8
	.long	RPSTANCE8A,RPSTANCE8B,0
RPSTANCE9
	.long	RPSTANCE9A,RPSTANCE9B,0

;*******************

a_walkf
	.long	SCWALK1
	.long	SCWALK2
	.long	SCWALK3
	.long	SCWALK4
	.long	SCWALK5
	.long	SCWALK6
	.long	SCWALK7
	.long	SCWALK8
	.long	SCWALK9
	.long	ani_jump,a_walkf

a_walkb
	.long	SCWALK9
	.long	SCWALK8
	.long	SCWALK7
	.long	SCWALK6
	.long	SCWALK5
	.long	SCWALK4
	.long	SCWALK3
	.long	SCWALK2
	.long	SCWALK1
	.long	ani_jump,a_walkb

SCWALK1	.long	SCWALKLEG1A,SCWALKLEG1B,SCWALKTORSO1A,0
SCWALK2	.long	SCWALKLEG2A,SCWALKTORSO2A,0
SCWALK3	.long	SCWALKLEG3A,SCWALKTORSO3A,0
SCWALK4	.long	SCWALKLEG4A,SCWALKTORSO4A,0
SCWALK5	.long	SCWALKLEG5A,SCWALKTORSO5A,0
SCWALK6	.long	SCWALKLEG6A,SCWALKTORSO6A,0
SCWALK7	.long	SCWALKLEG7A,SCWALKTORSO7A,0
SCWALK8	.long	SCWALKLEG8A,SCWALKLEG8B,SCWALKTORSO8A,0
SCWALK9	.long	SCWALKLEG9A,SCWALKLEG9B,SCWALKTORSO9A,0

;**************************

a_turn
	.long	SCTURN1
	.long	SCTURN2
	.long	ani_flip
	.long	SCTURN1
	.long	0

SCTURN1	.long	SCTURN1A,SCTURN1B,0
SCTURN2	.long	SCTURN2A,SCTURN2B,0

;**************************

a_block	.long	SCBLOCK1
	.long	SCBLOCK2
	.long	SCBLOCK3
	.long	0

SCBLOCK1	.long	SCBLOCK1A,SCBLOCK1B,0
SCBLOCK2	.long	SCBLOCK2A,SCBLOCK2B,0
SCBLOCK3	.long	SCBLOCK3A,SCBLOCK3B,0

;**************************

a_duck
	.long	SCDUCK1
      	.long	SCDUCK2
	.long	SCDUCK3
	.long	0
SCDUCK1
	.long	SCDUCK1A,SCDUCK1B,0
SCDUCK2
	.long	SCDUCK2A,SCDUCK2B,0
SCDUCK3
	.long	SCDUCK3A,SCDUCK3B,0

a_duck_block
	.long	SCDUCKBLOCK1
	.long	SCDUCKBLOCK2
	.long	SCDUCKBLOCK3
	.long	0

SCDUCKBLOCK1
	.long	SCDUCKBLOCK1A,SCDUCKBLOCK1B,0
SCDUCKBLOCK2
	.long	SCDUCKBLOCK2A,SCDUCKBLOCK2B,0
SCDUCKBLOCK3
	.long	SCDUCKBLOCK3A,SCDUCKBLOCK3B,0

a_duck_turn
	.long	SCDUCKTURN1
	.long	SCDUCKTURN2
	.long	ani_flip
	.long	SCDUCKTURN1
	.long	SCDUCK3
	.long	0

SCDUCKTURN1
	.long	SCDUCKTURN1A,SCDUCKTURN1B,0
SCDUCKTURN2
	.long	SCDUCKTURN2A,SCDUCKTURN2B,0

a_duck_punch
	.long	SCDUCKPUNCH1
	.long	SCDUCKPUNCH2
	.long	SCDUCKPUNCH3
	.long	0
	.long	SCDUCKPUNCH2
	.long	SCDUCKPUNCH1
	.long	SCDUCK3
	.long	0

SCDUCKPUNCH1
	.long	SCDUCKPUNCH1A,SCDUCKPUNCH1B,0
SCDUCKPUNCH2
	.long	SCDUCKPUNCH2A,0
SCDUCKPUNCH3
	.long	SCDUCKPUNCH3A,0


a_duck_kick_lo
	.long	SCDUCKLOKICK1
	.long	SCDUCKLOKICK2
	.long	SCDUCKLOKICK3
	.long	0
	.long	SCDUCKLOKICK2
	.long	SCDUCKLOKICK2
	.long	SCDUCK3
	.long	0

SCDUCKLOKICK1
	.long	SCDUCKLOKICK1A,SCDUCKLOKICK1B,0
SCDUCKLOKICK2
	.long	SCDUCKLOKICK2A,SCDUCKLOKICK2B,0
SCDUCKLOKICK3
	.long	SCDUCKLOKICK3A,SCDUCKLOKICK3B,SCDUCKLOKICK3C,0

a_duck_kick_hi
	.long	SCDUCKHIKICK1
	.long	SCDUCKHIKICK2
	.long	SCDUCKHIKICK3
	.long	SCDUCKHIKICK4
	.long	0
	.long	SCDUCKHIKICK3
	.long	SCDUCKHIKICK2
	.long	SCDUCKHIKICK1
	.long	SCDUCK3
	.long	0

SCDUCKHIKICK1
	.long	SCDUCKHIKICK1A,SCDUCKHIKICK1B,0
SCDUCKHIKICK2
	.long	SCDUCKHIKICK2A,SCDUCKHIKICK2B,0
SCDUCKHIKICK3
	.long	SCDUCKHIKICK3A,SCDUCKHIKICK3B,0
SCDUCKHIKICK4
	.long	SCDUCKHIKICK4A,SCDUCKHIKICK4B,0

a_uppercut
	.long	SCUPPERCUT1
	.long	SCUPPERCUT2
	.long	SCUPPERCUT4
	.long	SCUPPERCUT5
	.long	ani_nosleep	; dont sleep after next frame
	.long	SCUPPERCUT7
	.long	0
	.long	SCUPPERCUT5
	.long	0

SCUPPERCUT1
	.long	SCUPPERCUT1A,SCUPPERCUT1B,0
SCUPPERCUT2
	.long	SCUPPERCUT2A,SCUPPERCUT2B,0
SCUPPERCUT4
	.long	SCUPPERCUT4A,SCUPPERCUT4B,0
SCUPPERCUT5
	.long	SCUPPERCUT5A,SCUPPERCUT5B,SCUPPERCUT5C,0
SCUPPERCUT7
	.long	SCUPPERCUT7A,SCUPPERCUT7B,0

a_duck_hit
	.long	SCDUCKHIT2
	.long	SCDUCKHIT3
	.long	SCDUCKHIT2
	.long	SCDUCKHIT1
	.long	0

SCDUCKHIT1
	.long	SCDUCKHIT1A,SCDUCKHIT1B,0
SCDUCKHIT2
	.long	SCDUCKHIT2A,SCDUCKHIT2B,0
SCDUCKHIT3
	.long	SCDUCKHIT3A,SCDUCKHIT3B,0

a_hipunch
	.long	SCHIPUNCH1
	.long	SCHIPUNCH2
	.long	SCHIPUNCH3
	.long	0

	.long	SCHIPUNCH4
	.long	SCHIPUNCH5
	.long	SCHIPUNCH6
	.long	0
	.long	SCHIPUNCH5
	.long	SCHIPUNCH4
	.long	ani_jump,a_hipunch+(32*2)
	.long	0					; we NEED this "0"
*
* Unhipunch #1
*
	.long	SCHIPUNCH2
	.long	SCHIPUNCH1
	.long	0
*
* Unhipunch #2
*
	.long	SCHIPUNCH7
	.long	0
*
* Hi to Med #1
*
	.long	SCHIPUNCH4
	.long	SCLOPUNCH5
	.long	ani_jump,a_lopunch+(32*6)
	.long	0
*
* Hi to Med #2
*
	.long	SCHIPUNCH5
	.long	SCLOPUNCH2
	.long	ani_jump,a_lopunch+(32*2)
	.long	0

SCHIPUNCH1
	.long	SCHIPUNCH1A,SCHIPUNCH1B,0
SCHIPUNCH2
	.long	SCHIPUNCH2A,SCHIPUNCH2B,0
SCHIPUNCH3
	.long	SCHIPUNCH3A,SCHIPUNCH3B,0
SCHIPUNCH4
	.long	SCHIPUNCH4A,SCHIPUNCH4B,0
SCHIPUNCH5
	.long	SCHIPUNCH5A,SCHIPUNCH5B,0
SCHIPUNCH6
	.long	SCHIPUNCH6A,SCHIPUNCH6B,0
SCHIPUNCH7
	.long	SCHIPUNCH7A,SCHIPUNCH7B,0

a_lopunch
	.long	SCLOPUNCH1
	.long	SCLOPUNCH2
	.long	SCLOPUNCH3
	.long	0

	.long	SCLOPUNCH4
	.long	SCLOPUNCH5
	.long	SCLOPUNCH6
	.long	0

	.long	SCLOPUNCH5
	.long	SCLOPUNCH4
	.long	ani_jump,a_lopunch+(32*2)
	.long	0
*
* Unlopunch #1
*
	.long	SCLOPUNCH2
	.long	SCLOPUNCH1
	.long	0
*
* Unlopunch #2
*
	.long	SCHIPUNCH7
	.long	0
*
* Med to High #1
*
	.long	SCLOPUNCH4
	.long	SCLOPUNCH5
	.long	ani_jump,a_hipunch+(32*6)
	.long	0
*
* Med to High #2
*
	.long	SCLOPUNCH4
	.long	SCHIPUNCH5
	.long	ani_jump,a_hipunch+(32*2)

SCLOPUNCH1
	.long	SCLOPUNCH1A,SCLOPUNCH1B,0
SCLOPUNCH2
	.long	SCLOPUNCH2A,SCLOPUNCH2B,0
SCLOPUNCH3
	.long	SCLOPUNCH3A,SCLOPUNCH3B,0
SCLOPUNCH4
	.long	SCLOPUNCH4A,SCLOPUNCH4B,0
SCLOPUNCH5
	.long	SCLOPUNCH5A,SCLOPUNCH5B,0
SCLOPUNCH6
	.long	SCLOPUNCH6A,SCLOPUNCH6B,0

;*********************************************

a_elbow
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO1
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO2
	.long	SCCOMBO3
	.long	ani_nosleep
	.long	SCCOMBO4
	.long	0

	.long	SCCOMBO2
	.long	SCCOMBO1	; ani 2 = retract
	.long	0

	.long	ani_adjustx
	.word	6
	.long	SCCOMBO6
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO7
	.long	SCCOMBO8
	.long	SCCOMBO9	; ani 3 = hit 2
	.long	0

	.long	ani_adjustx
	.word	6
	.long	SCCOMBO10
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO11
	.long	SCCOMBO12	; ani 4 = hit 3
	.long	0

	.long	SCCOMBO11
	.long	SCCOMBO10
	.long	SCCOMBO9	; ani 5 = retract
	.long	0


a_ermac_elbow3
	.long	ani_adjustx
	.word	6
	.long	SCUPPERCUT1
	.long	ani_adjustx
	.word	6
	.long	SCUPPERCUT2
	.long	SCUPPERCUT4
	.long	SCUPPERCUT5
	.long	SCUPPERCUT7
	.long	0

	.long	SCUPPERCUT5
	.long	SCUPPERCUT4
	.long	SCUPPERCUT2
	.long	SCUPPERCUT1
	.long	0



a_osz_elbow
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO10
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO11
	.long	SCCOMBO12	; hit 1
	.long	0

	.long	SCCOMBO11
	.long	SCCOMBO10
	.long	0

	.long	RPCOMBO1
	.long	RPCOMBO2
	.long	RPCOMBO3
	.long	ani_nosleep
	.long	RPCOMBO4    	; ani3 = hit 2
	.long	0

	.long	RPCOMBO3
	.long	RPCOMBO2
	.long	RPCOMBO1	; ani4 = retract
	.long	0


a_rep_dash_elbow
	.long	SCCOMBO10
	.long	SCCOMBO11
	.long	SCCOMBO12
	.long	0
	.long	SCCOMBO11
	.long	SCCOMBO10
	.long	0

a_reptile_elbow2
	.long	RPCOMBO1
	.long	RPCOMBO2
	.long	RPCOMBO3
	.long	ani_nosleep
	.long	RPCOMBO4
	.long	0

	.long	RPCOMBO3
	.long	RPCOMBO2
	.long	RPCOMBO1
	.long	0
*
* part 3 = hit #2
*
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO10
	.long	ani_adjustx
	.word	6
	.long	SCCOMBO11
	.long	SCCOMBO12
	.long	0
*
* part 4 = hit #3
*
	.long	RPCOMBO6
	.long	RPCOMBO7
	.long	RPCOMBO8
	.long	RPCOMBO9
	.long	RPCOMBO10
	.long	0
*
* part 5 = retract
*
	.long	RPCOMBO9
	.long	RPCOMBO8
	.long	RPCOMBO7
	.long	RPCOMBO6
	.long	0

SCCOMBO1	.long	SCCOMBO1A,SCCOMBO1B,0
SCCOMBO2	.long	SCCOMBO2A,SCCOMBO2B,0
SCCOMBO3	.long	SCCOMBO3A,SCCOMBO3B,SCCOMBO3C,0
SCCOMBO4	.long	SCCOMBO4A,SCCOMBO4B,0
SCCOMBO6	.long	SCCOMBO6A,SCCOMBO6B,0
SCCOMBO7	.long	SCCOMBO7A,SCCOMBO7B,0
SCCOMBO8	.long	SCCOMBO8A,SCCOMBO8B,0
SCCOMBO9	.long	SCCOMBO9A,SCCOMBO9B,0
SCCOMBO10
	.long	SCCOMBO10A,SCCOMBO10B,0
SCCOMBO11
	.long	SCCOMBO11A,SCCOMBO11B,0
SCCOMBO12
	.long	SCCOMBO12A,SCCOMBO12B,0

;*********************************************

RPCOMBO1
	.long	RPCOMBO1A,RPCOMBO1B,0
RPCOMBO2
	.long	RPCOMBO2A,RPCOMBO2B,0
RPCOMBO3
	.long	RPCOMBO3A,0
RPCOMBO4
	.long	RPCOMBO4A,RPCOMBO4B,0
RPCOMBO6
	.long	RPCOMBO6A,RPCOMBO6B,0
RPCOMBO7
	.long	RPCOMBO7A,RPCOMBO7B,0
RPCOMBO8
	.long	RPCOMBO8A,RPCOMBO8B,0
RPCOMBO9
	.long	RPCOMBO9A,RPCOMBO9B,0
RPCOMBO10
	.long	RPCOMBO10A,RPCOMBO10B,0

a_lokick
	.long	SCLOKICK1
	.long	SCLOKICK2
	.long	SCLOKICK3
	.long	SCLOKICK4
	.long	SCLOKICK5
	.long	SCLOKICK6
	.long	0

	.long	SCLOKICK5
	.long	SCLOKICK4
	.long	SCLOKICK3
	.long	SCLOKICK2
	.long	SCLOKICK1
	.long	0

SCLOKICK1
	.long	SCLOKICK1A,SCLOKICK1B,0
SCLOKICK2
	.long	SCLOKICK2A,0
SCLOKICK3
	.long	SCLOKICK3A,SCLOKICK3B,0
SCLOKICK4
	.long	SCLOKICK4A,0
SCLOKICK5
	.long	SCLOKICK5A,SCLOKICK5B,0
SCLOKICK6
	.long	SCLOKICK6A,0

a_hikick
	.long	SCHIKICK1
	.long	SCHIKICK2
	.long	SCHIKICK3
	.long	SCHIKICK4
	.long	SCHIKICK5
	.long	SCHIKICK6
	.long	0
	.long	SCHIKICK5
	.long	SCHIKICK4
	.long	SCHIKICK3
	.long	SCHIKICK2
	.long	SCHIKICK1
	.long	0
SCHIKICK1
	.long	SCHIKICK1A,SCHIKICK1B,0
SCHIKICK2
	.long	SCHIKICK2A,SCHIKICK2B,0
SCHIKICK3
	.long	SCHIKICK3A,0
SCHIKICK4
	.long	SCHIKICK4A,SCHIKICK4B,0
SCHIKICK5
	.long	SCHIKICK5A,0
SCHIKICK6
	.long	SCHIKICK6A,SCHIKICK6B,0


a_knee
	.long	SCKNEECOMBO1
	.long	SCKNEECOMBO2
	.long	SCKNEECOMBO3
	.long	0
	.long	SCKNEECOMBO2
	.long	SCKNEECOMBO1
	.long	0
*
* part 3 = hit 2
* 
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO4
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO5
	.long	SCKNEECOMBO6
	.long	0
*
* part 4 = hit 3
* 
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO7
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO8
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO9
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO10
	.long	SCKNEECOMBO11
	.long	0
*
* part 5 = hit 4
* 
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO10
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO9
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO8
	.long	ani_adjustx
	.word	4
	.long	SCKNEECOMBO7
	.long	SCKNEECOMBO6
	.long	0
*
* part 6 = hit 5
*
	.long	SCKNEECOMBO5
	.long	SCKNEECOMBO4
	.long	SCKNEECOMBO3
	.long	SCKNEECOMBO2
	.long	SCKNEECOMBO1
	.long	0


a_moving_roundhouse
	.long	SCSPINHOOK1
	.long	ani_adjustx
	.word	8
	.long	SCSPINHOOK2
	.long	ani_adjustx
	.word	8
	.long	SCSPINHOOK3
	.long	ani_adjustx
	.word	8
	.long	SCSPINHOOK4
	.long	ani_adjustx
	.word	6
	.long	SCSPINHOOK5
	.long	0

	.long	SCSPINHOOK4
	.long	SCSPINHOOK3
	.long	SCSPINHOOK2
	.long	SCSPINHOOK1
	.long	0



SCKNEECOMBO1
	.long	SCKNEECOMBO1A,SCKNEECOMBO1B,0
SCKNEECOMBO2
	.long	SCKNEECOMBO2A,0
SCKNEECOMBO3
	.long	SCKNEECOMBO3A,SCKNEECOMBO3B,0
SCKNEECOMBO4
	.long	SCKNEECOMBO4A,SCKNEECOMBO4B,0
SCKNEECOMBO5
	.long	SCKNEECOMBO5A,SCKNEECOMBO5B,SCKNEECOMBO5C,0
SCKNEECOMBO6
	.long	SCKNEECOMBO6A,SCKNEECOMBO6B,SCKNEECOMBO6C,0
SCKNEECOMBO7
	.long	SCKNEECOMBO7A,SCKNEECOMBO7B,0
SCKNEECOMBO8
	.long	SCKNEECOMBO8A,SCKNEECOMBO8B,SCKNEECOMBO8C,0
SCKNEECOMBO9
	.long	SCKNEECOMBO9A,SCKNEECOMBO9B,SCKNEECOMBO9C,0
SCKNEECOMBO10
	.long	SCKNEECOMBO10A,SCKNEECOMBO10B,0
SCKNEECOMBO11
	.long	SCKNEECOMBO11A,SCKNEECOMBO11B,0

a_sweep_kick
	.long	SCSWEEPKICK1
	.long	SCSWEEPKICK2
	.long	SCSWEEPKICK3
	.long	ani_calla,sweep_sounds
	.long	SCSWEEPKICK4
	.long	SCSWEEPKICK5
	.long	0

	.long	SCSWEEPKICK6
	.long	SCSWEEPKICK7
	.long	SCSWEEPKICK8
	.long	0

SCSWEEPKICK1
	.long	SCSWEEPKICK1A,SCSWEEPKICK1B,0
SCSWEEPKICK2
	.long	SCSWEEPKICK2A,SCSWEEPKICK2B,0
SCSWEEPKICK3
	.long	SCSWEEPKICK3A,SCSWEEPKICK3B,0
SCSWEEPKICK4
	.long	SCSWEEPKICK4A,SCSWEEPKICK4B,0
SCSWEEPKICK5
	.long	SCSWEEPKICK5A,SCSWEEPKICK5B,0
SCSWEEPKICK6
	.long	SCSWEEPKICK6A,SCSWEEPKICK6B,0
SCSWEEPKICK7
	.long	SCSWEEPKICK7A,SCSWEEPKICK7B,0
SCSWEEPKICK8
	.long	SCSWEEPKICK8A,SCSWEEPKICK8B,0


a_roundhouse
	.long	SCSPINHOOK1
	.long	SCSPINHOOK2
	.long	SCSPINHOOK3
	.long	SCSPINHOOK4
	.long	ani_nosleep
	.long	SCSPINHOOK5
	.long	0

	.long	SCSPINHOOK6
	.long	SCSPINHOOK7
	.long	SCSPINHOOK8
	.long	0
*
* part 3 = combo roundhouse
*
	.long	SCSPINHOOK6
	.long	SCSPINHOOK7
	.long	SCSPINHOOK8
	.long	SCSPINHOOK1
	.long	SCSPINHOOK2
	.long	SCSPINHOOK3
	.long	SCSPINHOOK4
	.long	ani_nosleep
	.long	SCSPINHOOK5
	.long	0

	.long	SCSPINHOOK6
	.long	SCSPINHOOK7
	.long	SCSPINHOOK8
	.long	0


SCSPINHOOK1
	.long	SCSPINHOOK1A,SCSPINHOOK1B,0
SCSPINHOOK2
	.long	SCSPINHOOK2A,SCSPINHOOK2B,0
SCSPINHOOK3
	.long	SCSPINHOOK3A,0
SCSPINHOOK4
	.long	SCSPINHOOK4A,SCSPINHOOK4B,0
SCSPINHOOK5
	.long	SCSPINHOOK5A,SCSPINHOOK5B,SCSPINHOOK5C,0
SCSPINHOOK6
	.long	SCSPINHOOK6A,0
SCSPINHOOK7
	.long	SCSPINHOOK7A,0
SCSPINHOOK8
	.long	SCSPINHOOK8A,SCSPINHOOK8B,0

;********************************

a_jump	.long	SCJUMP1
	.long	SCJUMP2
	.long	SCJUMP3
	.long	0

SCJUMP1	.long	SCJUMP1A,SCJUMP1B,0
SCJUMP2	.long	SCJUMP2A,SCJUMP2B,0
SCJUMP3	.long	SCJUMP3A,SCJUMP3B,0

;********************************

a_jump_kick
	.long	SCJUMPKICK1
	.long	SCJUMPKICK2
	.long	SCJUMPKICK3
	.long	0
	.long	SCJUMPKICK2
	.long	SCJUMPKICK1
	.long	0

SCJUMPKICK1
	.long	SCJUMPKICK1A,0
SCJUMPKICK2
	.long	SCJUMPKICK2A,SCJUMPKICK2B,0
SCJUMPKICK3
	.long	SCJUMPKICK3A,SCJUMPKICK3B,0


a_fflip
	.long	SCJUMPFLIP1
	.long	SCJUMPFLIP2
	.long	SCJUMPFLIP3
	.long	SCJUMPFLIP4
	.long	SCJUMPFLIP5
	.long	SCJUMPFLIP6
	.long	SCJUMPFLIP7
	.long	SCJUMPFLIP8
	.long	ani_jump,a_fflip+32

a_bflip
	.long	SCJUMPFLIP1
	.long	SCJUMPFLIP8
	.long	SCJUMPFLIP7
	.long	SCJUMPFLIP6
	.long	SCJUMPFLIP5
	.long	SCJUMPFLIP4
	.long	SCJUMPFLIP3
	.long	SCJUMPFLIP2
	.long	ani_jump,a_bflip+32

SCJUMPFLIP1
	.long	SCJUMPFLIP1A,0
SCJUMPFLIP2
	.long	SCJUMPFLIP2A,0
SCJUMPFLIP3
	.long	SCJUMPFLIP3A,0
SCJUMPFLIP4
	.long	SCJUMPFLIP4A,0
SCJUMPFLIP5
	.long	SCJUMPFLIP5A,0
SCJUMPFLIP6
	.long	SCJUMPFLIP6A,0
SCJUMPFLIP7
	.long	SCJUMPFLIP7A,0
SCJUMPFLIP8
	.long	SCJUMPFLIP8A,0

a_flip_kick
	.long	SCFLIPKICK1
	.long	SCFLIPKICK2
	.long	SCFLIPKICK3
	.long	0
	.long	SCFLIPKICK2
	.long	SCFLIPKICK1
	.long	0


SCFLIPKICK1
	.long	SCFLIPKICK1A,0
SCFLIPKICK2
	.long	SCFLIPKICK2A,0
SCFLIPKICK3
	.long	SCFLIPKICK3A,0

;*****************************

a_flip_punch
	.long	SCFLIPUNCH1
	.long	SCFLIPUNCH2
	.long	SCFLIPUNCH3
	.long	0
	.long	SCFLIPUNCH2
	.long	SCFLIPUNCH1
	.long	0

SCFLIPUNCH1
	.long	SCFLIPUNCH1A,0
SCFLIPUNCH2
	.long	SCFLIPUNCH2A,SCFLIPUNCH2B,0
SCFLIPUNCH3
	.long	SCFLIPUNCH3A,SCFLIPUNCH3B,SCFLIPUNCH3C,0

;*****************************

a_slide	.long	SCDUCK1
	.long	SZSLIDE2
	.long	SZSLIDE3
	.long	0

SZSLIDE2	.long	SZSLIDE2A,SZSLIDE2B,0
SZSLIDE3	.long	SZSLIDE3A,SZSLIDE3B,0

;*****************************

a_scorp_tele
	.long	SCFLIPUNCH1
	.long	SCFLIPUNCH2
	.long	SCTELEPUNCH1
	.long	0

SCTELEPUNCH1
	.long	SCTELEPUNCH1A,SCTELEPUNCH1B,SCTELEPUNCH1C,0

;*****************************

a_hit_hi
	.long	SCHIHIT2
	.long	SCHIHIT3
	.long	SCHIHIT2
	.long	SCHIHIT1
	.long	0

SCHIHIT1
	.long	SCHIHIT1A,SCHIHIT1B,0
SCHIHIT2
	.long	SCHIHIT2A,SCHIHIT2B,0
SCHIHIT3
	.long	SCHIHIT3A,SCHIHIT3B,0

a_hit_lo
	.long	SCLOHIT2
	.long	SCLOHIT3
	.long	SCLOHIT2
	.long	SCLOHIT1
	.long	0


SCLOHIT1
	.long	SCLOHIT1A,SCLOHIT1B,0
SCLOHIT2
	.long	SCLOHIT2A,SCLOHIT2B,0
SCLOHIT3
	.long	SCLOHIT3A,SCLOHIT3B,0

a_stumble
	.long	SCSTUMBLE1
	.long	SCSTUMBLE2
	.long	SCSTUMBLE3
	.long	SCSTUMBLE4
	.long	SCSTUMBLE5
	.long	SCSTUMBLE7
	.long	SCSTUMBLE8
	.long	SCSTUMBLE9
	.long	0

j_stumble
	.long	SCSTUMBLE1
	.long	SCSTUMBLE2
	.long	SCSTUMBLE3
	.long	SCSTUMBLE4
	.long	SCSTUMBLE5
	.long	SCSTUMBLE7
	.long	SCSTUMBLE8
	.long	SCSTUMBLE9
	.long	ani_jump,j_stumble

SCSTUMBLE1
	.long	SCSTUMBLE1A,SCSTUMBLE1B,0
SCSTUMBLE2
	.long	SCSTUMBLE2A,SCSTUMBLE2B,0
SCSTUMBLE3
	.long	SCSTUMBLE3A,SCSTUMBLE3B,0
SCSTUMBLE4
	.long	SCSTUMBLE4A,SCSTUMBLE4B,0
SCSTUMBLE5
	.long	SCSTUMBLE5A,SCSTUMBLE5B,0
SCSTUMBLE7
	.long	SCSTUMBLE7A,0
SCSTUMBLE8
	.long	SCSTUMBLE8A,SCSTUMBLE8B,SCSTUMBLE8C,0
SCSTUMBLE9
	.long	SCSTUMBLE9A,SCSTUMBLE9B,0


a_knockdown
	.long	SCKNOCKDOWN1
	.long	SCKNOCKDOWN2
	.long	SCKNOCKDOWN3
	.long	SCKNOCKDOWN4
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	0
	.long	SCKNOCKDOWN7
	.long	SCKNOCKDOWN8
	.long	0

SCKNOCKDOWN1
	.long	SCKNOCKDOWN1A,SCKNOCKDOWN1B,0
SCKNOCKDOWN2
	.long	SCKNOCKDOWN2A,0
SCKNOCKDOWN3
	.long	SCKNOCKDOWN3A,0
SCKNOCKDOWN4
	.long	SCKNOCKDOWN4A,0
SCKNOCKDOWN5
	.long	SCKNOCKDOWN5A,SCKNOCKDOWN5B,0
SCKNOCKDOWN6
	.long	SCKNOCKDOWN6A,SCKNOCKDOWN6B,0
SCKNOCKDOWN7
	.long	SCKNOCKDOWN7A,0
SCKNOCKDOWN8
	.long	SCKNOCKDOWN8A,0

a_getup
	.long	SCGETUP1
	.long	SCGETUP2
	.long	SCGETUP3
	.long	SCGETUP4
	.long	SCGETUP5
	.long	SCGETUP6
	.long	0

SCGETUP1
	.long	SCGETUP1A,0
SCGETUP2
	.long	SCGETUP2A,0
SCGETUP3
	.long	SCGETUP3A,0
SCGETUP4
	.long	SCGETUP4A,SCGETUP4B,0
SCGETUP5
	.long	SCGETUP5A,SCGETUP5B,0
SCGETUP6
	.long	SCGETUP6A,SCGETUP6B,0


a_sweep_fall
	.long	SCSWEEPFALL1
	.long	SCSWEEPFALL2
	.long	SCSWEEPFALL3
	.long	SCSWEEPFALL4
	.long	0
	.long	SCSWEEPFALL5
	.long	SCSWEEPFALL6
	.long	0

SCSWEEPFALL1
	.long	SCSWEEPFALL1A,SCSWEEPFALL1B,0
SCSWEEPFALL2
	.long	SCSWEEPFALL2A,SCSWEEPFALL2B,0
SCSWEEPFALL3
	.long	SCSWEEPFALL3A,SCSWEEPFALL3B,0
SCSWEEPFALL4
	.long	SCSWEEPFALL4A,SCSWEEPFALL4B,0
SCSWEEPFALL5
	.long	SCSWEEPFALL5A,SCSWEEPFALL5B,0
SCSWEEPFALL6
	.long	SCSWEEPFALL6A,0

a_sweepup
	.long	SCSWEEPUP1
	.long	SCSWEEPUP2
	.long	SCSWEEPUP3
	.long	SCSWEEPUP4
	.long	SCSWEEPUP5
	.long	SCSWEEPUP6
	.long	0

SCSWEEPUP1
	.long	SCSWEEPUP1A,0
SCSWEEPUP2
	.long	SCSWEEPUP2A,SCSWEEPUP2B,0
SCSWEEPUP3
	.long	SCSWEEPUP3A,SCSWEEPUP3B,0
SCSWEEPUP4
	.long	SCSWEEPUP4A,0
SCSWEEPUP5
	.long	SCSWEEPUP5A,SCSWEEPUP5B,0
SCSWEEPUP6
	.long	SCSWEEPUP6A,SCSWEEPUP6B,0


a_orb_banged
	.long	SCFLIPPED1
	.long	SCFLIPPED2
	.long	SCFLIPPED3
	.long	SCFLIPPED4
	.long	SCFLIPPED5
	.long	0


a_fb_kano
	.long	ani_offset_xy
	.word	->3c,->10		; we need even # of words here !
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->1e,->23
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>20,->2d
	.long	SCFLIPPED3
	.long	0

	.long	SCFLIPPED4
	.long	SCFLIPPED5
	.long	SCKNOCKDOWN4
	.long	SCKNOCKDOWN5
	.long	0

a_fb_sonya
	.long	ani_offset_xy
	.word	->31,>0d
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->16,>14
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>0b,->03
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>50,->17
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>81,->23
	.long	SCFLIPPED4
	.long	0

	.long	SCFLIPPED5
	.long	SCKNOCKDOWN4
	.long	SCKNOCKDOWN5
	.long	0

a_fb_jax
	.long	ani_offset_xy
	.word	->4b,->12
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->30,->2a
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	->08,->45
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>35,->1f
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>45,>1d
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>40,>2d
	.long	SCKNOCKDOWN6
	.long	0

a_fb_ind
	.long	ani_offset_xy
	.word	->64,->0c
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->4f,->30
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	->1f,->56
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>2e,->31
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>50,->0f
	.long	SCKNOCKDOWN6
	.long	ani_offset_xy
	.word	>44,->1b
	.long	SCKNOCKDOWN6
	.long	0

a_fb_sz
	.long	ani_offset_xy
	.word	->49,->32
	.long	SCFLIPPED1

	.long	ani_flip
	.long	ani_offset_xy
	.word	>53,->1b
	.long	SCFLIPPED5

	.long	ani_offset_xy
	.word	>35,>0b
	.long	SCFLIPPED5

	.long	ani_offset_xy
	.word	->09,>26
	.long	SCKNOCKDOWN5

	.long	ani_offset_xy
	.word	->47,>04
	.long	SCKNOCKDOWN5

	.long	ani_offset_xy
	.word	->75,->26
	.long	SCKNOCKDOWN5
	.long	0

a_fb_swat
	.long	ani_offset_xy
	.word	->57,->08
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->3e,->31
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>1d,->47
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>58,>01
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>43,>24
	.long	SCKNOCKDOWN6
	.long	0

a_fb_lia
	.long	ani_offset_xy
	.word	->64,>00
	.long	SCSTUMBLE1
	.long	ani_offset_xy
	.word	->73,>03
	.long	SCSTUMBLE2

	.long	ani_offset_xy
	.word	->75,->1e
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->57,->3d
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->23,->46
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	>1e,->4e
	.long	SCFLIPPED1

	.long	ani_offset_xy
	.word	>a8,>12
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>8d,>00
	.long	SCKNOCKDOWN7
	.long	0



a_fb_robo
	.long	ani_offset_xy
	.word	->47,->0b
	.long	SCFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->43,->2f
	.long	SCFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->31,->48
	.long	SCFLIPPED2		; 3

	.long	ani_offset_xy
	.word	>00,->74
	.long	SCFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>3c,->72
	.long	SCFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>60,->5b
	.long	SCFLIPPED4		; 6

	.long	ani_offset_xy
	.word	>7b,->17
	.long	SCFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>57,->08
	.long	SCKNOCKDOWN7		; 8
	.long	0


a_fb_robo2
	.long	ani_offset_xy
	.word	->26,->08
	.long	SCSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->32,->11
	.long	SCFLIPPED1		; 2
	.long	ani_offset_xy
	.word	->0e,->1b
	.long	SCFLIPPED2		; 3
	.long	ani_offset_xy
	.word	>14,->12
	.long	SCFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>23,->0d
	.long	SCFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>2,>0e
	.long	SCFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->24,->11
	.long	SCKNOCKDOWN7		; 7
	.long	0


a_fb_lao
	.long	ani_offset_xy
	.word	->1d,>1a
	.long	SCSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	>00,>33
	.long	SCSTUMBLE1		; 2
	.long	ani_flip
	.long	ani_offset_xy
	.word	->22,>1d
	.long	SCFLIPPED1		; 3
	.long	ani_offset_xy
	.word	->46,->0f
	.long	SCFLIPPED2		; 4
	.long	ani_offset_xy
	.word	->2c,->3f
	.long	SCFLIPPED3		; 5
	.long	ani_offset_xy
	.word	>08,->57
	.long	SCFLIPPED4		; 6
	.long	ani_offset_xy
	.word	>4f,->59
	.long	SCFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>5a,->35
	.long	SCFLIPPED5		; 8
	.long	ani_offset_xy
	.word	>65,>0d
	.long	SCFLIPPED5		; 9
	.long	ani_offset_xy
	.word	>49,>45
	.long	SCFLIPPED5		; 10
	.long	0


a_fb_tusk
	.long	ani_offset_xy
	.word	->6e,>00
	.long	SCFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->62,->3f
	.long	SCFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->13,->73
	.long	SCFLIPPED3		; 3
	.long	ani_offset_xy
	.word	>40,->38
	.long	SCFLIPPED4		; 4
	.long	ani_offset_xy
	.word	>44,>09
	.long	SCFLIPPED5		; 5

	.long	ani_offset_xy
	.word	>0f,>33
	.long	SCFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->2c,>1a
  	.long	SCKNOCKDOWN6		; 7
	.long	ani_offset_xy
	.word	->72,>0c
	.long	SCFLIPPED1		; 8
	.long	ani_offset_xy
	.word	->5d,->4b
	.long	SCFLIPPED2		; 9
	.long	ani_offset_xy
	.word	>1c,->61
	.long	SCFLIPPED3		; 10 

	.long	ani_offset_xy
	.word	>65,>0f
	.long	SCFLIPPED5		; 11
	.long	ani_offset_xy
	.word	>64,>1f
  	.long	SCKNOCKDOWN6		; 12
	.long	0


a_fb_sg
	.long	ani_offset_xy
	.word	->3d,->30
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->10,->41
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	->0e,->4b
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>0b,->3d
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>10,->23
	.long	SCFLIPPED3
	.long	ani_flip
	.long	ani_offset_xy
	.word	->12,->14
  	.long	SCKNOCKDOWN7
	.long	0

a_fb_st
	.long	ani_offset_xy
	.word	->4c,>00
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->41,>07
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->2a,>12
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	->07,>0d
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>0e,>2e
	.long	SCFLIPPED4

	.long	ani_offset_xy
	.word	->0f,>14
	.long	SCKNOCKDOWN6
	.long	ani_offset_xy
	.word	->2c,>13
	.long	SCKNOCKDOWN6
	.long	ani_offset_xy
	.word	->3e,->13
	.long	SCKNOCKDOWN6

	.long	ani_offset_xy
	.word	->54,>18
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->61,->0b
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->3c,->3e
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>2b,->33
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>4c,>03
	.long	SCFLIPPED5
	.long	ani_offset_xy
	.word	>42,>0e
	.long	SCKNOCKDOWN6
	.long	0

a_fb_lk
	.long	ani_offset_xy
	.word	->42,>0c
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->3d,>0f
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->13,>13
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>0a,>0f
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>33,>03
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>78,->16
	.long	SCFLIPPED4
	.long	0

	.long	SCFLIPPED5
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	SCKNOCKDOWN7
	.long	0


a_fb_nj	.long	ani_offset_xy
	.word	->49,>06
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->3c,>0e
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->28,>17
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>00,>16
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>0e,>0e
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>5d,->17
	.long	SCFLIPPED4
	.long	0

	.long	SCFLIPPED5
	.long	SCKNOCKDOWN7
	.long	SCKNOCKDOWN8
	.long	0


a_fb_smoke
a_afb_robo2
	.long	ani_offset_xy
	.word	->19,->3b
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>16,->52
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>37,->40
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>4f,->26
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>66,->17
	.long	SCKNOCKDOWN6
	.long	ani_offset_xy
	.word	>78,>0f
	.long	SCKNOCKDOWN6
	.long	0


a_fb_mileena
	.long	ani_offset_xy
	.word	->3a,->01
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->29,>07
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->1e,>01
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>0e,->1a
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>63,->34
	.long	SCFLIPPED4
	.long	0

	.long	SCFLIPPED5
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	SCKNOCKDOWN7
	.long	0

a_fb_kitana
	.long	ani_offset_xy
	.word	->20,->23
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->08,->2e
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>23,->1d
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>32,>2c
	.long	SCFLIPPED4
	.long	0

	.long	SCFLIPPED4
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	0



a_fb_jade
	.long	ani_offset_xy
	.word	->65,->01
	.long	SCKNOCKDOWN1
	.long	ani_offset_xy
	.word	->67,->21
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->43,->52
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	->11,->4e
	.long	SCFLIPPED2
	.long	ani_offset_xy
	.word	>4a,->55
	.long	SCFLIPPED3
	.long	ani_offset_xy
	.word	>74,->1c
	.long	SCFLIPPED4
	.long	ani_offset_xy
	.word	>7b,>11
	.long	SCFLIPPED5
	.long	0

	.long	SCFLIPPED4
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	0



a_afb_kano
	.long	ani_offset_xy
	.word	->29,->03
	.long	SCKNOCKDOWN1

	.long	ani_offset_xy
	.word	->44,>1c
	.long	SCKNOCKDOWN3

	.long	ani_offset_xy
 	.word	->5c,>3f
	.long	SCKNOCKDOWN4

	.long	0
*
* fall down solo
*
	.long	SCKNOCKDOWN4
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	SCKNOCKDOWN7
	.long	0


a_legged
	.long	ani_offset_xy
	.word	->55,>00
	.long	SCKNOCKDOWN1

	.long	ani_offset_xy
	.word	->44,->29
	.long	SCFLIPPED1

	.long	ani_offset_xy
	.word	->1f,->3c
	.long	SCFLIPPED3

	.long	ani_offset_xy
	.word	>2b,->29
	.long	SCFLIPPED4

	.long	ani_offset_xy
	.word	>56,>12
	.long	SCFLIPPED5
	.long	0


a_zoomed
	.long	ani_offset_xy
	.word	>48,>01
	.long	SCKNOCKDOWN3	; 1

	.long	ani_offset_xy
	.word	>4e,>2b
	.long	SCKNOCKDOWN4	; 2

	.long	ani_offset_xy
	.word	>24,>42
	.long	SCKNOCKDOWN5	; 3

	.long	ani_offset_xy
	.word	->33,>40
	.long	SCKNOCKDOWN5	; 4

	.long	ani_offset_xy
	.word	->84,->04
	.long	SCFLIPPED1	; 5

	.long	ani_offset_xy
	.word	->2c,->52
	.long	SCFLIPPED3	; 6
	.long	0

	.long	SCFLIPPED3
	.long	SCFLIPPED4
	.long	SCFLIPPED5
	.long	SCKNOCKDOWN5
	.long	SCKNOCKDOWN6
	.long	SCKNOCKDOWN7
	.long	0


a_shook
	.long	ani_offset_xy
	.word	->4f,->08
	.long	SCSTUMBLE2

	.long	ani_offset_xy
	.word	->38,->1f
	.long	SCSTUMBLE2

	.long	ani_offset_xy
	.word	->1b,->1c
	.long	SCSTUMBLE2
	.long	0

; loop
	.long	ani_offset_xy
	.word	->1d,->1a
	.long	SCSTUMBLE2	; 6

	.long	ani_offset_xy
	.word	->33,->2b
	.long	SCSTUMBLE2	; 7

	.long	ani_offset_xy
	.word	->44,->2d	
	.long	SCSTUMBLE2	; 8

	.long	ani_offset_xy
	.word	->33,->2b
	.long	SCSTUMBLE1	; 7
	.long	0


SCFLIPPED1
	.long	SCFLIPPED1A,0
SCFLIPPED2
	.long	SCFLIPPED2A,0
SCFLIPPED3
	.long	SCFLIPPED3A,0
SCFLIPPED4
	.long	SCFLIPPED4A,0
SCFLIPPED5
	.long	SCFLIPPED5A,SCFLIPPED5B,0

;**************************************

a_air_throw
a_throw
	.long	SCFLIP1
	.long	SCFLIP2
	.long	0

	.long	ani_adjustx
	.word	-9
	.long	SCFLIP3
	.long	ani_adjustx
	.word	-9
	.long	SCFLIP4
	.long	ani_adjustx
	.word	-9
	.long	SCFLIP5
	.long	ani_adjustx
	.word	-9
	.long	SCFLIP6
	.long	ani_adjustx
	.word	-9
	.long	SCFLIP7
	.long	SCFLIP9		; animate 2-gether !!
	.long	0

	.long	SCFLIP9
	.long	SCFLIP7
	.long	SCFLIP6
	.long	SCFLIP5
	.long	SCFLIP4
	.long	SCFLIP3
	.long	SCFLIP2
	.long	0

SCFLIP1	.long	SCFLIP1A,SCFLIP1B,0
SCFLIP2	.long	SCFLIP2A,SCFLIP2B,0
SCFLIP3	.long	SCFLIP3A,SCFLIP3B,0
SCFLIP4	.long	SCFLIP4A,SCFLIP4B,0
SCFLIP5	.long	SCFLIP5A,0
SCFLIP6	.long	SCFLIP6A,0
SCFLIP7	.long	SCFLIP7A,0
SCFLIP9	.long	SCFLIP9A,SCFLIP9B,0

;**************************************

a_dizzy
	.long	SCSTUNNED1
	.long	SCSTUNNED2
	.long	SCSTUNNED3
	.long	SCSTUNNED4
	.long	SCSTUNNED5
	.long	SCSTUNNED6
	.long	SCSTUNNED7
	.long	SCSTUNNED8
	.long	ani_jump,a_dizzy

SCSTUNNED1
	.long	SCSTUNNED1A,SCSTUNNED1B,0
SCSTUNNED2
	.long	SCSTUNNED2A,SCSTUNNED2B,0
SCSTUNNED3
	.long	SCSTUNNED3A,SCSTUNNED3B,0
SCSTUNNED4
	.long	SCSTUNNED4A,SCSTUNNED4B,0
SCSTUNNED5
	.long	SCSTUNNED5A,SCSTUNNED5B,0
SCSTUNNED6
	.long	SCSTUNNED6A,SCSTUNNED6B,0
SCSTUNNED7
	.long	SCSTUNNED7A,SCSTUNNED7B,0
SCSTUNNED8
	.long	SCSTUNNED8A,SCSTUNNED8B,0


a_thudd	
	.long	SCFALLTHUD1
	.long	SCFALLTHUD4
	.long	SCFALLTHUD5
	.long	SCFALLTHUD6
	.long	SCFALLTHUD7
	.long	0

SCFALLTHUD1
	.long	SCFALLTHUD1A,0
SCFALLTHUD4
	.long	SCFALLTHUD4A,0
SCFALLTHUD5
	.long	SCFALLTHUD5A,0
SCFALLTHUD6
	.long	SCFALLTHUD6A,0
SCFALLTHUD7
	.long	SCFALLTHUD7A,0

a_throw_spear
	.long	SCSPEAR1
	.long	SCSPEAR2
	.long	SCSPEAR3
	.long	SCSPEAR4
	.long	0

	.long	SCSPEAR6
	.long	SCSPEAR7
	.long	SCSPEAR8
	.long	SCSPEAR9
	.long	0
*
* part 3 = spear obj
*
	.long	SPEAR1
	.long	SPEAR2
	.long	SPEAR3
	.long	0
*
* part 4 = multipart spear
*
	.long	M_SPEAR1


M_SPEAR1	.long	SPEAR1,0


SCSPEAR1	.long	SCSPEAR1A,SCSPEAR1B,SCSPEAR1C,0
SCSPEAR2	.long	SCSPEAR2A,SCSPEAR2B,0
SCSPEAR3	.long	SCSPEAR3A,SCSPEAR3B,0
SCSPEAR4	.long	SCSPEAR4A,SCSPEAR4B,0
SCSPEAR6	.long	SCSPEAR6A,SCSPEAR6B,0
SCSPEAR7	.long	SCSPEAR7A,SCSPEAR7B,0
SCSPEAR8	.long	SCSPEAR8A,SCSPEAR8B,0
SCSPEAR9	.long	SCSPEAR9A,SCSPEAR9B,0

;**********************************************************************

a_release_orb
	.long	RPFORCEBALL1
	.long	ani_sladd,ORB1
	.long	RPFORCEBALL2
	.long	ani_slani,ORB2
	.long	RPFORCEBALL3
	.long	ani_slani,ORB3
	.long	RPFORCEBALL4
	.long	ani_slani,ORB4
	.long	RPFORCEBALL5
	.long	0
*
* part 2 = un ani
*
	.long	RPFORCEBALL4
	.long	RPFORCEBALL3
	.long	RPFORCEBALL2
	.long	RPFORCEBALL1
	.long	0
*
* part 3 = orb ani
*
j_orb	.long	ORB7
	.long	ORB8
	.long	ORB9
	.long	ORB8
	.long	ani_jump,j_orb
	.long	0
*
* part 4 = orb explode
*
	.long	ani_swpal
	.long	ORBBOOM1
	.long	ORBBOOM2
	.long	ORBBOOM3
	.long	ORBBOOM4
	.long	ORBBOOM5
	.long	ORBBOOM6
	.long	ORBBOOM7
	.long	0

RPFORCEBALL1
	.long	RPFORCEBALL1A,RPFORCEBALL1B,0
RPFORCEBALL2
	.long	RPFORCEBALL2A,0
RPFORCEBALL3
	.long	RPFORCEBALL3A,0
RPFORCEBALL4
	.long	RPFORCEBALL4A,0
RPFORCEBALL5
	.long	RPFORCEBALL5A,0

ORB1	.long	GLOBALL1,0
ORB2	.long	GLOBALL2,0
ORB3	.long	GLOBALL3,0
ORB4	.long	GLOBALL4,0
ORB5	.long	GLOBALL5,0
ORB6	.long	GLOBALL6,0
ORB7	.long	GLOBALL7,0
ORB8	.long	GLOBALL8,0
ORB9	.long	GLOBALL9,0
ORBBOOM1	.long	REPLODE1,0
ORBBOOM2	.long	REPLODE2,0
ORBBOOM3	.long	REPLODE3,0
ORBBOOM4	.long	REPLODE4,0
ORBBOOM5	.long	REPLODE5,0
ORBBOOM6	.long	REPLODE6,0
ORBBOOM7	.long	REPLODE7,0

;********************************

a_oldsz_zap
	.long	SZICEPRO1
	.long	SZICEPRO2
	.long	SZICEPRO3
	.long	ani_sladd,ICEBS1
	.long	0
	.long	ani_jump,j_sz_ice
	.long	0

	.long	SZICEPRO2
	.long	SZICEPRO1
	.long	0

SZICEPRO1
	.long	SZICEPRO1A,SZICEPRO1B,0
SZICEPRO2
	.long	SZICEPRO2A,SZICEPRO2B,0
SZICEPRO3
	.long	SZICEPRO3A,0

;********************************************************************

a_floor_ice
	.long	SZFLOORICE1
	.long	SZFLOORICE2
	.long	SZFLOORICE3
	.long	ani_sladd,FLICE1
	.long	ani_slani_sleep,FLICE1
	.long	ani_slani_sleep,FLICE2
	.long	ani_slani_sleep,FLICE3
	.long	ani_slani_sleep,FLICE4
	.long	ani_slani_sleep,FLICE5
	.long	0
	.long	SZFLOORICE2
	.long	SZFLOORICE1
	.long	0
*
* part 3 - floor ice proc part
*
	.long	FLICE6
	.long	FLICE7
	.long	0

	.long	FLICE8
	.long	FLICE9
	.long	FLICE10
	.long	FLICE11
	.long	FLICE12
	.long	FLICE13
	.long	0

FLICE1	.long	CSFLOORICE1,0
FLICE2	.long	CSFLOORICE2,0
FLICE3	.long	CSFLOORICE3,0
FLICE4	.long	CSFLOORICE4,0
FLICE5	.long	CSFLOORICE5,0
FLICE6	.long	CSFLOORICE6,0
FLICE7	.long	CSFLOORICE7,0
FLICE8	.long	CSFLOORICE8,0
FLICE9	.long	CSFLOORICE9,0
FLICE10	.long	CSFLOORICE10,0
FLICE11	.long	CSFLOORICE11,0
FLICE12	.long	CSFLOORICE12,0
FLICE13	.long	CSFLOORICE13,0

SZFLOORICE1
	.long	SZFLOORICE1A,SZFLOORICE1B,0
SZFLOORICE2
	.long	SZFLOORICE2A,SZFLOORICE2B,0
SZFLOORICE3
	.long	SZFLOORICE3A,SZFLOORICE3B,0

;********************************************************************

a_spit	.long	RPSPIT1
	.long	RPSPIT2
	.long	RPSPIT3
	.long	ani_sladd,LOOGY2
	.long	RPSPIT4
	.long	0
*
* part 2 = un-spit
*
	.long	RPSPIT2
	.long	RPSPIT1
	.long	0
*
* part 3 = loogy fly animation
*
;	.long	LOOGY1
	.long	LOOGY2
	.long	LOOGY3
	.long	LOOGY4
j_loogy	.long	LOOGY5
	.long	LOOGY6
	.long	ani_jump,j_loogy
	.long	0
*
* part 4 = loogy hit animation
*
	.long	LOOGY7
	.long	LOOGY8
	.long	LOOGY9
	.long	LOOGY10
	.long	LOOGY11
	.long	LOOGY12
	.long	LOOGY13
	.long	LOOGY14
	.long	0

a_breath_fire
	.long	RPSPIT1
	.long	RPSPIT1
	.long	RPBREATH3
	.long	0

	.long	SKULLSPTFIRE1
	.long	SKULLSPTFIRE2
	.long	SKULLSPTFIRE3
	.long	0

RPBREATH3
	.long	RPSPIT3A,RPSPIT3B,0

RPSPIT1	.long	RPSPIT1A,RPSPIT1B,0
RPSPIT2	.long	RPSPIT2A,RPSPIT2B,0
RPSPIT3	.long	RPSPIT3A,RPSPIT3B,RPSPIT3FACE1,0
RPSPIT4	.long	RPSPIT3A,RPSPIT3B,RPSPIT3FACE2,0

LOOGY2	.long	SPIT2,0
LOOGY3	.long	SPIT3,0
LOOGY4	.long	SPIT4,0
LOOGY5	.long	SPIT5,0
LOOGY6	.long	SPIT6,0
LOOGY7	.long	SPIT7,0
LOOGY8	.long	SPIT8,0
LOOGY9	.long	SPIT9,0
LOOGY10	.long	SPIT10,0
LOOGY11	.long	SPIT11,0
LOOGY12	.long	SPIT12,0
LOOGY13	.long	SPIT13,0
LOOGY14	.long	SPIT14,0


a_tony_flame
	.long	SCORPFIRE1
	.long	SCORPFIRE2
	.long	SCORPFIRE3
	.long	0

	.long	SCORPFIRE4
	.long	SCORPFIRE5
	.long	SCORPFIRE6
	.long	0

	.long	SCORPFIRE7
	.long	SCORPFIRE8
	.long	SCORPFIRE9
	.long	SCORPFIRE10
	.long	SCORPFIRE11
	.long	SCORPFIRE12
	.long	SCORPFIRE13
	.long	0

;********************************

a_reptile_inv
	.long	RPPOOF1
	.long	RPPOOF2
	.long	RPPOOF3
	.long	0

RPPOOF1	.long	RPPOOF1A,RPPOOF1B,0
RPPOOF2	.long	RPPOOF2A,RPPOOF2B,0
RPPOOF3	.long	RPPOOF3A,RPPOOF3B,0

a_spit_glob
	.long	SPITROT1
	.long	SPITROT2
	.long	SPITROT3
	.long	SPITROT4
	.long	ani_jump,a_spit_glob
	.long	0

	.long	SPITROT5
	.long	SPITROT6
	.long	SPITROT7
	.long	SPITROT8
	.long	SPITROT9
	.long	SPITROT10
	.long	SPITROT11
	.long	SPITROT12
	.long	SPITROT13
	.long	0

;******************************

a_run	.long	SCRUN1
	.long	SCRUN2
	.long	SCRUN3
	.long	SCRUN4
	.long	ani_calla,rsnd_footstep
	.long	SCRUN5
	.long	SCRUN6
	.long	SCRUN7
	.long	SCRUN8
	.long	SCRUN9
	.long	ani_calla,rsnd_footstep
	.long	SCRUN10
	.long	SCRUN11
	.long	SCRUN12
	.long	ani_jump,a_run
	.long	0			; we need this zero !!

SCRUN1	.long	SCRUN1A,SCRUN1B,0
SCRUN2	.long	SCRUN2A,SCRUN2B,0
SCRUN3	.long	SCRUN3A,SCRUN3B,0
SCRUN4	.long	SCRUN4A,SCRUN4B,0
SCRUN5	.long	SCRUN5A,SCRUN5B,0
SCRUN6	.long	SCRUN6A,0
SCRUN7	.long	SCRUN7A,SCRUN7B,0
SCRUN8	.long	SCRUN8A,SCRUN8B,0
SCRUN9	.long	SCRUN9A,SCRUN9B,0
SCRUN10	.long	SCRUN10A,SCRUN10B,0
SCRUN11	.long	SCRUN11A,SCRUN11B,0
SCRUN12	.long	SCRUN12A,0

;******************************

a_victory
	.long	ani_ochar_jump
	.long	ft_reptile
	.long	a_reptile_victory	; yes = different victory animation

	.long	ani_ochar_jump
	.long	ft_oldsz
	.long	a_oldsz_victory		; yes = different victory animation

	.long	ani_ochar_jump
	.long	ft_oldsmoke
	.long	a_oldsz_victory		; old smoke ---> copy old subzero

	.long	ani_ochar_jump
	.long	ft_ermac
	.long	a_oldsz_victory		; ermac ---> copy old subzero

	.long	SCVICTORY2
	.long	SCVICTORY3
	.long	SCVICTORY4
	.long	SCVICTORY5
	.long	SCVICTORY6
	.long	SCVICTORY7
	.long	0

a_oldsz_victory
	.long	SZVICTORY1
	.long	SZVICTORY2
	.long	SZVICTORY3
	.long	0

a_reptile_victory
	.long	RPVICTORY1
	.long	RPVICTORY2
	.long	RPVICTORY3
	.long	RPVICTORY4
	.long	RPVICTORY5
	.long	0

SCVICTORY2
	.long	SCVICTORY2A,SCVICTORY2B,0
SCVICTORY3
	.long	SCVICTORY3A,0
SCVICTORY4
	.long	SCVICTORY4A,0
SCVICTORY5
	.long	SCVICTORY5A,0
SCVICTORY6
	.long	SCVICTORY6A,0
SCVICTORY7
	.long	SCVICTORY7A,SCVICTORY7B,0

RPVICTORY1
	.long	RPVICTORY1A,RPVICTORY1B,0
RPVICTORY2
	.long	RPVICTORY2A,RPVICTORY2B,RPVICTORY2C,0
RPVICTORY3
	.long	RPVICTORY3A,RPVICTORY3B,0
RPVICTORY4
	.long	RPVICTORY4A,RPVICTORY4B,0
RPVICTORY5
	.long	RPVICTORY5A,RPVICTORY5B,0


SZVICTORY1
	.long	SZVICTORY1A,SZVICTORY1B,0
SZVICTORY2
	.long	SZVICTORY2A,SZVICTORY2B,0
SZVICTORY3
	.long	SZVICTORY3A,0

;********************************************************************

a_scorpion_summon
	.long	SCSUMMON5
	.long	SCSUMMON6
	.long	SCSUMMON7
	.long	SCSUMMON8
	.long	SCSUMMON9
	.long	0

SCSUMMON5
	.long	SCSUMMON5A,SCSUMMON5B,0
SCSUMMON6
	.long	SCSUMMON6A,SCSUMMON6B,0
SCSUMMON7
	.long	SCSUMMON7A,SCSUMMON7B,0
SCSUMMON8
	.long	SCSUMMON8A,SCSUMMON8B,0
SCSUMMON9
	.long	SCSUMMON9A,SCSUMMON9B,0

;********************************************************************

a_scared	.long	SCSCARED2
	.long	0

SCSCARED2
	.long	SCSCARED2A,0

;******************************************************************

a_jade_shook
	.long	ani_offset_xy
	.word	->83,->18
	.long	SCFLIPPED1
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	SCSTUMBLE1
	.long	ani_offset_xy
	.word	->6d,>24
	.long	SCKNOCKDOWN2
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	SCSTUMBLE1
	.long	ani_jump,a_jade_shook

;***************************************************************

a_mask_off
	.long	SCMASKOFF2
	.long	SCMASKOFF3
	.long	SCMASKOFF4
	.long	SCMASKOFF5
	.long	SCMASKOFF6
	.long	SCMASKOFF7
	.long	0

SCMASKOFF2
	.long	SCMASKOFF2A,0
SCMASKOFF3
	.long	SCMASKOFF3A,0
SCMASKOFF4
	.long	SCMASKOFF4A,0
SCMASKOFF5
	.long	SCMASKOFF5A,0
SCMASKOFF6
	.long	SCMASKOFF6A,0
SCMASKOFF7
	.long	SCMASKOFF7A,SCMASKOFF7B,0

;***********************
;********************************************************************
a_back_break
	.long	SCBACKBREAK1
	.long	0
	
SCBACKBREAK1
	.long	SCBACKBREAK3A,SCBACKBREAK3B,0

;********************************************************************
a_baby
	.long	BABYSCORP
	.long	0
	
;********************************************************************
a_big_head
	.long	BHSCO1
	.long	BHSCO2
	.long	BHSCO3
	.long	BHSCO4
	.long	BHSCO5
	.long	0
	
;********************************************************************
a_half_cutup
	.long	HALF_NJ
	.long	0
	
HALF_NJ
	.long	SCCUT1D,SCCUT1C,0
;********************************************************************
a_cutup
	.long	SCCUT1
	.long	0
	
SCCUT1
	.long	SCCUT1A,SCCUT1B,SCCUT1C,SCCUT1D,0
;********************************************************************
a_float
	.long	NJFLOAT	
	.long	0
	
NJFLOAT	
	.long	BHSCO1,BHSCO2,BHSCO3,BHSCO4,BHSCO5,0
;********************************************************************
a_pounded
	.long	SCFALLTHUD1
	.long	0
;********************************************************************
a_reach
	.long	ani_adjustxy
	.word	0,0
	.long	NJMOUTH4
	.long	NJMOUTH5
	.long	NJMOUTH6
	.long	NJMOUTH8
	.long	0

NJMOUTH4	.long	SCMOUTH4,SCSKELEG,0
NJMOUTH5	.long	SCMOUTH5,SCSKELEG,0
NJMOUTH6	.long	SCMOUTH6,0
NJMOUTH8	.long	SCMOUTH8,0
;********************************************************************
a_skin_rip
	.long	SCRIP1
	.long	0
SCRIP1	.long	SCRIP1A,SCRIP1B,0
;********************************************************************
a_stretch
	.long	GROSCORP2
	.long	GROSCORP4
	.long	GROSCORP5
	.long	0
GROSCORP2
	.long	GROSCORP2A,GROSCORP2B,0
GROSCORP4
	.long	GROSCORP4A,GROSCORP4B,0
GROSCORP5
	.long	GROSCORP5A,GROSCORP5B,0

;********************************************************************
a_suk
	.long	SUKSCO1
	.long	SUKSCO3
	.long	SUKSCO4
	.long	SUKSCO5
	.long	SUKSCO6
	.long	0

SUKSCO1
	.long	SUKSCO1A,SUKSCO1B,0
SUKSCO3
	.long	SUKSCO3A,SUKSCO3B,0
SUKSCO4
	.long	SUKSCO4A,SUKSCO4B,0
SUKSCO5
	.long	SUKSCO5A,0
SUKSCO6
	.long	SUKSCO6A,0

;********************************************************************
a_shocked
	.long	SCBZZ1
	.long	SCBZZ2
	.long	SCBZZ3
	.long	SCBZZ4
	.long	0
SCBZZ1	.long	SCBUZZ1,0
SCBZZ2	.long	SCBUZZ2,0
SCBZZ3	.long	SCBUZZ3,0
SCBZZ4	.long	SCBUZZ4,0
;********************************************************************
a_shredded
	.long	ani_adjustxy
	.word	6,6
	.long	SCSTUMBLE1

	.long	ani_adjustxy
	.word	-6,-6
	.long	SCSTUMBLE2

	.long	ani_adjustxy
	.word	6,6
	.long	SCSTUMBLE3

	.long	ani_adjustxy
	.word	-6,-6
	.long	SCSTUMBLE2

	.long	ani_jump,a_shredded




a_vomit
	.long	ACIDVOMIT1
	.long	ACIDVOMIT2
	.long	ACIDVOMIT3
	.long	ACIDVOMIT4
	.long	ACIDVOMIT5
	.long	ACIDVOMIT6
	.long	ACIDVOMIT7
	.long	ACIDVOMIT8
	.long	ACIDVOMIT9
	.long	ACIDVOMIT10
	.long	ACIDVOMIT11
	.long	ACIDVOMIT12
	.long	0

	.long	ACIDVOMIT13
	.long	ACIDVOMIT14
	.long	ACIDVOMIT15
	.long	ACIDVOMIT16
	.long	ACIDVOMIT17
	.long	ACIDVOMIT18
	.long	ACIDVOMIT19
	.long	ACIDVOMIT20
	.long	ACIDVOMIT21
	.long	ACIDVOMIT22
	.long	ACIDVOMIT23
	.long	ACIDVOMIT24
	.long	ACIDVOMIT25
	.long	0

ACIDVOMIT1
	.long	ACIDVOMIT1A,0
ACIDVOMIT2
	.long	ACIDVOMIT2A,0
ACIDVOMIT3
	.long	ACIDVOMIT3A,0
ACIDVOMIT4
	.long	ACIDVOMIT4A,0
ACIDVOMIT5
	.long	ACIDVOMIT5A,0
ACIDVOMIT6
	.long	ACIDVOMIT6A,0
ACIDVOMIT7
	.long	ACIDVOMIT7A,ACIDVOMIT7B,0
ACIDVOMIT8
	.long	ACIDVOMIT8A,ACIDVOMIT8B,0
ACIDVOMIT9
	.long	ACIDVOMIT9A,ACIDVOMIT9B,0
ACIDVOMIT10
	.long	ACIDVOMIT10A,ACIDVOMIT10B,0
ACIDVOMIT11
	.long	ACIDVOMIT11A,ACIDVOMIT11B,0
ACIDVOMIT12
	.long	ACIDVOMIT12A,0
ACIDVOMIT13
	.long	ACIDVOMIT13A,0
ACIDVOMIT14
	.long	ACIDVOMIT14A,0
ACIDVOMIT15
	.long	ACIDVOMIT15A,0
ACIDVOMIT16
	.long	ACIDVOMIT16A,0
ACIDVOMIT17
	.long	ACIDVOMIT17A,0
ACIDVOMIT18
	.long	ACIDVOMIT18A,0
ACIDVOMIT19
	.long	ACIDVOMIT19A,0
ACIDVOMIT20
	.long	ACIDVOMIT20A,ACIDVOMIT20B,0
ACIDVOMIT21
	.long	ACIDVOMIT21A,ACIDVOMIT21B,0
ACIDVOMIT22
	.long	ACIDVOMIT22A,ACIDVOMIT22B,0
ACIDVOMIT23
	.long	ACIDVOMIT23A,ACIDVOMIT23B,0
ACIDVOMIT24
	.long	ACIDVOMIT24A,0
ACIDVOMIT25
	.long	ACIDVOMIT25A,0

a_hi_tongue
	.long	RPHITUNG1
	.long	RPHITUNG2
	.long	RPHITUNG3
	.long	RPHITUNG4
	.long	RPHITUNG5
	.long	RPHITUNG6
	.long	RPHITUNG7
	.long	RPHITUNG8
	.long	RPHITUNG9
	.long	RPHITUNG10
	.long	RPHITUNG11
	.long	0
	.long	RPHITUNG10
	.long	RPHITUNG9
	.long	RPHITUNG8
	.long	RPHITUNG7
	.long	RPHITUNG6
	.long	RPHITUNG5
	.long	RPHITUNG4
	.long	RPHITUNG3
	.long	RPHITUNG2
	.long	RPHITUNG1
	.long	0


a_med_tongue
	.long	RPMEDTUNG1
	.long	RPMEDTUNG2
	.long	RPMEDTUNG3
	.long	RPMEDTUNG4
	.long	RPMEDTUNG5
	.long	RPMEDTUNG6
	.long	RPMEDTUNG7
	.long	RPMEDTUNG8
	.long	RPMEDTUNG9
	.long	RPMEDTUNG10
	.long	RPMEDTUNG11
	.long	0
	.long	RPMEDTUNG10
	.long	RPMEDTUNG9
	.long	RPMEDTUNG8
	.long	RPMEDTUNG7
	.long	RPMEDTUNG6
	.long	RPMEDTUNG5
	.long	RPMEDTUNG4
	.long	RPMEDTUNG3
	.long	RPMEDTUNG2
	.long	RPMEDTUNG1
	.long	0



a_lo_tongue
	.long	RPLOTUNG1
	.long	RPLOTUNG2
	.long	RPLOTUNG3
	.long	RPLOTUNG4
	.long	RPLOTUNG5
	.long	RPLOTUNG6
	.long	RPLOTUNG7
	.long	RPLOTUNG8
	.long	RPLOTUNG9
	.long	RPLOTUNG10
	.long	RPLOTUNG11
	.long	0
	.long	RPLOTUNG10
	.long	RPLOTUNG9
	.long	RPLOTUNG8
	.long	RPLOTUNG7
	.long	RPLOTUNG6
	.long	RPLOTUNG5
	.long	RPLOTUNG4
	.long	RPLOTUNG3
	.long	RPLOTUNG2
	.long	RPLOTUNG1
	.long	0


a_reptile_chomp_head
	.long	RPCHOMP1
	.long	RPCHOMP2
	.long	RPCHOMP3
	.long	RPCHOMP4		; open mouth
	.long	0

	.long	RPCHOMP5
	.long	RPCHOMP6
	.long	RPCHOMP7
	.long	RPCHOMP8
	.long	RPCHOMP9
	.long	RPCHOMP10
	.long	RPCHOMP11
	.long	RPCHOMP12
	.long	RPCHOMP13
	.long	RPCHOMP14
	.long	RPCHOMP1
	.long	0


a_schand
	.long HAND1
	.long HAND2
	.long HAND3
	.long HAND4
	.long HAND5
	.long HAND6
	.long HAND7
	.long HAND8
	.long	0
	.long HAND9
	.long HAND10
	.long HAND11
	.long	0
	.long HAND12
	.long HAND13
	.long HAND14
	.long HAND15
	.long HAND16
	.long HAND17
	.long HAND18
	.long HAND19
	.long 0

a_icespike
	.long SZFLOORICE1
	.long SZFLOORICE2
	.long SZFLOORICE3
	.long ani_sladd
	.long ICSPIKE1
	.long ani_slani_sleep
	.long ICSPIKE2
	.long ani_slani_sleep
	.long ICSPIKE3
	.long ani_slani_sleep
	.long ICSPIKE4
	.long ani_slani_sleep
	.long ICSPIKE5
	.long ani_slani_sleep
	.long ICSPIKE6
	.long ani_slani_sleep
	.long ICSPIKE7
	.long ani_slani_sleep
	.long ICSPIKE8
	.long ani_slani_sleep
	.long ICSPIKE9
	.long ani_slani_sleep
	.long ICSPIKE10
	.long 0
	.long SZFLOORICE2
	.long SZFLOORICE1
	.long 0


a_ermac_zap
	.long SKPRO1
	.long SKPRO2
	.long SKPRO3
	.long SKPRO4
	.long SKPRO5
	.long SKPRO6
	.long SKPRO7
	.long SKPRO8
	.long SKPRO9
	.long SKPRO10
	.long SKPRO11
	.long ani_jump
	.long a_sk_projectile

	.end


