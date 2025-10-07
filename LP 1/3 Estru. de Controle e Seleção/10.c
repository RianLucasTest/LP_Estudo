#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, a1, a2, a3, a4;

    printf("Digite um numero de 5 algarismos:\n");
    scanf("%d", &num);
    while(num > 99999 || num < 10000){
        printf("O numero precisa ter 5 algarismos. Digite novamente:\n");
        scanf("%d", &num);
    }
    a1 = num / 10000;
    num = num % 10000;
    a2 = num / 1000;
    num = num % 100;
    a3 = num / 10;
    a4 = num % 10;

    if (a1 == a4){
        if(a2 == a3){
            printf("O numero e um palindromo\n");
        }
        else{
            printf("O numero nao e palindromo\n");
        }
    }
    else{
        printf("O numero nao e um palindromo\n");
    }

    system("PAUSE");
    return 0;
}