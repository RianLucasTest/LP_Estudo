#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float hip (float, float);

int main(){
    float cat1, cat2;

    printf("Digite o valor do cateto 1:\n");
    scanf("%f", &cat1);
    printf("Digite o valor do cateto 2:\n");
    scanf("%f", &cat2);

    printf("A hipotenusa e: %.2f\n", hip(cat1, cat2));
    return 0;
}

float hip(float cat1, float cat2){
    return sqrt((cat1*cat1)+(cat2*cat2));
}
