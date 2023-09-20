#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * process_char - Processes and prints a character.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints a character specifier 'c'.
 *
 * Return: The number of characters printed.
 */
int process_char(va_list args)
{
	char c = va_arg(args, int);

	return (print_char(c));
}

/**
 * process_string - Processes and prints a string.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints a string specifier 's'.
 *
 * Return: The number of characters printed.
 */
int process_string(va_list args)
{
	char *str = va_arg(args, char *);

	return (print_string(str));
}

/**
 * process_integer - Processes and prints an integer.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints integer specifiers 'd' and 'i'.
 *
 * Return: The number of characters printed.
 */
int process_integer(va_list args)
{
	int num = va_arg(args, int);

	return (print_integer(num));
}

/**
 * process_binary - Processes and prints a binary number.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints a binary specifier 'b'.
 *
 * Return: The number of characters printed.
 */
int process_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_binary(num));
}



