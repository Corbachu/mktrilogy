#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0											  

	.set noreorder
	
	
	.data

/*
;******************************************************************************
; File: mkgrad.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Gradient Modules
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern  no_scroll		
	.extern  dlists_buyin	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern gradientb_CLT  
	.extern gradientr_CLT  
	.extern gradientg_CLT  
#if 0
#include "arcpal.mas"

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.globl expld1
expld1:
	.word expld1_IMG
    .half 11, 12, 0, 0
	.word	expldp3
	.globl expld2
expld2:
	.word expld2_IMG
        .half 21,16, 0, 0
	.word	expldp3
	.globl expld3
expld3:
	.word expld3_IMG
        .half 21,16, 0, 0
	.word	expldp3
	.globl expld4
expld4:
	.word expld4_IMG
        .half 21,16,  0, 0
	.word	expldp3
	.globl expld5
expld5:
	.word expld5_IMG
        .half 20,16 0, 0
	.word	expldp3
	.globl expld6
expld6:
	.word expld6_IMG
        .half 10, 10, 0, 0
	.word	expldp3
	.globl expld7
expld7:
	.word expld7_IMG
        .half 11, 11, 0, 0
	.word	expldp3
	.globl expld8
expld8:
	.word expld8_IMG
        .half 11, 11, 0, 0
	.word	expldp3
	.globl ship1
ship1:
	.word ship1_IMG
        .half 21,14, 0, 0
	.word	shipp1
	.globl ship2
ship2:
	.word ship2_IMG
        .half 21,14, 0, 0
	.word	shipp1
	.globl ship3
ship3:
	.word ship3_IMG
        .half 15, 15, 0, 0
	.word	shipp1
	.globl ship4
ship4:
	.word ship4_IMG
        .half 15, 15, 0, 0
	.word	shipp1
	.globl enemy1
enemy1:
	.word enemy1_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy2
enemy2:
	.word enemy2_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy3
enemy3:
	.word enemy3_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy4
enemy4:
	.word enemy4_IMG
        .half 8, 11, 0, 0
	.word	enemyp
	.globl enemy5
enemy5:
	.word enemy5_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy6
enemy6:
	.word enemy6_IMG
        .half 11, 8, 0, 0
	.word	enemyp
	.globl enemy7
enemy7:
	.word enemy7_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy8
enemy8:
	.word enemy8_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy9
enemy9:
	.word enemy9_IMG
        .half 11, 11, 0, 0
	.word	enemyp
	.globl enemy10
enemy10:
	.word enemy10_IMG
        .half 11, 8, 0, 0
	.word	enemyp
	
	.align 2
#include "../arcade/arcade.att"

	.align 2
	.globl arcade_dict
arcade_dict:	
#include "../arcade/arcade.dct"
#endif
/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "gradient.umd"

	.align 2
	.globl redgrad_module
redgrad_module:
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
	.word	gredmodBMOD
	.half	0xfff2,0xfff8
	.word	FORCE_EXIT
	.word	0

	.align 2
	.globl greengrad_module
greengrad_module:
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
	.word	greenmodBMOD
	.half	0xfff2,0xfff8
	.word	FORCE_EXIT
	.word	0

	.align 2
	.globl bluegrad_module
bluegrad_module:
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
	.word	blumodBMOD
	.half	0xfff2,0xfff8
	.word	FORCE_EXIT
	.word	0





















