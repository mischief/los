#define ASM_FILE
#include <multiboot.h>

#define STACK_SIZE 0x4000

#define MULTIBOOT_HEADER_FLAGS (MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO)

  .text
  .global start, _start

start:
_start:
  jmp multiboot_entry

  .align 4
multiboot_header:
  .long MULTIBOOT_HEADER_MAGIC
  .long MULTIBOOT_HEADER_FLAGS
  .long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

multiboot_entry:
  mov   $(stack + STACK_SIZE), %esp
  
  /* set eflags to known state */
  pushl $0
  popf
  
  push  %eax                        /* magic number */
  push  %ebx                        /* data structure */

  call  kmain

  cli
hang:
  hlt
  jmp   hang

  .comm stack, STACK_SIZE, 32
