#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define LINESIZE 80
#define N_ARCHS 1

struct lattes
{
    char *all_content; // String contendo todo o arquivo xml
    
};

char **list_filename(char *dirname);
void free_list(char **list, int size);

#endif