#include "main.h"

/**
 * _printf - function like printf
 * @format: string
 * Return: size string or -1
*/

int _printf(const char *format, ...)
{
	va_list l_arg;
	int i = 0, j, f, len_container = 0, size_output;
	char *container;
	int last_output = 0;
	char output[500];
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
				for (j = 0; format[i] == ' '; j++, i++)
					if (format[i + 1] == '\0')
						return (-1);
			specif_func = get_specif_func(format[i]);
			container = (specif_func) ? specif_func(l_arg) : notexist_specif(format[i]);
			if (container)
			{
				len_container = _strlen(container);
				_memcpy(output, container, len_container, last_output);
				last_output += len_container;
			}
		}
		else
		{
			container = chartos(format[i]);
			_memcpy(output, container, 1, last_output);
			last_output += 1;
		};
		i++;
	};
	size_output = _puts(output, _strlen(output));
	va_end(l_arg);
	return (size_output);
}

