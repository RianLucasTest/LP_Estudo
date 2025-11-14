#include<stdio.h>
#include<stdlib.h>
#include"funcoes_vet.h"
#include"funcoes_lista.h"

//entrada:  / valor inserido
void insere_sem_cabeca(celula** p, int valor){
    celula* nova=malloc(sizeof(celula));

    nova->valor = valor;
    nova->prox = *p;
    *p=nova;
}

void imprime_lista_sem_cabeca(celula* p){

    for(int i=0; p!=NULL; i++, p=p->prox){
        printf("[%d] -> %d\n", i, p->valor);
    }

}

int* lista_em_vet(celula* p){
    int i=0;
    int* vet=NULL;

    while(p!=NULL){
        int* temp=realloc(vet, (i+1)*sizeof(int));
        if(temp==NULL){
            printf("ERRO na alocacao\n");
            free(vet);
            return NULL;
        }
        vet=temp;
        *(vet+i) = p->valor;
        i++;
        p=p->prox;
    }

    for(int j=0; j<i; j++){
        printf("vet[%d] == %d\n", j, *(vet+j));
    }
    return vet;
}

void libera_sem_cabeca(celula* p){

    while(p!=NULL){
        celula* ant=p;
        p=p->prox;
        free(ant);
    }
    
}

void excloi_sem_cabeca(int del, celula** p){

    if((*p)->valor == del){
        celula* aux = *p;
        *p=(*p)->prox;
        free(aux);
        return;
    }

    celula* lista=*p;
    celula* ant=NULL;
    while( lista!=NULL && lista->valor != del){
        ant=lista;
        lista=lista->prox;
    }
    if(lista==NULL){
        printf("Vallor nao encontrado na lista\n");
        return;
    }

    ant->prox = lista->prox;
    free(lista);
}



int main(void){
    celula* inicio=NULL;

    insere_sem_cabeca(&inicio, 20);
    insere_sem_cabeca(&inicio, 50);
    insere_sem_cabeca(&inicio, 10);
    insere_sem_cabeca(&inicio, 30);
    insere_sem_cabeca(&inicio, 100);

    imprime_lista_sem_cabeca(inicio);

    printf("\n==================================\n\n");

    int* vetor=lista_em_vet(inicio);

    libera_sem_cabeca(inicio);
    inicio=NULL;
    free(vetor);
    vetor=NULL;
    return 0;
}









/*
int main(void){
    celula* cabeca=malloc(sizeof(celula));
    cabeca->prox = NULL;

    insere(52, cabeca);
    insere(10, cabeca);
    insere(15, cabeca);
    insere(43, cabeca);
    insere(65, cabeca);
    insere(45, cabeca);
    

    imprimeLista(cabeca);

    int tam=0, i;
    celula* p=cabeca->prox;
    for(i=0; p!=NULL; p=p->prox, i++){}


    printf("\n\n--> %d\n\n", i);

    bubbleLista(i, cabeca);

    imprimeLista(cabeca);


    liberaLista(cabeca);
    free(cabeca);
    cabeca=NULL;
    return 0;
}*/
