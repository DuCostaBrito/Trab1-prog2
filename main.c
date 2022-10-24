#include <stdio.h>
#include "encoding.c"
#include "utils.c"

int main()
{
    FILE *cur_file;
    char *dirname = "curriculos";
    char **filenames;
    filenames = list_filename(dirname);

    for (int i = 0; i < N_ARCHS; i++)
    {
        printf("%s \n", filenames[i]);
    }

    /*char *file_contents = read_file(cur_file);
    printf("%s", ISO8859ToUTF8(file_contents));*/
    free(filenames[0]);
    free(filenames);
    return 0;
}