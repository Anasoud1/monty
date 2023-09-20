#include "monty.h"

/**
 * print_usage - prints the syntax of launching monty
 * Return: void (NOTHING)
 */
void print_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * main - Entry point of monty
 * @ac: number of arguments
 * @av: list of arguments
 * Return: int (SUCCESS or FAILURE)
 */
int main(int ac, char **av)
{
	int ln = 1, indx = 0;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *top = NULL;

	if (ac != 2)
		print_usage();

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		indx = remove_leading(line);
		if (line[indx] == '\n')
		{
			free(line);
			continue;
		}
		parse_execute_line(line, &top, ln, fp);
		free(line);
		line = NULL;
		ln++;
	}
	fclose(fp);
	free(line);
	free_list(top);
	return (0);
}
