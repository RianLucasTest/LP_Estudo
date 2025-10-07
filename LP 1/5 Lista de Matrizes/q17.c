#include<stdio.h>
#include<stdlib.h>
#define lin 5
#define col 5
void PrintMat(int[][col], int, int);

int main(){
    int mat[lin][col]={0}, i, j;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(i == j) {
                mat[i][j] = 1;
            }
        }
    }
    PrintMat(mat, lin, col);

    system("PAUSE");
    return 0;
}

void PrintMat(int mat[][col], int LIN, int COL){
    int i, j;
    printf("   ");
    for(j = 0; j < COL; j++)
        printf("%6d",j);
    printf("\n");
    for(i = 0; i < LIN; i++){
        printf("%3d",i);
        for(j = 0; j < COL; j++)
            printf("%6d", mat[i][j]);
        printf("\n");
    }
}