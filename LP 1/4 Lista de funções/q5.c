#include<stdio.h>
#include<stdlib.h>

int Inverso(int);

int main(){
    int num;
    printf("Digite um numero:\n");
    scanf("%d", &num);
    printf("O numero invertido e: %d\n", Inverso(num));

    system("PAUSE");
    return 0;
}

int Inverso(int num){
    int dig=0, out=0;
    while(num > 0){
        dig = num % 10;
        num = num / 10;
        out = dig + (out * 10); 
    }
    return out;
}