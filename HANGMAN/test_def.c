#include "unit_test.h"


Status test_init_default_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    
    if (hString == NULL)
    {
        strncpy(buffer, "test_init_default_returns_nonNULL\n"
                       "my_string_init_default returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if (hString == NULL || my_string_get_size(hString) != 0)
    {
        status = FAILURE;
        snprintf(buffer, length, "test_get_size_on_init_default_returns_0\n"
                                   "Expected a size of 0 but got %d\n",
                                   (hString != NULL) ? my_string_get_size(hString) : -1);
    }
    else
    {
        status = SUCCESS;
        snprintf(buffer, length, "test_get_size_on_init_default_returns_0\n");
    }

    my_string_destroy(&hString);
    return status;
}


Status test_push_back_adds_character(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_push_back_adds_character\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    char ch = 'a';
    Status status = my_string_push_back(hString, ch);
    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_adds_character\n"
                       "Failed to push character back into string", length);
        return FAILURE;
    }

    if (my_string_get_size(hString) != 1)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_adds_character\n"
                       "Size of string after push back is not as expected", length);
        return FAILURE;
    }

    if (*my_string_at(hString, 0) != ch)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_adds_character\n"
                       "Character at index 0 is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_push_back_adds_character\n", length);
    return SUCCESS;
}
/*
Status test_pop_back_removes_character(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_pop_back_removes_character\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_pop_back(hString);
    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\n"
                       "Failed to pop character back from string", length);
        return FAILURE;
    }

    if (my_string_get_size(hString) != 4)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\n"
                       "Size of string after pop back is not as expected", length);
        return FAILURE;
    }

    if (*my_string_at(hString, my_string_get_size(hString)) != '\0')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\n"
                       "Character at end of string is not NULL", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_pop_back_removes_character\n", length);
    return SUCCESS;
}
*/

Status test_empty_string_is_empty(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_empty_string_is_empty\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (!my_string_empty(hString))
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_empty_string_is_empty\n"
                       "my_string_empty did not return TRUE for an empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_empty_string_is_empty\n", length);
    return SUCCESS;
}


Status test_non_empty_string_is_not_empty(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_non_empty_string_is_not_empty\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (my_string_empty(hString))
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_non_empty_string_is_not_empty\n"
                       "my_string_empty returned TRUE for a non-empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_non_empty_string_is_not_empty\n", length);
    return SUCCESS;
}

Status test_push_back_adds_characters(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_push_back_adds_characters\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (my_string_push_back(hString, 'H') == FAILURE || my_string_push_back(hString, 'i') == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_adds_characters\n"
                       "Failed to push characters back to the string", length);
        return FAILURE;
    }

    if (my_string_get_size(hString) != 2 || strcmp(my_string_c_str(hString), "Hi") != 0)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_adds_characters\n"
                       "String content after push back is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_push_back_adds_characters\n", length);
    return SUCCESS;
}

Status test_get_character_at_index(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_get_character_at_index\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    char* char_at_index = my_string_at(hString, 2); // Get character at index 2
    if (char_at_index == NULL || *char_at_index != 'l')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_get_character_at_index\n"
                       "Character at index 2 is not 'l'", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_get_character_at_index\n", length);
    return SUCCESS;
}

Status test_c_str_returns_valid_c_string(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_c_str_returns_valid_c_string\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    char* c_string = my_string_c_str(hString);
    if (c_string == NULL || strcmp(c_string, "Hello") != 0)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_c_str_returns_valid_c_string\n"
                       "Returned C-style string is not 'Hello'", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_c_str_returns_valid_c_string\n", length);
    return SUCCESS;
}

