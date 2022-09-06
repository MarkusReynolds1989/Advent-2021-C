#include "list_ops.h"

// Takes a list of strings and turns it into a list of integers.
size_t string_to_integer_list(const size_t length, const char** strings, int* integers) {
	for (size_t i = 0; i < length; i += 1) {
		integers[i] = atoi(&strings[i]);
	}

	return length;
}

// Generates a list of strings.
string_list* string_list_new(const size_t size) {
	string_list* list = calloc(1, sizeof(string_list));
	if (list != NULL) {
		list->strings = (string**)calloc(size, sizeof(string*));
		list->length = 0;
		list->size = size;
	}
	return list;
}

void string_list_expand(string_list* string_list) {
	if (realloc(string_list, string_list->size * 4) != NULL) {
		string_list->size *= 4;
	}
}

void string_list_shrink(string_list* string_list) {

}

// Private.
void append(string_list* string_list, string* new_string) {
	string_list->strings[string_list->length] = new_string;
	string_list->length += 1;
}

// Appends to the end of the string_list.
void string_list_append(string_list* string_list, string* new_string) {
	if (string_list->length < string_list->size) {
		append(string_list, new_string);
	}
	else {
		string_list_expand(string_list);
		append(string_list, new_string);
	}
}

void string_list_free(string_list* string_list) {
	for (size_t i = 0; i < string_list->size; i += 1) {
		free(string_list->strings[i]);
	}

	free(string_list);
}