**************************************************************************
*											     *
*  mk3 - Lia											*
*											     *
**************************************************************************
	.FILE	'mklia.asm'
	.WIDTH	132
	.OPTION	B,D,L,T
	.MNOLIST

	.include mainequ.asm
	.include imgtbl.glo
	.include mklia.tbl
	.include mklia2.tbl
	.include mklia3.tbl
	.include mklia4.tbl
	.include mkliatmp.tbl
	.text

lia_anitab1
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
	.long	a_fb_st		; 32 - flipped by shang tsung
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
	.long	0		; 45
	.long	a_run		; 46 - run
	.long	a_thudd		; 47	-
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


lia_anitab2
	.long	a_lia_scream	; 0 - scream
	.long	a_shock_wave	; 1 - shock wave images
	.long	a_fly_up	; 2 - fly straight up 0
	.long	a_fly_forward  	; 3 - fly forward	  1
	.long	a_fly_backward	; 4 - fly backwards	  2
	.long	a_unforward	; 5 - transition to normal float 3
	.long	a_unbackoff	; 6 -
	.long	a_angle_zap		; 7 - fireball
	.long	a_top	       		; 8
	.long	0			; 9
	.long	a_hair_wrap		; a


a_dummy		
a_stance
	.long	LIASTANCE1
	.long	LIASTANCE2
	.long	LIASTANCE3
	.long	LIASTANCE4
	.long	LIASTANCE5
	.long	LIASTANCE6
	.long	LIASTANCE7
	.long	LIASTANCE8
	.long	LIASTANCE9
	.long	ani_jump,a_stance

LIASTANCE1
	.long	LIASTANCE1A,LIASTANCE1B,0
LIASTANCE2
	.long	LIASTANCE2A,LIASTANCE2B,0
LIASTANCE3
	.long	LIASTANCE3A,LIASTANCE3B,0
LIASTANCE4
	.long	LIASTANCE4A,LIASTANCE4B,0
LIASTANCE5
	.long	LIASTANCE5A,LIASTANCE5B,0
LIASTANCE6
	.long	LIASTANCE6A,LIASTANCE6B,0
LIASTANCE7
	.long	LIASTANCE7A,LIASTANCE7B,0
LIASTANCE8
	.long	LIASTANCE8A,LIASTANCE8B,0
LIASTANCE9
	.long	LIASTANCE9A,LIASTANCE9B,0

;***************************************************************************

a_turn
	.long	LITURN1
	.long	LITURN2
	.long	ani_flip
	.long	LITURN1
	.long	0

LITURN1	.long	LITURN1A,LITURN1B,0
LITURN2	.long	LITURN2A,LITURN2B,0

;***************************************************************************

a_walkf
	.long	LIWALK1
	.long	LIWALK2
	.long	LIWALK3
	.long	LIWALK4
	.long	LIWALK5
	.long	LIWALK6
	.long	LIWALK7
	.long	LIWALK8
	.long	LIWALK9
	.long	ani_jump,a_walkf

a_walkb
	.long	LIWALK9
	.long	LIWALK8
	.long	LIWALK7
	.long	LIWALK6
	.long	LIWALK5
	.long	LIWALK4
	.long	LIWALK3
	.long	LIWALK2
	.long	LIWALK1
	.long	ani_jump,a_walkb

LIWALK1	.long	LIWALKLEG1A,LIWALKLEG1B,LIWALKTORSO1,0
LIWALK2	.long	LIWALKLEG2A,LIWALKLEG2B,LIWALKTORSO2,0
LIWALK3	.long	LIWALKLEG3A,LIWALKTORSO3,0
LIWALK4	.long	LIWALKLEG4A,LIWALKLEG4B,LIWALKTORSO4,0
LIWALK5	.long	LIWALKLEG5A,LIWALKLEG5B,LIWALKTORSO5,0
LIWALK6	.long	LIWALKLEG6A,LIWALKLEG6B,LIWALKTORSO6,0
LIWALK7	.long	LIWALKLEG7A,LIWALKTORSO7,0
LIWALK8	.long	LIWALKLEG8A,LIWALKLEG8B,LIWALKTORSO8,0
LIWALK9	.long	LIWALKLEG9A,LIWALKLEG9B,LIWALKTORSO9,0

;***************************************************************************

a_duck
	.long	LIDUCK1
	.long	LIDUCK2
	.long	LIDUCK3
	.long	0

LIDUCK1	.long	LIDUCK1A,LIDUCK1B,0
LIDUCK2	.long	LIDUCK2A,LIDUCK2B,0
LIDUCK3	.long	LIDUCK3A,LIDUCK3B,0

;***************************************************************************

a_duck_turn
	.long	LIDUCKTURN1
	.long	LIDUCKTURN2
	.long	ani_flip
	.long	LIDUCKTURN1
	.long	LIDUCK3
	.long	0

LIDUCKTURN1
	.long	LIDUCKTURN1A,LIDUCKTURN1B,0
LIDUCKTURN2
	.long	LIDUCKTURN2A,LIDUCKTURN2B,0

;***************************************************************************

a_duck_block
	.long	LIDUCKBLOCK1
	.long	LIDUCKBLOCK2
	.long	LIDUCKBLOCK3
	.long	0

LIDUCKBLOCK1
	.long	LIDUCKBLOCK1A,LIDUCKBLOCK1B,0
LIDUCKBLOCK2
	.long	LIDUCKBLOCK2A,LIDUCKBLOCK2B,0
LIDUCKBLOCK3
	.long	LIDUCKBLOCK3A,LIDUCKBLOCK3B,0

;***************************************************************************

a_duck_punch
	.long	LIDUCKPUNCH1
	.long	LIDUCKPUNCH2
	.long	LIDUCKPUNCH3
	.long	0
	.long	LIDUCKPUNCH2
	.long	LIDUCKPUNCH1
	.long	LIDUCK3
	.long	0

LIDUCKPUNCH1
	.long	LIDUCKPUNCH1A,LIDUCKPUNCH1B,0
LIDUCKPUNCH2
	.long	LIDUCKPUNCH2A,LIDUCKPUNCH2B,0
LIDUCKPUNCH3
	.long	LIDUCKPUNCH3A,LIDUCKPUNCH3B,0

;***************************************************************************

a_duck_kick_lo
	.long	LIDUCKHIKICK1
	.long	LIDUCKHIKICK2
	.long	LIDUCKLOKICK1
	.long	LIDUCKLOKICK2
	.long	0
	.long	LIDUCKLOKICK1
	.long	LIDUCKHIKICK2
	.long	LIDUCKHIKICK1
	.long	LIDUCK3
	.long	0

LIDUCKLOKICK1
	.long	LIDUCKLOKICK1A,LIDUCKLOKICK1B,0
LIDUCKLOKICK2
	.long	LIDUCKLOKICK2A,LIDUCKLOKICK2B,0

;***************************************************************************

a_duck_kick_hi
	.long	LIDUCKHIKICK1
	.long	LIDUCKHIKICK2
	.long	LIDUCKHIKICK3
	.long	LIDUCKHIKICK4
	.long	0
	.long	LIDUCKHIKICK3
	.long	LIDUCKHIKICK2
	.long	LIDUCKHIKICK1
	.long	LIDUCK3
	.long	0

LIDUCKHIKICK1
	.long	LIDUCKHIKICK1A,LIDUCKHIKICK1B,0
LIDUCKHIKICK2
	.long	LIDUCKHIKICK2A,LIDUCKHIKICK2B,0
LIDUCKHIKICK3
	.long	LIDUCKHIKICK3A,LIDUCKHIKICK3B,0
LIDUCKHIKICK4
	.long	LIDUCKHIKICK4A,0

;***************************************************************************

a_uppercut
	.long	LIUPPERCUT2
	.long	LIUPPERCUT3
	.long	LIUPPERCUT4
	.long	LIUPPERCUT5
	.long	ani_nosleep	; dont sleep after next frame
	.long	LIUPPERCUT6
	.long	0
	.long	LIUPPERCUT5
	.long	0

LIUPPERCUT2
	.long	LIUPPERCUT2A,0
LIUPPERCUT3
	.long	LIUPPERCUT3A,LIUPPERCUT3B,0
LIUPPERCUT4
	.long	LIUPPERCUT4A,LIUPPERCUT4B,0
