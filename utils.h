#ifndef _utils_t_H
#define _utils_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include "events.h"
#define LINESIZE 240
#define BLOCK 200
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(char *s1, char *s2);
char **list_filename(char *dirname, int *num_arq);
void free_list_filenames(char **list, int size);
void get_all_events(char **filenames, char **lattesnames, int num_files, lista_t *Periodicos, lista_t *Conferencias);
void get_qualifications(char *filename, lista_t *eventos);
/* Funcao para printar vetor de autores */
void author_summary(int periodicos[], int conferencias[], char **authornames, int num);
void display_menu();

#endif