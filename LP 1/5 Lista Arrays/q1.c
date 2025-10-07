#include<stdlib.h>
#include<stdio.h>
#define TAM_VET 4

int main(){
    int num[TAM_VET], i, x, y;
    printf("Preencha com %d numeros (tecle 'enter' apos cada numero)\n", TAM_VET);
    for(i = 0; i < TAM_VET; i++){
        scanf("%d", &num[i]);
    }
    printf("Digite duas posicoes na lista x e y (separados por um 'enter') que vao de 0 ate %d\n", TAM_VET-1);
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Os numeros associados a essas posicoes sao\nx\t%d\ny\t%d\n", num[x], num[y]);

    system("PAUSE");
    return 0;
}