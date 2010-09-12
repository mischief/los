#include <GDT.hh>
#include <oskit/x86/seg.h>
#include <oskit/x86/base_gdt.h>
#include <oskit/x86/proc_reg.h>
#include <string.h>

GDT::GDT(void) {
}

GDT::~GDT(void) {
}

void GDT::init(void) {
  memset(&base_gdt, 0, sizeof(base_gdt));
  memset(&base_gdt[0], 0xA0, sizeof(base_gdt[0]));
  /* 32-bit kernel code and data segment */
  fill_descriptor(KERNEL_CS / 8, 0, 0xffffffff, ACC_PL_K | ACC_CODE_R, SZ_32);
  fill_descriptor(KERNEL_DS / 8, 0, 0xffffffff, ACC_PL_K | ACC_DATA_W, SZ_32);
  
  /* */
  
  load();
  
}

void GDT::load(void) {
  struct pseudo_descriptor pdesc;
  pdesc.limit = sizeof(base_gdt) - 1;
  pdesc.linear_base = (uint32_t) &base_gdt;

  set_gdt(&pdesc);
  
  asm volatile("ljmp %0,$1f; 1:" : : "i" (KERNEL_CS));
  set_ds(KERNEL_DS);
  set_es(KERNEL_DS);
  set_ss(KERNEL_DS);
  
  set_fs(0);
  set_gs(0);
}
