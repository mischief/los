#include <oskit/x86/base_cpu.h>

struct cpu_info base_cpuid;

void base_cpu_init(void) {
  cpuid(&base_cpuid);
}
