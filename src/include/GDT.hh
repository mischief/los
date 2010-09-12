#ifndef GDT_HH
#define GDT_HH

#include <oskit/x86/seg.h>
#include <oskit/x86/base_gdt.h>
#include <stdint.h>

#define BASE_TSS	0x08
#define KERNEL_CS	0x10	/* Kernel's PL0 code segment */
#define KERNEL_DS	0x18	/* Kernel's PL0 data segment */
#define KERNEL_16_CS	0x20	/* 16-bit version of KERNEL_CS */
#define KERNEL_16_DS	0x28	/* 16-bit version of KERNEL_DS */
#define LINEAR_CS	0x30	/* PL0 code segment mapping to linear space */
#define LINEAR_DS	0x38	/* PL0 data segment mapping to linear space */
#define USER_CS		0x43	/* User-defined descriptor, RPL=3 */
#define USER_DS		0x4b	/* User-defined descriptor, RPL=3 */
#define KERNEL_TRAP_TSS 0x50	/* Used by stack-overflow detection code */

/* Leave a little additional room beyond this for customization */
#define GDTSZ		(0x80/8) /* 128/8 = 16 entries */

class GDT {
public:
  GDT(void);
  ~GDT(void);
  void init(void);

private:
  void load(void);

  inline void fill_descriptor(uint32_t num, uint32_t base,
    uint32_t limit, uint8_t access, uint8_t sizebits)
  {
    if(limit > 0xfffff) {
      limit >>= 12;
      sizebits |= SZ_G;
    }

    base_gdt[num].limit_low = limit & 0xffff;
    base_gdt[num].base_low = base & 0xffff;
    base_gdt[num].base_med = (base >> 16) & 0xff;
    base_gdt[num].access = access | ACC_P;
    base_gdt[num].granularity = (uint8_t)(limit >> 16) & 0x0F;
    base_gdt[num].granularity |= (uint8_t)(sizebits & 0xF0U);
    base_gdt[num].base_high = (uint8_t) (base >> 24);
  }

  struct x86_desc base_gdt[GDTSZ];

};

#endif
