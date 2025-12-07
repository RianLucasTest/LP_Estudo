#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_NOTI 3 //maximo de notificações diferentes
typedef void(*notificar)(const char*); //tipo 'notificar' é uma função void que recebe char*.

typedef struct custom_noti{
    int option;
    char descricao[20];
    notificar alerta;
}custom_noti;

/*
Por enquanto os alertas estão sendo enviados para todos
Ainda estou pensando numa maneira de especificar(ex: "Olá 'fulano de tal'. Temos uma novidade...")
para emails personalizados
Podemos fazer algo como: "Deseja receber emails?"
*/

//FUNCOES DE ALERTA___________________________
void registrar_alerta_custom(notificar, char*); //registra um alerta + uma descricao
void option_alerta_custom(void); //verifica se o usuario quer ou nao aquele alerta. Deve ser usada sempre imediatamente antes de notificar_all_custom
void notificar_all_custom(const char*); //Chama ou nao alguma funcao de alerta

void alerta_email(const char* msg);
void alerta_sistema(const char* msg);
void alerta_cel(const char* msg);
void registrar_alerta(notificar reg);
void notificar_all(notificar*, const char*);
//____________________________________________

typedef struct Toferta{
    char vendedor[50];
    char nome[50];
    int qtd;
    float valor;
    struct Toferta* prox;
} Toferta;

//Função para executar e controlar o menu de vendas
//Parâmetro de entrada: ptr para cabeça da lista(preferencial criar no main)
void vendasMenu(Toferta*);
void registrar_oferta(Toferta*);  //parametros:  ptr para cabeca
void registrar_oferta_teste(Toferta*, char*, int, float, char*);
void excluir_oferta_teste(Toferta*, const char*);   //parametros:  ptr para cabeca / nome do prod a ser excluido
void excluir_oferta(Toferta*);
void lista_ofertas(Toferta*);  //imprime todas as ofertas
void liberaLista(Toferta*);  //libera a lista inteira EXCETO A CABEÇA(liberar no main ou modificar função)Isso facilita reutilização da cabeça se necessário

#endif