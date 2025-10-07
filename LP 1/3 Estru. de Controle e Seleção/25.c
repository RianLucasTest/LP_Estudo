#include<stdio.h>
#include<stdlib.h>

int main(){
    int num_conta, cont;
    float lim, saldo;
    
    for(cont = 0; cont < 3; cont++){
        printf("Insira o numero da conta:\n");
        scanf("%d", &num_conta);
        printf("Insira o limite antes da recessao:\n");
        scanf("%f", &lim);
        printf("Insira o saldo atual:\n");
        scanf("%f", &saldo);

        lim = lim / 2;

        if (saldo > lim){
            printf("O cliente de conta %d possui %.2f como novo limite e possui saldo excedente ao limite\n", num_conta, lim);
        }
        else{
            printf("O cliente de conta %d possui %.2f como novo limite e possui saldo nao excedente ao limite\n", num_conta, lim);
        }
    }

    system("PAUSE");
    return 0;
}