#ifndef STRING_UTILS
#define STRING_UTILS
#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list_ops.h"
#include "real_string.h"
#pragma warning(disable:4996)

string_list* split(string* input, char deliminator);

#endif