#include<stdlib.h>
#include<stdio.h>
#define T_V 5

int main(){ 
    int i, v1[T_V], j;
    printf("Preencha o Vetor 1\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v1[i]);
    }
    printf("Os valores que aparecem repetidos sao:\n");
    for(i = 0; i < T_V; i++){
        for(j = 0; j < T_V; j++){
            if(v1[i]== v1[j]){
                printf("%d\n", v1[i]);
            }
        }
    }


    system("PAUSE");
    return 0;
}