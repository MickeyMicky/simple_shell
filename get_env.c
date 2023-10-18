#include "shell.h"

/**
  * get_env - function that get an environment variable
  * @input: variable
  *
  * Return: environment variable content
  */
char *get_env(const char *input)
{
	int i = 0;
	char *envro = NULL;

	while (environ[i])
	{
		if (_strncmp(input, environ[i], _strlen(input)) == 0)
		{
			envro = _strdup(environ[i]);
			while (*envro != '=')
				envro++;

			++envro;
			return (envro);
		}
		i++;
	}

	return (NULL);
}
