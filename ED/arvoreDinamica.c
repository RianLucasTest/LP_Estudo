#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_STR 32

typedef struct tree{
    char nome[MAX_STR];
    struct tree* left;
    struct tree* right; 
} Ttree;

Ttree* criaNoh(char* nome){
    Ttree* novo = malloc(sizeof(Ttree));
    if (novo == NULL){ 
        printf("ERRO ao alocar memoria\n"); 
        return NULL; 
    }

    strcpy(novo->nome, nome);
    novo->left=NULL;
    novo->right=NULL;
    return novo;
}

Ttree* inserir(Ttree* root, char* nome){
    if(root == NULL){
        return criaNoh(nome);
    }
    if(strcmp(nome, root->nome) < 0){
        root->left = inserir(root->left, nome);
    }
    else{
        root->right = inserir(root->right, nome);
    }
    return root;
}

void prnPreOrder(Ttree* root){
    if(root == NULL){
        return;
    }
    else{
        printf("%s ", root->nome);
        prnPreOrder(root->left);
        prnPreOrder(root->right);
    }

}
void prnInOrder(Ttree* root){
    if(root == NULL){
        return;
    }
    else{
        prnInOrder(root->left);
        printf("%s ", root->nome);
        prnInOrder(root->right);
    }

    
}void prnPosOrder(Ttree* root){
    if(root == NULL){
        return;
    }
    else{
        prnPosOrder(root->left);
        prnPosOrder(root->right);
        printf("%s ", root->nome);
    }

    
}


int main(){
    Ttree* root=NULL;
    char* nomes[7] = {"Zebra", "Urso", "Zorro", "Morcego", "Rato", "Leao", "Tatu"};

    for(int i=0; i<7; i++){
        root = inserir(root, nomes[i]);
    }

    printf("\nPreOrder: ");
    prnPreOrder(root);
    printf("\nInOrder: ");
    prnInOrder(root);
    printf("\nPosOrder: ");
    prnPosOrder(root);
    printf("\n\n");

    return 0;
}