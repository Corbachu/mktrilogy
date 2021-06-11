#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

aind_anitab1:
	.word a_sky_light
	.word a_sky_zap

a_sky_light:
	.word INSKYLIGHT2
	.word INSKYLIGHT4
	.word 0
	.word INSKYLIGHT5
	.word INSKYLIGHT6
	.word INSKYLIGHT7
	.word INSKYLIGHT8
	.word INSKYLIGHT9
	.word 0
a_sky_zap:
	.word ZAP2
	.word ZAP3
	.word ZAP4
	.word ZAP5
	.word ZAP6
	.word ZAP7
	.word ZAP8
	.word ZAP9
	.word ZAP8
	.word ZAP7
	.word ZAP8
	.word ZAP9
	.word ZAP8
	.word ZAP7
	.word ZAP8
	.word ZAP9
	.word ZAP8
	.word ZAP7
	.word ZAP8
	.word ZAP9
	.word ZAP10
	.word ZAP11
	.word ZAP12
	.word ZAP13
	.word ZAP14
	.word ZAP15
	.word 0

INSKYLIGHT2:
	.word INSKYLIGHT2_SUB, 0
INSKYLIGHT2_SUB:
	.word INSKYLIGHT2_IMG
	.half 111, 50, 16, -5
INSKYLIGHT4:
	.word INSKYLIGHT4_SUB, 0
INSKYLIGHT4_SUB:
	.word INSKYLIGHT4_IMG
	.half 138, 54, 18, 20
INSKYLIGHT5:
	.word INSKYLIGHT5_SUB, 0
INSKYLIGHT5_SUB:
	.word INSKYLIGHT5_IMG
	.half 124, 63, 18, 7
INSKYLIGHT6:
	.word INSKYLIGHT6_SUB, 0
INSKYLIGHT6_SUB:
	.word INSKYLIGHT6_IMG
	.half 102, 74, 18, -14
INSKYLIGHT7:
	.word INSKYLIGHT7_SUB, 0
INSKYLIGHT7_SUB:
	.word INSKYLIGHT7_IMG
	.half 81, 79, 18, -36
INSKYLIGHT8:
	.word INSKYLIGHT8_SUB, 0
INSKYLIGHT8_SUB:
	.word INSKYLIGHT8_IMG
	.half 67, 77, 17, -49
INSKYLIGHT9:
	.word INSKYLIGHT9_SUB, 0
INSKYLIGHT9_SUB:
	.word INSKYLIGHT9_IMG
	.half 56, 65, 16, -60
ZAP2:
	.word ZAP2_SUB, 0
ZAP2_SUB:
	.word ZAP2_IMG
	.half 144, 6, 2, 222
	.word ZAP_P
ZAP3:
	.word ZAP3_SUB, 0
ZAP3_SUB:
	.word ZAP3_IMG
	.half 206, 48, 23, 207
ZAP4:
	.word ZAP4_SUB, 0
ZAP4_SUB:
	.word ZAP4_IMG
	.half 221, 88, 42, 222
	.word ZAP_P
ZAP5:
	.word ZAP5_SUB, 0
ZAP5_SUB:
	.word ZAP5_IMG
	.half 224, 124, 62, 223
ZAP6:
	.word ZAP6_SUB, 0
ZAP6_SUB:
	.word ZAP6_IMG
	.half 222, 116, 57, 223
ZAP7:
	.word ZAP7_SUB, 0
ZAP7_SUB:
	.word ZAP7_IMG
	.half 222, 74, 36, 223
ZAP8:
	.word ZAP8_SUB, 0
ZAP8_SUB:
	.word ZAP8_IMG
	.half 222, 74, 36, 223
ZAP9:
	.word ZAP9_SUB, 0
ZAP9_SUB:
	.word ZAP9_IMG
	.half 222, 74, 36, 223
ZAP10:
	.word ZAP10_SUB, 0
ZAP10_SUB:
	.word ZAP10_IMG
	.half 222, 74, 36, 223
ZAP11:
	.word ZAP11_SUB, 0
ZAP11_SUB:
	.word ZAP11_IMG
	.half 222, 74, 36, 223
ZAP12:
	.word ZAP12_SUB, 0
ZAP12_SUB:
	.word ZAP12_IMG
	.half 222, 74, 36, 223
ZAP13:
	.word ZAP13_SUB, 0
ZAP13_SUB:
	.word ZAP13_IMG
	.half 221, 39, 18, 222
ZAP14:
	.word ZAP14_SUB, 0
ZAP14_SUB:
	.word ZAP14_IMG
	.half 190, 23, 10, 207
ZAP15:
	.word ZAP15_SUB, 0
ZAP15_SUB:
	.word ZAP15_IMG
	.half 144, 6, 2, 222

	.align 2
#include "mkindf2.att" 
