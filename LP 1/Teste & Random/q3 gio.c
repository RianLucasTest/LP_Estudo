#include<stdlib.h>
#include<stdio.h>
//ler e armazenar N notas e encontrar a maior
int main(){
    int qtd;

    printf("Digite a quantidade de alunos total: ");
    scanf("%d", &qtd);

    float vet[qtd], maior; 
    int i;

    maior = 0;

    printf("Preencha as notas\n");
    for(i = 0; i < qtd; i++){
        scanf("%f", &vet[i]);
        if(maior < vet[i]){
            maior = vet[i];
        }
    }
    /*
    maior = vet[0];

    for(i = 1; i < qtd; i++){}
    */
    
    printf("O maior valor e: %.2f\n", maior);

    return 0;
}