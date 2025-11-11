#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"
//========Variáveis globais(declaradas no main)=========
extern int qtd_alertas; //serve para ambos os sistemas de notificação
extern notificar alertas[MAX_NOTI];  //sistema básica de notificações
extern custom_noti noti_mod[MAX_NOTI];  //sistema custom de notificações
//==================================

//==============FUNÇÕES RELACIONADAS ÀS OFERTAS ========================================================

void registrar_oferta_teste(Toferta* head, char* nome, int qtd, float valor, char* vendedor){
    Toferta* nova=malloc(sizeof(Toferta));
    char notificacao[170];

    strcpy(nova->nome, nome); //copia de nome para nova
    strcpy(nova->vendedor, vendedor); //copia de vendedor para nova
    nova->qtd = qtd;
    nova->valor = valor;

    nova->prox = head->prox; //adiciona 'nova' depois da cabeça
    head->prox = nova;  //liga 'cabeça' à 'nova'

    //snprintf(notificacao, 100, "Nova oferta adicionada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n", nome, qtd, valor);
    snprintf(notificacao, 170, "Nova oferta adicionada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n    Vendedor-> %s\n", nova->nome, nova->qtd, nova->valor, nova->vendedor);
    notificar_all(alertas, notificacao);

}

void registrar_oferta(Toferta* head){
    Toferta* nova=malloc(sizeof(Toferta));
    char notificacao[120];

    getchar(); //consome buffer de entrada
    printf("Insira o nome do produto: ");
    fgets(nova->nome, 50, stdin);
    nova->nome[strcspn(nova->nome, "\n")] = '\0'; //tira o '\n'

    printf("Insira a quantidade de itens da oferta: ");
    scanf("%d", &nova->qtd);

    printf("Insira o valor da oferta: ");
    scanf("%f", &nova->valor);

    nova->prox = head->prox; //adiciona 'nova' depois da cabeça
    head->prox = nova;  //liga 'cabeça' à 'nova'

    snprintf(notificacao, 120, "Nova oferta adicionada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n", nova->nome, nova->qtd, nova->valor);
    notificar_all(alertas, notificacao);

}

void excluir_oferta(Toferta* p){
    Toferta* ant=p;
    p=p->prox;
    char notificacao[170];
    char nome[50];

    getchar(); //consome buffer de entrada
    printf("Insira o nome do produto a ser excluido(exatamente igual a lista): ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

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

void excluir_oferta_teste(Toferta* p, const char* nome){
    Toferta* ant=p;
    p=p->prox;
    char notificacao[170];

    while(p!=NULL){ //avança até achar o nó a ser excluído (identificado pelo nome)
        if(strcmp(p->nome, nome) == 0) break;
        ant=p; //sempre guarda o que aponta pra p
        p=p->prox;
    }
    if(p==NULL){ //se o while finalizou pois chegou ao fim
        printf("Nome nao encontrado na lista\n");
        return;
    }

    snprintf(notificacao, 170, "Oferta esgotada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n    Vendedor-> %s\n", p->nome, p->qtd, p->valor, p->vendedor);
    //snprintf(notificacao, 100, "Oferta esgotada\n    Nome->%s\n    Quantidade->%d\n    Valor->%.2f\n", p->nome, p->qtd, p->valor); //nesse momento p é p nó a ser excluído
    notificar_all(alertas, notificacao);

    ant->prox = p->prox; //só é executado se alista não chegou ao fim(evitar segmentation fault)
    free(p);

}

void lista_ofertas(Toferta* p){
    int i;
    printf("\n======INICIO DA LISTA=====\n");

    for(i=0, p=p->prox ; p != NULL; i++, p = p->prox){

        printf("======Lista[%d]======\n"
            "\tqtd: %d\n"
            "\tValor: %.2f\n"
            "\tNome: %s\n" 
            "\tVendedor: %s\n", i+1, p->qtd, p->valor, p->nome, p->vendedor);
            printf("\n");
    }

    printf("=====FIM DA LISTA=====\n\n");
}

void vendasMenu(Toferta* cabeca){
    int option=0;

    do{
    printf("======MENU DE VENDAS======\n"
        "\t-> Sempre que uma oferta e excluido ou adicionada uma notificacao e enviada para todos\n"
        "1. Registrar Oferta\n"
        "2. Excluir Oferta\n"
        "3. Mostrar Ofertas\n"
        "4. Sair do Menu de Vendas\n");
    printf("Selecione opcao desejada: ");
    scanf("%d", &option);

    switch(option){
        case 1:
            registrar_oferta(cabeca);
            break;
        case 2:
            excluir_oferta(cabeca);            
            break;
        case 3:
            lista_ofertas(cabeca);
            break;
        case 4: 
            printf("Obrigado! Volte sempre!!!\n");
            return;
        default: 
            printf("Opcao invalida! Tente Novamente\n!");
            break;
    }

    }while(option > 0 || option < 5);
}

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

//========FIM DAS FUNÇÕES DE OFERTAS=========================================================================

//========FUNÇÕES RELACIONADAS ÀS NOTIFICAÇÕES/ALERTAS=======================================================

void alerta_email(const char* msg){
    printf("Email enviado automaticamente para todos\n%s\n", msg);
}

void alerta_sistema(const char* msg){
    printf("ATENCAO: Notificacao de sistema\n%s\n", msg);
}

void alerta_cel(const char* msg){
    printf("Mensagem automatica enviada para todos os celulares cadastrados\n%s\n", msg);
}

void registrar_alerta(notificar reg){;
    alertas[qtd_alertas++] = reg;
}

void notificar_all(notificar* vet, const char* msg){
    for(int i=0; i<qtd_alertas; i++){
        vet[i](msg);
    }
}

//========================================================================================================

//============SISTEMA DE NOTIFICAÇÕES CUSTOMIZADO==================

void registrar_alerta_custom(notificar reg, char* descri){
    if(qtd_alertas >= MAX_NOTI){
        printf("Quantidade maxima de alertas excedida!\n");
        return;
    }
    noti_mod[qtd_alertas].alerta = reg;
    strcpy(noti_mod[qtd_alertas].descricao, descri);
    qtd_alertas++;
}

void option_alerta_custom(void){
    for(int i=0; i<qtd_alertas; i++){
        printf("Deseja enviar notificacao para %s (1 para sim, 0 para nao)? ", noti_mod[i].descricao);
        scanf("%d", &noti_mod[i].option);
    }
}

void notificar_all_custom(const char* msg){
    for(int i=0; i<qtd_alertas; i++){
        if(noti_mod[i].option) noti_mod[i].alerta(msg);
    }
}

//====================================================================================