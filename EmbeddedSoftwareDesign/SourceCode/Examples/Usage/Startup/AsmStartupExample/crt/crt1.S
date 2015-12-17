/******************************************************//**
* \file     crt1.S
* \brief    Call all ctor initializations.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

    .syntax unified
    .arch armv7-m

/********************************************************/
    .text
    .thumb
    .thumb_func
    .align 2
    .globl  _crt_init_ctors
    .type   _crt_init_ctors, %function
_crt_init_ctors:
    ldr   r1, = _ctors_begin// Load start address of segment.
    ldr   r2, = _ctors_end  // Load end address of segment.
    push {lr}               // Store lr (link register) at stack.
    b  .call_ctors
    .loop_call_ctor:
        ldr  r3, [r1], #4
        push {r1, r2}       // Store r1 and r2 at stack.
        blx   r3            // Call Ctor. This will modifiy lr, r1 and r2.
        pop {r1, r2}        // Pop r2 and r1 from stack.
    .call_ctors:
        cmp  r1, r2
        bcc  .loop_call_ctor    // Branch if carry clear (r1 != r2).

    pop {lr}                // Pop lr from stack.
    mov pc, lr              // Return to calling function.
    .size   _crt_init_ctors, . - _crt_init_ctors

    .end
