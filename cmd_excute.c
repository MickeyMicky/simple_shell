#include "shell.h"

/**
  * concat_p - function that Concatenate path name and program name
  * @path: path name to concatenate with the program name
  * @pname: program name
  *
  * Return: concatenated string
  */
char *concat_p(char *path, char *pname)
{
	int pro_len = 0, path_len = 0, concat = 0;

	pro_len = _strlen(pname);
	path_len = _strlen(path);
	concat = sizeof(char) * (path_len + pro_len + 2);
	path = _realloc(path, (path_len + 1), concat);
	if (!path)
		return (NULL);

	_strcat(path, "/");
	_strcat(path, pname);

	return (path);
}

/**
  * found - Function that checks if a command is found in the system
  * @cmd: command string
  *
  * Return: path name of the command found or NULL if failed
  */
char *found(char *cmd)
{
	char *env_p = NULL, **args = NULL;
	int i = 0, num = 0;
	struct stat sb;

	if (cmd)
	{
		if (stat(cmd, &sb) != 0 && cmd[0] != '/')
		{
			env_p = get_env("PATH");
			num = count_delim(env_p, ":") + 1;
			args = tokenize(env_p, ":", num);

			while (args[i])
			{
				args[i] = concat_p(args[i], cmd);

				if (stat(args[i], &sb) == 0)
				{
					free(cmd);
					cmd = _strdup(args[i]);
					free_getenv(env_p);
					free_token(args);
					return (cmd);
				}

				i++;
			}

			free_getenv(env_p);
			free_token(args);
		}

		if (stat(cmd, &sb) == 0)
			return (cmd);
	}

	free(cmd);
	return (NULL);
}

/**
  * execute_cmd - Function that executes a command
  * @cmd: command to execute
  * @args: string
  *
  * Return: integer status
  */
int execute_cmd(char *cmd, char **args)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cmd, args, environ);
			break;
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
