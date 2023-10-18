#include "shell.h"

/**
  * tokenize - Function that extract tokens from string
  * @str: string to be tokenize
  * @del: delim
  * @len: Token number
  *
  * Return: An array of tokens of the string
  */
char **tokenize(char *str, char *del, int len)
{
	char **tokens = NULL, *_token = NULL, *current = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (len + 1));
	if (tokens == NULL)
		return (NULL);

	str = delete_line(str);
	current = _strdup(str);
	_token = strtok(current, del);

	while (_token)
	{
		tokens[i] = _strdup(_token);
		_token = strtok(NULL, del);
		i++;
	}

	tokens[i] = NULL;
	free(current);
	return (tokens);
}
