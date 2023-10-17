#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Custom prinf function to handle %c, %s and %%
 * @format: Format string
 *
 * Return: Number of characyers printed
 */
int _print(const char *format, ...)
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

				putchar(character);
				count++;
			}
			else if (*(format + 1) == 's')
			{
				const char *str = va_arg(args, const char *);

				while (*str != '\0')
				{
					putchar(*str);
					count++;
					str++;
				}
			}
			else if (*(format + 1) == '%')
			{
				putchar('%');
				count++;
			}
			format++;
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

