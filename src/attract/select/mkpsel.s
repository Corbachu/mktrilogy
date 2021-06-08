#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkpsel.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Mortal Kombat Player Select
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern no_scroll
	.extern boonpal
	.extern	mk3_calla
/*
;*********************************
;**			PALETTES
;*********************************
*/

	.align 2
#include "nuselpal.mas"

#include "../gradient/arcpal.mas"


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

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2
	.globl select_dict
select_dict:	
#include "ladder.dct"


psel_anims:
mugshot_anims:
ladder_anims:


	.align 2
	.globl emh_images
emh_images:
	.word TXT_NOVICE
	.word TXT_WARRIOR
	.word TXT_MASTER
	.word TXT_CHAMPION
	.globl TXT_NOVICE
TXT_NOVICE:
	.word TXT_NOVICE_IMG
	.half 8, 37, 0, 0
	.word boonpal
TXT_WARRIOR:
	.word TXT_WARRIOR_IMG
	.half 8, 46, 0, 0
	.word boonpal
TXT_MASTER:
	.word TXT_MASTER_IMG
	.half 8, 41, 0, 0
	.word boonpal
TXT_CHAMPION:
	.word TXT_CHAMPION_IMG
	.half 8, 51, 14, 0
	.word boonpal

#if 0	
	.globl UPEVILB
UPEVILB:
	.word bottom2_IMG
	.half 12, 160, 0, 0
	.word   bottom_PAL

	.globl UPEVILA
UPEVILA:
	.word bottom1_IMG
	.half 12, 160, 0, 0
	.word   bottom_PAL
#endif
 
	.globl MKBRICK
MKBRICK:
	.word ladbricka_IMG
	.half 72, 135, 0, 0
	.word bricka_PAL
				 
	.globl MKBRICK2
MKBRICK2:
	.word ladbrickb_IMG
	.half 29, 135, -41, -17
	.word brickb_PAL

	.globl NSCURSOR
NSCURSOR:
	.word NSCURSOR_IMG
	.half 45, 34, 0, 0



	.align 2
#include "ladder.att"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/

	.align 2
#include "nuselect.umd"

	.align 2
	.globl psel_module
psel_module:
	.half	0x00	 	 	/* autoerase color */

	.half	0	 		/* initial world y */
	.half	0xed-15	 		/* ground y */
	.half	0			/* initial worldx */
	.half	-0x50 	  		/* scroll left limit */
	.half	0xfff	  		/* scroll right limit */

	.word	calla_return
	.word	no_scroll		/* scroll table */
	.word	dlists_psel

	.word	bakmods
	.word	bgmodBMOD
	.half	0,43
	.word	diaz1modBMOD
	.half	0,180-4+9+8+6
	.word	diaz2modBMOD
	.half	197+18-3,180+9+8+6-2
	.word 	SKIP_BAKMOD
	.word	FORCE_EXIT
	.word	0
 
dlists_psel:
	.word	baklst1,worldtlx 
	.word 	baklst4,worldtlx
	.word	baklst3,worldtlx 
	.word	baklst2,worldtlx 
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

/*
;********************************* 
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "nuladz.umd"

	.align 2
	.globl ladder_module
ladder_module:
	.half	0		 		/* autoerase color */
	.half	0x00				/* initial world y */
	.half	0x00	     			/* ground y */
	.half	0x00				/* initial worldx */
	.half	-0x500 	  			/* scroll left limit */
	.half	0x500	  			/* scroll right limit */

	.word	calla_return
	.word	no_scroll			/* scroll table */
	.word	dlists_ladder
	.word	bakmods
	.word	SKIP_BAKMOD 	 		/* baklst1 = lightning */
	.word	SKIP_BAKMOD 	 		/* baklst2 = */
	.word	SKIP_BAKMOD 	 		/* baklst3 = */
	.word	SKIP_BAKMOD 	 		/* baklst4 = */
	.word	SKIP_BAKMOD 	 		/* baklst5 = */
	.word	SKIP_BAKMOD 	 		/* baklst6 = */
	.word	SKIP_BAKMOD 	 		/* baklst7 = */
	.word	ladmod1BMOD			/* baklst8 */
	.half	-100,-100
	.word	0xffffffff
	.word	0				/* no floor here !! */


dlists_ladder:
	.word	baklst9,worldtlx

	.word	baklst8,worldtlx
	.word	baklst7,worldtlx

	.word	baklst6,worldtlx
	.word	baklst5,worldtlx

	.word	baklst4,worldtlx
	.word	baklst3,worldtlx	
	.word	baklst2,worldtlx
	.word	baklst1,worldtlx

	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
	.globl fire_module
fire_module:
	.half	0x00    	 	/* autoerase color */
	.half	0x00    		/* initial world y */
	.half	0xe8   		/* ground y */
	.half	0x00		/* initial worldx */
	.half	-0x50 		/* scroll left limit */
	.half	0xfff		/* scroll right limit */

	.word	calla_return
	.word	no_scroll 	/* scroll table */
	.word	dlists_fireport

	.word	bakmods
	.word	SKIP_BAKMOD     /* baklst1 = skip */
	.word	ladmod1BMOD
	.half	-100,-100
	.word	0xffffffff
	.word	0

	.align 2
	.globl firedark_module
firedark_module:
	.half	0x00    	 	/* autoerase color */
	.half	0x00    		/* initial world y */
	.half	0xe8   		/* ground y */
	.half	0x00		/* initial worldx */
	.half	-0x50 		/* scroll left limit */
	.half	0xfff		/* scroll right limit */

	.word	calla_return
	.word	no_scroll 	/* scroll table */
	.word	dlists_fireport1

	.word	bakmods
	.word	SKIP_BAKMOD     /* baklst1 = skip */
	.word	ladmod1BMOD
	.half	-100,-100
	.word	0xffffffff
	.word	0

dlists_fireport:
	.word	baklst1,worldtlx
	.word	baklst2,worldtlx
	.word	baklst3,worldtlx
	.word	baklst4,worldtlx
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0


	.extern half_combine_mode
	.extern	default_combine_mode
dlists_fireport1:
	.word	-1,half_combine_mode
	.word	baklst1,worldtlx
	.word	baklst2,worldtlx
	.word	baklst3,worldtlx
	.word	baklst4,worldtlx
	.word	-1,default_combine_mode														 
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0



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
#include "../options/option.att"

	.align 2
#include "../options/button.att"

	.align 2
	.globl button_dict
button_dict:
#include "../options/button.dct"

	.align 2
	.globl option_dict
option_dict:
#include "../options/option.dct"
