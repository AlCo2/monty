#include "monty.h"

stack_t *head = NULL;

int main(int argc, char **argv)
{
	if (argc != 2)
		handle_error(0);
	process_file(argv[1]);
	return 0;
}
