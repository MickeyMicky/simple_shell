#include "shell.h"

/**
  * free_getenv - function that frees variable
  * @env_p: frees environment variable
  */
void free_getenv(char *env_p)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_p--;

	free(env_p);
}

/**
  * free_token - Function that frees token
  * @token: string
  */
void free_token(char **token)
{
	char **temp = token;

	if (token)
	{
		while (*token)
			free(*token++);
		free(temp);
	}
}
