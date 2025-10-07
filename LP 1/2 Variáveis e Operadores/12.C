#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//Escreva um programa que leia os coeficientes de um polinômio de segundo grau na forma "ax^2 + bx + c" .Calcule as raízes reais do polinômio, 
//se o polinômio não tiver raízes reais uma mensagem de erro deve ser mostrada.

int main(){
    float a, b, c, x1, x2, d;

    printf("Valor de A:\n");
    scanf("%f", &a);
    printf("Valor de B:\n");
    scanf("%f", &b);
    printf("Valor de C:\n");
    scanf("%f", &c);

    d = (b*b) - (4 * a * c);

    if (d < 0){
        printf("Erro: Nao existem raizes reais\n");
    }
    else{
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        printf("As raizes do polinomio sao: %f, %f\n", x1, x2);
    }

    system("PAUSE");
    return 0;
}