Status test_concatenation_result_is_correct(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = my_string_init_c_string(" World");
    if (hString1 == NULL || hString2 == NULL)
    {
        strncpy(buffer, "test_concatenation_result_is_correct\n"
                       "Failed to initialize string objects", length);
        return FAILURE;
    }

    Status status = my_string_concat(hString1, hString2);
    if (status == FAILURE || strcmp(my_string_c_str(hString1), "Hello World") != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concatenation_result_is_correct\n"
                       "Concatenation result is not 'Hello World'", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_concatenation_result_is_correct\n", length);
    return SUCCESS;
}

Status test_pop_back_on_empty_string_returns_failure(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_pop_back_on_empty_string_returns_failure\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_pop_back(hString); // Try to pop back from an empty string
    if (status != FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_on_empty_string_returns_failure\n"
                       "my_string_pop_back did not return FAILURE on an empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_pop_back_on_empty_string_returns_failure\n", length);
    return SUCCESS;
}


Status test_pop_back_removes_last_character(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_pop_back_removes_last_character\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_pop_back(hString); // Pop back from "Hello" -> "Hell"
    if (status == FAILURE || strcmp(my_string_c_str(hString), "Hell") != 0)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_last_character\n"
                       "Failed to remove last character from the string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_pop_back_removes_last_character\n", length);
    return SUCCESS;
}




Status test_at_returns_correct_character(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_at_returns_correct_character\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (*my_string_at(hString, 1) != 'e' || *my_string_at(hString, 4) != 'o')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_at_returns_correct_character\n"
                       "Returned character at index is not correct", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_at_returns_correct_character\n", length);
    return SUCCESS;
}

Status test_concat_concatenates_strings(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = my_string_init_c_string(" World");

    if (hString1 == NULL || hString2 == NULL)
    {
        strncpy(buffer, "test_concat_concatenates_strings\n"
                       "Failed to initialize string objects", length);
        return FAILURE;
    }

    if (my_string_concat(hString1, hString2) == FAILURE || strcmp(my_string_c_str(hString1), "Hello World") != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concat_concatenates_strings\n"
                       "Concatenation of strings failed", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_concat_concatenates_strings\n", length);
    return SUCCESS;
}

Status test_c_str_returns_valid_c_string_after_concatenation(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = my_string_init_c_string(" World");

    if (hString1 == NULL || hString2 == NULL)
    {
        strncpy(buffer, "test_c_str_returns_valid_c_string_after_concatenation\n"
                       "Failed to initialize string objects", length);
        return FAILURE;
    }

    my_string_concat(hString1, hString2);
    char* c_str = my_string_c_str(hString1);
    if (c_str == NULL || strcmp(c_str, "Hello World") != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_c_str_returns_valid_c_string_after_concatenation\n"
                       "Returned C-style string after concatenation is not valid", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_c_str_returns_valid_c_string_after_concatenation\n", length);
    return SUCCESS;
}

Status test_concat_with_empty_string(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("Hello");
    MY_STRING hString2 = my_string_init_default();

    if (hString1 == NULL || hString2 == NULL)
    {
        strncpy(buffer, "test_concat_with_empty_string\n"
                       "Failed to initialize string objects", length);
        return FAILURE;
    }

    my_string_concat(hString1, hString2);
    if (strcmp(my_string_c_str(hString1), "Hello") != 0)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concat_with_empty_string\n"
                       "Concatenation with empty string failed", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_concat_with_empty_string\n", length);
    return SUCCESS;
}

Status test_get_capacity_returns_correct_capacity(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("Hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_get_capacity_returns_correct_capacity\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (my_string_get_capacity(hString) != 6)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_get_capacity_returns_correct_capacity\n"
                       "Returned capacity is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_get_capacity_returns_correct_capacity\n", length);
    return SUCCESS;
}


Status test_empty_returns_true_for_empty_string(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_empty_returns_true_for_empty_string\n"
                       "Failed to initialize string object", length);
        return FAILURE;
    }

    if (my_string_empty(hString) != TRUE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_empty_returns_true_for_empty_string\n"
                       "Returned value is not TRUE for an empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_empty_returns_true_for_empty_string\n", length);
    return SUCCESS;
}

