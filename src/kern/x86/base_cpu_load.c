#include <oskit/x86/base_cpu.h>
#include <oskit/x86/base_gdt.h>

void base_cpu_load(void) {
  base_gdt_load();
}
