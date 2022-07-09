#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct spec Specifier_t;

/**
 * struct spec - structure to choose the specifier option
 * @op: type to print
 * @f: function to print
 */
struct spec
{
        char *op;
        int (*f)(va_list);
};

int _putchar(char c);
int _printf(const char *format, ...);

/* Functions inside functions.c */
int print_char(va_list c);
int print_string(va_list s);

#endif
