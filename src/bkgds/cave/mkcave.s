#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkcave.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Cave Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	make_hell_flames	
	.extern	calla_cave			

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern	MKHADES_CLT	
	.extern	MKCAVE_CLT	
	.extern	CAVFLR_P	
	.extern	HELFLR_P	
	.extern STBREAK_P	
	.extern SMALL_p		
	.extern MEDIUM_p	
	.extern HELLFLAM_P	
	.extern CAVESKY1_P	
	.extern HELLHIT1_P	

/*
;*********************************
;** ANIMATIONS			**
;*********************************
*/
	.align	2
	.globl hell_anims
	.globl cave_anims
hell_anims:
hades_anims:
cave_anims:

	.globl HELLFLAME01
	.globl a_hell_flames
	.globl a_hell_hit
	.globl a_cave_sky
	.globl a_cave_sky_f

a_hell_flames:
	.word HELLFLAME01
	.word HELLFLAME02
	.word HELLFLAME03
	.word HELLFLAME04
	.word HELLFLAME05
	.word HELLFLAME06
	.word 0
a_hell_hit:
	.word HELLHIT1
	.word HELLHIT2
	.word HELLHIT3
	.word HELLHIT4
	.word HELLHIT5
	.word HELLHIT6
	.word HELLHIT7
	.word HELLHIT8
	.word 0
a_cave_sky:
	.word CAVESKY1
	.word CAVESKY2
	.word CAVESKY3
	.word CAVESKY4
	.word CAVESKY5
	.word CAVESKY6
	.word CAVESKY7
	.word CAVESKY8
	.word CAVESKY9
	.word CAVESKY10
	.word CAVESKY11
	.word 0
a_cave_sky_f:
	.word CAVESKY11
	.word CAVESKY10
	.word CAVESKY9
	.word CAVESKY8
	.word CAVESKY7
	.word CAVESKY6
	.word CAVESKY5
	.word CAVESKY4
	.word CAVESKY3
	.word CAVESKY2
	.word CAVESKY1
	.word 0
	.globl HELLFLAME01
HELLFLAME01:
	.word HELLFLAME01_IMG
	.half 31, 26, 0, 0
	.word	HELLFLAM_P
HELLFLAME02:
	.word HELLFLAME02_IMG
	.half 31, 26, 0, 0
HELLFLAME03:
	.word HELLFLAME03_IMG
	.half 31, 26, 0, 0
HELLFLAME04:
	.word HELLFLAME04_IMG
	.half 31, 26, 0, 0
HELLFLAME05:
	.word HELLFLAME05_IMG
	.half 31, 26, 0, 0
HELLFLAME06:
	.word HELLFLAME06_IMG
	.half 31, 26, 0, 0
	.globl HELLHIT1
HELLHIT1:
	.word HELLHIT1_IMG
	.half 8, 16, 7, 6
	.word HELLHIT1_P
HELLHIT2:
	.word HELLHIT2_IMG
	.half 14, 27, 14, 11
HELLHIT3:
	.word HELLHIT3_IMG
	.half 22, 48, 22, 20
HELLHIT4:
	.word HELLHIT4_IMG
	.half 26, 56, 28, 23
HELLHIT5:
	.word HELLHIT5_IMG
	.half 23, 61, 30, 19
HELLHIT6:
	.word HELLHIT6_IMG
	.half 19, 62, 31, 14
HELLHIT7:
	.word HELLHIT7_IMG
	.half 13, 49, 26, 8
HELLHIT8:
	.word HELLHIT8_IMG
	.half 6, 52, 28, 2
	.globl CAVESKY1
CAVESKY1:
	.word CAVESKY1_IMG
	.half 43, 15, 0, 0
	.word	CAVESKY1_P
CAVESKY2:
	.word CAVESKY2_IMG
	.half 43, 15, 0, 0
CAVESKY3:
	.word CAVESKY3_IMG
	.half 43, 15, 0, 0
CAVESKY4:
	.word CAVESKY4_IMG
	.half 43, 15, 0, 0
CAVESKY5:
	.word CAVESKY5_IMG
	.half 43, 15, 0, 0
CAVESKY6:
	.word CAVESKY6_IMG
	.half 43, 15, 0, 0
CAVESKY7:
	.word CAVESKY7_IMG
	.half 43, 15, 0, 0
