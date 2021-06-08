* MK3 Johnny Cage

jc_anitab1
	.long	a_stance	;  0 - stance
	.long	a_walkf		;  1 - walk forward
	.long	a_walkb		;  2 - walk backward
	.long	a_turn		;  3 - turn around (standing)
	.long	a_duck		;  4 - duck
	.long	a_duck_turn	;  5 - duck turnaround
	.long	a_duck_block;  6 - duck block
	.long	a_duck_hit	;  7 - duck hit
	.long	a_duck_punch;  8 - duck punch
	.long	a_duck_kick_hi;9 - duck high kick
	.long	a_duck_kick_lo;a - duck low kick
	.long	a_uppercut	;  b - uppercut
	.long	a_block		;  c - block (standing)
	.long	a_victory	;  d - victory
	.long	a_hipunch	;  e - punch high
	.long	a_lopunch	;  f - punch low
	.long	a_elbow		; 10 -
	.long	a_hikick 	; 11 -
	.long	a_lokick 	; 12 -
	.long	a_knee		; 13 -
	.long	a_sweep_kick; 14 -
	.long	a_roundhouse; 15 -
	.long	a_jump		; 16 -
	.long	a_jump_kick	; 17 -
	.long	a_flip_punch; 18 -
	.long	a_flip_kick	; 19 -
	.long	a_fflip		; 1a -
	.long	a_bflip		; 1b -
	.long	a_hit_hi	; 1c -
	.long	a_hit_lo	; 1d -
	.long	a_knockdown	; 1e -
	.long	a_sweep_fall; 1f -
	.long	a_stumble	; 20 -
	.long	a_getup		; 21 -
	.long	a_sweepup	; 22 -
	.long	a_throw		; 23 -
	.long	a_zap		; 24 - 
	.long	a_dizzy		; 25 -

	.long	a_fb_kano	; 26 - flipped by kano
	.long	a_fb_sonya	; 27 - flipped by sonya
	.long	a_fb_jax	; 28 - flipped by jax
	.long	a_fb_ind	; 29 - flipped by indian
	.long	a_fb_jc		; 2a - flipped by johnny cage
	.long	a_fb_swat	; 2b - flipped by swat
	.long	a_fb_lia	; 2c - flipped by lia
	.long	a_fb_robo	; 2d - flipped by robot ninja
	.long	a_fb_robo2	; 2e - flipped by robot ninja 2
	.long	a_fb_lao	; 2f - flipped by kung lao
	.long	a_fb_tusk	; 30 - flipped by tusk
	.long	a_fb_sg     ; 31 - flipped by she goro
	.long	a_fb_st		; 32 - flipped by shang tsung
	.long	a_fb_lk		; 33 - flipped by liu kang
	.long	a_fb_smoke	; 34 - flipped by smoke
	.long	a_fb_kitana	; 35 - flipped by kitana
	.long	a_fb_jade	; 36 - flipped by jade
	.long	a_fb_mileena; 37 - flipped by mileena
	.long	a_fb_nj		; 38 - flipped by male ninja (scorpion)
	.long	a_fb_nj		; 39 - flipped by male ninja (reptile)
	.long	a_fb_nj		; 3a - flipped by male ninja (ermac)
	.long	a_fb_nj		; 3b - flipped by male ninja (oldsz)
	.long	a_fb_nj		; 3c - flipped by male ninja (oldsmoke)
	.long	a_fb_nj		; 3d - flipped by male ninja (noob)
	.long	a_fb_nj		; 3e - flipped by male ninja (rain)
	.long	a_fb_nj		; 3f - flipped by rayden
	.long	a_fb_nj		; 40 - flipped by baraka

	.long	a_afb_kano	; 3d - air flipped by kano
	.long	a_legged	; 3e - legged by sonya
	.long	a_projectile; 3f - projectile animation
	.long	a_shook		; 40 - shook by kano
	.long	a_afb_robo2	; 41 - air flipped by robo2
	.long	a_zoomed	; 42 - zoomed
	.long	a_orb_banged; 43 - hit by reptile's obj thingy
	.long	a_jade_shook; 44 - shook by jade
	.long	a_impaled	; 45 - impaled by baraka
	.long	a_run		; 46 - run
	.long	a_thudd		; 47 - fall down
	.long	a_scared	; 48 - scared by tusk

	.long	a_back_break; 49
	.long	a_baby		; 4a
	.long	a_big_head	; 4b
	.long	a_half_cutup; 4c
	.long	a_cutup		; 4d
	.long	a_float		; 4e
	.long	a_pounded	; 4f
	.long	a_reach		; 50
	.long	a_skin_rip	; 51
	.long	a_stretch	; 52
	.long	a_suk		; 53
	.long	a_shocked	; 54
	.long	a_shredded	; 55

jc_anitab2
	.long	a_shadow_elbow
	.long	a_shadow_kick
	.long	a_back_snap
	.long	a_friend

**************************************************************************

dummy
a_stance
	.long	JCSTANCE1
	.long	JCSTANCE2
	.long	JCSTANCE3
	.long	JCSTANCE4
	.long	JCSTANCE5
	.long	JCSTANCE6
	.long	JCSTANCE7
	.long	JCSTANCE8
	.long	ani_jump,a_stance

JCSTANCE1	.long	JCSTANCEF1,0
JCSTANCE2	.long	JCSTANCEF2,0
JCSTANCE3	.long	JCSTANCEF3,0
JCSTANCE4	.long	JCSTANCEF4,0
JCSTANCE5	.long	JCSTANCEF5,0
JCSTANCE6	.long	JCSTANCEF6,0
JCSTANCE7	.long	JCSTANCEF7,0
JCSTANCE8	.long	JCSTANCEF8,0

**************************************************************************

a_walkf
	.long	JCWALK1
	.long	JCWALK2
	.long	JCWALK3
	.long	JCWALK4
	.long	JCWALK5
	.long	JCWALK6
	.long	JCWALK7
	.long	JCWALK8
	.long	JCWALK9
	.long	ani_jump,a_walkf

**************************************************************************

a_walkb
	.long	JCWALK9
	.long	JCWALK8
	.long	JCWALK7
	.long	JCWALK6
	.long	JCWALK5
	.long	JCWALK4
	.long	JCWALK3
	.long	JCWALK2
	.long	JCWALK1
	.long	ani_jump,a_walkb

JCWALK1		.long	JCWALKF1,0
JCWALK2		.long	JCWALKF2,0
JCWALK3		.long	JCWALKF3,0
JCWALK4		.long	JCWALKF4,0
JCWALK5		.long	JCWALKF5,0
JCWALK6		.long	JCWALKF6,0
JCWALK7		.long	JCWALKF7,0
JCWALK8		.long	JCWALKF8,0
JCWALK9		.long	JCWALKF9,0

