#include "libbst.h"

// Funcao inicializadora de nodo
tNo_t *criaNodo(int ano)
{
    int i;
    tNo_t *nodo = (tNo_t *)malloc(sizeof(tNo_t));
    nodo->ano = ano;
    for (i = 0; i < 9; i++)
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
    if (raiz == NULL || raiz->ano == ano)
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

// Funcao para imprimir a arvore (in-order traversal)
void imprimeBST(tNo_t *raiz)
{
    if (raiz == NULL)
        return;

    imprimeBST(raiz->esq);
    printf("Ano: %d \n", raiz->ano);
    printf("     PER     CONF \n");
    printf("A1   %d     %d \n", raiz->periodicos[0], raiz->conferencias[0]);
    printf("A2   %d     %d \n", raiz->periodicos[1], raiz->conferencias[1]);
    printf("A3   %d     %d \n", raiz->periodicos[2], raiz->conferencias[2]);
    printf("A4   %d     %d \n", raiz->periodicos[3], raiz->conferencias[3]);
    printf("B1   %d     %d \n", raiz->periodicos[4], raiz->conferencias[4]);
    printf("B2   %d     %d \n", raiz->periodicos[5], raiz->conferencias[5]);
    printf("B3   %d     %d \n", raiz->periodicos[6], raiz->conferencias[6]);
    printf("B4   %d     %d \n", raiz->periodicos[7], raiz->conferencias[7]);
    printf("C    %d     %d \n", raiz->periodicos[8], raiz->conferencias[8]);
    imprimeBST(raiz->dir);
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