#include "string_utils.h"
#include <assert.h>
#include <stdio.h>

int main() {
    // Test 1: Leerer String
    assert(custom_len("") == 0);
    printf("Test 1 passed: custom_len(\"\") == 0\n");

    // Test 2: Einzelner Buchstabe
    assert(custom_len("a") == 1);
    printf("Test 2 passed: custom_len(\"a\") == 1\n");

    // Test 3: Mehrere Buchstaben
    assert(custom_len("hello") == 5);
    printf("Test 3 passed: custom_len(\"hello\") == 5\n");

    // Test 4: String mit Leerzeichen
    assert(custom_len("hello world") == 11);
    printf("Test 4 passed: custom_len(\"hello world\") == 11\n");

    // Test 5: NULL Pointer
    assert(custom_len(NULL) == 0);
    printf("Test 5 passed: custom_len(NULL) == 0\n");

    printf("All tests passed!\n");
    return 0;
}