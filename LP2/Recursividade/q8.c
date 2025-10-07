#include<stdio.h>
#include<string.h>
#include"funcoes.h"

int main(void){
    char str[50];
    int inicio=0, fim;

    printf("Insira sua string:\n->");
    fgets(str, 50, stdin);
    //utilizando fgets lê '\n' no final(strlen-2 para limite do vetor)
    fim = strlen(str)-2;

    if(eh_palindromo(str, inicio, fim)){
        printf("A string e palindromo!\n");
    }
    else{
        printf("A string nao e palindromo!\n");
    }


    return 0;
}