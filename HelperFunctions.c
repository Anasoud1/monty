#include "monty.h"

/**
 * is_number - checks if a string is number
 * @s: input string
 * Return: 0 or 1
 */
int is_number(char *s)
{
	int i = 0;

	if (s[0] == '-')
		i++;

	for (; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}


/**
 * remove_leading - removes spaces at the beginning
 * @str: string input
 * Return: new string pointer
 */
int remove_leading(char *str)
{
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	return (i);
}
