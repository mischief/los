#ifndef VIDEO_HH
#define VIDEO_HH

#include <compiler.h>
#include <stdint.h>

enum VGAFGColor {
  VGAFGBlack, VGAFGBlue, VGAFGGreen, VGAFGCyan, VGAFGRed, VGAFGMagenta, VGAFGBrown, VGAFGLightGrey, VGAFGDarkGrey,
  VGAFGLightBlue, VGAFGLightGreen, VGAFGLightCyan, VGAFGLightRed, VGAFGLightMagenta, VGAFGLightBrown, VGAFGWhite
};


enum VGABGColor {
  VGABGBlack = VGAFGBlack << 4,
  VGABGBlue = VGAFGBlue << 4,
};

#define VIDEO_BASE ((uint8_t *) 0xB8000)

class Video {
public:
  Video(void);
  ~Video(void);
  void clear(void);
  void write(char *s);
  void writeln(char *s);
  void put(char c);
  void scroll(void);
  void set_fg(VGAFGColor color);
  void set_bg(VGABGColor color);
  VGAFGColor get_fg(void);
  VGABGColor get_bg(void);
  
private:
  uint8_t *vmem;
  uint16_t xpos, ypos;
  uint8_t attrib;
  uint8_t rows, cols;

};

#endif
