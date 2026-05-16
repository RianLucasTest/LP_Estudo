#include <stdio.h>
#define SIZE 50

void insere(char vet[], char d){
    int i=0;

    while(i < SIZE && vet[i] != ' '){
        if(d < vet[i]){
            i = (2*i)+1;
        }
        else{
            i = (2*i)+2;
        }
    }
    if(i < SIZE) vet[i] = d;
}

void preordert(int i,  char dest[], char orig[]){
    if (i >= SIZE || orig[i] == ' ') {
        return;
    }

    insere(dest, orig[i]);
    preordert((2 * i) + 1, dest, orig);
    preordert((2 * i) + 2, dest, orig);
}

void inordert(int i, char dest[], char orig[]){
    if (i >= SIZE || orig[i] == ' ') {
        return;
    }

    inordert((2 * i) + 1, dest, orig);
    insere(dest, orig[i]);
    inordert((2 * i) + 2, dest, orig);
}

void posordert(int i, char dest[], char orig[]) {
    if (i >= SIZE || orig[i] == ' ') {
        return;
    }

    posordert((2 * i) + 1, dest, orig);
    posordert((2 * i) + 2, dest, orig);
    insere(dest, orig[i]);
}


void prn(char t[]){
    for(int i=0; i<SIZE; i++){
        if(t[i] == ' ') continue;
        printf("%3c ", t[i]);
    }
}

int main(){
    char T[SIZE]={' '};
    char pos[SIZE]={' '}, in[SIZE]={' '}, pre[SIZE]={' '};

    for(int i=0; i<SIZE; i++){
        T[i] = pos[i] = in[i] = pre[i] = ' ';
    }

    T[0]='a'; T[1]='b';T[2]='c'; T[3]='d'; T[4]='e'; T[5]='f'; T[6]='g'; T[7]='h'; 
    T[8]='i'; T[9]='j'; T[10]='k'; T[11]='l'; T[12]='m'; T[13]='o'; T[14]='p';
   
    preordert(0, pre, T);
    inordert(0, in, T);
    posordert(0, pos, T);
   
    printf("Original: ");
    prn(T);
    printf("\nPRE: ");
    prn(pre);
    printf("\nIN: ");
    prn(in);
    printf("\nPOS: ");
    prn(pos);
    printf("\n");

    return 0;
}