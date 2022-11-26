/* Biblioteca de funcoes para display */
#ifndef _PRINTFUNCTIONS_t_H
#define _PRINTFUNCTIONS_t_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "events.h"
#define PROG_BAR_LENGTH 30

void summary(lista_t *l, int vetor[]);
void print_lista(lista_t *l);
void print_years(lista_t *per, lista_t *conf);
void print_authors(lista_t *per, lista_t *conf, char **lattesnames, int n);
void print_estrato(lista_t *l, int e);
void plotGraph(lista_t *Periodicos, lista_t *Conferencias);
void update_bar(int percent_done);
void display_menu();

#endif