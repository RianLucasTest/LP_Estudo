#include<stdio.h>
#include<stdlib.h>
#include"funcoes_vet.h"
#include"funcoes_lista.h"

void bubbleLista(int tam, celula* head){
    celula* p1=NULL;
    celula* p2=NULL;
    int temp;

    for(int i=0; i<tam-1; i++){
        p1=head->prox;
        p2=p1->prox;

        for( ; p2!=NULL; p1=p1->prox, p2=p2->prox){

            if(p1->valor > p2->valor){
                temp = p1->valor;
                p1->valor = p2->valor;
                p2->valor = temp;
            }
        }
    }
}


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
}
