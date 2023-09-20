#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);
int print_integer (int num);
int print_binary(unsigned int num);
int print_unsigned(va_list ap, params_t *params);

#endif /* _MAIN_H_ */
