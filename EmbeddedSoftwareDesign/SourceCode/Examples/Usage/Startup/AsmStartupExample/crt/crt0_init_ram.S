/******************************************************//**
* \file     crt0_init_ram.S
* \brief    Initialize statics from ROM to RAM.
*           Zero-clear default-initialized static RAM.
*           Expressed with ASM.
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
    .globl  _crt_init_ram
    .type   _crt_init_ram, %function
_crt_init_ram:
    // Copy data segment from flash to ram.
    ldr    r1, =_rom_data_begin     // Load-address of .data segment.
    ldr    r2, =_data_begin         // Begin of data address range in RAM.
    ldr    r3, =_data_end           // End of data address range in RAM.

    subs    r3, r2                  // Calculate length of data segment (max offset).
    ble    .flash_to_ram_loop_end   // Branch if offset is less or equal 0 (empty segment).
    .flash_to_ram_loop:
        subs   r3, #4               // Decrement offset by 4.
        ldr    r0, [r1, r3]         // Load from _rom_data_begin+offset to r0.
        str    r0, [r2, r3]         // Store r0 to _data_begin+offset.
        bgt    .flash_to_ram_loop   // Branch if offset is greater than 0.
    .flash_to_ram_loop_end:

    // Zero fill the bss segment.
    ldr   r1, = _bss_begin
    ldr   r2, = _bss_end
    movs  r3, #0                    // Move 0 to r3.
    b  .fill_zero_bss
    .loop_zero_bss:
        str  r3, [r1], #4           // Write r3 (0) to address in r1, increment r1 by 4.

    .fill_zero_bss:
        cmp  r1, r2
        bcc  .loop_zero_bss         // Branch if carry clear (r1 != r2).

    mov pc, lr                      // Return to calling function.
    .size   _crt_init_ram, . - _crt_init_ram
    /********************************************************/

    .end
