#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, soma;
    soma = 0;

    for(num = 2; num <= 30; num+= 2){
        soma = soma + num;
    }
    printf("A soma dos numeros pares de 2 a 30 e: %d\n", soma);

    system("PAUSE");
    return 0;
}