#include<stdlib.h>
#include<stdio.h>

typedef union{//TAD para distinguir item b)
    char op;
    int num;
}TOp; typedef struct{TOp d; char flag;} TOper;

typedef struct queue{ //tipo fila baseado em TAD item a)
    TOper dado;
    struct queue* prox;}TQueue;

typedef struct pilha{ //pilha baseado em float item c)
    float valor;
    struct pilha* prox;} TStack;

//parte do código comentada/desconsiderada no papel

/***********************************************************************************************/

int push(TStack *s, float n){
    TStack *lifo;
    lifo = (TStack *)malloc(sizeof(TStack));
    if(lifo == NULL){
        printf("Erro ao alocar memoria\n");
        return (-1);
    }
    lifo->valor = n;
    (*lifo).prox = s->prox;
    (*s).prox = lifo;
    return(0);
}
float pop(TStack *s){
    if(s->prox == NULL){
        printf("Lista vazia: Nao e possivel realizar 'pop'\n");
        return(-1);
    }
    TStack *lifo = s->prox;
    float dado = lifo->valor;
    s->prox = lifo->prox;
    free(lifo);
    return(dado);
}

int enqueue(TQueue *queue, TOper a){ 
    TQueue* novo=malloc(sizeof(TQueue));
    if(novo==NULL){printf("ERRO na alocacao de memoria"); return(-1);}

    while((*queue).prox != NULL){
        queue=(*queue).prox;
    }

    (*novo).dado = a;
    (*novo).prox = (*queue).prox;
    (*queue).prox = novo;
    return(0);
}
 
TOper dequeue(TQueue *queue){
    if((*queue).prox == NULL){
        printf("ERRO: fila vazia\n");
        TOper erro;
        erro.d.num=-1;
        erro.flag='e';
        return erro;
    }
    TQueue* aux=(*queue).prox;
    (*queue).prox = (*aux).prox;
    TOper b = (*aux).dado;
    free(aux);
    return(b);
}

int fila_vazia(TQueue* fila){
    if (fila->prox == NULL) return 1;
    else return 0;
}

/***********************************************************************************************/


int main(){
    //fila ja possui notação
    TQueue* fila=malloc(sizeof(TQueue));
    fila->prox = NULL;
    TStack* pilha=malloc(sizeof(TStack));
    pilha->prox = NULL;

    TOper notacao[13];
    notacao[0].d.num=2;
    notacao[1].d.num=3;
    notacao[2].d.num=4;
    notacao[3].d.num=5;
    notacao[4].d.num=6;
    notacao[5].d.num=7;
    notacao[6].d.num=8;
    notacao[7].d.op='+';
    notacao[8].d.op='*';
    notacao[9].d.op='+';
    notacao[10].d.op='*';
    notacao[11].d.op='+';
    notacao[12].d.op='*';

    for (int i=0; i<13; i++){
        enqueue(fila, notacao[i]);
    }


    while(!fila_vazia(fila)){
        TOper valor = dequeue(fila);
        if((valor.d).op == '+' || (valor.d).op == '*'){valor.flag = 's';}//s=sinal
        else valor.flag = 'n'; //n=numero

        if(valor.flag == 'n'){push(pilha, (valor.d).num);}
        else if(valor.flag == 's'){
            float y=pop(pilha);
            float x=pop(pilha);
            if((valor.d).op == '+'){push(pilha, x+y);}
            else if((valor.d).op == '*'){push(pilha, x*y);}
        }//ende-else if
    }//end-while
    printf("Valor = %f\n", pop(pilha)); //while termina = pilha contem 1 valor
    return 0;                      //que é o resultador
}