#include "monty.h"

/**
 * push_q - function to push to queue
 *
 * @stack: the new node
 * @line: the line number
*/

void push_q(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	(void)line;
	if (head == NULL)
	{
		head = (*stack);
		return;
	}
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = (*stack);
	(*stack)->prev = temp;
}

