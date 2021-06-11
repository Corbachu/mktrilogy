#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data

anj_anitab1:
	.word a_monkey
	.word a_frog
	.word a_pengo
	.word a_egg
	.word a_polar
	.word a_anteater
	.word a_elephant
	.word a_porcupine

a_polar:
/*
	.word POLAR1
	.word POLAR3
	.word POLAR4
	.word POLAR5
*/	
	.word POLAR6
	.word 0
	.word POLAR8
	.word POLAR10
	.word POLAR11
	.word 0
	.word POLAR12
	.word ani_adjustxy
	.half 0
	.half 8
	.word POLAR13
	.word ani_adjustxy
	.half 0
	.half 8
j_polar:
	.word POLAR15
	.word POLAR16
	.word POLAR17
	.word ani_jump
	.word j_polar
#if 0	
POLAR1:
	.word POLAR1_SUB, 0
POLAR1_SUB:
	.word POLAR1_IMG
	.half 109, 45, 14, -6
	.word POLAR_P
POLAR3:
	.word POLAR3_SUB, 0
POLAR3_SUB:
	.word POLAR3_IMG
	.half 105, 53, 22, -13
POLAR4:
	.word POLAR4_SUB, 0
POLAR4_SUB:
	.word POLAR4_IMG
	.half 94, 59, 29, -25
POLAR5:
	.word POLAR5_SUB, 0
POLAR5_SUB:
	.word POLAR5_IMG
	.half 82, 78, 37, -36
#endif	
POLAR6:
	.word POLAR6_SUB, 0
POLAR6_SUB:
	.word POLAR6_IMG
	.half 69, 100, 45, -50
	.word POLAR_P
POLAR8:
	.word POLAR8_SUB, 0
POLAR8_SUB:
	.word POLAR8_IMG
	.half 112, 71, 40, -7
POLAR10:
	.word POLAR10_SUB, 0
POLAR10_SUB:
	.word POLAR10_IMG
	.half 131, 63, 37, 11
POLAR11:
	.word POLAR11_SUB, 0
POLAR11_SUB:
	.word POLAR11_IMG
	.half 132, 60, 31, 11
POLAR12:
	.word POLAR12_SUB, 0
POLAR12_SUB:
	.word POLAR12_IMG
	.half 133, 68, 30, 14
POLAR13:
	.word POLAR13_SUB, 0
POLAR13_SUB:
	.word POLAR13_IMG
	.half 134, 86, 41, 15
POLAR15:
	.word POLAR15_SUB, 0
POLAR15_SUB:
	.word POLAR15_IMG
	.half 98, 82, 43, -20
POLAR16:
	.word POLAR16_SUB, 0
POLAR16_SUB:
	.word POLAR16_IMG
	.half 83, 85, 51, -36
POLAR17:
	.word POLAR17_SUB, 0
POLAR17_SUB:
	.word POLAR17_IMG
	.half 80, 90, 54, -40

a_monkey:
	.word MONKEY1
	.word MONKEY2
	.word MONKEY3
	.word MONKEY4
	.word MONKEY5
	.word ani_jump
	.word a_monkey

a_frog:
	.word FROG1
	.word FROG2
	.word FROG3
	.word 0
	.word FROG4
	.word ani_adjustx
	.word 16
	.word FROG5
	.word FROG6
	.word FROG7
	.word 0
	.word FROG8
	.word FROG7
	.word FROG6
	.word ani_adjustx
	.word -16
	.word FROG5
	.word FROG4
	.word FROG3
	.word FROG2
	.word FROG1
	.word 0
a_pengo:
	.word PENGO1
	.word PENGO2
	.word PENGO3
	.word ani_jump
	.word a_pengo
a_egg:
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word EGG1
	.word EGG2
	.word 0

FROG1:
	.word FROG1_IMG
	.half 9, 14, -10, -36
	.word FROG_P
FROG2:
	.word FROG2_IMG
	.half 9, 14, -10, -36
FROG3:
	.word FROG3_IMG
	.half 9, 14, -10, -36
FROG4:
	.word FROG4_IMG
	.half 17, 14, -10, -26
FROG5:
	.word FROG5_IMG
	.half 36, 19, -13, 0
FROG6:
	.word FROG6_IMG
	.half 43, 29, -10, 17
FROG7:
	.word FROG7_IMG
	.half 71, 42, -3, 49
FROG8:
	.word FROG8_IMG
	.half 109, 41, 0, 70
PENGO1:
	.word PENGO1_IMG
	.half 35, 18, 6, -2
	.word PENGO_P
PENGO2:
	.word PENGO2_IMG
	.half 35, 15, 4, -2
PENGO3:
	.word PENGO3_IMG
	.half 35, 17, 2, -2
EGG1:
	.word EGG1_IMG
	.half 13, 10, 1, -19
	.word PENGO_P
EGG2:
	.word EGG2_IMG
	.half 16, 10, 1, -16

MONKEY1:
	.word MONKEY1_IMG
	.half 54, 49, 18, -4
	.word MONKY_P
MONKEY2:
	.word MONKEY2_IMG
	.half 59, 32, 12, 0
MONKEY3:
	.word MONKEY3_IMG
	.half 58, 22, 10, 0
