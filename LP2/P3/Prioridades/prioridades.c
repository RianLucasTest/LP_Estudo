#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prioridades.h"


Tarefa* criar_tarefa(int id, const char *descricao, int prioridade) {
    /**
     * COMPLETE ESTA FUNÇÃO (0,5 pontos)
     * Aloca e inicializa uma nova tarefa
     * Retorna ponteiro para a tarefa criada
     */

    Tarefa* nova=malloc(sizeof(Tarefa)); //aloca dinamicamente uma nova estrutura

    //Copia os dados passados para a estrutura nova___________
    nova->id = id; 
    strcpy(nova->descricao, descricao); 
    nova->prioridade = prioridade;
    nova->prox = NULL; //inicializa como NULL para evitar ponteiro selvagem
    //____________________________________

    return nova;
}

void inserir_tarefa(Tarefa **lista, int id, const char *descricao, int prioridade) {
    /**
     * COMPLETE ESTA FUNÇÃO (0,5 pontos)
     * Insere nova tarefa no FINAL da lista
     * Mantenha o ponteiro para o último elemento para eficiência
     */

    if((*lista) == NULL){  //lista vazia
        *lista = criar_tarefa(id, descricao, prioridade); //cria novo nó, que já aponta para NULL (funcao de criar)
        return;
    }

    Tarefa* p = *lista;  //ptr para avançar na lista. Recebe o primeiro nó


    while(p->prox != NULL){
        p=p->prox;
    } 
    //sai do loop quando p->prox = NULL
    //ou seja, p é o último nó
    
    p->prox = criar_tarefa(id, descricao, prioridade); //cria novo nó, que já aponta para NULL (funcao de criar)

}

// Funções de processamento (JÁ IMPLEMENTADAS)
void imprimir_detalhado(Tarefa *t) {
    printf("Tarefa %d: %s [Prioridade: %d]\n", t->id, t->descricao, t->prioridade);
}

void imprimir_resumido(Tarefa *t) {
    printf("%d - %s\n", t->id, t->descricao);
}

void processar_alta_prioridade(Tarefa *t) {
    if (t->prioridade == 3) {
        printf("⭐ URGENTE: %s\n", t->descricao);
    }
}

void processar_lista(Tarefa *lista, FuncaoProcessamento funcao) {
    /**
     * COMPLETE ESTA FUNÇÃO (0,5 pontos)
     * Percorre a lista e aplica a função de processamento em cada tarefa
     * Use ponteiro para função conforme o parâmetro 'funcao'
     */

     while(lista != NULL){ //sai do loop quando nao tem mais nós (lista=NULL)
        funcao(lista);  //chama a função passada como parâmetro, enviando lista
        lista = lista->prox;
     }
     //percorre até o ultimo nó e aplica a funcao

}

void liberar_lista(Tarefa *lista) {
    /**
     * COMPLETE ESTA FUNÇÃO (0,5 pontos)
     * Libera toda a memória alocada para a lista
     */

     Tarefa* del=NULL; //inicializar com NULL para evitar comportamento selvagem

     while(lista != NULL){
        del = lista; //mantém o endereço a ser liberado
        lista = lista->prox; //avança
        free(del); //libera
     }
     lista=NULL;
     del=NULL;  //evita comportamento selvagem

}

void user_add_tarefa(Tarefa** lista, int* id){
    char descricao[100];
    int prioridade, option;

    printf("Deseja inserir uma tarefa(1 para sim, 0 para nao)? ");
    scanf("%d", &option);  //decisão se quer ou não adicionar tarefa

    while(option){
        printf("Insira a sua tarefa (max 100 caracteres): ");
        getchar(); //tira \n do buffer
        fgets(descricao, 100, stdin);
        descricao[strcspn(descricao, "\n")] = '\0'; //lê uma string e retira o \n final

        printf("Insira a prioridade da tarefa(1 a 3): ");
        scanf("%d", &prioridade); //lê a prioridade
        while(prioridade < 1 || prioridade > 3){
            printf("Valor invalido. digite um valor entre 1 e 3: ");
            scanf("%d", &prioridade);   //mantém a validade da prioridade
        }
        inserir_tarefa(lista, (*id), descricao, prioridade); //chama função para inserir uma nova tarefa
        (*id)++; //se adicionou tarefa incrementa 1 no id
        printf("Tarefa adicionada :)\n\n");

        printf("Deseja inserir uma tarefa(1 para sim, 0 para nao)? ");
        scanf("%d", &option); //para manter no loop inserindo tarefas

    }
}

void user_del_tarefa(Tarefa** lista, int* id){
    int option, del;
    printf("Deseja excluir uma tarefa(1 para sim, 0 para nao)? ");
    scanf("%d", &option);  //decisão se quer ou não excluir tarefa
    Tarefa* p = *lista; //cria um ptr para ser avançado sem modificar o original
    Tarefa* atual = NULL;

    while(option){
        p = *lista; //reinicia a cada loop
        atual = NULL;

        printf("Insira o id da tarefa a ser deletada: ");
        scanf("%d", &del);
        while(del < 1 || del > *id){
            printf("Insira um id valido a ser deletado: ");
            scanf("%d", &del);
        }

        if(del == (*lista)->id){ //verifica se é o primeiro
            atual = *lista;
            *lista= (*lista)->prox;
            free(atual);
            break;
        }

        //loop para procurar nó
        while(p != NULL && del != p->id){ //sai do loop se p=NULL ou p=nó a ser deletado
            atual = p; //sempre anterior a p
            p=p->prox;
        } //quando sai p é NULL ou p é o nó a ser deletado 

        if(p == NULL) { printf("Id nao existe na lista! Tente novamente\n"); } //testa se p é NULL
        else{
            atual->prox = p->prox; //ligação do anterior a p com o próximo de p
            free(p); //deleta p
            printf("Noh deletado\n");
        }

        printf("Deseja excluir uma tarefa(1 para sim, 0 para nao)? ");
        scanf("%d", &option);  //decisão se quer ou não excluir tarefa
    }
}
