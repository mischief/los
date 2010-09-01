#ifndef KMAIN_H
#define KMAIN_H

#include <oskit/x86/types.h>
#include <oskit/x86/multiboot.h>

void kmain(struct multiboot_info *mb_boot_info, oskit_u32_t magic);

#endif
