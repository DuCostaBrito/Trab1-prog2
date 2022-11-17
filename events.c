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

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void print_years(lista_t *per, lista_t *conf)
{
    int anos[50];
    int len, i, j, achei;
    len = 0;
    int vetor[10];
    int vetor2[10];
    for (i = 0; i < per->size; i++)
    {
        achei = 0;
        for (j = 0; j < len; j++)
        {
            if (per->nodes[i].year == anos[j])
            {
                achei = 1;
                break;
            }
        }
        if ((achei == 0) && (per->nodes[i].quali < 9))
        {
            anos[len] = per->nodes[i].year;
            len++;
        }
    }
    for (i = 0; i < conf->size; i++)
    {
        achei = 0;
        for (j = 0; j < len; j++)
        {
            if (conf->nodes[i].year == anos[j])
            {
                achei = 1;
                break;
            }
        }
        if ((achei == 0) && (conf->nodes[i].quali < 9))
        {
            anos[len] = conf->nodes[i].year;
            len++;
        }
    }
    insertionSort(anos, len);

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 10; j++)
        {
            vetor[j] = 0;
            vetor2[j] = 0;
        }
        for (j = 0; j < per->size; j++)
        {
            if (per->nodes[j].year == anos[i])
                vetor[per->nodes[j].quali]++;
        }
        for (j = 0; j < conf->size; j++)
        {
            if (conf->nodes[j].year == anos[i])
                vetor2[conf->nodes[j].quali]++;
        }
        printf("Ano: %d \n", anos[i]);
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