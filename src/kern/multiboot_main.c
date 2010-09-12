#include <multiboot_main.h>
#include <video.h>
#include <version.h>
#include <stdio.h>

#include <multiboot.h>

#include <oskit/x86/base_cpu.h>

struct multiboot_info boot_info;

extern int main(int argc, char *argv[]);


void multiboot_main(struct multiboot_info *mb_boot_info, uint64_t magic) {
  video_init();
  video_set_fg(FG_RED);
  printf("Bootloader magic: 0x%x\n", magic);
  
  if (magic != 0x2BADB002) {
    video_set_fg(FG_RED);
    printf("bad magic \n");
    return;
  }

  boot_info = *mb_boot_info;
  
  base_cpu_setup();
  
  printf("We are on the other side!\n");

  return;
}
