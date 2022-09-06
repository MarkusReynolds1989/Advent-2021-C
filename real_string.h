#ifndef REAL_STRING
#define REAL_STRING 
#pragma once
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct string {
	char* raw_string;
	size_t length;
	size_t size;
} string;

string* string_new(char* raw_string);

void string_free(string* input);
#endif

