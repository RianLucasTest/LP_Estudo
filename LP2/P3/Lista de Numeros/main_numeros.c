#include<stdio.h>
#include<stdlib.h>
#include"numeros.h"

void aplicar_operacao(celula *inicio, void (*operacao_par)(int *), void (*operacao_impar)(int *));

int main(void){
    celula* lista = NULL;

    insere_ordem(&lista);

    exibe_lista(lista);
    liberar_lista(lista);



}