/* Quaiquer outras funcoes relacionadas a manipulacao de arquivo xml*/
#ifndef _utils_t_H
#define _utils_t_H
#include "events.h"
#include "printFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define LINESIZE 300
#define BLOCK 200
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

char **list_filename(char *dirname, int *num_arq);
void free_list_filenames(char **list, int size);
void get_all_events(char **filenames, char **lattesnames, int num_files, lista_t *Periodicos, lista_t *Conferencias);
void get_qualifications(char *filename, lista_t *eventos, int max_dist);

#endif