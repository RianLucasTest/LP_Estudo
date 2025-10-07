#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, prod;
    prod = 1;

    for(num = 1; num <= 15; num+= 2){
        prod = prod * num;
    }
    printf("O produto dos numeros impares de 1 a 15 e: %d\n", prod);

    system("PAUSE");
    return 0;
}