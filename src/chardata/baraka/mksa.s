#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
	 
	.extern UGRED_P
	.extern UGSPARK_P
 
	.align 2
#include "mksa.atd"
#include "mksa.att1" 
