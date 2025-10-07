#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIN 10
#define COL 10
//TESTE UTILIZANDO PONTEIROS
int MAIOR (int[][COL], int, int, int*, int*);
void PrintMat(int[][COL], int, int);
void PreencheM(int[][COL], int, int);

int main(){
    int mat[LIN][COL], maior, mlin, mcol;

    printf("Preencha a matriz:\n");
    srand(time(NULL));
    PreencheM(mat, LIN, COL);

    PrintMat(mat, LIN, COL);
    maior = MAIOR(mat, LIN, COL, &mlin, &mcol);

    printf("O maior valor e: %d. e se encontra na linha %d, coluna %d\n", maior, mlin, mcol);

    system("PAUSE");
    return 0;
}

int MAIOR (int MAT[][COL], int lin, int col, int* MLIN, int* MCOL){
    int maior = MAT[0][0];
    for(int i = 0; i <lin; i++){
        for(int j = 0; j < col; j++){
            if(MAT[i][j] > maior){
                *MLIN = i;
                *MCOL = j;
                maior = MAT[i][j];
            }
        }
    }
    return maior;
}

void PrintMat(int mat[][COL], int lin, int col){
    int i, j;

    printf("   ");
    for(j = 0; j < col; j++){
        printf("%6d",j);
    }
    printf("\n");
    for(i = 0; i < lin; i++){
        printf("%3d",i);
        for(j = 0; j < col; j++){
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

void PreencheM(int mat[][COL], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = rand() % 100;
        }
    }
}