**************************************************************************

a_turn
	.long	JCTURN1
	.long	JCTURN2
	.long	ani_flip
	.long	JCTURN1
	.long	0

JCTURN1	.long	JCTURNF1,0
JCTURN2	.long	JCTURNF2,0

*************************************************************************

a_duck
	.long	JCDUCK1
	.long	JCDUCK2
	.long	JCDUCK3
	.long	0

JCDUCK1	.long	JCDUCKF1,0
JCDUCK2	.long	JCDUCKF2,0
JCDUCK3	.long	JCDUCKF3,0

*************************************************************************

a_duck_turn
	.long	JCDUCKTURN1
	.long	JCDUCKTURN2
	.long	ani_flip
	.long	JCDUCKTURN2
	.long	JCDUCKTURN1
	.long	JCDUCK3
	.long	0

JCDUCKTURN1	.long	JCDUCKTURNF1,0
JCDUCKTURN2	.long	JCDUCKTURNF2,0

*************************************************************************

a_duck_block
	.long	JCDUCKBLOCK1
	.long	JCDUCKBLOCK2
	.long	JCDUCKBLOCK3
	.long	0

JCDUCKBLOCK1	.long	JCDUCKBLOCKF1,0
JCDUCKBLOCK2	.long	JCDUCKBLOCKF2,0
JCDUCKBLOCK3	.long	JCDUCKBLOCKF3,0

*************************************************************************

a_duck_hit
	.long	JCDUCKHIT2
	.long	JCDUCKHIT3
	.long	JCDUCKHIT2
	.long	JCDUCKHIT1
	.long	JCDUCK3
	.long	0

JCDUCKHIT1	.long	JCDUCKHITF1,0
JCDUCKHIT2	.long	JCDUCKHITF2,0
JCDUCKHIT3	.long	JCDUCKHITF3,0

*************************************************************************

a_duck_punch
	.long	JCDUCKPUNCH1
	.long	JCDUCKPUNCH2
	.long	JCDUCKPUNCH3
	.long	0
	.long	JCDUCKPUNCH2
	.long	JCDUCKPUNCH1
	.long	JCDUCK3
	.long	0

JCDUCKPUNCH1	.long	JCDUCKPUNCHF1,0
JCDUCKPUNCH2	.long	JCDUCKPUNCHF2,0
JCDUCKPUNCH3	.long	JCDUCKPUNCHF3,0

*************************************************************************

a_duck_kick_hi
	.long	JCDUCKLOKICK1
	.long	JCDUCKLOKICK2
	.long	JCDUCKHIKICK1
	.long	JCDUCKHIKICK2
	.long	0
	.long	JCDUCKHIKICK1
	.long	JCDUCKLOKICK2
	.long	JCDUCKLOKICK1
	.long	JCDUCK3
	.long	0

*************************************************************************

a_duck_kick_lo
	.long	JCDUCKLOKICK1
	.long	JCDUCKLOKICK2
	.long	JCDUCKLOKICK3
	.long	JCDUCKLOKICK4
	.long	0

	.long	JCDUCKLOKICK3
	.long	JCDUCKLOKICK2
	.long	JCDUCKLOKICK1
	.long	JCDUCK3
	.long	0

JCDUCKLOKICK1	.long	JCDUCKLOKICKF1,0
JCDUCKLOKICK2	.long	JCDUCKLOKICKF2,0
JCDUCKLOKICK3	.long	JCDUCKLOKICKF3,0
JCDUCKLOKICK4	.long	JCDUCKLOKICKF4,0
JCDUCKHIKICK1	.long	JCDUCKHIKICKF1,0
JCDUCKHIKICK2	.long	JCDUCKHIKICKF2,0

*************************************************************************

a_uppercut
	.long	JCUPPERCUT1	; probably cut this one
	.long	JCUPPERCUT2
	.long	JCUPPERCUT3
	.long	JCUPPERCUT4
	.long	JCUPPERCUT5
	.long	ani_nosleep	; dont sleep after next frame
	.long	JCUPPERCUT6
	.long	0
	.long	JCUPPERCUT7
	.long	0

JCUPPERCUT1	.long	JCUPPERCUTF1,0
JCUPPERCUT2	.long	JCUPPERCUTF2,0
JCUPPERCUT3	.long	JCUPPERCUTF3,0
JCUPPERCUT4	.long	JCUPPERCUTF4,0
JCUPPERCUT5	.long	JCUPPERCUTF5,0
JCUPPERCUT6	.long	JCUPPERCUTF6,0
JCUPPERCUT7	.long	JCUPPERCUTF7,0

*************************************************************************

a_block
	.long	JCHIBLOCK1
	.long	JCHIBLOCK2
	.long	JCHIBLOCK3
	.long	0

JCHIBLOCK1	.long	JCHIBLOCKF1,0
JCHIBLOCK2	.long	JCHIBLOCKF2,0
JCHIBLOCK3	.long	JCHIBLOCKF3,0

*************************************************************************

a_victory
	.long	JCVICTORY1
	.long	JCVICTORY2
	.long	JCVICTORY3
	.long	JCVICTORY4
	.long	JCVICTORY5
	.long	JCVICTORY6
	.long	0

JCVICTORY1	.long	JCVICTORYF1,0
JCVICTORY2	.long	JCVICTORYF2,0
JCVICTORY3	.long	JCVICTORYF3,0
JCVICTORY4	.long	JCVICTORYF4,0
JCVICTORY5	.long	JCVICTORYF5,0
JCVICTORY6	.long	JCVICTORYF6,0

*************************************************************************

a_hipunch
	.long	JCHIPUNCH1
	.long	JCHIPUNCH2
	.long	JCHIPUNCH3
	.long	0

	.long	JCHIPUNCH4
	.long	JCHIPUNCH5
	.long	JCHIPUNCH6
	.long	0

	.long	JCHIPUNCH5
	.long	JCHIPUNCH4
	.long	ani_jump,a_hipunch+(32*2)
	.long	0
*
* Unhipunch #1
*
	.long	JCHIPUNCH2
	.long	JCHIPUNCH1
	.long	0
*
* Unhipunch #2
*
	.long	JCHIPUNCH6
	.long	0
*
* Hi to Med #1
*
	.long	JCHIPUNCH4
	.long	JCLOPUNCH5
	.long	ani_jump,a_lopunch+(32*6)
	.long	0
*
* Hi to Med #2
*
	.long	JCHIPUNCH5
	.long	JCLOPUNCH2
	.long	ani_jump,a_lopunch+(32*2)
	.long	0

**************************************************************************

