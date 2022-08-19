#include "monty.h"

void _pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr;
    ptr = *stack;

    while (ptr->next != NULL)
        ptr = ptr->next;
    /*elemento final*/
    (ptr->prev)->next = NULL;
    free(ptr);
}
