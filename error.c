#include "monty.h"

void handle_error(int error_code, ...)
{
	int line;
	char *opcode;
	va_list a_list;

	va_start(a_list, error_code);
	switch (error_code)
	{
		case 0:
			printf("USAGE: monty file\n");
			break;
		case 1:
			printf("Error: Can't open file %s\n", va_arg(a_list, char *));
			break;
		case 2:
			printf("Error: malloc failed\n");
			break;
		case 3:
			line = va_arg(a_list, int);
			opcode = va_arg(a_list, char *);
			printf("L%d: unknown instruction %s", line, opcode);
			break;
		case 4:
			printf("L%d: usage: push integer", va_arg(a_list, int));
			break;

	}
	exit(EXIT_FAILURE);
}
