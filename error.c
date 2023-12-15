#include "monty.h"
/**
 * handle_error - function to handle errors
 *
 * @error_code: code of error
*/
void handle_error(int error_code, ...)
{
	int line;
	char *opcode;
	va_list a_list;

	va_start(a_list, error_code);
	switch (error_code)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(a_list, char *));
			break;
		case 2:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 3:
			line = va_arg(a_list, int);
			opcode = va_arg(a_list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case 4:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a_list, int));
			break;
		case 5:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(a_list, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(a_list, int));
			break;

	}
	exit(EXIT_FAILURE);
}
/**
 * handle_error2 - function to handle errors
 *
 * @error_code: code of error
*/
void handle_error2(int error_code, ...)
{
	va_list a_list;

	va_start(a_list, error_code);
	switch (error_code)
	{
		case 7:
			fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(a_list, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(a_list, int));
			break;
	}
	exit(EXIT_FAILURE);
}
