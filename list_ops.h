#ifndef LIST_OPS
#define LIST_OPS 
#pragma once
#include <stdlib.h>
#include "real_string.h"

typedef struct string_list {
	string** strings;
	size_t length;
	size_t size;
} string_list;

// Takes a list of strings and turns it into a list of integers.
size_t string_to_integer_list(size_t length, const char** strings, int* integers);

// Generates a list of strings.
string_list* string_list_new(size_t size);

// Appends to the end of the string_list.
void string_list_append(string_list* string_list, string* new_string);

// Free all memory used by the list.
void string_list_free(string_list* string_list);
#endif
