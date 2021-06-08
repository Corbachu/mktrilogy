#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkpit.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Pit Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_pit	
/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern MKTHRONE_CLT	
	.extern throne2x_CLT	
	.extern	BGHD3_P			
	.extern BLDXPD_P		
	.extern	BODY_P			
	.extern	CAGE_P			
	.extern	GBODY_P			
	.extern	SAW_P			

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
pit_anims:
base_anims:

	.globl	SAW2
	.globl	a_saw
	.globl	THRONEWALL

a_saw:
	.word SAW2
	.word SAW4
	.word SAW6
	.word 0
SAW2:
	.word SAW2_IMG
	.half 79, 151, 65, 79
	.word SAW_P
SAW4:
	.word SAW4_IMG
	.half 74, 157, 77, 74
SAW6:
	.word SAW6_IMG
	.half 78, 154, 83, 78

THRONEWALL:
	.word THRONEWALL_IMG
	.half 71, 183, 0, 0
	.word BGHD3_P

	.align 2	
#include "pit.att"
 	
	.align 2
	.globl pit_dict
pit_dict:
#include "pit.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkthrone.umd"

	.align 2
	.globl pit_module
pit_module:
	.half	0			 	/* autoerase color */
	.half	0x00   	 		/* initial world y */
	.half	0xd4			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640			   	/* scroll right limit */

	.word	calla_pit			/* routine to call */
	.word	pit_scroll			/* scroll table */
	.word	dlists_pit

	.word	bakmods
	.word	MKPIT1BMOD			/* baklst1 = floor */
	.half	0x18,0xffe2
	.word	MKPIT2BMOD			/* baklst2 = side nose */
	.half	0x00,0x04
	.word	MKPIT3BMOD			/* baklst3 = lights */
	.half	0xfff8,0x66
	.word	MKPIT4BMOD			/* baklst4 = backplane */
	.half	0xfff0,0x1e+10

	.word	CENTER_X
	.word	MKPIT1BMOD,worldtlx1
	.word	MKPIT2BMOD,worldtlx2
	.word	MKPIT3BMOD,worldtlx3
	.word	MKPIT4BMOD,worldtlx4
	.word	0,0

pit_scroll:
	.word	0*SCX/100				/* 8 */
	.word	0*SCX/100				/* 7 */
	.word	0x00*SCX/100				/* 6 */
	.word	0x00*SCX/100				/* 5 */
	.word	0*SCX/100			/* 4 */
	.word	0x8000*SCX/100			/* 3 */
	.word	0xc000*SCX/100			/* 2 */
	.word	0x20000*SCX/100			/* 1 */
	.word	0x20000*SCX/100			/* player list */

dlists_pit:
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0


