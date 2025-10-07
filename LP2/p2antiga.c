#include<stdio.h>
typedef struct{
    char nome[50];
    int idade;
    char sexo;
    float cr;
} Taluno;
Taluno le_aluno(void);
void prn_aluno(Taluno*);
void ordena_alunos(Taluno*[]);


int main(void){
    Taluno alunos[3];
    Taluno* ptr[3];
    int i;

    //para cada elemento do vetor le um novo aluno
    for(i=0; i<3; i++){
        printf("Cadastro do aluno %d\n", i+1);
        alunos[i] = le_aluno();
        *(ptr+i) = &alunos[i];
    }

    //para cada elemento do vetor exibe os dados
    printf("===Antes da Ordenacao===\n");
    for(i=0; i<3; i++){
        prn_aluno(*(ptr+i));
    }

    //ordena o vetor
    ordena_alunos(ptr);
    
    //para cada elemento do vetor exibe os dados
    printf("===Depois da Ordenacao===\n");
    for(i=0; i<3; i++){
        prn_aluno(*(ptr+i));
    }
    

    return 0;
}

Taluno le_aluno(void){
    Taluno al;
    printf("Insira o nome: ");
    fflush(stdin);
    gets(al.nome);
    printf("Insira a idade: ");
    scanf("%d", &al.idade);
    printf("Insira o sexo(M ou F): ");
    fflush(stdin);
    scanf("%c", &al.sexo);
    printf("Insira o CR: ");
    scanf("%f", &al.cr);

    return al;
}
void prn_aluno(Taluno* al){
    printf("---Dados do Aluno---\n");
    printf("Nome: %s\nIdade: %d\nSexo: %c\nCR: %.2f\n", 
        al->nome, al->idade, al->sexo, al->cr);
}

void ordena_alunos(Taluno* al[]){
    int i, j;
    Taluno* temp;

    for(i=0; i<2; i++){
        for(j=0; j<2-i; j++){
            if( (*(al+j))->cr > (*(al+j+1))->cr){
                temp = *(al+j);
                *(al+j) = *(al+j+1);
                *(al+j+1) = temp;
            }
        }
    }
}