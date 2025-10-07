#include <stdio.h>
#include <stdlib.h>
//14. Elabore um programa que permita a entrada de dois valores, x e y, troque seus valores entre si e
//então exiba os novos resultados.

int main(){
    int x, y, c;
    c = 0;

    printf("Digite o valor de x:\n");
    scanf("%i", &x);
    printf("Digite o valor de y:\n");
    scanf("%i", &y);

    c = x;
    x = y;
    y = c;

    printf("O novo x e %i e o novo y e %i\n", x, y);

    system("PAUSE");
    return 0;
    

}