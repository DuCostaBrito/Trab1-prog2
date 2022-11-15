#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "libpool.h"
#include "liblist.h"
#define LINESIZE 120
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

char **list_filename(char *dirname, int *num_arq);
void free_list_filenames(char **list, int size);
void process_wrapper(char **filenames, char **lattesnames, int num_files, char *per_path, char *conf_path, lista_t *Periodicos, lista_t *Conferencias, int vetor_per[], int vetor_conf[]);
void author_summary(int periodicos[], int conferencias[], char **authornames, int num);
void display_menu();

#endif