#include<stdlib.h>
#include<stdio.h>
#define VET 9

int main(){
    int vet[VET]={4, -5, 8, 10, -3, 9, 12, -6, -1}, i, simp=0, spar=0;

    for(i = 0; i < VET; i++){
        if(vet[i]%2 == 0){
            spar += vet[i];
        }
        else{
            simp += vet[i];
        }
    }
    printf("Os valores do vetor sao:\n");
    for(i = 0; i < VET; i++){
        printf("%4d -", vet[i]);
    }
    printf("\nA soma dos valores impares e: %d, e a dos valores pares e: %d\n", simp, spar);

    system("PAUSE");
    return 0;
}