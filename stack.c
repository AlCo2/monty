#include "monty.h"

stack_t *create_node(int val)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_error(2);
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

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
