#include "monty.h"
/**
 * process_file - function to process the file
 *
 * @file_name: the file we want to process
*/
void process_file(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
		handle_error(1, file_name);
	read_file_lines(file);
	fclose(file);
}
/**
 * read_file_lines - function to read each line in the file
 *
 * @file: the file
*/
void read_file_lines(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	int line_count = 1;
	int type = 0;

	while (getline(&line, &len, file) != -1)
	{
		type = process_line(line, line_count, type);
		line_count++;
	}
	free(line);
}
/**
 * process_line - function to process line
 *
 * @line: the line
 * @count: line counter
 * @type: queue or stack
 *
 * Return: (0) if stack, (1) if queue
*/
int process_line(char *line, int count, int type)
{
	char *arg;
	char *opcode;

	if (line == NULL)
		handle_error(2);
	if (strlen(line) - 1 > 0 && line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	opcode = strtok(line, " ");
	if (opcode == NULL || opcode[0] == '\n')
		return (type);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	arg = strtok(NULL, " ");
	check_cmd(opcode, arg, type, count);
	return (type);
}

