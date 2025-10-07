#ifndef FUNCOES_H
#define FUNCOES_H
//gcc q1.c funcoes.c -o C:\Users\User\Desktop\Lp\LP2\Recursividade\output\main1


long int potencia(int, int);
void contagem_regressiva(int n);
unsigned int soma_dig(int n);
int mdc(int, int);
void inverte_str(char*, int, int);
int busca_bi(int[], int, int, int);
void bubble(int[], int);

void hanoi(int, char, char, char);

int eh_palindromo(char*, int, int);
void converte_base(int, int);
int soma_pares(int[], int);

#endif