#include<stdlib.h>
#include<stdio.h>
#define LIN 10
#define COL 10
void LerMatriz(int[][COL], int, int);
void PrintMat(int[][COL], int, int);

int main(){
    int i, j, mat1[LIN][COL], mat2[LIN][COL], temp;

    printf("Preencha a matriz 1:\n");
    LerMatriz(mat1, LIN, COL);
    printf("Matriz inserida:\n");
    PrintMat(mat1, LIN, COL);

    printf("Preencha a matriz 2:\n");
    LerMatriz(mat2, LIN, COL);
    printf("Matriz inserida:\n");
    PrintMat(mat2, LIN, COL);


    for(i = 0; i < LIN; i++){
        for(j = i; j < COL; j++){
            if(i == j) continue;
            temp = mat2[i][j];
            mat2[i][j] = mat1[j][i];
            mat1[j][i] = temp;

        }
    }
    printf("Troca da diagonal inferior da primeira com a superior da segunda\n");
    printf("\nNova matriz 1:\n");
    PrintMat(mat1, LIN, COL);
    printf("\nNova matriz 2:\n");
    PrintMat(mat2, LIN, COL);


    system("PAUSE");
    return 0;
}

void LerMatriz(int MAT[][COL], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &MAT[i][j]);
        }
    }
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