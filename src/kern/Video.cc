#include <Video.hh>

#include <string.h>

Video::Video() {
  vmem = VIDEO_BASE;
  cols = 80;
  rows = 25;
  xpos = ypos = 0;
  set_fg(VGAFGLightGrey);
  set_bg(VGABGBlue);
  clear();
}

Video::~Video() {
}

void Video::clear(void) {
  memset(vmem, 0, cols * rows * 2);
  xpos = ypos = 0;
}

void Video::write(char *s) {
  int i = 0;
  while(s[i])
    put(s[i++]);
}

void Video::writeln(char *s) {
  write(s);
  put('\n');
}

void Video::put(char c) {
  if(c == '\r') {
    xpos = 0;
    return;
  }

  if(xpos >= cols || c == '\n') {
    xpos = 0;
    ypos++;
    if(ypos >= rows)
      scroll();
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
  
}

void Video::scroll(void) {
  ypos--;
  memcpy(vmem, vmem + cols * 2, cols * (rows - 1) * 2);
  memset(vmem + cols * (rows - 1) * 2, 0, cols * 2);
}

void Video::set_fg(VGAFGColor color) {
  attrib = (attrib & 0xF0) | (color & 0x0F);
}

void Video::set_bg(VGABGColor color) {
  attrib = (attrib & 0x0F) | (color & 0xF0);
}

