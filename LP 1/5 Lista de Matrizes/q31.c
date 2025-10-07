#include<stdlib.h>
#include<stdio.h>
#define lin 4
#define col 4
void PrintMat(char[][col], int, int);

int main(){
    int i, j;
    char mat[lin][col];
    printf("digite\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            mat[i][j] = getchar();
        }
        getchar();
    }

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] != mat[lin-i-1][col-j-1]){
                printf("Nao e palindromo\n");
                system("PAUSE");
                return 0;
            }
        }
    }

    for(j = 0; j < lin; j++){
        for(i = 0; i < col/2; i++){
            if(mat[i][j] != mat[lin-i-1][col-j-1]){
                printf("Nao e palindromo\n");
                system("PAUSE");
                return 0;
            }
        }
    }
    printf("E palindromo\n");


    system("PAUSE");
    return 0;
}