#ifndef NUMEROS_H
#define NUMEROS_H

typedef struct celula{
    int valor;
    struct celula* prox;
} celula;

celula* cria_celula(int valor);
void insere_ordem(celula** lista);
void liberar_lista(celula *lista);
void op_par(int* valor);
void op_impar(int* valor);
void exibe_lista(celula* lista);


#endif