#include<stdlib.h>
#include<stdio.h>

unsigned long int Fatorial(int);

int main(){
    int num;
    printf("Insira um numero:\n");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        printf("Fatorial de %d = %ld\n", i, Fatorial(i));
    }

    system("PAUSE");
    return 0;
}

unsigned long int Fatorial(int num){
    unsigned long int result=1;
    for(int i=1; i<=num; i++){
        result *= i;
    }
    return result;
}