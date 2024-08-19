// my_string.c


#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"


Status my_string_push_back(MY_STRING hMy_string, char item) {
	My_string* str = (My_string*)hMy_string;
	if (str == NULL) {
		return FAILURE; //return failure if the handle is NULL

	}

	// Check if there is enough room to add the character
	if (str->size >= str->capacity) {
		//Resize
		int new_capacity = (str->capacity == 0) ? 1 : str->capacity * 2;
		char* new_data = realloc(str->data, new_capacity);
		if (new_data == NULL) {
			return FAILURE; 
		}
		str->data = new_data;
		str->capacity = new_capacity;
	}

	//add new character at the end and update size
	str->data[str->size++] = item;

	return SUCCESS; //Push was a success
}


Status my_string_pop_back(MY_STRING hMy_string) {
	My_string* str = (My_string*)hMy_string;
	if (str == NULL || str->size == 0) {
		return FAILURE;
	}
	str->data[--str->size] = '\0';

	return SUCCESS;
}


char* my_string_at(MY_STRING hMy_string, int index) {
	My_string* str = (My_string*)hMy_string;
	if (str == NULL || index < 0 || index >= str-> size) {
		return NULL;
	}
	//return the address at specified index
	return &(str->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string) {
    // Cast the handle to the appropriate struct type
    My_string* str = (My_string*)hMy_string;

    // Check if the handle is NULL
    if (str == NULL) {
        return NULL;
    }

    // Ensure that the string is null-terminated
    if (str->size + 1 > str->capacity) {
        // Reallocate memory to ensure space for the null terminator
        int new_capacity = str->size + 1;
        char* new_data = realloc(str->data, new_capacity);
        if (new_data == NULL) {
            return NULL; // Memory allocation failed
        }
        str->data = new_data;
        str->capacity = new_capacity;
    }

    // Null-terminate the string
    str->data[str->size] = '\0';

    // Return a pointer to the string data
    return str->data;
}




Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
    My_string* result = (My_string*)hResult;
    My_string* append = (My_string*)hAppend;
    if (result == NULL || append == NULL) {
        return FAILURE; // Return FAILURE if any handle is NULL
    }
    
    // Ensure capacity for the concatenated string
    int new_size = result->size + append->size;
    if (new_size + 1 > result->capacity) {
        int new_capacity = new_size + 1;
        char* new_data = realloc(result->data, new_capacity);
        if (new_data == NULL) {
            return FAILURE; // Return FAILURE if realloc fails
        }
        result->data = new_data;
        result->capacity = new_capacity;
    }
    
    // Concatenate the strings
    for (int i = 0; i < append->size; ++i) {
        result->data[result->size + i] = append->data[i];
    }
    result->size = new_size;
    result->data[result->size] = '\0';
    
    return SUCCESS; // Return SUCCESS if concatenation is successful
}

// Function to check if the string is empty
Boolean my_string_empty(MY_STRING hMy_string) {
    My_string* str = (My_string*)hMy_string;
    if (str == NULL) {
        return TRUE; // Return TRUE if handle is NULL
    }
    return (str->size == 0) ? TRUE : FALSE;
}


Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
    if (hMy_string == NULL || fp == NULL) {
        return FAILURE; // Return FAILURE if the string handle or file pointer is NULL
    }

    My_string* str = (My_string*)hMy_string;
    int capacity = str->capacity;
    int size = 0;

    int* size_ptr = &(str->size);

    // Read characters until whitespace or end of file
	char c;

       
	while (((c = fgetc(fp))) != EOF&& !isspace(c)) {
        // Resize the string if needed
	
        if (size >= capacity) {
            capacity *= 2;
            char* newData = realloc(str->data, capacity);
	    
            if (newData == NULL) {
                return FAILURE; // Return FAILURE if realloc fails
            }
            str->data = newData;
            str->capacity = capacity;
		
	 }
        
        // Store the character in the string
	       
       	str->data[size] = c;
	size++;
	
    }
	
    // Terminate the string with null character
    str->data[size] = '\0';
   //Push back last character read
    //ungetc(c,fp);
	//printf("this is extraction size: %d\n", size);
	*size_ptr=size;
   // str->size = size;

    // Check for end of file
    if (c == EOF) {
        return FAILURE; // Return FAILURE if EOF is encountered prematurely
    }

    return SUCCESS; // Return SUCCESS if string extraction is successful
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
    My_string* str = (My_string*)hMy_string;
    if (str == NULL || fp == NULL) {
        return FAILURE; // Return FAILURE if the handle or file stream is NULL
    }

    // Write the string data to the file stream using fprintf
    fprintf(fp, "%s", str->data);

    // Check for any error during writing
    if (ferror(fp)) {
        return FAILURE; // Return FAILURE if an error occurred during writing
    }

    return SUCCESS; // Return SUCCESS if writing was successful
}

