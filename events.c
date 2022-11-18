#include "events.h"
#include "utils.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

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
    /* Faz um sumario da lista, sabermos se ha um estrato vazio, assim nao o imprimimos*/
    summary(l, vetor);
    j = 0;
    /* Percorro cada um dos estratos*/
    while (j < 9)
    {
        /* Se o estrato nao estiver vazio*/
        if (vetor[j] != 0)
        {
            printf("Estrato: %s \n", return_quali(j));
            /* Percorro a lista procurando por artigos correspondentes*/
            for (i = 0; i < l->size - 1; i++)
            {
                if ((l->nodes[i].quali == j) && (l->nodes[i].flag == '0'))
                {
                    /* Procuro se ha outro evento de mesmo nome, para fazer sua contagem de participacao*/
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

void print_years(lista_t *per, lista_t *conf)
{
    int anos[50];
    int len, i, j, achei;
    len = 0;
    int vetor[10];
    int vetor2[10];
    /* Adiciono todos os anos distintos presentes nas listas (per, conf)*/
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
    /* Organizo o vetor com os anos*/
    qsort(anos, len, sizeof(int), compare);

    /* Percorro por cada elemento do vetor (ano), e encontro artigos correspondentes*/
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
                vetor2[per->nodes[j].quali]++;
        }
        for (j = 0; j < conf->size; j++)
        {
            if (conf->nodes[j].year == anos[i])
                vetor[conf->nodes[j].quali]++;
        }
        printf("Ano: %d \n", anos[i]);
        printf("+-------------------------+\n");
        printf("|Conferencias  Periodiocos|\n");
        printf("+-------------------------+\n");
        printf("|   A1: %d   |   A1: %d     |\n", vetor[0], vetor2[0]);
        printf("|   A2: %d   |   A2: %d     |\n", vetor[1], vetor2[1]);
        printf("|   A3: %d   |   A3: %d     |\n", vetor[2], vetor2[2]);
        printf("|   A4: %d   |   A4: %d     |\n", vetor[3], vetor2[3]);
        printf("|   B1: %d   |   B1: %d     |\n", vetor[4], vetor2[4]);
        printf("|   B2: %d   |   B2: %d     |\n", vetor[5], vetor2[5]);
        printf("|   B3: %d   |   B3: %d     |\n", vetor[6], vetor2[6]);
        printf("|   B4: %d   |   B4: %d     |\n", vetor[7], vetor2[7]);
        printf("|    C: %d   |    C: %d     |\n", vetor[8], vetor2[8]);
        printf("+------------------------+\n");
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
    /* Percorre por todos os nomes no vetor lattesnames */
    for (x = 0; x < n; x++)
    {
        printf("Pesquisador: %s \n", lattesnames[x]);
        /* Percorre ambas as listas (per, conf) procurando por cada estrato */
        for (j = 0; j < 9; j++)
        {
            for (i = 0; i < per->size; i++)
            {
                if ((per->nodes[i].author == x) && (per->nodes[i].quali == j))
                    vetor2[j]++;
            }

            for (i = 0; i < conf->size; i++)
            {
                if ((conf->nodes[i].author == x) && (conf->nodes[i].quali == j))
                    vetor[j]++;
            }
        }
        printf("+-------------------------+\n");
        printf("|Conferencias  Periodiocos|\n");
        printf("+-------------------------+\n");
        printf("|   A1: %d   |   A1: %d   |\n", vetor[0], vetor2[0]);
        printf("|   A2: %d   |   A1: %d   |\n", vetor[1], vetor2[1]);
        printf("|   A3: %d   |   A1: %d   |\n", vetor[2], vetor2[2]);
        printf("|   A4: %d   |   A1: %d   |\n", vetor[3], vetor2[3]);
        printf("|   B1: %d   |   A1: %d   |\n", vetor[4], vetor2[4]);
        printf("|   B2: %d   |   A1: %d   |\n", vetor[5], vetor2[5]);
        printf("|   B3: %d   |   A1: %d   |\n", vetor[6], vetor2[6]);
        printf("|   B4: %d   |   A1: %d   |\n", vetor[7], vetor2[7]);
        printf("|    C: %d   |   A1: %d   |\n", vetor[8], vetor2[8]);
        printf("+------------------------+\n");
        printf("\n\n");

        /* Zera os vetores auxiliares */
        for (i = 0; i < 9; i++)
        {
            vetor[i] = 0;
            vetor2[i] = 0;
        }
    }
}

void print_estrato(lista_t *l, int e)
{
    int vetor[10], i, n, count;
    for (i = 0; i < 10; i++)
        vetor[i] = 0;
    summary(l, vetor);
    if (vetor[e] != 0)
    {
        printf("Estrato: %s \n", return_quali(e));
        /* Percorro a lista procurando por artigos correspondentes*/
        for (i = 0; i < l->size - 1; i++)
        {
            if ((l->nodes[i].quali == e) && (l->nodes[i].flag == '0'))
            {
                /* Procuro se ha outro evento de mesmo nome, para fazer sua contagem de participacao*/
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
    return;
}