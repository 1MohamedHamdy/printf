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

	switch (**format)
	{
		case 'c':
			count += process_char(args);
			break;
		case 's':
			count += process_string(args);
			break;
		case '%':
			count += process_percent();
			break;
		case 'd':
		case 'i':
			count += process_integer(args);
			break;
		case 'b':
			count += process_binary(args);
			break;
		case 'u':
			count += process_unsigned_int(args);
			break;
		case 'o':
			count += process_octal(args);
			break;
		case 'x':
			count += process_hex_lower(args);
			break;
		case 'X':
			count += process_hex_upper(args);
			break;
		default:
			count += process_default(format);
	}
	return (count);
}
