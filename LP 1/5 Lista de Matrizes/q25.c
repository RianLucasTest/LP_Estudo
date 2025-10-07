#include<stdlib.h>
#include<stdio.h>
#define lin 8
#define col 8
void PrintMat(int[][col]);


int main(){
    int i, j, mat[lin][col], d_p_maior, s_d_sec=0;

    printf("Preencha a matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    PrintMat(mat);

    //maior da diag. princ.
    d_p_maior = mat[0][0];
    for(i = 1; i < lin; i++){
        if(mat[i][i] > d_p_maior){
            d_p_maior = mat[i][i];
        }
    }
    
    for(i = 0; i < lin; i++){
        s_d_sec += mat[i][col-1-i];
    
    }
    printf("O maior termo da diagonal principal e: %d\nA soma dos elementos da diagonal secundaria e: %d\n", d_p_maior, s_d_sec);

    system("PAUSE");
    return 0;
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