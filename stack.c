#include "monty.h"

/**
 * create_node - function to create nodes
 *
 * @val: the value
 *
 * Return: the node created
*/
stack_t *create_node(int val)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		handle_error(2);
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
/**
 * push - function to push to stack
 *
 * @stack: the new node
 * @line: the line number
*/
void push(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	(void)line;
	if (head == NULL)
	{
		head = (*stack);
		return;
	}
	temp = head;
	head = (*stack);
	head->next = temp;
	temp->prev = head;
}
/**
 * pall - functon to print everything in the stack
 *
 * @stack: the head
 * @line: line number
*/
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp = (*stack);

	(void)line;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

