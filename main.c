#include <stdio.h>
#include <unistd.h>
#include "utils.h"
#include "years.h"
#include "liblist.h"
#include "libpool.h"

int main(int argc, char **argv)
{
    char **filenames;
    char **authornames;
    char *cvalue = NULL;
    char *dvalue = NULL;
    char *pvalue = NULL;
    int num_files;
    int c;
    int i;
    int option;

    /* lendo os parametros do programa */
    while ((c = getopt(argc, argv, "d:c:p:")) != -1)
    {
        switch (c)
        {
        case 'c':
            cvalue = optarg;
            break;
        case 'd':
            dvalue = optarg;
            break;
        case 'p':
            pvalue = optarg;
            break;
        default:
            break;
        }
    }

    /* Listando todos os nomes no diretorio "diretorio/xxxxxxx.xml" */
    filenames = list_filename(dvalue, &num_files);
    
    /* Inicializando memory pools*/
    pool pool_ptr1;
    pool pool_ptr2;
    pool pool_ptr3;
    poolInitialize(&pool_ptr1, sizeof(nodo_l_t), 1024);
    poolInitialize(&pool_ptr2, sizeof(nodo_l_t), 1024);
    poolInitialize(&pool_ptr3, sizeof(tNo_l), 50);

    /* Listas em que serao armazenados os artigos*/
    lista_t *Periodicos = lista_cria();
    lista_t *Conferencias = lista_cria();
    Periodicos->nodes = poolMalloc(&pool_ptr1);
    Conferencias->nodes = poolMalloc(&pool_ptr2);

    /* Arvore em que serao armazenados os dados de cada ano */
    anos_l *anos = lista_anos();
    anos->ano = poolMalloc(&pool_ptr3);

    /* Alocando memoria para vetor que contera o nome de cada pesquisador */
    authornames = malloc(sizeof(char *) * (num_files));
    for (i = 0; i < num_files; i++)
        authornames[i] = malloc(sizeof(char) * LINESIZE);

    /* Vetores em que serao armazenados os numero de artigos de cada autor dividido por estrato*/
    int vetor_per[num_files * 10];
    int vetor_conf[num_files * 10];
    for (i = 0; i < (num_files * 10); i++)
    {
        vetor_conf[i] = 0;
        vetor_per[i] = 0;
    }

    printf("Deixando todos os dados a sua disposicao...\n");
    process_wrapper(filenames, authornames, num_files, pvalue, cvalue, anos, Periodicos, Conferencias, vetor_per, vetor_conf);

    display_menu();
    scanf(" %d", &option);
    while (1)
    {
        if (option == 0)
            break;
        else if (option == 1)
        {
            for (i = 0; i < 9; i++)
                lista_imprime(Periodicos, i);
        }
        else if (option == 2)
        {
            for (i = 0; i < 9; i++)
                lista_imprime(Conferencias, i);
        }
        else if (option == 3)
        {
            author_summary(vetor_per, vetor_conf, authornames, num_files);
        }

        else if (option == 4)
        {
            print_by_year(anos);
        }
        display_menu();
        scanf(" %d", &option);
    }

    /* Dando Free no que se faz necessario */
    poolFree(&pool_ptr1, Periodicos->nodes);
    poolFree(&pool_ptr2, Conferencias->nodes);

    free(Periodicos);
    free(Conferencias);
    free(anos);
    poolFreePool(&pool_ptr1);
    poolFreePool(&pool_ptr2);
    poolFreePool(&pool_ptr3);
    free_list_filenames(authornames, num_files);
    return 0;
}