// Test function to verify that pop_back removes a character from the string
Status test_pop_back_removes_character(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_pop_back_removes_character\nFailed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_pop_back(hString);
    if (status == FAILURE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\nFailed to pop character back from string", length);
        return FAILURE;
    }

    if (my_string_get_size(hString) != 4)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\nSize of string after pop back is not as expected", length);
        return FAILURE;
    }

    if (*my_string_at(hString, my_string_get_size(hString)) != '\0')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_removes_character\nCharacter at end of string is not NULL", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_pop_back_removes_character\n", length);
    return SUCCESS;
}

// Test function to verify concatenation with an empty string returns correct size
Status test_concat_with_empty_string_returns_correct_size(char* buffer, int length)
{
    MY_STRING hString1 = my_string_init_c_string("hello");
    MY_STRING hString2 = my_string_init_default();
    if (hString1 == NULL || hString2 == NULL)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concat_with_empty_string_returns_correct_size\nFailed to initialize string objects", length);
        return FAILURE;
    }

    Status status = my_string_concat(hString1, hString2);
    if (status == FAILURE)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concat_with_empty_string_returns_correct_size\nFailed to concatenate strings", length);
        return FAILURE;
    }

    if (my_string_get_size(hString1) != 5)
    {
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);
        strncpy(buffer, "test_concat_with_empty_string_returns_correct_size\nSize of string after concatenation is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString1);
    my_string_destroy(&hString2);
    strncpy(buffer, "test_concat_with_empty_string_returns_correct_size\n", length);
    return SUCCESS;
}


// Test function to verify that pushing back a character increases the size of the string by 1
Status test_push_back_increases_size(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_push_back_increases_size\nFailed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_push_back(hString, 'a');
    if (status == FAILURE || my_string_get_size(hString) != 1)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_push_back_increases_size\nFailed to push back character or size is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_push_back_increases_size\n", length);
    return SUCCESS;
}

// Test function to verify that popping back a character decreases the size of the string by 1
Status test_pop_back_decreases_size(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_pop_back_decreases_size\nFailed to initialize string object", length);
        return FAILURE;
    }

    Status status = my_string_pop_back(hString);
    if (status == FAILURE || my_string_get_size(hString) != 4)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_pop_back_decreases_size\nFailed to pop back character or size is not as expected", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_pop_back_decreases_size\n", length);
    return SUCCESS;
}

// Test function to verify that c_str returns a null-terminated string
Status test_c_str_returns_null_terminated(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_c_str_returns_null_terminated\nFailed to initialize string object", length);
        return FAILURE;
    }

    char* cstr = my_string_c_str(hString);
    if (cstr == NULL || cstr[my_string_get_size(hString)] != '\0')
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_c_str_returns_null_terminated\nReturned c-string is not null-terminated", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_c_str_returns_null_terminated\n", length);
    return SUCCESS;
}

// Test function to verify that empty returns TRUE for an empty string
Status test_empty_returns_TRUE_for_empty_string(char* buffer, int length)
{
    MY_STRING hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_empty_returns_TRUE_for_empty_string\nFailed to initialize string object", length);
        return FAILURE;
    }

    Boolean isEmpty = my_string_empty(hString);
    if (isEmpty != TRUE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_empty_returns_TRUE_for_empty_string\nmy_string_empty does not return TRUE for empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_empty_returns_TRUE_for_empty_string\n", length);
    return SUCCESS;
}

// Test function to verify that empty returns FALSE for a non-empty string
Status test_empty_returns_FALSE_for_non_empty_string(char* buffer, int length)
{
    MY_STRING hString = my_string_init_c_string("hello");
    if (hString == NULL)
    {
        strncpy(buffer, "test_empty_returns_FALSE_for_non_empty_string\nFailed to initialize string object", length);
        return FAILURE;
    }

    Boolean isEmpty = my_string_empty(hString);
    if (isEmpty != FALSE)
    {
        my_string_destroy(&hString);
        strncpy(buffer, "test_empty_returns_FALSE_for_non_empty_string\nmy_string_empty does not return FALSE for non-empty string", length);
        return FAILURE;
    }

    my_string_destroy(&hString);
    strncpy(buffer, "test_empty_returns_FALSE_for_non_empty_string\n", length);
    return SUCCESS;
}

