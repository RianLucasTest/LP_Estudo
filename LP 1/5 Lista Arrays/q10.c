#include<stdlib.h>
#include<stdio.h>
#define TAM_V 5

int main(){
    int i, num[TAM_V];
    printf("Digite os caracteres de um numero\n");
    for(i = 0; i < TAM_V; i++){
        scanf("%d", &num[i]);
    }
    printf("O numero digitado foi:\n");
    for(i = 0; i < TAM_V; i++){
        printf("%d", num[i]);
    }
    printf("\n");
    
    
    system("PAUSE");
    return 0;
}
