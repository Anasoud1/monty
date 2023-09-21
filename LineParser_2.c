#include "monty.h"

/**
 * parse_execute_push - function that parse and execute push function
 * @opcode: instruction to check
 * @top: top of the stack
 * @line: current line to be parsed
 * @ln: line number
 * Return: int
 */

int parse_execute_push(char *opcode, unsigned int ln, stack_t **top,
			char *line)
{
	char *arg;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n");
		if (!arg)
		{
			free(line);
			error_msg(1, ln, *top);
		}
		if (is_number(arg))
			push_item(top, atoi(arg), line);
		else
		{
			free(line);
			error_msg(1, ln, *top);
		}
		return (1);
	}
	return (0);
}

/**
 * parse_execute_instructions - function that parse and execute functions
 * @instructions: available instructions
 * @opcode: instruction to check
 * @top: top of the stack
 * @ln: line number
 * Return: int
 */

int parse_execute_instructions(instruction_t *instructions, char *opcode,
		stack_t **top, unsigned int ln)
{
	int i = 0;
	void (*f)(stack_t **top, unsigned int ln);

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			f = instructions[i].f;
			f(top, ln);
			return (1);
		}
		i++;
	}
	return (0);
}
