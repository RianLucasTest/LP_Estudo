#include<stdlib.h>
#include<stdio.h>
#include"FUNCOES.H"
#define LIN 4
#define COL 4
void LerMatriz(int lin, int col, int[][col]);
void PrintMat(int lin, int col, int[][col]);
int Maior(int, int);

//q18_mat

int main(){
    int lin=LIN, col=COL;
    int i, j, mat1[lin][col], mat2[lin][col], maior[lin][col];
    printf("Preencha a 1 matriz (separe cada digito por 'enter')\n");
    LerMatriz(lin, col, mat1);

    printf("Preencha a 2 matriz (separe cada digito por 'enter')\n");
    LerMatriz(lin, col, mat2);
    
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            maior[i][j] = Maior(mat1[i][j], mat2[i][j]);
        }
    }
    printf("A matriz resultante dos maiores valores entre cada anterior e:\n");
    PrintMat(lin, col, maior);

    system("PAUSE");
    return 0;
}