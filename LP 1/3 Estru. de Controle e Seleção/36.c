#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float Potencia(int x, int expo){
    int result, cont_2;
    result = 1;
    for(cont_2 = 0; cont_2 < expo; cont_2++ ){
        result = result * x;
    }
    return(result);
}

int main() {
    int n;
    float x_res, cont, x, serie_s;
    serie_s = 0;

    printf("Digite o valor de x:\n");
    scanf("%f", &x);
    printf("Digite o valor de n:\n");
    scanf("%d", &n);

    serie_s = serie_s + log(x);

    for(cont = 1; cont < n; cont++){

        x_res = Potencia(x, cont);
        serie_s = serie_s + (x_res / cont);
    }

    printf("O valor aproximado de S e: %f\n", serie_s);

    system("PAUSE");
    return 0;
}