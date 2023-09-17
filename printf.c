#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static int HANDLE_ERROR(const char *msg)
{
    perror(msg);
    return -1;
}
int _printf(const char *format, ...)
{
    va_list args;
    int num, counter = 0, len = 0;
    char c;
    char *str1 = NULL;
    char buffer[20];
    /* Handling error mechanism if format is Null */
    if (format == NULL)
        return (HANDLE_ERROR("_printf: format is NULL"));

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            if (write(1, format,1) < 0)
                return (HANDLE_ERROR("_printf: write error"));
            counter++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;
            switch (*format)
            {
                case 'c':
                {
                    c = va_arg(args, int);
                    if (write(1, &c, 1) < 0)
                        return (HANDLE_ERROR("_printf: write error"));
                    counter++;
                    break;
                }
                case 's':
                {
                    str1 = va_arg(args, char*);
                    if (str1 == NULL)
                        str1 = "(null)";
                    while (*str1)
                    {
                        if (write(1, str1, 1) < 0)
                            return (HANDLE_ERROR("_printf: write error"));
                        str1++;
                        counter++;
                    }
                    break;
                }
                case '%':
                {
                    if (write(1, "%", 1) < 0)
                        return (HANDLE_ERROR("_printf: write error"));
                    counter++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    num = va_arg(args, int);
                    len = snprintf(buffer, sizeof(buffer), "%d", num);
                    if (write(1, buffer, len) < 0)
                        return (HANDLE_ERROR("_printf: write error"));
                    counter += len;
                    break;
                }
                default:
                {
                    if (write(1, format, 1) < 0)
                        return (HANDLE_ERROR("_printf: write error"));
                    counter ++;
                }
            }
        }
        format++;
    }
    va_end(args);
    return (counter);
}


