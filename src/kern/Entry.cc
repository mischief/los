#include <multiboot_main.h>
#include <version.h>

#include <multiboot.h>

#include <Video.hh>

struct multiboot_info boot_info;

extern int main(int argc, char *argv[]);

void multiboot_main(struct multiboot_info *mb_boot_info, uint64_t magic) {
  Video VESA;
  //int argc = 0;
  //char **argv = 0;

  if (magic != 0x2BADB002) {
    VESA.writeln("bad magic. bad wizard?");
    return;
  }

  boot_info = *mb_boot_info;

  VESA.writeln(OS_VERSION_STRING);
  //monitor_init();
  //monitor_write(OS_VERSION_STRING "\n");
  //monitor_write("Wilkommen.");
  //monitor_scroll();
  //main(argc, argv);
  return;
}
