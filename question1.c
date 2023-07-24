#include <stdio.h>
#include <stdarg.h>

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
