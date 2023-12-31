#include "monty.h"
/**
 * check_cmd - function to check cmd
 *
 * @opcode: code
 * @arg: argument
 * @type: stack or queue
 * @line: line executed
*/
void check_cmd(char *opcode, char *arg, int type, int line)
{
	int i = 0;
	int found = 0;

	instruction_t list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divid},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL}
	};
	if (opcode[0] == '#')
		return;
	while (list[i].opcode != NULL)
	{
		if (strcmp(list[i].opcode, opcode) == 0)
		{
			run_cmd(list[i], arg, type, line);
			found = 1;
		}
		i++;
	}
	if (!found)
		handle_error(3, line, opcode);
}
/**
 * run_cmd - function to run cmd
 *
 * @func: instruction
 * @arg: argument for func
 * @type: stack or queue
 * @line: line executed
*/
void run_cmd(instruction_t func, char *arg, int type, int line)
{
	int negative = 0;
	int number;
	int i;
	stack_t *new_node;

	if (strcmp(func.opcode, "push") == 0)
	{
		if (arg == NULL)
			handle_error(4, line);
		if (arg[0] == '-')
		{
			negative = 1;
			arg++;
		}
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (!isdigit(arg[i]))
				handle_error(4, line);
		}
		number = atoi(arg);
		if (negative)
			number *= -1;
		new_node = create_node(number);
		if (type == 1)
			push_q(&new_node, line);
		else
			push(&new_node, line);
	}
	else
		func.f(&head, line);
}

