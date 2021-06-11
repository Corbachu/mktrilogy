#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0
	.set	noreorder
	.data

/*
;******************************************************************************
; File: mkarena.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III arena
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/
	.extern	calla_arena		

/*	
;*********************************
;**			PALETTES
;*********************************
*/

	.extern	arena_CLT	
	.extern	STADFLR_p	
	.extern nfans_p		
	.extern boss_p		
	.extern	BCHAIN1P	
	.extern	RCHAIN1P	

/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
	.align 2
	.globl arena_anims
arena_anims:
	
	/* frames referenced in C files */
	.globl 	bosssit1
	.globl	a_boss
	.globl 	RCHAIN1
	.globl	a_raidch
	.globl 	BCHAIN1
	.globl	a_barakach
	.globl	crowd1
	.globl	crowd2
	.globl	crowd3
	
#if 0
a_barakach:
	.word BCHAIN1
	.word BCHAIN2
	.word BCHAIN3
	.word BCHAIN4
	.word BCHAIN5
	.word BCHAIN6
	.word 0
a_raidch:
	.word RCHAIN1
	.word RCHAIN2
	.word RCHAIN3
	.word RCHAIN4
	.word 0
#endif	
a_boss:
	.word bosssit1
	.word bosssit2
	.word bosssit3
	.word 0
a_crowd:
	.word crowd1
	.word crowd2
	.word crowd3
	.word 0
#if 0	
BCHAIN1:
	.word BCHAIN1_IMG
	.half 88, 100, 0, 0
	.word	BCHAIN1P
BCHAIN2:
	.word BCHAIN2_IMG
	.half 88, 100, 0, 0
BCHAIN3:
	.word BCHAIN3_IMG
	.half 88, 100, 0, 0
BCHAIN4:
	.word BCHAIN4_IMG
	.half 88, 100, 0, 0
BCHAIN5:
	.word BCHAIN5_IMG
	.half 88, 100, 0, 0
BCHAIN6:
	.word BCHAIN6_IMG
	.half 88, 100, 0, 0
RCHAIN1:
	.word RCHAIN1_IMG
	.half 86, 92, 0, 0
	.word	RCHAIN1P
RCHAIN2:
	.word RCHAIN2_IMG
	.half 86, 92, 0, 0
RCHAIN3:
	.word RCHAIN3_IMG
	.half 86, 92, 0, 0
RCHAIN4:
	.word RCHAIN4_IMG
	.half 86, 92, 0, 0
#endif
bosssit1:
	.word BOSSSIT1_IMG
  	.half 122, 64, 38, 3
	.word	boss_p
bosssit2:
	.word BOSSSIT2_IMG
	.half 123, 63, 38, 3
bosssit3:
	.word BOSSSIT3_IMG
	.half 125, 66, 40, 5
crowd1:
	.word crowd1_IMG
	.half 21, 86, 0, 0
	.word	nfans_p
crowd2:
	.word crowd2_IMG
	.half 21, 86, 0, 0
	.word	nfans_p
crowd3:
   	.word crowd3_IMG
	.half 21, 86, 0, 0
	.word	nfans_p
 	
	.align 2
#include "arena.att"
	
	.align 2
	.globl arena_dict
arena_dict:
#include "arena.dct"

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "arena.umd"

	.align 2
	.globl arena_module
arena_module:
	.half	(32*32*13)+(32*8)+14		/* autoerase color */
	.half	0				/* initial world y */
	.half	230	     			/* ground y */
	.half	320				/* initial x */

	.half	0x20 			/* scroll left limit */
	.half	0x278 			/* scroll right limit */

	.word	calla_arena
	.word	arena_scroll			/* scroll table */
	.word	dlists_arena

	.word	bakmods
	.word	SKIP_BAKMOD			/* skip baklst1 */

	.word	arena2BMOD			/* baklst2 - kano / throne */
	.half	0xfff0,0x47

	.word	arena3BMOD			/* baklst3 - distant floor #1 */
	.half	0x00,0x9f

	.word	arena4BMOD			/* baklst4 - distant floor #2 */
	.half	0x00,0x95

	.word	SKIP_BAKMOD			/* skip baklst5 = crowd */

	.word	arena5BMOD			/* baklst6 = wall */
	.half	0x00,0x2e

	.word	arena6BMOD			/* baklst7 */
	.half	0x139,0x9

	.word	CENTER_X
/*	.word	arena2BMOD,worldtlx2		; kano / throne */
	.word	arena3BMOD,worldtlx3		/* distant floor #1 */
	.word	arena4BMOD,worldtlx4		/* distant floor #2 */
	.word	arena5BMOD,worldtlx6		/* back wall */
/*	.word	arena6BMOD,worldtlx7		; sky */
	.word	0

	.word	_arenaflrSegmentRomStart	/* sag */
	.word	_arenaflrSegmentRomEnd	/* sag end */
	.word	STADFLR_p		/* palette for floor */
	.word	37			/* height */
	.word	scrollx2
	.word	skew_7

arena_scroll:
	.word	0		/* 8 */
	.word	0		/* 7 - sky */
	.word	0x8000		/* 6 - wall */
	.word	0x8000		/* 5 - crowd */
	.word	0x10000		/* 4 - */
	.word	0x14000		/* 3 - */
	.word	0x1a000		/* 2 - kano / throne */
	.word	0x20000		/* 1 - player's plane */
	.word	0x20000		/* 0 */

dlists_arena:
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	-1,floor_code
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx2
	.word	-1,shadow_p1p2
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

