#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern	LKYELO_P
	.extern	LKRED_P
	.extern	DRAGFIR_P
	.extern LUFIRE_P

	.align 2
#include "mklk.dct"
