#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (HANDLE_ERROR());
	va_start(args, format);
	void (*print_funcs[])(va_list, int*) = {
		NULL,
		print_char,
		print_string
	};
	for (; *format; format++)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (HANDLE_ERROR());
			int specifier_index = *format - 'c';

			if (specifier_index >= 0 && specifier_index <= 2)
			{
				void (*print_func)(va_list, int*) = print_funcs[specifier_index];

				if (print_func != NULL)
				{
					print_func(args, &count);
				}
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
	}
	va_end(args);
	return (count);
}
