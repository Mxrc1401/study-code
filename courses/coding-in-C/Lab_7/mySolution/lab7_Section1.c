#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    int *arr;
    int *new_arr;
    printf("Geben Sie N ein: ");
    scanf("%d", &N);

    arr = (int *)calloc(N, sizeof(int));
    if (arr == NULL) {
        printf("Speicherreservierung fehlgeschlagen.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = i * i;
    }
    printf("Array-Inhalt:\n");
    for (int i = 0; i < N; i++) {
        printf("arr[%d]= %d\n", i, arr[i]);
    }
    new_arr = (int *)realloc(arr, 2*sizeof(arr));
    printf("Neue Array-Inhalt:\n");
    for (int i = 0; i < N*2; i++) {
        printf("arr[%d]= %d\n", i, i * i);
    }

    free(arr);

    return 0;
}
