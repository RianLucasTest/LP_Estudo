#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARQ "produtos.dat"
#define ARQ_IND "indices.txt"

int qtdProdutos=0;
typedef struct{
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Tproduto;

Tproduto* cadastrarProduto(Tproduto produto[]);
void listarProdutos(Tproduto produtos[]);
void grava_vet(Tproduto*);
Tproduto* resgata_vet(void);

int main(void){
    Tproduto* vetor = NULL;
    //vetor = cadastrarProduto(vetor);

    vetor = resgata_vet();
    listarProdutos(vetor);

   //grava_vet(vetor);

    free(vetor);
    return 0;
}

void grava_vet(Tproduto* vet){
    FILE* f_prod=fopen(ARQ, "wb");
    if(f_prod==NULL){
        printf("ERRO ao salvar dados em arquivo!\n");
        return;
    }

    FILE* f_ind = fopen(ARQ_IND, "w");
    if(f_ind==NULL){
        printf("ERRO ao salvar dados em arquivo!\n");
        return;
    }
    
    for(int i=0; i<qtdProdutos; i++){
        fwrite((vet+i), sizeof(Tproduto), 1, f_prod);
        fprintf(f_ind, "%d\n%s\n", (vet+i)->id, (vet+i)->nome);
    }

    fclose(f_prod);
    fclose(f_ind);

}

Tproduto* resgata_vet(void){
    Tproduto* vet = NULL;
    int i=0;
    Tproduto aux;

    FILE* f_prod=fopen(ARQ, "rb");
    if(f_prod==NULL){
        printf("ERRO ao salvar dados em arquivo!\n");
        return NULL;
    }

    while(fread(&aux, sizeof(Tproduto), 1, f_prod)){

        Tproduto* temp = realloc(vet, (qtdProdutos+1)*sizeof(Tproduto));
        if(temp == NULL){
            printf("EEro ao alocar memoria\n");
            free(vet);
            fclose(f_prod);
            return NULL;
        }
        vet = temp;

        *(vet+i) = aux;
        qtdProdutos++;
        i++; 

    }
    fclose(f_prod);
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

//