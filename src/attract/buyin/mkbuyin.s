#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkbuybt.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Mortal Kombat Buyin Screen
;******************************************************************************
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
	.extern NUBUYIN_CLT	
	.extern nucoin_CLT	
  
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "tribuy.umd"

/*
;**************************************************************************
;*											     *
;*  module: buyin
;*											     *
;**************************************************************************
*/
	.align 2
	.globl buyin_module
buyin_module:
	.half	0		 	/* autoerase color */
	.half	4				/* initial world y */
	.half	0xe8	     			/* ground y */
	.half	6				/* initial worldx */
	.half	-0x50 	  			/* scroll left limit */
	.half	0xfff	  			/* scroll right limit */

	.word	calla_return
	.word	no_scroll			/* scroll table */
	.word	dlists_buyin

	.word	bakmods

	.word	topmodBMOD
	.half	-2,-21+5+4
	.word	botmodBMOD
	.half	-4,0x60+10-3+4+4

	.word	FORCE_EXIT
	.word	0

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "nucoin.umd"

/*
;**************************************************************************
;*											     *
;*  module: mode select
;*											     *
;**************************************************************************
*/
#if 0
	.align 2
	.globl CP_MK1
CP_MK1:
	.word CP_MK1_IMG
	.half 40, 62, -11, -89
	.word CP_MK1_PAL
	
	.align 2
	.globl CP_MK2
CP_MK2:
	.word CP_MK2_IMG
	.half 27, 58, -89, -96
	.word CP_MK2_PAL
	
	.globl CP_MK3
	.align 2
CP_MK3:
	.word CP_MK3_IMG
	.half 57, 61, -166, -85
	.word CP_MK3_PAL
	
	.align 2
	.globl CP_UMK3
CP_UMK3:
	.word CP_UMK3_IMG
	.half 65, 60, -242, -79
	.word CP_UMK3_PAL
#endif

	.align 2
	.globl CP_MORTAL
CP_MORTAL:
	.word MORTAL_IMG
	.half 8, 47, 0,0
	.word NWHITEPAL_PAL

	.align 2
	.globl CP_2ON2
CP_2ON2:
	.word N2ON2_IMG
	.half 8, 37, 0,0
	.word NWHITEPAL_PAL

	.align 2
	.globl CP_3ON3
CP_3ON3:
	.word N3ON3_IMG
	.half 8, 37, 0,0
	.word NWHITEPAL_PAL

	.align 2
	.globl CP_TOURNAMENT
CP_TOURNAMENT:
        .word N8PLAYER_IMG
        .half 8, 51, 0,0
	.word NWHITEPAL_PAL

	.align 2
	.globl CP_KOMBAT
CP_KOMBAT:
	.word KOMBAT_IMG
	.half 8, 49, 0,0
	.word NWHITEPAL_PAL

	.align 2
#include "nucoin.att"

	.align 2
	.globl nucoin_dict
nucoin_dict:	
#include "nucoin.dct"



	.align 2
	.globl mode_coin_module
mode_coin_module:
	.half	0	  	 	/* autoerase color */
	.half	0	      		/* initial world y */
	.half	0	      		/* ground y */
	.half	0	      		/* initial worldx */
	.half	0 	      		/* scroll left limit */
	.half	0	      		/* scroll right limit */
	.word	calla_return
	.word	no_scroll     		/* scroll table */
	.word	dlists_modesel
	.word	bakmods
	.word	coinmodBMOD
	.half	1,-3-8
	.word	0xffffffff
	.word	0

dlists_modesel:
	.word	baklst1,worldtlx
	.word	baklst7,worldtlx
	.word	baklst4,worldtlx
	.word	baklst3,worldtlx
	.word	baklst2,worldtlx

	.word	baklst5,worldtlx
	.word	baklst6,worldtlx

	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0










