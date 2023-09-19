#include "monty.h"

/**
 * push - pushes a new item to the top of the stack
 * @data: new item to be pushed to the stack
 * Return: void (NOTHING)
 */
void push(int data)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
		printf("stack overflow\n"), exit(1);
	tmp->n = data;
	tmp->next = top;

	if (top)
		top->prev = tmp;

	top = tmp;
	top->prev = NULL;
}

/**
 * print_all - prints all the stack
 * Return: void (NOTHING)
 */
void print_all(void)
{
	stack_t *curr = top;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * parse_line - parses a line
 * @line: current line to be parsed
 * Return: int
 */
int parse_line(char *line)
{
	int ret = 0;
	char *opcode, *arg;

	opcode = strtok(line, " \n");

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " ");
		push(atoi(arg));
		/*
		printf("opcode = %s\n", opcode);
		printf("arg = %s\n", arg);
		*/
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		print_all();
		/*printf("opcode = %s\n", opcode);*/
	}
	else
	{
		printf("unknown instruction %s", opcode);
		ret = -1;
	}
	return (ret);
}
