#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */

void swap(stack_t  **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *curr = *stack, *tmp;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg(4, line_number, *stack);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */

void add(stack_t  **stack, unsigned int line_number)
{
	stack_t *tmp, *curr = *stack;
	int i = 0;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg(5, line_number, *stack);
	tmp = (*stack)->next;
	(*stack)->n += (*stack)->next->n;
	(*stack)->next = tmp->next;
	tmp->prev = *stack;
	free(tmp);
}

/**
 * nop - fucntion doesn't do anything
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */
void nop(stack_t  **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_top_items - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */

void sub_top_items(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int i = 0, sub = 0;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg(8, line_number, *stack);

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_top_items - divides the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */
void div_top_items(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int i = 0, div = 0;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg2(9, line_number, *stack);
	if (((*stack)->n) == 0)
		error_msg2(10, line_number, *stack);
	div = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
