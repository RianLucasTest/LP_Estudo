#include <stdio.h>
#include <stdlib.h>
//8. Escreva um programa que leia dois inteiros e então determine se o maior é múltiplo do menor.

int main(){
    int a, b, maior, menor;

    printf("Digite o primeiro numero:\n");
    scanf("%i", &a);
    printf("Digite o segundo numero:\n");
    scanf("%i", &b);

    if (a > b){
        maior = a;
        menor = b;
        if(a%b == 0){
            printf("%i e multiplo de %i\n", maior, menor);}
        else{
            printf("%i nao e multiplo de %i\n", maior, menor);}
    }
    else{
        maior = b;
        menor = a;
        if(b%a == 0){
            printf("%i e multiplo de %i\n", maior, menor);}
        else{
            printf("%i nao e multiplo de %i\n", maior, menor);}
    }
    system("PAUSE");
    return 0;
}