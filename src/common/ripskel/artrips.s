#include <regdef.h>
#include "mkchar.inc"

	.option	pic0

	.set noreorder
	.data
	
	.globl a_normal_skel
	.globl a_sg_skel
	
a_normal_skel:
	.word SKELRIP1
	.word SKELRIP2
	.word SKELRIP3
	.word 0
a_sg_skel:
	.word SGOROSKEL1
	.word SGOROSKEL2
	.word SGOROSKEL3
	.word 0
SKELRIP1:
	.word SKELRIP1_SUB, 0
SKELRIP1_SUB:
	.word SKELRIP1_IMG
	.half 105, 74, 48, -10
	.word SKELRIP_P
SKELRIP2:
	.word SKELRIP2_SUB, 0
SKELRIP2_SUB:
	.word SKELRIP2_IMG
	.half 105, 61, 35, -10
SKELRIP3:
	.word SKELRIP3_SUB, 0
SKELRIP3_SUB:
	.word SKELRIP3_IMG
	.half 105, 46, 20, -10
SGOROSKEL1:
	.word SGOROSKEL1_SUB, 0
SGOROSKEL1_SUB:
	.word SGOROSKEL1_IMG
	.half 110, 95, 75, -15
	.word SKELRIP_P
SGOROSKEL2:
	.word SGOROSKEL2_SUB, 0
SGOROSKEL2_SUB:
	.word SGOROSKEL2_IMG
	.half 110, 81, 61, -15
SGOROSKEL3:
	.word SGOROSKEL3_SUB, 0
SGOROSKEL3_SUB:
	.word SGOROSKEL3_IMG
	.half 110, 69, 49, -15
	

	.align 2
#include "../../common/ripskel/ripskel.att"

	.align 2
	.globl ripskel_dict
ripskel_dict:
#include "../../common/ripskel/ripskel.dct"
