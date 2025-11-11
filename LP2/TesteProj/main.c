#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"

//========Variáveis globais=========
int qtd_alertas=0;
notificar alertas[MAX_NOTI];
custom_noti noti_mod[MAX_NOTI];
//==================================

int main(void){

    registrar_alerta_custom(alerta_cel, "Celular");
    registrar_alerta_custom(alerta_email, "Email");
    registrar_alerta_custom(alerta_sistema, "Sistema Geral");

    for(int i=0; i<3; i++){

        option_alerta_custom();

        notificar_all_custom("Ola mundo, isto e um teste\n");
    }


    return 0;
}


/*
int main(void){
    Toferta* cabeca=malloc(sizeof(Toferta)); //cabeça sentinela SEMPRE
    cabeca->prox = NULL;

    //registrar_alerta(alerta_cel);
    registrar_alerta(alerta_email);
    //registrar_alerta(alerta_sistema);

    
    registrar_oferta_teste(cabeca, "Laranjeiras", 15, 85.34, "Joao");
    registrar_oferta_teste(cabeca, "Limoes", 47, 94.99, "Claudio");
    registrar_oferta_teste(cabeca, "Acucares(kg)", 9, 52.34, "Juliana");
    registrar_oferta_teste(cabeca, "Cafe(pcts)", 8, 32.60, "Seu Ze");

    lista_ofertas(cabeca);
    printf("\n");

    excluir_oferta_teste(cabeca, "Acucares(kg)");
    lista_ofertas(cabeca);
    printf("\n");
    


    //vendasMenu(cabeca);

    liberaLista(cabeca);
    free(cabeca);
    cabeca=NULL;
    system("PAUSE");
    return 0;
} */
