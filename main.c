#include <stdio.h>
#include "utils.h"

int main()
{
    FILE* cur_file;
    //char* dirname = "curriculos";
    unsigned char* file_contents;
    cur_file = fopen("curriculos/menotti.xml", "r");
    file_contents = read_file(cur_file);
    process_data((char*)file_contents);
    
    free(file_contents);
    
    return 0;
}