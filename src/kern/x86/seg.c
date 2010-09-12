#include <oskit/x86/seg.h>

/* Fill a segment descriptor.  */
void fill_descriptor(struct x86_desc *desc, unsigned base, unsigned limit,
  unsigned char access, unsigned char sizebits)
{
  if (limit > 0xfffff)
  {
    limit >>= 12;
    sizebits |= SZ_G;
  }
  desc->limit_low = limit & 0xffff;
  desc->base_low = base & 0xffff;
  desc->base_med = (base >> 16) & 0xff;
  desc->access = access | ACC_P;
  desc->limit_high = limit >> 16;
  desc->granularity = sizebits;
  desc->base_high = base >> 24;
}

/* Fill a gate with particular values.  */
void fill_gate(struct x86_gate *gate, unsigned offset, unsigned short selector,
  unsigned char access, unsigned char word_count)
{
  gate->offset_low = offset & 0xffff;
  gate->selector = selector;
  gate->word_count = word_count;
  gate->access = access | ACC_P;
  gate->offset_high = (offset >> 16) & 0xffff;
}
