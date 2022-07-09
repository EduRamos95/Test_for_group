#include "main.h"

/**
 * Control_Spec - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
unsigned int (*Control_Spec(const char *format))(va_list name_list)
{
	unsigned int i; // index of Spec
	Specifier_t Spec[] = {
		{"c", print_c},
		{"s", print_s},
		{"\0", NULL} // '\0' always in last field
	}; 

	for (i = 0; Spec[i].option != NULL; i++) // find Spec
	{
		if (Spec[i].option == *format)
		{
            return (Spec[i].op_func); // return pointer to function
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
	unsigned int i, count; // index to format, counter of the string to be printed
	va_list var_parameter; // assign a name
	int (*f)(va_list);     // function pointer

	if (format == NULL) // if format doesn't exist
		return (-1);    // error
	va_start(var_parameter, format); // stars the var_list args
    i = 0;
    count = 0;
	while (format[i] != '\0') // compare string with null character
	{
		for (i; format[i] != '%' && format[i] != '\0'; i++) 
		{
			_putchar(format[i]); //print string
			count++;
		}
		if (!format[i]) // if format finish
			return (count); // return the length of the string to be printed
		f = Control_Spec(&format[i + 1]); // to point a function specifier
		if (f != NULL) // if function exists
		{
			count += f(var_parameter); // store the length of the printed var_parameter 
			i += 2; // increment to skip '%S' percent and specifier
			continue; // next iteration
		}
		if (!format[i + 1]) 
			return (-1);
		_putchar(format[i]); // print '%'
		count++; //increment when a character was printed
		if (format[i + 1] == '%')
			i += 2; // increment to skip '%%'
		else
			i++; // increment to next position
	}
	va_end(valist); // ends the var_list args
	return (count);
}
