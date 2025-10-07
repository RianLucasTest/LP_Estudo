#include<stdio.h>
#include<stdlib.h>

int main(){
    float mbronze, custot=0;
    
    printf("Digite a massa de bronze desejada (em kg)\n");
    scanf("%f", &mbronze);

    custot = (0.67 * mbronze * 23 ) + (0.33 * mbronze * 380 );

    printf("O custo total foi de %.2f\n", custot);

    return 0;
}