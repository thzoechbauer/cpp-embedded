/******************************************************//**
* \file     crt0_init_ram.c
* \brief    Copy data from ROM to RAM and zero bss segment.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

#include <stddef.h>
#include <stdint.h>
#include <string.h>

extern void* _rom_data_begin;   // Start address for the initialization values of the rom-to-ram section.
extern void* _data_begin;       // Start address for the .data section.
extern void* _data_end;         // End address for the .data section.
extern void* _bss_begin;        // Start address for the .bss section.
extern void* _bss_end;          // End address for the .bss section.

void crt_init_ram()
{
    typedef uint32_t memory_aligned_type;

    // Copy the data segment initializers from ROM to RAM.
    // Note that all data segments are aligned by 4.
    size_t data_size = (memory_aligned_type*)&_data_end - (memory_aligned_type*)&_data_begin;
    memcpy(&_data_begin, &_rom_data_begin, data_size*sizeof(memory_aligned_type));

    // Clear the bss segment.
    // Note that the bss segment is aligned by 4.
    size_t bss_size = (memory_aligned_type*)&_bss_end - (memory_aligned_type*)&_bss_begin;
    memset(&_bss_begin, (0U), bss_size*sizeof(memory_aligned_type));
}
