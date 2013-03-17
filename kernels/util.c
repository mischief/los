#include "util.h"

// for lua
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include <stdio.h>

#include <oskit/c/stdlib.h>
#include <oskit/c/string.h>

// for cpuid routines
#include <oskit/x86/cpuid.h>

// lua call to exit(), which will reboot the kernel.
int los_exit (lua_State *L) {
  int status;
  if (lua_isboolean(L, 1))
    status = (lua_toboolean(L, 1) ? EXIT_SUCCESS : EXIT_FAILURE);
  else
    status = luaL_optint(L, 1, EXIT_SUCCESS);
  if (lua_toboolean(L, 2))
    lua_close(L);
  if (L) exit(status);  /* 'if' to avoid warnings for unreachable 'return' */
  return 0;
}

// printer utility for los_cpuid
static void luafmt(void *data, const char *fmt, ...) {
  va_list vl;
  char buf2[128];
  buf2[0] = buf2[127] = '\0';

  lua_State *L = (lua_State *) data;

  va_start(vl, fmt);
  vsnprintf(buf2, sizeof(buf2), fmt, vl);
  va_end(vl);

  // erase newline
  char *nl = strrchr(buf2, '\n');
  if(nl) *nl = '\0';

  lua_pushstring(L, buf2);
}

extern struct cpu_info base_cpuid;
// return a table of cpuid information
int los_cpuid (lua_State *L) {
  lua_newtable(L); /* creates a table */

  int size1 = lua_gettop(L); // store first size
  cpu_info_format(&base_cpuid, luafmt, L); //format shit
  int size2 = lua_gettop(L);

  int i;
  for(i = size2; i > size1; --i) {
    lua_rawseti(L, 1, i - size1);
  }

  return 1;
}

