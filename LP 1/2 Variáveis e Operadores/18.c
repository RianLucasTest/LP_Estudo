#include <stdio.h>
#include <stdlib.h>
//18.Idem ao exercício anterior, informe se for um triângulo equilátero.

int main(){
    int a, b, c;

    printf("Valor do lado a:\n");
    scanf("%i", &a);
    printf("Valor do lado b:\n");
    scanf("%i", &b);
    printf("Valor do lado c:\n");
    scanf("%i", &c);

    if (a == b && b == c){
        printf("O triangulo e equilatero\n");
    }
    else{
        printf("O triangulo nao e equilatero\n");
    }

    system("PAUSE");
    return 0;
}