#include<stdio.h>
#include"funcoes.h"

int main(void){
    int n;

    printf("Quantos discos deseja inserir? ");
    scanf("%d", &n);

    //discos--origem--destino--auxiliar
    hanoi(n, 'A', 'C', 'B');

    return 0;
}