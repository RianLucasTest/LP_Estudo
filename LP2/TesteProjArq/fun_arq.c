#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fun_arq.h"


//recebe vetor a ser gravado + o nome do arquivo a ser aberto + ptr para variável de tamanho do vetor
//Devolve o vetor resgatado do arquivo
void grava_vet(Tproduto* vet, const char* arq, int* tam){
    
    FILE* file=fopen(arq, "wb");
    if(file==NULL){
        printf("ERRO ao gravar arquivo binário!\n");
        return;
    }

    for(int i=0; i<(*tam); i++){
        fwrite((vet+i), sizeof(Tproduto), 1, file);
    }
    
    fclose(file);
}

//recebe o nome do arquivo a ser aberto + ponteiro para variável de tamanho do vetor
//Devolve o vetor resgatado do arquivo
Tproduto* resgata_vet(const char* arq, int* tam){
    Tproduto* vet = NULL;
    Tproduto aux;

    FILE* file=fopen(arq, "ab");  //abre e fecha arquivo com apend
    if(file==NULL){
        printf("ERRO ao abrir/criar arquivo binário!\n");
        return NULL;
    }
    fclose(file);  //garante que o arquivo sempre exista


    file=fopen(arq, "rb");
    if(file==NULL){
        printf("ERRO ao gravar arquivo binário!\n");
        return NULL;
    }

    while(fread(&aux, sizeof(Tproduto), 1, file)){

        Tproduto* temp = realloc(vet, ((*tam)+1)*sizeof(Tproduto));
        if(temp == NULL){
            printf("Erro ao alocar memoria\n");
            free(vet);
            fclose(file);
            return NULL;
        }
        vet = temp;

        *(vet+(*tam)) = aux;
        (*tam)++;
    }
    
    fclose(file);
    return vet;
}

Tproduto* cadastrarProduto(Tproduto* produtos)
{   char nome_temp[50];
    while (1)
    {

        printf("Insira o nome do produto %d (Digite ""0"" para terminar o cadastro): ", qtdProdutos+1);

        fgets(nome_temp, 50, stdin);
        nome_temp[strcspn(nome_temp, "\n")] = 0;

        if (strcmp(nome_temp, "0") == 0) //se o digitador for 0, sai
        {
            break;
        }
        
        Tproduto* temp = realloc(produtos, (qtdProdutos+1)*sizeof(Tproduto));
        if(temp == NULL){
            printf("Alocação de vetor inválida: Encerrando Programa\n");
            return NULL;
        }
        produtos = temp;
        
        strcpy(produtos[qtdProdutos].nome, nome_temp);
        

        printf("Insira o preco do produto(por @): ");
        scanf("%f", &produtos[qtdProdutos].preco);
        while (getchar() != '\n');
        printf("Insira a quantidade do produto: ");
        scanf("%d", &produtos[qtdProdutos].quantidade);
        
        while (getchar() != '\n');
        produtos[qtdProdutos].id = qtdProdutos + 1;
        qtdProdutos++; //incrementa qtd de produtos

        printf("\n");
    }
    return produtos;
}

void listarProdutos(Tproduto produtos[]){

    printf("Listagem de produtos.\n");
    printf("_______________________\n");
    for (int i = 0; i < qtdProdutos; i++)
    {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        
        if (produtos[i].quantidade == 0)
            printf("ESGOTADO.\n");
        else
        printf("Quantidade: %d\n", produtos[i].quantidade);
        
        printf("_______________________\n");
    }
}

