#include<stdlib.h>
#include<stdio.h>
#define lin 5
#define col 5

int main(){
    int i, j, mat[lin][col];
    
    printf("Preencha a matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(i == j){
                continue;
            }
            else if(i+j == lin-1){
                continue;
            }
            else if(mat[i][j] >= 0){
                continue;
            }
            else {
                mat[i][j] = 0;
            }
        }
    }

    system("PAUSE");
    return 0;
}

