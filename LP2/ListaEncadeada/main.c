#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"
#include"funcoes_lista.h"

void wait(void);

int main(void){
    int tam=0;
    int* vetor = preencheVet(&tam);
    celula* cabeca=malloc(sizeof(celula));
    cabeca->prox = NULL;

    vetEmLista(vetor, tam, cabeca);
    imprimeLista(cabeca);

    free(vetor);
    vetor=NULL;
    liberaLista(cabeca);
    free(cabeca);
    cabeca=NULL;
    return 0;
}