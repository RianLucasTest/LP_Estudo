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
void grava_vet(Tproduto*, const char*); //const char -> nome do arquivo a ser aberto
Tproduto* resgata_vet(const char*);

#endif