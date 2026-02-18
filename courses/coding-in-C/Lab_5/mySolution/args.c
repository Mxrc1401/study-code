#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    // Prüfe, ob mindestens ein Argument übergeben wurde (außer dem Programmnamen)
    if (argc < 2) {
        printf("Verwendung: %s <arg1> [arg2] ...\n", argv[0]);
        return 1;
    }

    printf("=== VARIANTE 1: Mit Array-Indizierung (argv[i]) ===\n");
    for (int i = 0; i < argc; i++) {
        size_t len = strlen(argv[i]);
        printf("Argument %d unter Adresse \"%016llX\" mit Inhalt: %s (Länge: %zu)\n",
               i, (unsigned long long)(uintptr_t)argv[i], argv[i], len);
    }

    printf("\n=== VARIANTE 2: Mit Pointer-Dereferenzierung (*(argv + i)) ===\n");
    for (int i = 0; i < argc; i++) {
        char *arg = *(argv + i);  // Pointer-Dereferenzierung: äquivalent zu argv[i]
        size_t len = strlen(arg);
        printf("Argument %d unter Adresse \"%016llX\" mit Inhalt: %s (Länge: %zu)\n",
               i, (unsigned long long)(uintptr_t)arg, arg, len);
    }

    printf("\n=== ERKLÄRUNG ===\n\n");
    printf("Beziehung zwischen Indizierung [] und Pointer-Dereferenzierung *:\n");
    printf("  Array-Indizierung argv[i] ist SYNTAKTISCHER ZUCKER für *(argv + i)\n");
    printf("  - argv[i]        --> *(argv + i)     --> greife auf Element i zu\n");
    printf("  - argv[0]        --> *argv           --> erstes Element\n");
    printf("  - argv[1]        --> *(argv + 1)     --> zweites Element\n\n");

    printf("Beziehung zwischen Arrays und Pointern:\n");
    printf("  In C werden Arrays zu Pointern auf das erste Element umgewandelt:\n");
    printf("  - argv ist ein char** (Pointer auf char-Pointer)\n");
    printf("  - *(argv + i) dereferenziert den Pointer, um den char* bei Index i zu erhalten\n");
    printf("  - **((argv + i)) würde zweimal dereferenzieren, um einen char-Wert zu erhalten\n");
    printf("  - Array-Schreibweise argv[i] ist äquivalent zur Pointer-Arithmetik *(argv + i)\n\n");

    printf("Speicherlayout:\n");
    printf("  argv zeigt auf ein Array von char*-Pointern:\n");
    printf("  argv[0] --> weist auf Programmnamen hin (eine C-Zeichenkette)\n");
    printf("  argv[1] --> weist auf erstes Argument hin (eine C-Zeichenkette)\n");
    printf("  argv[2] --> weist auf zweites Argument hin (eine C-Zeichenkette)\n");
    printf("  ...\n");

    return 0;
}
