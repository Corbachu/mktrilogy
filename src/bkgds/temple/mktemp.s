#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mktemp.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Temple Module
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	temple_calla	

/*
;*********************************
;**			PALETTES			**
;*********************************
*/
	.extern MKTEMP2x_CLT   
	.extern MKTEMP2z_CLT   
	.extern nutemp2_CLT   
	.extern WIKS_P		   
	.extern SKFIRE_P	   
	.extern RCANDLE_P	   
	.extern templfl_p	   
	.extern nutemple_CLT
	
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl temple_preload
temple_preload:
	.word KANDLE1
	.word SKTORCH1
	.word SKTORCH2
	.word SKTORCH3
	.word SKTORCH4
	.word SKTORCH5
	.word SKTORCH6
	.word wik1
	.word wik2
	.word wik3
	.word wik4
	.word 0
	

	.align 2
temple_anims:


	.globl	a_tflame
	.globl	KANDLE1
	.globl	wik1
	.globl	a_candle_flame
	
a_tflame:
	.word SKTORCH1
	.word SKTORCH2
	.word SKTORCH3
	.word SKTORCH4
	.word SKTORCH5
	.word SKTORCH6
	.word ani_jump
	.word a_tflame
a_candle_flame:
	.word wik1
	.word wik2
	.word wik3
	.word wik4
	.word ani_jump
	.word a_candle_flame
SKTORCH1:
	.word SKTORCH1_IMG
	.half 42, 21, 6, 42
	.word	SKFIRE_P
SKTORCH2:
	.word SKTORCH2_IMG
	.half 43, 22, 7, 43
SKTORCH3:
	.word SKTORCH3_IMG
	.half 45, 21, 6, 45
SKTORCH4:
	.word SKTORCH4_IMG
	.half 41, 22, 7, 41
SKTORCH5:
	.word SKTORCH5_IMG
	.half 37, 22, 7, 37
SKTORCH6:
	.word SKTORCH6_IMG
	.half 37, 21, 6, 37
wik1:
	.word WIK1_IMG
	.half 14, 6, 2, 14
	.word WIKS_P
wik2:
	.word WIK2_IMG
	.half 18, 6, 2, 18
wik3:
	.word WIK3_IMG
	.half 18, 6, 2, 17
wik4:
	.word WIK4_IMG
	.half 15, 7, 2, 15

KANDLE1:
	.word KANDLE1_IMG
	.half 25, 17, 7, 4
	.word RCANDLE_P

	.align 2
#include "temple.att"	

	.align 2
	.globl temple_dict
temple_dict:
#include "temple.dct"	

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/

	.align 2
#include "mktemple.umd"

	.align 2
	.globl temple_module
temple_module:
	.half	0x00					/* background color */
	.half	0x00	  				/* initial world y */
	.half	0xd9	  			/* ground y offset */
	.half	320 				/* initial world x */
	.half	32 	  				/* scroll left limit */
	.half	600					/* scroll right limit */

	.word	temple_calla
	.word	temple_scroll	  	/* scroll table */
	.word	dlists_temple

	.word	bakmods
	.word	temple1BMOD	  	/* baklst1 = railing */
	.half	0x14,0x5f+0x8-29
#if 0	
	.word	temple2BMOD	  	/* baklst2 = poles table */
	.half	0xc6,0x41+0x8
#endif

	.word	SKIP_BAKMOD	

	.word	temple3BMOD	  	/* baklst3 = arc */
	.half	0x0000,0xffc2+0x8
	
	.word	SKIP_BAKMOD	
#if 0	
	.word	temple4BMOD	  	/* baklst4 = stainglass */
	.half	0xa,0x2+0x8
#endif	
	.word	temple0BMOD	  	/* baklst5 = candles */
	.half	0x00,0xc8

	.word	CENTER_X
	.word	temple1BMOD,worldtlx1
	.word	temple3BMOD,worldtlx3
#if 0	
	.word	temple4BMOD,worldtlx4
#endif	
	.word	temple0BMOD,worldtlx5
#if 0	
	.word	temple2BMOD,worldtlx7
#endif	
	.word	0

	.word	_templeflrSegmentRomStart
	.word	_templeflrSegmentRomEnd
	.word	templfl_p	   	/* palette for floor */
	.word	51	/*+10				; skew height */
	.word	scrollx1		/* which scroll variable to follow */
	.word	skew_7

temple_scroll:
	.word	0*SCX/100	 		/* 8 */
	.word	0*SCX/100			/* 7 - tony flame */
	.word	0*SCX/100			/* 6 - vogel flame */
	.word	0x28000*SCX/100			/* 5 - candle */
	.word	0xa000*SCX/100			/* 4 */
	.word	0x10000*SCX/100			/* 3 */
	.word	0x14000*SCX/100			/* 2 */
	.word	0x16000*SCX/100			/* 1 - this matches the floor */
	.word	0x20000*SCX/100		/* 0 - player object list */

dlists_temple:
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst7,worldtlx1		/* tony flames */
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	baklst1,worldtlx1
	.word	objlst,worldtlx
	.word	baklst5,worldtlx5
	.word	baklst6,worldtlx5
	.word	objlst2,worldtlx
	.word	0

