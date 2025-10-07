#include<stdio.h>
#include"funcoesh.h"

int main(void){
    int vet[5]={1,2,3,4,5}, soma=0;
    int* ptr_vet=vet;
    int* ptr_soma=&soma;

    soma_print(ptr_vet, ptr_soma);

    printf("Soma total: %d\n", soma);

    return 0;
}