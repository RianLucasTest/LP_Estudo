#include<stdlib.h>
#include<stdio.h>
#define TAM_VET 10

int main(){
    int imp[TAM_VET], i, impar=1;
    for(i = 0; i < TAM_VET; i++){
        imp[i] = impar;
        impar += 2;
    }
    printf("Posicao\t\tNumero\n");
     for(i = 0; i < TAM_VET; i++){
        printf("%d\t\t%d\n", i, imp[i]);
    }


    system("PAUSE");
    return 0;
}