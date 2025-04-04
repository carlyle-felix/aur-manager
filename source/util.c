#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#include "../include/util.h"
#include "../include/memory.h"

Buffer get_buffer(const char *cmd) {
	
	char *temp_buffer = NULL;
	FILE *p;	
	Buffer temp = NULL;
	
	str_malloc(&temp_buffer, MAX_BUFFER);

	p = popen(cmd, "r");
	if (p == NULL) {
		printf(BRED"ERROR:"BOLD" Failed in buffer().\n"RESET);
		exit(EXIT_FAILURE);
	}
	fgets(temp_buffer, MAX_BUFFER, p);
	pclose(p);

	if (strlen(temp_buffer) == 0) {
		free(temp_buffer);
		return NULL;
	}

	str_malloc(&temp, (strlen(temp_buffer) + 1));
	strcpy(temp, temp_buffer);
	free(temp_buffer);

	return temp;
}

void get_str(char **cmd, const char *str, const char *str_var) {
	
	if (str_var != NULL) {
		str_malloc(cmd, strlen(str) + strlen(str_var) - 1);
		sprintf(*cmd, str, str_var);
	} else {
		str_malloc(cmd, strlen(str) + 1);
		sprintf(*cmd, str);
	}
}

bool is_dir(char *pkgname) {

	DIR* dir = opendir(pkgname);
	if (dir) {
		closedir(dir);
		return true;
	} else {
		return false;
	}
}

bool file_exists(char *path) {
	
	FILE *f;
	int result;

	f = fopen(path, "r");
	if (f != NULL) {
		fclose(f);
		return true;
	} else {
		return false;
	}
}

bool prompt(void) {

	char c;

	for (;;) {
        c = tolower(getchar());
        if (c != '\n') {
			while (getchar() != '\n');
		}
        if (c == 'y' || c == '\n') {
			return true;
        } else if (c == 'n') {
			return false;
        }
    }
}