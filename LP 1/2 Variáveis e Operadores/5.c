#include <stdio.h>
#include <stdlib.h>
//5. Escreva um programa que leia os valores (x; y) de um ponto do plano e informe no qual quadrante o
//ponto se encontra. Utilize o menor número de condições possíveis.

int main(){
    float x, y;
    printf("Digite o valor de x\n");
    scanf("%f", &x);
    printf("Digite o valor de y\n");
    scanf("%f", &y);

    if (x > 0){
        if(y > 0){
            printf("Primeiro quadrante\n");
        }
        else{
            printf("Quarto quadrante\n");
        }
    }
    else{
        if(y > 0){
            printf("Segundo quadrante\n");
        }
        else{
            printf("Terceiro quadrante\n");
        }
    }

    system("PAUSE");
    return 0;
}