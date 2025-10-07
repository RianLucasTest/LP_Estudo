#include<stdlib.h>
#include<stdio.h>
typedef struct{
    char nome[20];
    char sobnome[20];
    int idade;
    char telef[15];
    char sexo;
    char email[30];
} Taluno;


int main(){
    Taluno info;

    printf("  Preencha os segintes dados:\n");
    printf("Insira o Nome:\n");
    gets(info.nome);
    fflush(stdin);
    printf("Insira o Sobrenome:\n");
    gets(info.sobnome);
    fflush(stdin);
    printf("Insira a idade:\n");
    scanf("%d", &info.idade);
    fflush(stdin);
    printf("Insira o Telefone:\n");
    gets(info.telef);
    fflush(stdin);
    printf("Insira o sexo(M ou F):\n");
    scanf("%c", &info.sexo);
    fflush(stdin);
    printf("Insira o email:\n");
    gets(info.email);
    fflush(stdin);

    printf("\n\n======Dados do Aluno=====\n");
    printf("  Nome: %s\n  Sobrenome: %s\n  Idade: %d\n  Telefone: %s\n  Sexo: %c\n  Email: %s\n",
                info.nome, info.sobnome, info.idade, info.telef, info.sexo, info.email);

    system("PAUSE");
    return 0;
}