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

	.extern	SBGREEN_P
	.extern	sbENG_p
	.extern	sbzap_p
	.extern	dROP_p
	.extern	SPARKIS_P
	.extern	KISSORB_P
	.extern	SBLTBLU_P
	.extern ENGPINK_P
	.extern GUTS_P
	.extern HAWK_P
	.extern GIRLFRD_P
	.extern BABY4_P
	
	.align 2
#include "mksonya.att2" 
