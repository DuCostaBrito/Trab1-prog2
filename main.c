#include <stdio.h>
#include "utils.h"

int main()
{
    FILE* cur_file;
    //char* dirname = "curriculos";
    unsigned char* file_contents;
    cur_file = fopen("curriculos/kohayakawa.xml", "r");
    file_contents = read_file(cur_file);
    process_wrapper((char*)file_contents, "periodicos.txt", "conferencias.txt");
    free(file_contents);
    
    return 0;
}