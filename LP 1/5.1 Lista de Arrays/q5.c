#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define VET 8

int main(){
    int num[VET], i, maior=0, menor=0;
    srand(time(NULL));
    for(i = 0; i < VET; i++){
        num[i] = rand() % 2001;
        printf("->%d\t", num[i]);
    }
    printf("\n");
    for(i = 0; i < VET; i++){
        if(num[i] < 1000){
            menor++;
        }
        else{
            maior++;
        }
    }
    printf("Houve %d numeros maiores que 1000 e %d menores\n", maior, menor);


    system("PAUSE");
    return 0;
}