MONKEY4:
	.word MONKEY4_IMG
	.half 59, 28, 12, 0
MONKEY5:
	.word MONKEY5_IMG
	.half 54, 47, 17, -3


a_elephant:
	.word PHANT1
	.word PHANT2
	.word ani_sladd
	.word PHANT3B
	.word PHANT3A
	
	.word ani_slani_sleep
	.word PHANT3C

	.word ani_slani_sleep
	.word PHANT3D
	.word 0
	.word ani_slani_sleep
	.word PHANT3D
	
	.word ani_slani_sleep
	.word PHANT3C

	.word ani_slani_sleep
	.word PHANT3B
	.word 0
	
PHANT1:
	.word PHANT1_SUB,0
PHANT1_SUB:
	.word PHANT1_IMG
	.half 35, 56, 0, 0
	.word ELEPHANT_P
PHANT2:
	.word PHANT2_SUB,0
PHANT2_SUB:
	.word PHANT2_IMG
	.half 35, 66, 10, 0
PHANT3A:
	.word PHANT3A_SUB,0
PHANT3A_SUB:
	.word PHANT3A_IMG
	.half 36, 52, -3, 1
PHANT3B:
	.word PHANT3B_SUB,0
PHANT3B_SUB:
	.word PHANT3B_IMG
	.half 16, 17, 12, 0
	.word ELEPHANT_P
PHANT3C:
	.word PHANT3C_SUB,0
PHANT3C_SUB:
	.word PHANT3C_IMG
	.half 22, 25, 20, 6
PHANT3D:
	.word PHANT3D_SUB,0
PHANT3D_SUB:
	.word PHANT3D_IMG
	.half 32, 33, 28, 15

a_anteater:
	.word ANTEAT1
	.word ANTEAT2
	.word ANTEAT3
	.word ANTEAT2
	.word ANTEAT3
	.word 0
	.word ani_sladd
	.word ANTEAT4
	.word ANTEAT9
	.word ani_slani_sleep
	.word ANTEAT5
	.word 0
	.word ani_slani_sleep
	.word ANTEAT6
	.word ani_slani_sleep
	.word ANTEAT7
	.word ani_slani_sleep
	.word ANTEAT8
	.word 0
	.word ani_slani_sleep
	.word ANTEAT5
	.word ani_slani_sleep
	.word ANTEAT4
	.word ani_calla
	.word delete_slave
	.word ANTEAT3
	.word ANTEAT2
	.word ANTEAT1
	.word 0
	
ANTEAT1:
	.word ANTEAT1_SUB,0
ANTEAT1_SUB:
	.word ANTEAT1_IMG
	.half 42, 98, 0, 0
	.word ANTEATER_P
ANTEAT2:
	.word ANTEAT2_SUB,0
ANTEAT2_SUB:
	.word ANTEAT2_IMG
	.half 42, 103, 0, 0
ANTEAT3:
	.word ANTEAT3_SUB,0
ANTEAT3_SUB:
	.word ANTEAT3_IMG
	.half 52, 99, 0, 10
ANTEAT4:
	.word ANTEAT4_SUB,0
ANTEAT4_SUB:
	.word ANTEAT4_IMG
	.half 46, 50, -73, 31
	.word ANTEATER_P
ANTEAT5:
	.word ANTEAT5_SUB,0
ANTEAT5_SUB:
	.word ANTEAT5_IMG
	.half 68, 74, -73, 53
ANTEAT6:
	.word ANTEAT6_SUB,0
ANTEAT6_SUB:
	.word ANTEAT6_IMG
	.half 70, 77, -73, 55
ANTEAT7:
	.word ANTEAT7_SUB,0
ANTEAT7_SUB:
	.word ANTEAT7_IMG
	.half 68, 74, -73, 53
ANTEAT8:
	.word ANTEAT8_SUB,0
ANTEAT8_SUB:
	.word ANTEAT8_IMG
	.half 68, 74, -73, 53
ANTEAT9:
	.word ANTEAT9_SUB,0
ANTEAT9_SUB:
	.word ANTEAT9_IMG
	.half 43, 78, 0, 1


a_porcupine:
	.word PORC1
	.word PORC2
	.word 0
	.word PORC1
	.word PORC2
	.word PORC2
	.word PORC1
	.word 0
	.word PORC3
	.word PORC4
	.word 0
	.word PORC5
	.word PORC6
	.word 0
	.word PSPIKE
	.word 0
	.word PORC6
	.word PORC5
	.word PORC4
	.word PORC3
	.word PORC2
	.word PORC1
	.word 0
PORC1:
	.word PORC1_IMG
	.half 24, 48, 0, 0
	.word PORCUPINE_P
PORC2:
	.word PORC2_IMG
	.half 24, 35, -6, 0
PORC3:
	.word PORC3_IMG
	.half 32, 37, -2, 6
PORC4:
	.word PORC4_IMG
	.half 38, 31, 0, 11
PORC5:
	.word PORC5_IMG
	.half 38, 38, 1, 11
PORC6:
	.word PORC6_IMG
	.half 39, 45, 2, 12
PSPIKE:
	.word PSPIKE_IMG
	.half 3, 18, 0, 0
	.word PORCUPINE_P

	.align 2
#include "mknj.atta" 
