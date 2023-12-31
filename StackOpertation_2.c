#include "monty.h"

/**
 * mul_top_items - multiply the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */

void mul_top_items(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int i = 0, mul = 0;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg2(11, line_number, *stack);

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_top_items - computes the rest of the division the top two elements of
 *			the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void(nothing)
 */

void mod_top_items(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int i = 0, mod = 0;

	while (curr)
	{
		i++;
		curr = curr->next;
	}
	if (i < 2)
		error_msg2(12, line_number, *stack);
	if (((*stack)->n) == 0)
		error_msg2(10, line_number, *stack);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * pchar_top_item - prints the char at the top of the stack
 * @stack: top of the stack
 * @line_number: line number
 * Return: void (NOTHING)
 */
void pchar_top_item(stack_t  **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_msg2(14, line_number, *stack);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		error_msg2(13, line_number, *stack);
	printf("%c\n", (*stack)->n);
}

/**
 * pstr_items - prints the string
 * @stack: top of the stack
 * @line_number: line number
 * Return: void (NOTHING)
 */
void pstr_items(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}

/**
 * rotl - rotl
 * @stack: top of the stack
 * @line_number: line number
 * Return: void (NOTHING)
 */
void rotl(stack_t  **stack, unsigned int line_number)
{
	stack_t *curr = *stack, *tmp = *stack;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;
	while (curr->next)
		curr = curr->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->prev = curr;
	tmp->next = NULL;
}
