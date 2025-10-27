#ifndef FUNCOES_LISTA_H
#define FUNCOES_LISTA_H

typedef struct Celula{
    int valor;
    struct Celula* prox;
}celula;

/*
|======FUNÇÕES LISTA COM CABEÇA==================================================================================================|
| MODELO INICIO:                             |                                  FIM DE CÓDIGO:                                   |
|    celula* cabeca=malloc(sizeof(celula));  |   liberaLista(cabeca);                         |  free(cabeca);                   |
|    cabeca->prox = NULL;                    |   cabeca->prox = NULL; <---retulizar cabeça    |  cabeca=NULL;  <---Libera cabeça |
|================================================================================================================================|
*/
void liberaLista(celula*);     //libera a lista inteira após a cabeça. NÃO libera a cabeça. Entrada: (cabeça). Fazer cabeca->prox=NULL para reutilizar ou free(cabeça) 
void insere(int, celula*);     //insere uma célula exatamente APÓS a célula passada como parâmetro. Entrada: (valor_add, celula_anterior);
void insereFim(int, celula*);  //insere o valor no fim da lista(apontando para NULL). Entrada: (valor, cabeça)
void imprimeLista(celula*);    //Imprime a lista inteira. Entrada: (cabeça)


/*=======FUNÇÕES LISTA SEM CABEÇA=====================
|       ainda a serem implementadas       :)         |
====================================================*/

#endif