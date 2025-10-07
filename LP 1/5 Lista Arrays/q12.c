#include<stdlib.h>
#include<stdio.h>
#define T_V 9

int main(){ 
    int i, v1[T_V], v2[T_V], v3[T_V], vfim[T_V];
    printf("Preencha o Vetor 1\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v1[i]);
    }
    printf("Preencha o Vetor 2\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v2[i]);
    }
    printf("Preencha o Vetor 3\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v3[i]);
    }
    for(i = 0; i < 3; i++){
        vfim[i] = v1[i];
    }
    for(i = 3; i < 6; i++){
        vfim[i] = v2[i];
    }
    for(i = 6; i < T_V; i++){
        vfim[i] = v3[i];
    }
    printf("O vetor resultante e:\n");
    for(i = 0; i < T_V; i++){
        printf("%5d - ", vfim[i]);
    }
    printf("\n");

    system("PAUSE");
    return 0;
}