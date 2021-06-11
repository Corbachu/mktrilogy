#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mkbrig.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III City Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	bridge_calla 

/*
;*********************************
;**			PALETTES
;*********************************
*/

	.extern MKBRIDGE_CLT 
	.extern PAPER_P		 
	.extern BRGRD_P		  


/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
	.globl bridge_anims
bridge_anims:

/*

	global a_paper1
a_paper1
	.word PAPER1-bridge_anims
	.word PAPER2-bridge_anims
	.word PAPER3-bridge_anims
	.word PAPER4-bridge_anims
	.word PAPER5-bridge_anims
	.word PAPER6-bridge_anims
	.word PAPER7-bridge_anims
	.word PAPER8-bridge_anims
	.word PAPER9-bridge_anims
	.word 0

	global a_big_paper
a_big_paper
	.word LGSHEET1-bridge_anims
	.word LGSHEET2-bridge_anims
	.word LGSHEET3-bridge_anims
	.word LGSHEET4-bridge_anims
	.word LGSHEET5-bridge_anims
	.word LGSHEET6-bridge_anims
	.word LGSHEET7-bridge_anims
	.word LGSHEET8-bridge_anims
	.word LGSHEET9-bridge_anims
	.word ani_jump
	.word a_big_paper-bridge_anims

	global a_lil_paper
a_lil_paper
	.word SMSHEET1-bridge_anims
	.word SMSHEET2-bridge_anims
	.word SMSHEET3-bridge_anims
	.word SMSHEET4-bridge_anims
	.word SMSHEET5-bridge_anims
	.word SMSHEET6-bridge_anims
	.word SMSHEET7-bridge_anims
	.word SMSHEET8-bridge_anims
	.word SMSHEET9-bridge_anims
	.word ani_jump
	.word a_lil_paper-bridge_anims

	global a_leaf
a_leaf
	.word LEAF1-bridge_anims
	.word LEAF2-bridge_anims
	.word LEAF3-bridge_anims
	.word LEAF4-bridge_anims
	.word LEAF5-bridge_anims
	.word LEAF6-bridge_anims
	.word LEAF7-bridge_anims
	.word LEAF8-bridge_anims
	.word ani_jump
	.word a_leaf-bridge_anims

	CNOP 0,4
	global PAPER1
PAPER1
	.word PAPER1_TPG-bridge_anims
	.half 18, 12, 7, 11
	.word   PAPER_P
PAPER1_TPG
	.half	0,   129,   225,    0

	CNOP 0,4
	global PAPER2
PAPER2
	.word PAPER2_TPG-bridge_anims
	.half 18, 12, 7, 11
PAPER2_TPG
	.half	0,   169,   225,    0

	CNOP 0,4
	global PAPER3
PAPER3
	.word PAPER3_TPG-bridge_anims
	.half 18, 12, 7, 11
PAPER3_TPG
	.half	0,   213,   234,    0

	CNOP 0,4
	global PAPER4
PAPER4
	.word PAPER4_TPG-bridge_anims
	.half 18, 11, 7, 10
PAPER4_TPG
	.half	0,   129,   237,    0

	CNOP 0,4
	global PAPER5
PAPER5
	.word PAPER5_TPG-bridge_anims
	.half 18, 10, 7, 9
PAPER5_TPG
	.half	0,   169,   237,    0

	CNOP 0,4
	global PAPER6
PAPER6
	.word PAPER6_TPG-bridge_anims
	.half 19, 10, 7, 9
PAPER6_TPG
	.half	0,   149,   225,    0

	CNOP 0,4
	global PAPER7
PAPER7
	.word PAPER7_TPG-bridge_anims
	.half 20, 12, 7, 11
PAPER7_TPG
	.half	0,   189,   225,    0

	CNOP 0,4
	global PAPER8
PAPER8
	.word PAPER8_TPG-bridge_anims
	.half 19, 14, 9, 13
PAPER8_TPG
	.half	0,    81,   175,    0

	CNOP 0,4
	global PAPER9
PAPER9
	.word PAPER9_TPG-bridge_anims
	.half 20, 15, 8, 14
PAPER9_TPG
	.half	0,   149,   235,    0

	CNOP 0,4
	global LGSHEET1
LGSHEET1
	.word LGSHEET1_TPG-bridge_anims
	.half 9, 17, 4, 8
	.word   PAPER_P
LGSHEET1_TPG
	.half	0,   117,     5,    0

	CNOP 0,4
	global LGSHEET2
LGSHEET2
	.word LGSHEET2_TPG-bridge_anims
	.half 12, 12, 3, 4
LGSHEET2_TPG
	.half	0,   237,    75,    0

	CNOP 0,4
	global LGSHEET3
LGSHEET3
	.word LGSHEET3_TPG-bridge_anims
	.half 14, 11, 2, 3
LGSHEET3_TPG
	.half	0,   237,    96,    0

	CNOP 0,4
	global LGSHEET4
LGSHEET4
	.word LGSHEET4_TPG-bridge_anims
	.half 11, 13, 2, 3
LGSHEET4_TPG
	.half	0,     1,   232,    0

	CNOP 0,4
	global LGSHEET5
LGSHEET5
	.word LGSHEET5_TPG-bridge_anims
	.half 5, 14, 0, 4
LGSHEET5_TPG
	.half	0,    49,   232,     0

	CNOP 0,4
	global LGSHEET6
LGSHEET6
	.word LGSHEET6_TPG-bridge_anims
	.half 11, 13, 5, 3
LGSHEET6_TPG
	.half	0,   237,    62,    0

	CNOP 0,4
	global LGSHEET7
LGSHEET7
	.word LGSHEET7_TPG-bridge_anims
	.half 14, 14, 6, 3
LGSHEET7_TPG
	.half	0,   189,   237,    0

	CNOP 0,4
	global LGSHEET8
LGSHEET8
	.word LGSHEET8_TPG-bridge_anims
	.half 11, 14, 3, 4
LGSHEET8_TPG
	.half	0,   117,    42,    0

	CNOP 0,4
	global LGSHEET9
LGSHEET9
	.word LGSHEET9_TPG-bridge_anims
	.half 9, 14, 3, 6
LGSHEET9_TPG
	.half	0,    13,   232,    0

	CNOP 0,4
	global SMSHEET1
SMSHEET1
	.word SMSHEET1_TPG-bridge_anims
	.half 7, 14, 3, 7
	.word   PAPER_P
SMSHEET1_TPG
	.half	0,   205,   237,     0

	CNOP 0,4
	global SMSHEET2
SMSHEET2
	.word SMSHEET2_TPG-bridge_anims
	.half 8, 9, 2, 4
SMSHEET2_TPG
	.half	0,    25,   232,     0

	CNOP 0,4
	global SMSHEET3
SMSHEET3
	.word SMSHEET3_TPG-bridge_anims
	.half 10, 9, 2, 3
SMSHEET3_TPG
	.half	0,   237,    87,    0

	CNOP 0,4
	global SMSHEET4
SMSHEET4
	.word SMSHEET4_TPG-bridge_anims
	.half 8, 10, 0, 3
SMSHEET4_TPG
	.half	0,    33,   232,     0

	CNOP 0,4
	global SMSHEET5
SMSHEET5
	.word SMSHEET5_TPG-bridge_anims
	.half 3, 11, 0, 4
SMSHEET5_TPG
	.half	0,   249,    11,     0

	CNOP 0,4
	global SMSHEET6
SMSHEET6
	.word SMSHEET6_TPG-bridge_anims
	.half 9, 9, 4, 3
SMSHEET6_TPG
	.half	0,   117,    22,    0

	CNOP 0,4
	global SMSHEET7
SMSHEET7
	.word SMSHEET7_TPG-bridge_anims
	.half 10, 11, 6, 4
SMSHEET7_TPG
	.half	0,   117,    31,    0

	CNOP 0,4
	global SMSHEET8
SMSHEET8
	.word SMSHEET8_TPG-bridge_anims
	.half 9, 11, 4, 5
SMSHEET8_TPG
	.half	0,   101,   175,    0

	CNOP 0,4
	global SMSHEET9
SMSHEET9
	.word SMSHEET9_TPG-bridge_anims
	.half 6, 10, 4, 5
SMSHEET9_TPG
	.half	0,    41,   232,     0

	CNOP 0,4
	global LEAF1
LEAF1
	.word LEAF1_TPG-bridge_anims
	.half 5, 3, 3, 1
	.word   PAPER_P
LEAF1_TPG
	.half	0,   213,   246,     0

	CNOP 0,4
	global LEAF2
LEAF2
	.word LEAF2_TPG-bridge_anims
	.half 3, 3, 2, 2
LEAF2_TPG
	.half	0,   249,     5,     0

	CNOP 0,4
	global LEAF3
LEAF3
	.word LEAF3_TPG-bridge_anims
	.half 3, 3, 1, 2
LEAF3_TPG
	.half	0,    81,    71,     0

	CNOP 0,4
	global LEAF4
LEAF4
	.word LEAF4_TPG-bridge_anims
	.half 4, 3, 1, 1
LEAF4_TPG
	.half	0,   209,   225,     0

	CNOP 0,4
	global LEAF5
LEAF5
	.word LEAF5_TPG-bridge_anims
	.half 2, 4, 0, 2
LEAF5_TPG
	.half	0,   249,     1,     0

	CNOP 0,4
	global LEAF6
LEAF6
	.word LEAF6_TPG-bridge_anims
	.half 2, 3, 0, 0
LEAF6_TPG
	.half	0,   249,     8,     0

	CNOP 0,4
	global LEAF7
LEAF7
	.word LEAF7_TPG-bridge_anims
	.half 3, 1, 2, -1
LEAF7_TPG
	.half	0,   113,    97,     0

	CNOP 0,4
	global LEAF8
LEAF8
	.word LEAF8_TPG-bridge_anims
	.half 3, 1, 2, 0
LEAF8_TPG
	.half	0,   233,   234,     0

*/

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align	2
#include "bridge.umd" 
	
	.align 2
	.globl bridge_module
