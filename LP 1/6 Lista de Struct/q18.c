#include<stdlib.h>
#include<stdio.h>
#define TAMA 100
typedef struct{
    int elem[TAMA];
    int tam;
    float media;
    float mediana;
    int max;
    int min;
} Tvetor;
void Ordena(int[], int);
float Media(int[], int);
float Mediana(int[], int);

int main(){
    Tvetor v;
    int i;

    printf("Insira a quantidade de elementos desejada (Max: 100)\n");
    scanf("%d", &v.tam);
    if(v.tam > TAMA || v.tam <= 0){
        printf("ERRO: Quantidade nao suportada:\n");
        return 0;
    }

    printf("Preencha o vetor:\n");
    for(i = 0; i < v.tam; i++){
        scanf("%d", &v.elem[i]);
    }
    Ordena(v.elem, v.tam);
    v.media = Media(v.elem, v.tam);
    v.mediana = Mediana(v.elem, v.tam);
    v.min = v.elem[0];
    v.max = v.elem[v.tam-1];

    printf("  Media: %.2f\n  Mediana: %.2f\n  Valor maximo: %d\n  Valor minimo: %d\n",
            v.media, v.mediana, v.max, v.min);

    system("PAUSE");
    return 0;
}

void Ordena(int vet[], int qtd_ele){
    int i, j, temp;

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
float Media(int vet[], int qtd_ele){
    int i;
    float soma=0;
    for(i = 0; i < qtd_ele; i++){
        soma += vet[i];
    }
    return (soma/qtd_ele);
}
float Mediana(int vet[], int qtd_ele){
    if(qtd_ele%2 == 0){
        return (vet[qtd_ele/2] + vet[(qtd_ele/2)-1])/2.0;
    }
    else{
        return vet[(qtd_ele-1)/2];
    }
}