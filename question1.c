#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    char c;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's': {
                    char *s = va_arg(args, char *);
                    if (s) {
                        while (*s) {
                            putchar(*s);
                            s++;
                            count++;
                        }
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
