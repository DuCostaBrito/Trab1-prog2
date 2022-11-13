#include "liblist.h"

lista_t *lista_cria()
{
    lista_t *l;
    nodo_l_t *nodo1, *nodo2;

    /* aloca espaco para a cabeca da lista_t */
    if (!(l = (lista_t *)malloc(sizeof(lista_t))))
        return NULL;

    if (!(nodo1 = (nodo_l_t *)malloc(sizeof(nodo_l_t))))
    {
        free(l);
        return NULL;
    }

    if (!(nodo2 = (nodo_l_t *)malloc(sizeof(nodo_l_t))))
    {
        free(nodo1);
        free(l);
        return NULL;
    }

    /* crio dois nodos "fantasmas" para evitar alguns ifs depois */
    /* a lista vazia eh quando l->ini->prox->prox == NULL        */
    l->tamanho = 0;
    l->ini = nodo1;
    nodo1->prox = nodo2;
    nodo2->prox = NULL;
    nodo1->number = 0;
    nodo2->number = 0;

    return l;
}

lista_t *lista_destroi(lista_t *l)
{
    nodo_l_t *aux;

    while (l->ini->prox->prox != NULL)
    {
        aux = l->ini->prox;
        l->ini->prox = aux->prox;
        aux->number = 0;
        free(aux);
    }

    free(l->ini->prox);
    free(l->ini);
    l->ini = NULL;
    l->tamanho = 0;
    free(l);

    return l;
}

int lista_tamanho(lista_t *l)
{
    return l->tamanho;
}

int lista_vazia(lista_t *l)
{
    return (lista_tamanho(l) == 0);
}

int lista_insere_inicio(lista_t *l, char *name, int year)
{
    nodo_l_t *novo;

    if (!(novo = (nodo_l_t *)malloc(sizeof(nodo_l_t))))
        return 0;

    strcpy(novo->name, name);
    novo->year = year;
    novo->number = 1;
    novo->prox = l->ini->prox;
    l->ini->prox = novo;
    (l->tamanho)++;

    return 1;
}

int lista_insere_ordenado (lista_t* l, char *name, int year)
{
    /* Confere se o elemento ja esta na lista */
    if (lista_pertence(l, name) == 1)
        return 1;

    nodo_l_t *novo, *ptr, *prev;

    /* se a lista for vazia insere no inicio */
    if (lista_vazia (l))
    {
        lista_insere_inicio (l, name, year);
        return 1;
    }

    if (! (novo = (nodo_l_t *) malloc (sizeof (nodo_l_t))))
        return 0;

    novo->year = year;
    strcpy(novo->name, name);
    novo->number = 1;

    /* acha o lugar para inserir elemento */
    prev= l->ini;
    ptr= l->ini->prox;
    while ((ptr->prox != NULL) && (ptr->year <= year))
    {
        ptr= ptr->prox;
        prev= prev->prox;
    }

    /* tem que inserir entre prev e ptr */
    novo->prox= ptr;
    prev->prox= novo;
    (l->tamanho)++;

    return 1;
}

/*
 * Retorna 1 se o elemento existe na lista e 0 caso contrario.
 */
int lista_pertence(lista_t *l, char *name)
{
    nodo_l_t *ptr;

    if (lista_vazia(l))
        return 0;

    /* localiza elemento */
    ptr = l->ini->prox;
    while ((ptr->prox != NULL) && (strcmp(ptr->name, name) != 0))
        ptr = ptr->prox;

    if (ptr->prox != NULL)
    {
        ptr->number = ptr->number + 1;
        l->tamanho++;
        return 1;
    }

    return 0;
}

int data_by_year(lista_t *l, int year)
{
    int n = 0;
    nodo_l_t *ptr;
    if (lista_vazia(l))
        return 0;

    ptr = l->ini->prox;
    while ((ptr->prox != NULL))
    {
        if (ptr->year == year)
        {
            n++;
        }
        if ((n != 0) && (ptr->year != year))
            return n;
        ptr = ptr->prox;
    }

}
char *return_quali(int i)
{
    if (i == 0)
        return "A1";
    else if (i == 1)
        return "A2";
    else if (i == 2)
        return "A3";
    else if (i == 3)
        return "A4";
    else if (i == 4)
        return "B1";
    else if (i == 5)
        return "B2";
    else if (i == 6)
        return "B3";
    else if (i == 7)
        return "B4";
    else if (i == 8)
        return "C";
    else
        return "NC";
}
void lista_imprime(lista_t *l, int i)
{
    nodo_l_t *ptr;

    if (lista_vazia(l))
        return;
    
    printf("Estrato %s: \n", return_quali(i));
    ptr = l->ini->prox;
    while (ptr->prox->prox != NULL)
    {
        printf("%s: %d :%d \n", ptr->name, ptr->year, ptr->number);
        ptr = ptr->prox;
    }
    printf("%s: %d :%d \n\n", ptr->name, ptr->year, ptr->number);
}