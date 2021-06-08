#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
 
	.extern	RADBLU_P
	.extern	RD_ELEC_P

	.align 2
#include "mkrd.atd"
#include "mkrd.att1" 
