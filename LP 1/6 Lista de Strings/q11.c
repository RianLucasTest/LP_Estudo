#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 50

int main(){
  char nome[TAM];
  int i;
  
  printf("Insira o nome completo(preposicoes como 'da', 'de' em minusculo):\n");
  gets(nome);
  printf("A abreviatura desse nome e: ");

  if(isupper(nome[0])) printf("%c.", nome[0]);
  for(i = 0; nome[i] != '\0'; i++){
    if(nome[i] == ' '){
      if(isupper(nome[i+1])) printf("%c.", nome[i+1]);
    }
  }
  printf("\n");
  
    return 0;
}