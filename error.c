#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * print_usage_error - Prints the usage error message.
 * @line_number: Line number in the Monty byte code file.
 */

void print_usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
}

/**
 * print_unknown_opcode_error - Prints the unknown opcode error message.
 * @opcode: The unknown opcode.
 * @line_number: Line number in the Monty byte code file.
 */

void print_unknown_opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/**
 * print_empty_stack_error - Prints the empty stack error message.
 * @line_number: Line number in the Monty byte code file.
 */

void print_empty_stack_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}

/**
 * print_short_stack_error - Prints the stack too short error message.
 * @line_number: Line number in the Monty byte code file.
 */

void print_short_stack_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
}

/**
 * print_malloc_error - Prints the malloc error message and exits.
 */

void print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
