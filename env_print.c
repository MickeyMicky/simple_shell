#include "shell.h"

/**
  * env_print - Function that prints the environment built-in
  */
void env_print(void)
{
	int i = 0, j;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}
