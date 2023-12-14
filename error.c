#include "monty.h"

void handle_error(int error_code, ...)
{
	va_list a_list;

	va_start(a_list, error_code);
	switch (error_code)
	{
		case 0:
			printf("USAGE: monty file\n");
			break;
		case 1:
			printf("Error: Can't open file %s", va_arg(a_list, char *));
			break;
		case 2:
			printf("Error: malloc failed");

	}
	exit(EXIT_FAILURE);
}
