#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define QTD 5
#define TAM 30

int main(){
    char nome[QTD][TAM], temp[TAM];
    int i, j;
    printf("Insira os nomes a serem organizados:\n");
    for(i = 0; i < QTD; i++){
        printf("\n-> ");
        gets(nome[i]);
        fflush(stdin);
    }

    for(i = 0; i < QTD; i++){
        for(j = 0; j < (QTD-1-i); j++){
            if(strcmp(nome[j], nome[j+1]) > 0){
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j+1]);
                strcpy(nome[j+1], temp);
            }
        }
    }
    printf("LISTA EM ORDEM:\n");
    for(i = 0; i < QTD; i++){
        printf(" -> %s\n", nome[i]);
    }

    system("PAUSE");
    return 0;
}
void OrdemAlfa(int[][TAM], int, int);
void OrdemAlfa(int vet[][TAM], int qtd_str, int tam_str){
    int i, j;
    char temp[tam_str];
    for(i = 0; i < qtd_str; i++){
        for(j = 0; j < (qtd_str-1-i); j++){
            if(strcmp(vet[j], vet[j+1]) > 0){
                strcpy(temp, vet[j]);
                strcpy(vet[j], vet[j+1]);
                strcpy(vet[j+1], temp);
            }
        }
    }
}