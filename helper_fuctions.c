#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
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
/**
 * *print_interger - Helper function to ptint an integer.
 * @num : the nteger to print
 *
 * Return : the number of characters printed.
 */
int print_integer(int num)
{
	int num_len = num < 0?1 : 0;
	int temp = num;

	while (temp != 0)
	{
		temp /=10;
		num_len++;
	}
	char buffer[20];
	snprintf(buffer, sizeof(buffer), "%d",num);

	return (print_string(buffer));
}
