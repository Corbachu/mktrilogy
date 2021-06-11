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
	.extern 	grave_calla	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern  MKGRAVE_CLT	
	.extern  MOONANI_P		
	.extern  GRAVES_P		
	.extern  CEMFLR_P		


/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2
grave_anims:

	.globl	a_moon
	.globl	MOONA28
	.globl	BOON
	.globl	BERAN
	.globl	TOBIAS
	.globl	MICHIC
	.globl	GOSKIE
	.globl	VOGEL
	.globl	MAY
	.globl	MILLER
	.globl	SCHWARTZ
	.globl	GUIDO

a_moon:
	.word MOONA28
	.word MOONA2
	.word MOONA4
	.word MOONA6
	.word MOONA8
	.word MOONA10
	.word MOONA12
	.word MOONA14
	.word MOONA16
	.word MOONA18
	.word MOONA20
	.word MOONA22
	.word MOONA24
	.word MOONA26
	.word MOONA28
	.word 0
MOONA28:
	.word MOONA28_IMG
	.half 65, 72, -16, 0
	.word MOONANI_P
MOONA2:
	.word MOONA2_IMG
	.half 65, 75, -13, 0
	.word MOONANI_P
MOONA4:
	.word MOONA4_IMG
	.half 65, 76, -12, 0
MOONA6:
	.word MOONA6_IMG
	.half 65, 74, -13, 0
MOONA8:
	.word MOONA8_IMG
	.half 65, 89, 0, 0
MOONA10:
	.word MOONA10_IMG
	.half 65, 82, -6, 0
MOONA12:
	.word MOONA12_IMG
	.half 65, 93, 0, 0
MOONA14:
	.word MOONA14_IMG
	.half 65, 98, -6, 0
MOONA16:
	.word MOONA16_IMG
	.half 65, 96, -11, 0
MOONA18:
	.word MOONA18_IMG
	.half 65, 89, -16, 0
MOONA20:
	.word MOONA20_IMG
	.half 65, 79, -16, 0
MOONA22:
	.word MOONA22_IMG
	.half 65, 86, -16, 0
MOONA24:
	.word MOONA24_IMG
	.half 65, 83, -16, 0
MOONA26:
	.word MOONA26_IMG
	.half 65, 83, -16, 0
MAY:
	.word MA_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
MILLER:
	.word MIL_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
SCHWARTZ:
	.word SCH_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
GUIDO:
	.word GUI_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
VOGEL:
	.word VOGEL_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
BERAN:
	.word BERAN_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
GOSKIE:
	.word GOSKIE_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
MICHIC:
	.word MICHIC_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
BOON:
	.word BOON_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P
TOBIAS:
	.word TOBIAS_IMG
	.half 43, 34, 0, 0
	.word GRAVES_P

	.align 2
	.globl preload_grave
preload_grave:
	.word TOBIAS
	.word MAY
	.word MILLER
	.word SCHWARTZ
	.word GUIDO
	.word VOGEL
	.word BERAN
	.word GOSKIE
	.word MICHIC
	.word BOON
	.word 0

	.align 2
#include "grave.att"

	.align 2
	.globl grave_dict
grave_dict:
#include "grave.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkgrave.umd"

	.align 2
	.globl grave_module
grave_module:
	.half	(32*32*4)+(32*0)+0	 	/* autoerase color */
	.half	0x00    				/* initial world y */
	.half	0xe0		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	0 	  			/* scroll left limit */
	.half	580  			/* scroll right limit */

	.word	grave_calla			/* routine to call */
	.word	grave_scroll			/* scroll table */
	.word	dlists_grave

	.word	bakmods
	.word	GRAVE1BMOD			/* baklst1 =	front grass */
	.half	0x00,0x09
	.word	GRAVE2BMOD			/* baklst2 =	shovel */
	.half	0xfff8,0xffe0
	.word	GRAVE3BMOD			/* baklst3 = tomb stones (cross) */
	.half	0x08,0x43
	.word	GRAVE4BMOD			/* baklst4 = big house */
	.half	0x00,0x4b
	.word	GRAVE5BMOD			/* baklst5 = small tree */
	.half	0x140,0x2a
	.word	GRAVE6BMOD			/* baklst6 = death w/scyth */
	.half	0xffe0,0x68
	.word	GRAVE7BMOD			/* baklst7 = mountains */
	.half	0x00,0x39

	.word	CENTER_X
	.word	GRAVE1BMOD,worldtlx1
	.word	GRAVE2BMOD,worldtlx2
	.word	GRAVE3BMOD,worldtlx3
	.word	GRAVE4BMOD,worldtlx4
	.word	GRAVE6BMOD,worldtlx6
	.word	GRAVE7BMOD,worldtlx7
	.word	0

	.word	_graveflrSegmentRomStart
	.word	_graveflrSegmentRomEnd
	.word	CEMFLR_P   			/* palette for floor */
	.word	36				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

grave_scroll:
	.word	0*SCX/100			/* 8 */
	.word	0x0000*SCX/100			/* 7 */
	.word	0x8000*SCX/100			/* 6 */
	.word	0xc000*SCX/100				/* 5 */
	.word	0x10000*SCX/100				/* 4 */
	.word	0x14000*SCX/100				/* 3 */
	.word	0x18000*SCX/100				/* 2 */
	.word	0x1c000*SCX/100				/* 1 */
	.word	0x20000*SCX/100				/* player list */

dlists_grave:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	baklst9,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

