#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += print_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			count += process_format(&format, args);
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * process_format - Processes format specifiers.
 * @format: Pointer to the format string.
 * @args: Variable argument list.
 *
 * Return: The number of characters printed.
 */
int process_format(const char **format, va_list args)
{
	int count = 0;

	if (**format == 'c')
	{
		char c = va_arg(args, int);

		count += print_char(c);
	}
	else if (**format == 's')
	{
		char *str = va_arg(args, char *);

		count += print_string(str);
	}
	else if (**format == '%')
	{
		count += print_char('%');
	}
	else if (**format == 'd' || **format == 'i')
	{
		int num = va_arg(args, int);

		count += print_integer(num);
	}
	else if (**format == 'b')
	{
		unsigned int num = va_arg(args, unsigned int);

		count += print_binary(num);
	}
	else
	{
		count += write(1, *format - 1, 2);
	}
	return (count);

}
