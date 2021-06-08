#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkarmor.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Armory
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_armory	
	.extern	calla_tomb	
	.extern	calla_lair	

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern	MARFLOR_P	
	.extern	armory1_CLT	 
	.extern	LAVA_P		 

	.extern TOMB_CLT	 
	.extern TOMBFLR_p	 
	.extern BATORG_p	 
	.extern SMALL_p		 
	.extern MEDIUM_p	 
	.extern STBREAK_P	 

	.extern	gorocave_CLT 
	.extern	goro_CLT	 

	.extern spiker_p	  

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2

armory_anims:
lair_anims:
tomb_anims:

	.globl	a_lava
	.globl	MEDBAT1
	.globl	a_medbat
	.globl	a_smallbat
 	.globl	spikeroof2
	.globl	spikes

a_lava:
	.word LAVA1
	.word LAVA2
	.word LAVA3
	.word LAVA4
	.word LAVA5
	.word LAVA6
	.word LAVA7
	.word LAVA8
	.word LAVA9
	.word LAVA10
	.word LAVA11
	.word LAVA12
	.word 0
a_medbat:
	.word MEDBAT1
	.word MEDBAT2
	.word MEDBAT3
	.word MEDBAT4
	.word MEDBAT5
	.word MEDBAT6
	.word MEDBAT7
	.word MEDBAT8
	.word ani_jump
	.word a_medbat
a_smallbat:
	.word SMBAT1
	.word SMBAT2
	.word SMBAT3
	.word SMBAT4
	.word SMBAT5
	.word SMBAT6
	.word SMBAT7
	.word SMBAT8
	.word ani_jump
	.word a_smallbat
MEDBAT1:
	.word MEDBAT1_IMG
	.half 21, 60, 3, 10
	.word BATORG_p
MEDBAT2:
	.word MEDBAT2_IMG
	.half 28, 59, 3, 11
MEDBAT3:
	.word MEDBAT3_IMG
	.half 28, 61, 5, 15
MEDBAT4:
	.word MEDBAT4_IMG
	.half 32, 62, 6, 18
MEDBAT5:
	.word MEDBAT5_IMG
	.half 25, 63, 7, 22
MEDBAT6:
	.word MEDBAT6_IMG
	.half 31, 66, 8, 28
MEDBAT7:
	.word MEDBAT7_IMG
	.half 25, 60, 7, 22
MEDBAT8:
	.word MEDBAT8_IMG
	.half 22, 64, 5, 8
SMBAT1:
	.word SMBAT1_IMG
	.half 16, 42, 3, 7
	.word BATORG_p
SMBAT2:
	.word SMBAT2_IMG
	.half 20, 41, 3, 8
SMBAT3:
	.word SMBAT3_IMG
	.half 20, 42, 4, 11
SMBAT4:
	.word SMBAT4_IMG
	.half 21, 43, 6, 13
SMBAT5:
	.word SMBAT5_IMG
	.half 16, 42, 6, 15
SMBAT6:
	.word SMBAT6_IMG
	.half 21, 43, 8, 19
SMBAT7:
	.word SMBAT7_IMG
	.half 18, 43, 9, 14
SMBAT8:
	.word SMBAT8_IMG
	.half 17, 45, 6, 6
spikes:
	.word spikes_IMG
	.half 60, 47, 0, 0
	.word spiker_p
spikeroof2:
	.word spikeroof2_IMG
	.half 53, 56, 0, 0
	.word spiker_p
LAVA1:
	.word lava1_IMG
	.half 72, 10, 0, 0
	.word LAVA_P
LAVA2:
	.word lava2_IMG
	.half 72, 10, 0, 0
LAVA3:
	.word lava3_IMG
	.half 72, 10, 0, 0
LAVA4:
	.word lava4_IMG
	.half 72, 10, 0, 0
LAVA5:
	.word lava5_IMG
	.half 72, 10, 0, 0
LAVA6:
	.word lava6_IMG
	.half 72, 10, 0, 0
LAVA7:
	.word lava7_IMG
	.half 72, 10, 0, 0
LAVA8:
	.word lava8_IMG
	.half 72, 10, 0, 0
LAVA9:
	.word lava9_IMG
	.half 72, 10, 0, 0
LAVA10:
	.word lava10_IMG
	.half 72, 10, 0, 0
LAVA11:
	.word lava11_IMG
	.half 72, 10, 0, 0
LAVA12:
	.word lava12_IMG
	.half 72, 10, 0, 0

#include "armory.att"

	.align 2
	.globl armory_dict
armory_dict:
#include "armory.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "armory1.umd"

	.align 2
	.globl armory_module
armory_module:
	.half	0				/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0xe6	     			/* ground y */

	.half	320				/* initial worldx */
	.half	0x41 	  			/* scroll left limit */
	.half	0x278		 		/* scroll right limit */

	.word	calla_armory
	.word	armory_scroll			/* scroll table */
	.word	dlists_armory

	.word	bakmods

	.word	SKIP_BAKMOD			/* baklst1 = skip baklst1 */

	.word	ARM1BMOD			/* baklst2 = pillars / weapons rack */
	.half	0x20,0xfff0

	.word	SKIP_BAKMOD			/* baklst3 = LAVA ANIMATION */

	.word	ARM2BMOD			/* baklst4 = steel tub */
	.half	0x00,0x38

	.word	ARM3BMOD			/* baklst5 = back wall w/ mk symbol */
	.half	0xfff8,0xfff9

	.word	CENTER_X
	.word	ARM1BMOD,worldtlx2
	.word	ARM2BMOD,worldtlx3		/* lineup lava with steel tub */
	.word	ARM2BMOD,worldtlx4
	.word	ARM3BMOD,worldtlx5
	.word	0

	.word	_armorflrSegmentRomStart			/* sag */
	.word	_armorflrSegmentRomEnd			/* sag end*/
	.word	MARFLOR_P		/* palette for floor */
	.word	54			/* height */
	.word	scrollx8
	.word	skew_7


	.align 2
