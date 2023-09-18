#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int print_integer(int num);
int print_binary(unsigned int num);
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);

#endif /* _MAIN_H_ */
