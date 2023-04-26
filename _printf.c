#include "main.h"
#include <string.h>

/**
 * _printf - function like printf
 * @format: string
 * Return: size string or -1
*/

int _printf(const char *format, ...)
{
	va_list l_arg;
	int i = 0, j, f, len_container = 0, size_output;
	int handle_size_output = 0, last_output = 0, h_space = 0;
	char *container, output[500];
	char *(*specif_func)(va_list) = NULL;

	if (!format)
		return (-1);
	for (f = 0; f < 500; f++)
		output[f] = 0;
	va_start(l_arg, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; format[i] == ' ' || format[i] == '\0'; j++, i++)
			{
				if (format[i + 1] == '\0' || format[i] == '\0')
				{
					_puts(output, _strlen(output));
					return (-1);
				};
			}
			specif_func = get_specif_func(format[i]);
			container = (specif_func) ? specif_func(l_arg) : notexist_specif(format[i]);
			len_container = _strlen(container);
			handle_size_output = (len_container == 0 && format[i] == 'c') ? 1 : 0;
			_memcpy(output, container, len_container, last_output);
			last_output += len_container;
		}
		else
			_memcpy(output, chartos(format[i]), 1, last_output), last_output += 1;
		i++;
	};
	size_output = _puts(output, _strlen(output) + handle_size_output);
	va_end(l_arg);
	return (size_output);
}