LIUPPERCUT5
	.long	LIUPPERCUT5A,LIUPPERCUT5B,0
LIUPPERCUT6
	.long	LIUPPERCUT6A,LIUPPERCUT6B,0

;***************************************************************************

a_duck_hit
	.long	LIDUCKHIT2
	.long	LIDUCKHIT3
	.long	LIDUCKHIT2
	.long	LIDUCKHIT1
	.long	0

LIDUCKHIT1
	.long	LIDUCKHIT1A,LIDUCKHIT1B,0
LIDUCKHIT2
	.long	LIDUCKHIT2A,LIDUCKHIT2B,0
LIDUCKHIT3
	.long	LIDUCKHIT3A,LIDUCKHIT3B,0

;***************************************************************************

a_hipunch
	.long	LIHIPUNCH1
	.long	LIHIPUNCH2
	.long	LIHIPUNCH3
	.long	0

	.long	LIHIPUNCH4
	.long	LIHIPUNCH5
	.long	LIHIPUNCH6
	.long	0

	.long	LIHIPUNCH5
	.long	LIHIPUNCH4
	.long	ani_jump,a_hipunch+(32*2)
	.long	0					; we NEED this "0"
*
* Unhipunch #1
*
	.long	LIHIPUNCH2
	.long	LIHIPUNCH1
	.long	0
*
* Unhipunch #2
*
	.long	LIHIPUNCH7
	.long	0
*
* Hi to Med #1
*
	.long	LIHIPUNCH4
	.long	LILOPUNCH5
	.long	ani_jump,a_lopunch+(32*6)
	.long	0
*
* Hi to Med #2
*
	.long	LIHIPUNCH5
	.long	LILOPUNCH2
	.long	ani_jump,a_lopunch+(32*2)
	.long	0


a_lopunch
	.long	LIHIPUNCH1
	.long	LILOPUNCH1
	.long	LILOPUNCH2
	.long	0

	.long	LILOPUNCH3
	.long	LILOPUNCH4
	.long	LILOPUNCH5
	.long	0

	.long	LILOPUNCH4
	.long	LILOPUNCH3
	.long	ani_jump,a_lopunch+(32*2)
	.long	0
*
* Unlopunch #1
*
	.long	LILOPUNCH1
	.long	LIHIPUNCH1
	.long	0
*
* Unlopunch #2
*
	.long	LILOPUNCH4
	.long	0
*
* Med to High #1
*
	.long	LILOPUNCH1
	.long	LIHIPUNCH5
	.long	ani_jump,a_hipunch+(32*6)
	.long	0
*
* Med to High #2
*
	.long	LILOPUNCH4
	.long	LIHIPUNCH5
	.long	ani_jump,a_hipunch+(32*2)


LIHIPUNCH1
	.long	LIHIPUNCH1A,LIHIPUNCH1B,0
LIHIPUNCH2
	.long	LIHIPUNCH2A,LIHIPUNCH2B,0
LIHIPUNCH3
	.long	LIHIPUNCH3A,LIHIPUNCH3B,0
LIHIPUNCH4
	.long	LIHIPUNCH4A,LIHIPUNCH4B,0
LIHIPUNCH5
	.long	LIHIPUNCH5A,LIHIPUNCH5B,0
LIHIPUNCH6
	.long	LIHIPUNCH6A,LIHIPUNCH6B,0
LIHIPUNCH7
	.long	LIHIPUNCH7A,LIHIPUNCH7B,0

LILOPUNCH1
	.long	LILOPUNCH1A,LILOPUNCH1B,0
LILOPUNCH2
	.long	LILOPUNCH2A,LILOPUNCH2B,0
LILOPUNCH3
	.long	LILOPUNCH3A,LILOPUNCH3B,0
LILOPUNCH4
	.long	LILOPUNCH4A,LILOPUNCH4B,0
LILOPUNCH5
	.long	LILOPUNCH5A,LILOPUNCH5B,0

;***************************************************************************

a_elbow
	.long	LICOMBO1
	.long	LICOMBO2
	.long	LICOMBO3
	.long	ani_nosleep
	.long	LICOMBO4
	.long	0
	.long	LICOMBO2
	.long	LICOMBO1
	.long	0

	.long	LICOMBO5
	.long	ani_adjustx
	.word	>10
	.long	LICOMBO6
	.long	ani_adjustx
	.word	>10
	.long	LICOMBO7
	.long	LICOMBO8	; part 3 - elbow hit #2
	.long	0

	.long	LICOMBO9
	.long	ani_adjustx
	.word	5
	.long	LICOMBO10
	.long	ani_adjustx
	.word	5
	.long	LICOMBO11
	.long	ani_adjustx
	.word	5
	.long	LICOMBO12
	.long	ani_adjustx
	.word	5
	.long	LICOMBO13
	.long	ani_adjustx
	.word	5
	.long	LICOMBO14
	.long	ani_adjustx
	.word	5
	.long	LICOMBO15	; part 4 - elbow hit #3
	.long	0

	.long	LICOMBO16
	.long	0

LICOMBO1
	.long	LICOMBO1A,LICOMBO1B,0
LICOMBO2
	.long	LICOMBO2A,LICOMBO2B,0
LICOMBO3
	.long	LICOMBO3A,LICOMBO3B,0
LICOMBO4
	.long	LICOMBO4A,LICOMBO4B,0
LICOMBO5
	.long	LICOMBO5A,LICOMBO5B,0
LICOMBO6
	.long	LICOMBO6A,LICOMBO6B,0
LICOMBO7
	.long	LICOMBO7A,LICOMBO7B,0
LICOMBO8
	.long	LICOMBO8A,LICOMBO8B,0
LICOMBO9
	.long	LICOMBO9A,LICOMBO9B,0
LICOMBO10
	.long	LICOMBO10A,LICOMBO10B,0
LICOMBO11
	.long	LICOMBO11A,LICOMBO11B,0
LICOMBO12
	.long	LICOMBO12A,LICOMBO12B,0
LICOMBO13
	.long	LICOMBO13A,LICOMBO13B,0
LICOMBO14
	.long	LICOMBO14A,LICOMBO14B,0
LICOMBO15
	.long	LICOMBO15A,LICOMBO15B,0
LICOMBO16
	.long	LICOMBO16A,LICOMBO16B,0

;***************************************************************************

a_block
	.long	LIHIBLOCK1
	.long	LIHIBLOCK2
	.long	LIHIBLOCK3
	.long	0

LIHIBLOCK1
	.long	LIHIBLOCK1A,LIHIBLOCK1B,0
LIHIBLOCK2
	.long	LIHIBLOCK2A,LIHIBLOCK2B,0
LIHIBLOCK3
	.long	LIHIBLOCK3A,LIHIBLOCK3B,0

; ejbpatch
;LILOBLOCK1
;	.long	LILOBLOCK1A,LILOBLOCK1B,0
;LILOBLOCK2
;	.long	LILOBLOCK2A,LILOBLOCK2B,0

;***************************************************************************

a_lokick 
	.long	LILOKICK1
	.long	LILOKICK2
	.long	LILOKICK3
	.long	LILOKICK4
	.long	LILOKICK5
	.long	LILOKICK6
	.long	0
	.long	LILOKICK5
	.long	LILOKICK4
	.long	LILOKICK3
	.long	LILOKICK2
	.long	LILOKICK1
	.long	0

LILOKICK1
	.long	LILOKICK1A,LILOKICK1B,0
LILOKICK2
	.long	LILOKICK2A,LILOKICK2B,0
LILOKICK3
	.long	LILOKICK3A,LILOKICK3B,0
LILOKICK4
	.long	LILOKICK4A,LILOKICK4B,0
LILOKICK5
	.long	LILOKICK5A,0
LILOKICK6
	.long	LILOKICK6A,LILOKICK6B,0

;***************************************************************************

a_hikick
	.long	LILOKICK1
	.long	LILOKICK2
	.long	LILOKICK3
	.long	LIHIKICK1
	.long	LIHIKICK2
	.long	LIHIKICK3
	.long	0
	.long	LIHIKICK2
	.long	LIHIKICK1
	.long	LILOKICK3
	.long	LILOKICK2
	.long	LILOKICK1
	.long	0

LIHIKICK1
	.long	LIHIKICK1A,LIHIKICK1B,0
