#include<stdio.h>
#include<stdlib.h>
#define TAM 20
void ExtAno(int, char[][TAM], char[][TAM], char[][TAM], char[][TAM]);

int main(){
    int a, m, duni, d, ddez;
    char mes[12][TAM] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    char uni[10][TAM] = {"", "Um", "Dois", "Tres", "Quatro", "Cinco", 
                        "Seis", "Sete", "Oito", "Nove"};
    char dez[10][TAM] = {"", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta",
                        "Sessenta", "Setenta", "Oitenta", "Noventa"};
    char cent[10][TAM] = {"", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos",
                         "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char excecao[9][TAM] = {"Onze", "Doze", "Treze", "Quatroze", "Quinze", "Dezesseis", 
                            "Dezessete", "Dezoito", "Dezenove"};
    


    printf("Digite a data (formato dia mes ano, separados por um enter)\n");
    scanf("%d %d %d", &d, &m, &a);
    if(d == 1) printf("Primeiro de %s de ", mes[m-1]);
    else if(d >=11 && d <=19) printf("%s de %s de ", excecao[d-11], mes[m-1]);
    else{
        ddez = d / 10;
        duni = d % 10;
        if(ddez != 0)
            printf("%s", dez[ddez]);

        if(ddez != 0 && duni != 0)
            printf(" e ");

        if(duni != 0)
            printf("%s", uni[duni]);

        printf(" de %s de ", mes[m-1]);
    }
    ExtAno(a, uni, dez, cent, excecao);

    


    system("PAUSE");
    return 0;
}

void ExtAno(int ano, char uni[][TAM], char dez[][TAM], char cent[][TAM], char excecao[][TAM]){
    int milhar, centena, dezena, unidade;
    milhar = ano / 1000;
    ano = ano % 1000;
    centena = ano / 100;
    ano = ano % 100;
    if(ano > 19 || ano < 11){
        dezena = ano / 10;
        unidade = ano % 10;
    }
    else dezena = ano;
    

    if(milhar != 0){
        if(milhar == 1) printf("Mil ");
        else printf("%s mil ", uni[milhar]);
    }
    printf("%s e ", cent[centena]);
    if(dezena < 20 && dezena > 10){
        dezena -= 11;
        printf("%s", excecao[dezena]);
    }
    else{
        if(dezena != 0)
            printf("%s ", dez[dezena]);
        if(dezena != 0 && unidade != 0) 
            printf("e ");
        if(unidade != 0)
            printf("%s", uni[unidade]);
    }
    printf("\n");

}