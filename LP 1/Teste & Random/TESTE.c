#include <stdio.h>
#include <stdlib.h>

int Menor(int, int);

int main() {
    int n1, n2, m;
    printf("digite o 1 numero\n");
    scanf("%d", &n1);
    printf("digite outro numero\n");
    scanf("%d", &n2);

    m = Menor(n1, n2);

    printf("Menor e %d\n", m);

    system("PAUSE");
    return 0;
}

int Menor(int x1, int x2){
    int menor;
    if(x1<x2){
        menor = x1;
    }
    else{
        menor = x2;
    }
    return menor;
}