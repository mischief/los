#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oskit/clientos.h>
#include <oskit/startup.h>
#include <oskit/version.h>
#include <oskit/x86/cpuid.h>
#include <oskit/x86/pc/base_multiboot.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include <assert.h>

#include <oskit/dev/dev.h>
#include <oskit/dev/linux.h>
#include <oskit/io/blkio.h>
#include <oskit/diskpart/diskpart.h>
#include <oskit/c/stdio.h>
#include <oskit/c/string.h>
//#include <oskit/clientos.h>
//#include <oskit/startup.h>

#define MAX_PARTS 30
diskpart_t part_array[MAX_PARTS];

extern struct cpu_info base_cpuid;

static int os_exit (lua_State *L) {
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

static int lua_cpuid (lua_State *L) {
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

int main(int argc, char **argv) {

  extern char **environ;
  unsigned i = 0;

#ifndef KNIT
	oskit_clientos_init();
  start_blk_devices();
#endif
#ifdef  GPROF
	start_fs_bmod();
	start_gprof();
#endif


#if 1

  oskit_blkio_t *b;
  oskit_error_t err;
  int numparts;
  char name[10];

 for (;;) {    printf("What disk do you want to check?"
           " (eg, \"sd0\", \"quit\" to exit): ");  gets(name);
    if (*name == '\0')      continue;
    if (strcmp(name, "quit") == 0)
      break;

    printf("\nGetting partition info for %s\n", name);
    /* Open the disk. */    err = oskit_linux_block_open(name, OSKIT_DEV_OPEN_READ, &b);    switch (err) {    case 0:      break;
    case OSKIT_E_DEV_NOSUCH_DEV:
      printf("disk %s does not exist!\n", name);
      continue;    default:      printf("error %x opening disk %s\n", err, name);      continue;
    }
    /*     * Get the partition info and dump it out.
     * Another way to do this is by using diskpart_get_partition,
     * which takes a callback function.
     * That is, in fact, what diskpart_blkio_get_partition ends
     * up calling.
     */
    numparts = diskpart_blkio_get_partition(b, part_array,
              MAX_PARTS);
    if (numparts == 0) {
      printf("No partitions found\n");
      continue;
    }
    printf("%d partitions found\n", numparts);
    diskpart_dump(part_array, 0, 'a');

    /* Close the disk. */
    oskit_blkio_release(b);
  }

#endif

  printf("Lua OS v0.0.1, with OSKit v%s.\n", _OSKIT_VERSION_STRING);
	printf("Type exit() to shutdown.\n");

  printf("\nI was given this command line, environment, and bootopts:\n");
  for (i = 0; i < argc; i++)
    printf("  argv[%d]: `%s'\n", i, argv[i]);
  for (i = 0; environ[i]; i++)
    printf("  environ[%d]: `%s'\n", i, environ[i]);
  for (i = 0; i < oskit_bootargc; i++)
    printf("  oskit_bootargv[%d]: `%s'\n", i, oskit_bootargv[i]);

  multiboot_info_dump(&boot_info);

  int error;
  lua_State *L = luaL_newstate(); /* opens Lua */
  luaL_openlibs(L); /* opens the standard libraries */
  lua_pushcfunction(L, os_exit);
  lua_setglobal(L, "exit");
  lua_pushcfunction(L, lua_cpuid);
  lua_setglobal(L,"cpuid");
  char str[4096];

  memset(str, 0, sizeof(str));
  //while(fgets(str, 100, stdin) != NULL && !strcmp(str, "stop")) {
  while(fputs("> ", stdout), fgets(str, sizeof(str), stdin) != NULL) {
    register char *nl;
    if(nl = strrchr(str, '\n'))
      *nl = '\0'; // remove newline

    error = 0;
    //error = luaL_loadbuffer(L, str, strlen(str), "line") || lua_pcall(L, 0, 0, 0);
    error = luaL_dostring(L, str);
    if (error) {
      fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));
      lua_pop(L, 1); // pop error message from the stack
    }

//    printf("%d: %s\n", strlen(str), str);
    memset(str, 0, sizeof(str));
  }

  puts("Lua OS Exiting - press any key to reboot.");
  getchar();
  return 0;
}
