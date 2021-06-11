#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mksteel.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III steel Module
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
#include "steelvs.rgb"

	.align 2
#include "vspal.mas"
 
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl	steel_anims
steel_anims:

	.align 2
	.globl a_mklight
a_mklight:
	.word MKLIGHT1
	.word MKLIGHT4
	.word MKLIGHT7
	.word MKLIGHT10
	.word MKLIGHT13
	.word MKLIGHT16
	.word MKLIGHT19
	.word ani_jump
	.word a_mklight

	.align 2
	.globl a_vs_v
a_vs_v:
	.word BURNV1
	.word BURNV2
	.word BURNV3
	.word BURNV4
	.word BURNV5
	.word BURNV6
	.word BURNV7
	.word BURNV8
	.word BURNV9
	.word BURNV10
	.word BURNV11
	.word BURNV12
	.word BURNV13
	.word 0

	.align 2
	.globl a_vs_s
a_vs_s:
	.word BURNS1
	.word BURNS2
	.word BURNS3
	.word BURNS4
	.word BURNS5
	.word BURNS6
	.word BURNS7
	.word BURNS8
	.word BURNS9
	.word BURNS10
	.word BURNS11
	.word BURNS12
	.word BURNS13
	.word BURNS14
	.word BURNS15
	.word 0

	.align 2
	.globl battle_digits
battle_digits:
	.word BATTLE0
	.word BATTLE1
	.word BATTLE2
	.word BATTLE3
	.word BATTLE4
	.word BATTLE5
	.word BATTLE6
	.word BATTLE7
	.word BATTLE8
	.word BATTLE9
	.word 0
	
	
	.globl MKLIGHT1
MKLIGHT1:
	.word MKLIGHT1_IMG
	.half 54, 65, 0, 0
	.word mKlIGHT_p
MKLIGHT4:
	.word MKLIGHT4_IMG
	.half 54, 65, 0, 0
MKLIGHT7:
	.word MKLIGHT7_IMG
	.half 53, 65, 0, 0
MKLIGHT10:
	.word MKLIGHT10_IMG
	.half 53, 65, 0, 0
MKLIGHT13:
	.word MKLIGHT13_IMG
	.half 53, 65, 0, 0
MKLIGHT16:
	.word MKLIGHT16_IMG
	.half 54, 65, 0, 0
MKLIGHT19:
	.word MKLIGHT19_IMG
	.half 53, 65, 0, 0
	
	.globl BURNV1
BURNV1:
	.word BURNV1_IMG
	.half 18, 14, -1, -8
	.word BURNVS_P
BURNV2:
	.word BURNV2_IMG
	.half 20, 14, 0, -10
BURNV3:
	.word BURNV3_IMG
	.half 25, 12, 0, -10
BURNV4:
	.word BURNV4_IMG
	.half 31, 11, -1, -10
BURNV5:
	.word BURNV5_IMG
	.half 41, 12, -1, -10
BURNV6:
	.word BURNV6_IMG
	.half 39, 14, -3, -10
BURNV7:
	.word BURNV7_IMG
	.half 38, 18, -3, -10
BURNV8:
	.word BURNV8_IMG
	.half 38, 19, -3, -10
BURNV9:
	.word BURNV9_IMG
	.half 38, 22, -3, -10
BURNV10:
	.word BURNV10_IMG
	.half 43, 27, -3, -5
BURNV11:
	.word BURNV11_IMG
	.half 44, 29, -3, -4
BURNV12:
	.word BURNV12_IMG
	.half 48, 30, -3, 0
BURNV13:
	.word BURNV13_IMG
	.half 49, 31, -3, 1
	.globl BURNS1
BURNS1:
	.word BURNS1_IMG
	.half 14, 10, -21, -1
	.word BURNVS_P
BURNS2:
	.word BURNS2_IMG
	.half 16, 10, -21, 1
BURNS3:
	.word BURNS3_IMG
	.half 14, 15, -16, -3
BURNS4:
	.word BURNS4_IMG
	.half 16, 17, -14, -3
BURNS5:
	.word BURNS5_IMG
	.half 20, 20, -11, -3
BURNS6:
	.word BURNS6_IMG
	.half 26, 26, -5, -3
BURNS7:
	.word BURNS7_IMG
	.half 26, 22, -9, -3
BURNS8:
	.word BURNS8_IMG
	.half 26, 22, -9, -3
BURNS9:
	.word BURNS9_IMG
	.half 31, 22, -9, -3
