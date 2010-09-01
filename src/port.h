#ifndef PORT_H
#define PORT_H

#include <oskit/x86/types.h>

void outb(oskit_u16_t port, oskit_u8_t value);
oskit_u8_t inb(oskit_u16_t port);
oskit_u16_t inw(oskit_u16_t port);

#endif
