#include <unistd.h>
#include "utils.h"


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
    

    /* Listas em que serao armazenados os artigos*/
    lista_t *Periodicos = lista_cria();
    lista_t *Conferencias = lista_cria();

    /* Alocando memoria para vetor que contera o nome de cada pesquisador */
    authornames = malloc(sizeof(char *) * (num_files));
    for (i = 0; i < num_files; i++)
        authornames[i] = malloc(sizeof(char) * LINESIZE);


    printf("Deixando todos os dados a sua disposicao...\n");
    /* Inserindo nas listas os eventos listados em todos os lattes */
    get_all_events(filenames, authornames, num_files, Periodicos, Conferencias);
    /* Classificando cada artigo */
    get_qualifications(cvalue, Conferencias);
    get_qualifications(pvalue, Periodicos);

    display_menu();
    scanf(" %d", &option);
    while (1)
    {
        if (option == 0)
            break;
        else if (option == 1)
        {
            print_lista(Periodicos);
        }
        else if (option == 2)
        {
            
            print_lista(Conferencias); 
        }
        else if (option == 3)
        {
            print_authors(Periodicos, Conferencias, authornames, num_files);
        }

        else if (option == 4)
        {
            print_years(Periodicos, Conferencias);
        }
        else if (option == 5)
        {
            printf("Periodicos: \n");
            print_estrato(Periodicos, 8);
            printf("Conferencias: \n");
            print_estrato(Conferencias, 8);
        }
        else if (option == 6)
        {
            printf("Periodicos: \n");
            print_estrato(Periodicos, 9);
            printf("Conferencias: \n");
            print_estrato(Conferencias, 9);
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