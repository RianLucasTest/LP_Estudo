//Rian Lucas dos Santos Araujo
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 64
char abb[SIZE][50];
int h[SIZE];
int bf[SIZE];

typedef struct{
    char fila[SIZE][50];
    int size;
} TFila;

//------------------------------------------------------------------------------
int insereabb(int i, char ABB[][50], char* str) {

    while(i < SIZE && strcmp(ABB[i], "") != 0) {
        if(strcmp(str, ABB[i]) < 0) { i = (2*i)  ; }
        else                        { i = (2*i)+1; }
    }
   
    if(i < SIZE) { strcpy(ABB[i], str); }
    return(0);
}

//------------------------------------------------------------------------------
void prn_ordem(int i, char ABB[][50], int h[]){
    for(int i=0; i<SIZE; i++){
        if (i >= SIZE || strcmp(ABB[i], "") == 0) { continue; }
        printf("%d %s h=%d\n", i, ABB[i], h[i]);
    }
}//end-prn_ordem()

//------------------------------------------------------------------------------
int cheight(char ABB[][50], int h[]){
    for (int i=SIZE-1; i>0; i--) {
        if (strcmp(ABB[i], "") != 0) {
            if(h[2*i]==-1 && h[2*i+1]==-1) { h[i] = 0; }
           
            else if (h[2*i]==-1 && h[2*i+1]!=-1) { h[i] = 1 + h[2*i+1]; }
            else if (h[2*i]!=-1 && h[2*i+1]==-1) { h[i] = 1 + h[2*i]  ; }
            else {
                if(h[2*i+1] > h[2*i]) { h[i] = 1+ h[2*i+1]; }
                else                  { h[i] = 1+ h[2*i]  ; }
            }//end-if-elseif
        }//end-if
    }//end-for
    return(0);
}//end-cheight()




//2026-05-11-----------------------------------------------------------------------------
int balance_factor(int h[], int bf[]){
    for(int i=0; i<SIZE; i++){
        bf[i] = h[2*i] - h[2*i+1];
    }
    return(0);
}

//2026-05-13-----------------------------------------------------------------------------
int is_f_vazia(TFila* d){  //1 para vazia, 0 para não
    if(d->size == 0) { return(1); }
    else{ return(0); }
}

int enqueue(TFila* d, char* data){
    if(d->size >= SIZE) { printf("ERRO na fila\n"); return(-1); }

    strcpy(d->fila[d->size++], data);
    return (0);
}

char* dequeue(TFila* d){ //fazer "free(retorno)" após usar o dado
    if(d->size == 0){ printf("Fila vazia\n"); return (NULL); }


    char* valor=malloc(50);
    strcpy(valor, d->fila[0]);
    for (int i = 0; i < d->size-1; i++) {
        strcpy(d->fila[i], d->fila[i+1]);
    }
    d->size--;

    return (valor);
}

int get_index(char ABB[][50], char* data){
    //Calcula o indice de um nó

    for(int i=0; i<SIZE; i++){
        if(strcmp(ABB[i], data) == 0){ return (i); }
    }
    return(-1);
}

//retorna indice do primeiro ancestral com BF == +-2
int get_idx_desb( int bf[], char ABB[][50], char* desb){
    int i=get_index(ABB, desb);

    while(i>0){
        if(bf[i] == 2 || bf[i] == -2){ return(i); }
        else { i=i/2; }
    }
    return(-1);
}

int remove_dado(char ABB[][50], char* dado){
    int i = get_index(ABB, dado);
    if(i==-1){ return(-1); }
    strcpy(ABB[i], "");
    return(0);
}

void preorder_getSubtree(char ABB[][50], TFila* d, int i){
    if(i >=SIZE || strcmp(ABB[i], "")==0) { return; }

    enqueue(d, ABB[i]);
    strcpy(ABB[i], "");
    preorder_getSubtree(ABB, d, 2*i);
    preorder_getSubtree(ABB, d, (2*i)+1);

}

