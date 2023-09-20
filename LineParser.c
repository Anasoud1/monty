#include "monty.h"

/**
 * push_item - pushes a new item to the top of the stack
 * @top: top of the stack
 * @data: new item to be pushed to the stack
 * Return: void (NOTHING)
 */
void push_item(stack_t **top, int data)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	tmp->n = data;
	tmp->next = *top;

	if (*top)
		(*top)->prev = tmp;

	*top = tmp;
	(*top)->prev = NULL;
}

/**
 * print_all - prints all the stack
 * @top: top of the stack
 * @ln: line number
 * Return: void (NOTHING)
 */
void print_all(stack_t **top, unsigned int ln)
{
	stack_t *cur = *top;

	(void)ln;

	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

/**
 * parse_execute_line - parses a line
 * @top: top of the stack
 * @line: current line to be parsed
 * @ln: line number
 * @fp: file descriptor
 * Return: int
 */
int parse_execute_line(char *line, stack_t **top, unsigned int ln, FILE *fp)
{
	int i = 0;
	char *opcode, *arg;
	void (*f)(stack_t **top, unsigned int ln);
	instruction_t instructions[] = {
		{"pall", print_all},
		{NULL, NULL}
	};

	opcode = strtok(line, " \n");
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n");
		if (!arg)
			error_msg(1, ln, *top);
		if (is_number(arg))
			push_item(top, atoi(arg));
		else
			error_msg(1, ln, *top);
		return (0);
	}

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			f = instructions[i].f;
			f(top, ln);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	free(line);
	free_list(*top);
	fclose(fp);
	exit(EXIT_FAILURE);
}
