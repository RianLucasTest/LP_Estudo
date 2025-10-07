#include<stdio.h>
#include<stdlib.h>

int main(){
    float cap_ini, taxa, tempo, montante, juros, t_1;

    printf("Digite o capital inicial:\n");
    scanf("%f", &cap_ini);
    printf("Digite o tempo total da aplicacao(em anos)\n");
    scanf("%f", &tempo);

  for (float c_taxa = 5; c_taxa <= 10; c_taxa++){

    t_1 = 1;
    taxa = c_taxa /100;

    for(int cont = 1; cont <= tempo; cont++){
        t_1 = t_1 *(1 + taxa);
    }
    montante = cap_ini * t_1;
    juros = montante - cap_ini;

    printf("O juros e: %.2f\n", juros);
    }

    getchar();
    return 0;
}
