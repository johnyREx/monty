#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the monty byte code file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (globalvar.token2 == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit(globalvar.token2) || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}

	n = atoi(globalvar.token2);
	if (*stack == NULL)
	{
		push_stack_first(stack, n);
	}
	else
	{
		push_stack_end(stack, n);
	}
}

/**
 * pall - print the stack
 * @stack: pointer to the stack
 * @line_number: Line number of the intrsuction
 *
 * Return: no return
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: Line number in the monty byte code file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * pop - Remove the top element from the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the monty byte code file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		printf("%d\n", temp->n);
		free(temp);
	}
}

/**
 * swap - Swaps the top elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the monty byte code file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->prev = second;
	first->next = second->next;

	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;

	*stack = second;
}
