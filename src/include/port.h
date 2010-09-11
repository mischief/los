#ifndef PORT_H
#define PORT_H

#include <compiler.h>
#include <stdint.h>

BEGIN_DECLS

void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);

END_DECLS

#endif
