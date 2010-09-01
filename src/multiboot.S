.text
.global _start                 # making entry point visible to linker

_start:
  jmp multiboot_entry

/* setting up the Multiboot header - see GRUB docs for details */
.set ALIGN,    1<<0             /* align loaded modules on page boundaries */
.set MEMINFO,  1<<1             /* provide memory map */
.set FLAGS,    ALIGN | MEMINFO  /* this is the Multiboot 'flag' field */
.set MAGIC,    0x1BADB002       /* 'magic number' lets bootloader find the header */
.set CHECKSUM, -(MAGIC + FLAGS) /* checksum required */


.align 4
multiboot_header:
.long MAGIC
.long FLAGS
.long CHECKSUM

/* reserve 16k kernel stack on a quadword boundary */
.set STACKSIZE, 0x4000             
.comm stack, STACKSIZE, 32          

multiboot_entry:
  mov   $(stack + STACKSIZE), %esp  /* set stack */
  push  %eax                        /* magic number */
  push  %ebx                        /* data structure */
  
/* set eflags to known state */

  push $0x0
  popf

  /* call kernel proper */
  call  kmain

  cli
hang:
  hlt    
  jmp   hang
