/* Estrutura de lista para armazenar os artigos */
#ifndef _EVENTS_t_H
#define _EVENTS_t_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nodo_l {
    int author;  /* Nos diz quem eh o autor do artigo */
    int year;   /* Ano de publicacao */
    int quali; /* Classificacao */
    char name[240]; /* Nome do evento */
    char flag;  /* sinaliza se ja foi contado. "0" ja foi contado, caso contrario "1" */
};
typedef struct nodo_l nodo_l_t;

struct lista {
    nodo_l_t *nodes;      /* Nodos que serao alocados */
    int size;        /* Index que paramos  de inserir, e tambem o numero total de artigos */
    int max_size;
};
typedef struct lista lista_t;

lista_t *lista_cria();
void insert(lista_t *l, char *name, int year, int i);


#endif