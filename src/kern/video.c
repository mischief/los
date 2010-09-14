#include <video.h>
#include <port.h>
#include <string.h>

static uint8_t *vmem;
static uint16_t xpos, ypos;
static uint8_t cols, rows, attrib;

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

static void video_scroll(void) {
  ypos--;
  memcpy(vmem, vmem + cols * 2, cols * (rows - 1) * 2);
  memset(vmem + cols * (rows - 1) * 2, 0, cols * 2);
}

static void video_clear(void) {
  memset(vmem, 0, cols * rows * 2);
  xpos = ypos = 0;
  move_cursor();
}

void video_init(void) {
  vmem = (uint8_t *) 0xB8000;
  cols = 80;
  rows = 25;
  xpos = ypos = 0;
  video_set_fg(FG_WHITE);
  video_set_bg(BG_BLACK);
  video_clear();
}

void video_put(char c) {
  if(c == '\r') {
    xpos = 0;
    return;
  }
  
  if(xpos >= cols || c == '\n') {
    xpos = 0;
    ypos++;
    if(ypos >= rows)
      video_scroll();
    if(c == '\n')
      return;
  }
  
  if(c == '\b' && xpos) {
    xpos--;
  }
  
  if(c == '\t') {
    xpos = (xpos+8) & ~(8-1);
  }
  
  if(c >= ' ') {
    vmem[(xpos + ypos * cols) * 2] = (uint8_t) c;
    vmem[(xpos + ypos * cols) * 2 + 1] = attrib;
    xpos++;
  }
  
  move_cursor();
}

void video_write(char *c) {
  int i = 0;
  while(c[i])
    video_put(c[i++]);
}

void video_set_fg(uint8_t color) {
  attrib = (attrib & 0xF0) | (color & 0x0F);
}

void video_set_bg(uint8_t color) {
  attrib = (attrib & 0x0F) | (color & 0xF0);
}
