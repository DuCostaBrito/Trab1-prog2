#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "liblist.h"
#define LINESIZE 120
#define N_ARCHS 1
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

char **list_filename(char *dirname, int *list_size);
void free_list_filenames(char **list, int size);
unsigned char *read_file(FILE *file);
void get_data(char *string, char *lable, char *data, char **pointer);
char *get_inside_lable(char *string, char *data);
void process_event(char *string, char *lable[], lista_t *estrato[]);
void comparing(FILE *arq,char *name, char *quali,fpos_t *ini);
void get_lattes_data(char *lattes, char *per_path, char *conf_path);

#endif