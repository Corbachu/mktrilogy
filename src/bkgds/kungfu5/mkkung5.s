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
	.extern 	calla_return
	.extern		calla_mk1pitstar

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern KUNGFU5x_CLT
	
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl preload_pittorch
preload_pittorch:
	.word PITFIRE1
	.word PITFIRE2
	.word PITFIRE3
	.word PITFIRE4
	.word PITFIRE5
	.word PITFIRE6
	.word 0
	
	.align 2
	.globl a_pittorch
a_pittorch:
	.word PITFIRE1
	.word PITFIRE2
	.word PITFIRE3
	.word PITFIRE4
	.word PITFIRE5
	.word PITFIRE6
	.word ani_jump
	.word a_pittorch
	
PITFIRE1:
	.word fire1_IMG
	.half 33, 17, 0, -3
	.word PITFIRE_P
PITFIRE2:
	.word fire2_IMG
	.half 28, 20, 1, -8
PITFIRE3:
	.word fire3_IMG
	.half 28, 18, 0, -8
PITFIRE4:
	.word fire4_IMG
	.half 34, 19, 1, -2
PITFIRE5:
	.word fire5_IMG
	.half 35, 22, 2, -1
PITFIRE6:
	.word fire6_IMG
	.half 36, 18, 0, 0
	
	.align 2
#include "pitfire.att"

	.align 2
	.globl mk1pit_dict
mk1pit_dict:
#include "pitfire.dct"
	


	.align 2
	
	.globl a_silo
a_silo:
	.word sil1
	.word sil2
	.word sil3
	.word sil4
	.word 0
sil1:
	.word sil1_IMG
	.half 39, 92, 0, 0
	.word silo_p
sil2:
	.word sil2_IMG
	.half 20, 25, 0, 0
	.word silo_p
sil3:
	.word sil3_IMG
	.half 25, 32, 0, 0
	.word silo_p
sil4:
	.word sil4_IMG
	.half 13, 13, 0, 0
	.word silo_p
	
	.align 2
#include "silo.att"


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "kungfu5.umd"

	.align 2
	.globl kung5_module
kung5_module:
	.half	(32*32*0)+(32*0)+0	 	/* autoerase color */
	.half	0x00    				/* initial world y */
	.half	0xd0		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	20 	  			/* scroll left limit */
	.half	604  			/* scroll right limit */

	.word	calla_mk1pitstar			/* routine to call */
	.word	kungfu5_scroll			/* scroll table */
	.word	dlists_kungfu5

	.word	bakmods
	.word	bridge0BMOD			/* baklst1 =  */
	.half	11,0x91+534+64
	.word	bridge1BMOD			/* baklst2 =  */
	.half	0x00,-534+534+64
	.word	star2BMOD			/* baklst3 =  */
	.half	0x00,-534+534+40-16
	.word	star1BMOD			/* baklst4 =  */
	.half	0x00,-534+534+40+8-230
	.word	star1BMOD			/* baklst5 =  */
	.half	0x00,-534+534+40+8-90
	.word	star1BMOD			/* baklst6 =  */
	.half	0x00,-534+534+40+8+50
					  
	.word	CENTER_X
	.word	bridge0BMOD,worldtlx
	.word	bridge1BMOD,worldtlx
	.word	star2BMOD,worldtlx3
	.word	star1BMOD,worldtlx4
	.word	star1BMOD,worldtlx5
	.word	star1BMOD,worldtlx6
	.word	0,0,0

	.align 2
	.globl kung5bottom_module
kung5bottom_module:
	.half	(32*32*0)+(32*0)+0	 	/* autoerase color */
	.half	0x00    				/* initial world y */
	.half	0xe0		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	20 	  			/* scroll left limit */
	.half	604  			/* scroll right limit */

	.word	calla_return			/* routine to call */
	.word	kungfu5_scroll			/* scroll table */
	.word	dlists_kungfu5bot

	.word	bakmods
	.word	bridge0BMOD			/* baklst1 =  */
	.half	11,0x91
	.word	bridge1BMOD			/* baklst2 =  */
	.half	0x00,-534
	.word	SKIP_BAKMOD
					  
	.word	CENTER_X
	.word	bridge0BMOD,worldtlx
	.word	bridge1BMOD,worldtlx
	.word	0,0,0

kungfu5_scroll:
	.word	0*SCX/100			/* 8 */
	.word	0x0000*SCX/100			/* 7 */
	.word	0x800*SCX/100			/* 6 */
	.word	0x800*SCX/100				/* 5 */
 	.word	0x800*SCX/100				/* 4 */
	.word	0x3000*SCX/100				/* 3 */
	.word	0x20000*SCX/100				/* 2 */
	.word	0x20000*SCX/100				/* 1 */
	.word	0x20000*SCX/100				/* player list */

dlists_kungfu5:
	.word	baklst8,worldtlx4
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst7,worldtlx
	.word	baklst2,worldtlx
	.word	objlst,worldtlx
	.word	baklst1,worldtlx
	.word	objlst2,worldtlx
	.word	0

dlists_kungfu5bot:
	.word	baklst2,worldtlx
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	baklst1,worldtlx
	.word	objlst2,worldtlx
	.word	0

