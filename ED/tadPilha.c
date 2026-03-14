#include<stdio.h>
#include<stdlib.h>
#define TAMPILHA 10

typedef struct{
    int vet[TAMPILHA];
    int top;
} Tstack;

//1 = vazia // 0 = não vazia
int is_empty(Tstack* pilha){
    if (pilha->top == -1) return 1;
    else return 0;
}

//1 = cheia // 0 = não cheia
int is_full(Tstack* pilha){
    if(pilha->top == TAMPILHA-1) return 1;
    else return 0;
}

void push(Tstack* pilha, int valor){
    if(is_full(pilha)){
        printf("Pilha cheia: Nao e possivel adicionar\n");
        return;
    }
    (pilha->top)++;
    pilha->vet[pilha->top] = valor;
}

int pop(Tstack* pilha){
    if(is_empty(pilha)){
        printf("Pilha vazia: Nada a desempilhar\n");
        return -1; //código de erro
    }
    int temp = pilha->vet[pilha->top];
    (pilha->top)--;
    return temp;
}

int ver_topo(Tstack* pilha){
    if(is_empty(pilha)){
        printf("Pilha vazia!\n");
        return -1; //código de erro
    }
    return pilha->vet[pilha->top];;
}

void inicializa(Tstack* pilha){
    pilha->top = -1;
}


int main(void){
    Tstack pilha;
    inicializa(&pilha);

    printf("Topo: %d\n", ver_topo(&pilha));
    printf("Pop1: %d\n", pop(&pilha));

    for(int i=0;i<=10; i++){
        push(&pilha, i*10);
        printf("Topo: %d\n", ver_topo(&pilha));
    }

    for(int i=10; i>=0; i--){
        printf("pop: %d\n", pop(&pilha));
        printf("Topo: %d\n", ver_topo(&pilha));
    }


    return 0;
}

