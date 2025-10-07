#include <stdio.h>
#include <stdlib.h>
//17. Escreva um programa que recebe a longitude dos três lados de um triângulo e informa se o triângulo
//é isóscele. Considere que efetivamente os lados formam um triângulo.

int main(){
    int a, b, c;

    printf("Valor do lado a:\n");
    scanf("%i", &a);
    printf("Valor do lado b:\n");
    scanf("%i", &b);
    printf("Valor do lado c:\n");
    scanf("%i", &c);

    if (a == b ){
        if (a != c){
            printf("O triangulo e isoscele\n");
        }
        else{
            printf("O triangulo nao e isoscele\n");
        }
    }
    else{
        if (a == c){
            printf("O triangulo e isoscele\n");
        }
        else{
            printf("O triangulo nao e isoscele\n");
        }
    }

    system("PAUSE");
    return 0;
}