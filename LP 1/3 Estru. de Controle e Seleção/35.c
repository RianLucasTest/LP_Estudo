#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd_p, nota_ent, n1, n2, n3, n4, n5, n0;
    float percent;
    nota_ent = n0 = n1 = n2 = n3 = n4 = n5 = qtd_p = 0;

    printf("Insira as notas da pesquisa (separadas por um'enter'. Digite 99 para finalizar entradas)\n");

    while(nota_ent >= 0){
        scanf("%d", &nota_ent);
        if(nota_ent == 99){
            break;
        }
        qtd_p = qtd_p + 1;

        switch(nota_ent){
            case(0):
                n0++;
                break;
            case(1):
                n1++;
                break;
            case(2):
                n2++;
                break;
            case(3):
                n3++;
                break;
            case(4):
                n4++;
                break;
            case(5):
                n5++;
                break;
            default: 
                break;
        }

        percent = (100 * (n4 + n5)) / qtd_p;
    }
        printf("A quantidade total de pessoas foi: %d\n", qtd_p);
        printf("A quantidade de pessoas associadas as notas foi:\n%d\tNota 0\n%d\tNota 1\n%d\tNota 2\n%d\tNota 3\n%d\tNota 4\n%d\tNota 5\n", n0, n1, n2, n3, n4, n5);
        printf("A porcentagem de pessoas que avaliaram como 'Boa (notas 4 ou 5)' e: %.2f\n", percent);
    

    system("PAUSE");
    return 0;
}