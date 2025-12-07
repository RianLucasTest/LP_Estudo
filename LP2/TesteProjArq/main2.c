#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fun_arq.h"

int qtdProdutos=0;
void gera_relatorio();


int main(void){
    Tproduto* vetor = NULL;

    vetor = resgata_vet("produtos.dat");

    //vetor = cadastrarProduto(vetor);
    listarProdutos(vetor);

    grava_vet(vetor, "produtos.dat");

   
    free(vetor);
    return 0;
}
