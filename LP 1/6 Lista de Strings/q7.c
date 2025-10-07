#include<stdio.h>
#include<stdlib.h>
#define STR 15

int main(){
    char num1[STR], num2[STR], num3[STR], num4[STR];
    int soma=0, a, b, c, d;
    printf("Digite 4 numeros:\n");

    gets(num1);
    a = atoi(num1);
    if(!a){
        printf("ERRO: nao representa um numero inteiro\n");
        return 0;
    }
    gets(num2);
    b = atoi(num2);
    if(!b){
        printf("ERRO: nao representa um numero inteiro\n");
        return 0;
    }
    gets(num3);
    c = atoi(num3);
    if(!c){
        printf("ERRO: nao representa um numero inteiro\n");
        return 0;
    }
    gets(num4);
    d = atoi(num4);
    if(!d){
        printf("ERRO: nao representa um numero inteiro\n");
        return 0;
    }
    soma = a + b + c + d;

    printf("A soma dos valores digitados e: %d\n", soma);

    system("PAUSE");
    return 0;
}