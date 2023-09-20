#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * process_unsigned_int - Processes and prints an unsigned integer.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints an unsigned integer specifier 'u'.
 *
 * Return: The number of characters printed.
 */
int process_unsigned_int(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_int(num));
}

/**
 * process_octal - Processes and prints an octal number.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints an octal specifier 'o'.
 *
 * Return: The number of characters printed.
 */
int process_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_octal(num));
}

/**
 * process_hex_lower - Processes and prints a lowercase hexadecimal number.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints a lowercase hexadecimal specifier 'x'.
 *
 * Return: The number of characters printed.
 */
int process_hex_lower(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hex_lower(num));
}

/**
 * process_hex_upper - Processes and prints an uppercase hexadecimal number.
 *
 * @args: Variable argument list.
 *
 * This function processes and prints an uppercase hexadecimal specifier 'X'.
 *
 * Return: The number of characters printed.
 */
int process_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hex_upper(num));
}
