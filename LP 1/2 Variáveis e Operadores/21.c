#include <stdio.h>
#include <stdlib.h>
//21. Elabore um programa que transforme uma temperatura fornecida em ±C para a temperatura
//correspondente em ±F

int main(){
    float tempC, tempF;

    printf("Digite a temperatura em C:\n");
    scanf("%f", &tempC);

    tempF = 1.8 * tempC + 32;

    printf("A temperatura em Fahrenheit e %.2f\n", tempF);

    system("PAUSE");
    return 0;
}