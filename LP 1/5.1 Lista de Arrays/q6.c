#include<stdlib.h>
#include<stdio.h>
#define VET 15

int main(){
    int num[VET], i;
    printf("Insira %d numeros inteiros\n", VET);
    for(i = 0; i < VET; i++){
        scanf("%d", &num[i]);
    }
    printf("Valores impares inseridos:\n");
    for(i = 0; i < VET; i++){
        if(num[i]%2 != 0){
            printf("-> %5d\n", num[i]);
        }
    }
    system("PAUSE");
    return 0;
}