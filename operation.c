#include "monty.h"

/**
 * divid - function to divid two element in stack
 *
 * @stack: the head
 * @line: the line number
*/
void divid(stack_t **stack, unsigned int line)
{
	int div;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error2(10, line);
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	temp = (*stack)->next;
	temp->n = div;
	free(*stack);
	*stack = temp;
}
/**
 * mul - function to multiply two element in stack
 *
 * @stack: the head
 * @line: the line number
*/
void mul(stack_t **stack, unsigned int line)
{
	int mul;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error2(11, line);
	mul = (*stack)->n * (*stack)->next->n;
	temp = (*stack)->next;
	temp->n = mul;
	free(*stack);
	*stack = temp;
}

/**
 * mod - function to mod two element in stack
 *
 * @stack: the head
 * @line: the line number
*/
void mod(stack_t **stack, unsigned int line)
{
	int mod;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error2(12, line);
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	temp = (*stack)->next;
	temp->n = mod;
	free(*stack);
	*stack = temp;
}
