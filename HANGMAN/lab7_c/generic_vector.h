#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    void **data;
    size_t size;
    size_t capacity;
} Vector;

Vector *generic_vector_init_default() {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    if (vector == NULL) {
        return NULL; // Allocation failed
    }
    vector->data = (void **)malloc(INITIAL_CAPACITY * sizeof(void *));
    if (vector->data == NULL) {
        free(vector); // Clean up previously allocated memory
        return NULL; // Allocation failed
    }
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    return vector;
}

size_t generic_vector_get_size(const Vector *vector) {
    if (vector == NULL) {
        return 0;
    }
    return vector->size;
}

void generic_vector_push_back(Vector *vector, void *element) {
    if (vector == NULL || element == NULL) {
        return;
    }
    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        void **new_data = (void **)realloc(vector->data, new_capacity * sizeof(void *));
        if (new_data == NULL) {
            return; // Reallocation failed
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->data[vector->size++] = element;
}

void *generic_vector_at(const Vector *vector, size_t index) {
    if (vector == NULL || index >= vector->size) {
        return NULL;
    }
    return vector->data[index];
}

void generic_vector_destroy(Vector **vector) {
    if (vector == NULL || *vector == NULL) {
        return;
    }
    free((*vector)->data);
    free(*vector);
    *vector = NULL;
}

