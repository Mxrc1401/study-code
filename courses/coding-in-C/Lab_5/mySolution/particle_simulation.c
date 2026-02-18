#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_SIZE 10
#define NUM_STEPS 10

int main(void)
{
    // Zufallszahlengenerator mit Seed vom aktuellen Zeitpunkt initialisieren
    srand(time(NULL));
    
    // Hauptfeld-Array erstellen (alle Werte sind zunächst 0)
    int field[FIELD_SIZE] = {0};
    int *p_field = field;
    
    // Drei Partikel an den Positionen 2, 4 und 6 platzieren
    *(p_field + 2) = 1;
    *(p_field + 4) = 1;
    *(p_field + 6) = 1;
    
    printf("=== Partikel-Simulation ===\n\n");
    
    // Simulationsschleife: diskrete Zeitschritte
    for (int time = 0; time < NUM_STEPS; time++) {
        // Aktuellen Zustand des Feldes ausgeben
        printf("Zeit %d: ", time);
        for (int i = 0; i < FIELD_SIZE; i++) {
            printf("%d ", *(p_field + i));
        }
        printf("\n");
        
        // Temporäres Array für den nächsten Zustand erstellen
        int temp_field[FIELD_SIZE] = {0};
        int *p_temp = temp_field;
        
        // Jedes Partikel zufällig nach links oder rechts bewegen
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (*(p_field + i) == 1) {
                // Partikel gefunden an Position i
                int direction = rand() % 2;  // 0 = links, 1 = rechts
                int new_pos = i;
                
                if (direction == 0) {
                    // Nach links bewegen: stelle sicher, dass wir nicht unter 0 gehen
                    new_pos = (i > 0) ? i - 1 : i;
                } else {
                    // Nach rechts bewegen: stelle sicher, dass wir nicht über FIELD_SIZE - 1 gehen
                    new_pos = (i < FIELD_SIZE - 1) ? i + 1 : i;
                }
                
                // Zähler an neuer Position erhöhen (um Kollisionen zu erkennen)
                *(p_temp + new_pos) = *(p_temp + new_pos) + 1;
            }
        }
        
        // Kollisionen behandeln: Partikel, die sich in die gleiche Zelle bewegen, vernichten sich
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (*(p_temp + i) > 1) {
                // Kollision erkannt: entferne alle Partikel an dieser Position
                printf("  --> Kollision bei Index %d (%d Partikel)\n", i, *(p_temp + i));
                *(p_temp + i) = 0;
            } else if (*(p_temp + i) == 1) {
                // Einzelnes Partikel überlebt
                *(p_temp + i) = 1;
            }
        }
        
        // Temporäres Array mit Pointer-Arithmetik zurück ins Hauptfeld kopieren
        for (int i = 0; i < FIELD_SIZE; i++) {
            *(p_field + i) = *(p_temp + i);
        }
        
        printf("\n");
    }
    
    printf("=== Simulation abgeschlossen ===\n\n");
    
    printf("=== ERKLÄRUNG ===\n\n");
    printf("Pointer-Dereferenzierung und Pointer-Arithmetik:\n");
    printf("  - p_field zeigt auf das erste Element des Feldes\n");
    printf("  - *(p_field + i) greift auf das Element bei Index i zu (äquivalent zu field[i])\n");
    printf("  - *(p_temp + i) = *(p_temp + i) + 1 erhöht den Zähler bei Index i\n\n");
    
    printf("Beziehung zwischen Arrays und Pointern:\n");
    printf("  - Arrays in C werden zu Pointern umgewandelt (Array-zu-Pointer-Zerfall)\n");
    printf("  - field wird zu &field[0] (Pointer auf erstes Element)\n");
    printf("  - field[i] ist syntaktischer Zucker für *(field + i)\n");
    printf("  - Pointer unterstützen Pointer-Arithmetik: (p + i) berechnet p + i*sizeof(*p)\n\n");
    
    printf("Behandlung von Kollisionen:\n");
    printf("  - Temporäres Array zählt Partikel, die sich zu jeder Position bewegen\n");
    printf("  - Wenn Zähler > 1, kollidieren Partikel und vernichten sich (auf 0 setzen)\n");
    printf("  - Wenn Zähler = 1, setzt sich Partikel fort (auf 1 setzen)\n");
    printf("  - Bereichsprüfung stellt sicher, dass Partikel innerhalb von 0 bis %d bleiben\n", FIELD_SIZE - 1);
    
    return 0;
}
