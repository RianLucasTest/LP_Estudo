
#include<stdlib.h>
#include<stdio.h>
#define lin 20
#define col 20
void LerMatriz(int[][col]);

int main(){
    int i, j, k, h, mat1[lin][col], mat2[lin][col], achou;
    
    printf("Preencha a matriz 1:\n");
    LerMatriz(mat1);
    
    printf("Preencha a matriz 2:\n");
    LerMatriz(mat2);

    printf("Valores da 1 que ocorrem na 2 matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            achou = 0;
            for(k = 0; k < lin; k++){
                for(h = 0; h < col; h++){
                    if(mat1[i][j] == mat2[k][h]){
                        printf("   %4d", mat1[i][j]);
                        achou = 1;
                        break;
                    }
                }
                if(achou) break;
            }
        }
    }
    printf("\n");
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