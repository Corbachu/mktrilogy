#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkdead.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Dead Pool Module
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_dead 

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern NUPOOL_CLT 
	.extern apool_p	   

/*	
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
dead_anims:

	.globl	a_green_splash
	.globl	a_slime_skel
	.globl	acidsplash1a
	.globl	acidskel1

a_green_splash:
	.word acidsplash1a
	.word acidsplash2a
	.word acidsplash3
	.word acidsplash4
	.word acidsplash5
	.word acidsplash6
	.word acidsplash7
	.word acidsplash8
	.word 0
a_slime_skel:
	.word acidskel1
	.word acidskel2
	.word acidskel3
	.word acidskel4
	.word acidskel5
	.word 0
	.word acidskel6
	.word acidskel7
	.word acidskel8
	.word acidskel9
	.word acidskel10
	.word acidskel11
	.word 0
acidsplash1a:
	.word acidsplash1a_IMG
	.half 11, 62, 43, 11
	.word apool_p	   
acidsplash1b:
	.word acidsplash1b_IMG
	.half 31, 57, 37, 42
acidsplash2a:
	.word acidsplash2a_IMG
	.half 23, 78, 51, 19
acidsplash2b:
	.word acidsplash2b_IMG
	.half 31, 85, 50, 46
acidsplash3:
	.word acidsplash3_IMG
	.half 60, 127, 74, 60
acidsplash4:
	.word acidsplash4_IMG
	.half 59, 158, 88, 57
acidsplash5:
	.word acidsplash5_IMG
	.half 70, 169, 95, 65
acidsplash6:
	.word acidsplash6_IMG
	.half 69, 98, 61, 63
acidsplash7:
	.word acidsplash7_IMG
	.half 73, 111, 67, 67
acidsplash8:
	.word acidsplash8_IMG
	.half 70, 110, 67, 64
acidskel1:
	.word acidskel1_IMG
	.half 10, 11, 6, -4
	.word apool_p	   
acidskel2:
	.word acidskel2_IMG
	.half 10, 12, 6, -3
acidskel3:
	.word acidskel3_IMG
	.half 18, 16, 6, -2
acidskel4:
	.word acidskel4_IMG
	.half 18, 17, 6, -2
acidskel5:
	.word acidskel5_IMG
	.half 19, 19, 10, 0
acidskel6:
	.word acidskel6_IMG
	.half 20, 24, 14, 2
acidskel7:
	.word acidskel7_IMG
	.half 22, 27, 16, 4
acidskel8:
	.word acidskel8_IMG
	.half 25, 27, 17, 7
acidskel9:
	.word acidskel9_IMG
	.half 26, 21, 10, 9
acidskel10:
	.word acidskel10_IMG
	.half 26, 21, 10, 8
acidskel11:
	.word acidskel11_IMG
	.half 26, 21, 10, 9

#include "dead.att"

	.align 2
	.globl dead_dict
dead_dict:
#include "dead.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "nupool.umd"

	.align 2
	.globl dedpool_module
dedpool_module:
	.half	0	/* autoerase color */
	.half	0x20				/* initial world y */
	.half	0xd8	     			/* ground y */
	.half	320				/* world x */
	.half	0x2 	  			/* scroll left limit */
	.half	592	  			/* scroll right limit */

	.word	calla_dead
	.word	dedpool_scroll			/* scroll table */
	.word	dlists_dedpool

	.word	bakmods

	.word	DPUL6BMOD			/* baklst1 = back wall */
	.half	0x78,0x10
	.word	DPUL5BMOD			/* baklst1 = back wall */
	.half	0,0xffe8
/*	.word	SKIP_BAKMOD			; baklst2 = skip */
	.word	DPUL2BMOD
	.half	0,-0x40+0x28				/* baklst3 = close up chains */
	.word	DPUL3BMOD			/* 4 - chains */
	.half	0,-0x40+0x28
	.word	DPUL4BMOD			/* 5 - chains */
	.half	0,-0x40+0x28

	.word	CENTER_X
	.word	DPUL6BMOD,worldtlx		/* sky */
	.word	DPUL5BMOD,worldtlx		/* back wall */
	.word	DPUL3BMOD,worldtlx4		/* back wall */
	.word	DPUL4BMOD,worldtlx5		/* back wall */
	.word	DPUL2BMOD,worldtlx3		/* close chains */
	.word	0,0


dedpool_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0x24000		/* 5 */
	.word	0x28000		/* 4 */
	.word	0x30000		/* 3 */
	.word	0x20000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* 0 */

dlists_dedpool:
	.word	baklst1,worldtlx		/* wall is furthest thing back */
	.word	baklst2,worldtlx		/* wall is furthest thing back */
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	baklst3,worldtlx3		/* close up chains */
	.word	objlst2,worldtlx
	.word	0

