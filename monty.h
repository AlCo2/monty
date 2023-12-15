#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void process_file(char *file_name);
void read_file_lines(FILE *file);
int process_line(char *line, int count, int type);
void check_cmd(char *opcode, char *arg, int type, int line);
void run_cmd(instruction_t func, char *arg, int type, int line);
stack_t *create_node(int val);
void push(stack_t **stack, unsigned int line);
void push_q(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void handle_error(int error_code, ...);
void handle_error2(int error_code, ...);
void free_stack();
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
#endif
