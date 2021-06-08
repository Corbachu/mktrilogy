#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkoption.s
;
; By: David Schwartz
;
; Date: March 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III option Animation Tables
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern no_scroll	 
	.extern dlists_bogus 

/*
;*********************************
;**			PALETTES		**
;*********************************
*/
	.align 2

#include "nuoption.mas" 


/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

nuoptions_anims:
ICONS_anims:

	.globl ICON_GAME
ICON_GAME:
	.word U64GAMEK64_IMG
	.half 81, 86, 0, 0
	.word	GAMEP

	.globl ICON_KOMBAT
ICON_KOMBAT:
	.word KOMBAT64_IMG
	.half 81, 86, 0, 0
	.word	KOMBATP

	.globl ICON_KONTROL
ICON_KONTROL:
	.word U64KONTR64_IMG
	.half 81, 86, 0, 0
	.word KONTROLP

 	.globl ICON_SOUND
ICON_SOUND:
	.word SOUND64_IMG
	.half 81, 86, 0, 0
	.word SOUNDP

	.globl ICON_QUESTION1
ICON_QUESTION1:
	.word QUESTION64_IMG
	.half 81, 86, 0, 0
	.word QUESTIONP

	.globl ICON_QUESTION2
ICON_QUESTION2:
	.word QUESTION64_IMG
	.half 81, 86, 0, 0
	.word QUESTIONP_C1
	
	.globl ICON_QUESTION3
ICON_QUESTION3:
	.word QUESTION64_IMG
	.half 81, 86, 0, 0
	.word QUESTIONP_C2
	
	.globl ICON_QUESTION4
ICON_QUESTION4:
	.word QUESTION64_IMG
	.half 81, 86, 0, 0
	.word QUESTIONP

	.globl icon_list
icon_list:
	.word	ICON_KOMBAT
	.word	ICON_GAME
	.word	ICON_KONTROL
	.word	ICON_SOUND
	.word	ICON_QUESTION1
	.word	ICON_QUESTION2
	.word	ICON_QUESTION3
	.word	ICON_QUESTION4

	.globl button_list
button_list:
	.word	BUT_A
	.word	BUT_B
	.word	BUT_L
	.word	BUT_R
	.word	BUT_YUP
	.word	BUT_YDOWN
	.word	BUT_YLEFT
	.word	BUT_YRIGHT
	
	
BUT_A:
	.word A_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_B:
	.word B_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_L:
	.word L_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_R:
	.word R_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_YUP:
	.word YUP_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_YLEFT:
	.word YLEFT_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_YRIGHT:
	.word YRIGHT_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL
BUT_YDOWN:
	.word YDOWN_IMG
	.half 13, 13, 0, 0
	.word BUTTON_PAL

	.align 2
#include "option.att"

	.align 2
#include "button.att"

	.align 2
	.globl button_dict
button_dict:
#include "button.dct"

	.align 2
	.globl option_dict
option_dict:
#include "option.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "option.umd"

	.align 2
	.globl nuoptions_module
nuoptions_module:
	.half	0		 		/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0x00	     			/* ground y */
	.half	0x00				/* initial worldx */
	.half	-0x500 	  			/* scroll left limit */
	.half	0x500	  			/* scroll right limit */

	.word	calla_return
	.word	no_scroll			/* scroll table */
	.word	dlists_bogus

	.word	bakmods

	.word	optionBMOD
	.half	0xfff6+5,0xfff0+12
	.word	0xffffffff
	.word	0				/* no floor here !! */

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	dlists_buyin 

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.align 2

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
	.globl nuoptcoin_module
nuoptcoin_module:
	.half	0		 		/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0x00	     			/* ground y */
	.half	0x00				/* initial worldx */
	.half	-0x500 	  			/* scroll left limit */
	.half	0x500	  			/* scroll right limit */

	.word	calla_return
	.word	no_scroll			/* scroll table */
	.word	dlists_coin

	.word	bakmods

	.word	optionBMOD
	.half	0xfff6+5,0xfff0+12
	.word	0xffffffff
	.word	0				/* no floor here !! */

	.extern half_combine_mode
	.extern	default_combine_mode

dlists_coin:
	.word	-1,half_combine_mode
	.word	baklst4,worldtlx
	.word	baklst3,worldtlx
	.word	baklst2,worldtlx
	.word	baklst1,worldtlx
	.word	-1,default_combine_mode														 
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0




















				 
