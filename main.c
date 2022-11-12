#include "utils.h"
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    FILE* cur_file;
    char **filenames;
    char *cvalue = NULL;
    char *dvalue = NULL;
    char *pvalue = NULL;
    unsigned char* file_contents;
    int num_files;
    int c;
    
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
    
    
    filenames = list_filename(dvalue, &num_files);
    cur_file = fopen(filenames[0], "r");
    file_contents = read_file(cur_file);
    for(c = 0; c < num_files; c++)
        printf("%s \n", filenames[c]);
    printf("%s", file_contents);
    //get_lattes_data((char*)file_contents, "periodicos.txt", "conferencias.txt");
    free(file_contents);
    free_list_filenames(filenames, num_files);
    return 0;
}