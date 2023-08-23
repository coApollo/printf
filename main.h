/*main.h*/

#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void _puts(char *str);
int _printf(const char *format, ...);
int decide(va_list variable, char c);
void print_int(int n);
void print_unsigned(unsigned int n);
void print_hex(unsigned int n, int upper);
void print_oct(unsigned int n);
void print_bin(unsigned int n);

#endif
