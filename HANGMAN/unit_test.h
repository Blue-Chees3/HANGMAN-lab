#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_push_back_adds_character(char* buffer, int length);

//Status test_pop_back_removes_character(char* buffer, int length);

Status test_empty_string_is_empty(char* buffer, int length);
Status test_non_empty_string_is_not_empty(char* buffer, int length);
Status test_push_back_adds_characters(char* buffer, int length);
Status test_get_character_at_index(char* buffer, int length);
Status test_c_str_returns_valid_c_string(char* buffer, int length);
Status test_concatenation_result_is_correct(char* buffer, int length);
Status test_pop_back_on_empty_string_returns_failure(char* buffer, int length);
Status test_pop_back_removes_last_character(char* buffer, int length);

Status test_c_str_returns_valid_c_string(char* buffer, int length);
Status test_at_returns_correct_character(char* buffer, int length);
Status test_concat_concatenates_strings(char* buffer, int length);
Status test_c_str_returns_valid_c_string_after_concatenation(char* buffer, int length);
Status test_concat_with_empty_string(char* buffer, int length);
Status test_get_capacity_returns_correct_capacity(char* buffer, int length);
Status test_empty_returns_true_for_empty_string(char* buffer, int length);
Status test_push_back_adds_character(char* buffer, int length);
Status test_pop_back_removes_character(char* buffer, int length);
Status test_concat_with_empty_string_returns_correct_size(char* buffer, int length);

Status test_push_back_increases_size(char* buffer, int length);
Status test_pop_back_decreases_size(char* buffer, int length);
Status test_c_str_returns_null_terminated(char* buffer, int length);
Status test_empty_returns_TRUE_for_empty_string(char* buffer, int length);
Status test_empty_returns_FALSE_for_non_empty_string(char* buffer, int length);



#endif
