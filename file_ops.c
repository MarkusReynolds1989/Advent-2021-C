#include "file_ops.h"

int file_to_lines(const char* path, char** buffer) {
	int index = 0;
	FILE* data_file = fopen(path, "r");
	if (data_file != NULL) {
		char temp_buffer[80] = { 0 };
		while (fgets(&temp_buffer, 80, data_file) != NULL) {
			strcpy(&buffer[index], temp_buffer);
			index += 1;
		}

		fclose(data_file);
	}

	else {
		index = -1;
		perror("Couldn't open file.");
	}

	return index;
}

int file_to_real_strings(const char* path, string_list* string_list) {
	/*int index = 0;
	FILE* data_file = fopen(path, "r");
	if (data_file != NULL) {
		char* temp_buffer[80] = { 0 };
		while (fgets(&temp_buffer, 80, data_file) != NULL) {
			string_list[index] = string_new(&temp_buffer);
			index += 1;
		}

		fclose(data_file);
	}

	else {
		index = -1;
		perror("Couldn't open file.");
	}

	return index;*/
}