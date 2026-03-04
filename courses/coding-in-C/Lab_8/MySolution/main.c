#include "include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a string: ");
    char *input = read_line_dynamic();
    if (input == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    printf("You entered: %s\n", input);
    printf("Length: %zu\n", custom_len(input));
    free(input);
    return 0;
}