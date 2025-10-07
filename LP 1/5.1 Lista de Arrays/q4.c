#include<stdlib.h>
#include<stdio.h>
#define VET 10

int main(){
    int num[VET], i;
    printf("Insira %d numeros:\n", VET/2);
    for(i = 0; i < VET/2; i++){
        scanf("%d", &num[i]);
    }
    printf("Insira mais %d numeros:\n", VET/2);
    for(i = (VET/2); i < VET; i++){
        scanf("%d", &num[i]);
    }

    for(i = 0; i < VET/2; i++){
        printf("%d | %d | ", num[i], num[i + VET/2]);
    }
    printf("\n");

    system("PAUSE");
    return 0;
}