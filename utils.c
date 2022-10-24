#include "utils.h"

/*
Retorna uma lista de strings
Cada string eh o caminho a um determinado curriculo
*/
char** list_filename(char *dirname)
{
    // Vetor em que serao armazenados as strings
    char** filenames;
    filenames = malloc(sizeof(char*)*(N_ARCHS - 1));

    DIR *cur_dir;
    struct dirent *entry;
    cur_dir = opendir(dirname);
    if (!cur_dir)
    {
        perror("ERRO ao abrir o diretório");
        exit(1);
    }
    // I vai contar quantas vezes passamos pelo loop abaixo
    int i = 0;

    // Loop sobre todos os arquivos de um diretorio
    while (entry = readdir(cur_dir))
    {
        // Ignorando as entradas dos diretórios . e ..
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
        {
            filenames[i] = malloc(sizeof(char)*LINESIZE);
            strcpy(filenames[i], dirname);
			strcat(filenames[i], "/");
			strcat(filenames[i], entry->d_name);
            i++;
        }
    }
    closedir(cur_dir);
    return filenames;
}