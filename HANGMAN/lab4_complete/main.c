#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"


int main(int argc, char* argv[]) {
    // Create two string objects
    MY_STRING hStr1 = my_string_init_default();
    MY_STRING hStr2 = my_string_init_default();

    // Push characters to the first string
    my_string_push_back(hStr1, 'H');
    my_string_push_back(hStr1, 'e');
    my_string_push_back(hStr1, 'l');
    my_string_push_back(hStr1, 'l');
    my_string_push_back(hStr1, 'o');

    // Print the first string
    printf("String 1: %s\n", my_string_c_str(hStr1));

    // Push characters to the second string
    my_string_push_back(hStr2, 'W');
    my_string_push_back(hStr2, 'o');
    my_string_push_back(hStr2, 'r');
    my_string_push_back(hStr2, 'l');
    my_string_push_back(hStr2, 'd');

    // Print the second string
    printf("String 2: %s\n", my_string_c_str(hStr2));

    // Concatenate the two strings
    my_string_concat(hStr1, hStr2);

    // Print the concatenated string
    printf("Concatenated String: %s\n", my_string_c_str(hStr1));

    // Pop characters from the concatenated string
    my_string_pop_back(hStr1);
    my_string_pop_back(hStr1);

    // Print the modified concatenated string
    printf("Modified Concatenated String: %s\n", my_string_c_str(hStr1));

    // Access characters at specific indices in the concatenated string
    printf("Character at index 0: %c\n", *my_string_at(hStr1, 0));
    printf("Character at index 3: %c\n", *my_string_at(hStr1, 3));
    printf("Character at index 6: %c\n", *my_string_at(hStr1, 6));

    // Check if the concatenated string is empty
    printf("Is concatenated string empty? %s\n", my_string_empty(hStr1) ? "Yes" : "No");

    // Destroy the string objects
    my_string_destroy(&hStr1);
    my_string_destroy(&hStr2);

    return 0;
}

