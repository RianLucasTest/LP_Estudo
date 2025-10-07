#include<stdlib.h>
#include<stdio.h>
#define VET 20

int main(){
    float notas[VET], maior;
    int i, loc_maior;
    printf("Insira as notas dos alunos da turma(separe com um 'enter'):\n");
    for(i = 0; i < VET; i++){
        printf("Aluno numero %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    maior = notas[0];
    loc_maior = 1;
    for(i = 0; i < VET; i++){
        if(maior < notas[i]){
            maior = notas[i];
            loc_maior = i+1;
        }
    }
    printf("A maior nota foi: %.2f\nNota obtida pelo aluno %d\n", maior, loc_maior);

    system("PAUSE");
    return 0;
}