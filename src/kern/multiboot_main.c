#include <multiboot_main.h>
#include <monitor.h>
#include <version.h>

#include <multiboot.h>

struct multiboot_info boot_info;

extern int main(int argc, char *argv[]);

/*
void multiboot_main(struct multiboot_info *mb_boot_info, uint64_t magic) {
  int argc = 0;
  char **argv = 0;
  
  if (magic != 0x2BADB002) {
    return;
  }

  boot_info = *mb_boot_info;

  monitor_init();
  //monitor_write(OS_VERSION_STRING "\n");
  //monitor_write("Wilkommen.");
  //monitor_scroll();
  //main(argc, argv);
  return;
}
*/
