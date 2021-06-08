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


	.extern	FGRED_P
	.extern	FGBLUE_P
	.extern	BLUPAL_P
	.extern	 CRACKP_P
	.extern SMLXPLD_P

	.align 2
#include "mksg.atd"
#include "mksg.att1" 
