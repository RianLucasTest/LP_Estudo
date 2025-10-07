#include<stdio.h>
#include"funcoes.h"

int main(void){
    int base, num;

    printf("Insira o numero: ");
    scanf("%d", &num);
    printf("Insira a base desejada: ");
    scanf("%d", &base);

    converte_base(num,base);
    printf("\n");

    return 0;
}