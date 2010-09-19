#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

#ifndef NULL
#define NULL 0
#endif

/* copies n bytes between two memory areas, which must not overlap */
void *memcpy(void *dest, const void *src, size_t n);

/* copies n bytes between two memory areas; unlike with memcpy the areas may overlap */
void *memmove(void *dest, const void *src, size_t n);

/* returns a pointer to the first occurrence of c in the first n bytes of s, or NULL if not found */
void *memchr(const void *s, char c, size_t n);

/* compares the first n characters of two memory areas */
int memcmp(const void *s1, const void *s2, size_t n);

/* overwrites a memory area with a byte pattern */
void *memset(void *s, int c, size_t n);

/* openbsd str functions, yes plz */
size_t strlcat(char *dest, const char *src, size_t n);
size_t strlcpy(char *dest, const char *src, size_t n);

#endif
