#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkdesert.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Desert Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	make_cyrax_sand	


/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern MKDESERT_CLT	
	.extern DESFLR_P		
	.extern CYRXSAND1_P		

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2

desert_anims:

	.globl	a_cyrax
	.globl	CYRXSAND1

a_cyrax:
	.word CYRXSAND1
	.word CYRXSAND2
	.word CYRXSAND3
	.word CYRXSAND4
	.word 0
CYRXSAND1:
	.word CYRXSAND1_IMG
	.half 36, 44, -2, 1
	.word CYRXSAND1_P
CYRXSAND2:
	.word CYRXSAND2_IMG
	.half 35, 46, 0, 0
CYRXSAND3:
	.word CYRXSAND3_IMG
	.half 34, 46, 0, -1
CYRXSAND4:
	.word CYRXSAND4_IMG
	.half 35, 46, 0, 0

#include "desert.att"

	.align 2
	.globl desert_dict
desert_dict:
#include "desert.dct"
	

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/

	.align 2
#include "mkdesert.umd"

	.align 2
	.globl desert_module
desert_module:
	.half	0x8000+(32*32*19)+(32*7)+2	 	/* autoerase color */
	.half	0   	 		   	/* initial world y */
	.half	0xe2			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	960-320		   	/* scroll right limit */

	.word	make_cyrax_sand			/* routine to call */
	.word	desert_scroll			/* scroll table */
	.word	dlists_desert

	.word	bakmods

	.word	DESERT1BMOD			/* baklst */
	.half	0xffff,0x67
	.word	DESERT2BMOD			/* baklst */
	.half	0xffff,0x4c
	.word	DESERT3BMOD			/* baklst */
	.half	0xfffe,0x27
	.word	DESERT4BMOD			/* baklst */
	.half	0xfffe,0x35

	.word	CENTER_X
	.word	DESERT1BMOD,worldtlx1
	.word	DESERT2BMOD,worldtlx2
	.word	DESERT3BMOD,worldtlx3
	.word	DESERT4BMOD,worldtlx4
	.word	0

	.word	_desertflrSegmentRomStart
	.word	_desertflrSegmentRomEnd
	.word	DESFLR_P   			/* palette for floor */
	.word	34				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

desert_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0x10000		/* 5 */
	.word	0		/* 4 */
	.word	0x8000		/* 3 */
	.word	0x10000		/* 2 */
	.word	0x18000		/* 1 */
	.word	0x20000		/* player list */

dlists_desert:
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst5,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

