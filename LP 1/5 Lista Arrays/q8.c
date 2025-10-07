#include<stdlib.h>
#include<stdio.h>
#define TAM_V 40

int main(){
    int i, num[TAM_V];
    printf("Preencha com %d numeros (tecle 'enter' apos cada numero)\n", TAM_V);
    for(i = 1; i <= TAM_V; i++){
        scanf("%d", &num[i]);
    }
    printf("A lista de valores inserida foi:\n");
    for(i = 0; i < TAM_V; i++){
        printf("%8d\n", num[i]);
    }
    system("PAUSE");
    return 0;
}