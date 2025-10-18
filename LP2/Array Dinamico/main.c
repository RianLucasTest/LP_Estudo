#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"


int main(void){
  float** notas=alocaMatrizIrregular(DISCIPLINAS);
  int tamanhos[DISCIPLINAS] = {0}; //guarda o tamanho do vetor de cada disciplina(qtd de notas)
  int i; //controle/contagem
  
  printf("=====CADASTRO DE NOTAS=====\n");
  for(i=0; i<DISCIPLINAS; i++){
    printf("---DISCIPLINA %d---\n", i+1);
    notas[i] = leNotasDisciplina(&tamanhos[i]);
    //Para cada disciplina preenche as notas 
  }
  //Para cada disciplina chama função que calcula media individual
  printf("\n=====MEDIAS DE CADA DISCIPLINA=====\n");
  for(i=0; i<DISCIPLINAS; i++){
    printf("---DISCIPLINA %d---\n"
           "\tMedia: %.2f\n", i+1, mediaDisciplina(*(notas+i), tamanhos[i]));
  }

  printf("=====MEDIA GERAL DO ALUNO=====\n"
          "Media: %.2f\n", mediaGeral(notas, tamanhos, DISCIPLINAS));
  
  liberaMatriz(notas, DISCIPLINAS);
  notas = NULL; //libera e anula para segurança

  return 0;
}

