#include<stdio.h>
#include"funcoes.h"

int main(void){
    int n;

    printf("Insira qtd de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    printf("Preencha o vetor:\n");
    for(int i=0; i<n; i++){
        printf("Elemento [%d]-> ", i);
        scanf("%d", &vetor[i]);
    }

    printf("A soma dos elementos pares desse vetor e: %d\n", soma_pares(vetor, n));

    return 0;
}