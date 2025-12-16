#ifndef PRIORIDADE_H
#define PRIORIDADE_H


// Estrutura para representar uma tarefa
typedef struct tarefa {
    int id;
    char descricao[100];
    int prioridade;  // 1-Baixa, 2-Média, 3-Alta
    struct tarefa *prox;
} Tarefa;

// Ponteiro para função de processamento
typedef void (*FuncaoProcessamento)(Tarefa*);

void user_del_tarefa(Tarefa** lista, int* id);
void user_add_tarefa(Tarefa** lista, int* id);
void liberar_lista(Tarefa *lista);
void processar_lista(Tarefa *lista, FuncaoProcessamento funcao);
void processar_alta_prioridade(Tarefa *t);
void imprimir_resumido(Tarefa *t);
void imprimir_detalhado(Tarefa *t);
void inserir_tarefa(Tarefa **lista, int id, const char *descricao, int prioridade);
Tarefa* criar_tarefa(int id, const char *descricao, int prioridade);


#endif