#include <stdio.h>
#include<stdlib.h>
#define printe() printf("\n list[]: "); for(TList* tmp=lista->prox; tmp != NULL; ) { printf("%3d ", tmp->dado ); tmp=tmp->prox; }

typedef struct lista{
    int dado;
    struct lista* prox;
} TList;

int size(TList* lista){
    TList* tmp=lista->prox;
    int i=0;
    for(; tmp != NULL; tmp=tmp->prox, i++){}
    return i;
}

int search(TList* lista, int a) {
    int tmp=-1;
    int h = -1;
    while ( (lista->prox != NULL)&&(lista->dado!=a)) { h++; lista=lista->prox; }
    if (lista->dado==a) { tmp = h; }
    return(tmp);
}
int insatk(TList* lista, int k, int a) {
    for (int cont=0; cont<k; cont++){lista=lista->prox;}
    
    TList* novo=malloc(sizeof(TList));
    novo->dado = a;
    novo->prox = lista->prox;
    lista->prox=novo;

    return(0);
}
int delatk(TList* lista, int k) {
    TList* aux;
    
    if (lista->prox !=0) {
        for (int cont=0; cont<k; cont++){
            aux=lista;
            lista=lista->prox;
        }
        aux->prox = lista->prox;
        free(lista);
    }
    return(0);
}
int main() {
    TList* lista=malloc(sizeof(TList));
    lista->prox=NULL;
    printf("\n           0   1   2   3   4   5   6   7   8   9 ");
    insatk(lista, 0, 2); insatk(lista, 0, 4); insatk(lista, 0, 6);
    insatk(lista, 0, 8); insatk(lista, 0, 1); printe();

   
    insatk(lista, size(lista), 3); insatk(lista, size(lista), 5);
    insatk(lista, size(lista), 7); printe();
   
    printf("\n 5 at %d", search(lista, 5));
    printf("\n 8 at %d", search(lista, 8)); delatk(lista, 2);printe();
    printf("\n           0   1   2   3   4   5   6   7   8   9 ");
    free(lista);
    return(0);
}