#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float Distancia(float, float);

int main(){
    float x, y;
    int n;
    printf("Digite a quantidade de pontos que serao inseridos:\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Insira o valor do ponto (formato 'x y')\n");
        scanf("%f %f", &x, &y);
        printf("A distancia ate a origem e de: %.2f\n", Distancia(x, y));
    }
    system("PAUSE");
    return 0;
}

float Distancia(float x, float y){
    return sqrt(x*x + y*y);
}