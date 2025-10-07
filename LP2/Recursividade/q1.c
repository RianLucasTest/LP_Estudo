#include<stdio.h>
#include"funcoes.h"

int main(void){
  int base, exp;
  printf("Insira a base: ");
  scanf("%d",  &base);
  printf("Insira o expoente: ");
  scanf("%d", &exp);
  printf("Resultado: %ld\n", potencia(base, exp));
  return 0;
}
