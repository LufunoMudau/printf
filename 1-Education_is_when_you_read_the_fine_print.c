#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Custom printf function to handle %c, %s, %d, %i, and %%
 * @format: Format string containing conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '%')
		{
			++ptr;
            if (*ptr == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                ++count;
            }
            else if (*ptr == 's')
            {
                const char *str = va_arg(args, const char *);
                while (*str)
                {
                    putchar(*str);
                    ++str;
                    ++count;
                }
            }
            else if (*ptr == 'd' || *ptr == 'i')
            {
                int num = va_arg(args, int);
                printf("%d", num);
                count += num < 0 ? count_digits(-num) + 1 : count_digits(num);
            }
            else if (*ptr == '%')
            {
                putchar('%');
                ++count;
            }
        }
        else
        {
            putchar(*ptr);
            ++count;
        }
    }

    va_end(args);

    return count;
}

/**
 * count_digits - Count the number of digits in an integer
 * @num: The integer
 *
 * Return: Number of digits
 */
int count_digits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        ++count;
    }
    return count;
}
