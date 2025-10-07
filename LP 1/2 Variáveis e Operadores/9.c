#include <stdio.h>
#include <stdlib.h>
//9. Escreva um programa que receba a entrada de um numero inteiro de 5 dígitos , separe o número em
//seus dígitos componentes e os imprima separados uns dos outros por três espaços.

int main(){
    int a, a1, a2, a3, a4, a5;

    printf("Digite um numero de 5 digitos:\n");
    scanf("%i", &a);
    
    if(a > 99999 || a <10000){
        printf("Erro: o numero nao tem 5 digitos\n");
    }
    else{
        a1 = a / 10000;
        a = a % 10000;
        a2 = a / 1000;
        a = a % 1000;
        a3 = a / 100;
        a = a % 100;
        a4 = a / 10;
        a5 = a % 10;
        printf("%i   %i   %i   %i   %i   \n", a1, a2, a3, a4, a5);
    }
    
    system("PAUSE");
    return 0;
}