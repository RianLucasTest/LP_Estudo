#include<stdio.h>
#include<stdlib.h>

int main(){
    int sel, h_trab, h_extra, qtd_item;
    float pag_sem, sal_mes, valor_hn, venda_brut, val_item;
    sel = 1;

    while (sel > 0 && sel < 5){

        printf("Selecione o tipo de empregado (0 para finalizar o acesso)\n1\tGerente\n2\tTrab. comum\n3\tTrab. por comissao\n4\tTrab. por empreitada\n");
        scanf("%d", &sel);

        switch(sel){

        case (1):
            printf("Insira o salario fixo mensal\n");
            scanf("%f", &sal_mes);
            pag_sem = sal_mes / 4;
            printf("O pagamento semanal e: %.2f\n\n", pag_sem);
            break;

        case (2):
            printf("Insira o numero de horas trabalhadas:\n");
            scanf("%d", &h_trab);
            printf("Insira o valor da hora normal do trabalhador:\n");
            scanf("%f", &valor_hn);
            
            if(h_trab <= 40){
                sal_mes = h_trab * valor_hn;
            }
            else{
                h_extra = h_trab - 40;
                sal_mes = (40 * valor_hn) + (h_extra * 1.5 * valor_hn);
            }
            pag_sem = sal_mes / 4;
            printf("O pagamento semanal e: %.2f\n\n", pag_sem);
            break;

        case (3):
            printf("Digite o valor das vendas brutas:\n");
            scanf("%f", &venda_brut);
            pag_sem = 250.00 + (venda_brut * 0.057);
            printf("O pagamento semanal e: %.2f\n\n", pag_sem);
            break;

        case (4):
            printf("Digite o valor de cada item:\n");
            scanf("%f", &val_item);
            printf("Digite a quantidade de itens vendidos:\n");
            scanf("%d", &qtd_item);
            pag_sem = val_item * qtd_item;
            printf("O pagamento semanal e: %.2f\n\n", pag_sem);
            break;

        case (0):
            printf("Fim do processamento de pagamentos!\n");
            break;

        default:
            printf("ERRO: Selecione uma opcao valida\n");
            break;
        }
    }
    system("PAUSE");
    return 0;
}