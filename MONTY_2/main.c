#include "monty.h"

/* global struct to hold flag for queue and stack length */
/*var_t var;*/

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	stack_t *stack_top = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;
	char *lineptr = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	var.gfs = fs;
	while (getline(&lineptr, &n, fs) != -1)
	{
		var.gline = lineptr;
		stack_top = last_node(&stack);
		line_number++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && op[0] != '#')
			get_opc(op, &stack, line_number);
		stack_top = last_node(&stack);
		if (var.stack_len == 1)
			stack = stack_top;
	}
	free(lineptr);
	free_stack(stack);
	fclose(fs);
	var.stack_len = 0;
	exit(EXIT_SUCCESS);
}