// Other functions remain the same...





MY_STRING my_string_init_default(void) {
	My_string *str = (My_string*)malloc(sizeof(My_string));
	if (str == NULL) {
        	return NULL; // Return NULL on failure
	}
	str->size = 0;
	str->capacity = 7; //Default capacity
	str->data = (char*)malloc(sizeof(char) * str->capacity); // Allocate space for the dynamic array of characters
	if (str->data == NULL) {
		free(str); // Clean up allocated memory on failure
		return NULL;
	}
	str->data[0] = '\0'; // Initialize the string with an empty string
	return (MY_STRING)str;
}




MY_STRING my_string_init_c_string(const char* c_string) {
    if (c_string == NULL) {
        return NULL; // Return NULL if c_string is NULL
    }

    // Calculate the length of the c-string
    size_t length = strlen(c_string);

    // Allocate memory for the My_string struct
    My_string* str = (My_string*)malloc(sizeof(My_string));
    if (str == NULL) {
        return NULL; // Return NULL on failure
    }

    // Set capacity to exactly one greater than the length of the c-string
    str->capacity = length + 1;
    str->size = length;

    // Allocate space for the dynamic array of characters
    str->data = (char*)malloc(str->capacity * sizeof(char));
    if (str->data == NULL) {
        free(str); // Clean up allocated memory on failure
        return NULL;
    }

    // Copy the contents of the c-string to the data array
    strcpy(str->data, c_string);

    return (MY_STRING)str;
}



void my_string_destroy(MY_STRING* phMy_string) {
	if (phMy_string != NULL && *phMy_string != NULL) {
		My_string *str = (My_string*)*phMy_string;
		free(str->data); // Free the dynamic array of characters
		free(str);       // Free the My_string object
		*phMy_string = NULL;
	}
}

// Function to get the capacity of a My_string object
int my_string_get_capacity(MY_STRING hMy_string) {
	if (hMy_string == NULL) {
		return -1; // Invalid handle, return -1 as error indicator
    }
	return hMy_string->capacity; // Return the capacity of the string object
}

// Function to get the size of a My_string object
int my_string_get_size(MY_STRING hMy_string) {
//	My_string *pString = (My_string*)hMy_string;

//	return pString->size;
		
	if (hMy_string == NULL) {
		return -1; // Invalid handle, return -1 as error indicator
	}
	return hMy_string->size; // Return the size of the string object
}

// Function to compare two My_string objects lexicographically
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	if (hLeft_string == NULL || hRight_string == NULL) {
		return -2; // Invalid handle, return -2 as error indicator
	}
	return strcmp(hLeft_string->data, hRight_string->data); // Compare the strings using strcmp
}



Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight) {
    // Check if both handles are valid
    if (hLeft == NULL || hRight == NULL) {
        return FAILURE;
    }

    // Cast handles to My_string pointers
    My_string* left = (My_string*)hLeft;
    My_string* right = (My_string*)hRight;

    if(left==right)
    {
	    return SUCCESS;
	}

    // Ensure the destination string has enough capacity
    if (left->capacity < right->size + 1) {
        // Resize the destination string's buffer
        char* new_data = realloc(left->data, right->size + 1);
        if (new_data == NULL) {
            return FAILURE; // Failed to reallocate memory
        }
        left->data = new_data;
        left->capacity = right->size + 1;
    }

    // Copy the contents of the right string to the left string
    strcpy(left->data, right->data);
    left->size = right->size;

    return SUCCESS;
}




MY_STRING my_string_init_copy(MY_STRING hMy_string) {
    // Check if handle is valid
    if (hMy_string == NULL) {
        return NULL;
    }

    // Cast handle to string pointer
    My_string* original = (My_string*)hMy_string;

    // Allocate memory for the copy
    MY_STRING copy = my_string_init_default();
    if (copy == NULL) {
        return NULL;
    }

    // Deep copy
    for (int i = 0; i < original->size; ++i) {
        if (my_string_push_back(copy, original->data[i]) == FAILURE) {
            my_string_destroy(&copy);
            return NULL;
        }
    }

    return copy;
}



void my_string_swap(MY_STRING hLeft, MY_STRING hRight) {
    if (hLeft == NULL || hRight == NULL) {
        return;
    }

    My_string* left = (My_string*)hLeft;
    My_string* right = (My_string*)hRight;

    // Swap the size and capacity of the string objects
    size_t temp_size = left->size;
    left->size = right->size;
    right->size = temp_size;

    size_t temp_capacity = left->capacity;
    left->capacity = right->capacity;
    right->capacity = temp_capacity;

    // Swap the data pointers
    char* temp_data = left->data;
    left->data = right->data;
    right->data = temp_data;
}