LIHIKICK2
	.long	LIHIKICK2A,0
LIHIKICK3
	.long	LIHIKICK3A,LIHIKICK3B,LIHIKICK3C,0

;***************************************************************************

a_knee
	.long	LIKNEECOMBO1
	.long	LIKNEECOMBO2
	.long	LIKNEECOMBO3
	.long	0
	.long	LIKNEECOMBO2
	.long	LIKNEECOMBO1
	.long	0

	.long	LIKNEECOMBO4
	.long	LIKNEECOMBO5
	.long	LIKNEECOMBO6
	.long	LIKNEECOMBO7

LIKNEECOMBO1
	.long	LIKNEECOMBO1A,LIKNEECOMBO1B,0
LIKNEECOMBO2
	.long	LIKNEECOMBO2A,0
LIKNEECOMBO3
	.long	LIKNEECOMBO3A,LIKNEECOMBO3B,0
LIKNEECOMBO4
	.long	LIKNEECOMBO4A,LIKNEECOMBO4B,0
LIKNEECOMBO5
	.long	LIKNEECOMBO5A,LIKNEECOMBO5B,0
LIKNEECOMBO6
	.long	LIKNEECOMBO6A,0
LIKNEECOMBO7
	.long	LIKNEECOMBO7A,LIKNEECOMBO7B,0

;***************************************************************************

a_roundhouse
	.long	LISPINKICK1
	.long	LISPINKICK2
	.long	LISPINKICK3
	.long	LISPINKICK4
	.long	LISPINKICK5
	.long	0
	.long	LISPINKICK6
	.long	LISPINKICK7
	.long	LISPINKICK8
	.long	0

LISPINKICK1
	.long	LISPINKICK1A,LISPINKICK1B,0
LISPINKICK2
	.long	LISPINKICK2A,LISPINKICK2B,0
LISPINKICK3
	.long	LISPINKICK3A,0
LISPINKICK4
	.long	LISPINKICK4A,LISPINKICK4B,0
LISPINKICK5
	.long	LISPINKICK5A,LISPINKICK5B,0
LISPINKICK6
	.long	LISPINKICK6A,0
LISPINKICK7
	.long	LISPINKICK7A,LISPINKICK7B,0
LISPINKICK8
	.long	LISPINKICK8A,LISPINKICK8B,0
;***************************************************************************

a_sweep_kick
	.long	LISWEEPKICK1
	.long	LISWEEPKICK2
	.long	LISWEEPKICK3
	.long	ani_calla,sweep_sounds
	.long	LISWEEPKICK4
	.long	LISWEEPKICK5
	.long	0
	.long	LISWEEPKICK6
	.long	LISWEEPKICK7
	.long	LISWEEPKICK8
	.long	0

LISWEEPKICK1
	.long	LISWEEPKICK1A,LISWEEPKICK1B,0
LISWEEPKICK2
	.long	LISWEEPKICK2A,LISWEEPKICK2B,0
LISWEEPKICK3
	.long	LISWEEPKICK3A,LISWEEPKICK3B,0
LISWEEPKICK4
	.long	LISWEEPKICK4A,LISWEEPKICK4B,0
LISWEEPKICK5
	.long	LISWEEPKICK5A,LISWEEPKICK5B,0
LISWEEPKICK6
	.long	LISWEEPKICK6A,LISWEEPKICK6B,0
LISWEEPKICK7
	.long	LISWEEPKICK7A,0
LISWEEPKICK8
	.long	LISWEEPKICK8A,LISWEEPKICK8B,0

;***************************************************************************

a_jump
	.long	LIJUMP1
	.long	LIJUMP2
	.long	LIJUMP3
	.long	0
	.long	LIJUMP2
	.long	LIJUMP1
	.long	0

LIJUMP1	.long	LIJUMP1A,LIJUMP1B,0
LIJUMP2	.long	LIJUMP2A,LIJUMP2B,0
LIJUMP3	.long	LIJUMP3A,LIJUMP3B,0

;***************************************************************************

a_jump_kick
	.long	LIJUMPKICK1
	.long	LIJUMPKICK2
	.long	LIJUMPKICK3
	.long	0
	.long	LIJUMPKICK2
	.long	LIJUMPKICK1
	.long	0

LIJUMPKICK1
	.long	LIJUMPKICK1A,0
LIJUMPKICK2
	.long	LIJUMPKICK2A,LIJUMPKICK2B,0
LIJUMPKICK3
	.long	LIJUMPKICK3A,LIJUMPKICK3B,0

;***************************************************************************
a_fflip
	.long	LIJUMPFLIP1
	.long	LIJUMPFLIP2
	.long	LIJUMPFLIP3
	.long	LIJUMPFLIP4
	.long	LIJUMPFLIP5
	.long	LIJUMPFLIP6
	.long	LIJUMPFLIP7
	.long	LIJUMPFLIP8
	.long	ani_jump,a_fflip+32

a_bflip
	.long	LIJUMPFLIP1
	.long	LIJUMPFLIP8
	.long	LIJUMPFLIP7
	.long	LIJUMPFLIP6
	.long	LIJUMPFLIP5
	.long	LIJUMPFLIP4
	.long	LIJUMPFLIP3
	.long	LIJUMPFLIP2
	.long	ani_jump,a_bflip+32

LIJUMPFLIP1
	.long	LIJUMPFLIP1A,0
LIJUMPFLIP2
	.long	LIJUMPFLIP2A,0
LIJUMPFLIP3
	.long	LIJUMPFLIP3A,0
LIJUMPFLIP4
	.long	LIJUMPFLIP4A,0
LIJUMPFLIP5
	.long	LIJUMPFLIP5A,0
LIJUMPFLIP6
	.long	LIJUMPFLIP6A,0
LIJUMPFLIP7
	.long	LIJUMPFLIP7A,0
LIJUMPFLIP8
	.long	LIJUMPFLIP8A,0
;***************************************************************************

a_flip_kick
	.long	LIFLIPKICK1
	.long	LIFLIPKICK2
	.long	LIFLIPKICK3
	.long	0
	.long	LIFLIPKICK2
	.long	LIFLIPKICK1
	.long	0

LIFLIPKICK1
	.long	LIFLIPKICK1A,0
LIFLIPKICK2
	.long	LIFLIPKICK2A,0
LIFLIPKICK3
	.long	LIFLIPKICK3A,LIFLIPKICK3B,0

;***************************************************************************

a_flip_punch
	.long	LIFLIPUNCH1
	.long	LIFLIPUNCH2
	.long	LIFLIPUNCH3
	.long	0
	.long	LIFLIPUNCH2
	.long	LIFLIPUNCH1
	.long	0

LIFLIPUNCH1
	.long	LIFLIPUNCH1A,LIFLIPUNCH1B,0
LIFLIPUNCH2
	.long	LIFLIPUNCH2A,LIFLIPUNCH2B,0
LIFLIPUNCH3
	.long	LIFLIPUNCH3A,LIFLIPUNCH3B,0

;***************************************************************************

a_hit_hi
	.long	LIHIHIT2
	.long	LIHIHIT3
	.long	LIHIHIT2
	.long	LIHIHIT1
	.long	0

LIHIHIT1	.long	LIHIHIT1A,LIHIHIT1B,0
LIHIHIT2	.long	LIHIHIT2A,LIHIHIT2B,0
LIHIHIT3	.long	LIHIHIT3A,LIHIHIT3B,0

;***************************************************************************

a_hit_lo
	.long	LILOHIT2
	.long	LILOHIT3
	.long	LILOHIT2
	.long	LILOHIT1
	.long	0

LILOHIT1	.long	LILOHIT1A,LILOHIT1B,0
LILOHIT2	.long	LILOHIT2A,LILOHIT2B,0
LILOHIT3	.long	LILOHIT3A,LILOHIT3B,0

;***************************************************************************

a_stumble
	.long	LISTUMBLE1
	.long	LISTUMBLE2
	.long	LISTUMBLE3
	.long	LISTUMBLE4
	.long	LISTUMBLE5
	.long	LISTUMBLE6
	.long	LISTUMBLE7
	.long	0

j_stumble
	.long	LISTUMBLE1
	.long	LISTUMBLE2
	.long	LISTUMBLE3
	.long	LISTUMBLE4
	.long	LISTUMBLE5
	.long	LISTUMBLE6
	.long	LISTUMBLE7
	.long	ani_jump,j_stumble

