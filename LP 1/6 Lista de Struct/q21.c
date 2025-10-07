#include<stdlib.h>
#include<stdio.h>
#include<math.h>
typedef struct{
    double x;
    double y;
} Tponto;
Tponto Leponto(void);
double Dist(Tponto, Tponto);

int main(){
    Tponto p, q;

    printf("PONTO 1\n");
    p = Leponto();
    printf("PONTO 2\n");
    q = Leponto();
    printf("A distancia entre os pontos inseridos e de %.2lf\n", Dist(p,q));
    
    system("PAUSE");
    return 0;
}
Tponto Leponto(void){
    Tponto ponto;
    printf("Digite o x: ");
    scanf("%lf", &ponto.x);
    printf("Digite o y: ");
    scanf("%lf", &ponto.y);
    return ponto;
}
double Dist(Tponto a, Tponto b){
    return (sqrt(((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y))));
}