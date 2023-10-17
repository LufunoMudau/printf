#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Print a character to stdout
 * @c: Character to print
 *
 * Return: Number of characters printed (always 1)
 */
static int print_char(char c)
{
	putchar(c);
	return (1);
}

/**
 * print_str - Print a string to stdout
 * @str: String to print
 *
 * Return: Number of characters printed
 */
static int print_str(const char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		putchar(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * _printf - Custom printf function to handle %c, %s and %%
 * @format: Format string
 *i
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c')
			{
				int character = va_arg(args, int);

				count += print_char((char)character);
			}
			else if (*(format + 1) == 's')
			{
				const char *str = va_arg(args, const char *);

				count += print_str(str);
			}
			else if (*(format + 1) == '%')
			{
				count += print_char('%');
			}
			format++;
		}
		else
		{
	count += print_char(*format);
		}
	format++;
	}

	va_end(args);

	return (count);
}
