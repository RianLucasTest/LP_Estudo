#include<stdlib.h>
#include<stdio.h>
#define VET 5

int main(){
    int vet1[VET], vet2[VET], soma[VET], i;

    printf("Digite %d numeros inteiros para o vetor 1:\n", VET);
    for (i = 0; i < VET; i++){
        printf(">");
        scanf("%d", &vet1[i]);
    }
    printf("Digite %d numeros inteiros para o vetor 2:\n", VET);
    for (i = 0; i < VET; i++){
        printf(">");
        scanf("%d", &vet2[i]);
    }
    for(i = 0; i < VET; i++){
        soma[i] = vet1[i] + vet2[i];
    }
    printf("A soma dos valores de mesma posicao nos dois vetores e:\n");
    for(i = 0; i < VET; i++){
        printf("%5d\n", soma[i]);
    }
    system("PAUSE");
    return 0;
}