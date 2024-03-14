/*
   Author: Ahmed Raza
   Description: This linker script sets the memory layout for a RISC-V executable.
                It places the .text section at address 0x80000000 with a page alignment of 0x1000.
                The .data section follows immediately after .text, also with page alignment.
                The .tohost section, if present, is placed after .data.
*/

OUTPUT_ARCH("riscv")
ENTRY(main)

SECTIONS
{
  . = 0x80000000;    /* Start address of program */
  . = ALIGN(0x1000);  /* Align to page boundary */
  
  .text :            /* Code section */
  {
    *(.text)
  } 

  . = ALIGN(0x1000);  /* Align to page boundary */
  . = 0x80001000;     /* Address immediately after .text */

  .data :            /* Data section */
  {
    *(.data)
  } 
  . = ALIGN(0x1000);  /* Align to page boundary */
  
  .tohost :          /* Custom section */
  {
    *(.tohost)
  } 

  _end = .;          /* Symbol marking end of program */
}

