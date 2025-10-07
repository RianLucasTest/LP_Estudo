#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 50
#define QTD 3

int main(){
    char nome[QTD][TAM], temp[TAM];
    int i, j;

    for(i = 0; i < QTD; i++){
        printf("Insira o %d nome: ", i+1);
        gets(nome[i]);
    }

    for(i = 0; i < QTD-1; i++){
        for(j = i+1; j < QTD; j++){
            if(strcmp(nome[i], nome[j]) > 0){
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp); 
            }
        }
    }
    printf("Nomes em ordem alfabetica:\n");
    for(i = 0; i < QTD; i++){
        puts(nome[i]);
    }
    printf("\n");
    

    system("PAUSE");
    return 0;
}