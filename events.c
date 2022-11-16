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

void insertionSort(lista_t *l)
{
    int i, j;
    nodo_l_t tmp;
    for (i = 1; i < l->size; i++)
    {
        tmp = l->nodes[i];
        j = i - 1;
        while ((j >= 0) && (l->nodes[j].year > tmp.year))
        {
            l->nodes[j + 1] = l->nodes[j];
            j--;
        }
        l->nodes[j + 1] = tmp;
    }
}

void print_years(lista_t *per, lista_t *conf)
{
    int i, j, min, n;
    i = 0;
    j = 0;
    int vetor[10];
    int vetor2[10];
    insertionSort(per);
    insertionSort(conf);
    for (i = 0; i < 10; i++)
    {
        vetor[i] = 0;
        vetor2[i] = 0;
    }
    while ((i < per->size) || (j < conf->size))
    {
        min = MIN3(per->nodes[i].year, conf->nodes[j].year, 2025);
        printf("Ano: %d\n", min);
        while ((i < per->size) && (per->nodes[i].year == min))
        {
            vetor[per->nodes[i].quali]++;
            i++;
        }
        while ((j < conf->size) && (conf->nodes[j].year == min))
        {
            vetor2[conf->nodes[j].quali]++;
            j++;
        }

        printf("A1:    %d     %d \n", vetor[0], vetor2[0]);
        printf("A2:    %d     %d \n", vetor[1], vetor2[1]);
        printf("A3:    %d     %d \n", vetor[2], vetor2[2]);
        printf("A4:    %d     %d \n", vetor[3], vetor2[3]);
        printf("B1:    %d     %d \n", vetor[4], vetor2[4]);
        printf("B2:    %d     %d \n", vetor[5], vetor2[5]);
        printf("B3:    %d     %d \n", vetor[6], vetor2[6]);
        printf("B4:    %d     %d \n", vetor[7], vetor2[7]);
        printf(" C:    %d     %d \n", vetor[8], vetor2[8]);
        printf("\n");

        for (n = 0; n < 10; n++)
        {
            vetor[n] = 0;
            vetor2[n] = 0;
        }
    }
}

void print_authors(lista_t *per, lista_t *conf, char **lattesnames, int n)
{
    int i, j, x;
    int vetor[9], vetor2[9];
    for (i = 0; i < 9; i++)
    {
        vetor[i] = 0;
        vetor2[i] = 0;
    }
    for (x = 0; x < n; x++)
    {
        printf("Pesquisador: %s \n", lattesnames[x]);
        for (j = 0; j < 9; j++)
        {
            for (i = 0; i < per->size; i++)
            {
                if ((per->nodes[i].author == x) && (per->nodes[i].quali == j))
                    vetor[j]++;
            }

            for (i = 0; i < conf->size; i++)
            {
                if ((conf->nodes[i].author == x) && (conf->nodes[i].quali == j))
                    vetor2[j]++;
            }
        }
        printf("A1:    %d     %d \n", vetor[0], vetor2[0]);
        printf("A2:    %d     %d \n", vetor[1], vetor2[1]);
        printf("A3:    %d     %d \n", vetor[2], vetor2[2]);
        printf("A4:    %d     %d \n", vetor[3], vetor2[3]);
        printf("B1:    %d     %d \n", vetor[4], vetor2[4]);
        printf("B2:    %d     %d \n", vetor[5], vetor2[5]);
        printf("B3:    %d     %d \n", vetor[6], vetor2[6]);
        printf("B4:    %d     %d \n", vetor[7], vetor2[7]);
        printf(" C:    %d     %d \n", vetor[8], vetor2[8]);
        printf("\n\n");
        for (i = 0; i < 9; i++)
        {
            vetor[i] = 0;
            vetor2[i] = 0;
        }
    }
}