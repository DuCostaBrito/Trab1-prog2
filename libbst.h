#ifndef _LIBBST_H_
#define _LIBBST_H_

// Declarando estrutura do nodo
struct tNo
{
    int ano; // Valor de busca
    // A1, A2, A3, A4, B1, B2, B3, B4, C, NC
    int periodicos[10];
    int conferencias[10];
    struct tNo *esq, *dir; // Filhos esquerda e direita
};
typedef struct tNo tNo_t;

// Cria Nodo
tNo_t *criaNodo(int chave);

// Retorna o nodo desejado
tNo_t *busca(tNo_t *raiz, int ano);

// Funcao de insercao
tNo_t *insercao(tNo_t *raiz, int chave);

// Funcao para destruir a arvore
void destroiBST(tNo_t *raiz);

#endif