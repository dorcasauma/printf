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
            else if (* format == 'b'){
                int num = va_arg(args, int);
                char* binary_str = int_to_binary(num);
                printf(binary_str);
            }
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

char* int_to_binary(int num) {
    int i;
    int index = 0;
    int leading_zeros = 1;
    int size = sizeof(int) * 8; // Number of bits in an integer
    char* binary_str = (char*)malloc(size + 1); // +1 for null terminator

    if (!binary_str) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Extract each bit from the integer and build the binary string
    for (i = size - 1; i >= 0; i--) {
        int bit = (num & (1 << i)) ? 1 : 0;

        if (bit || !leading_zeros) {
            binary_str[index++] = bit + '0';
            leading_zeros = 0;
        }
    }

    // If the number was zero, represent it as '0'
    if (index == 0)
        binary_str[index++] = '0';

    binary_str[index] = '\0'; // Null-terminate the binary string
    return binary_str;
}
