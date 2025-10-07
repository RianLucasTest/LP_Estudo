#include<stdlib.h>
#include<stdio.h>
#define T_V 4

int main(){ 
    int i, v1[T_V], v2[T_V], j, verif=0;
    printf("Preencha o Vetor 1\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v1[i]);
    }
    printf("Preencha o Vetor 2\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v2[i]);
    }
    system("PAUSE");
    return 0;
}