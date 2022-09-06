#ifndef FILE_OPS
#define FILE_OPS 
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "real_string.h"
#include "list_ops.h"
#pragma warning(disable:4996)

// Takes a path and a buffer, will input the lines of the file into the buffer.
// Returns the amount of lines.
int file_to_lines(const char* path, char** buffer);

int file_to_real_strings(const char* path, string_list* string_list);
#endif