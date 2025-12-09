#ifndef FUN_ARQ_H
#define FUN_ARQ_H

typedef struct{
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Tproduto;

extern int qtdProdutos;

Tproduto* cadastrarProduto(Tproduto produto[]);
void listarProdutos(Tproduto produtos[]);

//entrada: ptr void para o vetor, nome do arq a ser aberto, tamanho de cada elemento, tamanho do vetor
void grava_vet(void*, const char*, int, int*);

//entrada: nome do arq a ser aberto, tamanho de cada elemento, tamanho do vetor
//Devolve o vetor resgatado do arquivo
void* resgata_vet(const char*, int, int*);

#endif