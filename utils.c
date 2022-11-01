#include "utils.h"

/*
Retorna uma lista de strings
Cada string eh o caminho a um determinado curriculo
*/
char **list_filename(char *dirname)
{
    // Vetor em que serao armazenados as strings
    char **filenames;
    filenames = malloc(sizeof(char *) * (N_ARCHS));

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
    while ((entry = readdir(cur_dir)))
    {
        // Ignorando as entradas dos diretórios . e ..
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
        {
            filenames[i] = malloc(sizeof(char) * LINESIZE);
            strcpy(filenames[i], dirname);
            strcat(filenames[i], "/");
            strcat(filenames[i], entry->d_name);
            i++;
        }
    }
    closedir(cur_dir);
    return filenames;
}

void free_list_filenames(char **list, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(list[i]);
    }
    free(list);
}

/*
Funcao que le todo o arquivo xml e o aloca seu conteudo em uma string
*/
unsigned char *read_file(FILE *file)
{
  // Se a leitura falha, retorna NULL
  if (file == NULL)
    return NULL;

  // Move o ponteiro para o final do texto
  fseek(file, 0, SEEK_END);

  // ftell() devolve a posicao atual do ponteiro que esta no fim do texto
  int length = ftell(file);

  // Move o ponteiro de volta para o inicio
  fseek(file, 0, SEEK_SET);

  // Aloca dinamicamente o espaco no qual sera salvo todo o conteudo do texto
  unsigned char *string = malloc(sizeof(char) * (length + 1));

  char c;
  int i = 0;

  // Continua lendo caractere por caractere ate o fim
  while ((c = fgetc(file)) != EOF)
  {
    string[i] = c;
    i++;
  }

  // Coloca o caractere nulo no fim da string
  string[i] = '\0';

  fclose(file);

  return string;
}