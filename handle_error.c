#include <stdio.h>

/**
 * HANDLE_ERROR - Helper function to handle errors using perror
 * @msg: The error message to display
 *
 * Return: -1
 */
int HANDLE_ERROR(const char *msg)
{
	perror(msg);
	return (-1);
}
