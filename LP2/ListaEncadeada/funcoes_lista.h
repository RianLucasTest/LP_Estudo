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
celula* insereRetorna(int x, celula* p); //Igual a função insere, MAS retorna ptr para o ultimo Nó adicionado
void insereFim(int, celula*);  //insere o valor no fim da lista(apontando para NULL). Entrada: (valor, cabeça)
void imprimeLista(celula*);    //Imprime a lista inteira. Entrada: (cabeça)
void vetEmLista(int*, int, celula*); //Converte um vetor numa Lista Encadeada(com cabeça). Entrada: (vetor, tamanho de vet, cabeça)
int* listaEmVet(int*, celula*);   //Converte uma Lista Encadeada em Vetor. Entrada:(ptr para tam,cabeça). Retorna vetor preenchido, tam modificado internamente
celula* buscaValor(int x, celula* p);  //Busca por valor. Entrada: (valor a ser encontrado, cabeca). Retorna ptr para celula que contem o valor
celula* buscaEndereco(celula* find, celula* p);  //Busca celula que aponta para endereco inserido e retorna ele. Entrada(celula a procurar, cabeca) NESSA ORDEM
void removeNo(int x, celula* p);   //Remove o no referente ao valor inserido. Entrada(valor a ser retirado, cabeca)
void insereOrdenado(int, celula*);  //Insere Nó em ordem crescente(ou decrescente). Entrada: (valor, cabeca)
void bubbleLista(int, celula*); //BubbleSort em lista. Entrada: (cabeca)


/*=======FUNÇÕES LISTA SEM CABEÇA=====================
|       ainda a serem implementadas       :)         |
====================================================*/

#endif