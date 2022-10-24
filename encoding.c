#include "encoding.h"

/*
Funcao que tranforma uma string iso8859-1 em utf8.
Encontrada em: https://tzaeru.com/bit-ops-and-character-encodings
*/
char *ISO8859ToUTF8(unsigned char *word)
{
  char *utf8 = (char *)malloc(1 + (2 * strlen((char*)word)));

  int len = 0;

  char *c = utf8;
  for (; *word; ++word)
  {
    if (!(*word & 0x80))
    {
      *c++ = *word;
      len++;
    }
    else
    {
      *c++ = (char)(0xc2 | ((unsigned char)(*word) >> 6));

      *c++ = (char)(0xbf & *word);
      len += 2;
    }
  }
  *c++ = '\0';

  return utf8;
}

/*
Funcao que le todo o arquivo xml e o aloca seu conteudo em uma string
*/
char *read_file(FILE *file)
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
  char *string = malloc(sizeof(char) * (length + 1));

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