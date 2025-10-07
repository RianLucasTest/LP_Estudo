#include <stdio.h>
#include <stdlib.h>
//4. Escreva um programa que leia o raio de um círculo e imprima seu diâmetro, o valor de sua
//circunferência e sua área.

int main(){
    float r, d, c, a;

    printf("Digite o valor do raio do circulo\n");
    scanf("%f", &r);
    d = 2 * r;
    c = d * 3.14;
    a = r * r * 3.14;
    printf("O diametro e %.2f, a circunferencia e %.2f e a area e %.2f\n", d, c, a);

    system("PAUSE");
    return 0;
}