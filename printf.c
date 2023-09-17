#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_conversion_specifier - Handles formatting
 * and printing of a conversion specifier.
 * @format: The conversion specifier character.
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed for the conversion specifier.
 */
int handle_conversion_specifier(char format, va_list args)
{
	char c;
	char *str = NULL;

	switch (format)
	{
		case 'c':
			c = va_arg(args, int);

			return (print_char(c));

		case 's':
			str = va_arg(args, char *);

			return (print_string(str));

		case '%':
			return (print_char('%'));

		default:
			return (0);
	}
}

/**
 * _printf - Custom printf implementation that supports
 * character and string conversion specifiers.
 * @format: The format string containing conversion specifiers.
 * @...: The variable number of arguments to be formatted and printed.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			count += handle_conversion_specifier(*format, args);
		}
		else
		{
			count += print_char(*format);
		}
		format++;
	}
	return (count);
}
