#include "main.h"

/**
 * print_char - prints a single character
 * @c: character to print
 *
 * Return: 1
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int len = 0;

    if (!s)
        s = "(null)";

    while (s[len])
    {
        write(1, &s[len], 1);
        len++;
    }

    return (len);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

             if (format[i] == '\0')
                return (-1);

            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else
            {
                count += print_char('%');
                count += print_char(format[i]);
            }
        }
        else
            count += print_char(format[i]);

        i++;
    }

    va_end(args);
    return (count);
}
