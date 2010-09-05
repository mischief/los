#include <kmain.h>
#include <monitor.h>
#include <version.h>

#include <multiboot.h>

struct multiboot_info boot_info;

void kmain(struct multiboot_info *mb_boot_info, uint64_t magic) {
  
  /* bad magic. just die. */
  if (magic != 0x2BADB002) {
    return;
  }

  boot_info = *mb_boot_info;

  /* Write your kernel here. */

  monitor_init();
  monitor_write(OS_VERSION_STRING "\n");
  monitor_write("Wilkommen.");
  //monitor_scroll();
  return;
}

/*
void printf (const char *format, ...) {
  char **arg = (char **) &format;
  int c;
  char buf[20];

  arg++;

  while ((c = *format++) != 0) {
    if (c != '%')
      putchar (c);
    else {
      char *p;

      c = *format++;
      switch (c) {
        case 'd':
        case 'u':
        case 'x':
          itoa (buf, c, *((int *) arg++));
          p = buf;
          goto string;
        break;

        case 's':
          p = *arg++;
          if (! p)
            p = "(null)";

        string:
          while (*p)
          putchar (*p++);
        break;

        default:
          putchar (*((int *) arg++));
        break;
      }
    }
  }
}
*/
