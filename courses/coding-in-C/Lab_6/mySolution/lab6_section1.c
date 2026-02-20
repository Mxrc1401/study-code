#include <stdio.h>

int main() {
    FILE *datei = fopen("test.txt", "w");
    if (datei == NULL) 
    return 1;

    fputc('B', datei);
    fputs("Marc\n", datei);
    fprintf(datei, "%d\n", 1401);

    fclose(datei);

    datei = fopen("test.txt", "r");
    if (datei == NULL)
    return 1;

    char zeichen;
    char zeile[100];
    int zahl;
    float wert;

    zeichen = fgetc(datei);
    fgets(zeile, 100, datei);
    fscanf(datei, "%d %f", &zahl, &wert);

    printf("%c\n", zeichen);
    printf("%s", zeile);
    printf("%d %.2f\n", zahl, wert);

    fclose(datei);
    return 0;
}
