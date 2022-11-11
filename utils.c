#include "utils.h"
#include "libbst.h"
#include "liblist.h"

/*
  Edit distance function.
  Retirada de: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
*/
int levenshtein(char *s1, char *s2)
{
  unsigned int s1len, s2len, x, y, lastdiag, olddiag;
  s1len = strlen(s1);
  s2len = strlen(s2);
  unsigned int column[s1len + 1];
  for (y = 1; y <= s1len; y++)
    column[y] = y;
  for (x = 1; x <= s2len; x++)
  {
    column[0] = x;
    for (y = 1, lastdiag = x - 1; y <= s1len; y++)
    {
      olddiag = column[y];
      column[y] = MIN3(column[y] + 1, column[y - 1] + 1, lastdiag + (s1[y - 1] == s2[x - 1] ? 0 : 1));
      lastdiag = olddiag;
    }
  }
  return column[s1len];
}

/*
Retorna uma lista de strings
Cada string eh o caminho a um determinado curriculo
*/
char **list_filename(char *dirname, int *list_size)
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
  // Para nos informar o tamanho da stack criada
  *list_size = i;

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

/* Retorna o conteudo entre as aspas*/
char *get_inside_lable(char *string, char *data)
{
  int i = 0;
  string++;
  while (string[0] != '\"')
  {
    data[i] = string[0];
    string++;
    i++;
  }
  data[i] = '\0';
  return data;
}

/* Retorna o conteudo de uma lable no arquivo xml */
void get_data(char *string, char *lable, char *data, char **pointer)
{
  char *text;
  /* Procurando pela lable */
  text = strstr(string, lable);

  /* Testa se foi achado uma lable restante */
  if (text == NULL)
  {
    *pointer = NULL;
    return;
  }

  /* Movendo o ponteiro ate as aspas */
  text = strstr(text, "\"");
  /* Pegando o conteudo entre aspas */
  get_inside_lable(text, data);
  /* Mantendo track do endereco em que parei a leitura */
  *pointer = text;
  return; // Lembrar de dar free
}

void process_event(char *string, char *lable[])
{
  printf("++++++++++%s+++++++++++++\n", lable[0]);
  FILE *arq;
  fpos_t pos;          // Para guardar a posicao do inicio do arquivo
  char date[5];        // Para guardar o ano
  char quali[3];       // Para guardar a qualificacao
  char name[LINESIZE]; // Para guardar o nome do evento
  char *pointer;

  // Abrindo o arquivo
  arq = fopen(lable[3], "r");
  if (!arq)
  {
    perror("Erro ao abrir arquivo");
    exit(1);
  }
  fgetpos(arq, &pos);

  get_data(string, lable[1], date, &pointer);
  while (pointer != NULL)
  {
    strcpy(quali, "NC");
    get_data(pointer, lable[2], name, &pointer);
    comparing(arq, name, quali, &pos);
    printf("%s : %s : %s \n", name, date, quali);
    get_data(pointer, lable[1], date, &pointer);
  }
  printf("\n");
  fclose(arq);
  return;
}

/*
Compara o nome do evento com cada linha.
Retorna a qualificacao se exite, ou "NC", caso nao exista. (POR REFERENCIA)
*/
void comparing(FILE *arq, char *name, char *quali, fpos_t *ini)
{
  char line[LINESIZE];
  char ch;
  int i;

  // Lendo cada linha
  ch = fgetc(arq);
  while (ch != EOF)
  {
    i = 0;
    while (ch != '\n')
    {
      line[i] = ch;
      i++;
      ch = fgetc(arq);
    }
    line[i] = '\0';
    // LINHA COMPLETA

    line[i - 3] = '\0'; // Deixando so o nome na linha

    // Comparando cada linha com o nome do evento
    if (levenshtein(line, name) <= 10)
    {
      // Pegando a qualificacao
      quali[0] = line[i - 2];
      quali[1] = line[i - 1];
      quali[2] = '\0';
      name = line;
      fsetpos(arq, ini); // Voltando o ponteiro para o inicio
      return;
    }

    ch = fgetc(arq);
  }
  fsetpos(arq, ini); // Voltando o ponteiro para o inicio
  return;            // NAO CONTEM
}

void process_wrapper(char *string, char *per_path, char *conf_path)
{
  /* Vetor de strings contenco as lables a serem procuradas */
  char *conf_lable[] = {"CONFERENCIAS", "ANO-DO-TRABALHO=", "NOME-DO-EVENTO=", conf_path};
  char *per_lable[] = {"PERIODICOS", "ANO-DO-ARTIGO=", "TITULO-DO-PERIODICO-OU-REVISTA=", per_path};

  process_event(string, conf_lable);
  process_event(string, per_lable);
  return;
}