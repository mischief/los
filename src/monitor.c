#include <monitor.h>
#include <port.h>
#include <string.h>

static oskit_u8_t *vmem;
static oskit_u16_t cursor_x;
static oskit_u16_t cursor_y;

static oskit_u8_t attrib;
static oskit_u16_t blank = 0x20 | ((0 << 4) | (15 & 0x0F) << 8);

void monitor_init(void) {
  vmem = (oskit_u8_t *) 0x000B8000;
  cursor_x = cursor_y = 0;
  attrib = (0 << 4) | (15 & 0x0F);
  monitor_clear();
}

static void move_cursor(void) {
  /* do we really need this dumb shit? */
  /*
  oskit_u16_t loc = cursor_y * 80 + cursor_x;
  outb(0x3D4, 14);
  outb(0x3D5, loc >> 8);
  outb(0x3D4, 15);
  outb(0x3D5, loc);
  */
}

static void scroll(void) {
  if(cursor_y >= 25) {
    int i;
    for(i = 0; i < 24*80; ++i) {
      vmem[i] = vmem[i+80];
    }
    for(i = 24*80; i < 25*80; ++i) {
      vmem[i] = blank | (attrib << 8);
    }
    cursor_y = 24;
  }
}

void monitor_put(char c) {
  if(c == 0x08 && cursor_x) {
    cursor_x--;
  } else if(c == 0x09) {
    cursor_x = (cursor_x+8) & ~(8-1);
  } else if(c == '\r') {
    cursor_x = 0;
  } else if(c == '\n') {
    cursor_x = 0;
    cursor_y++;
  } else if(c >= ' ') {
    *(vmem + (cursor_y*80 + cursor_x)) = c | (attrib << 8);
    cursor_x++;
  }
  if(cursor_x >= 80) {
    cursor_x = 0;
    cursor_y++;
  }
  scroll();
  move_cursor();
}

void monitor_clear(void) {
  int i;
  for(i = 0; i < 80*25; ++i) {
    vmem[i] =  blank;
  }
  cursor_x = cursor_y = 0;
  move_cursor();
}

void monitor_write(char *c) {
  int i = 0;
  while(c[i])
    monitor_put(c[i++]);
}
