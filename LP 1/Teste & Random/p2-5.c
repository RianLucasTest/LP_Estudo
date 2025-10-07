#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;

    printf("Digite o valor de n\n");
    scanf("%d", &n);
    n = n*n - 1;
    printf("O enesimo terma da sequencia e %d\n", n);

    return 0;
}