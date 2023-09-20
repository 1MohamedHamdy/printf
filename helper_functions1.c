#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

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
 * print_integer - Helper function to print an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
	int num_len = num < 0 ? 1 : 0;
	int temp = num;
	char buffer[20];

	while (temp != 0)
	{
		temp /= 10;
		num_len++;
	}

	snprintf(buffer, sizeof(buffer), "%d", num);
	return (print_string(buffer));
}
/**
 * print_binary - Helper function to print an integer in binary.
 * @num: The integer to print in binary.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int i, count = 0, start_index = 0;
	int binary_size = sizeof(num) * 8;
	char binary[33];

	if (num == 0)
		count += print_char('0');
	else
	{
		for (i = 0; i < binary_size; i++)
		{
			binary[i] = '0';
		}
		binary[binary_size] = '\0';

		for (i = binary_size - 1; i >= 0; i--)
		{
			binary[i] = (num & 1) ? '1' : '0';
			num >>= 1;
		}
		while (binary[start_index] == '0' && start_index < binary_size)
		{
			start_index++;
		}
		count += print_string(&binary[start_index]);
	}
	return (count);
}
