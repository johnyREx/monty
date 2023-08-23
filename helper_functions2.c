#include "monty.h"

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
