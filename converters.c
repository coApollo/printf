#include <stdio.h>
#include "main.h"
/**
 *print_bin -converts
 *
 *Return: Nothing
 */
void print_bin(unsigned int n)
{
	if (n > 1)
		print_bin(n / 2);
	
	_putchar((n % 2) + '0');
}

/**
 *print_oct-
 *
 *Return: Nothing
 */
void print_oct(unsigned int n)
{
	if (n > 7) 
		print_oct(n / 8);

	_putchar((n % 8) + '0');
}

/**
 *print_hex-
 *
 *Return: Nothing
 */
void print_hex(unsigned int n, int upper)
{
	int digit;

	if (n > 15)
		print_hex(n / 16, upper);
	
	digit = n % 16;
	if (digit < 10)
		_putchar(digit + '0');
	else
		_putchar((digit - 10) + (upper ? 'A' : 'a'));
	
}

/**
 *print_unsigned- converts char to unsigned int
 *
 *@n: integer parameter
 *Return: Nothing
 */
void print_unsigned(unsigned int n)
{
	if (n > 9)
		print_unsigned(n / 10);

	_putchar((n % 10) + '0');
}

