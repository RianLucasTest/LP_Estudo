#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define VET 20

int main(){
    int vet[VET], maior, loc_maior, soma, i;
    float media;
    
    srand(time(NULL));
    printf("Lista de elementos:\nPosicao\tValor\n");
    for(i = 0; i < VET; i++){
        vet[i] = rand() % 100;
        soma += vet[i];
        printf("%d\t%d\n", i, vet[i]);
    }
    media = soma / VET;
    maior = vet[0];
    loc_maior = 0;
    for(i = 0; i < VET; i++){
        if(maior < vet[i]){
            maior = vet[i];
            loc_maior = i;
        }
    }
    printf("   A media dos elementos e: %.2f\n", media);
    printf("   O maior valor e: %d\n", maior);
    printf("   O maior valor esta na posicao %d\n", loc_maior);

    system("PAUSE");
    return 0;
}