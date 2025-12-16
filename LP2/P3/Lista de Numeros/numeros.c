#include<stdio.h>
#include<stdlib.h>
#include"numeros.h"

celula* cria_celula(int valor){ //cria e retorna ptr paraa celula nova
    celula* nova = malloc(sizeof(celula)); //cria uma nova celula dinamicamente

    nova-> valor = valor;
    nova->prox = NULL;
    return nova;
}

void insere_ordem(celula** lista){
    printf("Insira os valores na lista: \n");
    int add;

    if(*lista == NULL){ //caso especial: primeiro no
        printf("Numero: ");
        scanf("%d", &add);
        if(add < 0) return;
        *lista = cria_celula(add); //adicona direto
    }

    celula* p=*lista;
    celula* aux=NULL;

    while(1){
        printf("Numero: ");
        scanf("%d", &add);
        if(add < 0) break; //verifica se é positivos, se for, prossegue

        aux = cria_celula(add); //p é a nova e aponta para NULL
        p->prox = aux; //p recebe a celula nova depois avança para add depois dela
        p = p->prox;

    }
}

void liberar_lista(celula *lista) {
     celula* del=NULL; //inicializar com NULL para evitar comportamento selvagem

     while(lista != NULL){
        del = lista; //mantém o endereço a ser liberado
        lista = lista->prox; //avança
        free(del); //libera
     }
     lista=NULL;
     del=NULL;  //evita comportamento selvagem

}

void op_par(int* valor){
    *valor *= 2; //multiplica por 2
}
void op_impar(int* valor){
    *valor += 10; //adiciona 10
}

void exibe_lista(celula* lista){

    while(lista->prox != NULL){
        printf("%d->", lista->valor); //exibe da  maneira correta
        lista=lista->prox; //acança
    }
    printf("%d\n", lista->valor); //exibição final
}
