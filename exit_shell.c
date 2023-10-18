#include "shell.h"

/**
  * exit_shell - Function that handle exit shell
  * @args: string
  * @command: string
  */
void exit_shell(char **args, char *command)
{
	int status = 0;

	if (args[1] == NULL || (!_strcmp(args[1], "0")))
	{
		free_token(args);
		free(command);
		exit(0);
	}
	status = _atoi(args[1]);

	if (status != 0)
	{
		free_token(args);
		free(command);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");

		_puts(args[1]);
		_puts("\n");
		exit(2);
	}

	free_token(args);
	free(command);
	exit(EXIT_SUCCESS);
}
