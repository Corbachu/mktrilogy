#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mklost.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Lost Bridge Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_lost	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern MKLOST80_CLT 
	.extern MKLOST_CLT	 
	.extern LITTLE_p	 
	.extern TOR_p		 

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
  	.align 2

lost_anims:

	.globl a_darkman1
	.globl a_darkman2

a_darkman1:
	.word BKGUY1
	.word BKGUY2
	.word BKGUY3
	.word BKGUY4
	.word BKGUY5
	.word BKGUY6
	.word BKGUY7
	.word 0
a_darkman2:
	.word TORCH1
	.word TORCH2
	.word TORCH3
	.word TORCH4
	.word TORCH5
	.word TORCH6
	.word TORCH7
	.word 0
BKGUY1:
	.word BKGUY1_IMG
	.half 22, 11, 5, 20
	.word	LITTLE_p
BKGUY2:
	.word BKGUY2_IMG
	.half 22, 11, 5, 20
BKGUY3:
	.word BKGUY3_IMG
	.half 22, 11, 5, 20
BKGUY4:
	.word BKGUY4_IMG
	.half 22, 11, 5, 20
BKGUY5:
	.word BKGUY5_IMG
	.half 22, 10, 5, 20
BKGUY6:
	.word BKGUY6_IMG
	.half 22, 11, 5, 20
BKGUY7:
	.word BKGUY7_IMG
	.half 22, 10, 5, 20
TORCH1:
	.word TORCH1_IMG
	.half 29, 12, 6, 25
	.word TOR_p
TORCH2:
	.word TORCH2_IMG
	.half 30, 12, 6, 26
TORCH3:
	.word TORCH3_IMG
	.half 29, 11, 6, 25
TORCH4:
	.word TORCH4_IMG
	.half 30, 11, 6, 26
TORCH5:
	.word TORCH5_IMG
	.half 31, 12, 6, 27
TORCH6:
	.word TORCH6_IMG
	.half 31, 12, 6, 27
TORCH7:
	.word TORCH7_IMG
	.half 28, 11, 6, 24

#include "lost.att"

	.align 2
	.globl lost_dict
lost_dict:
#if 0
#include "lost.dct"
#endif

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mklost.umd"

	.align 2
	.globl lost_module
lost_module:
	.half	0			 	/* autoerase color */
	.half	0x00   	 		   	/* initial world y */
	.half	0xe0-12			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640		   	/* scroll right limit */

	.word	calla_lost				/* routine: make lightning proc */
	.word	portal_scroll			/* scroll table */
	.word	dlists_portal

	.word	bakmods
	.word	LOST1BMOD			/* baklst2 = floor */
	.half	0x00,0xb8
	.word	LOST2BMOD			/* baklst3 = portal sky */
	.half	0x00,0x3c
	.word	LOST3BMOD			/* baklst3 = portal sky */
	.half	0x00,0xffe6

	.word	CENTER_X
	.word	LOST1BMOD,worldtlx1
	.word	LOST2BMOD,worldtlx2
	.word	LOST3BMOD,worldtlx3
	.word	0,0

portal_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0		/* 5 */
	.word	0		/* 4 */
	.word	0			/* 3 */
	.word	0x8000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* player list */


dlists_portal:
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0
