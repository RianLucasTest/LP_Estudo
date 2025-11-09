#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NOTI 3 //maximo de notificações diferentes

typedef void(*notificar)(const char*); //tipo 'notificar' é uma função void que recebe char*.

int qtd_alertas=0;
notificar alertas[MAX_NOTI];

/*
Por enquanto os alertas estão sendo enviados para todos
Ainda estou pensando numa maneira de especificar(ex: "Olá 'fulano de tal'. Temos uma novidade...")
para emails personalizados
*/

//FUNCOES DE ALERTA___________________________
void alerta_email(const char* msg);
void alerta_sistema(const char* msg);
void alerta_cel(const char* msg);
void registrar_alerta(notificar reg);
void notificar_all(notificar*, const char*);
//____________________________________________

typedef struct Toferta{
    char nome[50];
    int qtd;
    float valor;
    struct Toferta* prox;
} Toferta;

//parametros:  ptr para cabeca / nome do prod / qtd de prod / valor da oferta
void registrar_oferta(Toferta* head, char* nome, int qtd, float valor){
    Toferta* nova=malloc(sizeof(Toferta));
    char notificacao[100];

    strcpy(nova->nome, nome); //copia de nome para nova
    nova->qtd = qtd;
    nova->valor = valor;

    nova->prox = head->prox; //adiciona 'nova' depois da cabeça
    head->prox = nova;  //liga 'cabeça' à 'nova'

    snprintf(notificacao, 100, "Nova oferta adicionada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n", nome, qtd, valor);
    notificar_all(alertas, notificacao);

}

void excluir_oferta(Toferta* p, const char* nome){
    Toferta* ant=p;
    p=p->prox;
    char notificacao[100];

    while(p!=NULL){ //avança até achar o nó a ser excluído (identificado pelo nome)
        if(strcmp(p->nome, nome) == 0) break;
        ant=p; //sempre guarda o que aponta pra p
        p=p->prox;
    }
    if(p==NULL){ //se o while finalizou pois chegou ao fim
        printf("Nome nao encontrado na lista\n");
        return;
    }

    snprintf(notificacao, 100, "Oferta esgotada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n", p->nome, p->qtd, p->valor); //nesse momento p é p nó a ser excluído
    notificar_all(alertas, notificacao);

    ant->prox = p->prox; //só é executado se alista não chegou ao fim(evitar segmentation fault)
    free(p);

}

void lista_ofertas(Toferta* p){
    int i;
    printf("======INICIO DA LISTA=====\n");

    for(i=0, p=p->prox ; p != NULL; i++, p = p->prox){

        printf("======Lista[%d]======\n"
            "qtd: %d\n"
            "Valor: %.2f\n"
            "Nome: %s\n", i+1, p->qtd, p->valor, p->nome);
            printf("\n");
    }

    printf("=====FIM DA LISTA=====\n");
}

//libera a lista inteira EXCETO A CABEÇA(liberar no main ou modificar função)
//Isso facilita reutilização da ccabeça se necessário
void liberaLista(Toferta* p){
    Toferta* liberar=NULL;
    p=p->prox;  //tirar(ou comentar, em caso de testes) ESSA linha para liberar cabeça também
    while(p!=NULL){
        liberar = p;
        p = p->prox;
        free(liberar);
    }
    printf("Lista liberada""\n");
}


int main(void){
    Toferta* cabeca=malloc(sizeof(Toferta)); //cabeça sentinela SEMPRE
    cabeca->prox = NULL;

    registrar_alerta(alerta_cel);
    registrar_alerta(alerta_email);
    registrar_alerta(alerta_sistema);

    //ptr para cabeca / nome do prod / qtd de prod / valor da oferta
    registrar_oferta(cabeca, "Laranjeiras", 15, 85.34);
    registrar_oferta(cabeca, "Limoes", 47, 94.99);
    registrar_oferta(cabeca, "Acucares(kg)", 9, 52.34);
    registrar_oferta(cabeca, "Cafe(pcts)", 8, 32.60);

    lista_ofertas(cabeca);
    printf("\n");

    excluir_oferta(cabeca, "Acucares(kg)");
    lista_ofertas(cabeca);
    printf("\n");


    liberaLista(cabeca);
    free(cabeca);
    system("PAUSE");
    return 0;
}

void alerta_email(const char* msg){
    printf("Email enviado automaticamente para todos\n%s\n", msg);
}
void alerta_sistema(const char* msg){
    printf("ATENCAO: Notificacao de sistema\n%s\n", msg);
}
void alerta_cel(const char* msg){
    printf("Mensagem automatica enviada para todos os cadastrados\n%s\n", msg);
}
void registrar_alerta(notificar reg){
    alertas[qtd_alertas++] = reg;
}
void notificar_all(notificar* vet, const char* msg){
    for(int i=0; i<qtd_alertas; i++){
        vet[i](msg);
    }
}