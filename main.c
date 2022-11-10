#include <stdio.h>
#include "utils.h"

int main()
{
    FILE* cur_file;
    //char* dirname = "curriculos";
    unsigned char* file_contents;
    cur_file = fopen("curriculos/menotti.xml", "r");
    file_contents = read_file(cur_file);
    process_periodicos((char*)file_contents, "periodicos.txt");
    process_conferencias((char*)file_contents, "conferencias.txt");
    
    free(file_contents);
    
    return 0;
}