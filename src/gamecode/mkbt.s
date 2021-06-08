#include <regdef.h>
#include "mkbkgd.inc"

	.option	pic0
	.set	noreorder
	
/*
;******************************************************************************
; File: mkbt.s
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Background Module Composition Tables
;******************************************************************************
; DATA DEFINITIONS, BETTER MATCH IN MKBKGD.H
*/

/*
;************************************************
;* NOTE: ADDING BACKGROUND INFO
;*1) update: makefile.mak, mkbt.s
;*
;*2) change all bit offsets into byte offsets by dividing by 8 (important)
;************************************************
*/
	.rdata

/*
;*********************************
;**			EXTERNALS			**
;*********************************
*/

	.extern		roof_module			
	.extern		subway_module		
	.extern		street_module		
	.extern		temple_module		
	.extern		bridge_module		
	.extern		tower_module		
	.extern		bell_module			
	.extern		grave_module		
	.extern		soul_module			
	.extern		pit_module			
	.extern		bank_module			
	.extern		portal_module		
	.extern		nowall_module		
								
	.extern		buyin_module		
	.extern		ladder_module		
	.extern		vs_module			
	.extern		bvs_module			
	.extern		psel_module			
								
								
	.extern		nuoptions_module	
	.extern		nuoptcoin_module	
								
	.extern		options_module		
	.extern		optcoin_module		
	.extern		title_module		
	.extern		legal_module		
								
	.extern		redgrad_module		
	.extern		greengrad_module	
	.extern		bluegrad_module		
								
	.extern		skdie1_module		
	.extern		skdie2_module		
	.extern		skdiepit_module		
	.extern		hscore_module		
	.extern		mockpit_module		
								
	.extern		mk2pit_module			
	.extern		lost_module			
	.extern		desert_module		
	.extern		water_module		
	.extern		cave_module			
	.extern		hell_module			
	.extern		fire_module			
	.extern		firedark_module			
	.extern		mode_coin_module	
								
	.extern		dedpool_module		
	.extern		battle_module		
	.extern		roof_module		
	.extern		armory_module		
	.extern		forest_module		
	.extern		sktower_module		
	.extern		monkport_module		
	.extern		mk1_module			
	.extern		tomb_module			
								
	.extern		logo_module
	.extern		kung2_module
	.extern		kung5_module
	.extern		kung5bottom_module
	
	.align	2

	.globl	table_o_mods

table_o_mods:
/*
;	module name					; background #
; ---------------------			------------------------
*/
	.word	subway_module			/* 0	*/
	.word	street_module			/* 1	*/
	.word	kung2_module				/* 2	*/
	.word	kung5_module				/* 3	*/
	.word	tower_module			/* 4	*/
	.word	bridge_module 			/* 5	*/
	.word	soul_module				/* 6	*/
	.word	bell_module				/* 7	*/
	.word	temple_module 			/* 8	*/
	.word	grave_module			/* 9	*/
	.word	pit_module				/* a	*/
	.word	water_module			/*water,b	*/
	.word	hell_module				/*hell,c	*/
	.word	cave_module				/*cave,d	*/
	.word	desert_module			/*desert,e	*/
	.word	lost_module				/* f	*/
	.word	portal_module			/* 10,	*/
	.word	dedpool_module			/* 11	*/
	.word	battle_module			/* 12	*/
	.word	roof_module				/* 13	*/
	.word	armory_module			/* 14	*/
	.word	forest_module			/* 15	*/
	.word	sktower_module			/* 16	*/
	.word	monkport_module			/* 17	*/
	.word	mk1_module				/* 18	*/
	.word	tomb_module				/* 19	*/
 	.word	mk2pit_module			/* 1a	*/
 	.word	mk2pitstar_module		/* 1b	*/
 	.word	kung5bottom_module		/* 1c	*/
 	.word	0						/* 1d	*/
 	.word	0						/* 1e	*/
 	.word	0						/* 1f	*/
	.word	buyin_module			/* 20	*/
	.word	bvs_module				/* 21 (HIGH SCORE)	*/
	.word	ladder_module 			/* 22	*/
	.word	vs_module				/* 23	*/
	.word	firedark_module			/* 24 */
	.word	fire_module				/* 25	*/
	.word	nowall_module			/* 26	*/
	.word	redgrad_module			/* 27	*/
	.word	greengrad_module		/* 28	*/
	.word	bluegrad_module			/* 29	*/
	.word	mode_coin_module		/* 2a	*/
	.word	title_module			/* 2b	*/
	.word	psel_module				/* 2c	*/
	.word	legal_module			/* 2d	*/
	.word	0	/*skdie1_module*/			/* 2e	*/
	.word	0	/*skdie2_module*/			/* 2f	*/
	.word	0	/*skdiepit_module*/			/* 30	*/
	.word	0	/*mockpit_module*/			/* 31	*/
	.word	0 /*nuoptions_module  */		/* 32	*/
	.word	0 /*nuoptcoin_module  */		/* 33	*/

/*
;*	Format of Module Table
;*	WORD	autoerase color
;*	WORD	ground y position
;*	WORD	initial world y coord
;*	WORD	initial world x coord
;*	WORD	scroll left limit
;*	WORD	scroll right limit
;*	LONG	ptr to a function that will initiate various processes for the background module
;*	LONG	ptr to a table of longs used to specify scroll rates
;*	LONG	ptr to a table of two longs per record. [object list for module, worldtlx variable to use]
;*	LONG	ptr to first background mod variable to fill
;*
;*	FOLLOWING DATA REPEATED DEPENDING ON BACKGROUND:
;*	LONG	command to skip background level
;*
;*	LONG	ptr to background module (OMODULE) data
;*
;*	LONG	command to center x coord of background modules
;*
;*	LONG,LONG	list of background modules and world x variables used to center
*/

	.globl dlists_buyin
dlists_buyin:
	.word	baklst4,worldtlx
	.word	baklst3,worldtlx
	.word	baklst2,worldtlx
	.word	baklst1,worldtlx
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlists_end1
dlists_end1:
	.word	baklst1,worldtlx
	.word	baklst2,worldtlx
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlists_end2
dlists_end2:
	.word	baklst1,worldtlx
	.word	baklst3,worldtlx
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl no_scroll
no_scroll:
	.word	0*SCX/100 			/* 8	*/
	.word	0*SCX/100 			/* 7	*/
	.word	0*SCX/100 			/* 6	*/
	.word	0*SCX/100 			/* 5 -	*/
	.word	0x10000*SCX/100 		/* 4 -	*/
	.word	0x10000*SCX/100 		/* 3 - fence	*/
	.word	0x18000*SCX/100 		/* 2 - wall	*/
	.word	0x20000*SCX/100 		/* 1 - players	*/
	.word	0x20000*SCX/100 		/* 0	*/

	.globl dlists_bogus
dlists_bogus:
	.word	baklst8,worldtlx8
	.word	baklst7,worldtlx7
	.word	baklst6,worldtlx6
	.word	baklst5,worldtlx5
	.word	baklst4,worldtlx4
	.word	baklst3,worldtlx3
	.word	baklst2,worldtlx2
	.word	baklst1,worldtlx
	.globl dlists_objlst
dlists_objlst:
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlist_tournament
dlist_tournament:
	.word	baklst1,worldtlx
	.word	baklst3,worldtlx
	.word	baklst2,worldtlx
	.word	baklst4,worldtlx
	.word	objlst,worldtlx
	.word	objlst2,worldtlx
	.word	0

	.globl dlists_only_q
dlists_only_q:
	.word	objlst,worldtlx
	.word	0