a_lopunch
	.long	JCLOPUNCH1
	.long	JCLOPUNCH2
	.long	JCLOPUNCH3
	.long	0

	.long	JCLOPUNCH4
	.long	JCLOPUNCH5
	.long	JCLOPUNCH6
	.long	0

	.long	JCLOPUNCH7
	.long	JCLOPUNCH5
	.long	JCLOPUNCH4
	.long	ani_jump,a_lopunch+(32*2)
	.long	0
*
* Unlopunch #1
*
	.long	JCLOPUNCH2
	.long	JCLOPUNCH1
	.long	0
*
* Unlopunch #2
*
	.long	JCHIPUNCH6
	.long	0
*
* Med to High #1
*
	.long	JCLOPUNCH4
	.long	JCLOPUNCH5
	.long	ani_jump,a_hipunch+(32*6)
	.long	0
*
* Med to High #2
*
	.long	JCLOPUNCH4
	.long	JCHIPUNCH5
	.long	ani_jump,a_hipunch+(32*2)

JCHIPUNCH1	.long	JCHIPUNCHF1,0
JCHIPUNCH2	.long	JCHIPUNCHF2,0
JCHIPUNCH3	.long	JCHIPUNCHF3,0
JCHIPUNCH4	.long	JCHIPUNCHF4,0
JCHIPUNCH5	.long	JCHIPUNCHF5,0
JCHIPUNCH6	.long	JCHIPUNCHF6,0
JCLOPUNCH1	.long	JCLOPUNCHF1,0
JCLOPUNCH2	.long	JCLOPUNCHF2,0
JCLOPUNCH3	.long	JCLOPUNCHF3,0
JCLOPUNCH4	.long	JCLOPUNCHF4,0
JCLOPUNCH5	.long	JCLOPUNCHF5,0
JCLOPUNCH6	.long	JCLOPUNCHF6,0
JCLOPUNCH7	.long	JCLOPUNCHF7,0

*************************************************************************

a_elbow
	.long	JCELBOCOMBO1
	.long	JCELBOCOMBO2
	.long	JCELBOCOMBO3
	.long	0

j_unelb
	.long	JCELBOCOMBO2
	.long	JCELBOCOMBO1
	.long	0

*
* part 3 - combo hit #2
*
	.long	JCELBOCOMBO4
	.long	JCELBOCOMBO5
	.long	0

*
* part 4 - combo hit #3
*
	.long	JCELBOCOMBO6
	.long	JCELBOCOMBO7
	.long	JCELBOCOMBO8
	.long	JCELBOCOMBO9
	.long	JCELBOCOMBO10
	.long	0

JCELBOCOMBO1	.long	JCELBOCOMBOF1,0
JCELBOCOMBO2	.long	JCELBOCOMBOF2,0
JCELBOCOMBO3	.long	JCELBOCOMBOF3,0
JCELBOCOMBO4	.long	JCELBOCOMBOF4,0
JCELBOCOMBO5	.long	JCELBOCOMBOF5,0
JCELBOCOMBO6	.long	JCELBOCOMBOF6,0
JCELBOCOMBO7	.long	JCELBOCOMBOF7,0
JCELBOCOMBO8	.long	JCELBOCOMBOF8,0
JCELBOCOMBO9	.long	JCELBOCOMBOF9,0
JCELBOCOMBO10	.long	JCELBOCOMBOF10,0

*************************************************************************

a_hikick
	.long	JCLOKICK1
	.long	JCLOKICK2
	.long	JCLOKICK3
	.long	JCLOKICK4
	.long	JCLOKICK5
	.long	JCHIKICK1
	.long	0
	.long	JCLOKICK5
	.long	JCLOKICK4
	.long	JCLOKICK3
	.long	JCLOKICK2
	.long	JCLOKICK1
	.long	0

*************************************************************************

a_lokick
	.long	JCLOKICK1
	.long	JCLOKICK2
	.long	JCLOKICK3
	.long	JCLOKICK4
	.long	JCLOKICK5
	.long	JCLOKICK6
	.long	0
	.long	JCLOKICK5
	.long	JCLOKICK4
	.long	JCLOKICK3
	.long	JCLOKICK2
	.long	JCLOKICK1
	.long	0

JCLOKICK1	.long	JCLOKICKF1,0
JCLOKICK2	.long	JCLOKICKF2,0
JCLOKICK3	.long	JCLOKICKF3,0
JCLOKICK4	.long	JCLOKICKF4,0
JCLOKICK5	.long	JCLOKICKF5,0
JCLOKICK6	.long	JCLOKICKF6,0
JCHIKICK1	.long	JCHIKICKF1,0

*************************************************************************

a_knee
	.long	JCKNEEKICK1
	.long	JCKNEEKICK2
	.long	JCKNEEKICK3
	.long	0
	.long	JCKNEEKICK2
	.long	JCKNEEKICK1
	.long	0

JCKNEEKICK1	.long	JCKNEEKICKF1,0
JCKNEEKICK2	.long	JCKNEEKICKF2,0
JCKNEEKICK3	.long	JCKNEEKICKF3,0

*************************************************************************

a_sweep_kick
	.long	JCSWEEPKICK1
	.long	JCSWEEPKICK2
	.long	JCSWEEPKICK3
	.long	ani_calla,sweep_sounds
	.long	JCSWEEPKICK4
	.long	JCSWEEPKICK5
	.long	0
	.long	JCSWEEPKICK6
	.long	JCSWEEPKICK7
	.long	JCSWEEPKICK8
	.long	0

JCSWEEPKICK1	.long	JCSWEEPKICKF1,0
JCSWEEPKICK2	.long	JCSWEEPKICKF2,0
JCSWEEPKICK3	.long	JCSWEEPKICKF3,0
JCSWEEPKICK4	.long	JCSWEEPKICKF4,0
JCSWEEPKICK5	.long	JCSWEEPKICKF5,0
JCSWEEPKICK6	.long	JCSWEEPKICKF6,0
JCSWEEPKICK7	.long	JCSWEEPKICKF7,0
JCSWEEPKICK8	.long	JCSWEEPKICKF8,0

*************************************************************************

a_roundhouse
	.long	JCROUNDHOUSE1
	.long	JCROUNDHOUSE2
	.long	JCROUNDHOUSE3
	.long	JCROUNDHOUSE4
	.long	ani_nosleep
	.long	JCROUNDHOUSE5
	.long	0
	.long	JCROUNDHOUSE6
	.long	JCROUNDHOUSE7
	.long	JCROUNDHOUSE8
	.long	0

JCROUNDHOUSE1	.long	JCROUNDHOUSEF1,0
JCROUNDHOUSE2	.long	JCROUNDHOUSEF2,0
JCROUNDHOUSE3	.long	JCROUNDHOUSEF3,0
JCROUNDHOUSE4	.long	JCROUNDHOUSEF4,0
JCROUNDHOUSE5	.long	JCROUNDHOUSEF5,0
JCROUNDHOUSE6	.long	JCROUNDHOUSEF6,0
JCROUNDHOUSE7	.long	JCROUNDHOUSEF7,0
JCROUNDHOUSE8	.long	JCROUNDHOUSEF8,0

