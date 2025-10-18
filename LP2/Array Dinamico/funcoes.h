#ifndef FUNCOES_H
#define FUNCOES_H

#define DISCIPLINAS 3
float** alocaMatrizIrregular(int); //entrar com qtd de linhas(disciplinas)
float* leNotasDisciplina(int*); //entrar com ptr para tam(qtd de notas da disciplina)
void liberaMatriz(float** mat, int qtd); //entrar com a matriz a ser liberada e qtd de linhas
float mediaDisciplina(float* notas, int tam); //entrar com o vetor da disciplina e qtd de notas desse vetor
float mediaGeral(float** mat, int* tams, int linhas); //entrar com matriz geral, vetor de tamanhos e qtd de linhas da matriz

#endif
