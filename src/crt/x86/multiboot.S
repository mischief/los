#ifndef __asm__
#define __asm__ 1
#include <multiboot.h>
#endif

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
  
  /* call ctors */
  mov $start_ctors, %ebx
  jmp 2f
  
1:
  call *(%ebx)
  add $4, %ebx
2:
  cmp $end_ctors, %ebx
  jb 1b
  
  /* call kernel entrypoint */  
  call  multiboot_main
  
  /* call dtors */
  mov $start_dtors, %ebx
  jmp 4f
3:
  call *(%ebx)
  add $4, %ebx
4:
  cmp $end_dtors, %ebx
  jb 3b

  /* stop */
  cli
hang:
  hlt
  jmp   hang

  .comm stack, STACK_SIZE, 32

/*
  .section .ctors, "aw", @progbits
  .align 4
__CTOR_LIST__:
  //.long -1
  
  .section .dtors, "aw", @progbits
  .align 4
__DTOR_LIST__:
  //.long -1
*/
