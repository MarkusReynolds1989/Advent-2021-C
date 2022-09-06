#include "real_string.h"
string* string_new(char* raw_string) {
	string* new_string = calloc(1, sizeof(string));
	if (new_string == NULL) {
		perror("Couldn't allocate memory for string.");
		return NULL;
	}

	size_t length = strlen(raw_string);
	const char* new_raw = calloc(length, sizeof(char));
	if (new_raw == NULL) {
		perror("Couldn't allocate memory for new_raw");
		return NULL;
	}

	new_string->raw_string = raw_string;
	new_string->length = length;
	new_string->size = length;

	return new_string;
}