LISTUMBLE1
	.long	LISTUMBLE1A,LISTUMBLE1B,0
LISTUMBLE2
	.long	LISTUMBLE2A,LISTUMBLE2B,0
LISTUMBLE3
	.long	LISTUMBLE3A,0
LISTUMBLE4
	.long	LISTUMBLE4A,LISTUMBLE4B,0
LISTUMBLE5
	.long	LISTUMBLE5A,LISTUMBLE5B,0
LISTUMBLE6
	.long	LISTUMBLE6A,LISTUMBLE6B,0
LISTUMBLE7
	.long	LISTUMBLE7A,LISTUMBLE7B,0

;***************************************************************************

a_dizzy
	.long	LISTUNNED1
	.long	LISTUNNED2
	.long	LISTUNNED3
	.long	LISTUNNED4
	.long	LISTUNNED5
	.long	LISTUNNED6
	.long	LISTUNNED7
	.long	LISTUNNED8
	.long	LISTUNNED9
	.long	ani_jump,a_dizzy

LISTUNNED1
	.long	LISTUNNED1A,LISTUNNED1B,0
LISTUNNED2
	.long	LISTUNNED2A,LISTUNNED2B,0
LISTUNNED3
	.long	LISTUNNED3A,LISTUNNED3B,0
LISTUNNED4
	.long	LISTUNNED4A,LISTUNNED4B,0
LISTUNNED5
	.long	LISTUNNED5A,LISTUNNED5B,0
LISTUNNED6
	.long	LISTUNNED6A,LISTUNNED6B,0
LISTUNNED7
	.long	LISTUNNED7A,LISTUNNED7B,0
LISTUNNED8
	.long	LISTUNNED8A,LISTUNNED8B,0
LISTUNNED9
	.long	LISTUNNED9A,LISTUNNED9B,0
;***************************************************************************

a_knockdown
	.long	LIKNOCKDOWN1
	.long	LIKNOCKDOWN2
	.long	LIKNOCKDOWN3
	.long	LIKNOCKDOWN4
	.long	0
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0

LIKNOCKDOWN1
	.long	LIKNOCKDOWN1A,0
LIKNOCKDOWN2
	.long	LIKNOCKDOWN2A,0
LIKNOCKDOWN3
	.long	LIKNOCKDOWN3A,0
LIKNOCKDOWN4
	.long	LIKNOCKDOWN4A,LIKNOCKDOWN4B,0
LIKNOCKDOWN5
	.long	LIKNOCKDOWN5A,0
LIKNOCKDOWN6
	.long	LIKNOCKDOWN6A,0

;***************************************************************************

a_getup
	.long	LIGETUP1
	.long	LIGETUP2
	.long	LIGETUP3
	.long	LIGETUP4
	.long	LIGETUP5
	.long	LIGETUP6
	.long	0

LIGETUP1	.long	LIGETUP1A,0
LIGETUP2	.long	LIGETUP2A,LIGETUP2B,0
LIGETUP3	.long	LIGETUP3A,LIGETUP3B,0
LIGETUP4	.long	LIGETUP4A,0
LIGETUP5	.long	LIGETUP5A,0
LIGETUP6	.long	LIGETUP6A,LIGETUP6B,0

;***************************************************************************

a_afb_kano
	.long	ani_offset_xy
	.word	->29,->03
	.long	LIKNOCKDOWN1

	.long	ani_offset_xy
	.word	->2d,>05
	.long	LIKNOCKDOWN3

	.long	ani_offset_xy
 	.word	->36,>14
	.long	LIKNOCKDOWN4

	.long	0
*
* fall down solo
*
	.long	LIKNOCKDOWN4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0

a_fb_smoke
a_afb_robo2
	.long	ani_offset_xy
	.word	->1e,->32
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>07,->47
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>37,->4e
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>55,->26
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>67,->15
	.long	LIKNOCKDOWN6
	.long	ani_offset_xy
	.word	>72,>16
	.long	LIKNOCKDOWN6
	.long	0

a_fb_mileena
	.long	ani_offset_xy
	.word	->3a,->01
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->29,>07
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->1e,>01
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>0e,->1a
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>63,->34
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0

a_fb_kitana
	.long	ani_offset_xy
	.word	->20,->23
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->08,->40
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>32,->2d
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>3d,>0c
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0



a_fb_jade
	.long	ani_offset_xy
	.word	->5a,>04
	.long	LIKNOCKDOWN1
	.long	ani_offset_xy
	.word	->5b,->21
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->43,->6c
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	->05,->6d
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>5e,->6c
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>81,->3d
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>89,->0c
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0


a_fb_nj	.long	ani_offset_xy
	.word	->49,>06
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->3c,>0e
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->28,>17
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>00,>16
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>0e,>0e
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>5d,->17
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0


a_fb_lao
	.long	ani_offset_xy
	.word	->2b,>1a
	.long	LISTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->0f,>33
	.long	LISTUMBLE1		; 2
	.long	ani_flip
	.long	ani_offset_xy
	.word	->2b,>1d
	.long	LIFLIPPED1		; 3
	.long	ani_offset_xy
	.word	->46,->1e
	.long	LIFLIPPED2		; 4
	.long	ani_offset_xy
	.word	->2c,->5e
	.long	LIFLIPPED3		; 5
	.long	ani_offset_xy
	.word	>1d,->74
	.long	LIFLIPPED4		; 6
	.long	ani_offset_xy
	.word	>54,->70
	.long	LIFLIPPED4		; 7
	.long	ani_offset_xy
	.word	>60,->56
	.long	LIFLIPPED4		; 8
	.long	ani_offset_xy
	.word	>77,>02
	.long	LIFLIPPED4		; 9
	.long	ani_offset_xy
	.word	>77,>52
	.long	LIFLIPPED4		; 10
	.long	0


a_fb_tusk
	.long	ani_offset_xy
	.word	->6e,>00
	.long	LIFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->5d,->4a
	.long	LIFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->0c,->81
	.long	LIFLIPPED3		; 3
	.long	ani_offset_xy
	.word	>4b,->61
	.long	LIFLIPPED4		; 4
	.long	ani_offset_xy
	.word	>4a,->1c
	.long	LIFLIPPED4		; 5

	.long	ani_offset_xy
	.word	>17,->04
  	.long	LIKNOCKDOWN6		; 7
	.long	ani_offset_xy
	.word	->24,->19
  	.long	LIKNOCKDOWN6		; 7
	.long	ani_offset_xy
	.word	->68,>01
	.long	LIFLIPPED1		; 8
	.long	ani_offset_xy
	.word	->4e,->54
	.long	LIFLIPPED2		; 9
	.long	ani_offset_xy
	.word	>26,->72
	.long	LIFLIPPED3		; 10 

	.long	ani_offset_xy
	.word	>65,->05
	.long	LIFLIPPED4		; 11
	.long	ani_offset_xy
	.word	>64,>09
  	.long	LIKNOCKDOWN6		; 12
	.long	0



a_fb_sg
	.long	ani_offset_xy
	.word	->3d,->30
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->08,->52
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	->01,->5e
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>18,->4f
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>1a,->35
	.long	LIFLIPPED3
	.long	ani_flip
	.long	ani_offset_xy
	.word	->1c,->09
  	.long	LIKNOCKDOWN6
	.long	0


a_fb_st
	.long	ani_offset_xy
	.word	->4c,>00
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->41,>07
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->2a,>01
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	->07,>03
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>24,>13
	.long	LIFLIPPED4

	.long	ani_offset_xy
	.word	>02,->04
	.long	LIKNOCKDOWN6
	.long	ani_offset_xy
	.word	->23,->04
	.long	LIKNOCKDOWN6
	.long	ani_offset_xy
	.word	->38,->04
	.long	LIKNOCKDOWN6

	.long	ani_offset_xy
	.word	->60,>19
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->67,->0b
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->3c,->4c
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>3b,->54
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>4c,->18
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>5b,->08
	.long	LIKNOCKDOWN6
	.long	0



a_fb_lk
	.long	ani_offset_xy
	.word	->44,->01
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->3b,>07
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->13,>08
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>01,>10
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>2c,->04
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>88,->1f
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0



