#include<stdio.h>
#include<stdlib.h>
#include"funcoes_lista.h"

void liberaLista(celula* p){
    celula* liberar=NULL;
    p=p->prox;
    while(p!=NULL){
        liberar = p;
        p = p->prox;
        free(liberar);
    }
    printf("Lista liberada""\n");
}

void insere(int x, celula* p){
    celula* nova=malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = p->prox;
    p->prox = nova;
}

celula* insereRetorna(int x, celula* p){
    celula* nova=malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = p->prox;
    p->prox = nova;

    return nova;
}

void insereFim(int x, celula* p){
    celula* nova = malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = NULL;

    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = nova;
}

void imprimeLista(celula* p){
    int i;
    printf("======INICIO DA LISTA=====\n");

    for(i=0, p=p->prox ; p != NULL; i++, p = p->prox){
        printf("Elemento[%d]: %d\n", i, p->valor);
    }

    printf("=====FIM DA LISTA=====\n");
}

void vetEmLista(int* vetor, int tam, celula* head){
    int i;
    celula* temp=head;

    for(i = 0; i < tam; i++){
        temp = insereRetorna(*(vetor+i), temp);
    }

}