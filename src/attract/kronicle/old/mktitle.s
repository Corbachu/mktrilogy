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
	.extern half_combine_mode
	.extern	default_combine_mode

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
#include "trilogy.umd"

	.align 2
	.globl title_module
title_module:
	.half	0	/* NULL_IRQSKYE */ 	 	/* autoerase color */
	.half	0	      		/* initial world y */
	.half	0	      		/* ground y */
	.half	0	      		/* initial worldx */
	.half	0 	      		/* scroll left limit */
	.half	0	      		/* scroll right limit */
	.word	calla_return
	.word	no_scroll     		/* scroll table */
	.word	dlists_buyin
	.word	bakmods																			  
   	.word	plane1BMOD
	.half	-9,-9
  	.word	FORCE_EXIT
	.word	0

/*
;*********************************
;**		 MODULE DATA  LEGALS		**
;*********************************
*/
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
	.word	dlists_legal
	.word	bakmods
   	.word	plane1BMOD
/*	.word	legalmodBMOD */
	.half	-9,-9
	.word	FORCE_EXIT
	.word	0

#if 0
/*
;*********************************
;**		 MODULE DATA  LOGO **
;*********************************
*/
	.align 2
#include "willlogo.umd"

	.align 2
	.globl logo_module

logo_module:
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
	.word	midmodBMOD
	.half	-16+7,-7
	.word	FORCE_EXIT
	.word	0
#endif

dlists_legal:
	.word	-1,half_combine_mode
	.word	baklst4,worldtlx
	.word	baklst3,worldtlx
	.word	baklst2,worldtlx
	.word	baklst1,worldtlx
	.word	objlst,worldtlx
	.word	-1,default_combine_mode
	.word	objlst2,worldtlx
	.word	0

