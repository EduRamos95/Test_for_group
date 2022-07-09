#include "main.h"

/**
 * Control_Spec - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*Control_Spec(const char *format))(va_list)
{
	unsigned int i; 
	Specifier_t Spec[] = {
		{"c", print_char},
		{"s", print_string},
		{"\0", NULL}
	}; 

	for (i = 0; Spec[i].option != NULL; i++) 
	{
		if (*(Spec[i].option) == *format)
		{
            return (Spec[i].op_func); 
		}
	}
	return (NULL);
}

/**
 * _printf - prints a string with optional directives
 * @format: string to print 
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, count; 
	va_list var_parameter; 
	int (*f)(va_list);     

	if (format == NULL) 
		return (-1);    
	va_start(var_parameter, format); 
    i = 0;
    count = 0;
	while (format[i] != '\0') 
	{
		for (; format[i] != '%' && format[i] != '\0'; i++) 
		{
			_putchar(format[i]); 
			count++;
		}
		if (!format[i]) 
			return (count); 
		f = Control_Spec(&format[i + 1]); 
		if (f != NULL) 
		{
			count += f(var_parameter); 
			i += 2; 
			continue; 
		}
		if (!format[i + 1]) 
			return (-1);
		_putchar(format[i]); 
		count++; 
		if (format[i + 1] == '%')
			i += 2; 
		else
			i++; 
	}
	va_end(var_parameter); 
	return (count);
}
