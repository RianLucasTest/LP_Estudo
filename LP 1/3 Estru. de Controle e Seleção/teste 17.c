#include<stdio.h>
#include<stdlib.h>

int main(){
    int cont, x, n, x_n;
    double ex, fat_cont;
    ex = 1;

    printf("Digite o valor de x:\n");
    scanf("%d", &x);
    printf("Digite o valor de n:\n");
    scanf("%d", &n);
    x_n = x;
    fat_cont = 1;

    for(cont = 1; cont <= n; cont++){
        fat_cont *= cont;
        ex = ex + (x_n / fat_cont );
        x_n *= x;
    }

    printf("O valor de e^x e: %f\n", ex);

    system("PAUSE");
    return 0;
}