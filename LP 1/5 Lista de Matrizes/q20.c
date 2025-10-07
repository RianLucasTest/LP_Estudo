#include<stdio.h>
#include<stdlib.h>
#define lin 20
#define col 20
int main(){
    int mat[lin][col], i, j, find;
    printf("Preencha a matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Digite um valor para procurar na matriz: ");
    scanf("%d", &find);

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] == find){
                printf("O valor esta na linha %d, coluna %d\n", i, j);
                break;
            }
        }
    }

    system("PAUSE");
    return 0;
}
