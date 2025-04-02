#ifndef MEMORY_H
#define MEMORY_H

#include <string.h>
#include <stdlib.h>

#define NAME_LEN 100

typedef struct node List;

void str_malloc(char **ptr, int size);
List *list_malloc(void);

#endif