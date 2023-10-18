#include "shell.h"
/**
  * main - Entry point
  *
  * Return: Always 0.
  */
int main(void)
{
	char *cmd = NULL, **args = NULL;
	int exec_flag = 0, len;
	size_t command_size = 0;
	ssize_t command_len = 0;

	while (command_len >= 0)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		command_len = getline(&cmd, &command_size, stdin);
		if (command_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		len = count_cmd(cmd);
		if (cmd[0] != '\n' && len > 0)
		{
			args = tokenize(cmd, " \t", len);
			exec_flag = exe_builtin(args, cmd);
			if (!exec_flag)
			{
				args[0] = found(args[0]);
				if (args[0] && access(args[0], X_OK) == 0)
					execute_cmd(args[0], args);
				else
					perror("./hsh");
			}

			free_token(args);
		}
	}

	free(cmd);
	return (0);
}
