#include <regdef.h>
#include "mkchar.inc"
#include "mkbkgd.inc"

	.option	pic0

	.set noreorder
	.data

/*
;******************************************************************************
; File: mklost.s
;
; By: David Schwartz
;
; Date: Jan 1995
;
; (C) Williams Entertainment
;
; Mortal Kombat III Lost Bridge Module
;******************************************************************************
*/

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern	calla_mk2pit

/*
;*********************************
;**			PALETTES
;*********************************
*/
	.extern LITTLE_p	 
	.extern TOR_p		 
	.extern BRIDGE1_CLT
	
/*
;*********************************
;**			ANIMATIONS			**
;*********************************
*/
  	.align 2
	.globl a_mk2darkman1
	.globl a_mk2darkman2

a_mk2darkman1:
	.word BKGUY1
	.word BKGUY2
	.word BKGUY3
	.word BKGUY4
	.word BKGUY5
	.word BKGUY6
	.word BKGUY7
	.word 0
a_mk2darkman2:
	.word TORCH1
	.word TORCH2
	.word TORCH3
	.word TORCH4
	.word TORCH5
	.word TORCH6
	.word TORCH7
	.word 0
BKGUY1:
	.word BKGUY1_IMG
	.half 22, 11, 5, 20
	.word	LITTLE_p
BKGUY2:
	.word BKGUY2_IMG
	.half 22, 11, 5, 20
BKGUY3:
	.word BKGUY3_IMG
	.half 22, 11, 5, 20
BKGUY4:
	.word BKGUY4_IMG
	.half 22, 11, 5, 20
BKGUY5:
	.word BKGUY5_IMG
	.half 22, 10, 5, 20
BKGUY6:
	.word BKGUY6_IMG
	.half 22, 11, 5, 20
BKGUY7:
	.word BKGUY7_IMG
	.half 22, 10, 5, 20
TORCH1:
	.word TORCH1_IMG
	.half 29, 12, 6, 25
	.word TOR_p
TORCH2:
	.word TORCH2_IMG
	.half 30, 12, 6, 26
TORCH3:
	.word TORCH3_IMG
	.half 29, 11, 6, 25
TORCH4:
	.word TORCH4_IMG
	.half 30, 11, 6, 26
TORCH5:
	.word TORCH5_IMG
	.half 31, 12, 6, 27
TORCH6:
	.word TORCH6_IMG
	.half 31, 12, 6, 27
TORCH7:
	.word TORCH7_IMG
	.half 28, 11, 6, 24

#include "../lost/lost.att"

	.align 2
	.globl mk2pit_dict
mk2pit_dict:
#if 0
#include "../lost/lost.dct"
#endif

/*
;*********************************
;**		 MODULE DATA			**
;*********************************
*/
	.align 2
#include "bridge1.umd"

	.align 2
	.globl mk2pit_module
mk2pit_module:
	.half	(32*2)+6*32*32		 	
	.half	0x00   	 		   	/* initial world y */
	.half	0xe0-12			   	/* ground y offset */
	.half	320
	.half	0x90 	  			
	.half	0x3d0	  			

	.word	calla_mk2pit
 	.word	pit2_scroll		
	.word	dlists_pit2

	.word	bakmods

	.word	MK2BRIDGE0BMOD			/* ; baklst1 main bridge (front)*/
	.half	-0x20,0xb8
	.word	MK2BRIDGE1BMOD			/* ; baklst2 main bridge */
	.half	0x00,0xa4
	.word	MK2BRIDGE2BMOD			/* ; baklst3 mist*/
	.half	0x00,0xab

	.word	SKIP_BAKMOD			/* ; skip baklst4 = distant fighters*/

	.word	MK2BRIDGE3BMOD			/* ; baklst5 distance mountain / bridge*/
	.half	0x00,0x34
	.word	MK2BRIDGE4BMOD			/* ; baklst6 thin mist behind distance bridge*/
	.half	0x00,0x90
	.word	MK2BRIDGE6BMOD			/* ; baklst7 thick clouds / moon*/
	.half	0x00,0x18
	.word	MK2BRIDGE5BMOD			/* ; baklst8 cloud outline*/
	.half	0x00,0x40

	.word	CENTER_X
	.word	MK2BRIDGE0BMOD,worldtlx
	.word	MK2BRIDGE1BMOD,worldtlx
	.word	MK2BRIDGE2BMOD,worldtlx3
	.word	MK2BRIDGE3BMOD,worldtlx5
	.word	MK2BRIDGE4BMOD,worldtlx6
	.word	MK2BRIDGE6BMOD,worldtlx7
	.word	MK2BRIDGE5BMOD,worldtlx8
	.word	0,0

pit2_scroll:
	.word	0		 	/*  8	*/
	.word	0		 	/* 7	*/
	.word	0x2000	 	/* 6 - */
	.word	0x4000	 	/* 5 - distant bridge */
	.word	0x4000	 	/* 4 - distant fighters */
	.word	0x8000	 	/* 3 - mist */
	.word	0x20000	 	/* 2 - main bridge */
	.word	0x20000	 	/* 1 - main bridge */
	.word	0x20000	 	/* 0 - main bridge */

pit2s_scroll:
	.word	0x400		 	/*  8	*/
	.word	0x400		 	/* 7	*/
	.word	0x800	 	/* 6 - */
	.word	0x4000	 	/* 5 - distant bridge */
	.word	0x4000	 	/* 4 - distant fighters */
	.word	0x8000	 	/* 3 - mist */
	.word	0x20000	 	/* 2 - main bridge */
	.word	0x20000	 	/* 1 - main bridge */
	.word	0x20000	 	/* 0 - main bridge */
			   

dlists_pit2:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	objlst,worldtlx
	.word	baklst1,worldtlx2
	.word	objlst2,worldtlx
	.word	0


	.align 2
	.globl mk2pitstar_module
mk2pitstar_module:
	.half	0
	.half	0x00   	 		   	/* initial world y */
	.half	0xe0-12			   	/* ground y offset */
	.half	320
	.half	0x90 	  			
	.half	0x3d0	  			

	.word	calla_mk2star
	.word	pit2s_scroll		
	.word	dlists_pit2

	.word	bakmods

	.word	MK2BRIDGE0BMOD			/* ; baklst1 main bridge (front)*/
	.half	-0x20,0xb8
	.word	MK2BRIDGE1BMOD			/* ; baklst2 main bridge */
	.half	0x00,0xa4
	.word	MK2BRIDGE2BMOD			/* ; baklst3 mist*/
	.half	0x00,0xab

	.word	SKIP_BAKMOD			/* ; skip baklst4 = distant fighters*/

	.word	MK2BRIDGE3BMOD			/* ; baklst5 distance mountain / bridge*/
	.half	0x00,0x34-24

	.word	mk2stars1BMOD			/* ; baklst5 distance mountain / bridge*/
	.half	0x00,0x34-50
#if 0
	.word	mk2stars2BMOD			/* ; baklst6 distance mountain / bridge*/
	.half	0x00,0-16

	.word	mk2stars2BMOD			/* ; baklst6 distance mountain / bridge*/
	.half	0x00,120+16
	
#endif
	.word	CENTER_X
	.word	MK2BRIDGE0BMOD,worldtlx
	.word	MK2BRIDGE1BMOD,worldtlx
	.word	MK2BRIDGE2BMOD,worldtlx3
	.word	MK2BRIDGE3BMOD,worldtlx5
	.word 	mk2stars1BMOD,worldtlx6
#if 0	
	.word 	mk2stars2BMOD,worldtlx7
	.word 	mk2stars2BMOD,worldtlx8
#endif	
	.word	0,0




