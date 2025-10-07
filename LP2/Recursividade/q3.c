#include<stdio.h>
#include"funcoes.h"

int main(void){
  int n;
  printf("Insira o numero para exibir a soma de seus digitos: ");
  scanf("%d", &n);
  printf("Soma dos seus digitos = %u\n", soma_dig(n));
  return 0;
}