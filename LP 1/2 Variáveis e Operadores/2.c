#include <stdio.h>
#include <stdlib.h>
//2.Escreva um programa que peça ao usuário para fornecer dois números inteiros, obtenha-os do usuário e imprima o maior deles seguido das
// palavras “e maior”. Se os números foram iguais, imprima a mensagem “estes números são iguais”.

int main(){
    int n1, n2;

    printf("Digite o primeiro numero inteiro\n");
    scanf("%i", &n1);
    printf("Digite o segundo numero inteiro\n");
    scanf("%i", &n2);
    
    if (n1 == n2){
        printf("Esses numeros sao iguais\n");
    }
    else{
        if (n1 > n2){
            printf("%i e maior\n", n1);
        }
        else {
            printf("%i e maior\n", n2);
        }
    }
    
    system("PAUSE");
    return 0;
}