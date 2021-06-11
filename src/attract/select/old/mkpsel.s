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
#include "mkblue.umd"

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
	.word	NUPORTBMOD			/* baklst8 */
	.half	0xfffc,0xfffc
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
	.word	NUFIREBMOD
	.half	0xfffb,0xfffc
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

