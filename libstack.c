#include "libstack.h"

author_t *author_cria(char *name)
{
    int i;
    author_t *a = (author_t *)malloc(sizeof(author_t));
    if (!(a))
        return NULL; // Confere erro de alocacao
    a->name = name;
    /* Inicia os vetores como nulo */
    for (i = 0; i < 9; i++)
    {
        a->periodicos[i] = 0;
        a->conferencias[i] = 0;
    }
    return a;
}

/*
 * Cria e retorna uma nova stack com capacidade de max_size elementos.
 * Retorna NULL em caso de erro de alocação
 */
stack_t *stack_cria(int max_size)
{
    stack_t *s = malloc(sizeof(stack_t));
    s->array = (author_t *)malloc(sizeof(author_t) * max_size);

    /* confere erro de alocacao */
    if (!(s) || !(s->array))
        return NULL;

    s->top = -1;
    s->max_size = max_size;
    return s;
}

/*
 * Insere elemento na stack (politica LIFO). Retorna o número de elementos na stack
 * em caso de sucesso e -1 em caso de stack cheia
 */
int push(stack_t *stack, author_t author)
{
    /* Caso a stack esteja cheia */
    if (stack->top == stack->max_size - 1)
        return -1;

    stack->top++;
    stack->array[stack->top] = author;
    return ((stack->top) + 1);
}

/* Retorna 1 se stack vazia, 0 em caso contrario */
int stack_vazia(stack_t *stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

/* Desaloca memoria de stack_t e retorna NULL */
stack_t *stack_destroi(stack_t *stack)
{
    free(stack->array);
    free(stack);
    return NULL;
}

/* Imprime a stack no formato requerido*/
void stack_imprime(stack_t *stack)
{
    if (stack_vazia(stack) == 1)
        return;
    int i = 0;

    while (i <= stack->top)
    {
        printf("Pesquisador: %s \n", stack->array[i].name);
        printf("     PER     CONF \n");
        printf("A1   %d     %d \n", stack->array[i].periodicos[0], stack->array[i].conferencias[0]);
        printf("A2   %d     %d \n", stack->array[i].periodicos[1], stack->array[i].conferencias[1]);
        printf("A3   %d     %d \n", stack->array[i].periodicos[2], stack->array[i].conferencias[2]);
        printf("A4   %d     %d \n", stack->array[i].periodicos[3], stack->array[i].conferencias[3]);
        printf("B1   %d     %d \n", stack->array[i].periodicos[4], stack->array[i].conferencias[4]);
        printf("B2   %d     %d \n", stack->array[i].periodicos[5], stack->array[i].conferencias[5]);
        printf("B3   %d     %d \n", stack->array[i].periodicos[6], stack->array[i].conferencias[6]);
        printf("B4   %d     %d \n", stack->array[i].periodicos[7], stack->array[i].conferencias[7]);
        printf("C    %d     %d \n", stack->array[i].periodicos[8], stack->array[i].conferencias[8]);
        i++;
    }
}