#include <stdio.h>
#include <unistd.h>
#include "../include/install.h"
#include "../include/update.h"
#include "../include/uninstall.h"
#include "../include/memory.h"

void set_dir(void);

int main(int argc, char *argv[]) {

	set_dir();

	if (argc == 1 || argv[1] == "-h") {
        printf("-u						update\n");
		printf("-i [git clone URL]				install\n");
		printf("-c						clean AUR dir\n");
	} else if (strcmp(argv[1], "-u") == 0) {
		update();
	} else if (strcmp(argv[1], "-i") == 0) { 
		clone(argv[2]);
	} else if (strcmp(argv[1], "-c") == 0) { 
		clean();
	} 

	return 0;
}

void set_dir(void) {

	char *home, *aur = NULL;

	home = getenv("HOME");
	mem_alloc(&aur, VSTR(aur), strlen(home) + 6);
	sprintf(aur, "%s/.aur", home);
	chdir(aur);
	free(aur);
}