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
	char *s;
	const char *next;
	va_list variable;
	int ch;

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
			ch = va_arg(variable, int);
			_putchar(ch);
			break;
		case 's':
			s = va_arg(variable, char*);
			puts(s);
			break;
		default:
			_putchar(*next);
		}

	}
	va_end(variable);

	return (0);
}
