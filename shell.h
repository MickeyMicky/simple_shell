#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *_strcat(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int src, unsigned int dest);
int count_cmd(char *str);
int count_delim(char *str, char *delim);
char *delete_line(char *str);
void _help_(void);
void signal_handler(int signal_id);
void env_print(void);
void exit_shell(char **args, char *command);
int exe_builtin(char **args, char *command);
void free_getenv(char *env_p);
void free_token(char **token);
int execute_cmd(char *cmd, char **args);
char *get_env(const char *input);
char *found(char *cmd);
char **tokenize(char *str, char *del, int len);

#endif
