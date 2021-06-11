#include <regdef.h>
#include "mkchar.inc"

	.option	pic0
	.set	noreorder
	.data
 
 
	.align 2
	.globl a_sk_die_cycle
a_sk_die_cycle:
	.word SHACYCLE1
	.word ani_swpal
	.word SHACYCLE1
j_skcycle:
	.word SHACYCLE1
	.word SHACYCLE3
	.word SHACYCLE5
	.word SHACYCLE7
	.word SHACYCLE9
	.word ani_jump
	.word j_skcycle
	
SHACYCLE1:
	.word SHACYCLE1_SUB, 0
SHACYCLE1_SUB:
	.word MINISHACYCLE1_IMG
	.half 122, 121, 56, -14
	.word   SHAEND_P
SHACYCLE3:
	.word SHACYCLE3_SUB, 0
SHACYCLE3_SUB:
	.word MINISHACYCLE3_IMG
	.half 122, 121, 56, -14
SHACYCLE5:
	.word SHACYCLE5_SUB, 0
SHACYCLE5_SUB:
	.word MINISHACYCLE5_IMG
	.half 122, 121, 56, -14
SHACYCLE7:
	.word SHACYCLE7_SUB, 0
SHACYCLE7_SUB:
	.word MINISHACYCLE7_IMG
	.half 122, 121, 56, -14
SHACYCLE9:
	.word SHACYCLE9_SUB, 0
SHACYCLE9_SUB:
	.word MINISHACYCLE9_IMG
	.half 122, 121, 56, -14
	
	
	.align 2
	.globl sk_pieces
sk_pieces:
	.word SKTOP
	.word SKBOTL
	.word SKBOTR
	.word SKTOPR
	.word SKTOPL
	.word SKLEFT
	.word SKRIGHT
	.word 0
	
SKBOTL:
	.word BOTL_IMG
	.half 85, 153, 0,0
	.word   SHAEND_P

SKBOTR:
	.word BOTR_IMG
	.half 107, 98, 0,0
	.word   SHAEND_P

SKTOPR:
	.word TOPR_IMG
	.half 107, 102, 0,0
	.word   SHAEND_P

SKTOPL:
	.word TOPL_IMG
	.half 105, 100, 0,0
	.word   SHAEND_P

SKLEFT:
	.word LEFT_IMG
	.half 31, 104,  0,0
	.word   SHAEND_P

SKRIGHT:
	.word RIGHT_IMG
	.half 5, 109,  0,0
	.word   SHAEND_P

SKTOP:
	.word TOP_IMG
	.half 89, 14,  0,0
	.word   SHAEND_P
	
	.align 2
#include "shacycle.att" 

