#include "monty.h"

/**
 * rotr - rotates the stack to the top
 * @stack: top of the stack
 * @line_number: line number
 */
void rotr(stack_t  **stack, unsigned int line_number)
{
	stack_t *tmp, *curr;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->prev->next = NULL;
	curr->next = tmp;
	curr->prev = NULL;
	tmp->prev = curr;
	*stack = curr;
}
