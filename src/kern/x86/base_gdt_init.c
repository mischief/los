#include <oskit/x86/base_gdt.h>
#include <oskit/x86/seg.h>
#include <oskit/x86/proc_reg.h>

void base_gdt_init(void) {
  fill_descriptor(&base_gdt[KERNEL_CS / 8], 0, 0xFFFFFFFF, ACC_PL_K | ACC_CODE_R, SZ_32);
  fill_descriptor(&base_gdt[KERNEL_DS / 8], 0, 0xFFFFFFFF, ACC_PL_K | ACC_DATA_W, SZ_32);
}
