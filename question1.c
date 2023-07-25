#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 *_printf - this function takes a format string and a variable number of arguments,
 * and processes the format specifiers within the format string to print the
 * corresponding data in a formatted manner.
 * @param format: The format specifier string containing directives and text to print.
 * @param ...:The variable arguments that correspond to the format specifiers
 *            in the format string.
 * Return: The total number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...) {
    int printed_chars = 0;
    va_list args;
    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'

            if (*format == 'c') {
                // char type
                int ch = va_arg(args, int);
                putchar(ch);
                printed_chars++;
            } else if (*format == 's') {
                // string type
                const char *str = va_arg(args, const char*);
                printed_chars += fputs(str, stdout);
            } else if (*format == '%') {
                // '%' character
                putchar('%');
                printed_chars++;
            } else {
                // Unknown format specifier, just print the character
                putchar(*format);
                printed_chars++;
            }
        } else {
            // Regular character, not a format specifier
            putchar(*format);
            printed_chars++;
        }
        format++;
    }
    va_end(args);
 return printed_chars;
}