a_fb_kano
	.long	ani_offset_xy
	.word	->3d,->16			; we need even # of words here !
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->11,->2d
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>33,->37
	.long	LIFLIPPED3
	.long	0

	.long	LIFLIPPED4
	.long	LIFLIPPED4
	.long	LIKNOCKDOWN4
	.long	LIKNOCKDOWN5
	.long	0


a_fb_sonya
	.long	ani_offset_xy
	.word	->2d,>05
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->11,>04
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>19,->13
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>71,->27
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>9f,->41
	.long	LIFLIPPED4
	.long	0

	.long	LIFLIPPED4
	.long	LIKNOCKDOWN4
	.long	LIKNOCKDOWN5
	.long	0

a_fb_jax
	.long	ani_offset_xy
	.word	->4a,->1a
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->1e,->3b
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>15,->51
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>4e,->38
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>5f,->0b
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>4c,>06
	.long	LIKNOCKDOWN6
	.long	0

a_fb_ind
	.long	ani_offset_xy
	.word	->5c,->10
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->4d,->3e
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	->13,->65
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>39,->55
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>57,->1d
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>46,>00
	.long	LIKNOCKDOWN6
	.long	0

a_fb_sz
	.long	ani_offset_xy
	.word	->4a,->39
	.long	LIFLIPPED1

	.long	ani_flip
	.long	ani_offset_xy
	.word	>55,->26
	.long	LIFLIPPED4

	.long	ani_offset_xy
	.word	>3a,->07
	.long	LIFLIPPED4

	.long	ani_offset_xy
	.word	>02,->16
	.long	LIKNOCKDOWN5

	.long	ani_offset_xy
	.word	->3a,->3e
	.long	LIKNOCKDOWN5

	.long	ani_offset_xy
	.word	->60,->63
	.long	LIKNOCKDOWN5
	.long	0

a_fb_swat
	.long	ani_offset_xy
	.word	->4c,->11
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->36,->44
	.long	LIFLIPPED2
	.long	ani_offset_xy
	.word	>26,->5f
	.long	LIFLIPPED3
	.long	ani_offset_xy
	.word	>65,->26
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>50,>00
	.long	LIKNOCKDOWN6
	.long	0



a_fb_lia
	.long	ani_offset_xy
	.word	->64,>00
	.long	LISTUMBLE1
	.long	ani_offset_xy
	.word	->73,>03
	.long	LISTUMBLE1

	.long	ani_offset_xy
	.word	->75,->1e
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->57,->3d
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->23,->46
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	>1e,->4e
	.long	LIFLIPPED1

	.long	ani_offset_xy
	.word	>a8,>12
	.long	LIFLIPPED4
	.long	ani_offset_xy
	.word	>8d,>00
	.long	LIKNOCKDOWN6
	.long	0

a_fb_robo
	.long	ani_offset_xy
	.word	->4f,->0b
	.long	LIFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->4d,->3c
	.long	LIFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->38,->51
	.long	LIFLIPPED2		; 3

	.long	ani_offset_xy
	.word	>00,->74
	.long	LIFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>45,->79
	.long	LIFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>71,->67
	.long	LIFLIPPED4		; 6

	.long	ani_offset_xy
	.word	>80,->1e
	.long	LIFLIPPED4		; 7
	.long	ani_offset_xy
	.word	>6d,->0e
	.long	LIKNOCKDOWN6		; 8
	.long	0


a_fb_robo2
	.long	ani_offset_xy
	.word	->29,->07
	.long	LISTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->2b,->1c
	.long	LIFLIPPED1		; 2
	.long	ani_offset_xy
	.word	->0e,->24
	.long	LIFLIPPED2		; 3
	.long	ani_offset_xy
	.word	>19,->26
	.long	LIFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>31,->0b
	.long	LIFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>25,>06
	.long	LIFLIPPED4		; 6
	.long	ani_offset_xy
	.word	->0d,->15
	.long	LIKNOCKDOWN6		; 7
	.long	0


a_legged
	.long	ani_offset_xy
	.word	->63,>03
	.long	LIKNOCKDOWN1

	.long	ani_offset_xy
	.word	->54,->26
	.long	LIFLIPPED1

	.long	ani_offset_xy
	.word	->1d,->4a
	.long	LIFLIPPED3

	.long	ani_offset_xy
	.word	>37,->40
	.long	LIFLIPPED4

	.long	ani_offset_xy
	.word	>5a,->0a
	.long	LIFLIPPED4
	.long	0
	

a_orb_banged
	.long	LIFLIPPED1
	.long	LIFLIPPED2
	.long	LIFLIPPED3
	.long	LIFLIPPED4
	.long	0


a_zoomed
	.long	ani_offset_xy
	.word	>59,->25
	.long	LIKNOCKDOWN3	; 1

	.long	ani_offset_xy
	.word	>57,->0a
	.long	LIKNOCKDOWN4	; 2

	.long	ani_offset_xy
	.word	>31,>01
	.long	LIKNOCKDOWN5	; 3

	.long	ani_offset_xy
	.word	->30,>02
	.long	LIKNOCKDOWN5	; 4

	.long	ani_offset_xy
	.word	->88,->13
	.long	LIFLIPPED1	; 5

	.long	ani_offset_xy
	.word	->2f,->5f
	.long	LIFLIPPED3	; 6
	.long	0

	.long	LIFLIPPED3
	.long	LIFLIPPED4
	.long	LIKNOCKDOWN5
	.long	LIKNOCKDOWN6
	.long	0

a_shook
	.long	ani_offset_xy
	.word	->50,->03
	.long	LISTUMBLE1	; 3

	.long	ani_offset_xy
	.word	->37,->1e
	.long	LISTUMBLE1	; 4

	.long	ani_offset_xy
	.word	->1a,->14
	.long	LISTUMBLE1	; 5
	.long	0

; loop
	.long	ani_offset_xy
	.word	->20,->18
	.long	LISTUMBLE1	; 6

	.long	ani_offset_xy
	.word	->36,->22
	.long	LISTUMBLE1	; 7

	.long	ani_offset_xy
	.word	->45,->26
	.long	LISTUMBLE1	; 8

	.long	ani_offset_xy
	.word	->36,->22
	.long	LISTUMBLE1	; 7
	.long	0


LIFLIPPED1
	.long	LIFLIPPED1A,0
LIFLIPPED2
	.long	LIFLIPPED2A,LIFLIPPED2B,0
LIFLIPPED3
	.long	LIFLIPPED3A,0
LIFLIPPED4
	.long	LIFLIPPED4A,0
;***************************************************************************

a_sweep_fall
	.long	LISWEEPFALL1
	.long	LISWEEPFALL2
	.long	LISWEEPFALL3
	.long	LISWEEPFALL4
	.long	0
	.long	LISWEEPFALL5
	.long	LISWEEPFALL6
	.long	0

LISWEEPFALL1
	.long	LISWEEPFALL1A,LISWEEPFALL1B,0
LISWEEPFALL2
	.long	LISWEEPFALL2A,LISWEEPFALL2B,0
LISWEEPFALL3
	.long	LISWEEPFALL3A,LISWEEPFALL3B,0
LISWEEPFALL4
	.long	LISWEEPFALL4A,0
LISWEEPFALL5
	.long	LISWEEPFALL5A,0
LISWEEPFALL6
	.long	LISWEEPFALL6A,0
;***************************************************************************

a_sweepup
	.long	LISWEEPUP1
	.long	LISWEEPUP2
	.long	LISWEEPUP3
	.long	LISWEEPUP4
	.long	LISWEEPUP5
	.long	LISWEEPUP6
	.long	0

LISWEEPUP1
	.long	LISWEEPUP1A,0
LISWEEPUP2
	.long	LISWEEPUP2A,0
LISWEEPUP3
	.long	LISWEEPUP3A,0
LISWEEPUP4
	.long	LISWEEPUP4A,0
LISWEEPUP5
	.long	LISWEEPUP5A,0
LISWEEPUP6
	.long	LISWEEPUP6A,LISWEEPUP6B,0

;**************************************************************************

a_victory
	.long	RBVICTORY1
	.long	RBVICTORY2
	.long	RBVICTORY3
	.long	RBVICTORY4
	.long	RBVICTORY5
	.long	RBVICTORY6
	.long	RBVICTORY7
	.long	0
