/******************************************************//**
* Linker script for STM32F303VC ARM(R) Cortex(TM)-M4 MCU
* Modified at 23-September-2015 by Thomas Zöchbauer.
**********************************************************/


/* Linker script to configure memory regions.
 * Need modifying for a specific board.
 *   FLASH.ORIGIN: starting address of flash
 *   FLASH.LENGTH: length of flash
 *   RAM.ORIGIN: starting address of RAM
 *   RAM.LENGTH: length of RAM
 *   CCRAM.ORIGIN: starting address of CCRAM
 *   CCRAM.LENGTH: length of CCRAM
 */

MEMORY
{
   FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K      /* ROM, Read-Only-Memory.*/
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 40K - 1K  /* Reserve 1K for stack. */
  CCRAM (rwx) : ORIGIN = 0x10000000, LENGTH = 8K
}

_stack_size = 1K;
_stack_begin = ORIGIN(RAM) + LENGTH(RAM);
_stack_end = _stack_begin + _stack_size;
__initial_stack_pointer = _stack_end;

SECTIONS
{
	. = ORIGIN(FLASH);
	. = ALIGN(4);

	/* ISR vectors */
	.isr_vector :
	{
		*(.isr_vector)
		KEEP(*(.isr_vector))	/* Keep section even if linked with --gc-sections. */
		. = ALIGN(0x10);		/* Align to 16 bytes boundary. */
	} > FLASH = 0xAAAA  		/* Fill memory gaps with 0xAAAA. */

	.text :
	{
		*(.text)
		. = ALIGN(4);
		*(.text*)
		. = ALIGN(4);
		*(.rodata)
		. = ALIGN(4);
		*(.rodata*)
		. = ALIGN(4);

		_ctors_begin = .;
		KEEP(*(.init_array))
		. = ALIGN(4);
		KEEP(*(SORT(.init_array.*)))
		. = ALIGN(4);
		_ctors_end = .;
	} > FLASH

	.text :
	{
		. = ALIGN(0x10);
	} > FLASH = 0xAAAA

    .eh_frame :
	{
        KEEP(*(.eh_frame))
		. = ALIGN(4);
	} > FLASH

	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > FLASH

	__exidx_start = .;
	.ARM.exidx :
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} > FLASH
	__exidx_end = .;

	/* Mark end of constant data (isr vector, text and arm-code).
	   ROM-to-RAM data follows in FLASH. */
	__etext = .;

	. = ORIGIN(RAM);
	. = ALIGN(4);

	/* The ROM-to-RAM initialized data section */
	.data :
	{
		_data_begin = .;
		KEEP(*(.data))
		. = ALIGN(4);
		KEEP(*(.data*))
		. = ALIGN(4);
		_data_end = .;
	} > RAM AT > FLASH

	/* The uninitialized (zero-cleared) data section */
	.bss :
	{
		_bss_begin = .;
		KEEP(*(.bss))
		. = ALIGN(4);
		KEEP(*(.bss*))
		. = ALIGN(4);
		KEEP(*(COMMON))
		. = ALIGN(4);
		_bss_end = .;
	} > RAM

    /* Mark end of data and bss section. Free memory space (heap) follows. */
	__end__ = .;
    PROVIDE(end = .);

	_rom_data_begin = LOADADDR(.data);
}
