#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

robo_anitab1:
	.word a_self_destruct
	
a_self_destruct:
	.word RBDESTRUCT2
	.word ani_sladd
	.word PLITE3
	.word RBDESTRUCT4
	.word 0
	.word ani_slani
	.word PLITE4
	.word RBDESTRUCT5
	.word ani_calla
	.word beep_sound
	.word ani_slani
	.word PLITE5
	.word RBDESTRUCT6
	.word ani_slani
	.word PLITE6
	.word RBDESTRUCT7
	.word ani_calla
	.word beep_sound
	.word ani_slani
	.word PLITE5
	.word RBDESTRUCT6
	.word 0
	.word ani_sladd
	.word RBDISPLAY1
	.word RBLAFF2
	.word ani_slani
	.word RBDISPLAY2
	.word RBLAFF2
	.word ani_slani
	.word RBDISPLAY3
	.word RBLAFF3
	.word 0
	.word ani_calla
	.word robo_laugh_sound
	.word RBLAFF4
	.word ani_slani
	.word RBDISPLAY2
	.word RBLAFF5
	.word ani_slani
	.word RBDISPLAY3
	.word RBLAFF6
	.word ani_slani
	.word RBDISPLAY1
	.word RBLAFF5
	.word 0

RBDESTRUCT2:
	.word RBDESTRUCT2_SUB, 0
RBDESTRUCT2_SUB:
	.word RBDESTRUCT2_IMG
	.half 111, 54, 23, -9
PLITE3:
	.word PLITE3_SUB, 0
PLITE3_SUB:
	.word PLITE3_IMG
	.half 23, 26, -1, -11
	.word PLITE_P
RBDESTRUCT4:
	.word RBDESTRUCT4_SUB, 0
RBDESTRUCT4_SUB:
	.word RBDESTRUCT4_IMG
	.half 112, 50, 18, -8
PLITE4:
	.word PLITE4_SUB, 0
PLITE4_SUB:
	.word PLITE4_IMG
	.half 26, 28, -1, -11
RBDESTRUCT5:
	.word RBDESTRUCT5_SUB, 0
RBDESTRUCT5_SUB:
	.word RBDESTRUCT5_IMG
	.half 112, 47, 17, -8
PLITE5:
	.word PLITE5_SUB, 0
PLITE5_SUB:
	.word PLITE5_IMG
	.half 26, 26, -1, -12
RBDESTRUCT6:
	.word RBDESTRUCT6_SUB, 0
RBDESTRUCT6_SUB:
	.word RBDESTRUCT6_IMG
	.half 112, 46, 17, -8
PLITE6:
	.word PLITE6_SUB, 0
PLITE6_SUB:
	.word PLITE6_IMG
	.half 9, 13, -14, -25
RBDESTRUCT7:
	.word RBDESTRUCT7_SUB, 0
RBDESTRUCT7_SUB:
	.word RBDESTRUCT7_IMG
	.half 112, 47, 17, -8
RBDISPLAY1:
	.word RBDISPLAY1_SUB, 0
RBDISPLAY1_SUB:
	.word RBDISPLAY1_IMG
	.half 85, 79, -15, -39
	.word DISPLAY_P
RBLAFF2:
	.word RBLAFF2_SUB, 0
RBLAFF2_SUB:
	.word RBLAFF2_IMG
	.half 111, 57, 25, -9
RBDISPLAY2:
	.word RBDISPLAY2_SUB, 0
RBDISPLAY2_SUB:
	.word RBDISPLAY2_IMG
	.half 85, 90, 44, -27
RBDISPLAY3:
	.word RBDISPLAY3_SUB, 0
RBDISPLAY3_SUB:
	.word RBDISPLAY3_IMG
	.half 114, 123, 54, -2
RBLAFF3:
	.word RBLAFF3_SUB, 0
RBLAFF3_SUB:
	.word RBLAFF3_IMG
	.half 111, 65, 29, -9
RBLAFF4:
	.word RBLAFF4_SUB, 0
RBLAFF4_SUB:
	.word RBLAFF4_IMG
	.half 111, 71, 33, -9
RBLAFF5:
	.word RBLAFF5_SUB, 0
RBLAFF5_SUB:
	.word RBLAFF5_IMG
	.half 111, 73, 34, -9
RBLAFF6:
	.word RBLAFF6_SUB, 0
RBLAFF6_SUB:
	.word RBLAFF6_IMG
	.half 111, 76, 35, -9
	
	.align 2
#include "mkrobo2f1.att" 
