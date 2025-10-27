#include<stdio.h>
#include<stdlib.h>
#include"funcoes_vet.h"
#include"funcoes_lista.h"

int main(void){
    celula* cabeca=malloc(sizeof(celula));
    cabeca->prox = NULL;

    for(int i=0; i<6; i++){
        insereFim((i*10), cabeca);
    }
    imprimeLista(cabeca);

    insereOrdenado(35, cabeca);
    insereOrdenado(5, cabeca);
    insereOrdenado(78, cabeca);

    imprimeLista(cabeca);


    liberaLista(cabeca);
    free(cabeca);
    return 0;
}
