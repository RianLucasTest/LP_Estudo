#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float Distancia(float, float, float, float);

int main(){
    float x1, y1, x2, y2, dist, disMed=0;
    int cont=0;
    char stop;

    while(stop != '0'){
        printf("Digite as coordenadas do 1 ponto(separadas por um 'enter'):\n");
        scanf("%f", &x1);
        scanf("%f", &y1);
        printf("Digite as coordenadas do 2 ponto(separadas por um 'enter'):\n");
        scanf("%f", &x2);
        scanf("%f", &y2);
        dist = Distancia(x1, y1, x2, y2);
        printf("A distancia entre os pontos e: %.2f\n", dist);
        cont++;
        disMed += dist;
        printf("'1' para continuar, '0' para finalizar\n");
        scanf(" %c", &stop);
    }
    disMed /= cont;
    printf("A distancia media foi de %.2f\n", disMed);

    system("PAUSE");
    return 0;
}

float Distancia(float x1, float y1, float x2, float y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}