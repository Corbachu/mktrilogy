/*
//////////////////////////////////////////////////////////////////////////////////////////
// int_s.s: interrupt enable/disable functions for the R4300 CPU.
//
// author: Steve Ranck
//////////////////////////////////////////////////////////////////////////////////////////
// THIS CODE IS PROPRIETARY PROPERTY OF WILLIAMS ENTERTAINMENT.
//
// The contents of this file may not be disclosed to third
// parties, copied or duplicated in any form, in whole or in part,
// without the prior written permission of Williams Entertainment.
//////////////////////////////////////////////////////////////////////////////////////////
*/

#include <asm.h>
#include <R4300.h>

#include <regdef.h>
/* #include "mtx_s.h" */


				.globl	sys_disable_ints
				.globl	sys_restore_ints

				.set	noreorder

/*
//////////////////////////////////////////////////////////////////////////////////////////
// u32 sys_cli(void) - disable R4300 CPU interrupts. Returns the previous state.
//////////////////////////////////////////////////////////////////////////////////////////
*/

LEAF( sys_disable_ints )
	mfc0	t0, C0_SR			/* t0 = special register with IE bit */
	and		t1, t0, ~SR_IE		/* t1 = same register with IE bit cleared */
	mtc0	t1, C0_SR			/* disable R4300 CPU interrupts */
	and		v0, t0, SR_IE		/* return the prior state of just the IE bit */
	nop
	j		ra
	nop
END( sys_disable_ints )


/*
//////////////////////////////////////////////////////////////////////////////////////////
// void sys_restore_ints( u32 prior_state ) - restores R4300 CPU interrupts to their
//                                            prior state (passed as the parameter).
//////////////////////////////////////////////////////////////////////////////////////////
*/

LEAF( sys_restore_ints )
	mfc0	t0,C0_SR			/* t0 = special register with IE bit */
	nop
	or		t0,a0				/* restore IE bit from passed-in parameter */
	mtc0	t0,C0_SR			/* restore R4300 CPU interrupts */
	nop
	nop
	j		ra					/* return nothing */
	nop
END( sys_restore_ints )
