/* Estrutura de lista para armazenar os artigos */
#ifndef _LIBlist_t_H
#define _LIBlist_t_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nodo_l {
    char name[120]; /* Nome do evento */
    char quali[3];
    int n_participation;  /* Numero de partipacoes */
};
typedef struct nodo_l nodo_l_t;

struct lista {
    nodo_l_t *nodes;      /* Nodos que serao alocados */
    int size;        /* Index que paramos  de inserir, e tambem o numero total de artigos */
};
typedef struct lista lista_t;

lista_t *lista_cria();
void insert(lista_t *l, char *name, char *quali);
void lista_imprime(lista_t *l, int i);

#endif