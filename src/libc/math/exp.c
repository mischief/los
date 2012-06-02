#include <math.h>
//#include <stdint.h>
#include <oskit/types.h>

/* by apples */

/* ieee754 binary64 */
double frexp(double x, int *exp) {
  oskit_u64_t tmp = *(oskit_u64_t *)&x;

  /* extract exponent and normalize it */
  *exp = ((tmp >> 52) & 0x7ff) - 0x3fe;

  /* set the exponent to 0, putting it in the range (0.5, 1] */
  tmp &= ~(0x7ffULL << 52);
  tmp |= 0x3feULL << 52;

  return *(double*)&tmp;
}

double ldexp(double x, int exp) {
  oskit_u64_t tmp = *(oskit_u64_t *)&x;

  tmp &= ~(0x7ffULL << 52);
  tmp |= ((unsigned)(exp + 0x3fe) & 0x7ffULL) << 52;

  return *(double*)&tmp;
}
