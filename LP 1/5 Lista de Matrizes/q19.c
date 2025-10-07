#include<stdio.h>
#include<stdlib.h>
#define lin 6
#define col 6
int main(){
    int mat[lin][col], i, j, cont=0;
    printf("Preencha a matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Valores maiores que 10:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] > 10){
                printf("%6d\n", mat[i][j]);
                cont++;
            }
        }
    }
    printf("Ha %d valores maiores que 10\n", cont);

    system("PAUSE");
    return 0;
}
