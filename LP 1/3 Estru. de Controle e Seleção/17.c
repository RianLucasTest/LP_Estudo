#include<stdio.h>
#include<stdlib.h>

int Fatorial (int cont){
    int fat;
    fat = 1;
    for( ; cont > 0; cont--){
    fat = fat * cont;
    }
    return(fat);
}

int Potencia(int x, int expo){
    int result, cont_2;
    result = 1;
    for(cont_2 = 0; cont_2 < expo; cont_2++ ){
        result = result * x;
    }
    return(result);
}

int main(){
    int cont, x, n, x_n;
    double ex, fat_cont;
    ex = 0;

    printf("Digite o valor de x:\n");
    scanf("%d", &x);
    printf("Digite o valor de n:\n");
    scanf("%d", &n);

    ex = ex + 1;

    for(cont = 1; cont <= n; cont++){

        x_n = Potencia(x, cont);
        fat_cont = Fatorial(cont);
        ex = ex + (x_n / fat_cont );
        
        
    }

    printf("O valor de e^x e: %f\n", ex);

    

    system("PAUSE");
    return 0;
}