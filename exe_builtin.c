#include "shell.h"

/**
* exe_builtin - Function that executes built-in commands
* @args: string
* @command: input string
*
* Return: 1 if is a built-in command else 0
*/
int exe_builtin(char **args, char *command)
{
	int i = 0;
	char *cmd_list[] = { "exit", "help", "cd", "env", NULL };

	while (cmd_list[i])
	{
		if (_strcmp(args[0], cmd_list[i]) == 0)
		{
			switch (i)
			{
				case 0:
					exit_shell(args, command);
					return (0);
				case 1:
					_help_();
					return (1);
				case 2:
					chdir(args[1]);
					return (1);
				case 3:
					env_print();
					return (1);
				default:
					break;
			}
		}
		i++;
	}

	return (0);
}
