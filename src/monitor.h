#ifndef MONITOR_H
#define MONITOR_H

#include <oskit/x86/types.h>

void monitor_init(void);
void monitor_put(char c);
void monitor_clear(void);
void monitor_write(char *c);

#endif
