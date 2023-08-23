#include "monty.h"

/**
 * free_distlint - Frees a doubly linked list of integers.
 * @stack: Pointer to the head of the stack.
 */

void free_distlint(stack_t *stack)
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

/**
 * push_stack_first - Pushes an element to the beginning of a stack.
 * @stack: Pointer to the head of the stack.
 * @n: Value to push.
 */

void push_stack_first(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * push_stack_end - Pushes an element to the end of a stack.
 * @stack: Pointer to the head of the stack.
 * @n: Value to push.
 */

void push_stack_end(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		stack_t *temp = *stack;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}

}

/**
 * init_globalvars - Initializes global variables.
 */

void init_globalvars(void)
{
	globalvar.token2 = NULL;
}

/**
 * free_globalvars - Frees global variables.
 */

void free_globalvars(void)
{
	free(globalvar.token2);
}
