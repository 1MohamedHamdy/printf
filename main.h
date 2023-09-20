#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int print_integer(int num);
int print_binary(unsigned int num);
int print_unsigned_int(unsigned int num);
int print_octal(unsigned int num);
int print_hex_lower(unsigned int num);
int print_hex_upper(unsigned int num);
int process_percent(void);
int process_default(const char **format);
int process_char(va_list args);
int process_string(va_list args);
int process_integer(va_list args);
int process_binary(va_list args);
int process_unsigned_int(va_list args);
int process_octal(va_list args);
int process_hex_lower(va_list args);
int process_hex_upper(va_list args);
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);
int process_custom_string(va_list args);

#endif /* _MAIN_H_ */

