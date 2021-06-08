#include <regdef.h>
	.option pic0

	.set noreorder
/*
;# File: context.s
;#
;# By: David Schwartz
;#
;# Date: August 1994
;#
;# (C) Williams Entertainment
;#
;# Mortal Kombat III CONTEXT SWITCHING ROUTINES
;#*******************************************************************************/

/*	opt c+ */

/* THESE EQUATES MUST MATCH THE CONTEXT STRUCT IN mkstruct.h */

c_wakeup = 0
c_stackptr = 4
c_frameptr = 8
c_globalptr = 12
c_s0 = 16
c_s1 = 20
c_s2 = 24
c_s3 = 28
c_s4 = 32
c_s5 = 36
c_s6 = 40
c_s7 = 44
#if 0
c_fs0 = 48
c_fs1 = 52
c_fs2 = 56
c_fs3 = 60
c_fs4 = 64
c_fs5 = 68
#endif

/*
;	xref	EnterCriticalSection
;	xref	ExitCriticalSection
*/
	.text

imask:
	.word	0
	
	.globl  context_init_main

	.ent	context_init_main
/*
;###############################################################################
;# Function: void context_init_main(ADDRESS *main_context)
;#
;# By: David Schwartz
;#
;# Parameters: a0 = ADDRESS *main_context
;#
;# Description: This routine initialize the variables in the main context
;###############################################################################
*/
context_init_main:
	sw	ra,c_wakeup(a0)
	sw	sp,c_stackptr(a0)
	sw	fp,c_frameptr(a0)
	sw	gp,c_globalptr(a0)
	sw	s0,c_s0(a0)
	sw	s1,c_s1(a0)
	sw	s2,c_s2(a0)
	sw	s3,c_s3(a0)
	sw	s4,c_s4(a0)
	sw	s5,c_s5(a0)
	sw	s6,c_s6(a0)
	sw	s7,c_s7(a0)
#if 0	
	s.s	fs0,c_fs0(a0)	/* fs0-fs5 */
	s.s	fs1,c_fs1(a0)
	s.s	fs2,c_fs2(a0)
	s.s	fs3,c_fs3(a0)
	s.s	fs4,c_fs4(a0)
	s.s	fs5,c_fs5(a0)
#endif	
	j	ra
	nop
	.end	context_init_main

	.globl 	context_kill_switch
	.ent	context_kill_switch
/*
;###############################################################################
;# Function: void context_kill_switch(ADDRESS *restore_context)
;#
;# By: David Schwartz
;#
;# Parameters: a0 = ADDRESS *restore_context
;#
;# Description: This routine performs a context switch back to the main
;#			   process.  It is usually called from the process_kill_context routine.
;###############################################################################
*/
context_kill_switch:
	move	s0,a0				/* stick in a reg that must be preserved during calls */
	nop

	jal	EnterCriticalSection
	nop

	
	lw	gp,c_globalptr(s0)
	lw	fp,c_frameptr(s0)
	lw	sp,c_stackptr(s0)
	nop


	jal	ExitCriticalSection
	nop

	move	a0,s0
	nop

	lw	ra,c_wakeup(a0)
	lw	s0,c_s0(a0)
	lw	s1,c_s1(a0)
	lw	s2,c_s2(a0)
	lw	s3,c_s3(a0)
	lw	s4,c_s4(a0)
	lw	s5,c_s5(a0)
	lw	s6,c_s6(a0)
	lw	s7,c_s7(a0)
#if 0	
	l.s	fs0,c_fs0(a0)	/* fs0-fs5 */
	l.s	fs1,c_fs1(a0)
	l.s	fs2,c_fs2(a0)
	l.s	fs3,c_fs3(a0)
	l.s	fs4,c_fs4(a0)
	l.s	fs5,c_fs5(a0)
#endif	
	j	ra
	nop
	.end	context_kill_switch
	
	.globl context_switch
	.ent context_switch

/*
;###############################################################################
;# Function: void context_switch(ADDRESS *restore_context,ADDRESS *save_context)
;#
;# By: David Schwartz
;#
;# Parameters: a0 = ADDRESS *restore_context
;#			  a1 = ADDRESS *save_context
;#
;# Description: This routine performs a context switch back to the restore.  It saves the current
;#			   context into the save context and then restores the context from the restore context.
;###############################################################################
*/
context_switch:
	sw	ra,c_wakeup(a1)							/* ; save the current context */
	sw	sp,c_stackptr(a1)
	sw	fp,c_frameptr(a1)
	sw	gp,c_globalptr(a1)
	sw	s0,c_s0(a1)
	sw	s1,c_s1(a1)
	sw	s2,c_s2(a1)
	sw	s3,c_s3(a1)
	sw	s4,c_s4(a1)
	sw	s5,c_s5(a1)
	sw	s6,c_s6(a1)
	sw	s7,c_s7(a1)
#if 0	
	s.s	fs0,c_fs0(a1)	/* fs0-fs5 */
	s.s	fs1,c_fs1(a1)
	s.s	fs2,c_fs2(a1)
	s.s	fs3,c_fs3(a1)
	s.s	fs4,c_fs4(a1)
	s.s	fs5,c_fs5(a1)
#endif
	move	s0,a0				/* ; stick in a reg that must be preserved during calls */
	nop


	jal	EnterCriticalSection
	nop
	
	lw	gp,c_globalptr(s0)
	lw	fp,c_frameptr(s0)
	lw	sp,c_stackptr(s0)
	nop

	jal	ExitCriticalSection
	nop

	move	a0,s0
	nop

	lw	ra,c_wakeup(a0)					/* ; restore the new context */
	lw	s0,c_s0(a0)
	lw	s1,c_s1(a0)
	lw	s2,c_s2(a0)
	lw	s3,c_s3(a0)
	lw	s4,c_s4(a0)
	lw	s5,c_s5(a0)
	lw	s6,c_s6(a0)
	lw	s7,c_s7(a0)
#if 0	
	l.s	fs0,c_fs0(a0)	/* fs0-fs5 */
	l.s	fs1,c_fs1(a0)
	l.s	fs2,c_fs2(a0)
	l.s	fs3,c_fs3(a0)
	l.s	fs4,c_fs4(a0)
	l.s	fs5,c_fs5(a0)
#endif
	j  	ra
	nop

	.end context_switch

	.globl context_jump
	.ent	context_jump

/*;###############################################################################
;# Function: void context_jump(ADDRESS *jmp_context)
;#
;# By: David Schwartz
;#
;# Parameters: a0 = context that has jump info set
;#
;# Description: This routine makes a jump from one routine to another, in the process
;#				it resets the stack
;###############################################################################
*/
context_jump:
	move	s0,a0				/* ; stick in a reg that must be preserved during calls */
	nop

	jal	EnterCriticalSection
	nop

	lw	gp,c_globalptr(s0)
	lw	fp,c_stackptr(s0)
	lw	sp,c_stackptr(s0)
	nop

	jal	ExitCriticalSection
	nop

	lw	ra,c_wakeup(s0)					/* ; restore the new context */
	nop

	j  	ra
	nop
	.end	context_jump


	.globl get_sp
	.ent	get_sp
get_sp:	
	move	v0,sp
	nop
	j	ra
	nop
	
	.end 	get_sp
	