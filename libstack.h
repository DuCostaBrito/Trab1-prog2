/* Estrutura stack para armazenar os pesquisadores e suas informacoes*/

#ifndef _LIBSTACK_H_
#define _LIBSTACK_H_
#include <stdio.h>
#include <stdlib.h>

struct author
{
    char *name;
    // A1, A2, A3, A4, B1, B2, B3, B4, C
    int periodicos[9];
    int conferencias[9];
};
typedef struct author author_t;

struct stack
{
    author_t* array;
    int max_size;
    int top;
};
typedef struct stack stack_t;

stack_t* stack_cria (int max_size);

int push (stack_t* stack, author_t author);

stack_t* stack_destroi (stack_t* stack);

int stack_vazia (stack_t* stack);

void stack_imprime(stack_t* stack);


#endif