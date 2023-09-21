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
void error_msg2(int number_err, unsigned int line_number, stack_t *stack)
{
	(void)stack;
	switch (number_err)
	{
		case 9:
			fprintf(stderr, "L%d:  can't div, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		case 10:
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		case 11:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		case 12:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		case 13:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		case 14:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		default:
			break;
	}
}
