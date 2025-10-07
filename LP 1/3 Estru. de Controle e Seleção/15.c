#include<stdio.h>
#include<stdlib.h>

//o codigo é confiavel
//porem so funciona ate o numero 12, pois o resultado de 13! ultrapassa o limite de bits para a variávil 'int'
//se usarmos float, o código calcula apenas até o valor de 13!, 
//após o numero 14 ele apresenta uma precisão de apenas 6 ou 7  dígitos corretos, porém o numero completo está errado.

int main(){
    float num;
    float fat;
    fat = 1;

    printf("Insira um numero para calcular o seu fatorial:\n");
        scanf("%f", &num);
        while (num <= 0){
            printf("Insira um numero para calcular o seu fatorial:\n");
            scanf("%f", &num);
        }

    for( ; num > 0; num--){
        
        fat *= num;
    }
    printf("O fatorial do numero inserido e: %.1f\n", fat) ;

    system("PAUSE");
    return 0;
}