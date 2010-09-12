#ifndef STDARG_H
#define STDARG_H

#define __va_size(type) ((sizeof(type)+3) & ~0x3)

#ifndef _VA_LIST_
#define _VA_LIST_
typedef char * va_list;
#endif

#define va_start(v, l) \
  ((v) = (char*)(void*)&(l) + __va_size(l))

#define va_end(v)

#define va_arg(v, l) \
  ((v) == __va_size(type), \
  *((type *)((v) - __va_size(type))))

#endif
