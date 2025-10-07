#include<stdlib.h>
#include<stdio.h>
#define LIN 50
#define COL 50
typedef struct{
    int ele[LIN][COL];
    int col;
    int lin;
} Tmatriz;
void PrintMat(int[][COL], int, int);
void LerMatriz(int[][COL], int, int);

int main(){
    Tmatriz a, b, ad, sub;
    int i,j;

    //Lê qtd de linhas e colunas 
    printf("  Limite da quantidade de linhas: %d.\n  Limite da quantidade de colunas: %d.\n", LIN, COL);
    printf("Insira a quantidade de linhas em A: ");
    scanf("%d", &a.lin);
    printf("Insira a quantidade de colunas em A: ");
    scanf("%d", &a.col);
    printf("Insira a quantidade de linhas em B: ");
    scanf("%d", &b.lin);
    printf("Insira a quantidade de colunas em B: ");
    scanf("%d", &b.col);

    //Verifica estouro de magnitude
    if(a.lin != b.lin || a.lin > LIN || b.lin > LIN){
        printf("ERRO: Operacao nao pode ser realizada (tamanho excede limite ou tamanhos diferntes)!\n");
        return 0;
    }
    if(a.col != b.col || a.col > COL || b.col > COL){
        printf("ERRO: Operacao nao pode ser realizada (tamanho excede limite ou tamanhos diferntes)!\n");
        return 0;
    }
    //Lê as matrizes
    printf("Preencha a matriz A:\n");
    LerMatriz(a.ele, a.lin, a.col);
    printf("Preencha a matriz B:\n");
    LerMatriz(b.ele, b.lin, b.col);
    
    //Realiza operações
    for(i = 0; i < a.lin; i++){
        for(j = 0; j < a.col; j++){
            ad.ele[i][j] = a.ele[i][j] + b.ele[i][j];
            sub.ele[i][j] = a.ele[i][j] - b.ele[i][j];
        }
    }
    ad.lin = a.lin;
    ad.col = a.col;
    sub.lin = a.lin;
    sub.col = a.col;

    //Exibe matrizes
    printf("A matriz resultante da soma de A+B e:\n");
    PrintMat(ad.ele, ad.lin, ad.col);
    printf("A matriz resultante da subtracao de A-B e:\n");
    PrintMat(sub.ele, sub.lin, sub.col);

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