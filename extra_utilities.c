#include "shell.h"

/**
  * _puts - Prints a string
  * @str: The string to print
  *
  * Return: Nothing to returns
  */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @s1: first string
  * @s2: second string
  * @len: limit bytes
  *
  * Return: int value
  */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int p = 0;
	int d = 0;

	while (p < len)
	{
		if (s1[p] == s2[p])
		{
			p++;
			continue;
		}
		else
		{
			d = s1[p] - s2[p];
			break;
		}

		p++;
	}

	return (d);
}

/**
  * _realloc - function that resize the ptr that was previously allocated
  * @ptr: pointer previously allocated
  * @src: old size of the pointer
  * @dest: new size of the new pointer
  *
  * Return: new pointer to the memory block allocated with the new size
  */
void *_realloc(void *ptr, unsigned int src, unsigned int dest)
{
	char *new_ptr;
	unsigned int i;

	if (dest == src)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(dest);

		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}
	else
	{
		if (dest == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	new_ptr = malloc(dest);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < src && i < dest; i++)
	{
		new_ptr[i] = ((char *) ptr)[i];
	}

	free(ptr);
	return (new_ptr);
}
