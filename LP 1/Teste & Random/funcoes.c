#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int main(){
    char nomeFuncao[TAM];
    char linha[TAM];
    FILE *arquivo;
    int exibir = 0;

    printf("======Opcoes======\n");
    printf("\t->PRINT\n\t->LERMATRIZ\n\t->PREENCHEMATRIZ\n\t->BUBBLESORT\n\t->MEDIA\n\t->MEDIANA\n\t->BUBBLESTR\n");
    printf("Digite o nome da funcao que deseja exibir (ex: somaMatriz): ");
    fgets(nomeFuncao, TAM, stdin);
    nomeFuncao[strcspn(nomeFuncao, "\n")] = '\0'; // remove o \n

    arquivo = fopen("funcoes.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(fgets(linha, TAM, arquivo) != NULL){
        // Verifica se encontrou a marcação da função
        if (strstr(linha, "/*") != NULL && strstr(linha, nomeFuncao) != NULL){
            exibir = 1;
        }
        // Se encontrar outra marcação, para de exibir
        else if (strstr(linha, "/*") != NULL && exibir == 1){
            break;
        }
        // Se deve exibir, imprime a linha
        if (exibir){
            printf("%s", linha);
        }
    }

    if (!exibir){
        printf("Funcao '%s' nao encontrada.\n", nomeFuncao);
    }
    printf("\n");
    fclose(arquivo);
    system("PAUSE");
    return 0;
}
