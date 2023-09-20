#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * print_unsigned_int - Prints an unsigned integer.
 * @num: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_int(unsigned int num)
{
	char buffer[20];

	snprintf(buffer, sizeof(buffer), "%u", num);
	return (print_string(buffer));
}

/**
 * print_octal - Prints an octal number.
 * @num: The octal number to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	char buffer[20];

	snprintf(buffer, sizeof(buffer), "%o", num);
	return (print_string(buffer));
}

/**
 * print_hex_lower - Prints a lowercase hexadecimal number.
 * @num: The hexadecimal number to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_lower(unsigned int num)
{
	char buffer[20];

	snprintf(buffer, sizeof(buffer), "%x", num);
	return (print_string(buffer));
}

/**
 * print_hex_upper - Prints an uppercase hexadecimal number.
 * @num: The hexadecimal number to print.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(unsigned int num)
{
	char buffer[20];

	snprintf(buffer, sizeof(buffer), "%X", num);
	return (print_string(buffer));
}

