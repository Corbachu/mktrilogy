#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkmonk.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Monk Portal
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_monk	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern	spiral_CLT	
	.extern	moflr_p		
	.extern	TIMEFLR_p	
	.extern	lite99_p	
	.extern	MONKS1		
	.extern	MONKPAL_p	

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
monk_anims:

	.globl	warplite1
	.globl	a_warplite
	.globl	timefloor1
	.globl	a_timemonk
	.globl	timemonk1


a_warplite:
	.word warplite1
	.word warplite2
	.word warplite3
	.word warplite4
	.word warplite5
	.word warplite6
	.word 0
a_timemonk:
	.word timemonk1
	.word timemonk2
	.word timemonk3
	.word timemonk4
	.word timemonk5
	.word timemonk6
	.word timemonk7
	.word 0
warplite1:
	.word warplite1_IMG
	.half 11, 10, 5, 4
	.word lite99_p
warplite2:
	.word warplite2_IMG
	.half 14, 12, 4, 3
warplite3:
	.word warplite3_IMG
	.half 15, 14, 2, 4
warplite4:
	.word warplite4_IMG
	.half 15, 15, 3, 4
warplite5:
	.word warplite5_IMG
	.half 7, 20, 6, 0
warplite6:
	.word warplite6_IMG
	.half 9, 21, 6, 1
timemonk1:
	.word timemonk1_IMG
	.half 27, 15, 8, 11
	.word MONKS1
timemonk2:
	.word timemonk2_IMG
	.half 27, 14, 8, 11
timemonk3:
	.word timemonk3_IMG
	.half 27, 14, 8, 11
timemonk4:
	.word timemonk4_IMG
	.half 26, 14, 8, 11
timemonk5:
	.word timemonk5_IMG
	.half 27, 15, 8, 11
timemonk6:
	.word timemonk6_IMG
	.half 27, 15, 8, 11
timemonk7:
	.word timemonk7_IMG
	.half 27, 16, 8, 11
timefloor1:
	.word timefloor1_IMG
	.half 43, 70, 35, 0
	.word TIMEFLR_p

#include "monks.att"

	.align 2
	.globl monks_dict
monks_dict:
#include "monks.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "spiral.umd"

	.align 2
	
	.globl monkport_module
monkport_module:
	.half	0		 	/* autoerase color */

	.half	0x0
	.half	0xe4	     		/* ground y */
	.half	320	/* initial worldx */

	.half	0x00 	  		/* scroll left limit */
	.half	0x250	  		/* scroll right limit */

	.word	calla_monk
	.word	port_scroll		/* scroll table */
	.word	dlists_port

	.word	bakmods
	.word	SKIP_BAKMOD		/* skip baklst1 */

	.word	spiral1BMOD		/* baklst2 = pillars */
	.half	0xfff4,0xfffc
	.word	spiral2BMOD		/* baklst3 = house */
	.half	0x40,0x20

	.word	SKIP_BAKMOD		/* skip baklst4 */

	.word	spiral3BMOD		/* baklst5 = little mountains */
	.half	0x00,0xa2
	.word	spiral4BMOD		/* baklst6 = sky */
	.half	0x00,0xfff8

	.word	CENTER_X
	.word	spiral1BMOD,worldtlx2
	.word	spiral2BMOD,worldtlx3
	.word	spiral3BMOD,worldtlx5
	.word	spiral4BMOD,worldtlx6
	.word	0

	.word	_monkflrSegmentRomStart
	.word	_monkflrSegmentRomEnd
	.word	moflr_p			/* palette for floor */
	.word	0x2c			/* height */
	.word	scrollx2
	.word	skew_7

port_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 - sky */
	.word	0x8000		/* 5 - little mountains */
	.word	0		/* 4 */
	.word	0x10000		/* 3 - house */
	.word	0x18000		/* 2 - pillars */
	.word	0x20000		/* 1 - main floor */
	.word	0x20000		/* 0 */

dlists_port:
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0
	
