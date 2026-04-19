#include <stdio.h>
#define SIZE 50

char queue[SIZE];
int size = 0;

void enqueue(int x) {
    if (size < SIZE) {
        queue[size++] = x;
    }
}

char dequeue() {
    if (size == 0) return -1;

    char valor = queue[0];
    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--;

    return valor;
}

void inserir(char vet[], char d, int i) {

    while (i < SIZE) {
        if (vet[i] == ' ') {
            vet[i] = d;
            return;
        }

        if (d < vet[i]) {
            i = (2 * i) + 1;
        } 
        else {
            i = (2 * i) + 2;
        }
    }

}

void removerSub(char vet[], int i){
    if(i >= SIZE || vet[i] == ' ')
        return;

    removerSub(vet, 2*i + 1);

    enqueue(vet[i]);
    vet[i] = ' ';

    removerSub(vet, 2*i + 2);
}

void removeDado(char vet[], char dado){
    int indice=-1;
    for(int i=0; i<SIZE; i++){
        if(vet[i] == dado){
            indice=i;
            break;
        }
    }
    if(indice==-1){
        return;
    }

    removerSub(vet, indice);
    dequeue();

    while(size > 0){
        char dado=dequeue();
        inserir(vet, dado, indice);
    }
    
}


void inordert(int i, char t[]) {
    if (i >= SIZE || t[i] == ' ') {
        return;
    }

    inordert((2 * i) + 1, t);
    printf("%c ", t[i]);
    inordert((2 * i) + 2, t);
}

int main() {
    char a[SIZE];

    for (int i = 0; i < SIZE; i++) {
        a[i] = ' ';
    }

    inserir(a, 'h', 0);
    inserir(a, 'a', 0);
    inserir(a, 'i', 0);
    inserir(a, 'b', 0);
    inserir(a, 'e', 0);
    inserir(a, 'c', 0);
    inserir(a, 'g', 0);
    inserir(a, 'd', 0);
    inserir(a, 'f', 0);

    printf("Inorder:\n");
    inordert(0, a);

    removeDado(a, 'f');

    printf("Inorder:\n");
    inordert(0, a);

    return 0;
}