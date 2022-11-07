#include <stdio.h>
#include "libbst.h"
#include "utils.h"
#include "libstack.h"

int main()
{
    FILE* cur_file;
    //char* dirname = "curriculos";
    unsigned char* file_contents;

    cur_file = fopen("curriculos/menotti.xml", "r");
    file_contents = read_file(cur_file);
    get_data((char*)file_contents);
    free(file_contents);
    
    return 0;
}