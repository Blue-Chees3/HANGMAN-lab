#include <stdio.h>
#include <string.h>
#include "unit_test.h"

int main(int argc, char* argv[]) {
    // Array of function pointers to test functions
    Status (*tests[])(char*, int) = {
        test_init_default_returns_nonNULL,
        test_get_size_on_init_default_returns_0,
	test_push_back_adds_character,
	//test_pop_back_removes_character,
	test_empty_string_is_empty,
	test_non_empty_string_is_not_empty,
	test_push_back_adds_characters,
	test_get_character_at_index,
	test_c_str_returns_valid_c_string,
	test_concatenation_result_is_correct,
	test_pop_back_on_empty_string_returns_failure,
	test_pop_back_removes_last_character,
	test_c_str_returns_valid_c_string,
	test_at_returns_correct_character,
	test_concat_concatenates_strings,
	test_c_str_returns_valid_c_string_after_concatenation,
	test_concat_with_empty_string,
	test_get_capacity_returns_correct_capacity,
	test_empty_returns_true_for_empty_string,
	test_push_back_adds_character,
//	test_pop_back_removes_character,
	test_concat_with_empty_string_returns_correct_size,
	
	test_push_back_increases_size,
	test_pop_back_decreases_size,
	test_c_str_returns_null_terminated,
	test_empty_returns_TRUE_for_empty_string,
	test_empty_returns_FALSE_for_non_empty_string


        // Add more test functions as needed...
    };

    int number_of_functions = sizeof(tests) / sizeof(tests[0]);
    char buffer[500];
    int success_count = 0;
    int failure_count = 0;

    for (int i = 0; i < number_of_functions; i++) {
        if (tests[i](buffer, sizeof(buffer)) == FAILURE) {
            printf("FAILED: Test %d failed miserably\n", i);
            printf("\t%s\n", buffer);
            failure_count++;
        } else {
            printf("PASS: Test %d passed\n", i);
            success_count++;
        }
    }

    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count,
           number_of_functions, failure_count, number_of_functions);
    
    return 0;
}

