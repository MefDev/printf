#include "main.h"

/**
 * char_specif - converts a char to a string
 * @c: char
 * Return: string
 */
char *char_specif(va_list c)
{
	char *pnt;
	char str[2];

	pnt = str;
	str[0] = va_arg(c, int);
	str[1] = '\0';
	return (pnt);
}

/**
 * string_specif - passes a string to print
 * @s: string
 * Return: string
 */
char *string_specif(va_list s)
{
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		return ("(null)");
	return (str);
}

/**
 * percent_specif - passes a '%' sign
 * Return: percent sign as a character
 */
char *percent_specif(void)
{
	char *str;

	str = "%";
	return (str);
}

/**
 * notexist_specif - print character after % if specifier not exist
 * @c: character
 * Return: string
 */
char *notexist_specif(char c)
{
	char str[3];
	char *pnt;

	pnt = str;
	str[0] = '%';
	str[1] = c;
	str[2] = '\0';
	return (pnt);
}


/**
 * integer_specif - print the integers
 * @npnt: digit
 * Return: pointer
 */


char *integer_specif(va_list npnt)
{
	int nmb;
	int i, reset, temp, expo, count;
	char *str;

	nmb = va_arg(npnt, int);
	count = i = 0;
	expo = 1;
	if (nmb >= 0)
		reset = nmb * -1;
	else
		reset = nmb;
	temp = reset;

	for (i = 0; temp <= -10; count++)
		expo *= 10, temp /= 10;

	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nmb < 0)
		str[i++] = '-';
	while (expo >= 1)
	{
		str[i++] = (((reset / expo) % 10) * -1 + '0');
		expo /= 10;
	}
	return (str);
}
