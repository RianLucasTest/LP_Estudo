#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

int* preencheVet(int* tam){
    int* vetor = malloc(sizeof(int));

    if(vetor == NULL){
        printf("Erro na alocacao de memoria.\nCódigo encerradO!\n");
        return NULL;
    }
    int* temp = NULL;
    int i=0;
    
    printf("Insira os valores(valor negativo para encerrar)\n");
    while(1){
        printf("vetor[%d]: ", i);
        scanf("%d", vetor+i); //leitura

        if(*(vetor+i) < 0){ //verifica código de parada (valor negativo)
            printf("Encerrando Leitura!\n");
            break;
        }

        i++; //incrementa quantidade de elementos do vetor

        temp = realloc(vetor, (i+1)*sizeof(int)); //faz a realocação e testa se deu certo
        if(temp == NULL){
            printf("Erro na realocacao de memoria.\nCodigo encerradO!\n");
            free(vetor); //libera o vetor em caso de erro
            return NULL;
        }
        vetor = temp;
    }
    *tam = i;
    printf("Qantidade total de itens inseridos: %d\n", i);
    return vetor;
}

void printVet(int* vet, int tam){
    printf("=====VETOR=====\n");
    for(int i=0; i<tam; i++){
        printf("vetor[%d]: %d\n", i, *(vet+i));
    }
    printf("======FIM DO VETOR=====\n");
}