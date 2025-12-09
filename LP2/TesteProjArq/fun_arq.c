#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fun_arq.h"


//entrada: ptr void para o vetor, nome do arq a ser aberto, tamanho de cada elemento, tamanho do vetor
void grava_vet(void* vet, const char* arq, int size_elem, int* tam){
    
    FILE* file=fopen(arq, "wb");
    if(file==NULL){
        printf("ERRO ao gravar arquivo binário!\n");
        return;
    }

    fwrite(vet, size_elem, (*tam), file);
    
    
    fclose(file);
}

//entrada: nome do arq a ser aberto, tamanho de cada elemento, tamanho do vetor
//Devolve o vetor resgatado do arquivo
void* resgata_vet(const char* arq, int size_elem, int* tam){
    void* vet = NULL;
    //Tproduto aux;

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

    while(1){
        char aux[size_elem];

        
        //casting para algo que tem 1 byte para usar aritmética
        if(fread(aux, size_elem, 1, file) != 1) break;

        void* temp = realloc(vet, ((*tam)+1)*size_elem);
        if(temp == NULL){
            printf("Erro ao alocar memoria\n");
            free(vet);
            fclose(file);
            return NULL;
        }
        vet = temp;

        for(int i=0; i<size_elem; i++){
            ((char*)vet)[*tam * size_elem + i] = aux[i];
        }

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

