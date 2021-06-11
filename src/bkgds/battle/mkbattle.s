#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkbattle.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Battle
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_battle
	.extern	GROUND_p	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	
	.extern battle_CLT	
	
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align	2
#include "battle.umd"

	.align 2
	.globl battle_module
battle_module:
	.half	(32*32*3)+(32*0)+3 		/* autoerase color */

	.half	0x0	/* initial world y */
	.half	0xe5	     			/* ground y */
	.half	320			/* initial worldx */

	.half	0x00 	  			/* scroll left limit */
	.half	960-320  			/* scroll right limit */

	.word	calla_battle
	.word	battle_scroll			/* scroll table */
	.word	dlists_battle

	.word	bakmods

	.word	SKIP_BAKMOD			/* skip baklst1 */

	.word	BAT1BMOD
	.half	0xffa8,0x91
	.word	BAT2BMOD
	.half	0x40,0x18
	.word	BAT4BMOD
	.half	0x50,0x64
	.word	BAT5BMOD
	.half	0x1c0,0x50		/* castle */
	.word	BAT6BMOD
	.half	0x120,0x5d		/* mountains */
	.word	BAT7BMOD
	.half	0x123,0x1e		/* sky */

	.word	0xffffffff

	.word	_battleflrSegmentRomStart			/* sag start */
	.word	_battleflrSegmentRomEnd			/* sag end */
	.word	GROUND_p			/* palette for floor */
	.word	40				/* height */
	.word	scrollx2
	.word	skew_7

battle_scroll:
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0x2000		/* 5 */
	.word	0x3000		/* 6 */
	.word	0x8000		/* 4 */
	.word	0x10000		/* 3 */
	.word	0x1a000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* 0 */

dlists_battle:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	-1,floor_code
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0
