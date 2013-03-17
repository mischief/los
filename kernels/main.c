#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oskit/clientos.h>
#include <oskit/startup.h>
#include <oskit/version.h>
#include <oskit/x86/cpuid.h>
#include <oskit/x86/pc/base_multiboot.h>
#include <oskit/x86/base_vm.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include <assert.h>

#include <oskit/dev/dev.h>
#include <oskit/dev/linux.h>
#include <oskit/dev/tty.h>
#include <oskit/io/blkio.h>
#include <oskit/diskpart/diskpart.h>
#include <oskit/c/environment.h>
#include <oskit/c/stdio.h>
#include <oskit/c/string.h>
#include <oskit/c/sys/types.h>
//#include <oskit/clientos.h>
//#include <oskit/startup.h>
#include <oskit/fs/memfs.h>

// added to please dols
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>   /* for mkdir ! */
#include <dirent.h>
#include <errno.h>
#include <oskit/fs/memfs.h>
#include <oskit/clientos.h>
#include <oskit/c/fs.h>
#include <assert.h>
#include <oskit/startup.h>

#include "main.h"
#include "util.h"

const char initfilename[] = INITFILE;

oskit_osenv_t *osenv;

extern char **environ;

static int argcount;
static char **argvector;

int luaopen_los(lua_State* L);

int main(int argc, char **argv) {
  argcount = argc;
  argvector = argv;

  extern char **environ;
  unsigned i = 0;

  printf("\nI was given this command line, environment, and bootopts:\n");
  for (i = 0; i < argc; i++)
    printf("  argv[%d]: `%s'\n", i, argv[i]);
  for (i = 0; environ[i]; i++)
    printf("  environ[%d]: `%s'\n", i, environ[i]);
  for (i = 0; i < oskit_bootargc; i++)
    printf("  oskit_bootargv[%d]: `%s'\n", i, oskit_bootargv[i]);

  //multiboot_info_dump(&boot_info);

  printf("Starting subsystems... ");

  printf("clientos ");
	oskit_clientos_init();

  printf("osenv ");
  osenv = start_osenv();

  printf("dev_init ");
  oskit_dev_init(osenv);

  printf("clock ");
  start_clock();

  printf("fs_bmod ");
  start_fs_bmod();

  //printf("\n");
  //printf("dump_drivers:\n");
  //oskit_dump_drivers();

  //start_devices();
  //start_blk_devices();
  //printf("dev_probe:\n");
  //oskit_dev_probe();
  //printf("dump_devices:\n");
  //oskit_dump_devices();

  //start_console();

#if 0
// broken
  dols("/", 1);
#endif

  printf("lua ");
  lua_State *L = luaL_newstate(); /* opens Lua */
  luaL_openlibs(L); /* opens the standard libraries */
  luaopen_los(L);

  printf("\n");

  // run init file
  if(luaL_dofile(L, initfilename) != 0) {
    fprintf(stderr, "%s: fatal error: %s\n", initfilename, lua_tostring(L, -1));
    lua_pop(L, -1);
  }
  printf("\n");

  puts("Lua OS Exiting - press any key to reboot.");
  getchar();
  return 0;
}

static const luaL_Reg loslib[] = {
  {"exit", los_exit},
  {"cpuid", los_cpuid},
  {NULL, NULL}
};

int luaopen_los(lua_State* L) {

  luaL_newlib(L, loslib);

  lua_pushstring(L, (char*) phystokv(boot_info.cmdline));
  lua_setfield(L, -2, "cmdline");

  // move multiboot shit to lua
  lua_pushnumber(L, boot_info.mem_lower);
  lua_setfield(L, -2, "mem_lower");

  lua_pushnumber(L, boot_info.mem_upper);
  lua_setfield(L, -2, "mem_upper");

  // argv table
  lua_newtable(L);
  for(int i = 0; i < argcount; i++) {
    lua_pushnumber(L, i+1);
    lua_pushstring(L, argvector[i]);
    lua_rawset(L, -3);
  }
  lua_setfield(L, -2, "argv");

  // environ table
  lua_newtable(L);
  for(int i=0; environ[i]; i++) {
    lua_pushnumber(L, i+1);
    lua_pushstring(L, environ[i]);
    lua_rawset(L, -3);
  }
  lua_setfield(L, -2, "environ");

  // oskit_argv table
  lua_newtable(L);
  for(int i=0; i < oskit_bootargc; i++) {
    lua_pushnumber(L, i+1);
    lua_pushstring(L, oskit_bootargv[i]);
    lua_rawset(L, -3);
  }
  lua_setfield(L, -2, "oskit_bootargv");

  // boot module table
  lua_newtable(L);

  struct multiboot_module *m;
  m = (struct multiboot_module *)phystokv(boot_info.mods_addr);

  for(int i = 0; i < boot_info.mods_count; i++) {
    lua_pushnumber(L, i+1);
    lua_pushstring(L, (char *) phystokv(m[i].string));
    lua_rawset(L, -3);
  }
  lua_setfield(L, -2, "bmods");

  lua_pushstring(L, LOS_VERSION_STRING);
  lua_setfield(L, -2, "los_version");

  lua_pushstring(L, _OSKIT_VERSION_STRING);
  lua_setfield(L, -2, "oskit_version");

  lua_setglobal(L, "los");

  return 0;
}

