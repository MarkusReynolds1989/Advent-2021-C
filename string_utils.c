#include "string_utils.h"

string_list* split(const string* input, const char deliminator) {
	string_list* list = string_list_new(4);

	size_t start = 0;
	size_t stop = 0;
	size_t index = 0;

	while (index < input->length) {
		while (*&input->raw_string[index] != deliminator && index <= input->length) {
			stop += 1;
			index += 1;
		}

		// Skip over the token found.
		index += 1;

		// Add the string to the list.
		char* raw_string = calloc(stop + 1, sizeof(char));
		for (size_t i = start, y = 0; i < stop; i += 1, y += 1) {
			raw_string[y] = input->raw_string[i];
		}

		string_list_append(list, string_new(raw_string));
		start = index;
		stop = index;
	}

	return list;
}