*
* part 2 is for psel
*
	.long	RBVICTORY1
	.long	ani_adjustx
	.word	-3
	.long	RBVICTORY2
	.long	ani_adjustx
	.word	-3
	.long	RBVICTORY3
	.long	ani_adjustx
	.word	-3
	.long	RBVICTORY4
	.long	ani_adjustx
	.word	-3
	.long	RBVICTORY5
	.long	ani_adjustx
	.word	-3
	.long	RBVICTORY6
	.long	RBVICTORY7
	.long	0

RBVICTORY1
	.long	RBVICTORY1A,RBVICTORY1B,0
RBVICTORY2
	.long	RBVICTORY2A,RBVICTORY2B,0
RBVICTORY3
	.long	RBVICTORY3A,0
RBVICTORY4
	.long	RBVICTORY4A,0
RBVICTORY5
	.long	RBVICTORY5A,0
RBVICTORY6
	.long	RBVICTORY6A,0
RBVICTORY7
	.long	RBVICTORY7A,0

;*************************************************************************

a_throw
	.long	LIHAIRTHRO1
	.long	LIHAIRTHRO2
	.long	LIHAIRTHRO3
	.long	LIHAIRTHRO4
	.long	LIHAIRTHRO5
	.long	LIHAIRTHRO6
	.long	0

	.long	LIHAIRTHRO7
	.long	LIHAIRTHRO9
	.long	LIHAIRTHRO11
	.long	LIHAIRTHRO12
	.long	LIHAIRTHRO13
	.long	LIHAIRTHRO14
	.long	LIHAIRTHRO15
	.long	LIHAIRTHRO16
	.long	0

	.long	LIHAIRTHRO17
	.long	LIHAIRTHRO18
	.long	LIHAIRTHRO19
	.long	0

LIHAIRTHRO1
	.long	LIHAIRTHRO1A,LIHAIRTHRO1B,0
LIHAIRTHRO2
	.long	LIHAIRTHRO2A,LIHAIRTHRO2B,0
LIHAIRTHRO3
	.long	LIHAIRBODY1A,LIHAIRBODY1B,LIHAIRTHRO3A,0
LIHAIRTHRO4
	.long	LIHAIRBODY1A,LIHAIRBODY1B,LIHAIRTHRO4A,0
LIHAIRTHRO5
	.long	LIHAIRBODY1A,LIHAIRBODY1B,LIHAIRTHRO5A,0
LIHAIRTHRO6
	.long	LIHAIRBODY1A,LIHAIRBODY1B,LIHAIRTHRO6A,0
LIHAIRTHRO7
	.long	LIHAIRBODY1A,LIHAIRBODY1B,LIHAIRTHRO7A,0
LIHAIRTHRO9
	.long	LIHAIRTHRO9A,LIHAIRTHRO9B,LIHAIRTHRO9C,0
LIHAIRTHRO11
	.long	LIHAIRTHRO11A,LIHAIRTHRO11B,LIHAIRTHRO11C,0
LIHAIRTHRO12
	.long	LIHAIRTHRO12A,LIHAIRTHRO12B,LIHAIRTHRO12C,0
LIHAIRTHRO13
	.long	LIHAIRTHRO13A,LIHAIRTHRO13B,LIHAIRTHRO13C,0
LIHAIRTHRO14
	.long	LIHAIRTHRO14A,LIHAIRTHRO14B,0
LIHAIRTHRO15
	.long	LIHAIRTHRO15A,LIHAIRTHRO15B,LIHAIRBODY2A,LIHAIRBODY2B,0
LIHAIRTHRO16
	.long	LIHAIRTHRO16A,LIHAIRBODY2A,LIHAIRBODY2B,0
LIHAIRTHRO17
	.long	LIHAIRTHRO17A,LIHAIRTHRO17B,LIHAIRTHRO17C,0
LIHAIRTHRO18
	.long	LIHAIRTHRO18A,LIHAIRTHRO18B,LIHAIRTHRO18C,0
LIHAIRTHRO19
	.long	LIHAIRTHRO19A,LIHAIRTHRO19B,0

;**************************************************************************

a_lia_scream
	.long	LIMOUTHPRO1
	.long	LIMOUTHPRO2
	.long	LIMOUTHPRO3
	.long	LIMOUTHPRO5
	.long	0

j_scream
	.long	LIMOUTHPRO6
	.long	LIMOUTHPRO7
	.long	LIMOUTHPRO8
	.long	LIMOUTHPRO9
	.long	LIMOUTHPRO10
	.long	LIMOUTHPRO11
	.long	LIMOUTHPRO12
	.long	LIMOUTHPRO5
	.long	ani_jump,j_scream
	.long	0
	.long	LIMOUTHPRO3
	.long	LIMOUTHPRO2
	.long	LIMOUTHPRO1
	.long	0

LIMOUTHPRO1
	.long	LIMOUTHPRO1A,LIMOUTHPRO1B,0
LIMOUTHPRO2
	.long	LIMOUTHPRO2A,LIMOUTHPRO2B,0
LIMOUTHPRO3
	.long	LIMOUTHPRO3A,LIMOUTHPRO3B,0
LIMOUTHPRO5
	.long	LIMOUTHPRO5A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO6
	.long	LIMOUTHPRO6A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO7
	.long	LIMOUTHPRO7A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO8
	.long	LIMOUTHPRO8A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO9
	.long	LIMOUTHPRO9A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO10
	.long	LIMOUTHPRO10A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO11
	.long	LIMOUTHPRO11A,LIMOUTHPRO4A,LIMOUTHPRO4B,0
LIMOUTHPRO12
	.long	LIMOUTHPRO12A,LIMOUTHPRO4A,LIMOUTHPRO4B,0


a_zap
	.long	LIMOUTHPRO1
	.long	LIMOUTHPRO2
	.long	LIMOUTHPRO3
	.long	LIMOUTHPRO5
	.long	0

	.long	SIDES1
	.long	SIDES2
	.long	SIDES3
	.long	SIDES4
	.long	SIDES5
	.long	SIDES6
	.long	SIDES7
	.long	SIDES8
	.long	SIDES9
	.long	0

;	.long	LISIDEFLASH


SIDES1	.long	LISIDESPIT1,0
SIDES2	.long	LISIDESPIT2,0
SIDES3	.long	LISIDESPIT3,0
SIDES4	.long	LISIDESPIT4,0
SIDES5	.long	LISIDESPIT5,0
SIDES6	.long	LISIDESPIT6,0
SIDES7	.long	LISIDESPIT7,0
SIDES8	.long	LISIDESPIT8,0
SIDES9	.long	LISIDESPIT9,0


a_shock_wave
	.long	LISHOKWAV1
	.long	LISHOKWAV2
	.long	LISHOKWAV3
	.long	LISHOKWAV4
	.long	LISHOKWAV5
	.long	LISHOKWAV6
	.long	LISHOKWAV7
	.long	LISHOKWAV8
	.long	LISHOKWAV9
	.long	0

LISHOKWAV1
	.long	LISHOKWAV1A,0
LISHOKWAV2
	.long	LISHOKWAV2A,0
LISHOKWAV3
	.long	LISHOKWAV3A,0
LISHOKWAV4
	.long	LISHOKWAV4A,0
LISHOKWAV5
	.long	LISHOKWAV5A,0
LISHOKWAV6
	.long	LISHOKWAV6A,0
LISHOKWAV7
	.long	LISHOKWAV7A,LISHOKWAV7B,0
LISHOKWAV8
	.long	LISHOKWAV8A,0
LISHOKWAV9
	.long	LISHOKWAV9A,0


a_fly_up
	.long	LIHOVR1
	.long	LIHOVR2
	.long	0

	.long	LIHOVR2
	.long	LIHOVR2
	.long	LIHOVR2
	.long	LIHOVR2
	.long	LIHOVR3
	.long	LIHOVR4

j_hair	.long	LIHOVR51
	.long	LIHOVR52
	.long	LIHOVR53
	.long	LIHOVR54
	.long	ani_jump,j_hair


