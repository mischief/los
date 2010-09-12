#include <oskit/x86/base_gdt.h>
#include <oskit/x86/proc_reg.h>

void base_gdt_load(void) {
  volatile struct pseudo_descriptor pdesc;
  pdesc.__pad = 0;
  pdesc.limit = sizeof(base_gdt) - 1;
  pdesc.linear_base = (volatile uint32_t) &base_gdt;
  
  set_gdt(&pdesc);
  
  __asm__ __volatile__("xchg %bx, %bx");
  
  __asm__ __volatile__("ljmp %0,$1f; 1:" : : "i" (KERNEL_CS));
  set_ds(KERNEL_DS);
  set_es(KERNEL_DS);
  set_ss(KERNEL_DS);
  
  set_fs(0);
  set_gs(0);
  
}
