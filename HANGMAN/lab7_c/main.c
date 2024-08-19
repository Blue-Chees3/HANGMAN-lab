#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h" // Assuming this is your string-handling module
#include "generic_vector.h" // Assuming this is your vector module

#define MAX_WORD_LENGTH 29
#define DICT_FILE "dictionary.txt"

int main() {
    FILE *file = fopen(DICT_FILE, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        return 1;
    }

    // Create an array of vectors, each vector holds words of the same length
    Vector *word_vectors[MAX_WORD_LENGTH + 1]; // Index 0 is unused, so add 1
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        word_vectors[i] = generic_vector_init_default();
        if (word_vectors[i] == NULL) {
            fprintf(stderr, "Error creating vector for words of length %d\n", i);
            return 1;
        }
    }

    // Read words from the dictionary file and store them in the appropriate vector
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) == 1) {
        int word_length = strlen(word);
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            MY_STRING my_word = my_string_init_c_string(word);
            if (my_word == NULL) {
                fprintf(stderr, "Error creating MyString object for word %s\n", word);
                return 1;
            }
            generic_vector_push_back(word_vectors[word_length], my_word);
        }
    }

    // Print the size of each vector
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("Words of length %d: %zu\n", i, generic_vector_get_size(word_vectors[i]));
    }

    // Clean up
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        generic_vector_destroy(&word_vectors[i]);
    }
    fclose(file);
    return 0;
}

