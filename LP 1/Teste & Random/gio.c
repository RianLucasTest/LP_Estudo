#include<stdlib.h>
#include<stdio.h>
//Preencher todas as casas de um vetor com 0

int main(){
    int vet[10], i;
    //Tamanho 10 == 0 a 9

    for(i = 0; i < 10; i++){
        vet[i] = 0;
    }
    for(i = 0; i < 10; i++){
        printf("%d     %d\n", i, vet[i]);
    }

    return 0;
}