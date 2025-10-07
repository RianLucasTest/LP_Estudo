#include<stdio.h>
#include<string.h>
#include"funcoes.h"

int main(void){
  char str[50];
  int inicio, fim, call;
  
  printf("Insira uma string com menos de 50 caracteres: ");
  fgets(str, 50, stdin);
  str[strcspn(str, "\n")] = '\0';
  
  inicio = 0;
  fim = strlen(str)-1;
  
  inverte_str(str, inicio, fim);
  printf("String apos inversao: \n --> %s\n", str);
  
  return 0;
}