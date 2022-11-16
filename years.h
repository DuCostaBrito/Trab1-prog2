/* Estrtura BST para armazenar os dados de cada ano */
#ifndef _LIBBST_H_
#define _LIBBST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tNo {
    int year;
    int periodicos[9];
    int conferencias[9];
};
typedef struct tNo tNo_l;

struct anos {
    tNo_l *ano;      /* Nodos que serao alocados */
    int size;        /* Index que paramos  de inserir, e tambem o numero total de artigos */
};
typedef struct anos anos_l;

anos_l *lista_anos();
void insert_year(anos_l *anos, int year, int index, char *lable);
void print_by_year(anos_l *anos);

#endif