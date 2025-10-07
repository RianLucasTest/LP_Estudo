#include<stdlib.h>
#include<stdio.h>
#define TAM_V 20
#define GER TAM_V*2

int main(){
    int i, par[TAM_V], impar[TAM_V], geral[GER], p, imp;
    
    printf("Preencha a primeira lista com %d numeros (tecle 'enter' apos cada numero)\n", TAM_V);
    for(i = 0; i < TAM_V; i++){
        scanf("%d", &par[i]);
    }

    printf("Preencha a segunda lista com %d numeros (tecle 'enter' apos cada numero)\n", TAM_V);
    for(i = 0; i < TAM_V; i++){
        scanf("%d", &impar[i]);
    }
    for(i = 0, p = 0, imp = 0; i < GER; i++){
        if(i%2 == 0){
            geral[i] = par[p];
            p++;
        }
        else{
            geral[i] = impar[imp];
            imp++;
        }
    }
    printf("Substituicao:\nPosicoes Pares -> Primeira lista\nPosicoes Impares -> Segunda lista\n");
    for(i = 0; i < GER; i++){
        printf("%8d\n", geral[i]);
    }
    
    system("PAUSE");
    return 0;
}