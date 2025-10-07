#include<stdlib.h>
#include<stdio.h>
#define TAM_V 40

int main(){
    int num[TAM_V], i, cont_par=0;
    printf("Preencha com %d numeros (tecle 'enter' apos cada numero)\n", TAM_V);
    for(i = 0; i < TAM_V; i++){
        scanf("%d", &num[i]);
    }
    printf("Valores pares:\n");
    for(i = 0; i < TAM_V; i++){
        if(num[i]%2 == 0){
            cont_par++;
            printf("\t%d\n", num[i]);
        }
    }
    printf("Ha %d valores pares dentro do vetor\n", cont_par);


    system("PAUSE");
    return 0;
}