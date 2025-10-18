#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

//aloca o vetor de ponteiros inicial com tamanho=QTD de disciplinas
float** alocaMatrizIrregular(int qtd_dis){
  float** mat = malloc(qtd_dis * sizeof(float*));
  if(mat==NULL){
    printf("ERRO: Alocacao nao realizada\n");
    return NULL;
  }
  return mat;
}

//Lê notas e armazena em um vetor que se ajusta automaticamente e ptr para variavel que armazena qtd de elementos do vetor
float* leNotasDisciplina(int* tam){
  float* notas = malloc(sizeof(float));
  if(notas==NULL){
    printf("ERRO: Alocacao nao realizada\n");
    return NULL;
  }
  float* temp=NULL;
  int i;
  
  printf("Insira as notas da discplina(valor negativo para finalizar): \n");
  
  for(i=0; ; i++){
    printf("--> ");
    scanf("%f", (notas+i));
    if(*(notas+i) < 0){ //Verificação para código de parada(n° negativo)
      printf("Fim do cadastro!\n");
      break;
    }
    //realoca matriz para mais 1 espaço e faz teste
    temp = realloc(notas, (i+2)*sizeof(float));
    if(temp==NULL){
    printf("ERRO: Realocacao nao realizada\n");
    free(notas);
    return NULL;
    }
    notas = temp;
  }
  //modifica a variavel na main e guarda tamanho do vetor que foi preenchido
  *tam = i;

  /*
  int tamanho = sizeof(notas);
  int tamfloat = sizeof(float);
  printf("Tamanho do vetor: %d\nTamanho float: %d\n\n", tamanho, tamfloat);*/
  
  //i: +1 pois subscrito é começa em 0, -1 para retirar posição do elemento de parada
  return notas; //retorna vetor preenchido
}

void liberaMatriz(float** mat, int qtd){
  //libera cada linhas depois o vetor geral
  for(int i=0; i<qtd; i++){
    free(*(mat+i));
  }
  free(mat);
}
//Recebe o vetor de notas de cada disciplina e o tamanho desse vetor
//Calcula a media
float mediaDisciplina(float* notas, int tam){
  float media=0;
  
  for(int i=0; i<tam; i++){
    media+= *(notas+i);
  }
  media = media/tam;
  return media;
}

//Recebe matriz total, vetor que contém a quantidade de notas de CADA disciplina e a qtd total de disciplinas
//Calcula a media total usando a função de media por disciplina
float mediaGeral(float** mat, int* tams, int linhas){
  float media=0;
  
  for(int i=0; i<linhas; i++){
    media += mediaDisciplina(*(mat+i), *(tams+i));
  }
  media = media/linhas;
  return media;
}
