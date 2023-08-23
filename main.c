#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

global_var_t globalvar;

/**
 * intit_globalvars - Initialize global variables
 */

void init_globalvars(void)
{
	globalvar.token2 = NULL;
}

/**
 * free_globalvars - Free memory and clean up global variables
 */

void free_globalvars(void)
{
	if (globalvar.token2 != NULL)
	{
		free(globalvar.token2);
	}
}

/**
 * tokenize_input - Tokenize input line and extract opcode and argument
 * @input_line: Input line to tokenize
 */

void tokenize_inpute(char *input_line)
{
	char *opcode = strtok(input_line, " \t\n");
	if (opcode != NULL)
	{
		globalvar.token2 = strncmp(opcode);
	}
}

/**
 * main - Entry point of monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: EXIT_SUCCESS if successful, or EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	size_t read;

	stack_t *stack = NULL;

	init_globalvars();

	while ((read = getline(&line, &len, file)) != -1)
	{
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
				fprintf(stderr, "L%u: Unknown opcode: %s\n", line_number, globalvar.token2);
				free(line);
				free(line);
				free_dlistint(stack);
				free_globalvars();
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
	}

	free(line);
	free_dlistint(stack);
	free_globalvars();
	fclose(file);

	return (EXIT_SUCCESS);
}
