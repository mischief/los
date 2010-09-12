#include <oskit/x86/base_gdt.h>

.globl isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7, isr8
.globl  isr9, isr10, isr11, isr12, isr13, isr14, isr15, isr16
.globl isr17, isr18, isr19, isr20, isr21, isr22, isr23, isr24
.globl isr25, isr26, isr27, isr28, isr29, isr30, isr31

#define ISR_NOERROR(x) \
isr##x: 	\
  cli;			\
  push $0;		\
  push $##x;		\
  jmp isr_common;
  
#define ISR_ERROR(x) \
isr##x:	\
  cli;			\
  push $##x;		\
  jmp isr_common

ISR_NOERROR(0)
ISR_NOERROR(1)
ISR_NOERROR(2)
ISR_NOERROR(3)
ISR_NOERROR(4)
ISR_NOERROR(5)
ISR_NOERROR(6)
ISR_NOERROR(7)
ISR_ERROR(8)
ISR_NOERROR(9)
ISR_ERROR(10)
ISR_ERROR(11)
ISR_ERROR(12)
ISR_ERROR(13)
ISR_ERROR(14)
ISR_NOERROR(15)
ISR_NOERROR(16)
ISR_NOERROR(17)
ISR_NOERROR(18)
ISR_NOERROR(19)
ISR_NOERROR(20)
ISR_NOERROR(21)
ISR_NOERROR(22)
ISR_NOERROR(23)
ISR_NOERROR(24)
ISR_NOERROR(25)
ISR_NOERROR(26)
ISR_NOERROR(27)
ISR_NOERROR(28)
ISR_NOERROR(29)
ISR_NOERROR(30)
ISR_NOERROR(31)

.extern fault_handler
isr_common:
  pusha
  push %ds
  push %es
  push %fs
  push %gs
  mov $KERNEL_DS, %ax
  mov %ax, %ds
  mov %ax, %es
  mov %ax, %fs
  mov %ax, %gs
  mov %esp, %eax
  push %eax
  call fault_handler
  pop %eax
  pop %gs
  pop %fs
  pop %es
  pop %ds
  popa
  add $8, %esp
  sti
  iret
