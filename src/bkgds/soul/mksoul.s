#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mksoul.s
;
; By: David Schwartz
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Soul Module
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_soul	
	.extern	calla_tower	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern MK3SOUL_CLT	
	.extern SONADO_P	
	.extern soflor_PAL	
	.extern STBREAK_P	
	.extern SMALL_p		
	.extern MEDIUM_p	
	.extern MKBALC2z_CLT
	.extern BALFIRE_P	
	.extern BALCO_P		
						 
/*						 
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	
	.align 2
soul_anims:

	.globl SONADO1
	.globl	a_soul_na_do
	.globl	a_torch

a_soul_na_do:
	.word SONADO1
	.word SONADO2
	.word SONADO3
	.word SONADO4
	.word SONADO5
	.word SONADO6
	.word SONADO7
	.word SONADO8
	.word SONADO9
	.word SONADO10
	.word SONADO11
	.word SONADO12
	.word ani_jump
	.word a_soul_na_do
a_torch:
	.word BALFIRE1
	.word BALFIRE2
	.word BALFIRE3
	.word BALFIRE4
	.word BALFIRE5
	.word BALFIRE6
	.word ani_jump
	.word a_torch
SONADO1:
	.word SONADO1_IMG
	.half 83, 34, -15, -56
	.word SONADO_P
SONADO2:
	.word SONADO2_IMG
	.half 83, 34, -15, -56
SONADO3:
	.word SONADO3_IMG
	.half 83, 34, -15, -56
SONADO4:
	.word SONADO4_IMG
	.half 83, 34, -15, -56
SONADO5:
	.word SONADO5_IMG
	.half 83, 34, -15, -56
SONADO6:
	.word SONADO6_IMG
	.half 83, 34, -15, -56
SONADO7:
	.word SONADO7_IMG
	.half 83, 34, -15, -56
SONADO8:
	.word SONADO8_IMG
	.half 83, 34, -15, -56
SONADO9:
	.word SONADO9_IMG
	.half 83, 34, -15, -56
SONADO10:
	.word SONADO10_IMG
	.half 83, 34, -15, -56
SONADO11:
	.word SONADO11_IMG
	.half 83, 34, -15, -56
SONADO12:
	.word SONADO12_IMG
	.half 83, 34, -15, -56
BALFIRE1:
	.word BALFIRE1_IMG
	.half 33, 29, 0, -3
	.word BALFIRE_P
BALFIRE2:
	.word BALFIRE2_IMG
	.half 29, 29, 0, -8
BALFIRE3:
	.word BALFIRE3_IMG
	.half 29, 29, 0, -8
BALFIRE4:
	.word BALFIRE4_IMG
	.half 34, 29, 0, -2
BALFIRE5:
	.word BALFIRE5_IMG
	.half 36, 29, 0, -1
BALFIRE6:
	.word BALFIRE6_IMG
	.half 37, 29, 0, 0

#include "soul.att"

	.align 2
	.globl soul_dict
soul_dict:
#include "soul.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mksoul.umd"

	.align 2
	.globl soul_module
soul_module:
	.half	0						/* autoerase color */
	.half	0						/* initial world y */
	.half	0xdc 					/* ground y */
	.half	320					/* initial world x */
	.half	0 	  			/* scroll left limit */
	.half	640  			/* scroll right limit */

	.word	calla_soul			/* routine to call */
	.word	soul_scroll			/* scroll table */
	.word	dlists_soul

	.word	bakmods
	.word	SOUL1BMOD			/* baklst1 = small lower teeth */
	.half	0x00,0x83
	.word	SOUL2BMOD			/* baklst2 = soul monsters */
	.half	0x00,0x4a
	.word	SKIP_BAKMOD 	 	/* baklst3 = skip (soulnado) */

	.word	SOUL3BMOD			/* baklst4 = skull head */
	.half	0x00,0xffda
	.word	SOUL4BMOD			/* baklst5 = monks */
	.half	0xffb0,0x6c
	.word	SOUL5BMOD			/* baklst6 = back trees */
	.half	0x06,26

	.word	CENTER_X
	.word	SOUL1BMOD,worldtlx1
	.word	SOUL2BMOD,worldtlx2
	.word	SOUL3BMOD,worldtlx3
	.word	SOUL3BMOD,worldtlx4
	.word	SOUL4BMOD,worldtlx5
	.word	SOUL5BMOD,worldtlx6
	.word	END_LIST				/* endlist */

	.word	_soulflrSegmentRomStart
	.word	_soulflrSegmentRomEnd
	.word	soflor_PAL   			/* palette for floor */
	.word	38				/* floor height */
	.word	scrollx1			/* which scroll variable to follow */
	.word	skew_7