BURNS10:
	.word BURNS10_IMG
	.half 34, 22, -9, -3
BURNS11:
	.word BURNS11_IMG
	.half 38, 22, -9, -3
BURNS12:
	.word BURNS12_IMG
	.half 43, 22, -9, -3
BURNS13:
	.word BURNS13_IMG
	.half 46, 25, -6, -3
BURNS14:
	.word BURNS14_IMG
	.half 48, 28, -3, -3
BURNS15:
	.word BURNS15_IMG
	.half 49, 31, 0, -3
	.globl BATTLE
BATTLE:
	.word BATTLE_IMG
	.half 16, 140, 0, 0
	.word BATTLE_P
	.globl BATTLE0
BATTLE0:
	.word BATTLE0_IMG
	.half 15, 28, 14, -4
	.word BATTLE_P
BATTLE1:
	.word BATTLE1_IMG
	.half 15, 19, 11, -4
BATTLE2:
	.word BATTLE2_IMG
	.half 15, 27, 14, -4
BATTLE3:
	.word BATTLE3_IMG
	.half 16, 26, 14, -4
BATTLE4:
	.word BATTLE4_IMG
	.half 15, 30, 14, -4
BATTLE5:
	.word BATTLE5_IMG
	.half 15, 26, 13, -5
BATTLE6:
	.word BATTLE6_IMG
	.half 15, 28, 14, -5
BATTLE7:
	.word BATTLE7_IMG
	.half 15, 25, 11, -5
BATTLE8:
	.word BATTLE8_IMG
	.half 15, 26, 14, -5
BATTLE9:
	.word BATTLE9_IMG
	.half 15, 29, 14, -5
	
	.globl BOX2
BOX2:
	.word BOX2_IMG
	.half 18, 118, 0, 0
	.word BOX1_P

	.align 2
	.globl symbol_table
symbol_table:
	.word I_DRAGON
	.word I_MK
	.word I_YINYANG
	.word I_THREE
	.word I_QUESTION
	.word I_LIGHTNING
	.word I_GORO
	.word I_RAIDEN
	.word I_SHOKAHN
	.word I_SKULL
	.word I_QUESTION
	.word I_QUESTION
	.word I_RAIDEN
	.word I_MK
	.word I_DRAGON
	.word I_SKULL
	.word I_GORO
	.word I_THREE
	.word I_LIGHTNING
	.word I_DRAGON
	.word I_YINYANG
	.word I_SHOKAHN
	.word I_GORO
	.word I_MK
	
	.globl I_DRAGON
I_DRAGON:
	.word I_DRAGON_IMG
	.half 14, 17, 0, 0
	.word IDRAG_P
I_MK:
	.word I_MK_IMG
	.half 14, 17, 0, 0
	.word IMK_P
I_YINYANG:
	.word I_YINYANG_IMG
	.half 14, 17, 0, 0
	.word IYIN_P
I_THREE:
	.word I_THREE_IMG
	.half 14, 17, 0, 0
	.word ITHREE_P
I_QUESTION:
	.word I_QUESTION_IMG
	.half 14, 17, 0, 0
	.word IQ_P
I_LIGHTNING:
	.word I_LIGHTNING_IMG
	.half 14, 17, 0, 0
	.word ILIGHT_P
I_GORO:
	.word I_GORO_IMG
	.half 14, 17, 0, 0
	.word IGORO_P
I_RAIDEN:
	.word I_RAIDEN_IMG
	.half 14, 17, 0, 0
	.word IRAID_P
I_SHOKAHN:
	.word I_SHOKAHN_IMG
	.half 14, 17, 0, 0
	.word IKAHN_P
I_SKULL:
	.word I_SKULL_IMG
	.half 14, 17, 0, 0
	.word ISKULL_P


	.align 2
	.globl vs_dict
vs_dict:
#include "../../attract/vs/vs.dct"
	.align 2
#include "../../attract/vs/vs.att"

	.align 2
	.globl symbol_dict
symbol_dict:	
#include "../../common/symbols/symbol.dct"

	.align 2
#include "../../common/symbols/symbol.att"


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "steelvs.umd"
		  
	.align 2
	.globl vs_module
vs_module:
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

	.word	STEELMODBMOD
	.half	0xfffe,0x07
	.word	0xffffffff
	.word	0				/* no floor here !! */
		  
	.align 2
	.globl bvs_module
bvs_module:
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

	.word	BSTEELMODBMOD
	.half	0xfffe,0x07
	.word	0xffffffff
	.word	0				/* no floor here !! */

