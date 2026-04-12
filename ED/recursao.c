#include<stdio.h>
#include<stdlib.h>
#define pop2()   stack[top];top--
#define push2(x) top++;stack[top]=x
#define myprint(y)  printf("\n %2d - top==%d -stack: ", y, top);for(int h=top;h>=0;h--){ printf("%3d", stack[h]); }
int m;
int top=-1;
int stack[40];

int qtd_passos=0;
void hanoi(char, char, char, int);
int max0(int[], int n);
int maxm(int[], int, int);
void ordnc(int[], int, int);int minm(int [], int m, int n);
int fat(int);int fibo(int n);

typedef struct stack {
    int d;
    struct stack *next;
} TStack;

TStack pilha;

int push(TStack *, int);
int pop(TStack *);
int is_empty(TStack*);


int is_empty(TStack* s){
    if(s->next == NULL) return 1;
    else return 0;
}

int push(TStack *s, int n){
    TStack *lifo;
    lifo = (TStack *)malloc(sizeof(TStack));
    if(lifo == NULL){
        printf("Erro ao alocar memoria\n");
        return (-1);
    }
    lifo->d = n;
    (*lifo).next = s->next;
    (*s).next = lifo;
    return(0);
}//end-push

int pop(TStack *s){
    if(s == NULL){
        printf("Lista vazia: Nao e possivel realizar 'pop'\n");
        return(-1);
    }
    TStack *lifo = s->next;
    int dado = lifo->d;
    s->next = lifo->next;
    free(lifo);
    return(dado);
}//end-pop

int pstack(TStack *s) {
    TStack *lifo = s->next;
    while ( lifo != NULL) {
        printf("%2d ", lifo->d);
        lifo = lifo->next;
    }
    return 0;
}//end-pstack



int main(void){

    /*hanoi('A', 'B', 'C', 3);
    printf("QTD de passos: %d\n", qtd_passos);

    int vet[5] = {3, 6, -9, 94, 2};

    max0(vet, 4);
    printf("%d\n", vet[0]);

    maxm(vet, 4, 4);
    printf("%d\n", vet[4]);

    ordnc(vet, 0, 4);
    for(int i=0; i<5; i++) { printf("__> %d\n", vet[i]); }*/

    printf("Fibo 1: %d\nFibo 2: %d\nFibo 3: %d\n", fibo(1), fibo(2), fibo(3));
    printf("Fibo 4: %d\nFibo 5: %d\nFibo 6: %d\n", fibo(4), fibo(5), fibo(6));

    return 0;
}

void hanoi(char orig, char aux, char dest, int n){
    if(n == 1){
        printf("Movimento disco %d: %c-->%c\n", n, orig, dest);
        qtd_passos++;
        return;
    }
    hanoi(orig, dest, aux, n-1);
    printf("Movimento Disco %d: %c-->%c\n", n, orig, dest);
    qtd_passos++;
    hanoi(aux, orig, dest, n-1);
}

int max0(int vet[], int n){
    if(n == 0){
        return vet[0];
    }
    if(vet[n] > vet[0]){
        int temp = vet[n];
        vet[n] = vet[0];
        vet[0] = temp;
    }
    int m= max0(vet, n-1);
    return m;
}

int maxm(int vet[], int m, int n){//1
    if(n==m){//2
        return vet[m];//3
    }//4
    if(vet[n] > vet[m]){//5
        int temp = vet[n];//6
        vet[n] = vet[m];//7
        vet[m] = temp;//8
    }//9
    return maxm(vet, m, n-1);//10
}//11

void ordnc(int vet[], int m, int n){
    if(m==n){
        return;
    }
    maxm(vet, m, n);
    ordnc(vet, m+1, n);
    return;
}

int fat(int n){
    int m;
    L1:
    if(n < 0 ){
        push(&pilha, -1);
        goto L2;
    }
    if(n == 1){
        push(&pilha, 1);
        goto L2;
    }
    push(&pilha, n);
    n--;
    goto L1;
    L2:
    if((pilha.next)->next != NULL){
        m=pop(&pilha), n=pop(&pilha); push(&pilha, m*n);
        goto L2;
    }
    return pop(&pilha);

}

int fibo(int n){
    int h=0, j=0;
L1:
    if(n<=1){
        push2(1); 
        goto L3;
    } 
    push2(n);
    n--;
    goto L2;

L2:
    push2(n+pop2());
    n--;
    goto L1;

L3:
    if(top>=0){
        m=pop2(); n=pop2(); push2(n+m); goto L3;
    }
    return (n+m);

}