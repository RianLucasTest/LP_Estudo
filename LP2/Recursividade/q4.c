#include<stdio.h>
#include"funcoes.h"

int main(void){
  int n1, n2;
  printf("Primeiro num: ");
  scanf("%d", &n1);
  printf("Segundo num: ");
  scanf("%d", &n2);
  printf("Mdc entre eles e igual a: %d\n", mdc(n1, n2));
  
  
  return 0;
}