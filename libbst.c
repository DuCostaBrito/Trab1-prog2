#include <stdio.h>
#include <stdlib.h>
#include "libbst.h"

// Funcao inicializadora de nodo
tNo_t *criaNodo(int ano)
{
    int i;
    tNo_t *nodo = (tNo_t *)malloc(sizeof(tNo_t));
    nodo->ano = ano;
    for (i = 0; i < 10; i++)
    {
        // Inicializando o vetor como nulo
        nodo->periodicos[i] = 0;
        nodo->conferencias[i] = 0;
    }
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

// Retorna o nodo desejado
tNo_t *busca(tNo_t *raiz, int ano)
{
    if (raiz==NULL || raiz->ano == ano)
        return raiz;
    else if (ano > raiz->ano)
        return busca(raiz->dir, ano);
    else   
        return busca(raiz->esq, ano);
}

// Funcao de insercao
tNo_t *insercao(tNo_t *raiz, int ano)
{
    // Caso base
    if (raiz == NULL)
        return criaNodo(ano);

    // Achando o lugar apropriado para inserir o nodo(BST )
    if (ano < raiz->ano)
        raiz->esq = insercao(raiz->esq, ano);
    else if (ano >= raiz->ano)
        raiz->dir = insercao(raiz->dir, ano);

    return raiz;
}

// Funcao para destruir a arvore
void destroiBST(tNo_t *raiz)
{
    if (raiz == NULL)
        return;

    destroiBST(raiz->esq);
    destroiBST(raiz->dir);
    free(raiz);
}