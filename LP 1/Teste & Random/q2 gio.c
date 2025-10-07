#include<stdlib.h>
#include<stdio.h>
//ler um veto de 50 numeros, e procurar um N e mostrar os indices

int main(){
    int vet[10], i, N;

    printf("Preencha o vetor:\n");

    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }
    printf("Digite um termo a ser encontrado: ");
    scanf("%d", &N);

    printf("Indices onde foi encontrado:\n");

    for(i = 0; i < 10; i++){
        if(N == vet[i]){
            printf("  %d\n", i);
        }
    }

    return 0;
}