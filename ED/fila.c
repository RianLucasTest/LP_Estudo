#include<stdlib.h>
#include<stdio.h>
typedef struct queue{
    int dado;
    struct queue* prox;
}TQueue;
 
int enqueue(TQueue *queue, int a){ 
    TQueue* novo=malloc(sizeof(TQueue));
    if(novo==NULL){printf("ERRO na alocacao de memoria"); return(-1);}

    while((*queue).prox != NULL){
        queue=(*queue).prox;
    }

    (*novo).dado = a;
    (*novo).prox = (*queue).prox;
    (*queue).prox = novo;
    return(0);
}
 
int dequeue(TQueue *queue){
    if((*queue).prox == NULL){
        printf("ERRO: fila vazia\n");
        return(-1);
    }
    TQueue* aux=(*queue).prox;
    (*queue).prox = (*aux).prox;
    int b = (*aux).dado;
    free(aux);
    return(b);
}
 
int main() {
    TQueue *fila1;
    fila1 = malloc(sizeof(TQueue));
    (*fila1).prox=NULL;
    int tmp;
    enqueue(fila1, 8); enqueue(fila1, 6); enqueue(fila1, 4); enqueue(fila1, 4); enqueue(fila1, 2);
    enqueue(fila1, 1); enqueue(fila1, 3); enqueue(fila1, 5); enqueue(fila1, 7); enqueue(fila1, 9);

    printf("\n Queue: ");
    for(TQueue* aux=(*fila1).prox; aux!= NULL; aux=(*aux).prox) { printf("%3d ", (*aux).dado); }
    tmp=dequeue(fila1);

    printf("\n Queue: ");
    for(TQueue* aux=(*fila1).prox; aux!= NULL; aux=(*aux).prox) { printf("%3d ", (*aux).dado); }
    tmp=dequeue(fila1); tmp=dequeue(fila1);

    printf("\n Queue: ");
    for(TQueue* aux=(*fila1).prox; aux!= NULL; aux=(*aux).prox) { printf("%3d ", (*aux).dado); }

    tmp=dequeue(fila1); tmp=dequeue(fila1); tmp=dequeue(fila1);
    printf("\n Queue: ");
    for(TQueue* aux=(*fila1).prox; aux!= NULL; aux=(*aux).prox) { printf("%3d ", (*aux).dado); }

    return(0);
} 