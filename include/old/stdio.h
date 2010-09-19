#ifndef STDIO_H
#define STDIO_H

#include <old/stdarg.h>

int putchar(int c);
int puts(const char *s);
int printf(const char *format, ...);
int vprintf(const char *format, va_list vl);
int sprintf(char *out, const char *format, ...);

#endif
