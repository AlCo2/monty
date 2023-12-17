#include "monty.h"

/**
 * rotl - function to swap first element with the last
 *
 * @stack: the head
 * @line: the line number
*/
void rotl(stack_t **stack, unsigned int line)
{
	stack_t *last = *stack;
	
	if (last == NULL || last->next == NULL)
		return;
	(void)line;
	while (last->next)
	{
		last = last->next;
	}
	last->next = (*stack);
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - function that rotate the stack to bottom
 *
 * @stack: the head
 * @line: the line
*/
void rotr(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
		return;
	(void)line;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}
