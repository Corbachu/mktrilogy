#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_shark
	
a_shark:
	.word SHARK5
	.word 0
	.word SHARK9
	.word SHARK10
	.word SHARK11
	.word SHARK12
	.word SHARK13
	.word 0
	.word SHARK14
	.word SHARK15
	.word SHARK16
	.word SHARK17
	.word SHARK19
	.word 0
a_shark_fin:
	.word SHARKFIN
	.word 0
	
SHARK5:
	.word SHARK5_SUB, 0
SHARK5_SUB:
	.word SHARKFIN_IMG
	.half 75, 100, 50, -46
	.word SHARK_P
SHARK9:
	.word SHARK9_SUB, 0
SHARK9_SUB:
	.word SHARK9_IMG
	.half 46, 89, 51, -77
SHARK10:
	.word SHARK10_SUB, 0
SHARK10_SUB:
	.word SHARK10_IMG
	.half 69, 110, 63, -54
SHARK11:
	.word SHARK11_SUB, 0
SHARK11_SUB:
	.word SHARK11_IMG
	.half 101, 151, 91, -22
SHARK12:
	.word SHARK12_SUB, 0
SHARK12_SUB:
	.word SHARK12_IMG
	.half 136, 166, 96, 12
SHARK13:
	.word SHARK13_SUB, 0
SHARK13_SUB:
	.word SHARK13_IMG
	.half 163, 177, 99, 39
SHARK14:
	.word SHARK14_SUB, 0
SHARK14_SUB:
	.word SHARK14_IMG
	.half 174, 190, 103, 50
SHARK15:
	.word SHARK15_SUB, 0
SHARK15_SUB:
	.word SHARK15_IMG
	.half 130, 202, 113, 6
SHARK16:
	.word SHARK16_SUB, 0
SHARK16_SUB:
	.word SHARK16_IMG
	.half 43, 212, 114, -80
SHARK17:
	.word SHARK17_SUB, 0
SHARK17_SUB:
	.word SHARK17_IMG
	.half 59, 170, 72, -64
SHARK19:
	.word SHARK19_SUB, 0
SHARK19_SUB:
	.word SHARK19_IMG
	.half 14, 127, 29, -110

SHARKFIN:
	.word SHARKFIN_SUB, 0
SHARKFIN_SUB:
	.word SHARKFIN_IMG
	.half 75, 100, 50, -46
	.word SHARK_P

	.align 2
#include "mkrobo2.atta" 
