#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder

/*
;******************************************************************************
; File: mktree.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Living forest
;******************************************************************************
*/


/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_forest	

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern	forest2_CLT	
	.extern	humus_p		
	.extern	SCREAM_P	

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/

	.align 2
tree_anims:

	.globl TREEANI1
	.globl	a_treeroar
	
	
a_treeroar:
	.word TREEANI1
	.word TREEANI2
	.word TREEANI3
	.word TREEANI4
	.word TREEANI5
	.word TREEANI6
	.word TREEANI7
	.word TREEANI6
	.word TREEANI7
	.word TREEANI6
	.word TREEANI7
	.word TREEANI6
	.word TREEANI7
	.word TREEANI6
	.word TREEANI7
	.word TREEANI5
	.word TREEANI4
	.word TREEANI3
	.word TREEANI2
	.word TREEANI1
	.word 0
TREEANI1:
	.word TREEANI1_IMG
	.half 72, 65, 0, 0
	.word	SCREAM_P
TREEANI2:
	.word TREEANI2_IMG
	.half 72, 65, 0, 0
TREEANI3:
	.word TREEANI3_IMG
	.half 72, 65, 0, 0
TREEANI4:
	.word TREEANI4_IMG
	.half 72, 65, 0, 0
TREEANI5:
	.word TREEANI5_IMG
	.half 72, 65, 0, 0
TREEANI6:
	.word TREEANI6_IMG
	.half 72, 65, 0, 0
TREEANI7:
	.word TREEANI7_IMG
	.half 72, 65, 0, 0

	.align 2
#include "tree.att"

	.align 2
	.globl tree_dict
tree_dict:
#include "tree.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "forest2.umd"

	.align 2
	.globl forest_module
forest_module:
	.half	0				/* autoerase color */

	.half	0x0	/* initial world y */
	.half	0xe3	     			/* ground y */
	.half	960/2-320/2		/* init wx */

	.half	0x68 	  			/* scroll left limit */
	.half	0x2d8	  			/* scroll right limit */
	.word	calla_forest
	.word	forest_scroll			/* scroll table */
	.word	dlists_forest

	.word	bakmods
	.word	SKIP_BAKMOD			/* baklst1 = SKIP */

	.word	wood1BMOD
	.half	0x00,0xffe1		/* baklst2 = Biggest trees */
	.word	wood2BMOD
	.half	0x87,1		/* baklst3 */

	.word	SKIP_BAKMOD			/* baklst4 = SKIP */

	.word	wood4BMOD
	.half	0x6f,0x23			/* baklst5 */
	.word	wood5BMOD
	.half	0xd7,0x34		/* baklst6 */
	.word	wood6BMOD
	.half	0xf4,0x44		/* baklst7 */
	.word	wood7BMOD
	.half	0x120,0x64		/* baklst8 */

	.word	0xffffffff

	.word	_treeflrSegmentRomStart
	.word	_treeflrSegmentRomEnd
	.word	humus_p
	.word	35			/* height */
	.word	scrollx
	.word	skew_8

forest_scroll:
	.word	0		/* 8 */
	.word	0xa000		/* 7 */
	.word	0x10000		/* 6 */
	.word	0x14000		/* 5 */

	.word	0x18000		/* 4 - secrets */
	.word	0x18000		/* 3 */

	.word	0x20000		/* 2 */
	.word	0x20000		/* 1 */
	.word	0x20000		/* 0 */

dlists_forest:
	.word	baklst8,worldtlx8		/* clouds */
	.word	baklst7,worldtlx7		/* clouds */
	.word	baklst6,worldtlx6		/* */
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	-1,floor_code
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

/*
;*********************************
;** 		FLOOR DATA			**
;*********************************
	.align 2
FL_FORST
	include ..\bkgd\floors\forest\forestfl.asm

*/