*************************************************************************

a_jump
	.long	JCJUMP1
	.long	JCJUMP2
	.long	JCJUMP3
	.long	0

JCJUMP1	.long	JCJUMPF1,0
JCJUMP2	.long	JCJUMPF2,0
JCJUMP3	.long	JCJUMPF3,0

*************************************************************************

a_jump_kick
	.long	JCJUMPKICK1
	.long	JCJUMPKICK2
	.long	JCJUMPKICK3
	.long	0
	.long	JCJUMPKICK2
	.long	JCJUMPKICK1
	.long	0

JCJUMPKICK1	.long	JCJUMPKICKF1,0
JCJUMPKICK2	.long	JCJUMPKICKF2,0
JCJUMPKICK3	.long	JCJUMPKICKF3,0

*************************************************************************

a_flip_punch
	.long	JCFLIPUNCH1
	.long	JCFLIPUNCH2
	.long	JCFLIPUNCH3
	.long	0
	.long	JCFLIPUNCH2
	.long	JCFLIPUNCH1
	.long	0

JCFLIPUNCH1	.long	JCFLIPUNCHF1,0
JCFLIPUNCH2	.long	JCFLIPUNCHF2,0
JCFLIPUNCH3	.long	JCFLIPUNCHF3,0

*************************************************************************

a_flip_kick
	.long	JCFLIPKICK1
	.long	JCFLIPKICK2
	.long	JCFLIPKICK3
	.long	0
	.long	JCFLIPKICK2
	.long	JCFLIPKICK1
	.long	0

JCFLIPKICK1	.long	JCFLIPKICKF1,0
JCFLIPKICK2	.long	JCFLIPKICKF2,0
JCFLIPKICK3	.long	JCFLIPKICKF3,0

*************************************************************************

a_fflip
	.long	JCJUMPFLIP1
	.long	JCJUMPFLIP2
	.long	JCJUMPFLIP3
	.long	JCJUMPFLIP4
	.long	JCJUMPFLIP5
	.long	JCJUMPFLIP6
	.long	JCJUMPFLIP7
	.long	JCJUMPFLIP8
	.long	ani_jump,a_fflip+32

*************************************************************************

a_bflip
	.long	JCJUMPFLIP1
	.long	JCJUMPFLIP8
	.long	JCJUMPFLIP7
	.long	JCJUMPFLIP6
	.long	JCJUMPFLIP5
	.long	JCJUMPFLIP4
	.long	JCJUMPFLIP3
	.long	JCJUMPFLIP2
	.long	ani_jump,a_bflip+32

JCJUMPFLIP1	.long	JCJUMPFLIPF1,0
JCJUMPFLIP2	.long	JCJUMPFLIPF2,0
JCJUMPFLIP3	.long	JCJUMPFLIPF3,0
JCJUMPFLIP4	.long	JCJUMPFLIPF4,0
JCJUMPFLIP5	.long	JCJUMPFLIPF5,0
JCJUMPFLIP6	.long	JCJUMPFLIPF6,0
JCJUMPFLIP7	.long	JCJUMPFLIPF7,0
JCJUMPFLIP8	.long	JCJUMPFLIPF8,0

*************************************************************************

a_hit_hi
	.long	JCHIHIT2
	.long	JCHIHIT3
	.long	JCHIHIT2
	.long	JCHIHIT1
	.long	0

JCHIHIT1	.long	JCHIHITF1,0
JCHIHIT2	.long	JCHIHITF2,0
JCHIHIT3	.long	JCHIHITF3,0

*************************************************************************

a_hit_lo
	.long	JCLOHIT2
	.long	JCLOHIT3
	.long	JCLOHIT2
	.long	JCLOHIT1
	.long	0

JCLOHIT1	.long	JCLOHITF1,0
JCLOHIT2	.long	JCLOHITF2,0
JCLOHIT3	.long	JCLOHITF3,0

*************************************************************************

a_knockdown
	.long	JCKNOCKDOWN1
	.long	JCKNOCKDOWN2
	.long	JCKNOCKDOWN3
	.long	JCKNOCKDOWN4
	.long	JCKNOCKDOWN5
	.long	0
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

JCKNOCKDOWN1	.long	JCKNOCKDOWNF1,0
JCKNOCKDOWN2	.long	JCKNOCKDOWNF2,0
JCKNOCKDOWN3	.long	JCKNOCKDOWNF3,0
JCKNOCKDOWN4	.long	JCKNOCKDOWNF4,0
JCKNOCKDOWN5	.long	JCKNOCKDOWNF5,0
JCKNOCKDOWN6	.long	JCKNOCKDOWNF6,0
JCKNOCKDOWN7	.long	JCKNOCKDOWNF7,0

*************************************************************************

a_sweep_fall
	.long	JCSWEEPFALL1
	.long	JCSWEEPFALL2
	.long	JCSWEEPFALL3
	.long	JCSWEEPFALL4
	.long	JCSWEEPFALL5
	.long	0
	.long	JCSWEEPFALL6
	.long	0

JCSWEEPFALL1	.long	JCSWEEPFALLF1,0
JCSWEEPFALL2	.long	JCSWEEPFALLF2,0
JCSWEEPFALL3	.long	JCSWEEPFALLF3,0
JCSWEEPFALL4	.long	JCSWEEPFALLF4,0
JCSWEEPFALL5	.long	JCSWEEPFALLF5,0
JCSWEEPFALL6	.long	JCSWEEPFALLF6,0

*************************************************************************

a_stumble
	.long	JCSTUMBLE1
	.long	JCSTUMBLE2
	.long	JCSTUMBLE3
	.long	JCSTUMBLE4
	.long	JCSTUMBLE5
	.long	JCSTUMBLE6
	.long	JCSTUMBLE7
	.long	0

j_stumble
	.long	JCSTUMBLE1
	.long	JCSTUMBLE2
	.long	JCSTUMBLE3
	.long	JCSTUMBLE4
	.long	JCSTUMBLE5
	.long	JCSTUMBLE6
	.long	JCSTUMBLE7
	.long	0

JCSTUMBLE1	.long	JCSTUMBLEF1,0
JCSTUMBLE2	.long	JCSTUMBLEF2,0
JCSTUMBLE3	.long	JCSTUMBLEF3,0
JCSTUMBLE4	.long	JCSTUMBLEF4,0
JCSTUMBLE5	.long	JCSTUMBLEF5,0
JCSTUMBLE6	.long	JCSTUMBLEF6,0
JCSTUMBLE7	.long	JCSTUMBLEF7,0

