#include <stdlib.h>
#include <stdio.h>
#include "liblista.h"

/*
 * Cria uma lista vazia e a retorna, se falhar retorna NULL.
*/
lista_t* lista_cria (){
    lista_t* l = malloc(sizeof(lista_t));
    if ( l ){
        l->ini = NULL;
        l->tamanho = 0;
        return l;
    }
    return NULL;
}

/*
 * Cria um nodo e o retorna, se falhar retorna NULL.
*/
nodo_l_t* cria_nodo(int valor){
    nodo_l_t* novo = malloc(sizeof(nodo_l_t));
    if ( novo ){
        int i;
        novo->ano = valor;
        /* Inicializando os vetores como nulo */
        for(i = 0; i < N_estratos; i++){
            novo->periodicos[i] = 0;
            novo->conferencias[i] = 0;
        }
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

/*
 * Remove todos os elementos da lista, libera espaco e retorna NULL.
*/
lista_t* lista_destroi (lista_t* l){
    int* aux = (int*)malloc(sizeof(int));
    while(l->ini != NULL) {
        lista_retira_inicio(l, aux);
    }
    free(aux);
    free(l->ini);
    free(l);
    return NULL;
}

/*
 * Retorna 1 se a lista esta vazia e 0 caso contrario.
*/
int lista_vazia (lista_t* l){
    if (!(l)) return 0;
    if (l->ini == NULL) return 1;
    return 0;
}

/*
 * Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela.
*/
int lista_tamanho (lista_t* l){
    return l->tamanho;
}

/*
 * Insere o elemento no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_insere_inicio (lista_t* l, int elemento){
    nodo_l_t* novo = cria_nodo(elemento);
    if ( novo ){
        novo->prox = l->ini;
        l->ini = novo;
        l->tamanho++;
        return 1;
    }
    return 0;
}

/*
 * Insere o elemento na lista garantindo ordenacao em ordem crescente.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_insere_ordenado (lista_t* l, int elemento){
    if (lista_vazia(l) == 1) return lista_insere_inicio(l, elemento);
    
    nodo_l_t* novo = cria_nodo(elemento);
    if ( novo ){
        /* ponteiros auxiliares */
        nodo_l_t* inicio = l->ini;
        nodo_l_t* proximo = inicio->prox;

        l->tamanho++;

        /* percorre a lista inteira */
        /* REVER */
        while(proximo != NULL) {
            if (novo->ano >= inicio->ano && novo->ano <= proximo->ano){
                inicio->prox = novo;
                novo->prox = proximo;
                return 1;
            }
            inicio = proximo;
            proximo = proximo->prox;
        }
        /* Se percorremos a lista inteira e nao achamos nada que satisfaca as condicoes
        inserimos o elemento no final da lista */
        novo->prox = inicio->prox;
        inicio->prox = novo; 
        return 1;        
    }
    return 0;
}

/*
 * Remove o elemento do inicio da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int lista_retira_inicio (lista_t* l, int* elemento){
    if (lista_vazia(l) == 1) return 0;

    nodo_l_t* inicio = l->ini;
    *elemento = (int)inicio->ano;
    l->ini = l->ini->prox;
    free(inicio);
    l->tamanho = l->tamanho - 1;
    return 1;
}

/*
 * Retorna 1 se o elemento existe na lista e 0 caso contrario.
*/
int lista_pertence (lista_t* l, int elemento){

}

void lista_insere_artigo(lista_t* l, int ano, int estrato, int veiculo){
    if (lista_vazia(l) == 0) return 0;
    nodo_l_t *inicio = l->ini;
    while(inicio != NULL) {
        if (inicio->ano == ano){
            
        }
        nodo_l_t *proximo = inicio->prox;
        inicio = proximo;
    }
    return 0;
}

/*
 * Imprime a lista, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a lista estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD lista.
*/
void lista_imprime (lista_t* l){
    if (!(l)) return;
    if (lista_vazia(l) == 1) return;

    nodo_l_t *inicio = l->ini;
    while(inicio != NULL) {
        printf("%d ", inicio->ano);
        inicio = inicio->prox;
    }
}