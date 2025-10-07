#include<stdlib.h>
#include<stdio.h>
#define VET 5

int main(){
    int vet[VET], i, soma=0;
    float media;
    printf("Insira %d elementos para o vetor:\n", VET);
    for(i = 0; i < VET; i++){
        printf("Posicao %d: ", i);
        scanf("%d", &vet[i]);
        soma += vet[i];
    }
    media = soma / VET;
    printf("A media dos valores inseridos e de: %.2f\n", media);
    printf("Os valores acima da media encontram-se nas posicoes:\n");
    for(i = 0; i < VET; i++){
        if(vet[i] > media){
            printf("   Posicao %d\n", i);
        }
    }
    system("PAUSE");
    return 0;
}