#include<stdlib.h>
#include<stdio.h>
#define lin 5
#define col 2

int main(){
    int i, j;
    float lado[lin][col], area[lin];

    for(i = 0; i < lin; i++){
        area[i] = 1;
    }

    printf("Preencha a matriz (insira lado 1, lado 2, 'enter')\n");
    for(i = 0; i < lin; i++){
        printf("Triangulo %d: ", i);
        for(j = 0; j < col; j++){
            scanf("%f", &lado[i][j]);
        }
    }

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            area[i] *= lado[i][j];
        }
    }

    printf("Areas correspondentes a posicoes da matriz:\n");
    printf("Triangulo\tArea\n");
    for(i = 0; i < lin; i++){
        printf("%8d    %8.2f\n", i, area[i]);
    }

    system("PAUSE");
    return 0;
}