#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

typedef struct no{
    char dado[SIZE];
    struct no* dir;
    struct no* esq;
    struct no* pai;
    int bf;
    int h;
} Ttree;

int altura(Ttree* no){
    if(no == NULL) { return(-1); }
    else { return(no->h); }
}

int max_h(Ttree* no1, Ttree* no2){
    int h1, h2;

    h1 = altura(no1);
    h2 = altura(no2);

    if(h1 > h2) { return(h1); }
    else { return(h2); }
}

Ttree* novo_no(char add[]){
    Ttree* novo = malloc(sizeof(Ttree));
    if(novo == NULL) {return NULL;}

    novo->esq = novo->dir = novo->pai = NULL;
    strcpy(novo->dado, add);
    novo->h = novo->bf = 0;

    return novo;
}

Ttree* rot_ll(Ttree* A){
    Ttree* B = A->esq;
    Ttree* Br = B->dir;

    B->dir = A;
    A->esq = Br;
    A = B;

    A->h = 1 + max_h(A->dir, A->esq);
    B->h = 1 + max_h(B->dir, B->esq);

    return(A);
}

Ttree* rot_rr(Ttree* A){
    Ttree* B = A->dir;
    Ttree* Bl = B->esq;

    B->esq = A;
    A->dir = Bl;
    A = B;

    A->h = 1 + max_h(A->dir, A->esq);
    B->h = 1 + max_h(B->dir, B->esq);

    return(A);
}

Ttree* rot_lra(Ttree* A){
    Ttree* B = A->esq;
    Ttree* C = B->dir;

    C->dir = A;
    C->esq = B;
    A = C;

    return(A);
}

Ttree* rot_lra_reflex(Ttree* A){
    Ttree* B = A->dir;
    Ttree* C = B->esq;

    C->dir = B;
    C->esq = A;
    A = C;

    return(A);
}

Ttree* rot_lrb(Ttree* A){}
Ttree* rot_lrb_reflex(Ttree* A){}
Ttree* rot_lrc(Ttree* A){}
Ttree* rot_lrc_reflex(Ttree* A){}



Ttree* inserir(Ttree* raiz, char add[]){

    if(raiz == NULL){
        raiz = novo_no(add);
        return raiz;
    }

    // retorno >0 => a primeira vem depois da segunda
    if(strcmp(add, raiz->dado) > 0){ 
        raiz->dir = inserir(raiz->dir, add);
        raiz->dir->pai = raiz;
    }
    else{
        raiz->esq = inserir(raiz->esq, add);
        raiz->esq->pai = raiz;
    }

    raiz->h = 1 + max_h(raiz->dir, raiz->esq);

    raiz->bf = altura(raiz->esq) - altura(raiz->dir);

    return raiz; 

}

//Exclui toda a árvore
Ttree* del_arvore(Ttree* raiz){
    if(raiz == NULL){
        return raiz;
    }

    del_arvore(raiz->esq);
    del_arvore(raiz->dir);
    
    free(raiz);
    raiz=NULL;
    return raiz;
}
