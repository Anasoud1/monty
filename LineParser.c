#include "monty.h"

/**
 * pop_top - removes the top of the stack
 * @top: pointer to the top of the stack
 * @ln: line number
 */
void pop_top(stack_t **top, unsigned int ln)
{
	stack_t *tmp;

	if (top == NULL || *top == NULL)
		error_msg(7, ln, *top);

	tmp = *top;
	*top = tmp->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(tmp);
}

/**
 * print_top - prints the value a the top of the stack
 * @top: pointer to the top of the stack
 * @ln: line number
 */
void print_top(stack_t **top, unsigned int ln)
{
	if (top == NULL || *top == NULL)
		error_msg(6, ln, *top);
	printf("%d\n", (*top)->n);
}

/**
 * push_item - pushes a new item to the top of the stack
 * @top: top of the stack
 * @data: new item to be pushed to the stack
 * @line: line
 * Return: void (NOTHING)
 */
void push_item(stack_t **top, int data, char *line)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		free(line);
		free_list(*top);
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	}
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
	char *opcode;
	instruction_t instructions[] = {
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_top},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub_top_items},
		{"div", div_top_items},
		{"mul", mul_top_items},
		{"mod", mod_top_items},
		{"pchar", pchar_top_item},
		{"pstr", pstr_items},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	opcode = strtok(line, " \n");
	if (opcode[0] == '#')
		return (0);
	if (parse_execute_push(opcode, ln, top, line))
		return (0);
	if (parse_execute_instructions(instructions, opcode, top, ln))
		return (0);
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	free(line);
	free_list(*top);
	fclose(fp);
	exit(EXIT_FAILURE);
}
