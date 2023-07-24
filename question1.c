#include <stdio.h>
#include <stdarg.h>
/**
 * printf - This function takes a format string and a variable number of arguments,
 * and processes the format specifiers within the format string to print the
 * corresponding data in a formatted manner.
 * @param format The format specifier string containing directives and text to print.
 * @param ...    The variable arguments that correspond to the format specifiers
 *               in the format string.
 * @return The total number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
char c;
va_list args;
int count;
count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
c = (char)va_arg(args, int);
putchar(c);
count++;
break;
case 's':
{
char *s = va_arg(args, char *);
if (s)
{
while (*s)
{
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
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
