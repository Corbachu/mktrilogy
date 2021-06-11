#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern KUNG_P
	.extern KUNGBLU_P
	.extern LHATGLO_P
	.extern LAHAT_P
	.extern   LAOTOP_P
	.extern   SHAT_P

	.align 2
#include "mklao.att2" 
