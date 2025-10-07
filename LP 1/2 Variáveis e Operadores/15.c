#include <stdio.h>
#include <stdlib.h>
//15.Elabore um programa que calcule e exiba a média de três números fornecidos pelo usuário.

int main(){
    float a, b, c, m;

    printf("Digite tres valores:\n");
    scanf("%f", &a);
    printf("Digite o segundo valor:\n");
    scanf("%f", &b);
    printf("Digite o terceiro valor:\n");
    scanf("%f", &c);

    m = (a + b + c)/3;
    printf("A media e: %.2f\n", m);

    system("PAUSE");
    return 0;
}