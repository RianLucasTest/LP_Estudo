#include<stdlib.h>
#include<stdio.h>
#define T_VET 16

int main(){
    int num[T_VET], i, troca[T_VET/2];
    printf("Preencha com %d numeros (tecle 'enter' apos cada numero)\n", T_VET);
    for(i = 0; i < T_VET; i++){
        scanf("%d", &num[i]);
    }
    for(i = 0; i < T_VET/2; i++){
        troca[i] = num[i];
    }
    for(i = 0; i < T_VET/2; i++){
        num[i] = num[i+T_VET/2];
    }

    for(i = 0; i < T_VET/2; i++){
        num[i+T_VET/2] = troca[i];
    }

    printf("Posicao\t\tValor\n");
    for(i = 0; i < T_VET; i++){
        printf("%d\t\t%d\n", i, num[i]);
    }

    system("PAUSE");
    return 0;
}