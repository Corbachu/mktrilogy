#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern	KANORED_P
	.extern	KANOBLU_P
	.extern	SABER_P
	.extern	LASEREY_P

	.align 2
#include "mkkano.atd"

#include "mkkano.att1"

