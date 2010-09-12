#include <stdio.h>
#include <video.h>

int putchar(int c) {
  video_put(c);
  return c;
}

