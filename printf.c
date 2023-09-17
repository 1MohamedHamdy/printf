#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Helper function to print a character
 * @c: The character to print
 *
 * Return: Number of characters printed
 */
static int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Helper function to print a string
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
static int print_str(const char *str)
{
	int counter = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (print_char(*str) < 0)
			return (HANDLE_ERROR("_printf: write error"));

		str++;
		counter++;
	}
	return (counter);
}

/**
 * handle_format - Helper function to handle format specifiers
 * @format: The format specifier
 * @args: Arguments for the format specifier
 *
 * Return: Number of characters printed
 */
static int handle_format(const char *format, va_list args)
{
	int counter = 0;

	switch (*format)
	{
		case 'c':
			if (print_char(va_arg(args, int)) < 0)
				return (HANDLE_ERROR("_printf: write error"));
			counter++;
			break;
		case 's':
			counter += print_str(va_arg(args, const char *));
			break;
		case '%':
			if (print_char('%') < 0)
				return (HANDLE_ERROR("_printf: write error"));
			counter++;
			break;
	}
	return (counter);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;

	if (format == NULL)
		return (HANDLE_ERROR("_printf: format is NULL"));
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (print_char(*format) < 0)
				return (HANDLE_ERROR("_printf: write error"));
			counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			counter += handle_format(format, args);
		}
		format++;
	}
	va_end(args);
	return (counter);
}
