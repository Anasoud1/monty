#include "monty.h"

stack_t *top = NULL;

/**
 * print_usage - prints the syntax of launching monty
 * Return: void (NOTHING)
 */
void print_usage(void)
{
	printf("USAGE: monty file\n");
}

/**
 * main - Entry point of monty
 * @ac: number of arguments
 * @av: list of arguments
 * Return: int (SUCCESS or FAILURE)
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (ac != 2)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		parse_line(line);
	}
	fclose(fp);
	if (line)
		free(line);
	return (0);
}
