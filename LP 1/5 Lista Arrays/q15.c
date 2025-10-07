#include<stdlib.h>
#include<stdio.h>
#define TAM 9

int main(){
    int i, vet[TAM], atual=0;
    printf("Preencha o vetor trajetoria com %d elementos(0 para finalizar)\n", TAM);
    scanf("%d", &vet[atual]);
    for(i = 0; i < TAM; i++){
        atual = vet[atual]-1;
        scanf("%d", &vet[atual]);
    }
    printf("Indice: ");
    for(i = 0; i < TAM; i++){
        printf("%8d", i+1);
    }
    printf("\nValor: ");
    for(i = 0; i < TAM; i++){
        printf("%8d", vet[i]);
    }

    printf("\n");
    system("PAUSE");
    return 0;
}