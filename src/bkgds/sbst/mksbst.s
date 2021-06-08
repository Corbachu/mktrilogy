#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mksbst.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Subway Street Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_subway	
	.extern	calla_street	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern MKSUBRAW_CLT	
	.extern RAIL_P			
	.extern P_RAILGLM		
	.extern P_DLITE			
	.extern P_DARK11		
	.extern P_DARK3			
	.extern P_DARK6			
	.extern P_DARK8			
	.extern TRAIN_P			
	.extern P_LITE11		
	.extern P_LITE8			
	.extern SMALL_p			
	.extern MEDIUM_p		
	.extern STBREAK_P		
	.extern subflor_PAL		
	.extern mkstreet_CLT	
	.extern street_PAL		
	.extern PAPER_P			

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
;*****************
;*  module: subway
;*****************
*/
	.align 2
street_anims:
bkgd_subway_anims:

	.globl	BKRAIL
	.globl	FRTRAIL
	.globl	RAILGLEAM
	.globl	TRAINA
	.globl	TRAINB
	.globl	TRAINC
	.globl	LITE1
	.globl	LITE2
	.globl	LITE3
	.globl	LITE4
	.globl	LITE6
	.globl	LITE7
	.globl	LITE8
	.globl	LITE9
	.globl	LITE10
	.globl	LITE11
	.globl	DARK1
	.globl	DARK2
	.globl	DARK3
	.globl	DARK4
	.globl	DARK6
	.globl	DARK7
	.globl	DARK8
	.globl	DARK9
	.globl	DARK10
	.globl	DARK11





BKRAIL:
	.word BKRAIL1_IMG
	.half 8, 161, 0, 0
	.word RAIL_P
FRTRAIL:
	.word FRTRAIL1_IMG
	.half 9, 161, 0, 0
	.word RAIL_P
RAILGLEAM:
	.word RAILGLEAM_IMG
	.half 1, 103, 0, 0
	.word P_RAILGLM
DARK10:
	.word DARK10_IMG
	.half 5, 58, 31, 20
	.word	0
DARK11:
	.word DARK11_IMG
	.half 31, 25, 29, -25
	.word	0
DARK1:
	.word DARK1_IMG
	.half 10, 88, 94, 31
	.word	0
DARK2:
	.word DARK2_IMG
	.half 10, 90, 6, 31
	.word	0
DARK3:
	.word DARK3_IMG
	.half 92, 6, 83, 27
	.word	0
DARK4:
	.word DARK4_IMG
	.half 90, 6, 83, 27
	.word	0
DARK6:
	.word DARK6_IMG
	.half 11, 87, 94, -56
	.word	0
DARK7:
	.word DARK7_IMG
	.half 11, 90, 7, -56
	.word	0
DARK8:
	.word DARK8_IMG
	.half 11, 90, 94, -56
	.word	0
DARK9:
	.word DARK9_IMG
	.half 5, 60, 34, 20
	.word	0
LITE1:
	.word LITE1_IMG
	.half 10, 88, 94, 31
	.word	0
LITE10:
	.word LITE10_IMG
	.half 5, 58, 34, 20
	.word	0
LITE11:
	.word LITE11_IMG
	.half 31, 25, 29, -25
	.word	0
LITE2:
	.word LITE2_IMG
	.half 10, 90, 6, 31
	.word	0
LITE3:
	.word LITE3_IMG
	.half 91, 6, 83, 27
	.word	0
LITE4:
	.word LITE4_IMG
	.half 90, 6, 83, 27
	.word	0
LITE6:
	.word LITE6_IMG
	.half 11, 87, 94, -56
	.word	0
LITE7:
	.word LITE7_IMG
	.half 11, 90, 7, -56
	.word	0
LITE8:
	.word LITE8_IMG
	.half 11, 90, 94, -56
	.word	0
LITE9:
	.word LITE9_IMG
	.half 5, 60, 34, 20
	.word	0
TRAINA:
	.word TRAINA_IMG
	.half 81, 74, 0, 0
	.word TRAIN_P
TRAINB:
	.word TRAINB_IMG
	.half 81, 65, 0, 0
	.word TRAIN_P
TRAINC:
	.word TRAINC_IMG
	.half 81, 80, 0, 0
	.word TRAIN_P

#include "sbst.att"

	.align 2
	.globl sbst_dict
sbst_dict:
#include "sbst.dct"


/*
;*********************************
;**		 MODULE DATA			**
;*********************************
;*****************
;*  module: subway
;*****************
*/
	.align 2
#include "mksubway.umd"

	.align 2
	.globl subway_module
