#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int bin, dig, n_deci, cont;
    cont = n_deci = 0;

    printf("Digite um numero binario:\n");
    scanf("%d", &bin);


    while(bin > 0){
        dig = bin % 10;
        bin = bin / 10;
        n_deci = n_deci + (dig * pow(2.0,cont));
        cont = cont + 1;
    }

    printf("O numero inserido na forma decimal e: %d\n", n_deci);

    system("PAUSE");
    return 0;
}