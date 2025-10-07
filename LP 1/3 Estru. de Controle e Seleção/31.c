#include <stdio.h>
#include <stdlib.h>

int main() {
    int prod, qtd_prod, qtd_dia, l_dia, cont_dia, maior_dia, mais_vendas, qtd_sem, campe, maior;
    float lucro_prod, lucro_sem, l1, l2, l3, l4, l5;
    l1 = l2 = l3 = l4 = l5 = 0;
    qtd_sem = lucro_sem = maior_dia = campe = lucro_prod = qtd_dia = l_dia = qtd_prod = 0;

    for(cont_dia = 1; cont_dia <= 7; cont_dia++){
        printf("Processamento de vendas da semana. Dia %d:\n", cont_dia);
        prod = 1;
        qtd_dia = l_dia = 0;

        while(prod != 0){
            printf("\nSelecione o tipo de produto (0 para finalizar o dia):\n");
            scanf("%d", &prod);
            qtd_prod = lucro_prod = 0;

            switch (prod){
                case(1):
                    printf("Digite a quantidade vendida:\n");
                    scanf("%d", &qtd_prod);
                    l1 = l1 + (qtd_prod * (2.98 - 1.55));
                    break;

                case(2):
                    printf("Digite a quantidade vendida:\n");
                    scanf("%d", &qtd_prod);
                    l2 = l2 + (qtd_prod * (4.50 - 2.27));
                    break;

                case(3):
                    printf("Digite a quantidade vendida:\n");
                    scanf("%d", &qtd_prod);
                    l3 = l3 + (qtd_prod * (9.99 - 5.47));
                    break;

                case(4):
                    printf("Digite a quantidade vendida:\n");
                    scanf("%d", &qtd_prod);
                    l4 = l4 + (qtd_prod * (4.49 - 3.80));
                    break;

                case(5):
                    printf("Digite a quantidade vendida:\n");
                    scanf("%d", &qtd_prod);
                    l5 = l5 + (qtd_prod * (6.87 - 3.15));
                    break;

                case(0):
                    break;
                default:
                    printf("Código de produto invalido: Tente Novamente!\n");
                    break;
            }
            qtd_dia = qtd_dia + qtd_prod;
            l_dia = l_dia + lucro_prod;
            
        }
        if (cont_dia == 1){
            maior_dia = cont_dia;
            mais_vendas = qtd_dia;
        }
        if(qtd_dia > mais_vendas){
            maior_dia = cont_dia;
            mais_vendas = qtd_dia;
        }

        
        maior = l1;
        campe = 1;

        if(l2 > maior){
            maior = l2;
            campe = 2;
        }
        if(l3 > maior){
            maior = l3;
            campe = 3;
        }
        if(l4 > maior){
            maior = l4;
            campe = 4;
        }
        if(l5 > maior){
            maior = l5;
            campe = 5;
        }
        qtd_sem = qtd_sem + qtd_dia;
        lucro_sem = l1 + l2 + l3 + l4 + l5;
       
    } 
    
    if(qtd_sem == 0){
        maior_dia = campe = 0;
    }
    printf("\n\t\tTotal de itens vendidos na semana:\t%d\n", qtd_sem);
    printf("\t\tO lucro total da semana foi:\t%.2f\n", lucro_sem);
    printf("\t\tO dia com mais vendas foi:\t%d\n", maior_dia);
    printf("\t\tO produto que mais deu lucros foi o \t%d\n", campe);

    system("PAUSE");
    return 0;
}