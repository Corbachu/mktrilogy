#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern	TSRED_P
	.extern	TSYEL_P
	.extern	GLOW_P
	.extern	FIRE_P
	.extern	SZMORF_P
	.extern   LIMORF_P
	.extern   R1MORF_P
	.extern   SWMORF_P
	.extern   KLMORF_P
	.extern   KAMORF_P
	.extern   JXMORF_P
	.extern   INMORF_P
	.extern   SYMORF_P
	.extern   KAMORF_P
	.extern   SGMORF_P
	.extern   LKMORF_P
	.extern	TRMORF_P
	.extern   SKELSUK2

	.align 2
#include "mkst.atd"
#include "mkst.att1" 
