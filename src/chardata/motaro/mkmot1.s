#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
 
	.extern	MOTARO_P
	.extern   BLAST_P
	.extern   MOMIST_P

	.align 2
#include "mkmot.att2" 
