/* Estrutura de lista para armazenar os artigos */
#ifndef _LIBlist_t_H
#define _LIBlist_t_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nodo_l {
    char name[120];
    int year;
    int number;       
    struct nodo_l* prox;  /* ponteiro para o proximo   */
};
typedef struct nodo_l nodo_l_t;

struct lista {
    nodo_l_t* ini;      /* ponteiro para o inicio da lista */
    int tamanho;        /* numero de elementos na lista    */
};
typedef struct lista lista_t;

/*
 * Cria uma lista vazia e a retorna, se falhar retorna NULL.
*/
lista_t* lista_cria ();

/*
 * Remove todos os elementos da lista, libera espaco e retorna NULL.
*/
lista_t* lista_destroi (lista_t* l);

/*
 * Retorna 1 se a lista esta vazia e 0 caso contrario.
*/
int lista_vazia (lista_t* l);

/*
 * Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela.
*/
int lista_tamanho (lista_t* l);

/*
 * Insere o elemento no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_insere_inicio (lista_t* l, char *name, int year);

int lista_insere_ordenado (lista_t* l, char *name, int year);

/*
 * Retorna 1 se o elemento existe na lista e 0 caso contrario.
*/
int lista_pertence (lista_t* l, char *name);

/*
 * Imprime a lista, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a lista estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD lista.
*/
void lista_imprime (lista_t* l, int i);

int data_by_year(lista_t *l, int year);

#endif