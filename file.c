#include "monty.h"

void process_file(char *file_name)
{
	FILE *file = fopen(file_name, "r");
	if (file == NULL)
		handle_error(1, file_name);
	read_file_lines(file);
	fclose(file);
}

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
	printf("%d-opcode:%s arg: %s\n", count, opcode, arg);
	return type;
}

