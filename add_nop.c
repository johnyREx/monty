#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
		op_e(line_number, "add");

	temp = (*stack)->next;
	temp->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Doesn't do anything
 * @stack: Pointer to the head of the stack
 * @line_number: Line number of the instruction
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
