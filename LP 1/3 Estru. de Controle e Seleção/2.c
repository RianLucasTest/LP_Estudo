#include<stdio.h>
#include<stdlib.h>

int main(){
    int NumConta;
    float SaldoDev, Cobranca, Credito, LimCred, SaldoNew;
    NumConta = 1;

    while (NumConta != 0){
        printf("Digite o numero da conta (0 para finalizar):\n");
        scanf("%d", &NumConta);

        if (NumConta == 0){
            break;
        }
        printf("Digite o saldo devedor inicial:\n");
        scanf("%f", &SaldoDev);
        printf("Digite o total de cobrancas:\n");
        scanf("%f", &Cobranca);
        printf("Digite o total de creditos:\n");
        scanf("%f", &Credito);
        printf("Digite o limite de credito:\n");
        scanf("%f", &LimCred);
        SaldoNew = SaldoDev + Cobranca - Credito;

        if (SaldoNew > LimCred){
            printf("\tConta: %d\n\tLimite de credito: %.2f\n\tSaldo devedor: %.2f\n\tLimite de Credito excedido\n\n", NumConta, LimCred, SaldoNew);
        }
    }

    system("PAUSE");
    return 0;
}