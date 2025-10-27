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
        printf("Lista[%d]: %d\tEndereco da celula: %p\n", i, p->valor, p);
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

int* listaEmVet(int* tam, celula* p){
    int* vetor = malloc(sizeof(int));
    if(vetor == NULL){
        printf("Erro na alocacao de memoria.\nCódigo encerradO!\n");
        return NULL;
    }
    int* temp = NULL;
    int i=0;
    
    while(1){
        p=p->prox;
        *(vetor+i) = p->valor;
        i++; //incrementa quantidade de elementos do vetor

        if(p->prox == NULL){
            break;
        }

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

celula* buscaValor(int x, celula* p){
    p=p->prox;
    while(p!=NULL){
        if(p->valor == x){
            return p;
        }
        p=p->prox;
    }
    printf("Valor NAO encontrado na lista!\n");
    return NULL;
}

celula* buscaEndereco(celula* find, celula* p){

    p=p->prox;
    if(p==NULL){
        printf("Lista vazia!\n");
        return NULL;
    }
    while(p->prox != NULL){
        if(p->prox == find){
            return p;
        }
        p=p->prox;
    }
    printf("Endereço informado NAO encontrado na lista!\n");
    return NULL;
}

void removeNo(int x, celula* p){
    celula* deletar=NULL;
    celula* ant = NULL;
    while(p->prox!=NULL){
        ant=p; //recebe no anterior
        p=p->prox;  //recebe no atual
        if(p->valor == x){
            ant->prox = p->prox;
            free(p);
            return;
        }
    }
    printf("No a ser removido nao encontrado!\n");
}
