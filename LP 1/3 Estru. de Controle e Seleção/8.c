#include<stdio.h>
#include<stdlib.h>
//quadrado de asteriscos

int main(){
    int lado, cont1, cont2;

    printf("Insira o valor do lado:\n");
    scanf("%d", &lado);

    for(cont1 = 0; cont1 < lado; cont1++){
        for(cont2 = 0; cont2 < lado; cont2++){
            printf("*");
        }
        printf("\n");
    }


    system("PAUSE");
    return 0;
}