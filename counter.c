#include "shell.h"

/**
  * count_delim - Function that counts delimiters in a string
  * @str: delimiters
  * @delim: find string
  *
  * Return: number of delimiters in the string
  */
int count_delim(char *str, char *delim)
{
	int i = 0, j, len = 0;

	while (delim[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == delim[i])
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

/**
  * count_cmd - Function that counts the command input
  * @str: string
  *
  * Return: number of words found in the string
  */
int count_cmd(char *str)
{
	int i = 0, len = 0, st = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			st = 0;
		else if (st == 0)
		{
			st = 1;
			len++;
		}
		i++;
	}
	return (len);
}
