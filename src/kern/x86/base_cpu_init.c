#include <oskit/x86/base_trap.h>
#include <oskit/x86/base_cpu.h>
#include <oskit/x86/base_gdt.h>

struct cpu_info base_cpuid;

void base_cpu_init(void) {
  cpuid(&base_cpuid);
  
  base_trap_init();
  
  base_gdt_init();
  
}
