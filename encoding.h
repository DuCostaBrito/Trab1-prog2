#ifndef _encoding_t_H
#define _encoding_t_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ISO8859ToUTF8(unsigned char *str);
unsigned char *read_file(FILE *file);

#endif