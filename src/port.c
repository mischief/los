#include <port.h>

void outb(oskit_u16_t port, oskit_u8_t value) {
  __asm__ volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

oskit_u8_t inb(oskit_u16_t port) {
  oskit_u8_t v;
  __asm__ volatile("inb %1, %0" : "=a" (v) : "dN" (port));
  return v;
}

oskit_u16_t inw(oskit_u16_t port) {
  oskit_u16_t v;
  __asm__ volatile ("inw %1, %0" : "=a" (v) : "dN" (port));
  return v;
}
