#include<stdlib.h>
#include<stdio.h>
#define T_V 50

int main(){ 
    int i, v[T_V], temp, j;
    printf("Preencha o Vetor 1\n");
    for(i = 0; i < T_V; i++){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < T_V; i++){
        for(j = 0; j < (T_V-i-1); j++){
            if(v[j] == 0){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
       }
    }
    printf("O vetor final e:\n");
    for(i = 0; i < T_V; i++){
        printf("%d\n", v[i]);
    }

    system("PAUSE");
    return 0;
}