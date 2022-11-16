#include "years.h"


anos_l *lista_anos()
{
    anos_l *l;
    /* aloca espaco para a cabeca da lista_t */
    if (!(l = (anos_l *)malloc(sizeof(anos_l))))
        return NULL;
    
    l->size = 0;
    return l;
}

void insert_year(anos_l *anos, int year, int index, char *lable)
{
    int i;
    for (i = 0; i < anos->size; i++)
    {
        if (anos->ano[i].year == year)
        {
            if (strcmp(lable, "PERIODICOS") == 0)
                anos->ano[i].periodicos[index] = anos->ano[i].periodicos[index] + 1;
            else
                anos->ano[i].conferencias[index] = anos->ano[i].conferencias[index] + 1;
            return;
        }
    }
    anos->ano[anos->size].year = year;
    for (i = 0; i < 9; i++)
    {
        anos->ano[anos->size].periodicos[i] = 0;
        anos->ano[anos->size].conferencias[i] = 0;
    }
    if (strcmp(lable, "PERIODICOS") == 0)
        anos->ano[anos->size].periodicos[index] = 1;
    else
        anos->ano[anos->size].conferencias[index] = 1;
    anos->size = anos->size + 1;
    return;
}

void insertionSort(anos_l *anos)
{
    int i, j;
    tNo_l aux;
    for (i = 1; i < anos->size; i++)
    {
        aux = anos->ano[i];
        for (j = i; (j > 0) && (aux.year < anos->ano[j - 1].year); j--)
            anos->ano[j] = anos->ano[j - 1];
        anos->ano[j] = aux;
    }
}

void print_by_year(anos_l *anos)
{
    int i;
    insertionSort(anos);
    for (i = 0; i < anos->size; i++)
    {
        printf("\n");
        printf("Ano: %d \n", anos->ano[i].year);
        printf("+--------------------------------+ \n");
        printf("|    Periodiocos  Conferencias   | \n");
        printf("+--------------------------------+ \n");
        printf("| A1:     %d           %d          |\n", anos->ano[i].periodicos[0], anos->ano[i].conferencias[0]);
        printf("| A2:     %d           %d          |\n", anos->ano[i].periodicos[1], anos->ano[i].conferencias[1]);
        printf("| A3:     %d           %d          |\n", anos->ano[i].periodicos[2], anos->ano[i].conferencias[2]);
        printf("| A4:     %d           %d          |\n", anos->ano[i].periodicos[3], anos->ano[i].conferencias[3]);
        printf("| B1:     %d           %d          |\n", anos->ano[i].periodicos[4], anos->ano[i].conferencias[4]);
        printf("| B2:     %d           %d          |\n", anos->ano[i].periodicos[5], anos->ano[i].conferencias[5]);
        printf("| B3:     %d           %d          |\n", anos->ano[i].periodicos[6], anos->ano[i].conferencias[6]);
        printf("| B4:     %d           %d          |\n", anos->ano[i].periodicos[7], anos->ano[i].conferencias[7]);
        printf("|  C:     %d           %d          |\n", anos->ano[i].periodicos[8], anos->ano[i].conferencias[8]);
        printf("+--------------------------------+\n");
        printf("\n");
    }
}