*************************************************************************

a_getup
	.long	JCGETUP1
	.long	JCGETUP2
	.long	JCGETUP3
	.long	JCGETUP4
	.long	JCGETUP5
	.long	JCGETUP6
	.long	0

JCGETUP1	.long	JCGETUPF1,0
JCGETUP2	.long	JCGETUPF2,0
JCGETUP3	.long	JCGETUPF3,0
JCGETUP4	.long	JCGETUPF4,0
JCGETUP5	.long	JCGETUPF5,0
JCGETUP6	.long	JCGETUPF6,0

*************************************************************************

a_sweepup
	.long	JCSWEEPUP1
	.long	JCSWEEPUP2
	.long	JCSWEEPUP3
	.long	JCSWEEPUP4
	.long	JCSWEEPUP5
	.long	JCSWEEPUP6
	.long	0

JCSWEEPUP1	.long	JCSWEEPUPF1,0
JCSWEEPUP2	.long	JCSWEEPUPF2,0
JCSWEEPUP3	.long	JCSWEEPUPF3,0
JCSWEEPUP4	.long	JCSWEEPUPF4,0
JCSWEEPUP5	.long	JCSWEEPUPF5,0
JCSWEEPUP6	.long	JCSWEEPUPF6,0

*************************************************************************

a_throw
	.long	JCFLIP1
	.long	JCFLIP2
	.long	0
	.long	JCFLIP3
	.long	JCFLIP4
	.long	JCFLIP5
	.long	JCFLIP6
	.long	JCFLIP7
	.long	0
	.long	JCFLIP8
	.long	JCFLIP9
	.long	0

JCFLIP1	.long	JCFLIPF1,0
JCFLIP2	.long	JCFLIPF2,0
JCFLIP3	.long	JCFLIPF3,0
JCFLIP4	.long	JCFLIPF4,0
JCFLIP5	.long	JCFLIPF5,0
JCFLIP6	.long	JCFLIPF6,0
JCFLIP7	.long	JCFLIPF7,0
JCFLIP8	.long	JCFLIPF8,0
JCFLIP9	.long	JCFLIPF9,0

*************************************************************************

a_zap
	.long	JCORBTOSS1
	.long	ani_sladd,GREENBALL1	; introduce projectile obj
	.long	JCORBTOSS2
	.long	JCORBTOSS3
	.long	0
	.long	JCORBTOSS4
	.long	JCORBTOSS5
	.long	JCORBTOSS6
	.long	0

JCORBTOSS1	.long	JCORBTOSSF1,0
JCORBTOSS2	.long	JCORBTOSSF2,0
JCORBTOSS3	.long	JCORBTOSSF3,0
JCORBTOSS4	.long	JCORBTOSSF4,0
JCORBTOSS5	.long	JCORBTOSSF5,0
JCORBTOSS6	.long	JCORBTOSSF6,0

*************************************************************************

a_dizzy
	.long	JCSTUNNED1
	.long	JCSTUNNED2
	.long	JCSTUNNED3
	.long	JCSTUNNED4
	.long	JCSTUNNED5
	.long	JCSTUNNED6
	.long	JCSTUNNED7
	.long	ani_jump,a_dizzy

JCSTUNNED1	.long	JCSTUNNEDF1,0
JCSTUNNED2	.long	JCSTUNNEDF2,0
JCSTUNNED3	.long	JCSTUNNEDF3,0
JCSTUNNED4	.long	JCSTUNNEDF4,0
JCSTUNNED5	.long	JCSTUNNEDF5,0
JCSTUNNED6	.long	JCSTUNNEDF6,0
JCSTUNNED7	.long	JCSTUNNEDF7,0

*************************************************************************

a_fb_kano
	.long	ani_offset_xy
	.word	->3f,->1b
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->1b,->31
	.long	JCFLIPPED2
	.long	ani_offset_xy
 	.word	>4c,->37
	.long	JCFLIPPED3
	.long	0

	.long	JCFLIPPED4
	.long	JCFLIPPED5
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

JCFLIPPED1	.long	JCFLIPPEDF1,0
JCFLIPPED2	.long	JCFLIPPEDF2,0
JCFLIPPED3	.long	JCFLIPPEDF3,0
JCFLIPPED4	.long	JCFLIPPEDF4,0
JCFLIPPED5	.long	JCFLIPPEDF5,0

*************************************************************************

a_fb_sonya
	.long	ani_offset_xy
	.word	->31,->0e
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->1b,>01
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>26,->0a
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>68,->1b
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>a7,->1f
	.long	JCFLIPPED4
	.long	0

	.long	JCFLIPPED5
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_jax
	.long	ani_offset_xy
	.word	->4b,->27
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->30,->3e
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>18,->4c
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>40,->3a
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>53,->03
	.long	JCFLIPPED5
	.long	ani_offset_xy
	.word	>48,>00
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_ind
	.long	ani_offset_xy
	.word	->58,->1d
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->42,->3c
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	->09,->5c
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>38,->54
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>55,->18
	.long	JCFLIPPED5
	.long	ani_offset_xy
	.word	>54,>0c
	.long	JCKNOCKDOWN6
	.long	0

*************************************************************************

a_fb_jc

*************************************************************************

a_fb_swat
	.long	ani_offset_xy
	.word	->4f,->16
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->43,->44
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>30,->5b
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>63,->23
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>48,->02
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_lia
	.long	ani_offset_xy
	.word	->64,->0d
	.long	JCSTUMBLE1
	.long	ani_offset_xy
	.word	->81,->0d
	.long	JCSTUMBLE1

	.long	ani_offset_xy
	.word	->7f,->29
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->5d,->48
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->2e,->54
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	>16,->5a
	.long	JCFLIPPED1

	.long	ani_offset_xy
	.word	>a8,>12
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>8d,>00
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_robo
	.long	ani_offset_xy
	.word	->4e,->16
	.long	JCFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->51,->36
	.long	JCFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->42,->48
	.long	JCFLIPPED2		; 3

	.long	ani_offset_xy
	.word	>00,->6e
	.long	JCFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>3b,->73
	.long	JCFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>64,->61
	.long	JCFLIPPED4		; 6

	.long	ani_offset_xy
	.word	>7f,->1e
	.long	JCFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>59,->11
	.long	JCKNOCKDOWN7		; 8
	.long	0

*************************************************************************

a_fb_robo2
	.long	ani_offset_xy
	.word	->36,->0e
	.long	JCSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->32,->28
	.long	JCFLIPPED1		; 2
	.long	ani_offset_xy
	.word	->15,->29
	.long	JCFLIPPED2		; 3
	.long	ani_offset_xy
	.word	>1c,->24
	.long	JCFLIPPED3		; 4
	.long	ani_offset_xy
	.word	>22,->0b
	.long	JCFLIPPED4		; 5
	.long	ani_offset_xy
	.word	>09,>05
	.long	JCFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->18,->12
	.long	JCKNOCKDOWN7		; 7
	.long	0

