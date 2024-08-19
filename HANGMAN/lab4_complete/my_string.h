// my_string.h


#ifndef MY_STRING_H
#define MY_STRING_H
#include <stdio.h> // Include stdio.h near the top of the file


typedef struct My_string {
	int size;        // Number of characters the string currently holds
	int capacity;    // Number of characters the string CAN hold
	char *data;      // Pointer to a dynamic array of characters representing the string
} My_string;

typedef My_string* MY_STRING;

// Enumeration for Status
typedef enum {
	FAILURE,
	SUCCESS
} Status;


typedef enum {
	FALSE,
	TRUE
} Boolean;


Boolean my_string_empty(MY_STRING hMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);


Status my_string_push_back(MY_STRING hMy_string, char item);
Status my_string_pop_back(MY_STRING hMy_string);
char* my_string_at(MY_STRING hMy_string, int index);
char* my_string_c_str(MY_STRING hMy_string);


// Declaration for my_string_extraction function
Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

// Declaration for my_string_insertion function
Status my_string_insertion(MY_STRING hMy_string, FILE* fp);


MY_STRING my_string_init_default(void);
MY_STRING my_string_init_c_string(const char* c_string);
void my_string_destroy(MY_STRING* phMy_string);


int my_string_get_capacity(MY_STRING hMy_string);
int my_string_get_size(MY_STRING hMy_string);
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

#endif /* MY_STRING_H  */



