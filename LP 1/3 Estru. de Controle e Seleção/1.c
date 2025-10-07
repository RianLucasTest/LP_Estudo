#include<stdio.h>
#include<stdlib.h>

int main (){
    float L, Km, Soma_Taxa, TaxRel, TaxGer, Cont;
    L = 1;

    while(L > 0){
        printf("Digite os litros consumidos (0 para finalizar):\n");
        scanf("%f", &L);
        if (L<= 0){
            break;
        }
        printf("Digite a quilometragem percorrida:\n");
        scanf("%f", &Km);
        TaxRel = Km / L; 
        Cont = Cont + 1;
        Soma_Taxa = Soma_Taxa + TaxRel;
        printf("A taxa Km/l desse tanque foi: %.2f\n", TaxRel);
    }

    TaxGer = Soma_Taxa / Cont;
    printf("A taxa total de Km/Litro foi: %.4f\n", TaxGer);

    system("PAUSE");
    return 0;
}