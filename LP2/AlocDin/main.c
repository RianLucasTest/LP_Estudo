#include<stdio.h>
#include<stdlib.h>

int main(void){
  int lm, cm, lv, i, j;
  int** matriz=NULL;
  int* vetor=NULL;
  int* vet_res=NULL;
  
  printf("Insira a qtd de linhas da matriz: ");
  scanf("%d", &lm); 
  printf("Insira a qtd de colunas da matriz(linhas do vetor): ");
  scanf("%d", &cm);
  printf("Insira a qtd de linhas do vetor: ");
  scanf("%d", &lv); 
  if(lv!=cm){
    printf("ERRO: multipĺicacao indefinida\n");
    return 0;
  }
  
  //aloca o vetor linhasM e verifica
  matriz = malloc(lm*sizeof(int)); 
  if(matriz==NULL){
    printf("ERRO na alocacao\n");
    return 0;
  }
  //aloca um vetor (colunas) para cada linha e verifica
  for(i=0; i<lm; i++){
    *(matriz+i) = malloc(cm*sizeof(int));
    if(*(matriz+i)==NULL){
      printf("ERRO na alocacao\n");
      return 0;
    } 
}
  //aloca vetor
  vetor = malloc(lv*sizeof(int));
  
  //le elementos da matriz
  printf("====Matriz====\n");
  for(i=0; i<lm; i++){
    for(j=0; j<cm; j++){
      printf("[%d][%d]->", i, j);
      scanf("%d", (*(matriz+i)+j));
    }
  }
  //aloca o vetor resultante
  vet_res = malloc(lv*sizeof(int));
  
  //le elementos do vetor e preenche vetor resultante com 0
  printf("====Vetor====\n");
  for(i=0; i<lv; i++){
      printf("[%d]->", i);
    scanf("%d", (vetor+i));
    *(vet_res+i) = 0;
  }
  
  //faz o calculo da multiplicação
  for(i=0; i<lm; i++){
    for(j=0; j<cm; j++){
      *(vet_res+i) += *(*(matriz+i)+j) * *(vetor+j); //eu errei (tinha colocado vetor+i)
    }                                   //ele tem q percorrer o vetor de acordo as colunas
  }
  
  //imprime vetor resultante
  printf("======Vetor resultante=====\n");
  for(i=0; i<lm; i++){
    printf("->res[%d]--> %d\n", i, *(vet_res+i));
  }

  //desaloca os vetores colunas da matriz
  for(i=0; i<cm; i++){
    free(matriz[i]);
  }
  //desaloca os outros vetores
  free(matriz);
  free(vetor);
  free(vet_res);
  
  //iniciaiza os ponteiros com NULL para nao ter comportamento indefinido
  matriz=NULL;
  vetor=NULL;
  vet_res=NULL;
  
  
  return 0;
}
