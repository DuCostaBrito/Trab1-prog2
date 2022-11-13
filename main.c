#include "utils.h"
#include "liblist.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char **filenames;
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
    /* Listas em que serao armazenados os artigos A1, A2, A3, A4, B1, B2, B3, B4, C, NC*/
    lista_t *Periodicos[10];
    lista_t *Conferencias[10];
    for (i = 0; i < 10; i++)
    {
        Periodicos[i] = lista_cria();
        Conferencias[i] = lista_cria();
    }

    /* Listando todos os nomes no diretorio "diretorio/xxxxxxx.xml" */
    filenames = list_filename(dvalue, &num_files);
    /* Vetores em que serao armazenados os numero de artigos de cada autor dividido por estrato*/
    int vetor_per[num_files * 10];
    int vetor_conf[num_files * 10];
    for (i = 0; i < (num_files * 10); i++)
    {
        vetor_conf[i] = 0;
        vetor_per[i] = 0;
    }

    printf("Deixando todos os dados a sua disposicao...\n");
    /* Realizando todo o processo de antemao*/
    process_wrapper(filenames, num_files, pvalue, cvalue, Periodicos, Conferencias, vetor_per, vetor_conf);

    display_menu();
    scanf(" %d", &option);
    while (1)
    {
        if (option == 0)
            break;
        else if (option == 1)
        {
            for (i = 0; i < 10; i++)
                lista_imprime(Periodicos[i], i);
        }
        else if (option == 2)
        {
            for (i = 0; i < 10; i++)
                lista_imprime(Conferencias[i], i);
        }
        else if (option == 3)
        {
            /* FAZER */
        }
            
        else if (option == 4)
        {
            /* FAZER */
        }
        display_menu();
        scanf(" %d", &option);
    }

    for (i = 0; i < 10; i++)
    {
        lista_destroi(Periodicos[i]);
        lista_destroi(Conferencias[i]);
    }
    return 0;
}