LIHOVR6	.long	LIHOVR6A,0
LIHOVR7	.long	LIHOVR7A,LIHOVR7B,0
LIHOVR8	.long	LIHOVR8A,LIHOVR8B,0
LIHOVR91	.long	LIHOVR9A,LIHOVR9B,LIHOVR9HAIR1A,0
LIHOVR92	.long	LIHOVR9A,LIHOVR9B,LIHOVR9HAIR2A,0
LIHOVR93	.long	LIHOVR9A,LIHOVR9B,LIHOVR9HAIR3A,0

;**************************************************************************

a_fly_backward
	.long	LIHOVRA
	.long	LIHOVRB
j_backw	.long	LIHOVRC1
	.long	LIHOVRC2
	.long	LIHOVRC3
	.long	ani_jump,j_backw


a_fly_forward
	.long	LIHOVR6
	.long	LIHOVR7
	.long	LIHOVR8
j_right	.long	LIHOVR91
	.long	LIHOVR92
	.long	LIHOVR93
	.long	ani_jump,j_right
	.long	0
*
* part 2 = turn around
*
	.long	LIHOVR8
	.long	LIHOVR7
	.long	LIHOVR6
	.long	ani_flip
	.long	ani_jump,a_fly_forward


a_unforward
	.long	LIHOVR8
	.long	LIHOVR7
	.long	LIHOVR6
	.long	ani_calla,new_float_ani
	.long	ani_jump,j_hair

a_unbackoff
	.long	LIHOVRB
	.long	LIHOVRA
	.long	ani_calla,new_float_ani
	.long	ani_jump,j_hair

new_float_ani
	clr	a0
	move	a0,*a13(p_store3),0
	movk	6,a0
	move	a0,*a13(p_anirate),0
	rets


LIHOVR1	.long	LIHOVR1A,0
LIHOVR2	.long	LIHOVR2A,LIHOVR2B,LIHOVR2C,0
LIHOVR3	.long	LIHOVR3A,0
LIHOVR4	.long	LIHOVR4A,0

LIHOVR51	.long	LIHOVR5HAIR1A,LIHOVR5HAIR1B,LIHOVR5A,LIHOVR5B,LIHOVR5C,0
LIHOVR52	.long	LIHOVR5HAIR2A,LIHOVR5HAIR2B,LIHOVR5A,LIHOVR5B,LIHOVR5C,0
LIHOVR53	.long	LIHOVR5HAIR3A,LIHOVR5HAIR3B,LIHOVR5A,LIHOVR5B,LIHOVR5C,0
LIHOVR54	.long	LIHOVR5HAIR4A,LIHOVR5HAIR4B,LIHOVR5A,LIHOVR5B,LIHOVR5C,0


LIHOVRA	.long	LIHOVR10A,LIHOVR10B,0
LIHOVRB	.long	LIHOVR11A,0
LIHOVRC1	.long	LIHOVR12A,LIHOVR11HAIR2A,0
LIHOVRC2	.long	LIHOVR12A,LIHOVR11HAIR3A,0
LIHOVRC3	.long	LIHOVR12A,LIHOVR11HAIR4A,0


a_angle_zap
	.long	LIHOVRPRO1
	.long	LIHOVRPRO2
	.long	LIHOVRPRO3
	.long	ani_sladd,FACELIT	; add object ---> fireball
	.long	LIHOVRPRO4
	.long	0

	.long	ani_calla,slave_inviso
	.long	LIHOVRPRO4
	.long	ani_calla,slave_viso
	.long	LIHOVRPRO4
	.long	ani_calla,slave_inviso
	.long	LIHOVRPRO4

;	.long	ani_calla,slave_viso
;	.long	LIHOVRPRO4
;	.long	ani_calla,slave_inviso
;	.long	LIHOVRPRO4
;	.long	ani_calla,slave_viso
;	.long	LIHOVRPRO4
;	.long	ani_calla,slave_inviso
;	.long	LIHOVRPRO4
;	.long	ani_calla,slave_viso
;	.long	LIHOVRPRO4
	.long	0

	.long	LIHOVRPRO3
	.long	LIHOVRPRO2
	.long	LIHOVRPRO1
	.long	0


LIHOVRPRO1
	.long	LIHOVRPRO1A,LIHOVRPRO1B,LIHOVRPRO1C,0
LIHOVRPRO2
	.long	LIHOVRPRO2A,0
LIHOVRPRO3
	.long	LIHOVRPRO3A,0
LIHOVRPRO4
	.long	LIHOVRPRO4A,LIHOVRPRO4B,0


FACELIT	.long	LIFLASH,0

a_projectile
	.long	LIAFB1
	.long	LIAFB2
	.long	LIAFB3

j_fireball
	.long	LIAFB4
	.long	LIAFB5
	.long	LIAFB6
	.long	ani_jump,j_fireball
	.long	0

	.long	LIAFB7
	.long	LIAFB8
	.long	LIAFB9
	.long	LIABANG1
	.long	LIABANG2
	.long	LIABANG3
	.long	LIABANG4
	.long	LIABANG5
	.long	LIABANG6
	.long	LIABANG7
	.long	LIABANG8
	.long	LIABANG9
	.long	0

LIAFB1	.long	LIASPIT1,0
LIAFB2	.long	LIASPIT2,0
LIAFB3	.long	LIASPIT3,0
LIAFB4	.long	LIASPIT4,0
LIAFB5	.long	LIASPIT5,0
LIAFB6	.long	LIASPIT6,0
LIAFB7	.long	LIASPIT7,0
LIAFB8	.long	LIASPIT8,0
LIAFB9	.long	LIASPIT9,0


LIABANG1	.long	LIAXPLOD1,0
LIABANG2	.long	LIAXPLOD2,0
LIABANG3	.long	LIAXPLOD3,0
LIABANG4	.long	LIAXPLOD4,0
LIABANG5	.long	LIAXPLOD5,0
LIABANG6	.long	LIAXPLOD6,0
LIABANG7	.long	LIAXPLOD7,0
LIABANG8	.long	LIAXPLOD8,0
LIABANG9	.long	LIAXPLOD9,0

a_run	.long	LIRUN1
	.long	LIRUN2
	.long	LIRUN3
	.long	ani_calla,rsnd_footstep
	.long	LIRUN4
	.long	LIRUN5
	.long	LIRUN6
	.long	LIRUN7
	.long	LIRUN8
	.long	ani_calla,rsnd_footstep
	.long	LIRUN9
	.long	LIRUN10
	.long	LIRUN11
	.long	LIRUN12
	.long	ani_jump,a_run
	.long	0			; we need this zero !!


LIRUN1	.long	LIRUN1A,LIRUN1B,0
LIRUN2	.long	LIRUN2A,LIRUN2B,0
LIRUN3	.long	LIRUN3A,0
LIRUN4	.long	LIRUN4A,0
LIRUN5	.long	LIRUN5A,0
LIRUN6	.long	LIRUN6A,LIRUN6B,0
LIRUN7	.long	LIRUN7A,LIRUN7B,0
LIRUN8	.long	LIRUN8A,LIRUN8B,0
LIRUN9	.long	LIRUN9A,LIRUN9B,0
LIRUN10	.long	LIRUN10A,0
LIRUN11	.long	LIRUN11A,0
LIRUN12	.long	LIRUN12A,LIRUN12B,0

a_top 
	.long	ani_swpal
	.long	SPINNER1
	.long	SPINNER2
	.long	SPINNER3
	.long	SPINNER4
	.long	SPINNER5
	.long	SPINNER6
	.long	ani_jump,a_top
	.long	0

	.long	TOPGONE1
	.long	TOPGONE2
	.long	TOPGONE3
	.long	TOPGONE4
	.long	TOPGONE5
	.long	TOPGONE6
	.long	TOPGONE7
	.long	0

SPINNER1	.long	TOP1,0
SPINNER2	.long	TOP2,0
SPINNER3	.long	TOP3,0
SPINNER4	.long	TOP4,0
SPINNER5	.long	TOP5,0
SPINNER6	.long	TOP6,0

TOPGONE1	.long	TOPOUT1,0
TOPGONE2	.long	TOPOUT2,0
TOPGONE3	.long	TOPOUT3,0
TOPGONE4	.long	TOPOUT4,0
TOPGONE5	.long	TOPOUT5,0
TOPGONE6	.long	TOPOUT6,0
TOPGONE7	.long	TOPOUT7,0

;**************************************************************************

a_scared
	.long	LISCARED3
	.long	0

LISCARED3
	.long	LISCARED3A,0

