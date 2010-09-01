#include <kmain.h>

#include <oskit/x86/multiboot.h>
#include <oskit/x86/types.h>

#include <monitor.h>

#include <version.h>


struct multiboot_info boot_info;

void kmain(struct multiboot_info *mb_boot_info, oskit_u32_t magic) {
  /* bad magic. just die. */
  if (magic != 0x2BADB002) {
    return;
  }

  boot_info = *mb_boot_info;

  /* Write your kernel here. */
  
  monitor_init();
  monitor_write(OS_VERSION_STRING);

  return;
}
