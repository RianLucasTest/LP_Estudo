#include<stdio.h>
#include"funcoes.h"

int main(void){
  int vet[10]={1,2,3,4,5,6,7,8,9,10};
  int i, alvo;
  
  printf("Preencha o vetor: ");
  for(i=0; i<10; i++){
    printf("%d --> ", i);
    scanf("%d", &vet[i]);
  }
  printf("Qual numero deseja encontrar o indice?\n");
  scanf("%d", &alvo);
  
  
  bubble(vet, 10);
  
  
  printf("Indice de %d : %d\n", alvo, busca_bi(vet, 0, 10, alvo));
  
  
  
  return 0;
}