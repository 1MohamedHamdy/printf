#include "main.h"

/**
 * print_char - Prints a single character.
 * @c: The character to be printed.
 *
 * Return: The number of characters printed (always 1 for a single character).
 */
int print_char(char c)
{
	_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed in the string.
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
