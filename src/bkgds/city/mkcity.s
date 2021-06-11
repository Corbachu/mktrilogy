#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkcity.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III City Module
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_city 

/*
;*********************************
;**			PALETTES								**
;*********************************
*/
	.extern MKCITY_CLT	
	.extern BURN_P		
	.extern NUSTORM_P	
	.extern CITYFLR_P	
	.extern STBREAK_P	
	.extern SMALL_p		
	.extern MEDIUM_p	

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2
	.globl preload_burn
preload_burn:
	.word BURNING1
	.word BURNING2
	.word BURNING3
	.word BURNING4
	.word BURNING5
	.word BURNING6
	.word BURNING7
	.word BURNING8
	.word 0


	.globl a_burn

a_burn:
	.word BURNING1
	.word BURNING2
	.word BURNING3
	.word BURNING4
	.word BURNING5
	.word BURNING6
	.word BURNING7
	.word BURNING8
	.word ani_jump
	.word a_burn
BURNING1:
	.word BURNING1_IMG
	.half 26, 46, 0, 0
	.word	BURN_P
BURNING2:
	.word BURNING2_IMG
	.half 27, 45, -1, 1
BURNING3:
	.word BURNING3_IMG
	.half 26, 45, -1, 0
BURNING4:
	.word BURNING4_IMG
	.half 25, 42, -4, -1
BURNING5:
	.word BURNING5_IMG
	.half 25, 43, -3, -1
BURNING6:
	.word BURNING6_IMG
	.half 26, 42, -4, 0
BURNING7:
	.word BURNING7_IMG
	.half 26, 44, -2, 0
BURNING8:
	.word BURNING8_IMG
	.half 26, 46, 0, 0

#include "city.att"

	.align 2
	.globl city_dict
city_dict:
#include "city.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkcity.umd"

	.align 2
	.globl 	roof_module
roof_module:
 	.half	0x00			 	/* autoerase color */
	.half	0x40				/* initial world y */
	.half	0xe1-4		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	0x20 	  			/* scroll left limit */
	.half	630  			/* scroll right limit */

	.word	calla_city		/* routine to call */
	.word	city_scroll			/* scroll table */
	.word	dlists_roof

	.word	bakmods
	.word	mkcity1BMOD			/* baklst1 = gargoyles */
	.half	0x00,0x29
	.word	mkcity2BMOD			/* baklst2 = wall */
	.half	0x00,0xb4
	.word	mkcity3BMOD			/* baklst3 = background city */
	.half	0xffd8,0x8d

	.word	SKIP_BAKMOD 	 		/* baklst4 = fire animation */

	.word	mkcity4BMOD			/* baklst5 = background city */
	.half	0x04,0x38
	.word	mkcity5BMOD			/* baklst6 = background city */
	.half	0xfffe,0x6d

	.word	SKIP_BAKMOD 	 		/* baklst7 = fire animation */

	.word	CENTER_X
	.word	mkcity1BMOD,worldtlx1
	.word	mkcity2BMOD,worldtlx2
	.word	mkcity3BMOD,worldtlx3
	.word	mkcity4BMOD,worldtlx4
	.word	mkcity4BMOD,worldtlx5
	.word	mkcity5BMOD,worldtlx6
	.word	mkcity5BMOD,worldtlx7
	.word	END_LIST

	.word	_cityflrSegmentRomStart
	.word	_cityflrSegmentRomEnd
	.word	CITYFLR_P   			/* palette for floor */
	.word	43					/* floor height */
	.word	scrollx2			/* which scroll variable to follow */
	.word	skew_7

city_scroll:
	.word	0 		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0x8000*SCX/100		/* 5 */
	.word	0x8000*SCX/100			/* 4 */
	.word	0x10000*SCX/100			/* 3 */
	.word	0x18000*SCX/100			/* 2 - gargoyles */
	.word	0x1d000*SCX/100			/* 1 - back wall */
	.word	0x20000*SCX/100			/* player list */

dlists_roof:
	.word	baklst7,worldtlx5
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx4
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

