#include <stdio.h>

char Klasse[50];
int Besatzung;
int Missionstage;
long long km;
float km1;
float reichweite; 


int main()
{
/////////////////////EINGABE/////////////////////////////////////////
    printf("Bitte geben Sie die Klasse ein:");
    scanf("%49s", Klasse);
    printf("Teilnehmeranzahl:");
    scanf("%d", &Besatzung);
    printf("Missionstage:");
    scanf("%d", &Missionstage);
    printf("Wie viele Kilometer:");
    scanf("%lld", &km);
    printf("Wie viel Prozent:");
    scanf("%f", &km1);
    printf("Die Reichweite:");
    scanf("%f", &reichweite);
/////////////////////EINGABE/////////////////////////////////////////
///////////////////////////////AUSGBE/////////////////////////////////
    printf("%-30s","Name                          Klasse\n");
    printf("--------------------------------------------\n");
    printf("%-30s %s \n", "Klasse", Klasse);
    printf("%-30s %d \n", "Besatzung", Besatzung);
    printf("%-30s %d \n","Missionstage", Missionstage);
    printf("%-30s %lld \n","Klasse Zuruckgelegte Km", km);
    printf("%-30s %.1f \n","% der Km", km1);
    printf("%-30s %.3f \n","Reichweite", reichweite);
////////////////////////////////AUSGABE////////////////////////////////
    return 0;
    
}
