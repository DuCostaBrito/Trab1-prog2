#include "events.h"
#include "utils.h"
lista_t *lista_cria()
{
    lista_t *l;
    /* aloca espaco para a cabeca da lista_t */
    if (!(l = (lista_t *)malloc(sizeof(lista_t))))
        return NULL;

    l->nodes = (nodo_l_t *)malloc(sizeof(nodo_l_t) * BLOCK);
    l->max_size = BLOCK;
    l->size = 0;
    return l;
}

/* Funcao para reajustar o tamanho */
void resize(lista_t *l)
{
    nodo_l_t *tmp = (nodo_l_t *)realloc(l->nodes, (l->max_size + BLOCK) * sizeof(nodo_l_t));
    if (tmp != NULL)
    {
        l->nodes = tmp;
        l->max_size = l->max_size + BLOCK;
    }
}

/* Insere o nodo na lista, mas antes procura por um nome similar */
void insert(lista_t *l, char *name, int year, int i)
{
    /* Confere se ha a necessidade de realocar mais espaco*/
    if (l->size >= l->max_size)
        resize(l);
    strcpy(l->nodes[l->size].name, name);
    l->nodes[l->size].year = year;
    l->nodes[l->size].author = i;
    l->nodes[l->size].flag = '0';
    l->size = l->size + 1;
    return;
}
