//Leia uma matriz 100 x 10 que se refere respostas de 10 questões de múltipla escolha, referentes a
//100 alunos. Leia também um vetor de 10 posições contendo o gabarito d e respostas que podem ser
//a, b, c ou d. Seu programa deverá comparar as respostas de cada candidato com o gabarito e emitir
//um vetor Resultado, contendo a pontuação correspondente.

#include<stdlib.h>
#include<stdio.h>
#define lin 100
#define col 10
void LerMatriz(char[][col]);
int Compara(int, char[][col], char[]);
//i - linha = aluno
//j - coluna = respostas

int main(){
    int i, result[lin];
    char resp[lin][col], gab[10];
    
    printf("Preencha com as respostas:\n");
    LerMatriz(resp);
    
    printf("Preencha o gabarito:\n");
    for(i = 0; i < 10; i++){
        scanf(" %c", &gab[i]);
    }

    for(i = 0; i < lin; i++){
        result[i] = Compara(i, resp, gab);
    }

    for(i = 0; i < lin; i++){
        printf("Aluno %d -> Acertos: %d\n", i+1, result[i]);
    }

    system("PAUSE");
    return 0;
}

int Compara(int codigo, char resp[][col], char gab[]){
    int cont=0;
    for(int i = 0; i < col; i++){
        if(resp[codigo][i] == gab[i]){
            cont++;
        }
    }
    return cont;
}



void LerMatriz(char MAT[][col]){
    int i, j;
    for(i = 0; i < lin; i++){
        printf("Aluno %d\n", i+1);
        for(j = 0; j < col; j++){
            scanf(" %c", &MAT[i][j]);
        }
    }
}