#include <stdio.h>
#include <stdlib.h>
#include <oskit/clientos.h>
#include <oskit/startup.h>
#include <oskit/version.h>

int main()
{
#ifndef KNIT
	oskit_clientos_init();
#endif
#ifdef  GPROF
	start_fs_bmod();
	start_gprof();
#endif
	putchar('Z' - '@');
	//	oskit_print_version();
	//printf("Hello, World\n");
        osenv_log(OSENV_LOG_INFO, "%s", "OS Booted!\n");

	puts("Tell me your shit. ");
	
	char str[100];
	memset(str, 0, sizeof(str));
	if(fgets(str, 100, stdin) != NULL) {
	  printf("%d: %s\n", strlen(str), str);
	} else {
		puts("failz");
		}
	//	getchar();
	osenv_panic("I have decided to panic instead of exiting.");
        return 0;
}