a_thudd
	.long	LITHUD1
	.long	LITHUD2
	.long	LITHUD3
	.long	LITHUD4
	.long	LITHUD5
	.long	LITHUD6
	.long	LITHUD7
	.long	0

LITHUD1	.long	LITHUD1A,0
LITHUD2	.long	LITHUD2A,0
LITHUD3	.long	LITHUD3A,0
LITHUD4	.long	LITHUD4A,0
LITHUD5	.long	LITHUD5A,0
LITHUD6	.long	LITHUD6A,0
LITHUD7	.long	LITHUD7A,0

;**************************************************************************

;a_normal_skel
;	.long	SKELRIP1
;	.long	SKELRIP2
;	.long	SKELRIP3
;	.long	0
;
;a_sg_skel
;	.long	SGOROSKEL1
;	.long	SGOROSKEL2
;	.long	SGOROSKEL3
;	.long	0
;
;SGOROSKEL1
;	.long	SGOROSKEL1A,SGOROSKEL1B,0
;SGOROSKEL2
;	.long	SGOROSKEL2A,SGOROSKEL2B,0
;SGOROSKEL3
;	.long	SGOROSKEL3A,SGOROSKEL3B,0
;SKELRIP1
;	.long	SKELRIP1A,SKELRIP1B,0
;SKELRIP2
;	.long	SKELRIP2A,SKELRIP2B,0
;SKELRIP3
;	.long	SKELRIP3A,SKELRIP3B,0
;********************************************************************


a_hair_wrap
	.long	LILGHAIR1
	.long	LILGHAIR2
	.long	LILGHAIR3
	.long	LILGHAIR4
	.long	LILGHAIR5
	.long	LILGHAIR6
	.long	LILGHAIR7
	.long	LILGHAIR8
	.long	LILGHAIR9
	.long	LILGHAIR10
	.long	LILGHAIR11
	.long	LILGHAIR12
	.long	LILGHAIR13
	.long	0

	.long	LILGHAIR14
	.long	LILGHAIR15
	.long	LILGHAIR16
	.long	LILGHAIR17
	.long	LILGHAIR18
	.long	LILGHAIR19
	.long	LILGHAIR20
	.long	0

LILGHAIR1
	.long	LILGHAIR1A,LIABODY1A,LIABODY1B,0
LILGHAIR2
	.long	LILGHAIR2A,LILGHAIR2B,LIABODY1A,LIABODY1B,0
LILGHAIR3
	.long	LILGHAIR3A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR4
	.long	LILGHAIR4A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR5
	.long	LILGHAIR5A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR6
	.long	LILGHAIR6A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR7
	.long	LILGHAIR7A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR8
	.long	LILGHAIR8A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR9
	.long	LILGHAIR9A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR10
	.long	LILGHAIR10A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR11
	.long	LILGHAIR11A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR12
	.long	LILGHAIR12A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0
LILGHAIR13
	.long	LILGHAIR13A,LIABODY1A,LIABODY1B,LILGHAIR2A,LILGHAIR2B,0


LILGHAIR14
	.long	LILGHAIR14A,LILGHAIR14B,LILGHAIR14C,0
LILGHAIR15
	.long	LILGHAIR15A,LILGHAIR15B,LILGHAIR15C,0


LILGHAIR16
	.long	LILGHAIR16A,LILGHAIR16B
	.long	LIBODYPULL1A,LIBODYPULL1B,LIBODYPULL1C,0
LILGHAIR17
	.long	LILGHAIR17A,LILGHAIR17B,LILGHAIR17C
	.long	LIBODYPULL1A,LIBODYPULL1B,LIBODYPULL1C,0
LILGHAIR18
	.long	LILGHAIR18A,LILGHAIR18B
	.long	LIBODYPULL1A,LIBODYPULL1B,LIBODYPULL1C,0

LILGHAIR19
	.long	LILGHAIR19A
	.long	LIBODYPULL1A,LIBODYPULL1B,LIBODYPULL1C,0

LILGHAIR20
	.long	LILGHAIR20A,LILGHAIR20B,LILGHAIR20C,0

;**************************************************************************

;***************************************************************

a_jade_shook
	.long	ani_offset_xy
	.word	->83,->18
	.long	LIFLIPPED1
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	LISTUMBLE1
	.long	ani_offset_xy
	.word	->6d,>24
	.long	LIKNOCKDOWN2
	.long	ani_offset_xy
	.word	->80,>0a 
	.long	LISTUMBLE1
	.long	ani_jump,a_jade_shook

;***************************************************************
;********************************************************************
a_back_break
	.long	LIBACKBROKEN1
	.long	0

LIBACKBROKEN1
	.long	LIBACKBROKEN3A,LIBACKBROKEN3B,0

;********************************************************************
a_baby
	.long	BABWITCH
	.long	0
	
;********************************************************************
a_big_head
	.long	BHLIA1
	.long	BHLIA2
	.long	BHLIA3
	.long	BHLIA4
	.long	BHLIA5
	.long	0
;********************************************************************
a_half_cutup
	.long	HALF_LICUTUP1
	.long	0
	
HALF_LICUTUP1
	.long	LICUTUP1D,LICUTUP1C,0
;********************************************************************
a_cutup
	.long	LICUTUP1
	.long	0
	
LICUTUP1
	.long	LICUTUP1A,LICUTUP1B,LICUTUP1C,LICUTUP1D,0
;********************************************************************
a_float
	.long	LIFLOAT	
	.long	0
	
LIFLOAT	
	.long	BHLIA1,BHLIA2,BHLIA3,BHLIA4,BHLIA5,0
;********************************************************************
a_pounded
	.long	LINAIL1
	.long	0

;********************************************************************
a_reach
	.long	ani_adjustxy
	.word	-9,0
	.long	LIMOUTH3
	.long	LIMOUTH4
	.long	LIMOUTH5
	.long	LIMOUTH6
	.long	LIMOUTH8
	.long	0

LIMOUTH3
	.long	LIMOUTH3A,LISKELEG1A,LISKELEG1B,LISKELEG1C,0
LIMOUTH4
	.long	LIMOUTH4A,LISKELEG1A,LISKELEG1B,LISKELEG1C,0
LIMOUTH5
	.long	LIMOUTH5A,LISKELEG1A,LISKELEG1B,LISKELEG1C,0
LIMOUTH6
	.long	LIMOUTH6A,LIMOUTH6B,LIMOUTH6C,0
LIMOUTH8
	.long	LIMOUTH8A,0

;********************************************************************
a_skin_rip
	.long	LARIP1
	.long	0
LARIP1	.long	LARIP1A,LARIP1B,0
;********************************************************************
a_stretch
	.long	GROSINDEL2
	.long	GROSINDEL4
	.long	GROSINDEL5
	.long	0
GROSINDEL2
	.long	GROSINDEL2A,GROSINDEL2B,0
GROSINDEL4
	.long	GROSINDEL4A,GROSINDEL4B,0
GROSINDEL5
	.long	GROSINDEL5A,GROSINDEL5B,0
;********************************************************************
a_suk
	.long	SUKLIA1
	.long	SUKLIA3
	.long	SUKLIA4
	.long	SUKLIA5
	.long	0
SUKLIA1
	.long	SUKLIA1A,SUKLIA1B,0
SUKLIA3
	.long	SUKLIA3A,SUKLIA3B,0
SUKLIA4
	.long	SUKLIA4A,0
SUKLIA5
	.long	SUKLIA5A,0
	
;********************************************************************
a_shocked
	.long	LIBZZ1
	.long	LIBZZ2
	.long	LIBZZ3
	.long	LIBZZ4
	.long	0
LIBZZ1	.long	LIBUZZ1,0
LIBZZ2	.long	LIBUZZ2,0
LIBZZ3	.long	LIBUZZ3,0
LIBZZ4	.long	LIBUZZ4,0
;********************************************************************
a_shredded
	.long	ani_adjustxy
	.word	6,6
	.long	LISTUMBLE1

	.long	ani_adjustxy
	.word	-6,-6
	.long	LISTUMBLE2

	.long	ani_adjustxy
	.word	6,6
	.long	LISTUMBLE3

	.long	ani_adjustxy
	.word	-6,-6
	.long	LISTUMBLE2

	.long	ani_jump,a_shredded

	.end