dlists_armory:
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	-1,floor_code
	.word	baklst2,worldtlx2
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

armory_scroll:
	.word	0x16000		/* 8 - skewing floor follows this scroll */
	.word	0		/* 7 */
	.word	0		/* 6 */
/*	.word	0		; 6 */
	.word	0xc000		/* 5 - back wall */
	.word	0x15000		/* 4 - steel tub */
	.word	0x15000		/* 3 - lava animation */
	.word	0x1c000		/* 2 - pillars */
	.word	0x20000		/* 1 - players */
	.word	0x20000		/* 0 */


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "goro.umd"	
									  
	.align 2
	.globl mk1_module
mk1_module:
	.half	0	       		/* background sky color */
	.half	0x1a			/* initial worldy */
	.half	0xe4			/* ground y */
	.half	320			/* initial worldx */

	.half	146 	  		/* scroll left limit */
	.half	724	  		/* scroll right limit */
	.word	calla_lair
	.word	cave_scroll		/* scroll table */
	.word	dlists_cave

	.word	bakmods
	.word	dun1BMOD		/* 1, skulls */
	.half	0x80,0xf0
	.word	dun2BMOD		/* 2, lower floor */
	.half	0x80,0xe1
	.word	dun3BMOD		/* 3 */
	.half	0x80,0xd4
	.word	dun4BMOD		/* 4 */
	.half	0x40,0xffbd
	.word	dun5BMOD		/* 5 */
	.half	0x8f,0xc1
	.word	dun8BMOD		/* 6 */
	.half	0xfc,0xf
	.word	dun9BMOD		/* 7 */
	.half	0x100,0xab
	.word	dun10BMOD		/* 8 */
	.half	0x150,0xa7
	.word	0xffffffff
	.word	0,0

	.align 2
cave_scroll:
	.word	0x10000		/* 8 */
	.word	0x12000		/* 7 */
	.word	0x14000		/* 6 */
	.word	0x18000		/* 5 */
	.word	0x1c000		/* 4 */
	.word	0x1e000		/* 3 */
	.word	0x20000		/* 2 */
	.word	0x22000		/* 1 */
	.word	0x22000		/* 0 */

	.align 2
dlists_cave:
	.word	baklst9,worldtlx8
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "tomb.umd"	

	.align 2
	.globl tomb_module
tomb_module:
	.half	0			 	/* autoerase color */
	.half	0x0			/* initial world y */
	.half	0xe2	     			/* ground y */
	.half	320	/* initial worldx */

	.half	0x0 	  			/* scroll left limit */
	.half	0x288	  			/* scroll right limit */

	.word	calla_tomb
	.word	tomb_scroll			/* scroll table */
	.word	dlists_tomb

	.word	bakmods

	.word	SKIP_BAKMOD			/* baklst1 = skipped */

	.word	TMOD1BMOD			/* baklst2 = WALL */
	.half	0x08,0xffe8
	.word	TMOD2BMOD			/* baklst3 = FENCE */
	.half	0x00,0x68

	.word	SKIP_BAKMOD			/* baklst4 = bats (skip) */

	.word	TMOD3BMOD			/* baklst5 = SKY */
	.half	0x00,0x30

	.word	CENTER_X
	.word	TMOD1BMOD,worldtlx2	/* wall */
	.word	TMOD2BMOD,worldtlx3	/* FENCE */
	.word	TMOD3BMOD,worldtlx5	/* SKY */
	.word	0

	.word	_tombflrSegmentRomStart			/* sag */
	.word	_tombflrSegmentRomEnd				/* sag end */
	.word	TOMBFLR_p		/* palette for floor */
	.word	54			/* height */
	.word	scrollx2
	.word	skew_7

	.align 2
no_scroll:
tomb_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0		/* 5 - */
	.word	0		/* 5 - */
	.word	0x10000		/* 4 - */
	.word	0x10000		/* 3 - fence */
	.word	0x18000		/* 2 - wall */
	.word	0x20000		/* 1 - players */
	.word	0x20000		/* 0 */

	.align 2
dlists_tomb:
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	-1,floor_code
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl	dlists_ceiling
dlists_ceiling:
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	-1,floor_code
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx2
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl	dlists_lair_to_armory
dlists_lair_to_armory:
	.word	-1,use_worldtly_t
	.word	baklst8_t,worldtlx8_t
	.word	baklst7_t,worldtlx7_t
	.word	baklst6_t,worldtlx6_t
	.word	baklst5_t,worldtlx5_t
	.word	baklst4_t,worldtlx4_t
	.word	baklst3_t,worldtlx3_t
	.word	baklst2_t,worldtlx2_t
	.word	baklst1_t,worldtlx_t
	.word	objlst_t,worldtlx_t

	.word	-1,check_only_t
	.word	-1,use_worldtly

	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	-1,floor_code
	.word	baklst2,worldtlx2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0


	.globl	dlists_armory_to_tomb
dlists_armory_to_tomb:
	.word	-1,use_worldtly_t
	.word	baklst5_t,worldtlx5_t
	.word	baklst4_t,worldtlx4_t
	.word	baklst3_t,worldtlx3_t
	.word	baklst2_t,worldtlx2_t
	.word	objlst_t,worldtlx_t

	.word	-1,check_only_t
	.word	-1,use_worldtly

	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	-1,floor_code
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

