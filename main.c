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
    free_list(filenames, N_ARCHS);
    return 0;
}