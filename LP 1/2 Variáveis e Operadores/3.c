#include <stdio.h>
#include <stdlib.h>
//Escreva um programa que receba três números de ponto flutuante e imprima a soma, a média, o
//produto, o menor e o maior desses números.

int main(){
    float n1, n2, n3, s, m, p;

    printf("Digite o primeiro valor\n");
    scanf("%f", &n1);
    printf("Digite o segundo valor\n");
    scanf("%f", &n2);
    printf("Digite o terceiro valor\n");
    scanf("%f", &n3);
    s = n1 + n2 + n3;
    m = s / 3;
    p = n1 * n2 * n3;
    printf("A soma e %.2f, a media e %.2f e o produto e %.2f\n", s, m, p);

    if(n1 > n2){
        if (n2 > n3){
            printf("%.2f e o maior e %.2f e o menor\n", n1, n3);
        }
        else{
            if (n3 > n1){
                printf("%.2f e o maior e %.2f e o menor\n", n3, n2);
            }
            else
            printf("%.2f e o maior e %.2f e o menor\n", n1, n2);
        }
    }
    else{
        if (n1 > n3){
            printf("%.2f e o maior e %.2f e o menor\n", n2, n3);
        }
        else{
            if (n3 > n2){
                printf("%.2f e o maior e %.2f e o menor\n", n3, n1);
            }
            else
            printf("%.2f e o maior e %.2f e o menor\n", n2, n1);
        }
    }

    system("PAUSE");
    return 0;
}