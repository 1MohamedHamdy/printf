#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Helper function to print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Helper function to print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
