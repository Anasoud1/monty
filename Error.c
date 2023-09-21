#include "monty.h"

/**
 * error_msg - prints an error message
 * @number_err: error id
 * @line_number: line number
 * @stack: pointer to the stack
 * Return: void (NOTHING)
 */
void error_msg(int number_err, unsigned int line_number, stack_t *stack)
{
	(void)stack;
	switch (number_err)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		case 2:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		case 3:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		case 4:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		case 5:
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			exit(EXIT_FAILURE);
		case 8:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		default:
			break;
	}
}
