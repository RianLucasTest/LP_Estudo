#include<stdio.h>
#include"FUNCOES.H"
void LerMatriz(int lin, int col, int[][col]);
void PrintMat(int lin, int col, int[][col]);
int Maior(int, int);

int Maior(int x1, int x2){
    if(x1 > x2)
        return x1;
    else
        return x2;
}

void LerMatriz(int lin, int col, int MAT[][col]){
    int i, j;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &MAT[i][j]);
        }
    }
}

void PrintMat(int lin, int col, int MAT[][col]){
    int i, j;

    printf("   ");
    for(j = 0; j < col; j++){
        printf("%6d",j);
    }
    printf("\n");
    for(i = 0; i < lin; i++){
        printf("%3d",i);
        for(j = 0; j < col; j++){
            printf("%6d", MAT[i][j]);
        }
        printf("\n");
    }
}
