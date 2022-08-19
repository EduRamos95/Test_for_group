#include "monty.h"

void _pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr;
    ptr = *stack;

    while (ptr->next != NULL)
        ptr = ptr->next;

    printf("%d\n", ptr->n);
}
