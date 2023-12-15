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
/**
 * pchar - function to print char from top of stack
 *
 * @stack: the head
 * @line: the line number
*/
void pchar(stack_t **stack, unsigned int line)
{
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)val);
}
/**
 * pstr - function to print char from top of stack
 *
 * @stack: the head
 * @line: the line number
*/
void pstr(stack_t **stack, unsigned int line)
{
	int val;
	stack_t *temp = (*stack);

	(void)line;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temp)
	{
		val = temp->n;
		if (val <= 0 || val > 127)
		{
			break;
		}
		printf("%c", (char)val);
		temp = temp->next;
	}
	printf("\n");
}
