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

	process_return(&format, &count, args);
	return (count);
}

/**
 * process_return - Processes and handles format specifiers.
 * @format: Pointer to the format string.
 * @count: Pointer to the character count.
 * @args: Variable argument list.
 *
 * This function processes and handles format specifiers, calling appropriate
 * helper functions to print characters, strings, integers, and more.
 *
 * Return: The number of characters printed.
 */
int process_return(const char ***format, int *count, va_list args)
{
	switch (***format)
	{
		case 'c':
			return (*count += process_char(args));
		case 's':
			return (*count += process_string(args));
		case 'd':
		case 'i':
			return (*count += process_integer(args));
		case 'b':
			return (*count += process_binary(args));
		case 'u':
			return (*count += process_unsigned_int(args));
		case 'o':
			return (*count += process_octal(args));
		case 'x':
			return (*count += process_hex_lower(args));
		case 'X':
			return (*count += process_hex_upper(args));
		default:
			return (*count += process_default(format));
	}
}
