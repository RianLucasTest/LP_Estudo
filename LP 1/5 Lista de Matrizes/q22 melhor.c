#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIN 8
#define COL 8
void PrintMat(int[][COL], int, int);
void PreencheM(int[][COL], int, int);

int main(){
    int mat[LIN][COL]={0}, i, j;
    srand(time(NULL));
    PreencheM(mat, LIN, COL);

    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++)
            if(j > i){mat[i][j] = 0;}
    }
    PrintMat(mat, LIN, COL);

    system("PAUSE");
    return 0;
}

void PrintMat(int mat[][COL], int lin, int col){
    int i, j;
    printf("   ");
    for(j = 0; j < col; j++)
        printf("%6d",j);
    printf("\n");
    for(i = 0; i < lin; i++){
        printf("%3d",i);
        for(j = 0; j < col; j++)
            printf("%6d", mat[i][j]);
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
