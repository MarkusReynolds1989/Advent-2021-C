#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_ops.h"
#include "list_ops.h"

int star_one_day_one(size_t length, const int* data) {
	int accumulator = 0;
	for (int current = 0, next = 1; next < length; current += 1, next += 1) {
		if (data[current] < data[next]) {
			accumulator += 1;
		}
	}

	return accumulator;
}

int star_two_day_one(size_t length, const int* data) {
	int accumulator = 0;
	int current = data[0] + data[1] + data[2];

	for (int index = 1; index < length - 2; index += 1) {
		int next = data[index] + data[index + 1] + data[index + 2];

		if (current < next) {
			accumulator += 1;
			current = next;
		}
		else if (current > next) {
			current = next;
		}
	}

	return accumulator;
}

void day_01(void)
{
	char* data_path = "C:\\Users\\marku\\Code\\C\\advent\\data\\day_01.txt";
	int test_data[] = { 199,200,208,210,200,207,240,269,260,263 };
	size_t test_data_length = 10;

	int star_one_solution_test = star_one_day_one(test_data_length, &test_data);
	int star_two_solution_test = star_two_day_one(test_data_length, &test_data);

	char** buffer = calloc(5000, sizeof(char*));
	int file_length = file_to_lines(data_path, buffer);

	char** temp_buffer = realloc(buffer, file_length * sizeof(char*));

	if (temp_buffer != NULL) {
		buffer = temp_buffer;
		int* file_data_ints = calloc(file_length, sizeof(int));

		int size = string_to_integer_list(file_length, buffer, file_data_ints);

		int star_one_solution = star_one_day_one(file_length, file_data_ints);
		int star_two_solution = star_two_day_one(file_length, file_data_ints);

		printf("%d\n", star_one_solution_test);
		printf("%d\n", star_two_solution_test);
		printf("%d\n", star_one_solution);
		printf("%d\n", star_two_solution);
		free(file_data_ints);
	}

	free(buffer);
}
