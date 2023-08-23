#include <stdio.h>
#include <stdlib.h>
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