CAVESKY8:
	.word CAVESKY8_IMG
	.half 43, 15, 0, 0
CAVESKY9:
	.word CAVESKY9_IMG
	.half 43, 15, 0, 0
CAVESKY10:
	.word CAVESKY10_IMG
	.half 43, 15, 0, 0
	.globl CAVESKY11
CAVESKY11:
	.word CAVESKY11_IMG
	.half 43, 15, 0, 0
	.word	CAVESKY1_P

#include "cave.att"

	.align 2
	.globl cave_dict
cave_dict:
#include "cave.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkcave.umd"	

	.align 2
	.globl cave_module
cave_module:
	.half	(32*32*0)+(32*0)+0	 	/* autoerase color */
	.half	0   	 		   	/* initial world y */
	.half	0xe2			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640			   	/* scroll right limit */

	.word	calla_cave	/* routine to call */
	.word	cave_scroll			/* scroll table */
	.word	dlists_cave
	.word	bakmods

	.word	CAVE1BMOD			/* baklst1 = huge head */
	.half	0x00,0x3d
	.word	CAVE2BMOD			/* baklst2 = huge head */
	.half	0x00,0x02-0x0b
	.word	SKIP_BAKMOD 	 		/* baklst3 = skip */
	.word	SKIP_BAKMOD 	 		/* baklst4 = skip */

	.word	CENTER_X
	.word	CAVE1BMOD,worldtlx1
	.word	CAVE2BMOD,worldtlx2
	.word	0

	.word	_caveflrSegmentRomStart	/* sag start */
	.word	_caveflrSegmentRomEnd		/* sag end */
	.word	CAVFLR_P   			/* palette for floor */
	.word	62				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

cave_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0		/* 5 */
	.word	0x14000		/* 4 */
	.word	0x14000		/* 3 */
	.word	0x14000		/* 2 */
	.word	0x18000		/* 1 */
	.word	0x20000		/* player list */

dlists_cave:
	.word	baklst4,worldtlx2
	.word	baklst3,worldtlx2
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
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
#include "mkhades.umd"

	.globl hell_module
hell_module:
	.half	(32*32*0)+(32*0)+0	 	/* autoerase color */
	.half	0   	 		   	/* initial world y */
	.half	0xe4			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640		   	/* scroll right limit */

	.word	make_hell_flames		/* routine to call */
	.word	hell_scroll			/* scroll table */
	.word	dlists_hell
	.word	bakmods

	.word	HADES1BMOD			/* baklst1 = huge head */
	.half	0xFFF0,0xFFF6
	.word	HADES2BMOD			/* baklst2 = */
	.half	0x00,0xFFec

	.word	SKIP_BAKMOD 	 		/* baklst3 = skip */

	.word	HADES3BMOD			/* baklst4 = */
	.half	0x00,0x10
	.word	HADES4BMOD			/* baklst5 = */
	.half	0x00,0x28
	.word	HADES5BMOD			/* baklst6 = */
	.half	0xFFFE,0x43+8

	.word	CENTER_X
/*	.word	HADES1BMOD,worldtlx1 */
	.word	HADES2BMOD,worldtlx2
	.word	HADES3BMOD,worldtlx4
	.word	HADES4BMOD,worldtlx5
	.word	HADES5BMOD,worldtlx6
	.word	0

	.word	_hellflrSegmentRomStart
	.word	_hellflrSegmentRomEnd
	.word	HELFLR_P   			/* palette for floor */
	.word	40				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

hell_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0x8000		/* 5 */
	.word	0x10000		/* 4 */
	.word	0		/* 3 */
	.word	0x18000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* player list */

dlists_hell:
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx2
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	baklst7,worldtlx1
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0


	.globl dlists_hell_to_cave
dlists_hell_to_cave:
	.word	-1,use_worldtly_t
	.word	baklst6_t,worldtlx6_t
	.word	baklst5_t,worldtlx5_t
	.word	baklst4_t,worldtlx4_t
	.word	baklst3_t,worldtlx2_t
	.word	baklst2_t,worldtlx2_t
	.word	baklst1_t,worldtlx1_t
	.word	baklst7_t,worldtlx1_t
	.word	objlst_t,worldtlx_t
	.word	-1,check_only_t
	.word	-1,use_worldtly
	.word	baklst4,worldtlx2
	.word	baklst3,worldtlx2
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

