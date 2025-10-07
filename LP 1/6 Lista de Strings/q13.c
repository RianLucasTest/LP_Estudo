#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50

int main(){
    char pal1[TAM], pal2[TAM];
    int t1=0, t2=0;

    printf("Digite a primeira palavra\n");
    gets(pal1);
    printf("Digite a segunda palavra\n");
    gets(pal2);

    if(!strcmp(pal1, pal2)) printf("As palavras sao iguais\n");
    else{
        printf("As palavras nao sao iguais\n");
        t1 = strlen(pal1);
        t2 = strlen(pal2);
        if(t1 > t2) printf("A palavra 1 e maior que a 2\n");
        else if(t1 < t2) printf("A palavra 2 e maior que a 1\n");
        else printf("As palavras tem o mesmo tamanho\n");

        if(strstr(pal1, pal2)) printf("A palavra 2 e substring da palavra 1\n");
        else printf("A palavra 2 nao e substring da palavra 1\n");
    }

    system("PAUSE");
    return 0;
}