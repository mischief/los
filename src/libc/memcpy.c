#include <string.h>

void *memcpy(void *s1, const void *s2, size_t n) {
  register char *dst = (char *) s1;
  register const char *src = (const char *) s2;
  
  while(n-- > 0) {
    *++dst = *++src;
  }
  
  return s1;
}
