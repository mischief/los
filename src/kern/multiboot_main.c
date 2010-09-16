#include <multiboot_main.h>
#include <video.h>
#include <version.h>
#include <stdio.h>

//~ #include <multiboot.h>

#include <oskit/x86/base_cpu.h>
#include <oskit/debug.h>

#include <oskit/x86/pc/base_multiboot.h>

//~ struct multiboot_info boot_info;

extern int main(int argc, char *argv[]);

void multiboot_main(struct multiboot_info *mb_boot_info, uint64_t magic) {
  video_init();
  printf("Kernel version %d.%02d (compiled %s %s)\n", VERSION_MAJOR, VERSION_MINOR, __DATE__, __TIME__);
  
  if (magic != 0x2BADB002) {
    video_set_fg(FG_RED);
    printf("bad magic \n");
    return;
  }

  //~ boot_info = *mb_boot_info;
  
  base_cpu_setup();
  
  multiboot_info_dump(mb_boot_info);

  //~ printf("@ %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
  //~ panic("@ %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);

  return;
}
