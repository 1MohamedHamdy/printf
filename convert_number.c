#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex( va_list args, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list args, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}


/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list args, params_t *params)
{
unsigned long l;
char *str;
int c = 0;

if (params->l_modifier)
l = (unsigned long)va_arg(args, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(args, unsigned int);
else
l = (unsigned int)va_arg(args, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && l)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}