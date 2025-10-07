
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define QTD 4
typedef struct{
    double x;
    double y;
} Tponto;
void Leponto(Tponto[]);
double Dist(Tponto, Tponto);
void Ordena(double[], int);
int VeriQuad(double[]);

int main(){
    Tponto p[QTD];
    double dists[6];
    int i, j, cont;

    Leponto(p);

    //calcula todas as 6 distancias possiveis p/ 4 pontos
    for(i = 0, cont = 0; i < QTD-1; i++){
        for(j = i+1; j < QTD; j++, cont++){
            dists[cont] = Dist(p[i], p[j]);
        }
    }
    Ordena(dists, 6);
    for(i = 0; i < QTD; i++){
        printf("-> Ponto %d: (%.2lf, %.2lf)\n", i+1, p[i].x, p[i].y);
    }
    if(VeriQuad(dists)){
        printf("Os pontos formam um quadrado.\nArea do quadrado = %.2lf\n", (dists[0]*dists[0]));
    }
    else{
        printf("Os pontos nao formam um quadrado\n");
    }
    
    system("PAUSE");
    return 0;
}
void Leponto(Tponto pontos[]){
    for(int i = 0; i < QTD; i++){
        printf("===PONTO %d===\n", i+1);
        printf("Digite o x: ");
        scanf("%lf", &pontos[i].x);
        printf("Digite o y: ");
        scanf("%lf", &pontos[i].y);
    }
}
double Dist(Tponto a, Tponto b){
    return (sqrt(((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y))));
}
void Ordena(double vet[], int qtd_ele){
    int i, j;
    double temp;
    for(i = 0; i < qtd_ele; i++){
        for(j = 0; j < (qtd_ele-1-i); j++){
            if(vet[j] > vet[j+1]){
                temp =  vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}
int VeriQuad(double dist[]){
    //Ultimos 2 = Maiores = Diagonais
    //4 primeiros = Menores = Lados
    if( dist[0] == dist[1] &&
        dist[1] == dist[2] &&
        dist[2] == dist[3] &&
        dist[4] == dist[5] &&
        dist[4] > dist[0]){
        return 1;
    }
    return 0;
}