bridge_module:
	.half	(32*32*0)+(32*0)+0 	/* autoerase color */
	.half	0x00    		   	/* initial world y */
	.half	0xda		   	/* ground y offset */
	.half	320		   	/* initial world x */
	.half	8 	  	   	/* scroll left limit */
	.half	632	  	   	/* scroll right limit */

	.word	bridge_calla
	.word	bridge_scroll	  	/* scroll table */
	.word	dlists_bridge

	.word	bakmods
	.word	BRIDGE1BMOD	  	/* baklst1 = bridge */
	.half	0xffff,0xffde
	.word	BRIDGE2BMOD	  	/* baklst2 = buildings */
	.half	0xe4,0xffe1
	.word	BRIDGE3BMOD	  	/* baklst3 = sky */
	.half	0x140,0xd

	.word	CENTER_X
	.word	BRIDGE1BMOD,worldtlx1
	.word	BRIDGE1BMOD,worldtlx4
	.word	0

	.word	_bridgeflrSegmentRomStart
	.word	_bridgeflrSegmentRomEnd
	.word	BRGRD_P		   	/* palette for floor */
	.word	43
	.word	scrollx1
	.word	skew_7

bridge_scroll:
	.word	0*SCX/100			/* 8 */
	.word	0*SCX/100			/* 7 */
	.word	0*SCX/100			/* 6 */
	.word	0*SCX/100			/* 5 */
	.word	0*SCX/100			/* 4 - papers (this should match baklst1) */
	.word	0*SCX/100			/* 3 - far buildings and sky */
	.word	0x8000*SCX/100		/* 2 - close buildings */
	.word	0x1a000*SCX/100		/* 1 - bridge wall */
	.word	0x20000*SCX/100		/* 0 - players */

dlists_bridge:
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx1
	.word	-1,floor_code
	.word	-1,shadow_p1p2
	.word	baklst4,worldtlx1		/* draw papers 1st */
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

