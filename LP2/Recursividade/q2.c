#include<stdio.h>
#include"funcoes.h"

int main(void){
  int n;
  
  printf("Insira o inicio da contagem: ");
  scanf("%d", &n);
  contagem_regressiva(n);
  
  return 0;
}