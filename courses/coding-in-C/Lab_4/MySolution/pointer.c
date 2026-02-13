#include <stdio.h>

int main(){
    int myNumbers[5] = {10,20,30,40,50};
    int *p2 = myNumbers +1;
    int *p3 = myNumbers +4;

    printf("Adresse des zweiten Elements: %p\n", p2);
    printf("Adresse des letzten Elements: %p\n", p3);
    printf("Differenz der Adressen: %ld\n", p3 - p2);



    return 0;
}