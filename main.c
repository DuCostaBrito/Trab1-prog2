/* 
Resumo do programa: 
    Passo 1) Colhetar nome dos arquivos xml.
    Passo 2) Loop entre os arquivos (foram armazenados em uma string).
    Passo 3) Nesse loop colhetamos algumas informacoes dos artigos e as inserimos em 2 listas (periodicos e conferencias).
    Passo 4) Iteramos pelas listas e comparamos cada nome individualmente com o arquivo de qualificacoes.
    Passo 5) Agora temos todas as informacoes uteis e podemos apenas printar o que for pedido.
*/
#include <unistd.h>
#include "utils.h"
#include "printFunctions.h"
#define MAX_DIST_PERIODICS 2
#define MAX_DIST_EVENTS 9


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

    /* Verificando se todos os parametros foram preenchidos*/
    if (!cvalue || !dvalue || !pvalue)
    {
        printf("Por favor digite no formato: \"./lattes -d <nome do diretorio> -c <quali-conf> -p <quali-per>\"\n");
        exit(1);
    }

    /* Listas em que serao armazenados os artigos*/
    lista_t *Periodicos = lista_cria();
    lista_t *Conferencias = lista_cria();

    /* Listando todos os nomes no diretorio "diretorio/xxxxxxx.xml" */
    filenames = list_filename(dvalue, &num_files);

    /* Alocando memoria para vetor que contera o nome de cada pesquisador */
    authornames = malloc(sizeof(char *) * (num_files));
    for (i = 0; i < num_files; i++)
        authornames[i] = malloc(sizeof(char) * LINESIZE);


    printf("Deixando todos os dados a sua disposicao...\n");
    /* Inserindo nas listas os eventos listados em todos os lattes */
    get_all_events(filenames, authornames, num_files, Periodicos, Conferencias);
    
    printf("Colhetando todas as classificacoes de Conferencias...\n");
    update_bar(0);
    get_qualifications(cvalue, Conferencias, MAX_DIST_EVENTS);
    printf("\nColhetando todas as classificacoes de Periodicos...\n");
    get_qualifications(pvalue, Periodicos, MAX_DIST_PERIODICS);

    display_menu();
    scanf(" %d", &option);
    while (1)
    {
        if (option == 0)
            break;
        else if (option == 1)
        {
            printf("\n");
            print_lista(Periodicos);
        }
        else if (option == 2)
        {
            printf("\n");   
            print_lista(Conferencias); 
        }
        else if (option == 3)
        {
            printf("\n");  
            print_authors(Periodicos, Conferencias, authornames, num_files);
        }

        else if (option == 4)
        {
            printf("\n");  
            print_years(Periodicos, Conferencias);
        }
        else if (option == 5)
        {
            printf("\n");  
            printf("Periodicos: \n");
            print_estrato(Periodicos, 8);
            printf("Conferencias: \n");
            print_estrato(Conferencias, 8);
        }
        else if (option == 6)
        {
            printf("\n");  
            printf("Periodicos: \n");
            print_estrato(Periodicos, 9);
            printf("Conferencias: \n");
            print_estrato(Conferencias, 9);
        }
        else if (option == 7)
        {
            plotGraph(Periodicos, Conferencias);
        }
        display_menu();
        scanf(" %d", &option);
    }

    free(Periodicos->nodes);
    free(Conferencias->nodes);
    free(Periodicos);
    free(Conferencias);

    free_list_filenames(authornames, num_files);
    return 0;
}