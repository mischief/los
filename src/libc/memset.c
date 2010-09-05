#include <string.h>

void *memset(void *s, int c, size_t n) {
  register char *to = s;
  while(n-- > 0)
    *to++ = (char) c;

  return s;
}
