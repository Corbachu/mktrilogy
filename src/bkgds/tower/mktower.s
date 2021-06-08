#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mktower.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Tower
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_sktower 

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern	CASFLR1_P	 
	.extern	TOWER2_CLT	 
	.extern	MONKPAL_p	 
	.extern	CLOUDSSK_P	 

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl preload_clouds
preload_clouds:
	.word cloud1a
	.word cloud1b
	.word cloud1c
	.word cloud1d
	.word 0

	.align 2
sktower_anims:

	.globl cloud1a
	.globl cloud1b
	.globl cloud1c
	.globl cloud1d

cloud1a:
	.word cloud1a_IMG
	.half 84, 69, 0, 0
	.word	CLOUDSSK_P
cloud1b:
	.word cloud1b_IMG
	.half 52, 78, 0, 0
	.word	CLOUDSSK_P
cloud1c:
	.word cloud1c_IMG
	.half 52, 78, 0, 0
	.word	CLOUDSSK_P
cloud1d:
	.word cloud1d_IMG
	.half 84, 69, 0, 0
	.word	CLOUDSSK_P

	.align 2
#include "tower.att"

	.align 2
	.globl tower_dict
tower_dict:
#include "tower.dct"


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "tower2.umd"

	.align 2
	.globl 	sktower_module
sktower_module:
	.half	(32*32*12)+(32*9)+7 		/* autoerase color */

	.half	0x0	/* initial world y */
	.half	0xe5	     			/* ground y */

	.half	320				/* initial worldx */
	.half	0x2c 	  			/* scroll left limit */
	.half	0x2cc	  			/* scroll right limit */
	.word	calla_sktower
	.word	tower_scroll			/* scroll table */
	.word	dlists_tower

	.word	bakmods
	.word	SKIP_BAKMOD			/* skip baklst1 */
	.word	SKIP_BAKMOD			/* skip baklst2 */
	.word	SKIP_BAKMOD			/* skip baklst3 */

	.word	PLANE4BMOD			/* baklst4 = pillars / smallest statue */
	.half	0xe8,0xfff3

	.word	SKIP_BAKMOD			/* skip baklst5 = monk */

	.word	PLANE5BMOD			/* baklst6 = wall */
	.half	0x18,0xffee
	.word	0xffffffff

	.word	_towerflrSegmentRomStart
	.word	_towerflrSegmentRomEnd
	.word	CASFLR1_P		/* palette for floor */
	.word	72			/* height */
	.word	scrollx6
	.word	skew_7

tower_scroll:
	.word	0x14000		/* 8 - clouds */
	.word	0x14000		/* 7 - clouds */
	.word	0x14000		/* 6 - wall */
	.word	0x14000		/* 5 - monk */
	.word	0x16000		/* 4 - pillars / smallest statue #1 */
	.word	0x18000		/* 3 - statue #2 */
	.word	0		/* 2 -  */
	.word	0x20000		/* 1 - */
	.word	0x20000		/* 0 */

dlists_tower:
	.word	baklst8,worldtlx8		/* clouds */
	.word	baklst7,worldtlx7		/* clouds */
	.word	baklst6,worldtlx6
	.word	-1,floor_code
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

