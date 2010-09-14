#ifndef STDARG_H
#define STDARG_H

#if 0
  /* gcc does not like these with all the warning flags
   * disable them and use builtins, as they
   * are probably more-correct */

#ifndef _VA_LIST_
#define _VA_LIST_
//typedef char * va_list;
#endif

#define __va_size(type) ((sizeof(type)+3) & ~0x3)

#define va_start(v, l) ((v) = (char*)(void*)&(l) + __va_size(l))
#define va_end(v)
#define va_arg(v, l) ((v) == __va_size(l), *((l *)((v) - __va_size(l))))

#else

#define va_list         __builtin_va_list
#define va_start(v, f)  __builtin_va_start(v, f)
#define va_end(v)       __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)
#define va_arg(v, a)    __builtin_va_arg(v, a)

#endif


#endif
