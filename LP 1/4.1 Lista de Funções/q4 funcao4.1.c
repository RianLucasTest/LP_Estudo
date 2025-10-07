#include<stdio.h>
#include<stdlib.h>

int Fibon(int);

int main(){
    int num;
    printf("Insira um numero:\n");
    scanf("%d", &num);
    Fibon(num);
    return 0;
}

int Fibon(int n){
    int f1, f2, fibo=0;
    f1 = 0;
    f2 = 1;
    while(fibo < n){
        fibo = f1 + f2;
        f1 = f2;
        f2 = fibo;
    }
    if((fibo-n) < (n-f1)){
        printf("O numero de fibonacci mais proximo do numero inserido e o %d\n", fibo);
    }
    if((n-f1) < (fibo-n)){
        printf("O numero de fibonacci mais proximo do numero inserido e o %d\n", f1);
    }
    if((n-f1) == (fibo-n)){
        printf("Os numeros de fibonacci %d e %d sao equidistantes ao numero inserido\n", f1, fibo);
        }
    return 0;
}
