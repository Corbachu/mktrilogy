#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
 
	.extern   BGPAL1_P
	.extern   SKGLOW_P
	.extern   KANPRO_P
	.extern   SHAEND_P

	.align 2
#include "mksk.atd"
#include "mksk.att" 