*************************************************************************

a_fb_lao
	.long	ani_offset_xy
	.word	->34,>13
	.long	JCSTUMBLE1		; 1
	.long	ani_offset_xy
	.word	->1e,>2e
	.long	JCSTUMBLE1		; 2
	.long	ani_flip
	.long	ani_offset_xy
	.word	->2b,>20
	.long	JCFLIPPED1		; 3
	.long	ani_offset_xy
	.word	->54,->12
	.long	JCFLIPPED2		; 4
	.long	ani_offset_xy
	.word	->2c,->57
	.long	JCFLIPPED3		; 5
	.long	ani_offset_xy
	.word	>14,->6d
	.long	JCFLIPPED4		; 6
	.long	ani_offset_xy
	.word	>19,->74
	.long	JCFLIPPED5		; 7
	.long	ani_offset_xy
	.word	>54,->70
	.long	JCFLIPPED5		; 8
	.long	ani_offset_xy
	.word	>60,->56
	.long	JCFLIPPED5		; 9
	.long	ani_offset_xy
	.word	>77,>02
	.long	JCFLIPPED5		; 10
	.long	0

*************************************************************************

a_fb_tusk
	.long	ani_offset_xy
	.word	->6e,->07
	.long	JCFLIPPED1		; 1
	.long	ani_offset_xy
	.word	->5d,->4a
	.long	JCFLIPPED2		; 2
	.long	ani_offset_xy
	.word	->0c,->81
	.long	JCFLIPPED3		; 3
	.long	ani_offset_xy
	.word	>40,->57
	.long	JCFLIPPED4		; 4
	.long	ani_offset_xy
	.word	>44,->15
	.long	JCFLIPPED5		; 5

	.long	ani_offset_xy
	.word	>0f,>1e
	.long	JCFLIPPED5		; 6
	.long	ani_offset_xy
	.word	->31,>01
  	.long	JCKNOCKDOWN6		; 7
	.long	ani_offset_xy
	.word	->75,->0c
	.long	JCFLIPPED1		; 8
	.long	ani_offset_xy
	.word	->54,->4f
	.long	JCFLIPPED2		; 9
	.long	ani_offset_xy
	.word	>26,->72
	.long	JCFLIPPED3		; 10 

	.long	ani_offset_xy
	.word	>65,->05
	.long	JCFLIPPED5		; 11
	.long	ani_offset_xy
	.word	>64,>09
  	.long	JCKNOCKDOWN6		; 12
	.long	0

*************************************************************************

a_fb_sg
	.long	ani_offset_xy
	.word	->3d,->30
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->08,->52
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>01,->59
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>18,->4f
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>1a,->28
	.long	JCFLIPPED3
	.long	ani_flip
	.long	ani_offset_xy
	.word	->1b,->11
  	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_st
	.long	ani_offset_xy
	.word	->4c,>00
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->41,>07
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->2a,>01
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	->07,>03
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>0e,>25
	.long	JCFLIPPED4

	.long	ani_offset_xy
	.word	->0f,->04
	.long	JCKNOCKDOWN6
	.long	ani_offset_xy
	.word	->23,->04
	.long	JCKNOCKDOWN6
	.long	ani_offset_xy
	.word	->38,->04
	.long	JCKNOCKDOWN6

	.long	ani_offset_xy
	.word	->60,>19
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->67,->0b
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->3c,->4c
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>2b,->41
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>4c,->18
	.long	JCFLIPPED5
	.long	ani_offset_xy
	.word	>5b,->08
	.long	JCKNOCKDOWN6
	.long	0

*************************************************************************

a_fb_lk
	.long	ani_offset_xy
	.word	->44,->0e
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->3b,->0c
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->13,>02
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>10,>00
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>37,>01
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>88,->1f
	.long	JCFLIPPED4
	.long	0

	.long	JCFLIPPED5
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_kitana
	.long	ani_offset_xy
	.word	->20,->23
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->08,->40
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>32,->2d
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>3d,>0c
	.long	JCFLIPPED4
	.long	0

	.long	JCFLIPPED4
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	0

*************************************************************************

a_fb_jade
	.long	ani_offset_xy
	.word	->5a,>04
	.long	JCKNOCKDOWN1
	.long	ani_offset_xy
	.word	->5b,->21
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->43,->6c
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	->05,->6d
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>5e,->6c
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>81,->3d
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>89,->0c
	.long	JCFLIPPED5
	.long	0

	.long	JCFLIPPED4
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	0

*************************************************************************

a_fb_mileena
	.long	ani_offset_xy
	.word	->3a,->01
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->29,>07
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->1e,>01
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>0e,->1a
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>63,->34
	.long	JCFLIPPED4
	.long	0

	.long	JCFLIPPED5
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_fb_nj
	.long	ani_offset_xy
	.word	->49,>06
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->3c,>0e
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->28,>17
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>00,>16
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>0e,>0e
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>5d,->17
	.long	JCFLIPPED4
	.long	0

	.long	JCFLIPPED5
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_afb_kano
	.long	ani_offset_xy
	.word	->40,->1b
	.long	JCFLIPPED1

	.long	ani_offset_xy
	.word	->3c,->0b
	.long	JCKNOCKDOWN4

	.long	ani_offset_xy
 	.word	->59,>22
	.long	JCKNOCKDOWN5
	.long	0
*
* fall down solo
*
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_legged
	.long	ani_offset_xy
	.word	->5d,->07
	.long	JCKNOCKDOWN1

	.long	ani_offset_xy
	.word	->51,->30
	.long	JCFLIPPED1

	.long	ani_offset_xy
	.word	->0c,->4a
	.long	JCFLIPPED3

	.long	ani_offset_xy
	.word	>37,->2d
	.long	JCFLIPPED4

	.long	ani_offset_xy
	.word	>5e,>00
	.long	JCFLIPPED5
	.long	0

*************************************************************************

a_projectile
	.long	GREENBALL1
	.long	GREENBALL2
	.long	GREENBALL3

j_jczap
	.long	GREENBALL4
	.long	GREENBALL5
	.long	GREENBALL6
	.long	GREENBALL7
	.long	GREENBALL8
	.long	GREENBALL9
	.long	GREENBALL10
	.long	ani_jump,j_jczap
	.long	0

	.long	ani_swpal
	.long	GREENBALL11
	.long	GREENBALL12
	.long	GREENBALL13
	.long	GREENBALL14
	.long	GREENBALL15
	.long	GREENBALL16
	.long	0

