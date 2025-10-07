#include<stdlib.h>
#include<stdio.h>
#define QTD 10
typedef struct{
    int mat;
    char nome[20];
    char sobno[20];
    float nota;
} Taluno;

int main(){
    Taluno al[QTD];
    int i;
    float media=0;

    printf("===Preencha os segintes dados:===\n");
    for(i = 0; i < QTD; i++){
        printf("\n======Aluno %d======\n", i+1);
        printf("Insira o Nome:\n");
        gets(al[i].nome);
        fflush(stdin);
        printf("Insira o Sobrenome:\n");
        gets(al[i].sobno);
        printf("Insira a matricula:\n");
        scanf("%d", &al[i].mat);
        printf("Insira a nota do aluno:\n");
        scanf("%f", &al[i].nota);
        fflush(stdin);
        media += al[i].nota;
    }
    media /= QTD;
    int mind=0, pind=0;
    for(i = 0; i < QTD; i++){
        if(al[i].nota > al[mind].nota) mind = i;
        if(al[i].nota < al[pind].nota) pind = i;
    }
    printf("===Melhor estudante===\n  Nome> %s\n  Sobrenome: %s\n  Matricula: %d\n  Nota: %.2f\n",
            al[mind].nome, al[mind].sobno, al[mind].mat, al[mind].nota);
            
    printf("===Pior estudante===\n  Nome> %s\n  Sobrenome: %s\n  Matricula: %d\n  Nota: %.2f\n",
            al[pind].nome, al[pind].sobno, al[pind].mat, al[pind].nota);

    printf("A media das notas dos estudantes foi de %.2f\n", media);

    system("PAUSE");
    return 0;
}