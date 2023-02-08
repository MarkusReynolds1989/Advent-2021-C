#include "day_02.h"

typedef struct instruction {
	string* direction;
	int amount;
} instruction;

int star_one_day_two(const string_list* strings)
{
	instruction* instructions = calloc(strings->length, sizeof(instruction));

	if (instructions != NULL)
	{
		for (size_t i = 0; i < strings->length; i += 1)
		{
			// Get the direction.
			const string_list* split_up = split(strings->strings[i], ' ');
			string* direction = split_up->strings[0];
			const int amount = atoi(split_up->strings[1]->raw_string);

			instructions[i].direction = direction;
			instructions[i].amount = amount;
		}

		for (size_t i = 0; i < 6; i += 1) {
			printf("%s, %d\n", instructions[i].direction->raw_string, instructions[i].amount);
		}
		free(instructions);
	}
	return 0;
}

int star_two_day_two(size_t length, const char** data)
{
	return 0;
}

void day_02()
{
	char* data_path = "C:\\Users\\marku\\Code\\C\\advent\\data\\day_02.txt";

	string_list* test_directions = string_list_new(6);

	if (test_directions != NULL)
	{
		string_list_append(test_directions, string_new("forward 5"));
		string_list_append(test_directions, string_new("down 5"));
		string_list_append(test_directions, string_new("forward 8"));
		string_list_append(test_directions, string_new("up 3"));
		string_list_append(test_directions, string_new("down 8"));
		string_list_append(test_directions, string_new("forward 2"));
	}

	star_one_day_two(test_directions);

	string_list_free(test_directions);
	printf("*****\n\n\n\n");

	string_list* directions = string_list_new(2001);
	string_list_free(directions);
}
