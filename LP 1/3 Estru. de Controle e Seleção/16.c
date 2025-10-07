#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, fibo, ult, temp, cont;
    ult = 0;
    fibo = 1;

    printf("Insira um valor de n positivo:\n");
        scanf("%d", &n);
    while (n < 0){
        printf("Insira um valor de n positivo:\n");
        scanf("%d", &n);
    }

    switch (n){
        case 1:
            printf("O termo %d da sequencia de fibonacci e 0\n", n);
            break;
        case 2:
            printf("O termo %d da sequencia de fibonacci e o 1\n", n);
            break;
        default:
            for(cont = 2; cont < n; cont++){
                temp = fibo;
                fibo = fibo + ult;
                ult = temp;
            }
            printf("O %d termo da sequencia de fibonacci e o %d\n", n, fibo);
            break;
    }

    system("PAUSE");
    return 0;
}