#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define LINESIZE 120
#define N_ARCHS 1
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

char **list_filename(char *dirname, int *list_size);
void free_list_filenames(char **list, int size);
unsigned char *read_file(FILE *file);
char *get_data(char *string, char *lable, char **pointer);
char *get_inside_lable(char *string);
void process_data(char *string);
void find_quali(char *file_path ,char *name);

#endif