#include <stdio.h>

//////////////////////////MAIN///////////////////////////////
int main(){
    float erste, zweite;
    char opp;
    float add(float erste, float zweite);
    float sub(float erste, float zweite);
    float div(float erste, float zweite);
    float mul(float erste, float zweite);

    printf("Geben Sie die erste Zahl ein:\n");
    scanf("%f", &erste);
    printf("Geben Sie die zweite Zahl ein:\n");
    scanf("%f", &zweite);
    printf("Geben Sie den Opperator ein (+,-,*,/) ein:\n");
    scanf(" %c", &opp);
    
    switch (opp) {
        case '+':
            printf("Ergebnis: %.2f\n", add(erste, zweite));
            break;
        case '-':
            printf("Ergebnis: %.2f\n", sub(erste, zweite));
            break;
        case '*':
            printf("Ergebnis: %.2f\n", mul(erste, zweite));
            break;
        case '/':
            if (zweite != 0) {
                printf("Ergebnis: %.2f\n", div(erste, zweite));
            }
            break;
        default:
            printf("Ungültiger Operator.\n");
    }
    return 0;
}
//////////////////////////MAIN///////////////////////////////
////////////////////////FUNKTIONEN///////////////////////////
float add(float erste, float zweite){
    return erste + zweite;
}

float sub(float erste, float zweite){
    return erste - zweite;
}

float mul(float erste, float zweite){
    return erste * zweite;
}

float div(float erste, float zweite){
    if (zweite != 0) {
        return erste / zweite;
    } else {
        printf("Division durch Null ist nicht erlaubt.\n");
        return 0;
    }
}

////////////////////////FUNKTIONEN///////////////////////////