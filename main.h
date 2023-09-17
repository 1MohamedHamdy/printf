#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int _putchar(char c);
int print_char(char c);
int print_string(const char *str);
int handle_conversion_specifier(char format, va_list args);
int _printf(const char *format, ...);

#endif /* _MAIN_H_ */