GREENBALL1	.long	GREENBALLF1,0	;1 - 3 toss from hand
GREENBALL2	.long	GREENBALLF2,0
GREENBALL3	.long	GREENBALLF3,0
GREENBALL4	.long	GREENBALLF4,0	;4 - 10 in flight
GREENBALL5	.long	GREENBALLF5,0
GREENBALL6	.long	GREENBALLF6,0
GREENBALL7	.long	GREENBALLF7,0
GREENBALL8	.long	GREENBALLF8,0
GREENBALL9	.long	GREENBALLF9,0
GREENBALL10	.long	GREENBALLF10,0
GREENBALL11	.long	GREENBALLF11,0	;11 - 16 explode
GREENBALL12	.long	GREENBALLF12,0
GREENBALL13	.long	GREENBALLF13,0
GREENBALL14	.long	GREENBALLF14,0
GREENBALL15	.long	GREENBALLF15,0
GREENBALL16	.long	GREENBALLF16,0

*************************************************************************

a_shook
	.long	ani_offset_xy
	.word	->4a,->0d
	.long	JCSTUMBLE2	; 3

	.long	ani_offset_xy
	.word	->31,->26
	.long	JCSTUMBLE2	; 4

	.long	ani_offset_xy
	.word	->1b,->24
	.long	JCSTUMBLE2	; 5
	.long	0

; loop
	.long	ani_offset_xy
	.word	->1d,->26
	.long	JCSTUMBLE2	; 6

	.long	ani_offset_xy
	.word	->2d,->30
	.long	JCSTUMBLE2	; 7

	.long	ani_offset_xy
	.word	->3d,->34	
	.long	JCSTUMBLE2	; 8

	.long	ani_offset_xy
	.word	->2d,->30
	.long	JCSTUMBLE2	; 7
	.long	0

*************************************************************************

a_fb_smoke
a_afb_robo2
	.long	ani_offset_xy
	.word	->1e,->38
	.long	JCFLIPPED2
	.long	ani_offset_xy
	.word	>08,->48
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>2f,->41
	.long	JCFLIPPED3
	.long	ani_offset_xy
	.word	>4a,->26
	.long	JCFLIPPED4
	.long	ani_offset_xy
	.word	>57,>02
	.long	JCKNOCKDOWN6
	.long	ani_offset_xy
	.word	>6b,>30
	.long	JCKNOCKDOWN6
	.long	0

*************************************************************************

a_zoomed
	.long	ani_offset_xy
	.word	>55,->1c
	.long	JCKNOCKDOWN3	; 1

	.long	ani_offset_xy
	.word	>57,>01
	.long	JCKNOCKDOWN4	; 2

	.long	ani_offset_xy
	.word	>20,>16
	.long	JCKNOCKDOWN5	; 3

	.long	ani_offset_xy
	.word	->37,>17
	.long	JCKNOCKDOWN5	; 4

	.long	ani_offset_xy
	.word	->8c,->13
	.long	JCFLIPPED1	; 5

	.long	ani_offset_xy
	.word	->2e,->5e
	.long	JCFLIPPED3	; 6
	.long	0

	.long	JCFLIPPED3
	.long	JCFLIPPED4
	.long	JCFLIPPED5
	.long	JCKNOCKDOWN5
	.long	JCKNOCKDOWN6
	.long	JCKNOCKDOWN7
	.long	0

*************************************************************************

a_orb_banged
	.long	JCFLIPPED1
	.long	JCFLIPPED2
	.long	JCFLIPPED3
	.long	JCFLIPPED4
	.long	0

*************************************************************************

a_jade_shook
	.long	ani_offset_xy
	.word	->86,->27
	.long	JCFLIPPED1
	.long	ani_offset_xy
	.word	->87,>0d
	.long	JCSTUMBLE1
	.long	ani_offset_xy
	.word	->6d,>0d
	.long	JCKNOCKDOWN2
	.long	ani_offset_xy
	.word	->87,>0d
	.long	JCSTUMBLE1
	.long	ani_jump,a_jade_shook

*************************************************************************

a_impaled
	.long	ani_adjustxy
	.word	->60,>00
	.long	JCKNOCKDOWN1

	.long	ani_adjustxy
	.word	>00,->18
	.long	JCKNOCKDOWN1

	.long	ani_adjustxy
	.word	>00,->18
	.long	JCKNOCKDOWN1

	.long	ani_adjustxy
	.word	>10,->08
	.long	JCKNOCKDOWN1

	.long	0

	.long	JCKNOCKDOWN1
	.long	JCJUMPFLIP1
	.long	JCFLIPPED1

	.long	JCJUMPFLIP1
	.long	JCKNOCKDOWN1
	.long	JCJUMPFLIP1
	.long	JCFLIPPED1
	.long	0

*************************************************************************

a_run
	.long	JCRUN1
	.long	JCRUN2
	.long	JCRUN3
	.long	JCRUN4
	.long ani_calla,rsnd_footstep
	.long	JCRUN5
	.long	JCRUN6
	.long	JCRUN7
	.long	JCRUN8
	.long	JCRUN9
	.long ani_calla,rsnd_footstep
	.long	JCRUN10
	.long	JCRUN11
	.long	JCRUN12
	.long	ani_jump,a_run

JCRUN1	.long	JCRUNF1,0
JCRUN2	.long	JCRUNF2,0
JCRUN3	.long	JCRUNF3,0
JCRUN4	.long	JCRUNF4,0
JCRUN5	.long	JCRUNF5,0
JCRUN6	.long	JCRUNF6,0
JCRUN7	.long	JCRUNF7,0
JCRUN8	.long	JCRUNF8,0
JCRUN9	.long	JCRUNF9,0
JCRUN10	.long	JCRUNF10,0
JCRUN11	.long	JCRUNF11,0
JCRUN12	.long	JCRUNF12,0

*************************************************************************

a_thudd
	.long	JCTHUD1
	.long	JCTHUD2
	.long	JCTHUD3
	.long	JCTHUD4
	.long	JCTHUD5
	.long	JCTHUD6
	.long	JCTHUD7
	.long	0

JCTHUD1	.long	JCTHUDF1,0
JCTHUD2	.long	JCTHUDF2,0
JCTHUD3	.long	JCTHUDF3,0
JCTHUD4	.long	JCTHUDF4,0
JCTHUD5	.long	JCTHUDF5,0
JCTHUD6	.long	JCTHUDF6,0
JCTHUD7	.long	JCTHUDF7,0

*************************************************************************

a_scared
	.long	JCSCARED3
	.long	0

JCSCARED3	.long	JCSCAREDF3,0

*************************************************************************

a_back_break
	.long	JCBACKBROKEN3
	.long	0

JCBACKBROKEN3	.long	JCBACKBROKENF3,0

