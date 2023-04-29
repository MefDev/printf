#include "main.h"

/**
 * get_specif_func - check specifier type and return function
 * @s: type to check
 * Return: pointer to function to use
 */

char *(*get_specif_func(char s))(va_list)
{
	int i;
	specif_t sp_types[] = {
		{"c", char_specif},
		{"s", string_specif},
		{"%", percent_specif},
		{"i", integer_specif},
		{"d", integer_specif},
		{"b", binary_specif},
		{"u", unsigned_specif},
		{"o", octal_specif},
		{"x", hexa_specif},
		{"X", Hexa_specif},
		{NULL, NULL}
	};

	i = 0;
	while (sp_types[i].specif)
	{
		if (s == *sp_types[i].specif)
			return (sp_types[i].f);
		i++;
	}
	return (sp_types[i].f);
}
