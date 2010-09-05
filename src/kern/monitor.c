#include <monitor.h>
#include <port.h>
#include <string.h>

static uint8_t *vmem;      /* video memory address */
static uint16_t xpos;  /* X pos */
static uint16_t ypos;  /* Y pos */
static uint8_t attrib;     /* current attribute */

static uint8_t cols;
static uint8_t rows;

void monitor_init(void) {
  vmem = (uint8_t *) 0xB8000;
  cols = 80;
  rows = 25;
  xpos = ypos = 0;
  monitor_set_fg(FG_LIGHT_GREY);
  monitor_set_bg(BG_BLUE);
  monitor_clear();
}

static void move_cursor(void) {
  /* do we really need this dumb shit? */
  /*
  uint16_t loc = ypos * 80 + xpos;
  outb(0x3D4, 14);
  outb(0x3D5, loc >> 8);
  outb(0x3D4, 15);
  outb(0x3D5, loc);
  */
}

void monitor_scroll(void) {
  ypos--;
  memcpy(vmem, vmem + cols * 2, cols * (rows - 1) * 2);
  memset(vmem + cols * (rows - 1) * 2, 0, cols * 2);
}

void monitor_put(char c) {
  
  if(c == '\r') {
    xpos = 0;
    return;
  }
  
  if(xpos >= cols || c == '\n') {
    xpos = 0;
    ypos++;
    if(ypos >= rows)
      monitor_scroll();
    if(c == '\n')
      return;
  }
  
  /* backspace */
  /*if(c == '\b' && xpos) {
    xpos--;
  }*/
  
  /* tab */
  /*if(c == '\t') {
    xpos = (xpos+8) & ~(8-1);
  }*/
  
  if(c >= ' ') {
    vmem[(xpos + ypos * cols) * 2] = (uint8_t) c;
    vmem[(xpos + ypos * cols) * 2 + 1] = attrib;
    xpos++;
  }
  
  move_cursor();
}

void monitor_clear(void) {
  memset(vmem, 0, cols * rows * 2);
  xpos = ypos = 0;
  move_cursor();
}

void monitor_write(char *c) {
  int i = 0;
  while(c[i])
    monitor_put(c[i++]);
}

void monitor_set_fg(uint8_t color) {
  attrib = (attrib & 0xF0) | (color & 0x0F);
}

void monitor_set_bg(uint8_t color) {
  attrib = (attrib & 0x0F) | (color & 0xF0);
}
