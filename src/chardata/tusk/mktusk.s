#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

/*
;******************************************************************************
; File: mktusk.s
;
; By: David Schwartz
;
; Date: August 1994
;
; (C) Williams Entertainment
;
; Mortal Kombat III Tusk Animation Tables
;******************************************************************************
*/

	.extern   TSKTAN_P
	.extern   TSBLU_P
	.extern   HILITE_P
	.extern   MAGENTA_P
	.extern	FLESH_P
	.extern   UGHEAD_P
	.extern   KABGLOW_P
	.extern   BHJAX_P
	.extern   BHINDIA_P
	.extern   BHKANO_P
	.extern   BHRDROB_P
	.extern   BHLIU_P
	.extern   BHSZERO_P
	.extern   BHTUSK_P
	.extern   BHLIA_P
	.extern   BHSWAT_P
	.extern   BHTSANG_P
	.extern   BHLAO_P
	.extern   BHBLADE_P
	.extern	KABOK_P

	.align 2
#include "mktusk.atd"
#include "mktusk.att1" 
