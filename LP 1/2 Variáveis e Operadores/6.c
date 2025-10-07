#include <stdio.h>
#include <stdlib.h>
//6. Escreva um programa que leia um número inteiro e informe se ele é par ou ímpar.

int main(){
    int a;

    printf("Digite um numero\n");
    scanf("%i", &a);
    if(a%2 == 0){
        printf("O numero e par\n");
    }
    else{
        printf("O numero e impar\n"
        );
    }
    system("PAUSE");
    return 0;

}