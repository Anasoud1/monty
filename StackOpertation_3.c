#include "monty.h"

void rotr(stack_t  **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2, *ptr;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp2)
	{
		if (tmp2->next == NULL)
			*stack = tmp2;
		tmp2 = tmp2->next;
		ptr = tmp->prev;
		tmp->prev = tmp->next;
		tmp->next = ptr;
		tmp = tmp2;
	}
}
