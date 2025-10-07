#include<stdio.h>
#include"funcoesh.h"

int main(void){
    int n1=15, n2=25;
    int* a=&n1;
    int* b=&n2;

    printf("Valor inicial: n1: %d\tn2: %d\n", n1, n2);
    trocar(a, b);
    printf("Valor novo: n1: %d\tn2: %d\n", n1, n2);

    return 0;
}