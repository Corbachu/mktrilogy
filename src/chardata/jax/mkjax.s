#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

	.extern JAXPRP_P
	.extern JZXGRN_P
	.extern JXPROJT_P
 	.extern JQAK_P
 	.extern JXPREXP_P

	.align 2
#include "mkjax.atd"
#include "mkjax.att1" 
