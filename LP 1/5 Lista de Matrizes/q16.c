#include<stdio.h>
#include<stdlib.h>
//#include<time.h>
#define lin 10
#define col 10
void LerMatriz(int[][col]);
void PrintMat(int[][col]);

int main(){
    int mat[lin][col], i, j, mlin, mcol, maior;
    //srand(time(NULL));

    printf("Preencha a matriz:\n");
    LerMatriz(mat);
    PrintMat(mat);

    maior = mat[0][0];
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] > maior){
                mlin = i;
                mcol = j;
                maior = mat[i][j];
            }
        }
    }
    printf("O maior valor se encontra na linha %d, coluna %d\n", mlin, mcol);

    system("PAUSE");
    return 0;
}

void LerMatriz(int MAT[][col]){
    int i, j;
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &MAT[i][j]);
        }
    }
}

void PrintMat(int mat[][col]){
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
