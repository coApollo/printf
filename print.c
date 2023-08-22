#include <stdio.h>
#include <string.h>
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
	const char *next;
	va_list variable;

	va_start(variable, format);

	for (next = format; *next != '\0'; next++)
	{
		if (*next != '%')
		{
			_putchar(*next);
			continue;
		}

		switch (*++next)
		{
		case 'c':
			_putchar(va_arg(variable, int));
			break;
		case 's':
			puts(va_arg(variable, char*));
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
		default:
			_putchar(*next);
		}

	}
	va_end(variable);

	return (0);
}
/**
 *print_int - converts a string into an integer
 *
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

