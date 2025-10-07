
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TIT 50
#define AUT 50
#define QTD 50
typedef struct{
    char nome[TIT];
    char autor[AUT];
    int pag;
} Tlivro;
Tlivro Add(void);
int Remove(Tlivro[], int);
void Lista(Tlivro[], int);
void Busca(Tlivro[], int);

int main(){
    int sel, total=0;
    Tlivro liv[QTD];
    printf("Vamos comecar o gerenciamento do acervo!\n");
    printf("Selecione uma opcao:\n\n   1. Adicionar Livro\n   2. Buscar Livro\n   3. Apagar Livro\n   4. Listas Acervo\n   5. Sair\n\nSelecione: ");
    scanf("%d", &sel);

    while(sel != 5){
        switch (sel){
            case(1): //add
                liv[total] = Add();
                total++;
                break;
            case(2): //busca
                Busca(liv, total);
                break;
            case(3): //apagar
                total = Remove(liv, total);
                total--;
                break;
            case(4): //lista
                Lista(liv, total);
                break;
            default:
                printf("ERRO: Opcao invalida!\n");
                break;
        }
        printf("Selecione uma opcao:\n\n   1. Adicionar Livro\n   2. Buscar Livro\n   3. Apagar Livro\n   4. Listas Acervo\n   5. Sair\n\nSelecione: ");
        scanf("%d", &sel);
    }
    printf("Fim do gerenciamento!\n");
    system("PAUSE");
    return 0;
}

Tlivro Add(void){
    Tlivro liv;
    printf("====Adicionar Livro====\n");
    fflush(stdin);
    printf("Titulo do livro: ");
    gets(liv.nome);
    printf("Autor do livro: ");
    gets(liv.autor);
    printf("Numero de paginas: ");
    scanf("%d", &liv.pag);
    return liv;
}
int Remove(Tlivro liv[], int tot){
    int rem, i;
    printf("Qual livro deseja excluir(insira o numero dele)?: ");
    scanf("%d", &rem);
    if(rem < 1 || rem > tot){
        printf("ERRO: Livro nao existe\n");
        return tot;
    }
    rem--; //Na lista ele exibe cada livro como 'indice+1'
    liv[rem].nome[0] = '\0';
    liv[rem].autor[0] = '\0';
    liv[rem].pag = 0;
    for(i = rem; i < tot-1; i++){
        liv[i] = liv[i+1];
    }
    return tot-1;
}
void Lista(Tlivro livs[], int tot){
    int i;
    printf("Total de livros: %d\n", tot);
    for(i = 0; i < tot; i++){
        printf("====Livro %d====\n", i+1);
        printf("   Titulo: %s\n   Autor: %s\n   Num. de paginas : %d\n", 
        livs[i].nome, livs[i].autor, livs[i].pag);
    }
}
void Busca(Tlivro livs[], int tot){
    char find[TIT];
    int i, verif=1;
    printf("Insira o nome do livro que deseja buscar: ");
    fflush(stdin);
    gets(find);
    for(i = 0; i < tot; i++){
        if(strcmp(find, livs[i].nome) == 0){
            verif = 0;
            break;
        }
    }
    if(!verif){
        printf("O livro foi encontrado e esta na posicao %d!\n", i+1);
    }
    else{
        printf("Livro nao encontrado no acervo :(\n");
    }
}