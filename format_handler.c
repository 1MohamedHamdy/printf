#include <stdarg.h>

/**
 * print_char - Prints a character.
 * @args: The va_list containing the character to print.
 * @count: Pointer to the character count.
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	*count += _putchar(c);
}

/**
 * print_string - Prints a string.
 * @args: The va_list containing the string to print.
 * @count: Pointer to the character count.
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		*count += _putchar(*str);
		str++;
	}
}
