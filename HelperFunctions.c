#include "monty.h"

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

char *remove_leading(char *str)
{
	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	return str;
}
