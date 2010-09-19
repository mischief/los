#ifndef VIDEO_H
#define VIDEO_H

#include <old/stdint.h>

#define FG_BLACK 0
#define FG_BLUE 1
#define FG_GREEN 2
#define FG_CYAN 3
#define FG_RED 4
#define FG_MAGENTA 5
#define FG_BROWN 6
#define FG_LIGHT_GREY 7
#define FG_DARK_GREY 8
#define FG_LIGHT_BLUE 9
#define FG_LIGHT_GREEN 10
#define FG_LIGHT_CYAN 11
#define FG_LIGHT_RED 12
#define FG_LIGHT_MAGENTA 13
#define FG_LIGHT_BROWN 14
#define FG_WHITE 15

#define BG_BLACK (FG_BLACK << 4)
#define BG_BLUE (FG_BLUE << 4)
#define BG_GREEN (FG_GREEN << 4)
#define BG_CYAN (FG_CYAN << 4)
#define BG_WHITE (FG_WHITE << 4)

void video_init(void);
void video_put(char c);
void video_write(char *c);

void video_set_fg(uint8_t color);
void video_set_bg(uint8_t color);

#endif
