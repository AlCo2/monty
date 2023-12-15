#include "monty.h"

stack_t *head = NULL;

/**
 * main - function that run the interpreter
 *
 * @argc: count of argument
 * @argv: argements passed
 *
 * Return: (0)
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		handle_error(0);
	process_file(argv[1]);
	free_stack();
	return (0);
}

/**
 * free_stack - free everything
*/
void free_stack(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

