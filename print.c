#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *_printf - prints formated output to stdo
 *
 *@format: a string of placeholders
 *Return: Always 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list variable;
	int i = 0;
	char c;

	va_start(variable, format);

	if (format == NULL)
		return (-1);

	while ((c = *format++))
	{
		if (c != '%')
		{
			_putchar(c);
			i++;
		}
		else
		{
			i += decide(variable, *format++);
		}
	}
	va_end(variable);

	return (i);
}
/**
 *decide -prints datatype dipending on the char specified
 *
 *Return: Nothing
 */
int decide(va_list variable, char c)
{
	switch (c)
	{
	case 'c':
		_putchar(va_arg(variable, int));
		break;
	case 's':
		_puts(va_arg(variable, char*));
		break;
	case '%':
		_putchar('%');
		break;
	case 'i':
	case 'd':
		print_int(va_arg(variable, int));
		break;
	case 'b':
		print_bin(va_arg(variable, unsigned int));
		break;
	case 'u':
		print_unsigned(va_arg(variable, unsigned int));
		break;
	case 'o':
		print_oct(va_arg(variable, unsigned int));
		break;
	case 'x':
		print_hex(va_arg(variable, unsigned int), 0);
		break;
	case 'X':
		print_hex(va_arg(variable, unsigned int), 1);
		break;
	case 'p':
		printf("%p", va_arg(variable, void*));
		break;
	default:
		_putchar(c);
	}
	return (0);
}
/**
 *print_int - converts a string into an integer
 *@n: integer parameter
 *Return: Nothing
 */
void print_int(int n) 
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n == 0)
	{
		_putchar('0');
	}

	else
	{
        	if (n / 10)
			print_int(n / 10);

		_putchar((n % 10) + '0');
	}
}

