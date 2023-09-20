#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);
int print_integer (int num);
int print_binary(unsigned int num);


/**
* Task 3 
*/
/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int print_unsigned(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
void init_params(params_t *params, va_list args);


#endif /* _MAIN_H_ */
