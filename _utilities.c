#include "shell.h"

/**
  * _atoi - Function that convert a string to an integer.
  * @s: string
  *
  * Return: An integer
  */
int _atoi(char *s)
{
	int m = 1, i = 0, p = 0;
	unsigned int n = 0;

	while (s[p])
	{
		if (s[p] == '-')
			m *= -1;

		while (s[p] >= '0' && s[p] <= '9')
		{
			i = 1;
			n = (n * 10) + (s[p] - '0');
			p++;
		}

		if (i == 1)
			break;

		p++;
	}

	n *= m;
	return (n);
}

/**
  * _strcat - Function that concatenates two strings
  * @dest: destination
  * @src: source
  *
  * Return: concatenated strings
  */
char *_strcat(char *dest, char *src)
{
	int len = 0, i = 0;

	while (dest[len])
		len++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len++;
	}

	dest[len] = '\0';
	return (dest);
}

/**
  * _strlen - function that counts the length of a string
  * @s: string
  *
  * Return: length of a string
  */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
  * _strcmp - Fucntion that compares two strings
  * @s1: first string
  * @s2: second string
  *
  * Return: int value
  */
int _strcmp(char *s1, char *s2)
{
	int len_s1 = 0, len_s2 = 0, p = 0, d = 0, t = 0;

	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);

	if (len_s1 <= len_s2)
		t = len_s1;
	else
		t = len_s2;

	while (p <= t)
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
  * _strdup - Function that duplicate a string
  * @str: string
  *
  * Return: duplicated string
  */
char *_strdup(char *str)
{
	int idx = 0, len = 1;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup_str = malloc((sizeof(char) * len) + 1);
	if (dup_str == NULL)
		return (NULL);

	while (idx < len)
	{
		dup_str[idx] = str[idx];
		idx++;
	}

	dup_str[idx] = '\0';
	return (dup_str);
}
