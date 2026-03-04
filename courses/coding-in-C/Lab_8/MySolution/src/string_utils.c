#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

size_t custom_len(const char *str) {
    if (str == NULL) {
        return 0;
    }
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


char* read_line_dynamic(void) {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }
    
    size_t len = custom_len(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }
    char *result = (char*)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
    for (size_t i = 0; i <= len; i++) {
        result[i] = buffer[i];
    }
    return result;
}

