#include<stdlib.h>
#include<stdio.h>
#define LIN 6
#define COL 6
#define TRAJ 6
void LerMatriz(int[][COL], int, int);
void PrintMat(int[][COL], int, int);

int main(){
    int dist[LIN][COL], i, rota[TRAJ], soma=0;
    printf("===================Cidades===========================");
    printf("\n1.(Caceres)\n2.(BBugres)\n3.(Cuiaba)\n4.(VGrande)\n5.(Tangara)\n6.(PLacerda)\n");
    printf("=====================================================\n");
    printf("\n->Preencha as distancias das cidades\n");
    LerMatriz(dist, LIN, COL);

    printf("\n->Preencha a rota de viagem com %d cidades\n", TRAJ);
    for(i = 0; i < TRAJ; i++){
        scanf("%d", &rota[i]);
    }

    int lin, col;
    for(i = 1; i < TRAJ; i++){
        lin = rota[i-1];
        col = rota[i];
        soma += dist[lin-1][col-1];
    }
    printf("\n-->A distancia total percorrida foi de %d\n\n", soma);

    system("PAUSE");
    return 0;
}
void LerMatriz(int MAT[][COL], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = i; j < col; j++){
            if(i == j){
                MAT[i][j] = 0;
                continue;
            }
            printf("  Cidade %d-%d: ", i+1, j+1);
            scanf("%d", &MAT[i][j]);
            MAT[j][i] = MAT[i][j];
        }
    }
}
void PrintMat(int mat[][COL], int lin, int col){
    int i, j;
    printf("   ");
    for(j = 0; j < col; j++){
        printf("%6d",j+1);
    }
    printf("\n");
    for(i = 0; i < lin; i++){
        printf("%3d",i+1);
        for(j = 0; j < col; j++){
            if(mat[i][j] == 9999) mat[i][j] = '\0';
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}