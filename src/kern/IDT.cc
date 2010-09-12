#include <IDT.hh>
#include <oskit/x86/seg.h>
#include <oskit/x86/base_gdt.h>
#include <oskit/x86/proc_reg.h>
#include <string.h>

IDT::IDT(void) {
}

IDT::~IDT(void) {
}

void IDT::init(void) {
  memset(&base_idt, 0, sizeof(base_idt));

  SETUP_GATE(1);
  SETUP_GATE(2);
  SETUP_GATE(3);
  SETUP_GATE(4);
  SETUP_GATE(5);
  SETUP_GATE(6);
  SETUP_GATE(7);
  SETUP_GATE(8);
  SETUP_GATE(9);
  SETUP_GATE(10);
  SETUP_GATE(11);
  SETUP_GATE(12);
  SETUP_GATE(13);
  SETUP_GATE(14);
  SETUP_GATE(15);
  SETUP_GATE(16);
  SETUP_GATE(17);
  SETUP_GATE(18);
  SETUP_GATE(19);
  SETUP_GATE(20);
  SETUP_GATE(21);
  SETUP_GATE(22);
  SETUP_GATE(23);
  SETUP_GATE(24);
  SETUP_GATE(25);
  SETUP_GATE(26);
  SETUP_GATE(27);
  SETUP_GATE(28);
  SETUP_GATE(29);
  SETUP_GATE(30);
  SETUP_GATE(31);

  /* ... */
  
  load();
}

void IDT::load(void) {
  struct pseudo_descriptor pdesc;
  pdesc.limit = sizeof(base_idt) - 1;
  pdesc.linear_base = (uint32_t) &base_idt;
  
  set_idt(&pdesc);
}
