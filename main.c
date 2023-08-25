#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point of monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: EXIT_SUCCESS if successful, or EXIT_FAILURE otherwise
 */

global_var_t globalvar;

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	FILE *file;

	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	init_globalvars();

	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		tokenize_input(line);

		if (globalvar.token2 != NULL)
		{
			if (strcmp(globalvar.token2, "push") == 0)
			{
				push(&stack, line_number);
			}
			else if (strcmp(globalvar.token2, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else if (strcmp(globalvar.token2, "pint") == 0)
			{
				pint(&stack, line_number);
			}
			else if (strcmp(globalvar.token2, "swap") == 0)
			{
				swap(&stack, line_number);
			}
			else if (strcmp(globalvar.token2, "add") == 0)
			{
				add(&stack, line_number);
			}
			else if (strcmp(globalvar.token2, "nop") == 0)
			{
				nop(&stack, line_number);
			}
			else
			{
				print_unknown_opcode_error(globalvar.token2, line_number);
				free(line);
				free_dlistint(stack);
				free_globalvars();
				fclose(file);
				return (EXIT_FAILURE);
			}
		}

		free(globalvar.token2);
	}

	free(line);
	free_dlistint(stack);
	free_globalvars();
	fclose(file);

	return (EXIT_SUCCESS);
}
