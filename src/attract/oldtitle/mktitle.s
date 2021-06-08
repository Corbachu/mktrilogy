#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data
									 
/*
;******************************************************************************
; File: mktitle.s
;
; By: David Schwartz
;
; Date: Feb 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III title Module
;*****************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
															   
	.extern	dlists_buyin
	.extern	no_scroll

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.align 2
#include "titlepal.mas"

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
      
/*
;*********************************
;**		 MODULE DATA  MK3 LOGO			**
;*********************************
*/
	.align 2
#include "nutitle.umd"

	.align 2
	.globl title_module

title_module:
	.half	NULL_IRQSKYE  	 	/* autoerase color */
	.half	0	      		/* initial world y */
	.half	0	      		/* ground y */
	.half	0	      		/* initial worldx */
	.half	0 	      		/* scroll left limit */
	.half	0	      		/* scroll right limit */
	.word	calla_return
	.word	no_scroll     		/* scroll table */
	.word	dlists_buyin
	.word	bakmods																			  
   	.word	titlemodBMOD
	.half	0xfffa,0xfffc
  	.word	FORCE_EXIT
	.word	0

/*
;*********************************
;**		 MODULE DATA  LEGALS		**
;*********************************
*/
	.align 2
#include "legal2.umd"

	.align 2
	.globl legal_module

legal_module:
	.half	0	/*NULL_IRQSKYE  	 	; autoerase color */
	.half	0	      		/* initial world y */
	.half	0	      		/* ground y */
	.half	0	      		/* initial worldx */
	.half	0 	      		/* scroll left limit */
	.half	0	      		/* scroll right limit */
	.word	calla_return
	.word	no_scroll     		/* scroll table */
	.word	dlists_buyin
	.word	bakmods
	.word	legalmodBMOD
	.half	-16,-4
	.word	FORCE_EXIT
	.word	0



