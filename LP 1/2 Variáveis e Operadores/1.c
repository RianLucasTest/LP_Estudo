#include <stdio.h>
#include <stdlib.h>
//1. Escreva um programa que peça ao usuário para digitar dois números inteiros, obtenha-os do usuário
//e imprima a soma, o produto, a diferença, o quociente e o resto da divisão dos dois números.

int main(){
    int n1, n2, s, p, d, q, rd;

    printf("Digite o primeiro numero inteiro\n");
    scanf("%i", &n1);
    printf("Digite o segundo numero inteiro\n");
    scanf("%i", &n2);
    s = n1 + n2;
    p = n1 * n2;
    d = n1 - n2;

    if (n2 != 0){
        q = n1 / n2;
        rd = n1 % n2;
        printf("A soma e %i, o produto e %i, a diferenca e %i, o quociente e %i e o resto da divisao e %i\n", s, p, d, q, rd);
    }
    else {
        printf("A soma e %i, o produto e %i, a diferenca e %i e nao existe quociente e resto pois nao e possivel dividir por 0\n", s, p, d);
    }

    system("PAUSE");
    return 0;
}