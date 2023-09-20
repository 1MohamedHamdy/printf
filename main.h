#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
<<<<<<< HEAD
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);
int print_integer (int num);
=======
int print_integer(int num);
int print_binary(unsigned int num);
int _printf(const char *format, ...);
int process_format(const char **format, va_list args);

>>>>>>> 01e354f6a673fddedd3787271b1cb9208728280f
#endif /* _MAIN_H_ */
