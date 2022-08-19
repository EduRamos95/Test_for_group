#include "monty.h"

void _swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *ptr = NULL;
    stack_t *tmp_1 = NULL;
    int num1 = 0;
    int num2 = 0;

    ptr = *stack;

    while (ptr->next != NULL)
        ptr = ptr->next;

    tmp_1 = ptr->prev;
    
    num1 = ptr->n;
    num2 = tmp_1->n;

    ptr->n = num2;
    tmp_1->n = num1;
}
