#include <stdio.h>
#include <stdlib.h>
//Elabore um programa que calcule quantas notas de 50, 20, 10 e 1 são necessárias para se pagar uma
//conta cujo valor é fornecido (considere apenas valores inteiros).

int main(){
    int n, a50, a20, a10;

    printf("Digite o valor da conta a pagar:\n");
    scanf("%i", &n);
    a50 = n / 50;
    n = n % 50;
    a20 = n / 20;
    n = n % 20;
    a10 = n / 10;
    n = n % 10;
    printf("A conta sera paga com %i notas de 50, %i de 20, %i de 10 e %i de 1\n", a50, a20, a10, n);

    system("PAUSE");
    return 0;

}