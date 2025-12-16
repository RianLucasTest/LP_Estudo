#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prioridades.h"

int main() {
    Tarefa *lista = NULL;

    // Criando algumas tarefas
    inserir_tarefa(&lista, 1, "Estudar para a prova", 3);
    inserir_tarefa(&lista, 2, "Fazer compras", 2);
    inserir_tarefa(&lista, 3, "Reunião importante", 3);
    inserir_tarefa(&lista, 4, "Ler livro", 1);

    //Inserir tarefas=====================
    int id_atual = 5;
    //====================================

    int op_del_add;
    while(1){
        printf("=== LISTA DETALHADA ===\n");
        processar_lista(lista, imprimir_detalhado);

        printf("\n=== LISTA RESUMIDA ===\n");
        processar_lista(lista, imprimir_resumido);

        printf("\n=== TAREFAS URGENTES ===\n");
        processar_lista(lista, processar_alta_prioridade);

        printf("Deseja inserir ou excluir algumka tarefa(1 para sim, 0 para nao)? ");
        scanf("%d", &op_del_add);
        if(!op_del_add) break;

        user_add_tarefa(&lista, &id_atual);
        user_del_tarefa(&lista, &id_atual); //chama apenas 1 vez


    }
    liberar_lista(lista);

    lista = NULL; //evita comportamento selvagem
    return 0;
}