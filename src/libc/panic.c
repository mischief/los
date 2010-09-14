#include <stdio.h>
#include <stdarg.h>
#include <oskit/debug.h>

void panic(const char *format, ...) {
  va_list vl;
  va_start(vl, format);
  vprintf(format, vl);
  va_end(vl);
  printf("\n");

  //~ __asm__ __volatile__("int $0x0");
}
