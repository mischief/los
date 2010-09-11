#ifndef GDT_HH
#define GDT_HH

#include <stdint.h>

/* Leave a little additional room beyond this for customization */
#define GDTSZ		(0x80/8) /* 128/8 = 16 entries */

struct psuedo_descriptor {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));

struct x86_desc {
  uint32_t	limit_low:16,	/* limit 0..15 */
		base_low:16,	/* base  0..15 */
		base_med:8,	/* base  16..23 */
		access:8,	/* access byte */
		limit_high:4,	/* limit 16..19 */
		granularity:4,	/* granularity */
		base_high:8;	/* base 24..31 */
};

class GDT {
public:
  GDT(void);
  ~GDT(void);
  void init(void);

private:
  struct x86_desc base_gdt[GDTSZ];

};

#endif
