#include "events.h"
#include "utils.h"

lista_t *lista_cria()
{
    lista_t *l;
    /* aloca espaco para a cabeca da lista_t */
    if (!(l = (lista_t *)malloc(sizeof(lista_t))))
        return NULL;

    l->size = 0;
    return l;
}

/* Insere o nodo na lista, mas antes procura por um nome similar */
void insert(lista_t *l, char *name, int year, int i)
{
    strcpy(l->nodes[l->size].name, name);
    l->nodes[l->size].year = year;
    l->nodes[l->size].author = i;
    l->nodes[l->size].flag = '0';
    l->size = l->size + 1;
    return;
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
        return " C";
    else
        return "NC";
}

void summary(lista_t *l, int vetor[])
{
    int i;
    for (i = 0; i < l->size; i++)
    {
        vetor[l->nodes[i].quali]++;
    }
    return;
}

void print_lista(lista_t *l)
{
    int i, j, n;
    int count;
    int vetor[10];
    for (i = 0; i < 10; i++)
        vetor[i] = 0;
    summary(l, vetor);
    j = 0;
    while (j < 9)
    {
        if (vetor[j] != 0)
        {
            printf("Estrato: %s \n", return_quali(j));
            for (i = 0; i < l->size - 1; i++)
            {
                if ((l->nodes[i].quali == j) && (l->nodes[i].flag == '0'))
                {
                    count = 1;
                    for (n = i + 1; n < l->size; n++)
                    {
                        if (strcmp(l->nodes[i].name, l->nodes[n].name) == 0)
                        {
                            l->nodes[n].flag = '1';
                            count++;
                        }
                    }
                    printf("%s : %d \n", l->nodes[i].name, count);
                }
            }
            printf("\n");
        }
        j++;
    }
    return;
}