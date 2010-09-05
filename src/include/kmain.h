#ifndef KMAIN_H
#define KMAIN_H

#include <stdint.h>
#include <multiboot.h>

void kmain(struct multiboot_info *mb_boot_info, uint64_t magic);

#endif
