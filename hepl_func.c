#include  "main.h"
#include <unistd.h>


/**
 * _puts - prints a string
 * @str: string to be printed
 * @size: size of str
 *
 * Return: size
 */

int _puts(const char *str, int size)
{
	write(1, str, size);
	return (size);
}

/**
 * _strlen - return length of a string
 * @str: string to be printed
 *
 * Return: length of str
 */

int _strlen(const char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (1 + _strlen(str + 1));
}

/**
 * chartos - converts a character to a string
 * @c: character to convert
 * Return: pointer to string
 */
char *chartos(char c)
{
	char str[1];
	char *pnt;

	pnt = str;
	str[0] = c;
	return (pnt);
}


/**
 * _memcpy - Prints buffer in hexa
 * @dest: pointer buffer
 * @src: pointer buffer
 * @n: size
 * @dest_len: size of dest
 *
 * Return: pointer dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n, unsigned int dest_len)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + (i + dest_len)) = *(src + i);

	}
	return (dest);
}

/**
 * rev_string - reverses string
 * @str: string
 *
 *return : string .
 */

char *rev_string(char *str)
{
	int len = 0;
	int start, end, count;

	while (str[len] != '\0')
	{
		len++;
	}
	len--;
	for (count = 0; count <= len / 2; count++)
	{
		start = str[count];
		end = str[len - count];
		str[count] = end;
		str[len - count] = start;
	}
	return (str);
}
