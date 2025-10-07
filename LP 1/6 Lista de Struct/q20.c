#include<stdlib.h>
#include<stdio.h>
typedef struct{
    double x;
    double y;
} Tponto;
Tponto Leponto(void);
short int InfoQuad(Tponto);

int main(){
    Tponto p;
    short int quad;

    p = Leponto();
    while(p.x != 0 || p.y != 0){
        quad = InfoQuad(p);
        if(!quad) printf("O ponto pertence a um eixo.\n");
        else printf("O ponto pertence ao %d quadrante.\n", quad);
        p = Leponto();
    }
    printf("  Fim da consulta! :)\n");
    
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
short int InfoQuad(Tponto ponto){
    int quad = 0;
    
    if(ponto.x == 0 || ponto.y == 0) return quad;
    if(ponto.x > 0){
        if(ponto.y > 0) quad = 1;
        else quad = 4;
    }
    else{
        if(ponto.y > 0) quad = 2;
        else quad = 3;
    }
    return quad;
}