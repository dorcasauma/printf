#include <stdio.h>
#include <stdarg.h>
/**
 *_printf - this function takes a format string and a variable number of arguments,
 * and processes the format specifiers within the format string to print the
 * corresponding data in a formatted manner.
 * @param format: The format specifier string containing directives and text to print.
 * @param ...:The variable arguments that correspond to the format specifiers
 *            in the format string.
 * Return: The total number of characters printed (excluding the null byte used to end output to strings).
 */
#include <stdio.h>
#include <stdarg.h>


int _printf(const char *format, ...) {
    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'

            if (*format == 'c')
                putchar(*format);
            else if (*format == 's')
                fputs(format, stdout);
            else if (*format == '%')
                putchar('%');
            else if (*format == 'd')
                printf("%d", va_arg(args, int));
            else if (*format == 'i')
                printf("%i", va_arg(args, int));
        } else {
            // Regular character, not a format specifier
            putchar(*format);
        }
        printed_chars++;
        format++;
    }

    va_end(args);

    return printed_chars;
}
