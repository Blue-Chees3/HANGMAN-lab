#include <stdio.h>
#include "my_string.h"

#define ARRAY_SIZE 100

int main(int argc, char* argv[]) {

    // Create an array of MY_STRING handles with 100 elements
    MY_STRING string_array[ARRAY_SIZE];

    // Initialize each element of the array to NULL
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        string_array[i] = NULL;
    }

    // Initialize the first element of the array to "COPY ME!"
    string_array[0] = my_string_init_c_string("COPY ME!");

    // Use init_copy function to copy the first string into every other element of the array
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        string_array[i] = my_string_init_copy(string_array[0]);
    }

    // Destroy the object in the index 0 position of the array
    my_string_destroy(&string_array[0]);

    // Initialize the first element of the array to "FIRST FIFTY!"
    string_array[0] = my_string_init_c_string("FIRST FIFTY!");

    // Call my_string_assignment to copy the value of the first array element into the first fifty elements of the array (0-49)
    for (int i = 0; i < 50; ++i) {
        my_string_assignment(string_array[i], string_array[0]);
    }

    // Call my_string_swap to swap the values of the first 50 elements of the array with the last 50 elements
    for (int i = 0; i < 50; ++i) {
        my_string_swap(string_array[i], string_array[ARRAY_SIZE - 1 - i]);
    }

    // Print each element of the array before destroying it
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        my_string_insertion(string_array[i], stdout);
        printf("\n");
        my_string_destroy(&string_array[i]);
    }

    return 0;
}

