#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define LINESIZE 80
#define N_ARCHS 1

char **list_filename(char *dirname, int *list_size);
void free_list_filenames(char **list, int size);
unsigned char *read_file(FILE *file);
char *get_data(char *string, char *lable, char **pointer);
char *get_inside_lable(char *string);
void get_all_data(char *string, char *lable);

#endif