#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkgrav.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Grave Yard Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern 	calla_kungfu2

/*
;*********************************
;**			PALETTES
;*********************************
*/

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
	.align 2
#include "kungfu2.umd"

	.align 2
	.globl kung2_module
kung2_module:
	.half	(32*32*31)+(32*28)+20 		/* autoerase color */
	.half	0x00    				/* initial world y */
	.half	0xe0		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	104 	  			/* scroll left limit */
	.half	564  			/* scroll right limit */

	.word	calla_kungfu2			/* routine to call */
	.word	kungfu2_scroll			/* scroll table */
	.word	dlists_kungfu2

	.word	bakmods
	.word	ARENA1BMOD			/* baklst1 = bridge */
	.half	0x00,136
	.word	ARENA2BMOD			/* baklst2 = guards on floor */
	.half	0x00,96
	.word	ARENA3BMOD			/* baklst3 = monks 1 */
	.half	0x00,60-6+74+19
#if 0
	.word	ARENA4BMOD			/* baklst4 = monks 2 */
	.half	0x00,60-6+74+19
#endif
	.word	ARENA5BMOD			/* baklst5 = front face */
	.half	0,68
	.word	ARENA6BMOD			/* baklst6 = dojo  */
	.half	0,-49
	.word	ARENA7BMOD			/* baklst7 = backfence */
	.half	0,42
	.word	ARENA8BMOD			/* baklst8 = mountain */
	.half	-64,-32+8

	.word	CENTER_X
	.word	ARENA1BMOD,worldtlx1
	.word	ARENA2BMOD,worldtlx2
	.word	ARENA3BMOD,worldtlx3
/*	
	.word	ARENA4BMOD,worldtlx4
*/	
	.word	ARENA5BMOD,worldtlx4
	.word	ARENA6BMOD,worldtlx5
	.word	ARENA7BMOD,worldtlx6
	.word	ARENA8BMOD,worldtlx7
	.word	0,0,0

kungfu2_scroll:
	.word	0*SCX/100			/* 8 */
	.word	0x0000*SCX/100			/* 7 */
	.word	0x10000*SCX/100			/* 6 */
	.word	0x10000*SCX/100				/* 5 */
	.word	0x10000*SCX/100				/* 4 */
	.word	0x14000*SCX/100				/* 3 */
	.word	0x18000*SCX/100				/* 2 */
	.word	0x20000*SCX/100				/* 1 */
	.word	0x20000*SCX/100				/* player list */

dlists_kungfu2:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

