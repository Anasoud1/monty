#include "monty.h"

/**
 * free_list - frees a stack linked list
 * @head: top of the stack
 * Return: void (NOTHING)
 */

void free_list(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
	head = NULL;
	tmp = NULL;
}
