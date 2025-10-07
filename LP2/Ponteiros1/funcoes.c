#include<stdio.h>
#include"funcoesh.h"

/*Recebe ponteiro para inteiro. Imprime por inteiro
 simples e atraves de ponteiros*/
void imprime(int* ptr){
    int x=*ptr;
    printf("Valor de x por x: %d\n", x);
    printf("Endereco de x por x: %p\n", &x);
    printf("Valor de ptr: %p\n", ptr);
    printf("Valor apontado por ptr: %d\n", *ptr);

}

/*Recebe um ponteiro para inteiro. Manipula o valor apontado
Devolve por referência*/
void manipula(int* ptr){
    *ptr += 3;
    *ptr *= 2;
}

/*Recebe ponteiro para vetor e ponteiro para soma.
Imprime e realiza soma do vetorSoma devolvida por referencia*/
void soma_print(int* ptr_vet, int* ptr_soma){

    printf("Elementos do vetor:\n");
    for(int i=0; i<5; i++){
        printf("-> %d\n", *ptr_vet);
        *ptr_soma += *ptr_vet;
        ptr_vet++;
    }

}

/*Recebe 2 ponteiros para inteiros
Realiza a troca dos conteudos entre si*/

void trocar(int* a, int* b){
    int temp=*a;
    *a = *b;
    *b = temp;
}

/*Recebe um inteiro. Referencia atraves de ponteiros simples e duplo
Imprime atraves dos ponteiros*/
void impressao(int var){
    int* ptr1 = &var;
    int** ptr2 = &ptr1;

    printf("Valor por variavel: %d\n", var);
    printf("Valor por ptr1: %d\n", *ptr1);
    printf("Valor por ptr2: %d\n", **ptr2);
}

/*Recebe um ponteiro para tipo Tpessoa
imprime dados atraves do ponteiro*/
void print_struct(Tpessoa* ptr){
    ptr->idd = 18;
    ptr->alt = 1.86;
    printf("Idade: %d\nAltura: %.2f\n", ptr->idd, ptr->alt);
}

/*Recebe um vetor. Imprime endereco e 
valor atraves de ponteiro */
void val_endereco(float vet[]){

    float* p=vet;
    for(int i=0; i<4; i++){
        printf("Endereco da posicao %d: %p\n", i, p);
        printf("Valor da posicao %d: %.2f\n", i, *p);
        p++;
    }
}

/*Recebe dois ponteiros
Verifica qual endereco e maior e o imprime*/
void verif(int* px, int* py){

    printf("======\npx:%p\tpy: %p\n=====\n", px, py);

    if(px > py){
        printf("Px e maior: %p\n", px);
    }
    else if(px < py){
        printf("Py e maior: %p\n", py);
    }
    else{
        printf("Sao iguais: px:%p\tpy: %p\n", px, py);
    }

}

/*Recebe um vetor de ponteiro a quantidade de elementos.
Imprime os valores das variaveis apontadas atraves de ponteiros*/
void array_ptr(int* ap[], int lim){
    
    for(int i=0; i<lim; i++){
        printf("ap posicao %d: %d\n", i, *ap[i]);
    }

}
