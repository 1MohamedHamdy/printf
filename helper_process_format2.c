#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * process_percent - Processes and prints a percent character.
 *
 * This function processes and prints the percent specifier '%%'.
 *
 * Return: The number of characters printed.
 */
int process_percent(void)
{
	return (print_char('%'));
}

/**
 * process_default - Processes and prints characters
 * when no specifier matches.
 *
 * @format: Pointer to the format string.
 *
 * This function processes and prints characters
 * when no valid specifier is found.
 *
 * Return: The number of characters printed.
 */
int process_default(const char **format)
{
	return (write(1, *format - 1, 2));
}

