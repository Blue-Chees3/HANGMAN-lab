#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]) {
    MY_STRING hMy_string = NULL;
    FILE* fp;
    hMy_string = my_string_init_default();
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL)
    {
	    printf("Failed to open file\n");
	    exit(1);
    }
    while(my_string_extraction(hMy_string, fp)) {
//       my_string_insertion(hMy_string, stdout);
//	printf("\n");

//	printf(" Size: %d\n", my_string_get_size(hMy_string));
	if(my_string_get_size(hMy_string)==29)
	{
		
		
		my_string_insertion(hMy_string, stdout);
		printf("\n");		
	}
    }
    my_string_destroy(&hMy_string);
    fclose(fp);
    return 0;
}