*************************************************************************

a_baby
	.long	BABJC
	.long	0

BABJC	.long	BABJCF,0

*************************************************************************

a_big_head
	.long	BHJC1
	.long	BHJC2
	.long	BHJC3
	.long	BHJC4
	.long	BHJC5
	.long	0

BHJC1	.long	BHJCF1,0
BHJC2	.long	BHJCF2,0
BHJC3	.long	BHJCF3,0
BHJC4	.long	BHJCF4,0
BHJC5	.long	BHJCF5,0

*************************************************************************

a_half_cutup
	.long	HALF_JCCUTUP1
	.long	0
	
HALF_JCCUTUP1	.long	JCCUTUPF1D,0

*************************************************************************

a_cutup
	.long	JCCUTUP1A
	.long	JCCUTUP1B
	.long	JCCUTUP1C
	.long	JCCUTUP1D
	.long	0
	
JCCUTUP1A	.long	JCCUTUPF1A,0
JCCUTUP1B	.long	JCCUTUPF1B,0
JCCUTUP1C	.long	JCCUTUPF1C,0
JCCUTUP1D	.long	JCCUTUPF1D,0

*************************************************************************

a_float
	.long	JCSTUNNED2
	.long	0

*************************************************************************

a_pounded
	.long	JCTHUD1_SUB
	.long	0

*************************************************************************

a_reach
	.long	ani_adjustxy
	.word	-5,0
	.long	JCMOUTH1
	.long	JCMOUTH2
	.long	JCMOUTH3
	.long	JCMOUTH4
	.long	JCMOUTH5
	.long	JCMOUTH6
	.long	JCMOUTH7
	.long	JCMOUTH8
	.long	0

JCMOUTH1	.long	JCMOUTHF1,0
JCMOUTH2	.long	JCMOUTHF2,0
JCMOUTH3	.long	JCMOUTHF3,0
JCMOUTH4	.long	JCMOUTHF4,0
JCMOUTH5	.long	JCMOUTHF5,0
JCMOUTH6	.long	JCMOUTHF6,0
JCMOUTH7	.long	JCMOUTHF7,0
JCMOUTH8	.long	JCMOUTHF8,0

*************************************************************************

a_skin_rip
	.long	JCRIP1
	.long	0

JCRIP1	.long	JCRIPF1,0

*************************************************************************

a_stretch
	.long	GROJC2
	.long	GROJC4
	.long	GROJC5
	.long	0

GROJC2	.long	GROJCF2,0
GROJC4	.long	GROJCF4,0
GROJC5	.long	GROJCF5,0

*************************************************************************

a_suk
	.long	SUKJC1
	.long	SUKJC3
	.long	SUKJC4
	.long	SUKJC5
	.long	SUKJC6
	.long	0

SUKJC1	.long	SUKJCF1,0
SUKJC3	.long	SUKJCF3,0
SUKJC4	.long	SUKJCF4,0
SUKJC5	.long	SUKJCF5,0
SUKJC6	.long	SUKJCF6,0

*************************************************************************

a_shocked
	.long	JCSCARED3
	.long	JCSCARED3
	.long	JCSCARED3
	.long	JCSCARED3
	.long	0

*************************************************************************

a_shredded
	.long	ani_adjustxy
	.word	6,6
	.long	JCSTUMBLE1

	.long	ani_adjustxy
	.word	-6,-6
	.long	JCSTUMBLE2

	.long	ani_adjustxy
	.word	6,6
	.long	JCSTUMBLE3

	.long	ani_adjustxy
	.word	-6,-6
	.long	JCSTUMBLE2

	.long	ani_jump,a_shredded

*************************************************************************

a_shadow_elbow
	.long	JCSHADOWELBOW1
	.long	JCSHADOWELBOW2
	.long	JCSHADOWELBOW3
	.long	JCSHADOWELBOW4
	.long	0
	.long	JCSHADOWELBOW3
	.long	JCJUMP1
	.long	0

JCSHADOWELBOW1	.long	JCSHADOWELBOWF1,0
JCSHADOWELBOW2	.long	JCSHADOWELBOWF2,0
JCSHADOWELBOW3	.long	JCSHADOWELBOWF3,0
JCSHADOWELBOW4	.long	JCSHADOWELBOWF4,0

*************************************************************************

a_shadow_kick
	.long	JCLOKICK2
	.long	JCLOKICK4
	.long	JCLOKICK5
	.long	JCHIKICK1
	.long	0

	.long	JCLOKICK5
	.long	JCLOKICK4
	.long	JCLOKICK3
	.long	JCLOKICK2
	.long	JCLOKICK1
	.long	0

*************************************************************************

a_back_snap
	.long	JCFATAL1
	.long	JCFATAL2
	.long	JCFATAL3
	.long	JCFATAL4
	.long	JCFATAL5
	.long	JCFATAL6
	.long	JCFATAL7
	.long	JCFATAL8
	.long	JCFATAL9
	.long	JCFATAL10

JCFATAL1	.long	JCFATAF1,0
JCFATAL2	.long	JCFATAF2,0
JCFATAL3	.long	JCFATAF3,0
JCFATAL4	.long	JCFATAF4,0
JCFATAL5	.long	JCFATAF5,0
JCFATAL6	.long	JCFATAF6,0
JCFATAL7	.long	JCFATAF7,0
JCFATAL8	.long	JCFATAF8,0
JCFATAL9	.long	JCFATAF9,0
JCFATAL10	.long	JCFATAF10,0

*************************************************************************

a_friend
	.long	JCFRIENDSHIP1
	.long	JCFRIENDSHIP2
	.long	JCFRIENDSHIP3
	.long	JCFRIENDSHIP4
	.long	JCFRIENDSHIP5
	.long	JCFRIENDSHIP6
	.long	JCFRIENDSHIP7
	.long	JCFRIENDSHIP8
	.long	JCFRIENDSHIP9
	.long	JCFRIENDSHIP10

JCFRIENDSHIP1	.long	JCFRIENDSHIPF1,0
JCFRIENDSHIP2	.long	JCFRIENDSHIPF2,0
JCFRIENDSHIP3	.long	JCFRIENDSHIPF3,0
JCFRIENDSHIP4	.long	JCFRIENDSHIPF4,0
JCFRIENDSHIP5	.long	JCFRIENDSHIPF5,0
JCFRIENDSHIP6	.long	JCFRIENDSHIPF6,0
JCFRIENDSHIP7	.long	JCFRIENDSHIPF7,0
JCFRIENDSHIP8	.long	JCFRIENDSHIPF8,0
JCFRIENDSHIP9	.long	JCFRIENDSHIPF9,0
JCFRIENDSHIP10	.long	JCFRIENDSHIPF10,0

*************************************************************************

	.end
