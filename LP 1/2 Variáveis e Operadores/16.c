#include <stdio.h>
#include <stdlib.h>
//16. Elabore um programa que receba três valores digitados A; B e C informe se estes podem ser os lados
//de um triângulo. O ABC é triângulo se A < B + C e B < A + C e C < A + B.

int main(){
    int A, B, C;

    printf("Valor de A:\n");
    scanf("%i", &A);
    printf("Valor de B:\n");
    scanf("%i", &B);
    printf("Valor de C:\n");
    scanf("%i", &C);

    if (A < B + C){
        if(B < A + C){
            if (C < A + B){
                printf("Os valores podem ser lados de um triangulo\n");
            }
            else
                printf("Os valores nao podem ser lados de um triangulo\n");
        }
        else
            printf("Os valores nao podem ser lados de um triangulo\n");
    }
    else
        printf("Os valores nao podem ser lados de um triangulo\n");
    
    
    system("PAUSE");
    return 0;
}