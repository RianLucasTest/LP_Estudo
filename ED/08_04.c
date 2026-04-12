#include <stdio.h>
#include <stdlib.h>

/* Node structure for doubly linked list */
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

/* Doubly linked list structure */
typedef struct {
    Node *first;
    Node *last;
} DoublyLinkedList;

/* Create a new node */
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Initialize an empty list */
void initList(DoublyLinkedList *list) {
    list->first = NULL;
    list->last  = NULL;
}

/* Insert as first node */
void insasfirst(DoublyLinkedList *list, int value) {
    Node *newNode = createNode(value);
    if (list->first == NULL) {
        list->first = list->last = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->prev = list->last;
        newNode->next = list->first;
        list->first->prev = newNode;
        list->last->next = newNode;
        list->first       = newNode;

    }
}

/* Insert as last node */
void insaslast(DoublyLinkedList *list, int value) {
    Node *newNode = createNode(value);
    if (list->last == NULL) {
        list->first = list->last = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        
    } else {
        newNode->prev = list->last;
        newNode->next = list->first;
        list->last->next = newNode;
        list->first->prev = newNode;
        list->last       = newNode;
    }
}



/* Print list forward */
void pfirst2last(const DoublyLinkedList *list) {
    Node *current = list->first;
    printf("\nlist[]: ");
    do{
        printf("%2d ", current->data);
        current = current->next;
    }while(current != list->first);
   
}

DoublyLinkedList sumNumbers(DoublyLinkedList *a, DoublyLinkedList *b){

    DoublyLinkedList result;
    initList(&result);

    Node *p = a->last;
    Node *q = b->last;

    int carry = 0;

    while(p || q || carry){

        int soma = carry;

        if(p){
            soma += p->data;
            if(p == a->first) p = NULL;
            else p = p->prev;
        }

        if(q){
            soma += q->data;
            if(q == b->first) q = NULL;
            else q = q->prev;
        }

        insasfirst(&result, soma % 10);

        carry = soma / 10;
    }

    return result;
}

char* numToStr(long long int num){
    long long int tmp=num, cont=0;
    while(tmp!=0){
        tmp=tmp/10;
        cont++;
    }
    char* n=malloc(sizeof(char)*(cont+1));
    n[cont] = '\0';

    for(int i = cont-1; i >= 0; i--){
        n[i] = (num % 10) + '0';
        num = num / 10;
    }
    return n;
}


int main() {
    DoublyLinkedList list_result, n1, n2;
    initList(&n1);
    initList(&n2);

    char* num1=numToStr(583741296);
    char* num2=numToStr(904652137);

    for(int i=0; num1[i] != '\0'; i++){
        insaslast(&n1, num1[i]-48);
    }
    
    for(int i=0; num2[i] != '\0'; i++){
        insaslast(&n2, num2[i]-48);
    }

    list_result=sumNumbers(&n1, &n2);

    pfirst2last(&list_result);

    //freeList(&list);
    return 0;
}