#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mktourn.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Tournmanet Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	no_scroll 
	.extern	dlists_bogus 

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.align 2
#include "trnpal.mas"

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl	tourn_anims
tourn_anims:
/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "trnment.umd"

	.align 2
	.globl tourn_module
tourn_module:
	.half	0			 	/* autoerase color */
	.half	0   	 		   	/* initial world y */
	.half	0			   	/* ground y offset */
	.half	0			   	/* initial world x */
	.half	0 	  	   		/* scroll left limit */
	.half	640		   	/* scroll right limit */

	.word	calla_return				/* routine: make lightning proc */
	.word	tourn_scroll			/* scroll table */
	.word	dlists_bogus

	.word	bakmods
	.word	tournmodBMOD
	.half	0xfffa+3,-3
	.word	0xffffffff
	.word	0

	.align 2
tourn_scroll:
	.word	0*SCX/100 			/* 8 */
	.word	0*SCX/100 			/* 7 */
	.word	0*SCX/100 			/* 6 */
	.word	0*SCX/100 			/* 5 - */
	.word	0x20000*SCX/100 		/* 4 - */
	.word	0x20000*SCX/100 		/* 3 - fence */
	.word	0x20000*SCX/100 		/* 2 - wall */
	.word	0x20000*SCX/100 		/* 1 - players */
	.word	0x20000*SCX/100 			/* 0 */
