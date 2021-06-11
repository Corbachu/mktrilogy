#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkbell.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Bell Module
;*******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_bell 

/*
;*********************************
;**			PALETTES **
;*********************************
*/

	.extern MKBELL_CLT	 
	.extern MKBELL2_CLT	 
	.extern BELFLR_P	 
	.extern BELHOLE_P	 
	.extern SPIKE_P		 

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

bell_anims:

	.globl	EJBSPIKE
	.globl	BELLHOLE2
	.globl	BELLHOLE2_IMG
	.globl	BELLHOLE1A
	.globl	BELLHOLE1B
	

BELLHOLE1A:
	.word BELLHOLE1A_IMG
	.half 68, 86, 0, 0
	.word BELHOLE_P
BELLHOLE1B:
	.word BELLHOLE1B_IMG
	.half 68, 83, 0, 0
	.word BELHOLE_P
BELLHOLE2:
	.word BELLHOLE2_IMG
	.half 47, 75, 0, 0
	.word BELHOLE_P
EJBSPIKE:
	.word EJBSPIKE_IMG
	.half 118, 14, 0, 0
	.word SPIKE_P
 	
#include "bell.att"

	.align 2
	.globl bell_dict
bell_dict:
#include "bell.dct"
	

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/

	.align	2
#include "mkbell.umd"	
	.align	2
#include "mkbell2.umd"	

	.align 2
	.globl bell_module
bell_module:
	.half	(32*32*0)+(32*0)+0	/* autoerase color */
	.half	0x00					/* initial world y */
	.half	220 				/* ground y */
	.half	0 /*-320/2				; initial world x */
	.half	0xfef0 	  			/* scroll left limit */
	.half	120+160  				/* scroll right limit */
	.word	calla_bell			/* routine to call */
	.word	bell_scroll			/* scroll table */
	.word	dlists_bell
	.word	bakmods
	.word	MKBELL1BMOD			/* baklst1 = fore rope */
	.half	0x00,0xffb0
	.word	MKBELL2BMOD			/* baklst2 = fore wall */
	.half	0x00,0xffd0
	.word	MKBELL3BMOD			/* baklst3 = mid ropes */
	.half	0x00,0xffd4
	.word	MKBELL4BMOD			/* baklst4 = mid wall */
	.half	0xffec,0xffd0
	.word	MKBELL5BMOD			/* baklst5 = mid bell */
	.half	0x00,0xffa0
	.word	MKBELL6BMOD			/* baklst6 = back wall */
	.half	0x00,0xffda
	.word	MKBELL7BMOD			/* baklst7 = moon */
	.half	0x20,0x23

	.word	CENTER_X
	.word	MKBELL1BMOD,worldtlx1
	.word	MKBELL2BMOD,worldtlx2
	.word	MKBELL3BMOD,worldtlx3
	.word	MKBELL4BMOD,worldtlx4
	.word	MKBELL5BMOD,worldtlx5
	.word	MKBELL6BMOD,worldtlx6
	.word	MKBELL7BMOD,worldtlx7
	.word	END_LIST

	.word	_bellflrSegmentRomStart	/* sag */
	.word	_bellflrSegmentRomEnd	/* sag end */
	.word	BELFLR_P  			/* palette for floor */
	.word	65					/* floor height */
	.word	scrollx2			/* which scroll variable to follow */
	.word	skew_7

/*
;**************************************************************************
;*											     *
;*  module: Bell 2										*
;*											     *
;**************************************************************************
*/
	.align 2
	.globl bell2_module
bell2_module:
	.half	(32*32*0)+(32*0)+0	 	/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0xe7 				/* ground y */
	.half	320				/* initial world x */
	.half	0 	  			/* scroll left limit */
	.half	640  			/* scroll right limit */
	.word	calla_bell			/* routine to call */
	.word	bell_scroll			/* scroll table */
	.word	dlists_bell

	.word	bakmods
	.word	SKIP_BAKMOD 	 		/* baklst1 = */
	.word	SKIP_BAKMOD 	 		/* baklst2 = */
	.word	SKIP_BAKMOD 	 		/* baklst3 = */
	.word	SKIP_BAKMOD 	 		/* baklst4 = */
	.word	SKIP_BAKMOD 	 		/* baklst5 = */
	.word	SKIP_BAKMOD 	 		/* baklst6 = */
	.word	SKIP_BAKMOD 	 		/* baklst7 = */
	.word	MKTOWERBMOD			/* baklst8 = the only plane */
	.half	0x00,-0x70

	.word	CENTER_X
	.word	MKTOWERBMOD,worldtlx8
	.word	0,0

bell_scroll:
	.word	0*SCX/100		/* 8 */
	.word	0x4000*SCX/100			/* 7 */
	.word	0x8000*SCX/100			/* 6 */
	.word	0xd000*SCX/100			/* 5 */
	.word	0x10000*SCX/100			/* 4 */
	.word	0x14000*SCX/100			/* 3 - back fence */
	.word	0x18000*SCX/100			/* 2 - front fence */
	.word	0x28000*SCX/100			/* 1 - bells */
	.word	0x20000*SCX/100			/* player list */

dlists_bell:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0



