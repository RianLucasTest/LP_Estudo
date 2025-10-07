#include<stdlib.h>
#include<stdio.h>
#define TAM 9

int main(){
    int i, vet[TAM], atual=0;
    printf("Preencha o vetor trajetoria com elementos do intervalo 0 a %d\n", TAM-1);
    scanf("%d", &vet[atual]);
    for(i = 0; i < TAM; i++){
        atual = vet[atual];
        scanf("%d", &vet[atual]);
    }
    printf("Indice: ");
    for(i = 0; i < TAM; i++){
        printf("%8d", i);
    }
    printf("\nValor: ");
    for(i = 0; i < TAM; i++){
        printf("%8d", vet[i]);
    }

    printf("\n");
    system("PAUSE");
    return 0;
}