subway_module:
 	.half	0			 		/* autoerase color */
	.half	16 					/* initial world y */
	.half	0xe5 			  	/* ground y offset */
	.half	480			  		/* initial world x */
	.half	0+64	 			/* scroll left limit */
	.half	944-64 /*999 		; scroll right limit */

	.word	calla_subway
	.word	subway_scroll		/* scroll table */
	.word	dlists_subway

	.word	bakmods
	.word	SKIP_BAKMOD			/* baklst1 = skip (players) */
	.word	SKIP_BAKMOD			/* baklst2 = skip (gleam) */
	.word	SKIP_BAKMOD			/* baklst3 = skip (gleam) */
	.word	SKIP_BAKMOD			/* baklst4 = skip (rails) */
	.word	SUBWAY1BMOD			/* baklst5 = front plane / pillars */
	.half	0x00,0xff84+16
	.word	SKIP_BAKMOD			/* baklst6 = train */
	.word	SUBWAY2BMOD			/* baklst7 = blurry back wall */
	.half	0x00,0x23+16+1

	.word	CENTER_X
	.word	SUBWAY1BMOD,worldtlx1	/* gleam */
	.word	SUBWAY1BMOD,worldtlx2	/* gleam */
	.word	SUBWAY1BMOD,worldtlx4	/* lit/unlit */
	.word	SUBWAY1BMOD,worldtlx5	/* front plane */
	.word	SUBWAY2BMOD,worldtlx7	/* blurry back wall */
	.word	END_LIST				/* endlist */

	.word 	_subflrSegmentRomStart
	.word 	_subflrSegmentRomEnd
	.word	subflor_PAL		 		/* palette for floor */
	.word	72						/* floor height */
	.word	scrollx5				/* which scroll variable to follow */
	.word	skew_7

subway_scroll:
	.word	0*SCX/100 			/* 8 */
	.word	0x8000*SCX/100 		/* 7 - back */
	.word	0*SCX/100 			/* 6 - train */
	.word	0x14000*SCX/100 		/* 5 - front */
	.word	0x14000*SCX/100 		/* 4 - lit/unlit images */
	.word	0*SCX/100  			/* 3 - rails */
	.word	0x14000*SCX/100 		/* 2 - gleams of light #2 */
	.word	0x14000*SCX/100 		/* 1 - gleams of light #1 */
	.word	0x20000*SCX/100 		/* player list */

dlists_subway:
	.word	baklst7,worldtlx7		/* blurry wall */
	.word	baklst6,worldtlx6		/* train */
	.word	baklst4,worldtlx4  		/* lit / unlit */
	.word	baklst5,worldtlx5		/* front / pillars */
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	baklst3,worldtlx3		/* rails */
	.word	baklst2,worldtlx2		/* gleam */
	.word	baklst1,worldtlx1		/* gleam */
	.word	objlst,worldtlx		/* players */
 	.word	objlst2,worldtlx		/* text */
	.word	0

/*
;*****************
;*  module: street										*
;*****************
*/
	.align 2
#include "mkstreet.umd"

	.align 2
	.globl 	street_module
street_module:
	.half	0x00			/* background color */
	.half	0x00	  		/* initial world y */
	.half	0xe0	/*0xf6	; ground y offset */

	.half	320			/* initial world x */
	.half	0	  		/* scroll left limit */
	.half	694			/* scroll right limit */
	.word	calla_street
	.word	street_scroll	  	/* scroll table */
	.word	dlists_street
	.word	bakmods
	.word	street1BMOD	  	/* baklst1 = strip ontop of floor */
	.half	0x00,14-0x10
	.word	street2BMOD	  	/* baklst2 = small street */
	.half	0x00,0xa5-0x10
	.word	street3BMOD	  	/* baklst3 = blds */
	.half	0x4,0xffe0
	.word	SKIP_BAKMOD		/* baklst4 */
	.word	street4BMOD	  	/* baklst5 = tower */
	.half	0xfff8,0x2a-0x10

	.word	CENTER_X
	.word	street1BMOD,worldtlx1
	.word	street2BMOD,worldtlx2
	.word	street3BMOD,worldtlx3
	.word	street4BMOD,worldtlx5
	.word	END_LIST

	.word	_streetflrSegmentRomStart
	.word	_streetflrSegmentRomEnd
	.word	street_PAL	   	/* palette for floor */
	.word	43				/* skew height */ 
	.word	scrollx1		/* which scroll variable to follow */
	.word	skew_7

street_scroll:
	.word	0*SCX/100  		/* 8 */
	.word	0*SCX/100  		/* 7 */
	.word	0*SCX/100 		/* 6 */
	.word	0*SCX/100 		/* 5 */
	.word	0*SCX/100 		/* 4 */
	.word	0x10000*SCX/100 		/* 3 */
	.word	0x14000*SCX/100 			/* 2 */
	.word	0x1a000*SCX/100 			/* 1 */
	.word	0x20000*SCX/100 			/* player object list */

dlists_street:
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	baklst4,worldtlx1
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.align 2
	.globl dlists_subway_to_street
dlists_subway_to_street:
	.word	-1,use_worldtly_t
	.word	baklst8_t,worldtlx8_t		/* blurry wall */
	.word	baklst7_t,worldtlx7_t		/* train */
	.word	baklst6_t,worldtlx6_t		/* front / pillars */
	.word	baklst5_t,worldtlx5_t		/* lit / unlit */
	.word	baklst4_t,worldtlx4_t		/* rails */
	.word	baklst3_t,worldtlx3_t		/* gleam */
	.word	baklst2_t,worldtlx2_t		/* gleam */
	.word	objlst_t,worldtlx_t	    /* players */

	.word	-1,check_only_t
	.word	-1,use_worldtly
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
/*	.word	baklst4,worldtlx4 */
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	-1,floor_code
	.word	baklst1,worldtlx1
	.word	baklst4,worldtlx1
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlists_end
dlists_end:
	.word	0