soul_scroll:
	.word	0*SCX/100 		/* 8 */
	.word	0*SCX/100 		/* 7 */
	.word	0x8000*SCX/100		/* 6 */
	.word	0xc000*SCX/100			/* 5 */
	.word	0x10000*SCX/100			/* 4 */
	.word	0x10000*SCX/100			/* 3 */
	.word	0x18000*SCX/100			/* 2 */
	.word	0x1c000*SCX/100			/* 1 */
	.word	0x20000*SCX/100			/* player list */

dlists_soul:
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlists_soul_to_tower
dlists_soul_to_tower:
	.word	-1,use_worldtly_t
	.word	baklst7_t,worldtlx7_t
	.word	baklst6_t,worldtlx6_t
	.word	baklst5_t,worldtlx5_t
	.word	baklst4_t,worldtlx4_t
	.word	baklst3_t,worldtlx3_t
	.word	baklst2_t,worldtlx2_t
	.word	baklst1_t,worldtlx1_t
	.word	objlst_t,worldtlx_t

	.word	-1,check_only_t
	.word	-1,use_worldtly

	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	baklst8,worldtlx1		/* torch */
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "mkbalc2.umd"

	.align 2
	.globl tower_module
tower_module:
 	.half	0			 	/* autoerase color */
	.half	0      				/* initial world y */
	.half	0xdc		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	0x10	  			/* scroll left limit */
	.half	0x268				 /* scroll right limit */

	.word	calla_tower
	.word	tower_scroll	  	/* scroll table */
	.word	dlists_tower

	.word	bakmods
	.word	BALCONY1BMOD	  	/* baklst1 = front walls */
	.half	0xffd8,0xffee-44
	.word	BALCONY2BMOD	  	/* baklst2 = 2 side walls */
	.half	0x8,0xffe0
	.word	BALCONY3BMOD	  	/* baklst3 = well */
	.half	0x06,0x60
	.word	BALCONY4BMOD	  	/* baklst4 = pillars */
	.half	0x00,0xfff8
	.word	BALCONY5BMOD	  	/* baklst5 = distant candles */
	.half	0x00,0x30

	.word	CENTER_X
	.word	BALCONY1BMOD,worldtlx1
	.word	BALCONY2BMOD,worldtlx2
	.word	BALCONY3BMOD,worldtlx3
	.word	BALCONY4BMOD,worldtlx4
	.word	BALCONY5BMOD,worldtlx5
	.word	END_LIST

	.word	_balcflrSegmentRomStart
	.word	_balcflrSegmentRomEnd
	.word	BALCO_P		   	/* palette for floor */
	.word	64
	.word	scrollx1
	.word	skew_7


tower_scroll:
	.word	0x0000*SCX/100  /* 8 */
	.word	0x0000*SCX/100  /* 7 */
	.word	0x0000*SCX/100  /* 6 */
	.word	0x4000*SCX/100  /* 5 */
	.word	0x8000*SCX/100  /* 4 */
	.word	0xc000*SCX/100  /* 3 */
	.word	0x10000*SCX/100 /* 2 */
	.word	0x16000*SCX/100 /* 1 */
	.word	0x20000*SCX/100 /* 0 */

dlists_tower:
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	baklst8,worldtlx1		/* torch */
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

/*
;*********************************
;**		 HIDDEN NOWALL MODULE DATA			**
;*********************************
*/

	.align 2
	.globl nowall_module
nowall_module:
 	.half	0			 	/* autoerase color */
	.half	0      				/* initial world y */
	.half	0xdc		  		/* ground y offset */
	.half	320				/* initial world x */
	.half	0x10	  			/* scroll left limit */
	.half	0x268				 /* scroll right limit */

	.word	calla_return
	.word	tower_scroll	  	/* scroll table */
	.word	dlists_tower

	.word	bakmods
/*	.word	BALCONY1BMOD	  	; baklst1 = front walls */
/*	.half	0xffd8,0xffee-44 */
	.word	SKIP_BAKMOD			/* baklst1 = front walls */
	.word	BALCONY2BMOD	  	/* baklst2 = 2 side walls */
	.half	0x8,0xffe0
	.word	BALCONY3BMOD	  	/* baklst3 = well */
	.half	0x06,0x60
	.word	BALCONY4BMOD	  	/* baklst4 = pillars */
	.half	0x00,0xfff8
	.word	BALCONY5BMOD	  	/* baklst5 = distant candles */
	.half	0x00,0x30

	.word	CENTER_X
	.word	BALCONY1BMOD,worldtlx1
	.word	BALCONY2BMOD,worldtlx2
	.word	BALCONY3BMOD,worldtlx3
	.word	BALCONY4BMOD,worldtlx4
	.word	BALCONY5BMOD,worldtlx5
	.word	END_LIST

	.word	_balcflrSegmentRomStart
	.word	_balcflrSegmentRomEnd
	.word	BALCO_P		   	/* palette for floor */
	.word	64
	.word	scrollx1
	.word	skew_7