int rot_lrc(int h[], int bf[], char ABB[][50], char* lastIn){
    char tmp[50];

    strcpy(tmp, lastIn); //ultimo inserte em tmp
    int iDesb = get_idx_desb(bf, ABB, tmp); //get indice do ultimo insert
    remove_dado(ABB, tmp);

    char A[50], C[50];
    strcpy(A, ABB[iDesb]); //indice do noh com BF = 2
    remove_dado(ABB, A);

    //strcpy(B, ABB[2 * iDesb]); //filho esq de A

    strcpy(C, ABB[2 * (2*iDesb) + 1]); //filho dir de B
    remove_dado(ABB, C);

    TFila Ar, Cl, Cr;  //tratamento de subarvores
    Ar.size = Cl.size = Cr.size = 0;
    for(int i=0; i<SIZE; i++){ 
        strcpy(Ar.fila[i], ""); 
        strcpy(Cl.fila[i], ""); 
        strcpy(Cr.fila[i], "");
    }
    int iAr = (2*iDesb)+1;
    int iCl = 2*(2*(2*iDesb)+1);
    int iCr = 2*(2*(2*iDesb)+1)+1;


    preorder_getSubtree(ABB, &Ar, iAr);
    preorder_getSubtree(ABB, &Cl, iCl);
    preorder_getSubtree(ABB, &Cr, iCr);

    //MUDANÇAS

    strcpy(ABB[iDesb], C);
    strcpy(ABB[2*iDesb + 1], A);

    //NOVOS ÍNDICES APÓS A ROTAÇÃO
    iAr = 2*(2*(iDesb) + 1) + 1;
    iCl = 2*(2*iDesb) + 1;
    iCr = 2*(2*iDesb + 1);

    while(is_f_vazia(&Ar) == 0){ //Reinsere Ar
        char* aux = dequeue(&Ar);
        insereabb(iAr, ABB, aux);
        free(aux); 
    }
    while(is_f_vazia(&Cl) == 0){ //Reinsere Cl
        char* aux = dequeue(&Cl);
        insereabb(iCl, ABB, aux);
        free(aux); 
    }while(is_f_vazia(&Cr) == 0){ //Reinsere Cr
        char* aux = dequeue(&Cr);
        insereabb(iCr, ABB, aux);
        free(aux); 
    }

    insereabb(iCr, ABB, tmp);

    for(int i=0; i<SIZE; i++){ h[i] = -1; bf[i] = 0;} //reinicia alturas e fatores
    cheight(ABB, h);
    balance_factor(h, bf);

   return(0);
}

void print_format(char ABB[][50], int h[], int bf[]){
    printf("\n(i, abb[i], h[i], bf[i]):\n ");
    for(int i=0; i<SIZE; i++) { if (strcmp(abb[i], "")!=0) { printf("(%2d, %s, %2d, %2d)\n ", i, ABB[i], h[i], bf[i]); } }
   
}

//------------------------------------------------------------------------------
//ABB (caixa alta) -> passagem por parametro
//abb (minuscula) -> vetor global
int main() {
    for(int i=0; i<SIZE; i++) { strcpy(abb[i], ""); h[i]=-1; bf[i]=0; }
   
    insereabb(1, abb, "Mar");
    insereabb(1, abb, "Dec");
    insereabb(1, abb, "May");
    insereabb(1, abb, "Aug");
    insereabb(1, abb, "Jan");
    insereabb(1, abb, "Nov");
    insereabb(1, abb, "Apr");
    insereabb(1, abb, "Feb");
    insereabb(1, abb, "Jul");
    insereabb(1, abb, "Jun");
    //insereabb(1, abb, "Set");
    //insereabb(1, abb, "Out");  
   
    cheight(abb, h);
    balance_factor(h, bf);
   
    //prn_ordem(1, abb, h);
   
    printf("ARVORE ANTES DA ROTACAO\n");
    print_format(abb, h, bf);

    rot_lrc(h, bf, abb, "Jun");

    printf("ARVORE APOS ROTACAO\n");
    print_format(abb, h, bf);

    return(0);
}//end-int main()