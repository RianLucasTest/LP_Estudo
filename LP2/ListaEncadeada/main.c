#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"
#include"funcoes_lista.h"

int main(void){
    celula* cabeca=malloc(sizeof(celula));
    cabeca->prox = NULL;

    for(int i=0; i<6; i++){
        insereFim((i*10), cabeca);
    }
    imprimeLista(cabeca);
    printf("\n\nEndereco do 30: %p\n\n", buscaValor(30, cabeca));



    liberaLista(cabeca);
    free(cabeca);
    return 0;
}
