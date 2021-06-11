#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: mkwater.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III water Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	make_water_proc 

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern	mkwater_CLT		 
	.extern	WATFLR_P		 

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
water_anims:

	.align 2
	.globl a_water1
	
a_water1:
	.word	WATERA01,WATERC01,WATERD01,WATERB01
	.word	WATERA02,WATERC02,WATERD02,WATERB02
	.word	WATERA03,WATERC03,WATERD03,WATERB03
	.word	WATERA04,WATERC04,WATERD04,WATERB04
	.word	WATERA05,WATERC05,WATERD05,WATERB05
	.word	WATERA06,WATERC06,WATERD06,WATERB06
	.word	WATERA07,WATERC07,WATERD07,WATERB07
	.word	WATERA08,WATERC08,WATERD08,WATERB08
	.word	0

WATERA01:
	.word WATERA01_IMG
	.half 34, 144, 0, 0
WATERC01:
	.word WATERC01_IMG
	.half 34, 54, 0, 0
WATERD01:
	.word WATERD01_IMG
	.half 18, 54, 0, 0
WATERB01:
	.word WATERB01_IMG
	.half 18, 84, 0, 0
WATERA02:
	.word WATERA02_IMG
	.half 34, 144, 0, 0
WATERC02:
	.word WATERC02_IMG
	.half 34, 54, 0, 0
WATERD02:
	.word WATERD02_IMG
	.half 18, 54, 0, 0
WATERB02:
	.word WATERB02_IMG
	.half 18, 84, 0, 0
WATERA03:
	.word WATERA03_IMG
	.half 34, 144, 0, 0
WATERC03:
	.word WATERC03_IMG
	.half 34, 54, 0, 0
WATERD03:
	.word WATERD03_IMG
	.half 18, 54, 0, 0
WATERB03:
	.word WATERB03_IMG
	.half 18, 84, 0, 0
WATERA04:
	.word WATERA04_IMG
	.half 34, 144, 0, 0
WATERC04:
	.word WATERC04_IMG
	.half 34, 54, 0, 0
WATERD04:
	.word WATERD04_IMG
	.half 18, 54, 0, 0
WATERB04:
	.word WATERB04_IMG
	.half 18, 84, 0, 0
WATERA05:
	.word WATERA05_IMG
	.half 34, 144, 0, 0
WATERC05:
	.word WATERC05_IMG
	.half 34, 54, 0, 0
WATERD05:
	.word WATERD05_IMG
	.half 18, 54, 0, 0
WATERB05:
	.word WATERB05_IMG
	.half 18, 84, 0, 0
WATERA06:
	.word WATERA06_IMG
	.half 34, 144, 0, 0
WATERC06:
	.word WATERC06_IMG
	.half 34, 54, 0, 0
WATERD06:
	.word WATERD06_IMG
	.half 18, 54, 0, 0
WATERB06:
	.word WATERB06_IMG
	.half 18, 84, 0, 0
WATERA07:
	.word WATERA07_IMG
	.half 34, 144, 0, 0
WATERC07:
	.word WATERC07_IMG
	.half 34, 54, 0, 0
WATERD07:
	.word WATERD07_IMG
	.half 18, 54, 0, 0
WATERB07:
	.word WATERB07_IMG
	.half 18, 84, 0, 0
WATERA08:
	.word WATERA08_IMG
	.half 34, 144, 0, 0
WATERC08:
	.word WATERC08_IMG
	.half 34, 54, 0, 0
WATERD08:
	.word WATERD08_IMG
	.half 18, 54, 0, 0
WATERB08:
	.word WATERB08_IMG
	.half 18, 84, 0, 0

	.align 2
#include "water.att"

	.align 2
	.globl water_dict
water_dict:
#include "water.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkwater.umd"

	.align 2
	.globl water_module
water_module:
	.half	0x8000+(32*32*7)+(32*1)+5	 	/* autoerase color */
	.half	0   	 		   	/* initial world y */
	.half	0xe2			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */

	.half	590			   	/* kludge to fix missing water piece */

	.word	make_water_proc			/* routine to call */
	.word	water_scroll			/* scroll table */
	.word	dlists_water

	.word	bakmods
	.word	water1BMOD			/* baklst1 = rail */
	.half	0xffe0,0x89
	.word	water2BMOD			/* baklst2 = bridge */
	.half	0x44,0x12
	.word	water3BMOD			/* baklst3 = water #1 */
	.half	0x88,0x9a
	.word	water4BMOD			/* baklst4 = water #2 */
	.half	0x2c,0x88
	.word	water5BMOD			/* baklst5 = back wall */
	.half	0xd0,0x5d
	.word	water6BMOD			/* baklst6 = sky */
	.half	0,0x51
	.word	water7BMOD			/* baklst6 = sky */
	.half	0,0x08

	.word	CENTER_X
	.word	water4BMOD,worldtlx4
	.word	water6BMOD,worldtlx6
	.word	water7BMOD,worldtlx7
	.word	0

	.word	_waterflrSegmentRomStart
	.word	_waterflrSegmentRomEnd
	.word	WATFLR_P   			/* palette for floor */
	.word	32				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

water_scroll:
	.word	0		/* 8 */
	.word	0x4000		/* 7 */
	.word	0x8000		/* 6 */
	.word	0xd000		/* 5 */
	.word	0xd000		/* 4 */
	.word	0x10000		/* 3 */
	.word	0x18000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* player list */

dlists_water:
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst4,worldtlx4
	.word	baklst5,worldtlx5
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0
