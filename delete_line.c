#include "shell.h"

/**
  * delete_line - Function that delete a new line character from string
  * @str: string
  *
  * Return: string without a new line character
  */
char *delete_line(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}

	return (str);
}
