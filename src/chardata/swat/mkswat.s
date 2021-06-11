#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

/*
;******************************************************************************
; File: mksonya.s
;
; By: David Schwartz
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Sonya Animation Tables
;******************************************************************************
*/

	.extern OBRED_P
	.extern OLTBLU_P
	.extern GFIRE_P
	.extern CPBLAST_P
	.extern BOMB_P
	.extern TBLAST_P
	.extern	WICK_P
	.extern   DYNO_P
	.extern	HUGE_P

	
	.align 2
#include "mkswat.atd"
#include "mkswat.att1" 
