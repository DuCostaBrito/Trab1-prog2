#include "printFunctions.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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

/* Retorna a quantidade de artigos contidos em cada estrato*/
void summary(lista_t *l, int vetor[])
{
    int i;
    for (i = 0; i < l->size; i++)
    {
        vetor[l->nodes[i].quali]++;
    }
    return;
}

/* Printa toda a lista separada por estratos*/
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
        printf("|   A2: %d   |   A2: %d   |\n", vetor[1], vetor2[1]);
        printf("|   A3: %d   |   A3: %d   |\n", vetor[2], vetor2[2]);
        printf("|   A4: %d   |   A4: %d   |\n", vetor[3], vetor2[3]);
        printf("|   B1: %d   |   B1: %d   |\n", vetor[4], vetor2[4]);
        printf("|   B2: %d   |   B2: %d   |\n", vetor[5], vetor2[5]);
        printf("|   B3: %d   |   B3: %d   |\n", vetor[6], vetor2[6]);
        printf("|   B4: %d   |   B4: %d   |\n", vetor[7], vetor2[7]);
        printf("|    C: %d   |    C: %d   |\n", vetor[8], vetor2[8]);
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

/* Printa os artigos de um determinado estrato */
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

void plotGraph(lista_t *Periodicos, lista_t *Conferencias)
{
    char *commandsForGnuplot[] =
        {
            "set title \"Artigos publicados em Periodicos e Conferencias do grupo\"font \",13\"",
            "set yrange[0:]",
            "set mytics 2",
            "set style data histogram",
            "set style histogram cluster gap 1",
            "set style fill solid",
            "set boxwidth 0.9",
            "set xtics format \"\"",
            "set grid ytics",
            "unset grid",
            "set border lw 2",
            "set xlabel \"Estratos\"font \",18\"",
            "set ylabel \"Quantidade\"font \",18\"",
            "set xtics font \",15\"",
            "set ytics font \",15\"",
            "set key font \",12\"",
            "plot 'data.tmp' using 2:xtic(1) title \"Periodicos\" linecolor \"red\",  \
    'data.tmp' using 3 title \"Conferencias\" linecolor \"blue\""};

    FILE *dataTmp = fopen("data.tmp", "w");

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    int i;
    int vetor[9];
    int vetor2[9];
    for (i = 0; i < 9; i++)
    {
        vetor[i] = 0;
        vetor2[i] = 0;
    }

    summary(Periodicos, vetor);
    summary(Conferencias, vetor2);

    fprintf(dataTmp, "# %s %s\n", "Periodicos", "Conferencias");
    for (i = 0; i < 9; i++)
        fprintf(dataTmp, "%s %d %d\n", return_quali(i), vetor[i], vetor2[i]);

    for (i = 0; i < 17; i++)
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);

    fclose(dataTmp);
    pclose(gnuplotPipe);
}
