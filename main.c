#include <stdio.h>

int main(){
    FILE *menotti;
    int i;
    char c;
    menotti = fopen("curriculos/curriculo.xml", "rb");
    if (menotti != NULL){
        //Faz a leitura dos 10 primeiros caracteres do arquivo
        for (i =0; i < 10;i++){
            c = fgetc(menotti);
            printf("%c",c);
        }
        return 0;
    }
    fclose(menotti);
    return 1;
}