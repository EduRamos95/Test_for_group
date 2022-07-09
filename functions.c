#include "main.h"

/**
 * print_char - Prints a char.
 *
 * @c: Char to be printed.
 *
 * Return: 1.
 */

int print_char(va_list c)
{
	char ch;
	ch = (char)va_arg(c,int);

	_putchar(ch);
	return (1);
}


/**
 * print_string - Fucntion that prints a string.
 *
 * @s: String to print from specifier.
 *
 * Return: Chars printed.
 */

int print_string(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}
