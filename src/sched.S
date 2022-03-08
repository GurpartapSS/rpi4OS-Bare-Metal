#include "../include/sched.h"

.globl cpu_switch_to
cpu_switch_to:
    mov	x10, #THREAD_CPU_CONTEXT
	add	x8, x0, x10		// previous task_struct + THREAD_CPU_CONTEXT,X8 For the previous process struct cpu_context Structure pointer 
	mov	x9, sp
	stp	x19, x20, [x8], #16		// store callee-saved registers  &&&&  Pressing stack   &&&&
	stp	x21, x22, [x8], #16     //Store value and increment by 16 btis
	stp	x23, x24, [x8], #16
	stp	x25, x26, [x8], #16
	stp	x27, x28, [x8], #16
	stp	x29, x9, [x8], #16
	str	x30, [x8]       // lr Pressing stack 
	add	x8, x1, x10    // next task_struct + THREAD_CPU_CONTEXT,X8 For the latter process struct cpu_context Structure pointer 
	ldp	x19, x20, [x8], #16		// restore callee-saved registers  &&&&  Out of the stack   &&&&
	ldp	x21, x22, [x8], #16
	ldp	x23, x24, [x8], #16
	ldp	x25, x26, [x8], #16
	ldp	x27, x28, [x8], #16
	ldp	x29, x9, [x8], #16
	ldr	x30, [x8]
	mov	sp, x9
    ret