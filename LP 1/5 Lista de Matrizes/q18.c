#include<stdlib.h>
#include<stdio.h>
#define lin 4
#define col 4
void LerMatriz(int[][col]);
void PrintMat(int[][col]);
int Maior(int, int);

int main(){
    int i, j, mat1[lin][col], mat2[lin][col], maior[lin][col];
    printf("Preencha a 1 matriz (separe cada digito por 'enter')\n");
    LerMatriz(mat1);

    printf("Preencha a 2 matriz (separe cada digito por 'enter')\n");
    LerMatriz(mat2);
    
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            maior[i][j] = Maior(mat1[i][j], mat2[i][j]);
        }
    }
    printf("A matriz resultante dos maiores valores entre cada anterior e:\n");
    PrintMat(maior);

    system("PAUSE");
    return 0;
}

int Maior(int x1, int x2){
    if(x1 > x2)
        return x1;
    else
        return x2;
}

void LerMatriz(int MAT[][col]){
    int i, j;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &MAT[i][j]);
        }
    }
}

void PrintMat(int MAT[][col]){
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