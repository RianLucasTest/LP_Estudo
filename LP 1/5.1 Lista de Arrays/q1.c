#include<stdlib.h>
#include<stdio.h>
#define VET 10

int main(){
    int vet[VET], i;
    printf("Digite %d numeros inteiros:\n", VET);
    for (i = 0; i < VET; i++){
        printf(">");
        scanf("%d", &vet[i]);
    }
    printf("OS numeros inseridos foram(em ordem inversa):\n");
    for(i = (VET-1); i >= 0; i--){
        printf("%5d\n", vet[i]);
    }
    system("PAUSE");
    return 0;
}