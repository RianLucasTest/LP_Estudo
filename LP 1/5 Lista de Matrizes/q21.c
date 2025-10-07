#include<stdlib.h>
#include<stdio.h>
#define lin 4
#define col 4
void PrintMat(int[][col]);
void Troca_L_C (int[][col], int, int);

int main(){
    int i, j, mat[lin][col];
    
    printf("Preencha a matriz\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    //Entrada: (nome, n° linha, n° coluna)
    //O código faz a correção de índice
    printf("Matriz Inserida:\n");
    PrintMat(mat);

    Troca_L_C(mat, 1, 4);

    printf("Matriz resultante (troca da 1 linha, por 4 coluna):\n");
    PrintMat(mat);

    system("PAUSE");
    return 0;
}
//line = Linha pra trocar
//colu = coluna pra trocar
//line-1 = Usuario digita 1 para 1° linha (indice 0)
//colu-1 = Usuario digita 4 para 4° coluna (indice 3)

void Troca_L_C (int MAT[][col], int line, int colu){
    int temp, j;
    for(j = 0; j < col; j++){
        temp = MAT[line-1][j];
        MAT[line-1][j] = MAT[j][colu-1];
        MAT[j][colu-1] = temp;
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
