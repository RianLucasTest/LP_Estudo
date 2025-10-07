#include <stdio.h>
#include <stdlib.h>

int main() {
    double pi, impar;
    int cont;
    pi = 0;
    impar = 1;

    printf("Qtd. Termos\tPi\n");

    for(cont = 1; cont <= 10; cont++){

        if(cont%2 == 1){
            pi = pi + (4/impar);
        }
        if (cont%2 == 0){
            pi = pi - (4/impar);
        }
        impar = impar + 2;
    printf("%f\t%d\n", pi, cont);
    }

    system("PAUSE");
    return 0;
}