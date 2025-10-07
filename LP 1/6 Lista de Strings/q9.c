#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 50

int main(){
  char str[50];
  int i, pala=1, upper=0, lower=0, num=0;
  
  printf("Insira uma string\n");
  gets(str);
  
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == ' '){
      pala++;
      continue;
    }
    if(isupper(str[i])){
      upper++;
      continue;
    }
    if(islower(str[i])){
      lower++;
      continue;
    }
    if(isdigit(str[i])){
      num++;
    }
  }
  printf("QTD de caracter = %d\n", i);
  printf("QTD de palavras = %d\n", pala);
  printf("QTD de char maiusculo = %d\n", upper);
  printf("QTD de char minusculo = %d\n", lower);
  printf("QTD de char numericos = %d\n", num);
  
    return 0;
}