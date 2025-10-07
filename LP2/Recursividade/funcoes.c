#include<stdio.h>
#include<string.h>
#include"funcoes.h"

long int potencia(int base, int expo){
  if(expo == 0){
    return 1;
  }
  else{
    return base*potencia(base, expo-1);
  }
}
  
void contagem_regressiva(int n){
  printf("%d...\n", n);
  if(n == 0){
    printf("Fogo!\n");
  }
  else{
    contagem_regressiva(n-1);
  }
  
}

unsigned int soma_dig(int n){
  if(n < 10){
    return n;
  }
  else{
  return n%10 + soma_dig(n/10);
  }
  
}

int mdc(int a, int b){
  if(b == 0){
    return a;
  }
  else{
    return mdc(b, a%b);
  }
}

void inverte_str(char str[], int inicio, int fim){
  char temp;
  if(inicio >= fim){
    return;
  }
  else{
    temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverte_str(str, inicio+1, fim-1);
  }
}

int busca_bi(int vet[], int inicio, int fim, int alvo){
  int meio = (inicio + fim)/2;

  if(inicio > fim){
    return meio;
  }
  
  if(alvo > vet[meio]){
    inicio = meio+1;
  }
  else if(alvo < vet[meio]){
    fim = meio-1;
  }
  else{
    return meio;
  }
  return busca_bi(vet, inicio, fim, alvo);
  
}

void bubble(int vet[], int lim){
  int temp, i, j;
  for(i=0; i<lim-1; i++){
    for(j=i+1; j<lim; j++){
      if(vet[i] > vet[j]){
        temp = vet[j];
        vet[j] = vet[i];
        vet[i] = temp;
      }
    }
  }
  
}

void hanoi(int discos, char origem, char destino, char aux){
    static int cont=1;

    if(discos==1){
        printf("%d. Mova o disco de %c para %c\n", cont, origem, destino);
        cont++;
    }
    else{
        hanoi(discos-1, origem, aux, destino);
        printf("%d. Mova o disco de %c para %c\n", cont, origem, destino);
        cont++;
        hanoi(discos-1, aux, destino, origem);
    }

}

int eh_palindromo(char str[], int inicio, int fim){

    if(inicio==fim || inicio>fim){
        return 1;
    }
    else if(str[inicio] == str[fim]){
        return eh_palindromo(str, inicio+1, fim-1);
    }
    else{
        return 0;
    }

}

void converte_base(int n, int base){

    int resto=n%base;
    if(n < base){
        if(resto<10){
            printf("%d", resto);
        }
        else{
            printf("%c", (resto+55));
        }
    }
    else{
        converte_base(n/base, base);
        if(resto<10){
            printf("%d", resto);
        }
        else{
            printf("%c", (resto+55));
        }
    }

}

int soma_pares(int vet[], int tam){
    
    if(tam==0){
        return 0;
    }
    else{
        if((vet[tam-1]%2) == 0){
            return vet[tam-1] + soma_pares(vet, tam-1);
        }
        else{
            return soma_pares(vet, tam-1);
        }
    }

}