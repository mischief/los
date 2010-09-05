#ifndef STDDEF_H
#define STDDEF_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned long size_t;

#define offsetof(st, m) __builtin_offsetof(st, m)

#endif
