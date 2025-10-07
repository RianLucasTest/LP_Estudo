#include <stdio.h>
#include <stdlib.h>

float Calcula_Taxa (float h_est){
     float ret_tax;

    if(h_est <= 3){
        ret_tax = 2;
    }
    else{
        if(h_est <= 24){
            ret_tax = 2 + (0.5 * (h_est - 3.00));
            if(ret_tax > 10){
                ret_tax = 10;
            }
        }
    }   
    return (ret_tax);


}

int main() {
    int n, cont;
    float h_est, taxa, h_tot, tax_tot;
    tax_tot = h_tot = 0;

    printf("Digite a quantidade de clientes:\n");
    scanf("%d", &n);

    for(cont = 1; cont <= n; cont++){
        printf("Digite a quantidade de horas que o cliente %d ficou estacionado\n", cont);
        scanf("%f", &h_est);

        taxa = Calcula_Taxa(h_est);
       
        h_tot = h_tot + h_est;
        tax_tot = tax_tot + taxa;

        if(cont == 1){
            printf("Carro\tHoras\tTaxa\n");
        }
        printf("%d\t%.2f\t%.2f\n", cont, h_est, taxa);
        if(cont == n){
            printf("TOTAL\t%.2f\t%.2f\n", h_tot, tax_tot);
        }

    }

    system("PAUSE");
    return 0;
}
