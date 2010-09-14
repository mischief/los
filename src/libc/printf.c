#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

#define PAD_RIGHT 1
#define PAD_ZERO 2
#define PRINT_BUF_LEN 12

static void printchar(char **str, int c) {
  if(str) {
    **str = c;
    ++(*str);
  } else {
      putchar(c);
  }
}

static int prints(char **out, const char *string, int width, int pad) {
  register int pc = 0, padchar = ' ';
  
  const char *nil = "(null)";
  
  if(string == NULL)
    string = nil;

  if(width > 0) {
    register int len = 0;
    register const char *ptr;
    for (ptr = string; *ptr; ++ptr) {
      ++len;
    }

    if (len >= width)
      width = 0;
    else
      width -= len;
      
    if (pad & PAD_ZERO)
      padchar = '0';
  }

  if (!(pad & PAD_RIGHT)) {
    for ( ; width > 0; --width) {
      printchar (out, padchar);
      ++pc;
    }
  }
  
  for(; *string ; ++string) {
    printchar(out, *string);
    ++pc;
  }
  
  for(; width > 0; --width) {
    printchar(out, padchar);
    ++pc;
  }

  return pc;
}

static int printi(char **out, int i, int b, int sg, int width, int pad, int letbase) {
  char print_buf[PRINT_BUF_LEN];
  register char *s;
  register int t, neg = 0, pc = 0;
  register unsigned int u = i;

  if (i == 0) {
    print_buf[0] = '0';
    print_buf[1] = '\0';
    return prints (out, print_buf, width, pad);
  }

  if (sg && b == 10 && i < 0) {
    neg = 1;
    u = -i;
  }

  s = print_buf + PRINT_BUF_LEN-1;
  *s = '\0';

  while (u) {
    t = u % b;
    if( t >= 10 )
      t += letbase - '0' - 10;
      
    *--s = t + '0';
    u /= b;
  }

  if (neg) {
    if( width && (pad & PAD_ZERO) ) {
      printchar (out, '-');
      ++pc;
      --width;
    } else {
      *--s = '-';
    }
  }

  return pc + prints (out, s, width, pad);
}

static int print(char **out, const char *fmt, va_list ap) {
  register const char *c = fmt;
  register int pc = 0; // total chars written
  int i = 0; // format string index
  int width, pad;
  
  char shit[2];
  
  while(*c) {
   
    if(*c == '%') {
      ++i; ++c;
      width = pad = 0;
      if(*c == '\0') break;
      if(*c == '%') goto out;
      if(*c == '-') {
        c++;
        pad = PAD_RIGHT;
      }
      
      while(*c == '0') {
        c++;
        pad |= PAD_ZERO;
      }
      
      for(; *c >= '0' && *c <= '9'; ++c) {
        width *= 10;
        width += *c - '0';
      }

      switch(*c) {
      case 'd':
        pc += printi(out, va_arg(ap, int), 10, 1, width, pad, 'a');
        break;
      case 'u':
        pc += printi(out, va_arg(ap, unsigned long), 10, 0, width, pad, 'a');
        break;
      case 's':
        pc += prints(out, va_arg(ap, char *), width, pad);
        break;
      case 'x':
        pc += printi(out, va_arg(ap, unsigned long), 16, 0, width, pad, 'a');
        break;
      case 'X':
        pc += printi(out, va_arg(ap, unsigned long), 16, 0, width, pad, 'A');
        break;
      case 'c':
        shit[0] = va_arg(ap, int);
        shit[1] = '\0';
        pc += prints(out, shit, width, pad);
        break;
      case 'p':
        pc += prints(out, "0x", 0, 0);
        pad |= PAD_ZERO;
        width = 8;
        pc += printi(out, va_arg(ap, unsigned long), 16, 0, width, pad, 'a');
        break;
      default:
        pc += prints(out, ":O ", width, pad);
        break;
      }

    } else {
    out:
      printchar(out, *c);
      ++pc;
    }
    
  //~ next:
    ++i; ++c;
  }
    
  if (out) **out = '\0';
  
  return pc;
}

int printf(const char *format, ...) {
  
  va_list args;
  int rv;
  
  va_start(args, format);
  rv = print(0, format, args);
  va_end(args);
  
  return rv;
}

int vprintf(const char *format, va_list vl) {
  return print(0, format, vl);
}

int sprintf(char *out, const char *format, ...) {
  
  va_list args;
  int rv;
  
  va_start(args, format);
  rv = print(&out, format, args);
  va_end(args);
  
  return rv;
}
