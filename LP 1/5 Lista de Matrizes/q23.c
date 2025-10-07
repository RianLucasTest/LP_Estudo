#include<stdlib.h>
#include<stdio.h>
#define LIN  5
#define COL 5
void LerMatriz(int[][COL], int, int);
void PrintMat(int[][COL], int, int);

//superior j > i
//inferior j < i

int main(){
    int i, j, mat[LIN][COL], temp;

    LerMatriz(mat, LIN, COL);
    printf("\nA matriz digitada foi:\n");
    PrintMat(mat, LIN, COL);

    for(i = 0; i < LIN; i++){
        for(j = i; j < COL; j++){
            if(i == j) continue;
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;

        }
    }
    printf("\nNova matriz (diagonais invertidas):\n");
    PrintMat(mat, LIN, COL);

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