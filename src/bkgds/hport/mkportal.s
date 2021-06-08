#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkportal.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Portal Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	mk3_calla	

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern MKHIDDEN_CLT	
	.extern MKHIDx_CLT
	.extern WARP_P			

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
portal_anims:
	.globl	PORTAL01
	.globl	a_portal_zap

a_portal_zap:
	.word PORTAL01
	.word PORTAL02
	.word PORTAL03
	.word PORTAL04
	.word PORTAL05
	.word PORTAL06
	.word PORTAL07
	.word PORTAL08
	.word PORTAL09
	.word PORTAL11
	.word PORTAL12
	.word PORTAL13
	.word PORTAL14
	.word PORTAL17
	.word 0
PORTAL01:
	.word PORTAL01_IMG
	.half 8, 18, 0, 0
	.word WARP_P
PORTAL02:
	.word PORTAL02_IMG
	.half 26, 31, 0, 0
PORTAL03:
	.word PORTAL03_IMG
	.half 26, 30, 0, 0
PORTAL04:
	.word PORTAL04_IMG
	.half 24, 31, 0, -1
PORTAL05:
	.word PORTAL05_IMG
	.half 21, 30, 0, -2
PORTAL06:
	.word PORTAL06_IMG
	.half 17, 25, -1, -5
PORTAL07:
	.word PORTAL07_IMG
	.half 14, 21, -2, -8
PORTAL08:
	.word PORTAL08_IMG
	.half 7, 12, -8, -12
PORTAL09:
	.word PORTAL09_IMG
	.half 9, 9, -10, -9
PORTAL11:
	.word PORTAL11_IMG
	.half 9, 14, -10, -4
PORTAL12:
	.word PORTAL12_IMG
	.half 17, 22, -4, -3
PORTAL13:
	.word PORTAL13_IMG
	.half 15, 18, -5, -5
PORTAL14:
	.word PORTAL14_IMG
	.half 14, 15, -7, -6
PORTAL17:
	.word PORTAL17_IMG
	.half 9, 9, -9, -8
	
#include "hportal.att"	

	.align 2
	.globl hport_dict
hport_dict:
#include "hportal.dct"	

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkhidden.umd"

	.align 2
	.globl portal_module
portal_module:
	.half	0			 	/* autoerase color */
	.half	0x00   	 		   	/* initial world y */
	.half	0xd0			   	/* ground y offset */
	.half	320			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640		   	/* scroll right limit */

	.word	mk3_calla			/* routine: make lightning proc */
	.word	portal_scroll			/* scroll table */
	.word	dlists_portal

	.word	bakmods
	.word	SKIP_BAKMOD 	 		/* baklst1 = skip (lightning) */
	.word	HIDDEN1BMOD			/* baklst2 = floor */
	.half	0x00,0xb0
	.word	HIDDEN2BMOD			/* baklst3 = portal sky */
	.half	0x00,0xFFF0

	.word	CENTER_X
	.word	HIDDEN2BMOD,worldtlx1
	.word	HIDDEN1BMOD,worldtlx2
	.word	HIDDEN2BMOD,worldtlx3
	.word	0,0

portal_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 */
	.word	0		/* 6 */
	.word	0		/* 5 */
	.word	0		/* 4 */
	.word	0		/* 3 */
	.word	0x20000*SCX/100		/* 2 */
	.word	0		/* 1 */
	.word	0x20000*SCX/100			/* player list */

dlists_portal:
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

