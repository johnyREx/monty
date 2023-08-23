#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * tokenize_input - Tokenizes a line of input.
 * @input_line: The line to tokenize.
 */

void tokenize_input(char *input_line)
{
	char *token;
	size_t token_length;

	if (input_line == NULL)
	{
		globalvar.token2 = NULL;
		return;
	}

	token = strtok(input_line, " \t\n");

	if (token != NULL)
	{
		token_length = strlen(token);
		globalvar.token2 = malloc(token_length + 1);

		if (globalvar.token2 != token)
		{
			strcpy(globalvar.token2, token);
		}

		else
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		globalvar.token2 = NULL;
	}
}
