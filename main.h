#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct Struct_Spec
{
	char *option;
	int (*op_func)(va_list);
} Specifier_t;

int _putchar(char c);
int _printf(const char *format, ...);

/* Functions inside functions.c */
int print_char(va_list c);
int print_string(va_list s);

#endif
