#include <multiboot_main.h>
#include <video.h>
#include <version.h>
#include <stdio.h>

#include <multiboot.h>

#include <oskit/x86/base_cpu.h>
#include <oskit/debug.h>

struct multiboot_info boot_info;

extern int main(int argc, char *argv[]);

void multiboot_main(struct multiboot_info *mb_boot_info, uint64_t magic) {
  video_init();
  video_set_fg(FG_RED);
  
  if (magic != 0x2BADB002) {
    video_set_fg(FG_RED);
    printf("bad magic \n");
    return;
  }

  boot_info = *mb_boot_info;
  
  base_cpu_setup();

  //~ printf("@ %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
  //~ panic("@ %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
  //~ panic("%s\n", __FILE__);
  //~ panic("%s\n", __FUNCTION__);
  //~ panic("%d\n", __LINE__);
  //~ panic("PANIC!!@@!@@!");
  //panic("Oh no :(");
  
  __asm__ __volatile__("int $0x3");

  return;
}
