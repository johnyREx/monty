#include "monty.h"

/**
 * free_dlistint - Frees a doubly linked list of integers.
 * @stack: Pointer to the head of the stack.
 */

void free_dlistint(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * stderr_int - Prints an error message with line number to stderr.
 * @line_number: Line number where the error occurred.
 */

void stderr_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - Checks if a string represents a digit.
 * @str: The string to check.
 * Return: 1 if the string represents a digit, 0 otherwise.
 */

int _isdigit(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
