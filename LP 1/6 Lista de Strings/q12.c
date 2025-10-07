#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#define TAM 100
#define ALFA 27

int main(){
    char str[TAM], letra[ALFA];
    int i, j, estat[ALFA]={0};

    for(i=0, j=65; i < ALFA-1; i++, j++) 
        letra[i] = j;
    letra[i] = ' ';
    
    printf("Insira uma string (max 100 caracteres):\n");
    gets(str);

    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            estat[26]++;
        }
        else{
            str[i] = toupper(str[i]);
            j = str[i] - 65;
            estat[j]++;
        }
    }
    printf("A estatistica de caracteres digitados e:\n");
    printf("Letra\tQTD\n");
    for(i = 0; i < ALFA; i++){
        if(estat[i] != 0){
            printf("'%c'\t%d\n", letra[i], estat[i]);
        }
    }

    system("PAUSE");
    return 0;
}