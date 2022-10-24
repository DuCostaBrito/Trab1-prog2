#include <stdio.h>
#include "encoding.h"
#include "utils.h"

int main()
{
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
    free(filenames[1]);
    free(filenames);
    return 0;
}