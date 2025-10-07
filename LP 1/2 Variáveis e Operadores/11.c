#include <stdio.h>
#include <stdlib.h>
//11. Escreva um programa que leia um número inteiro e imprima-o em representação decimal, octal e
//hexadecimal.

int main(){
    int a;

    printf("Digite um numero inteiro:\n");
    scanf("%i", &a);
    printf("%i, %o, %X\n", a, a, a);

    system("PAUSE");
    return 0;
}