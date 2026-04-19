#include <stdio.h>
#include<string.h>
#define MAX_VET 16
#define MAX_STR 32

int preordert(int i, char t[][MAX_STR]) {
if ( (i > MAX_VET) || !(strcmp(t[i]," ")) ) {
return(0);
}
printf("%s ", t[i]);
preordert((2*i), t);
preordert(((2*i)+1), t);
return(0);
}

int inordert(int i, char t[][MAX_STR]) {
if ( (i > MAX_VET) || !(strcmp(t[i]," ")) ) {
return(0);
}
inordert((2*i), t);
printf("%s ", t[i]);
inordert(((2*i)+1), t);
return(0);
}

int posordert(int i, char t[][MAX_STR]) {
if ( (i > MAX_VET) || !(strcmp(t[i]," ")) ) {
return(0);
}
posordert((2*i), t);
posordert(((2*i)+1), t);
printf("%s ", t[i]);
return(0);
}

int main() {
char a[MAX_VET][MAX_STR];

for(int i=0; i<MAX_VET; i++) {
strcpy(a[i]," ");
}

strcpy(a[1],"Zebra");
strcpy(a[2],"Urso");
strcpy(a[3],"Zorro");
strcpy(a[4],"Morcego");
strcpy(a[5],"Rato");
strcpy(a[8],"Leao");
strcpy(a[11],"Tatu");

preordert(1,a);
    printf("\n");
    inordert(1,a);
    printf("\n");
    posordert(1,a);
return 0;
}