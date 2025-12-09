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

//recebe vetor a ser gravado + o nome do arquivo a ser aberto + ptr para variável de tamanho do vetor
//Devolve o vetor resgatado do arquivo
void grava_vet(Tproduto*, const char*, int*); 

//recebe o nome do arquivo a ser aberto + ponteiro para variável de tamanho do vetor
//Devolve o vetor resgatado do arquivo
Tproduto* resgata_vet(const char*, int*);

#endif