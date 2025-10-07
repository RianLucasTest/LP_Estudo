#ifndef FUNCOES_H
#define FUNCOES_H
//gcc q1.c funcoes.c -o C:\Users\User\Desktop\Lp\LP2\Ponteiros1\output\main1


void imprime(int*);
void manipula(int*);
void soma_print(int*, int*);
void trocar(int*, int*);
void impressao(int);
typedef struct{
    int idd;
    float alt;
} Tpessoa;
void print_struct(Tpessoa*);
void val_endereco(float[]);
void verif(int*, int*);
void array_ptr(int*[] , int);

#endif